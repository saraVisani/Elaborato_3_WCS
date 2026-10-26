#include "Spot.h"

void Spot::init(int pin) {
    pinMode(P_VALVE, INPUT);
}

int Spot::readPercentage() const {
    if (!active) {
        return -1;
    }

    int value = analogRead(P_VALVE);
    int percentage = map(value, 30, 950, 0, 20) * 5;

    return constrain(percentage, 0, 100);
}
