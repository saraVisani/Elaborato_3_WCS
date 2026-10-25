#include "ManualValve.h"

void ManualValve::tick()
{
    int temp = sensorPot->readPercentage();
    servoMotor->setAngleWithPercentage(temp);
    unsigned int now = millis();
    if(lastChange == 0){
        lastChange = now;
    }
    if(now - lastChange >= THRESHOLD){
        State::setPercentage(temp);
    }
}