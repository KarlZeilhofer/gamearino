// License: GPL v2
// Authors: some students from HTBLA Steyr, Austria

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

#define PinSTART 2
#define PinUP 3
#define PinDOWN 4
#define PinLEFT 5
#define PinRIGHT 6
#define TimePrell 30

// Button Matrix 
// UP      C0-R0
// DOWN    C0-R2
// LEFT    C0-R1
// RIGHT   C1-R2
// SELECT  C1-R0
// START   C1-R1
// B       C2-R1
// A       C2-R0


// MCU outputs:
#define MatrixC0 15
#define MatrixC1 4
#define MatrixC2 5
// MCU inputs (hardware pullups 10k):
#define MatrixR0 16
#define MatrixR1 12
#define MatrixR2 13


#include <stdlib.h>
#include <time.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>


// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


point snake[ARR_LEN] = {0};

uint16_t headindex;
uint16_t len = START_LEN;
uint8_t score = 0;
uint8_t highscore = 0;
bool gameRunning = false;
bool inLeaderboard = false;
uint8_t selectedOption = 0;
uint16_t oldtime;
uint16_t starttime;
uint16_t lasttoggle = 0;
point eatPos;

bool pinSTARTLow = true;
bool pinUPLow = true;
bool pinDOWNLow = true;
bool pinLEFTLow = true;
bool pinRIGHTLow = true;


unsigned long lastSTART = 0;
unsigned long lastUP = 0;
unsigned long lastDOWN = 0;
unsigned long lastLEFT = 0;
unsigned long lastRIGHT = 0;





enum Buttons {UP, DOWN, LEFT, RIGHT, START, EMPTY} button, oldButton;




#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16


void setup() {

  Serial.begin(9600);
  Wire.begin(2, 14); // SDA, SCL

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C, false, false)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  display.clearDisplay();


  pinMode(MatrixC0, OUTPUT);
  pinMode(MatrixC1, OUTPUT);
  pinMode(MatrixC2, OUTPUT);
  
  pinMode(MatrixR0, INPUT_PULLUP);
  pinMode(MatrixR1, INPUT_PULLUP);
  pinMode(MatrixR2, INPUT_PULLUP);
  

  // clear high score TODO with matrix
  if (digitalRead(PinSTART) == LOW && digitalRead(PinUP) == LOW) {

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
  button = RIGHT;
  oldButton = RIGHT;
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

  //
  uint16_t now = millis();

  if (now - lasttoggle > 1000) {

    lasttoggle = now;
    display.setTextColor(WHITE);
  } else if (now - lasttoggle > 500) {
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

Buttons getButtonPress() {
  Buttons rv = EMPTY;

  // Test for UP, LEFT or DOWN
  digitalWrite(MatrixC0, LOW);
  digitalWrite(MatrixC1, HIGH);
  digitalWrite(MatrixC2, HIGH);

  if (millis() - lastUP > TimePrell) {
    int valUP = digitalRead(MatrixR0);
    if (checkButton(valUP, &pinUPLow, &lastUP) == true) {
      Serial.println("UP");
      return UP;
    }
  }
  if (millis() - lastLEFT > TimePrell) {
    int valLEFT = digitalRead(MatrixR1);
    if (checkButton(valLEFT, &pinLEFTLow, &lastLEFT) == true) {
      Serial.println("LEFT");
      return LEFT;
    }
  }
  if (millis() - lastDOWN > TimePrell) {
    int valDOWN = digitalRead(MatrixR2);
    if (checkButton(valDOWN, &pinDOWNLow, &lastDOWN) == true) {
      Serial.println("DOWN");
      return DOWN;
    }
  }

  // Test for SELECT, START or RIGHT
  digitalWrite(MatrixC0, HIGH);
  digitalWrite(MatrixC1, LOW);
  digitalWrite(MatrixC2, HIGH);

  // TODO: Implement Select Button

  if (millis() - lastSTART > TimePrell) {
    int valSTART = digitalRead(MatrixR1);
    if (checkButton(valSTART, &pinSTARTLow, &lastSTART) == true) {
      Serial.println("START");
      return START;
    }
  }

  if (millis() - lastRIGHT > TimePrell) {
    int valRIGHT = digitalRead(MatrixR2);
    if (checkButton(valRIGHT, &pinRIGHTLow, &lastRIGHT) == true) {
      Serial.println("RIGHT");
      return RIGHT;
    }
  }

  // Test for A, B or Reserved
  digitalWrite(MatrixC0, HIGH);
  digitalWrite(MatrixC1, HIGH);
  digitalWrite(MatrixC2, LOW);

  // TODO: Implement A Button
  // TODO: Implement B Button
  // TODO: Implement Reserved Button



  digitalWrite(MatrixC0, HIGH);
  digitalWrite(MatrixC1, HIGH);
  digitalWrite(MatrixC2, HIGH);

  return rv;
}
bool checkButton(int val, bool* wasLow, unsigned long* lastTime) {
  if (val == LOW && (*wasLow) == true) {
    (*wasLow) = false;
    (*lastTime) = millis();
    return true;
  }
  if (val == HIGH && (*wasLow) == false) {
    (*lastTime) = millis();
    (*wasLow) = true;
  }
  return false;
}

void loop() {

  button = getButtonPress();

  if (!gameRunning) {
    if (button == START) {
      if (selectedOption == 1) {
        if (!inLeaderboard) {
          inLeaderboard = true;
          button = EMPTY;
          printLeaderBoard();
        } else {
          printWelcomeScreen();
          inLeaderboard = false;
          button = EMPTY;
        }

      } else {
        startGame();
      }
    }


    if (!inLeaderboard && !gameRunning) {

      if (button == UP) {
        selectedOption = 0;
        display.setTextColor(WHITE);

        display.setTextSize(1);
        display.setCursor(34, 55);
        display.println("LEADERBOARD");
      }

      if (button == DOWN) {
        selectedOption = 1;
        display.setTextColor(WHITE);
        display.setTextSize(1);
        display.setCursor(52, 43);
        display.println("START");
      }
      toggleText();
    }


  }


  if (gameRunning) {

    if (button != UP && button != DOWN && button != LEFT && button != RIGHT) {
      button = oldButton;
    }




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


    delay(SEGMENT_TIME);
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

  if (button == EMPTY) {
    button = oldButton;
  }

  switch (button) {

    case UP:
      if (oldButton == DOWN) {
        button = DOWN;
      }
      break;
    case DOWN:
      if (oldButton == UP) {
        button = UP;
      }
      break;
    case LEFT:
      if (oldButton == RIGHT) {
        button = RIGHT;
      }
      break;
    case RIGHT:
      if (oldButton == LEFT) {
        button = LEFT;
      }
      break;
  }

  oldButton = button;

  switch (button) {
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
  if (snake[headindex].x < 0 || snake[headindex].x > FIELD_SIZE_X - 1 || snake[headindex].y < 0 || snake[headindex].y > FIELD_SIZE_Y - 1) {
    return true;
  }
  return false;
}
