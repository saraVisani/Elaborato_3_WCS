#include "UpdateValve.h"

void UpdateValve::tick()
{
    servoMotor->update();
}