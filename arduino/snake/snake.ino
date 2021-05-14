// License: GPL v2
// Authors: some students from HTBLA Steyr, Austria

/*
 * Features:
 * Lenken mit Steuerkreuz
 * Äpfel fressen
 * Schlange wird pro Apfel um eins länger
 * Geschwindigkeit wird mit jedem Apfel erhöht
 *
 *
 * TODOs:
 * Bugfix, Spiel wird nach 25 Punkten beendet
 * Highscore Liste im ESP-Flash ablegen
 * Punktestand nach Spielende anzeigen
 * Möglichkeit des Pausierens
 */


#include <stdlib.h>
#include <time.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP_EEPROM.h>
#include <stdint.h>
#include "button.h"


struct Point {
    Point();
    Point(int8_t x, int8_t y);
    bool operator == (Point rhs);
    int8_t x;
    int8_t y;
};
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


#define SEGMENT_SIZE 3
#define START_LEN 3
#define FIELD_SIZE_X 32
#define FIELD_SIZE_Y 21
#define ARR_LEN 100



// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


Point snake[ARR_LEN] = {Point(0,0)};

uint16_t headindex;
uint16_t len = START_LEN;
uint8_t score = 0;
uint8_t highscore = 0;
bool gameRunning = false;
bool gamePaused = false;
bool inHighScore = false;
uint8_t selectedOption = 0;
uint16_t oldtime; // seconds
uint16_t starttime; // seconds
Point eatPos;

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

enum Direction{UP, DOWN, LEFT, RIGHT};
Direction direction;
#define START_DELAY 500
uint32_t moveDelay=START_DELAY; // start delay in ms


void setup() {
    Serial.begin(115200);
    delay(100);
    Serial.println("Welcome to SNAKE on Gamearino");
    Wire.begin(14,2); // SDA, SCL

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C, false, false)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;); // Don't proceed, loop forever
    }
    display.clearDisplay();


    // The library needs to know what size you need for your EEPROM variables
    // The minimum size is 16
    // The begin() call is required to initialise the EEPROM library
    EEPROM.begin(16);


    // clear high score TODO with matrix
    if (buttons.start->read() == Button::Pressed &&
            buttons.select->read() == Button::Pressed) {

        for (uint8_t i = 0; i < 15; i++) {
            EEPROM.put(i, 0);
        }
        if(EEPROM.commit()){
            Serial.println("Data written to EEPROM");
        }else{
            Serial.println("Error on EEPROM.commit()");
        }
        buttons.start->clearEvents();
        do{
            buttons.start->read();
        }while(buttons.start->getEvent() != Button::ReleasedEvent);
    }



    // Clear the buffer
    printWelcomeScreen();
}


void startGame() {
    Serial.println("startGame");
    EEPROM.get(0, highscore);

    display.clearDisplay();
    direction = RIGHT;
    drawBorder();
    initializeSnake();
    printScore();
    printTime();
    gameRunning = true;
    starttime = millis() / 1000;
    moveDelay = START_DELAY;
}
void printWelcomeScreen() {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(35, 5);
    display.println("Welcome to:");
    display.setTextSize(2);
    display.setCursor(37, 20);
    display.println("SNAKE");
    display.setTextSize(1);
    display.setCursor(52, 43);
    display.println("START");
    display.setTextSize(1);
    display.setCursor(34, 55);
    display.println("HIGHSCORE");
    display.display();
}

void toggleText() {
    static uint32_t lasttoggle = 0;
    uint32_t now = millis();

    if (now - lasttoggle > 600) {
        lasttoggle = now;
        display.setTextColor(WHITE);
    } else if (now - lasttoggle > 300) {
        display.setTextColor(BLACK);
    } else {
        return;
    }

    if (selectedOption == 0) {
        display.setTextSize(1);
        display.setCursor(52, 43);
        display.println("START");
    } else {
        display.setTextSize(1);
        display.setCursor(34, 55);
        display.println("HIGHSCORE");
    }

    display.display();
}



