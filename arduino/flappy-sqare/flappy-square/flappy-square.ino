

#include <stdlib.h>
#include <time.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <stdint.h>
#include "button.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64


#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);




#define SPRITE_HEIGHT   16
#define SPRITE_WIDTH    16



#define GAME_SPEED 50

int game_state = 1;
int score = 0;
int high_score = 0;
int bird_x = (int)display.width() / 4;
int bird_y;
int momentum = 0;
int wall_x[2];
int wall_y[2];
int wall_gap = 30;
int wall_width = 10;

void setup() {

    Serial.begin(115200);
    delay(100);
    Serial.println("Welcome to Flappy Bird on Gamearino");
    Wire.begin(14,2); // SDA, SCL


  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C, false, false)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();

  printWelcomeScreen();

  display.setTextColor(WHITE);
  display.clearDisplay();


  randomSeed(analogRead(0));

}

void printWelcomeScreen() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(35, 5);
  display.println("Press Start:");
  display.setTextSize(2);
  display.setCursor(30, 20);
  display.println("UUF");
  display.setTextSize(1);
  display.setCursor(52, 43);
  display.println("START");
  display.display();
}

void loop() {
    buttons.readAll();

  if (game_state == 0) {

    display.clearDisplay();


    if (buttons.a->getEvent() == Button::PressedEvent) {
      momentum = -4;
    }

    momentum += 1;

    bird_y += momentum;

    if (bird_y < 0 ) {
      bird_y = 0;
    }

    if (bird_y > display.height() - SPRITE_HEIGHT) {
      bird_y = display.height() - SPRITE_HEIGHT;
      momentum = -2;
    }

    if (momentum < 0) {

      if (random(2) == 0) {
          display.fillRect(bird_x, bird_y, 16,16, WHITE);

      }
      else {
          display.fillRect(bird_x, bird_y, 16, 16, WHITE);

      }

    }
    else {

        display.fillRect(bird_x, bird_y, 16,16, WHITE);

    }

    for (int i = 0 ; i < 2; i++) {

      display.fillRect(wall_x[i], 0, wall_width, wall_y[i], WHITE);

      display.fillRect(wall_x[i], wall_y[i] + wall_gap, wall_width, display.height() - wall_y[i] + wall_gap, WHITE);

      if (wall_x[i] < 0) {
        wall_y[i] = random(0, display.height() - wall_gap);
        wall_x[i] = display.width();
      }

      if (wall_x[i] == bird_x) {
        score++;

        high_score = max(score, high_score);
      }

      if (
        (bird_x + SPRITE_WIDTH > wall_x[i] && bird_x < wall_x[i] + wall_width)
        &&
        (bird_y < wall_y[i] || bird_y + SPRITE_HEIGHT > wall_y[i] + wall_gap)
      ) {

        display.display();
        delay(500);

        game_state = 1;

      }

      wall_x[i] -= 4;
    }

    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(64, 0);
    display.println((String)score);
    //boldTextAtCenter(0, (String)score);




    display.display();
    delay(GAME_SPEED);

  }
  else {

//GAME OVER

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(35, 5);
    display.println("FLAPPY BIRD");



    display.setTextSize(2);
    display.setCursor(15, 20);
    display.println("GAME OVER");
    display.setTextSize(1);
    display.setCursor(52, 43);
    display.println((String)score);
    display.setCursor(23, 55);
    display.println("Highscore: ");
    display.println(high_score);
    display.display();




    while (buttons.a->getEvent() == Button::PressedEvent);

    bird_y = display.height() / 2;
    momentum = -4;
    wall_x[0] = display.width() ;
    wall_y[0] = display.height() / 2 - wall_gap / 2;
    wall_x[1] = display.width() + display.width() / 2;
    wall_y[1] = display.height() / 2 - wall_gap / 1;
    score = 0;

    while (buttons.a->getEvent() == Button::PressedEvent);


    game_state = 0;


  }

}




