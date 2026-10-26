#include <Configuration/Includes.h>

RealTimer timer;
Scheduler scheduler(timer);

void setup() {
  Serial.begin(9600);
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
  valveTask->init(75);
  scheduler.addTask(valveTask);
  lcdDisplay->print("AUTO    WL   0.0", "NOW   0% OBJ  0%");
}

void loop() {
  scheduler.schedule();
}