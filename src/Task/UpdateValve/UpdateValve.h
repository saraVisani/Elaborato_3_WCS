#ifndef __UPDATEVALVE__
#define __UPDATEVALVE__

#include "Task/Task.h"

class UpdateValve : public Task {
    public:
    inline TaskType getType() override {
            return T_UPDATEVALVE;
        }
    void tick() override;
};

#endif