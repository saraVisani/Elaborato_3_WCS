#ifndef BUTTON_H
#define BUTTON_H

#include "./Util/Hardware/Api/IButton.h"

extern unsigned long lastPress;
extern unsigned long threshold;
extern volatile bool enabled;

class Button : public IButton {
private:
    bool activateInterrupt = false;
    static void irs();

public:
    void init(int pin = 0) override;

    inline bool isPressed() const override {
        return digitalRead(B_SWITCH) == LOW;
    }

    void enable() override {
        enabled = true;
    }

    void disable() override {
        enabled = false;
    }

    void addInterrupt() override;
};

#endif