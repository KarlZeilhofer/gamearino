#include "button.h"

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

Buttons buttons;

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
            if(event == NoEvent){
                event = PressedEvent;
            }
            state = Pressed;
            tLastPressed = now;
        }
    }else{
        if((now+T_Bounce) >= tLastPressed && state == Pressed){
            if(event == NoEvent){
                event = ReleasedEvent;
            }
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

Button::Event Button::peekEvent()
{
    return event;
}

Buttons::Buttons()
{
    left = &buttonLeft;
    right = &buttonRight;
    up = &buttonUp;
    down = &buttonDown;
    a = &buttonA;
    b = &buttonB;
    select = &buttonSelect;
    start = &buttonStart;
}

void Buttons::readAll()
{
    left->read();
    right->read();
    up->read();
    down->read();
    a->read();
    b->read();
    select->read();
    start->read();
}

void Buttons::clearAllEvents()
{
    left->clearEvents();
    right->clearEvents();
    up->clearEvents();
    down->clearEvents();
    a->clearEvents();
    b->clearEvents();
    select->clearEvents();
    start->clearEvents();
}

void Button::clearEvents()
{
    event = NoEvent;
}
