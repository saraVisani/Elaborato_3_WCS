#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "./Timer/Timer.h"
#include "./Task/Task.h"
#include "./Configuration/Globals.h"

#define MAX_TASKS 10

class Scheduler {
private:
    int basePeriod;
    int nTasks;
    Task *taskList[MAX_TASKS];
    Timer &timer;

public:
    /**
     * Costruttore che accetta un Timer come riferimento
     * @param t Timer da usare per lo scheduling
     */
    Scheduler(Timer &t);

    void init(int basePeriod);

    virtual bool addTask(Task *task);

    /**
     * The schedule method is called in the main loop to run the scheduler.
     */
    virtual void schedule();

    /**
     * Just for debug not safe remove of tasks
     */
    void reset();
};

#endif