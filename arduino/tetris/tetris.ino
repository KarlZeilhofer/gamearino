
//TETRIS - TODO-List:
//-Tetrominos müssen sich drehen können
//-Links-Rechts steuerung funktioniert noch nicht optimal, außerdem gibt es noch keine Grenze nach Links/Rechts
//-schnelleres Fallen mit DOWN Button
//-Reihe wird gecleared wenn alle Blöcke voll sind
//-Man verliert wenn man ganz oben ankommt
//-Der nächste Tetromino soll rechts angezeigt weden, so wie ein passender Score
//-Level System, nach gewisser Zeit fallen die Bläcke schneller






typedef struct point {
  uint8_t x;
  uint8_t y;
} point;
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


#define SEGMENT_TIME 500//Zeit bis 1 Segment vorwärts
#define SEGMENT_SIZE 3
#define START_LEN 3
#define FIELD_SIZE_X 12
#define FIELD_SIZE_Y 21
#define ARR_LEN 100

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

#define PinSTART 2
#define PinUP 3
#define PinDOWN 4
#define PinLEFT 5
#define PinRIGHT 6
#define TimePrell 30

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


point [4] = {0};
point groundBlock[ARR_LEN] = {0};

uint16_t field [21] = {0};

int num;
uint16_t len = START_LEN;
uint8_t score = 0;
uint8_t highscore = 0;
bool gameRunning = false;
bool inLeaderboard = false;
uint8_t selectedOption = 0;
uint16_t oldtime;
uint16_t starttime;
uint16_t lasttoggle = 0;
int mult;
int turnstate;
int count;
int zw;
point eatPos;
bool firstBlock = true;

int chosenBlock;
int nextBlock

bool pinSTARTLow = true;
bool pinUPLow = true;
bool pinDOWNLow = true;
bool pinLEFTLow = true;
bool pinRIGHTLow = true;
bool pinSELECTLow = true;
bool pinA_Button = true;
bool pinB_Button = true;


unsigned long lastSTART = 0;
unsigned long lastUP = 0;
unsigned long lastDOWN = 0;
unsigned long lastLEFT = 0;
unsigned long lastRIGHT = 0;
unsigned long lastSELECT = 0;
unsigned long lastA_Button = 0;
unsigned long lastB_Button = 0;





enum Buttons {UP, DOWN, LEFT, RIGHT, START, EMPTY} button, oldButton;

uint8_t buttons; // Um mehrere Inputs gleichzeitig verarbeiten zu können
#define UP 1
#define DOWN 2
#define LEFT 4
#define Right 8
#define A_Button 16
#define B_Button 32
#define START 64
#define Select 128

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16


void setup() {

  Serial.begin(9600);


  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C, false, false)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  Serial.print(F("Size of SSD1306: "));
  Serial.println(sizeof(display));
  display.clearDisplay();



  pinMode(PinSTART, INPUT_PULLUP);
  pinMode(PinUP, INPUT_PULLUP);
  pinMode(PinDOWN, INPUT_PULLUP);
  pinMode(PinLEFT, INPUT_PULLUP);
  pinMode(PinRIGHT, INPUT_PULLUP);


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
  formBlock();
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
  display.println("TETRIS");
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

