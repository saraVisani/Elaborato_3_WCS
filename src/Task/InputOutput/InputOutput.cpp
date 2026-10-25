#include "InputOutput.h"

void InputOutput::read() {
    while(Serial.available()) {
        String incoming = Serial.readStringUntil('\n');
        incoming.trim();
        String listMess[4];
        int count = this->divideMessage(incoming, listMess, 4);
        for (int i = 0; i < count; i++) {
            switch (i)
            {
            case 0:{
                WorkState temp = State::stringToWorkState(listMess[i].c_str());
                if(temp != WorkState::UNKNOWN_WORK_STATE){
                    State::setWorkState(temp);
                    State::setHandshakeState(HandshakeState::IDLE);
                    buttonSwitch->enable();
                    sensorPot->enable();
                } else {
                    State::setHandshakeState(HandshakeState::UNKNOWN_HANDSHAKE_STATE);
                }
                break;
            }
            case 1:{
                if(State::matchHandshakeState(HandshakeState::IDLE)){
                    ProblemState temp = State::stringToSystemState(listMess[i].c_str());
                    if(temp != ProblemState::UNKNOWN_PROBLEM_STATE){
                        State::setSystemState(temp);
                    }
                } else {
                    HandshakeState temp = State::stringToHandshakeState(listMess[i].c_str());
                    if(temp == HandshakeState::UNKNOWN_HANDSHAKE_STATE){
                        State::setHandshakeState(HandshakeState::IDLE);
                    } else {
                        State::setHandshakeState(temp);
                    }
                    switch (temp)
                    {
                        case HandshakeState::ALL:
                            sensorPot->disable();
                            buttonSwitch->disable();
                            break;
                        case HandshakeState::STATE:
                            buttonSwitch->disable();
                            break;
                        case HandshakeState::VALVE:
                            sensorPot->disable();
                            break;
                        default:
                            buttonSwitch->enable();
                            sensorPot->enable();
                            break;
                    }
                }
                break;
            }
                case 2:{
                    if(State::isNotSystemState(ProblemState::UNCON_NOTAVAIL) && State::isNotSystemState(ProblemState::UNCONNECTED)){
                        float floatValue;
                        if (checkForNumber(listMess[i], floatValue)) {
                            State::setWaterLevel(floatValue);
                        }
                    } else {
                        int integerValue;
                        if (checkForNumber(listMess[i], integerValue)) {
                            if(State::getPercentage() != integerValue && integerValue >= 0 && integerValue <= 0){
                                State::setPercentage(integerValue);
                                servoMotor->setAngleWithPercentage(integerValue);
                            }
                        }
                    }
                    break;
                }
            default:{
                    int integerValue;
                    if (checkForNumber(listMess[i], integerValue)) {
                        if(State::getPercentage() != integerValue && integerValue >= 0 && integerValue <= 0){
                            State::setPercentage(integerValue);
                            servoMotor->setAngleWithPercentage(integerValue);
                        }
                    }
                    break;
                }
            }
        }
    }
}

int InputOutput::divideMessage(const String& message, String parts[], int maxParts) {
    for (int i = 0; i < maxParts; i++) {
        parts[i] = "";
    }

    int start = 0;
    int count = 0;

    for (int i = 0; i <= message.length() && count < maxParts; i++) {
        if (i == message.length() || message[i] == '-') {
            parts[count++] = message.substring(start, i);
            start = i + 1;
        }
    }

    return count;
}

bool InputOutput::checkForNumber(const String& input, int& result) {
    if (input.length() == 0) {
        return false;
    }

    char* end;
    long value = strtol(input.c_str(), &end, 10);

    // Controlla che tutta la stringa sia un numero intero
    if (end == input.c_str() || *end != '\0') {
        return false;
    }

    // Controlla che il numero rientri nei limiti di int
    if (value < INT_MIN || value > INT_MAX) {
        return false;
    }

    result = (int)value;
    return true;
}

bool InputOutput::checkForNumber(const String& input, float& result) {
    if (input.length() == 0) {
        return false;
    }

    char* end;
    double value = strtod(input.c_str(), &end);

    // Controlla che tutta la stringa sia un numero
    if (end == input.c_str() || *end != '\0') {
        return false;
    }

    // Rifiuta valori non finiti o troppo grandi per un float
    if (!isfinite(value) || value > FLT_MAX || value < -FLT_MAX) {
        return false;
    }

    result = (float)value;
    return true;
}

void InputOutput::send() {
    String statusMessage = "";

    if (State::isNotHandshakeState(HandshakeState::IDLE)) {
        if (State::matchHandshakeState(HandshakeState::VALVE)) {
            statusMessage = State::currentWorkStateString() + "-";
        }

        statusMessage += String(servoMotor->getAngle());

        if (State::matchHandshakeState(HandshakeState::STATE)) {
            statusMessage += "-" + String(State::getPercentage());
        }
    } else {
        statusMessage = State::currentWorkStateString() + "-" + String(servoMotor->getAngle());

        if (State::matchWorkState(WorkState::MANUAL)) {
            statusMessage += "-" + String(State::getPercentage());
        }
    }
    Serial.println(statusMessage);
}

void InputOutput::tick() {
    read();
    send();
}