void loop() {
    buttons.readAll();

    if (!gameRunning) {
        if (buttons.start->getEvent() == Button::PressedEvent) {
            if (selectedOption == 1) {
                if (!inHighScore) {
                    inHighScore = true;
                    paintHighscore();
                } else {
                    printWelcomeScreen();
                    inHighScore = false;
                }
            } else {
                startGame();
            }
        }


        if (!inHighScore && !gameRunning) {

            if (buttons.up->getEvent() == Button::PressedEvent) {
                selectedOption = 0;
                display.setTextColor(WHITE);

                display.setTextSize(1);
                display.setCursor(34, 55);
                display.println("HIGHSCORE");
            }

            if (buttons.down->getEvent() == Button::PressedEvent) {
                selectedOption = 1;
                display.setTextColor(WHITE);
                display.setTextSize(1);
                display.setCursor(52, 43);
                display.println("START");
            }
            toggleText();
        }
    } // end !gameRunning


    if (gameRunning) {
        if(buttons.start->getEvent() == Button::PressedEvent){
            gamePaused = !gamePaused;

            if(!gamePaused){
                repaintField();
            }
        }

        uint32_t now = millis();

        if(!gamePaused){
            control();

            if (bodyCross() || borderCross()) {
                stateDump();

                gameRunning = false;
                updateHighscore();
                printWelcomeScreen();
                return;
            }
        }

        if (snake[headindex] == eatPos) {
            newEat();
            len++;
            moveDelay = 3000/(len+3); // increase speed with length of snake
            printScore();
            display.drawRect(eatPos.x * SEGMENT_SIZE + 1, eatPos.y * SEGMENT_SIZE + 1, 2, 2, SSD1306_WHITE);
        }

        display.drawRect(snake[headindex].x * SEGMENT_SIZE + 1, snake[headindex].y * SEGMENT_SIZE + 1, 2, 2, SSD1306_WHITE);

        if (headindex < len) {
            if (!(snake[ARR_LEN - (len - headindex)] == snake[headindex])) {
                display.drawRect(snake[ARR_LEN - (len - headindex)].x * SEGMENT_SIZE + 1,
                        snake[ARR_LEN - (len - headindex)].y * SEGMENT_SIZE + 1, 2, 2, SSD1306_BLACK);
            }
        } else {
            if (!(snake[headindex - len] == snake[headindex])) {
                display.drawRect(snake[headindex - len].x * SEGMENT_SIZE + 1,
                        snake[headindex - len].y * SEGMENT_SIZE + 1, 2, 2, SSD1306_BLACK);
            }
        }


        printTime();

        if(gamePaused){
            display.setCursor(20, 30);
            display.setTextColor(WHITE);
            display.setTextSize(2);
            display.println("PAUSE");
        }

        display.display(); // daten auf display schreiben.

        while(millis() < now+moveDelay){
            buttons.readAll();
        }
    }
}

void repaintField(){
    display.fillRect(1, 1, FIELD_SIZE_X*SEGMENT_SIZE-1, FIELD_SIZE_Y*SEGMENT_SIZE-1, SSD1306_BLACK);

    int16_t ii = headindex;
    for(int16_t i=0; i<len; i++){
        display.drawRect(snake[ii].x * SEGMENT_SIZE + 1, snake[ii].y * SEGMENT_SIZE + 1, 2, 2, SSD1306_WHITE);
        ii--;
        if(ii<0){
            ii = ARR_LEN-1;
        }
    }
    display.drawRect(eatPos.x * SEGMENT_SIZE + 1, eatPos.y * SEGMENT_SIZE + 1, 2, 2, SSD1306_WHITE);
}

