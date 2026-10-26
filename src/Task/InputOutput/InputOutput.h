#ifndef __INPUTOUTPUT__
#define __INPUTOUTPUT__

#include "Task/Task.h"
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <float.h>

class InputOutput: public Task {

    private:
        void read();
        void send();
        int divideMessage(const String& message, String parts[], int maxParts);
        bool checkForNumber(const String& input, int& result);
        bool checkForNumber(const String& input, float& result);
    public:
        void tick() override;
        inline TaskType getType() override {
            return T_INPUTOUTPUT;
        }
};

#endif