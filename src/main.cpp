#include <Configuration/Includes.h>

RealTimer timer;
Scheduler scheduler(timer);

void setup() {
  hw->initAllHardware();
  scheduler.init(25);
  Task* ioTask = new InputOutput();
  ioTask->init(50);
  scheduler.addTask(ioTask);
  Task* lcdTask = new TaskLCD();
  lcdTask->init(50);
  scheduler.addTask(lcdTask);
  Task* manualTask = new ManualValve();
  manualTask->init(50);
  scheduler.addTask(manualTask);
  Task* valveTask = new UpdateValve();
  valveTask->init(25);
  scheduler.addTask(valveTask);
}

void loop() {
  scheduler.schedule();
}