void paintHighscore() {
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("NUM: SCORE:   TIME:");
    for (uint16_t i = 0; i < 5; i++) {
        display.drawRect(0, (i * 10) + 10, 20, 11, SSD1306_WHITE);
        display.drawRect(19, (i * 10) + 10, 50, 11, SSD1306_WHITE);
        display.drawRect(68, (i * 10) + 10, 60, 11, SSD1306_WHITE);
        display.setTextColor(WHITE);
        display.setTextSize(1);
        display.setCursor(8, (i * 10) + 12);
        display.println(i + 1);
        uint8_t tmp;
        EEPROM.get(i*3, tmp);
        if (tmp != 0) {
            display.setCursor(35, (i * 10) + 12);
            display.println(tmp);

            uint16_t highScore;
            EEPROM.get(i*3+1, highScore);
            display.setCursor(85, (i * 10) + 12);
            display.println(highScore);
        }
    }

    display.display();
}

void updateHighscore() {
    uint16_t time = millis() / 1000 - starttime;

    for (int i = 0; i < 5; i++) {
        uint16_t highScoreTime;
        EEPROM.get(i*3+1, highScoreTime);
        uint8_t highScore;
        EEPROM.get(i*3, highScore);

        if (score > highScore || score == highScore && highScoreTime > time) {
            for (int j = 4; j > i; j--) {
                EEPROM.write(j * 3, EEPROM.read((j - 1) * 3));
                EEPROM.write(j * 3 + 1, EEPROM.read((j - 1) * 3 + 1));
                EEPROM.write(j * 3 + 2, EEPROM.read((j - 1) * 3 + 2));
            }

            EEPROM.put(i * 3, score);
            EEPROM.put(i * 3 + 1, time); // write 2 bytes

            if(EEPROM.commit()){
                Serial.println("Data written to EEPROM");
            }else{
                Serial.println("Error on EEPROM.commit()");
            }

            return;
        }
    }
}

void drawBorder() {
    display.drawRect(0, 0, FIELD_SIZE_X * SEGMENT_SIZE + 1, FIELD_SIZE_Y * SEGMENT_SIZE + 1, SSD1306_WHITE);

    display.setTextSize(0.5);

    display.setTextColor(WHITE);
    display.setCursor(98, 0);
    display.println("Score");
    display.setCursor(98, 23);
    display.println("H-S");

    display.setCursor(98, 45);
    display.println("Time");
}

void printScore() {
    score = len - 3;
    display.setTextSize(0.5);
    display.setCursor(98, 10);
    if (len > START_LEN) {
        display.setTextColor(BLACK);
        display.println(score - 1);
    }
    display.setCursor(98, 10);
    display.setTextColor(WHITE);
    display.println(len - 3);

    if (score > highscore) {
        highscore = score;
        display.setCursor(98, 33);
        if (highscore != 0) {
            display.setTextColor(BLACK);
            display.println(highscore - 1);
        }
        display.setCursor(98, 33);
        display.setTextColor(WHITE);
        display.println(highscore);
    } else {
        display.setCursor(98, 33);
        display.setTextColor(WHITE);
        display.println(highscore);
    }
}


void printTime() {
    display.setTextSize(0.01);

    display.setTextColor(BLACK);
    display.setCursor(98, 55);
    display.println(oldtime); // clear old value from display memory

    oldtime = millis() / 1000 - starttime;
    display.setTextColor(WHITE);
    display.setCursor(98, 55);
    display.println(oldtime); // print new time
}

void initializeSnake() {
    Serial.println(__func__);

    len = START_LEN;
    headindex = 2;
    snake[0].x = 12;
    snake[0].y = 14;
    snake[1].x = 13;
    snake[1].y = 14;
    snake[2].x = 14;
    snake[2].y = 14;
    newEat();
    for (uint16_t i = headindex - len + 1; i < headindex + 1; i++) {
        display.drawRect(snake[i].x * SEGMENT_SIZE + 1, snake[i].y * SEGMENT_SIZE + 1, 2, 2, SSD1306_WHITE);
        display.drawRect(eatPos.x * SEGMENT_SIZE + 1, eatPos.y * SEGMENT_SIZE + 1, 2, 2, SSD1306_WHITE);

    }
    display.display(); // daten auf display schreiben.
}

