#ifndef __SPOT__
#define __SPOT__

#include "./Util/Hardware/Api/ISpot.h"

class Spot : public ISpot {
    private:
    public:
        void init(int pin = 0) override;
        int readPercentage() const override;
};

#endif