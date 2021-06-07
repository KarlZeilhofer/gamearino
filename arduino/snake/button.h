#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>
#include <Arduino.h>

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
  Event peekEvent(); // returns event without clearing it
  void clearEvents();

private:
   Event event = NoEvent;
};

class Buttons
{
public:
    Buttons();
    void readAll();
    void clearAllEvents();

    Button* up;
    Button* down;
    Button* left;
    Button* right;
    Button* a;
    Button* b;
    Button* select;
    Button* start;
};

extern Buttons buttons;

#endif // BUTTON_H