uint8_t getButtonPress() {
  uint8_t rv = 0;
// Button Matrix 
// UP      C0-R0
// DOWN    C0-R2
// LEFT    C0-R1
// RIGHT   C1-R2
// SELECT  C1-R0
// START   C1-R1
// B       C2-R1
// A       C2-R0
  // Test for UP, LEFT or DOWN
  digitalWrite(MatrixC0, LOW);
  digitalWrite(MatrixC1, HIGH);
  digitalWrite(MatrixC2, HIGH);

  if (millis() - lastUP > TimePrell) {
    int valUP = digitalRead(MatrixR0);
    if (checkButton(valUP, &pinUPLow, &lastUP) == true) {
      Serial.println("UP");
      rv |= UP;
    }
  }
  if (millis() - lastLEFT > TimePrell) {
    int valLEFT = digitalRead(MatrixR1);
    if (checkButton(valLEFT, &pinLEFTLow, &lastLEFT) == true) {
      Serial.println("LEFT");
      rv|= LEFT;
    }
  }
  if (millis() - lastDOWN > TimePrell) {
    int valDOWN = digitalRead(MatrixR2);
    if (checkButton(valDOWN, &pinDOWNLow, &lastDOWN) == true) {
      Serial.println("DOWN");
      rv |= DOWN;
    }
  }

  // Test for SELECT, START or RIGHT
  digitalWrite(MatrixC0, HIGH);
  digitalWrite(MatrixC1, LOW);
  digitalWrite(MatrixC2, HIGH);

  if (millis() - lastSELECT > TimePrell) {
    int valSELECT = digitalRead(MatrixR0);
    if (checkButton(valSELECT, &pinSELECTLow, &lastSELECT) == true) {
      Serial.println("SELECT");
      rv |= SELECT;
    }
  }

  if (millis() - lastSTART > TimePrell) {
    int valSTART = digitalRead(MatrixR1);
    if (checkButton(valSTART, &pinSTARTLow, &lastSTART) == true) {
      Serial.println("START");
      rv |= START;
    }
  }

  if (millis() - lastRIGHT > TimePrell) {
    int valRIGHT = digitalRead(MatrixR2);
    if (checkButton(valRIGHT, &pinRIGHTLow, &lastRIGHT) == true) {
      Serial.println("RIGHT");
      rv |= RIGHT;
    }
  }

  // Test for A, B or Reserved
  digitalWrite(MatrixC0, HIGH);
  digitalWrite(MatrixC1, HIGH);
  digitalWrite(MatrixC2, LOW);

// TODO: Implement A Button
if (millis() - lastA_Button > TimePrell) {
    int valA_Button = digitalRead(MatrixR0);
    if (checkButton(A_Button, &pinA_ButtonLow, &lastA_Button) == true) {
      Serial.println("A");
      rv |= A;
    }
  } 
  // TODO: Implement B Button
  if (millis() - lastB_Button > TimePrell) {
    int valB_Button = digitalRead(MatrixR1);
    if (checkButton(valB_Button , &pinB_ButtonLow, &lastB_Button ) == true) {
      Serial.println("B");
      rv |= B;
    }
  }
  // TODO: Implement Reserved Button


  digitalWrite(MatrixC0, HIGH);
  digitalWrite(MatrixC1, HIGH);
  digitalWrite(MatrixC2, HIGH);

  return rv;
}

bool checkButton(int val, bool* wasLow, unsigned long* lastTime) {
  if (val == LOW && (*wasLow) == true) {
    (*wasLow) = false;
    (*lastTime)=millis();
    return true;
  }
  if (val == HIGH&&(*wasLow)==false) {
    (*lastTime)=millis();
    (*wasLow) = true;
  }
  return false;
}

