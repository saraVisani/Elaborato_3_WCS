#ifndef __SPOT__
#define __SPOT__

#include "./Util/Hardware/Api/ISpot.h"

class Spot : public ISpot {
    private:
        bool active = true;
    public:
        void init(int pin = 0) override;
        int readPercentage() const override;
        void enable() override {
            active = true;
        }

        void disable() override {
            active = false;
        }
};

#endif