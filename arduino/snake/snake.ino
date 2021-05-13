// License: GPL v2
// Authors: some students from HTBLA Steyr, Austria


#include <stdlib.h>
#include <time.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>
#include <stdint.h>
#include "button.h"


typedef struct point {
    uint8_t x;
    uint8_t y;
} point;
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


#define SEGMENT_TIME 500//Zeit bis 1 Segment vorwärts
#define SEGMENT_SIZE 3
#define START_LEN 3
#define FIELD_SIZE_X 32
#define FIELD_SIZE_Y 21
#define ARR_LEN 100



// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


point snake[ARR_LEN] = {0};

uint16_t headindex;
uint16_t len = START_LEN;
uint8_t score = 0;
uint8_t highscore = 0;
bool gameRunning = false;
bool inLeaderboard = false;
uint8_t selectedOption = 0;
uint16_t oldtime; // seconds
uint16_t starttime; // seconds
point eatPos;

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

enum Direction{UP, DOWN, LEFT, RIGHT};
Direction direction;


void setup() {

    Serial.begin(9600);
    Wire.begin(14,2); // SDA, SCL

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C, false, false)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;); // Don't proceed, loop forever
    }
    display.clearDisplay();


    // clear high score TODO with matrix
    if (buttons.start->read() == Button::Pressed &&
            buttons.select->read() == Button::Pressed) {

        for (uint8_t i = 0; i < 15; i++) {
            EEPROM.write(i, 0);
        }
    }

    // Clear the buffer
    printWelcomeScreen();
}


void startGame() {
    highscore = EEPROM.read(0);

    display.clearDisplay();
    direction = RIGHT;
    drawBorder();
    initializeSnake();
    printScore();
    printTime();
    gameRunning = true;
    starttime = millis() / 1000;

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
    display.println("LEADERBOARD");
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
        display.println("LEADERBOARD");
    }

    display.display();
}

void printLeaderBoard() {
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("NUM: SCORE:   TIME:");
    for (uint16_t i = 0; i <= 4; i++) {
        display.drawRect(0, (i * 10) + 10, 20, 11, SSD1306_WHITE);
        display.drawRect(19, (i * 10) + 10, 50, 11, SSD1306_WHITE);
        display.drawRect(68, (i * 10) + 10, 60, 11, SSD1306_WHITE);
        display.setTextColor(WHITE);
        display.setTextSize(1);
        display.setCursor(8, (i * 10) + 12);
        display.println(i + 1);
        if (EEPROM.read(i * 3) != 0) {
            display.setCursor(35, (i * 10) + 12);
            display.println(EEPROM.read(i * 3));

            char pC16[2];
            pC16[0] = EEPROM.read(i * 3 + 1);
            pC16[1] = EEPROM.read(i * 3 + 2);
            uint16_t ui16;
            memcpy( &ui16, pC16, 2 );

            display.setCursor(85, (i * 10) + 12);
            display.println(ui16);
        }

    }

    display.display();
}

void loop() {
    buttons.readAll();

    if (!gameRunning) {
        if (buttons.start->getEvent() == Button::PressedEvent) {
            if (selectedOption == 1) {
                if (!inLeaderboard) {
                    inLeaderboard = true;
                    printLeaderBoard();
                } else {
                    printWelcomeScreen();
                    inLeaderboard = false;
                }
            } else {
                startGame();
            }
        }


        if (!inLeaderboard && !gameRunning) {

            if (buttons.up->getEvent() == Button::PressedEvent) {
                selectedOption = 0;
                display.setTextColor(WHITE);

                display.setTextSize(1);
                display.setCursor(34, 55);
                display.println("LEADERBOARD");
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
        uint32_t now = millis();

        control();

        if (bodyCross() || borderCross()) {

            gameRunning = false;
            checkHighscore();
            printWelcomeScreen();


            return;

        }

        if (snake[headindex].x == eatPos.x && snake[headindex].y == eatPos.y) {
            newEat();
            len++;
            printScore();
            display.drawRect(eatPos.x * SEGMENT_SIZE + 1, eatPos.y * SEGMENT_SIZE + 1, 2, 2, SSD1306_WHITE);

        }

        display.drawRect(snake[headindex].x * SEGMENT_SIZE + 1, snake[headindex].y * SEGMENT_SIZE + 1, 2, 2, SSD1306_WHITE);

        if (headindex < len) {
            if (!(snake[ARR_LEN - (len - headindex)].x == snake[headindex].x && snake[ARR_LEN - (len - headindex)].y == snake[headindex].y)) {
                display.drawRect(snake[ARR_LEN - (len - headindex)].x * SEGMENT_SIZE + 1, snake[ARR_LEN - (len - headindex)].y * SEGMENT_SIZE + 1, 2, 2, SSD1306_BLACK);
            }
        } else {
            if (!(snake[headindex - len].x == snake[headindex].x && snake[headindex - len].y == snake[headindex].y)) {
                display.drawRect(snake[headindex - len].x * SEGMENT_SIZE + 1, snake[headindex - len].y * SEGMENT_SIZE + 1, 2, 2, SSD1306_BLACK);
            }
        }


        printTime();
        display.display(); // daten auf display schreiben.

        while(millis() < now+SEGMENT_TIME){
            buttons.readAll();
        }
    }
}

void checkHighscore() {
    uint16_t time = millis() / 1000 - starttime;

    for (int i = 0; i < 5; i++) {
        char pC16[2];
        pC16[0] = EEPROM.read(i * 3 + 1);
        pC16[1] = EEPROM.read(i * 3 + 2);
        uint16_t readTime;
        memcpy( &readTime, pC16, 2 );
        if (score > EEPROM.read(i * 3) || score == EEPROM.read(i * 3) && readTime > time) {

            for (int j = 4; j > i; j--) {
                EEPROM.write(j * 3, EEPROM.read((j - 1) * 3));
                EEPROM.write(j * 3 + 1, EEPROM.read((j - 1) * 3 + 1));
                EEPROM.write(j * 3 + 2, EEPROM.read((j - 1) * 3 + 2));
            }

            EEPROM.write(i * 3, score);

            EEPROM.write(i * 3 + 1, time & 0xFF);
            EEPROM.write(i * 3 + 2, time >> 8);
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


    display.println(oldtime);

    oldtime = millis() / 1000 - starttime;
    display.setTextColor(WHITE);
    display.setCursor(98, 55);


    display.println(oldtime);
}

void initializeSnake() {

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

bool isInSnake(point pt) {
    for (uint16_t i = 1; i < len; i++) {
        if (i > headindex) {
            if (pt.x == snake[ARR_LEN - (i - headindex)].x && pt.y == snake[headindex - i].y) {
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

    point pt;
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
