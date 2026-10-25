#include "Spot.h"

void Spot::init(int pin) {
    pinMode(P_VALVE, INPUT);
}

int Spot::readPercentage() const {
    if (!active) {
        return -1;  // Potentiometer is inactive
    }

    int value = analogRead(P_VALVE);

    // Convert the analog reading to a percentage from 0 to 100.
    int percentage = map(value, 0, 1023, 0, 100);

    // Round to the nearest multiple of 5.
    percentage = ((percentage + 2) / 5) * 5;

    return constrain(percentage, 0, 100);
}
