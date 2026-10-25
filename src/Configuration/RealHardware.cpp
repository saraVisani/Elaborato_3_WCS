#include "RealHardware.h"

#include "./Util/Hardware/Component.h"
#include "./Util/Hardware/Real/LCD/Lcd.h"
#include "./Util/Hardware/Real/Servo Motor/ServoMotor.h"
#include "./Util/Hardware/Real/Button/Button.h"
#include "./Util/Hardware/Real/S_Pot/Spot.h"

Hardware* hw = nullptr;

Button buttonResetInstance;
Spot sensorPotInstance;
Lcd lcdDisplayInstance;
ServoMotor servoMotorInstance;

IButton* buttonSwitch = &buttonResetInstance;
ISpot* sensorPot = &sensorPotInstance;
ILcd* lcdDisplay = &lcdDisplayInstance;
IServoMotor* servoMotor = &servoMotorInstance;

RealHardware::RealHardware() {
    hw = this;
}

void RealHardware::initAllHardware() {
    buttonSwitch->init();
    sensorPot->init();
    lcdDisplay->init();
    servoMotor->init();
}

static RealHardware realHw;