void loop() {

  button = getButtonPress();

  if (!gameRunning) {
    if (button&START) {
      if (selectedOption == 1) {
        if (!inLeaderboard) {
          inLeaderboard = true;
          button = 0;
          printLeaderBoard();
        } else {
          printWelcomeScreen();
          inLeaderboard = false;
          button = 0;
        }

      } else {
        startGame();
      }
    }


    if (!inLeaderboard && !gameRunning) {

      if (button&UP) {
        selectedOption = 0;
        display.setTextColor(WHITE);

        display.setTextSize(1);
        display.setCursor(34, 55);
        display.println("LEADERBOARD");
      }

      if (button&DOWN) {
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


    if (borderCross()) {

      gameRunning = false;
      checkHighscore();
      printWelcomeScreen();


      return;

    }



 
if (!collab()) {
 

  for(uint16_t i = 0; i < 4; ++i) {
      display.drawRect(tetro[i].x * SEGMENT_SIZE + 1, tetro[i].y * SEGMENT_SIZE + 1, 2, 2, SSD1306_BLACK);
      tetro[i].y = tetro[i].y + 1;
    } 
    
  for(uint16_t i = 0; i < 4; ++i) {
      display.drawRect(tetro[i].x * SEGMENT_SIZE + 1, tetro[i].y * SEGMENT_SIZE + 1, 2, 2, SSD1306_WHITE);
    }
} else{
      
  for(uint16_t i = 0; i < 4; ++i) {
    tetro[i].y = tetro[i].y - 1;
    field[tetro[i].y] = field[tetro[i].y] | (1 << tetro[i].x);   
  }
  formBlock();
  }
  
  
    button = 0;
    oldButton = 0;

    printTime();
    display.display(); // Daten auf display schreiben.


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
  display.println("NEXT");
  display.setCursor(98, 23);
  display.println("SCORE");

//  display.setCursor(98, 45);
 // display.println("Time");
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

void formBlock() {
chooseBlocks();
turnstate = 0;
 if(chosenBlock == 0) {
    // I
  tetro[0].x = 3;
  tetro[0].y = 4;
  tetro[1].x = 4;
  tetro[1].y = 4;
  tetro[2].x = 5;
  tetro[2].y = 4;
  tetro[3].x = 6;
  tetro[3].y = 4;

  }else if(chosenBlock == 1) {
    // J
  tetro[0].x = 4;
  tetro[0].y = 3;
  tetro[1].x = 4;
  tetro[1].y = 4;
  tetro[2].x = 5;
  tetro[2].y = 4;
  tetro[3].x = 6;
  tetro[3].y = 4;
  }else if(chosenBlock == 2) {
    // L
  tetro[0].x = 4;
  tetro[0].y = 4;
  tetro[1].x = 4;
  tetro[1].y = 3;
  tetro[2].x = 5;
  tetro[2].y = 3;
  tetro[3].x = 6;
  tetro[3].y = 3;
  }else if(chosenBlock == 3) {
    // O
  tetro[0].x = 4;
  tetro[0].y = 4;
  tetro[1].x = 4;
  tetro[1].y = 3;
  tetro[2].x = 5;
  tetro[2].y = 4;
  tetro[3].x = 5;
  tetro[3].y = 3;
  }else if(chosenBlock == 4) {
    // S
  tetro[0].x = 4;
  tetro[0].y = 4;
  tetro[1].x = 5;
  tetro[1].y = 4;
  tetro[2].x = 5;
  tetro[2].y = 3;
  tetro[3].x = 6;
  tetro[3].y = 3;
  }else if(chosenBlock == 5) {
    // T
  tetro[0].x = 4;
  tetro[0].y = 4;
  tetro[1].x = 5;
  tetro[1].y = 4;
  tetro[2].x = 5;
  tetro[2].y = 3;
  tetro[3].x = 6;
  tetro[3].y = 4;
  }else if(chosenBlock == 6) {
    // Z
  tetro[0].x = 4;
  tetro[0].y = 3;
  tetro[1].x = 5;
  tetro[1].y = 3;
  tetro[2].x = 5;
  tetro[2].y = 4;
  tetro[3].x = 6;
  tetro[3].y = 4; 
  }

      for(uint16_t i = 0; i < 4; ++i) {
      display.drawRect(tetro[i].x * SEGMENT_SIZE + 1, tetro[i].y * SEGMENT_SIZE + 1, 2, 2, SSD1306_WHITE);
    }
 
  display.display(); // daten auf display schreiben.
}



void chooseBlocks() { //generiere einen neuen zufälligen Block

if(firstBlock == true){
chosenBlock = rand() % 7;
firstBlock = false;
}
chosenBlock = nextBlock
nextBlock = rand() % 7;

 display.setCursor(98, 70); // 70 gewählt prüfen !!
 display.println(nextBlock);
 
}



  




void control() {



//if(button==EMPTY){
//  button=oldButton;
//}

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

      break;
    case LEFT:
 for(uint16_t i = 0; i < 4; ++i) {
        display.drawRect(tetro[i].x * SEGMENT_SIZE + 1, tetro[i].y * SEGMENT_SIZE + 1, 2, 2, SSD1306_BLACK);
     tetro[i].x = tetro[i].x - 1;
    }
      break;
    case RIGHT:
    for(uint16_t i = 0; i < 4; ++i) {
        display.drawRect(tetro[i].x * SEGMENT_SIZE + 1, tetro[i].y * SEGMENT_SIZE + 1, 2, 2, SSD1306_BLACK);
     tetro[i].x = tetro[i].x + 1;
    }
      break;
    case DOWN:

      break;
  }
  /*
  
  if(button == LEFT) {
 for(uint16_t i = 0; i < 4; ++i) {
        display.drawRect(tetro[i].x * SEGMENT_SIZE + 1, tetro[i].y * SEGMENT_SIZE + 1, 2, 2, SSD1306_BLACK);
     tetro[i].x = tetro[i].x - 1;
    }
} else if(button == RIGHT) {
 for(uint16_t i = 0; i < 4; ++i) {
        display.drawRect(tetro[i].x * SEGMENT_SIZE + 1, tetro[i].y * SEGMENT_SIZE + 1, 2, 2, SSD1306_BLACK);
     tetro[i].x = tetro[i].x + 1;
    }
}

  button = 0;
  oldButton = 0;

 * 
   */
}





bool collab() {
// int a;
// int b;


  for(uint16_t i = 0; i < 4; ++i) {
    if (tetro[i].y > FIELD_SIZE_Y - 2) {
    return true;
   }else if(bitRead(field[tetro[i].y], tetro[i].x) == 1) {
    return true;
   }
  }
  


   
  return false;

}

bool borderCross() {
  if (tetro[0].y > FIELD_SIZE_Y - 1) {
    return true;
  }
  return false;
}
