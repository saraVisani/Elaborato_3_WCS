#include "Spot.h"

void Spot::init(int pin) {
    pinMode(P_VALVE, INPUT);
}

int Spot::readPercentage() const {
    return 0;
}
