#include "Scheduler.h"

Scheduler::Scheduler(Timer &t) : timer(t) {
    nTasks = 0;
    activateTaskLed = false;
}

void Scheduler::init(int basePeriod) {
    this->basePeriod = basePeriod;
    timer.setupPeriod(basePeriod);
    nTasks = 0;
    activateTaskLed = false;
}

bool Scheduler::addTask(Task *task) {
    if (nTasks < MAX_TASKS - 1)
    {
        taskList[nTasks] = task;
        nTasks++;
        return true;
    }
    else
    {
        return false;
    }
}

void Scheduler::schedule() {
    timer.waitForNextTick();
    for (int i = 0; i < nTasks; i++)
    {
        if (    taskList[i]->guard()
                && taskList[i]->updateAndCheckTime(basePeriod)){
            taskList[i]->tick();
        }
    }
}

void Scheduler::reset() {
    nTasks = 0;               // nessun task schedulato
    for(int i = 0; i < MAX_TASKS; i++) {
        taskList[i] = nullptr; // rimuove riferimenti ai task
    }
}
