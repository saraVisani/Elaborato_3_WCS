#ifndef __ISPOT__
#define __ISPOT__

#include "./Util/Hardware/Component.h"

class ISpot : public Component {
    public:
        inline HardwareType getType() override {
            return HardwareType::POTENTIOMETER;
        }
        virtual int readPercentage() const = 0;
};

#endif