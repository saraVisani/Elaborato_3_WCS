#include "ServoMotor.h"

void ServoMotor::init(int pin) {
    motor.attach(P_SERVOMOTOR);
    angle = 0;
    targetAngle = 0;
    closed = true;
    opened = false;
    lastStepTime = 0;
    motor.write(angle);
}

int ServoMotor::angleToPulse(){
    return map(this->angle, 0, 180, 750, 2400);
}

void ServoMotor::setPosition(int angle) {
    this->angle = angle;
    motor.write(angleToPulse());
    opened = (angle == 90);
    closed = (angle == 0);
}

// -------------------------
// GRADUAL MOVEMENT
// -------------------------

void ServoMotor::open() {
    if(targetAngle != 90) targetAngle = 90;
}

void ServoMotor::close() {
    if(targetAngle != 0) targetAngle = 0;
}

void ServoMotor::setNewAngle(int angle) {
    if(angle < 0 || angle > 90) return;
    targetAngle = angle;
}

void ServoMotor::setAngleWithPercentage(int perc) {
    int angle = map(perc, 0, 100, 0, 90);
    this->setNewAngle(angle);
}

void ServoMotor::update() {
    if (angle == targetAngle) return;

    // L'avanzamento avviene ad ogni chiamata dello Scheduler (ogni 10 ms)
    if (angle < targetAngle) {
        angle += stepSize;
        if (angle > targetAngle) angle = targetAngle;
    } else {
        angle -= stepSize;
        if (angle < targetAngle) angle = targetAngle;
    }

    setPosition(angle);
}
