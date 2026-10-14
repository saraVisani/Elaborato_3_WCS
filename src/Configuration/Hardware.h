#ifndef __HARDWARE__
#define __HARDWARE__

#include "Globals.h"
#include "Util/Hardware/Api/IServoMotor.h"
#include "Util/Hardware/Api/ILcd.h"
#include "Util/Hardware/Api/IButton.h"
#include "Util/Hardware/Api/ISpot.h"

extern IButton* buttonReset;
extern ISpot* sensorPot;
extern ILcd* lcdDisplay;
extern IServoMotor* servoMotor;

class Hardware {
public:
    virtual void initAllHardware() = 0;
};

extern Hardware* hw;

#endif
