#ifndef __INPUTOUTPUT__
#define __INPUTOUTPUT__

#include "Task/Task.h"

class InputOutput: public Task {

    private:
        void read();
        void send();

    public:
        void tick() override;
        bool guard() override {
            return State::matchSystemState(OK);
        }
        inline TaskType getType() override {
            return T_INPUTOUTPUT;
        }
};

#endif