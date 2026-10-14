#ifndef __TASKLCD__
#define __TASKLCD__

#include "Task/Task.h"

class TaskLCD: public Task{
    public:
        void tick() override;
        inline TaskType getType() override{
            return TaskType::T_LCD;
        }
};
#endif