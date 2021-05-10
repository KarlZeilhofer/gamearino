
// Gamearino Hardware Test


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


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


uint8_t buttons=0; // Um mehrere Inputs gleichzeitig verarbeiten zu können
#define TimePrell 30

#define UP 1
#define DOWN 2
#define LEFT 4
#define RIGHT 8
#define A_Button 16
#define B_Button 32
#define START 64
#define SELECT 128

bool pinSTARTLow = true;
bool pinUPLow = true;
bool pinDOWNLow = true;
bool pinLEFTLow = true;
bool pinRIGHTLow = true;
bool pinSELECTLow = true;
bool pinA_ButtonLow = true;
bool pinB_ButtonLow = true;


unsigned long lastSTART = 0;
unsigned long lastUP = 0;
unsigned long lastDOWN = 0;
unsigned long lastLEFT = 0;
unsigned long lastRIGHT = 0;
unsigned long lastSELECT = 0;
unsigned long lastA_Button = 0;
unsigned long lastB_Button = 0;

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16


void setup() {

  Serial.begin(9600);
  
  pinMode(MatrixC0, OUTPUT);
  pinMode(MatrixC1, OUTPUT);
  pinMode(MatrixC2, OUTPUT);
  
  pinMode(MatrixR0, INPUT_PULLUP);
  pinMode(MatrixR1, INPUT_PULLUP);
  pinMode(MatrixR2, INPUT_PULLUP);

  Serial.println("Gamearino Hardware Test");
  
  Serial.print("Press UP...");
  do{
    getButtonPress();
  }while((buttons|UP) == 0);
  Serial.println("OK");

  Serial.print("Press DOWN...");
  do{
    getButtonPress();
  }while(buttons|DOWN == 0);
  Serial.println("OK");

  Serial.print("Test Display...");
  displayTest();
}


void displayTest() {
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C, false, false)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  Serial.print(F("Size of SSD1306: "));
  Serial.println(sizeof(display));
  display.clearDisplay();


  Wire.begin(2, 14); // SDA, SCL

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C, false, false)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  display.clearDisplay();

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(35, 5);
  display.println("Testscreen: ");
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
      rv |= LEFT;
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
      rv |= A_Button;
    }
  }
  // TODO: Implement B Button
  if (millis() - lastB_Button > TimePrell) {
    int valB_Button = digitalRead(MatrixR1);
    if (checkButton(valB_Button , &pinB_ButtonLow, &lastB_Button ) == true) {
      Serial.println("B");
      rv |= B_Button;
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
    (*lastTime) = millis();
    return true;
  }
  if (val == HIGH && (*wasLow) == false) {
    (*lastTime) = millis();
    (*wasLow) = true;
  }
  return false;
}

void loop()
{
  Serial.println("loop");
  delay(500);  
}

class Button
{
public:
  uint8_t pinColOut;
  uint8_t pinRowIn;

  Button(uint8_t pinColOut, uint8_t pinRowIn);
  uint32_t lastPressed;
  uint32_t lastReleased;

  static const int32_t T_Bounce = 20;
};

Button::Button(uint8_t pinColOut, uint8_t pinRowIn)
  :pinColOut(pinColOut), pinRowIn(pinRowIn)
{
  
}
