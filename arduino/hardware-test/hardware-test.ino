
// Gamearino Hardware Test
#include <stdlib.h>
#include <time.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>



class Button
{
public:
  uint8_t pinColOut;
  uint8_t pinRowIn;

  Button(uint8_t pinColOut, uint8_t pinRowIn);
  
  
  uint32_t tLastPressed;
  uint32_t tLastReleased;
  enum State{Pressed, Released} state;
  enum Event{NoEvent, PressedEvent, ReleasedEvent};

  static const int32_t T_Bounce = 20;

  State read();
  Event getEvent(); // clears the event state

private:
   Event event = NoEvent;
};



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

Button buttonUp(MatrixC0, MatrixR0);
Button buttonLeft(MatrixC0, MatrixR1);
Button buttonDown(MatrixC0, MatrixR2);
Button buttonSelect(MatrixC1, MatrixR0);
Button buttonStart(MatrixC1, MatrixR1);
Button buttonRight(MatrixC1, MatrixR2);
Button buttonA(MatrixC2, MatrixR0);
Button buttonB(MatrixC2, MatrixR1);

Button* buttonList[8] = {
    &buttonUp, &buttonLeft, &buttonDown, &buttonSelect, 
    &buttonStart, &buttonRight, &buttonA, &buttonB
  };




// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16


void setup() {

  Serial.begin(9600);

  Serial.println("Gamearino Hardware Test");
  
  Serial.print("Press UP...");
  do{
    buttonUp.read();
  }while(buttonUp.state == Button::Released);
  Serial.println("OK");

  Serial.print("Press DOWN...");
  do{
    buttonDown.read();
  }while(buttonDown.state == Button::Released);
  Serial.println("OK");

  Serial.print("Press LEFT...");
  do{
    buttonLeft.read();
  }while(buttonLeft.state == Button::Released);
  Serial.println("OK");

  Serial.print("Press RIGHT...");
  do{
    buttonRight.read();
  }while(buttonRight.state == Button::Released);
  Serial.println("OK");

  Serial.print("Press SELECT...");
  do{
    buttonSelect.read();
  }while(buttonSelect.state == Button::Released);
  Serial.println("OK");

  Serial.print("Press START...");
  do{
    buttonStart.read();
  }while(buttonStart.state == Button::Released);
  Serial.println("OK");

  Serial.print("Press A...");
  do{
    buttonA.read();
  }while(buttonA.state == Button::Released);
  Serial.println("OK");

  Serial.print("Press B...");
  do{
    buttonB.read();
  }while(buttonB.state == Button::Released);
  Serial.println("OK");

  Serial.print("Test Display...");
  displayTest();
}


void loop()
{
  Serial.println("loop");
  delay(2000);  
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


Button::Button(uint8_t pinColOut, uint8_t pinRowIn)
  :pinColOut(pinColOut), pinRowIn(pinRowIn)
{
  tLastPressed = 0;
  tLastReleased = 0;
  state = Released;

  pinMode(pinColOut, OUTPUT);
  digitalWrite(pinColOut, HIGH);
  pinMode(pinRowIn, INPUT_PULLUP);
}

Button::State Button::read()
{
  digitalWrite(pinColOut, LOW);
  bool in = digitalRead(pinRowIn);
  uint32_t now = millis();

  if(in == LOW){ // if pressed
    if((now+T_Bounce) >= tLastPressed && state == Released){
      event = PressedEvent;
      state = Pressed;
      tLastPressed = now;
    }
  }else{
    if((now+T_Bounce) >= tLastPressed && state == Pressed){
      event = ReleasedEvent;
      state = Released;
      tLastReleased = now;
    }
  }

  // necessary cooperation of column pins:
  digitalWrite(pinColOut, HIGH);

  return state;
}

Button::Event Button::getEvent(){
  Event ret = event;
  event = NoEvent;
  return ret;
}
