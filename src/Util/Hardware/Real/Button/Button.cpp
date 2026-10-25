#include "Button.h"

unsigned long lastPress = 0;
unsigned long threshold = 20;
volatile bool enabled = true;

void Button::init(int pin) {
    pinMode(B_SWITCH, INPUT_PULLUP);
    addInterrupt();
}

void Button::addInterrupt() {
    attachInterrupt(digitalPinToInterrupt(B_SWITCH), irs, FALLING);
    activateInterrupt = true;
}

void Button::irs() {
    if(!enabled){
        return;
    }
    if (lastPress == 0 || millis() - lastPress >= threshold) {
        if(State::matchWorkState(WorkState::AUTOMATIC)){
            State::setWorkState(WorkState::MANUAL);
        } else {
            State::setWorkState(WorkState::AUTOMATIC);
        }
        lastPress = millis();
    }
}
