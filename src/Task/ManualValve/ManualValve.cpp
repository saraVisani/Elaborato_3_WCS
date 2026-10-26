#include "ManualValve.h"

void ManualValve::tick()
{
    int temp = sensorPot->readPercentage();
    if(firstChangeAuto){
        Serial.println(lastMeasure);
        Serial.println(temp);
        if(lastMeasure == temp){
            return;
        }
        firstChangeAuto = false;
    }
    unsigned long now = millis();
    servoMotor->setAngleWithPercentage(temp);
    if (temp != lastMeasure) {
        lastMeasure = temp;
        lastChange = now;
        return;
    }
    if (now - lastChange >= THRESHOLD) {
        if (State::getPercentage() != temp) {
            State::setPercentage(temp);
        }
    }
}