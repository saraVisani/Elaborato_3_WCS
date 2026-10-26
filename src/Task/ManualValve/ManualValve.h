#ifndef __MANUALVALVE__
#define __MANUALVALVE__

#include "Task/Task.h"

class ManualValve: public Task{
    private:
        int lastMeasure = -1;
        unsigned long lastChange = 0;
        const unsigned int THRESHOLD = 1000;
    public:
    void tick() override;
    bool guard() override {
        return (State::matchWorkState(WorkState::MANUAL)
            || (State::matchSystemState(ProblemState::UNCONNECTED) || State::matchSystemState(ProblemState::UNCON_NOTAVAIL)))
            && (State::matchHandshakeState(HandshakeState::IDLE) || State::matchHandshakeState(HandshakeState::STATE));
    }
    inline TaskType getType() override {
        return TaskType::T_MANUALVALVE;
    };
};

#endif