void control() {

    headindex++;
    if (headindex >= ARR_LEN) {
        headindex = 0;
        snake[headindex] = snake[ARR_LEN - 1];
    } else {
        snake[headindex] = snake[headindex - 1];
    }

    if(buttons.up->getEvent() == Button::PressedEvent && direction != DOWN){
        direction = UP;
    }else if(buttons.down->getEvent() == Button::PressedEvent && direction != UP){
        direction = DOWN;
    }else if(buttons.left->getEvent() == Button::PressedEvent && direction != RIGHT){
        direction = LEFT;
    }else if(buttons.right->getEvent() == Button::PressedEvent && direction != LEFT){
        direction = RIGHT;
    }

    switch (direction) {
    case UP:
        snake[headindex].y--;
        break;
    case LEFT:
        snake[headindex].x--;
        break;
    case RIGHT:
        snake[headindex].x++;
        break;
    case DOWN:
        snake[headindex].y++;
        break;
    }
}

void newEat() {
    do {
        eatPos.x = rand() % FIELD_SIZE_X;
        eatPos.y = rand() % FIELD_SIZE_Y;
    } while (isInSnake(eatPos));
}

bool isInSnake(Point pt) {
    for (uint16_t i = 1; i < len; i++) {
        if (i > headindex) {
            if (pt.x == snake[ARR_LEN - (i - headindex)].x &&
                pt.y == snake[ARR_LEN - (i - headindex)].y) {
                return true;
            }
        } else {
            if (pt.x == snake[headindex - i].x && pt.y == snake[headindex - i].y) {
                return true;
            }
        }
    }
    return false;
}

bool bodyCross() {

    Point pt;
    pt.x = snake[headindex].x;
    pt.y = snake[headindex].y;
    return isInSnake(pt);
}

bool borderCross() {
    if (snake[headindex].x < 0 || snake[headindex].x > FIELD_SIZE_X - 1 ||
            snake[headindex].y < 0 || snake[headindex].y > FIELD_SIZE_Y - 1) {
        return true;
    }
    return false;
}

void stateDump(){
    for(int i=0; i<ARR_LEN; i++){
        Serial.println("snake[" + String(i) + "] = (" + String(snake[i].x) + "/" + String(snake[i].y) + ")");
    }

    Serial.print("headindex: " + String(headindex));
    Serial.println(", length: " + String(len));

    for(int x=-1; x<FIELD_SIZE_X+1; x++){
        Serial.print("# ");
    }
    Serial.println();
    for(int y=0; y<FIELD_SIZE_Y; y++){
        Serial.print("# ");
        for(int x=0; x<FIELD_SIZE_X; x++){
            bool isInArray=false;
            for(int i=0; i<ARR_LEN; i++){
                if(snake[i].x == x && snake[i].y == y){
                    isInArray = true;
                    break;
                }
            }
            if(isInArray){
                if(isInSnake(Point(x,y))){
                    if(snake[headindex] == Point(x,y)){
                        Serial.print("H ");
                    }else{
                        Serial.print("+ ");
                    }
                }else{
                    Serial.print(". ");
                }
            }else{
                if(eatPos.x == x && eatPos.y == y){
                    Serial.print("X ");
                }else{
                    Serial.print("  ");
                }
            }
        }
        Serial.println("# ");
        delay(1);
    }
    for(int x=-1; x<FIELD_SIZE_X+1; x++){
        Serial.print("# ");
    }
    Serial.println();

    while(buttons.start->read() != Button::Pressed){
        delay(1);
    }
    while(buttons.start->getEvent() != Button::ReleasedEvent){
        buttons.start->read();
    }
}

Point::Point()
{
    x=0;
    y=0;
}

Point::Point(int8_t x, int8_t y)
    :x(x), y(y)
{

}

bool Point::operator ==(Point rhs)
{
    if(x == rhs.x && y == rhs.y){
        return true;
    }else{
        return false;
    }
}
