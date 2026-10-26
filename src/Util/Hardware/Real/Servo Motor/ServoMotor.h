#ifndef __SERVOMOTOR__
#define __SERVOMOTOR__

#include "./Util/Hardware/Api/IServoMotor.h"
#include <./Util/Libraries/ServoTimer2/ServoTimer2.h>

class ServoMotor : public IServoMotor {
    private:
        bool closed;
        bool opened;
        int angle;
        ServoTimer2 motor;
        int targetAngle = 0;
        unsigned long lastStepTime = 0;
        unsigned int stepDelay = 20;
        int stepSize = 1;
        int angleToPulse();
    public:
        void init(int pin = 0) override;
        inline bool isClosed() const override {
            return closed;
        }
        inline bool isOpened() const override {
            return opened;
        }
        inline bool greaterThan(int angle) const override {
            return angle > this->angle;
        }
        inline bool lessThan(int angle) const override {
            return angle < this->angle;
        }
        inline bool isClosing() const override {
            return !isClosed() && targetAngle == 0;
        }
        inline bool isOpening() const override {
            return !isOpened() && targetAngle == 180;
        }
        inline bool isMoving() const override {
            return angle != targetAngle;
        }
        inline int getAngle() const override {
            int percentage = map(angle, 0, 90, 0, 100);
            if (angle == targetAngle) {
                percentage = ((percentage + 2) / 5) * 5;
            }
            return constrain(percentage, 0, 100);
        }
        void close() override;
        void open() override;
        void update() override;
        void setAngleWithPercentage(int perc) override;
        void setNewAngle(int angle) override;
        void setPosition(int angle) override;
};

#endif