#ifndef __REALHARDWARE__
#define __REALHARDWARE__

#include "Hardware.h"

class RealHardware: public Hardware{
public:
    RealHardware();
    void initAllHardware() override;
};

#endif
