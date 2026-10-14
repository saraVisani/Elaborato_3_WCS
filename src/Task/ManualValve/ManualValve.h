#ifndef __MANUALVALVE__
#define __MANUALVALVE__

#include "Task/Task.h"

class ManualValve: public Task{
    private:

    public:
    void tick() override;
    bool guard() override {
    }
    inline TaskType getType() override {
        return TaskType::T_MANUALVALVE;
    };
};

#endif