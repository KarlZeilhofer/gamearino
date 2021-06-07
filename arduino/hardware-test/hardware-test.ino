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


#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

enum Direction{UP, DOWN, LEFT, RIGHT};
Direction direction;
#define START_DELAY 500
uint32_t moveDelay=START_DELAY; // start delay in ms

bool anyButtonPressed = false;


void setup() {
    Serial.begin(115200);
    delay(100);
    Serial.println("Gamearino Hardware Test");
    Wire.begin(14,2); // SDA, SCL

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C, false, false)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;); // Don't proceed, loop forever
    }

    display.clearDisplay();
    display.setCursor(0,0);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.print("Gamearino HW-Test");
    display.display();
    delay(1000);
    display.clearDisplay();
    display.display();
}

void loop(){
    printButton();
    delay(10);

    static bool ticToc=false;

    if(anyButtonPressed == false){
        if((millis()/2000)%2 == 0 && ticToc == false){
            display.fillRect(0,0,128,64, WHITE);
            ticToc = true;
        }
        if ((millis()/2000)%2 == 1 && ticToc == true){
            display.clearDisplay();
            ticToc = false;
        }
        display.display();
    }
}

void printButton() {
    if(anyButtonPressed){
        display.clearDisplay();
    }
    display.setCursor(0,0);
    display.setTextSize(1);
    display.setTextColor(WHITE);

    if(buttons.left->read() == Button::Pressed){
        display.println("LEFT");
        anyButtonPressed = true;
    }
    if(buttons.right->read() == Button::Pressed){
        display.println("RIGHT");
        anyButtonPressed = true;
    }
    if(buttons.up->read() == Button::Pressed){
        display.println("UP");
        anyButtonPressed = true;
    }
    if(buttons.down->read() == Button::Pressed){
        display.println("DOWN");
        anyButtonPressed = true;
    }
    if(buttons.select->read() == Button::Pressed){
        display.println("SELECT");
        anyButtonPressed = true;
    }
    if(buttons.start->read() == Button::Pressed){
        display.println("START");
        anyButtonPressed = true;
    }
    if(buttons.a->read() == Button::Pressed){
        display.println("A");
        anyButtonPressed = true;
    }
    if(buttons.b->read() == Button::Pressed){
        display.println("B");
        anyButtonPressed = true;
    }

    display.display();
}


