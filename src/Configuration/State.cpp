#include "Globals.h"

bool matchHardwareType(HardwareType t1, String t2) {
    HardwareType ht;
    if(t2 == "BUTTON") ht = BUTTON;
    else if(t2 == "LCD") ht = LCD;
    else if(t2 == "POTENTIOMETER") ht = POTENTIOMETER;
    else if(t2 == "SERVO_MOTOR") ht = SERVO_MOTOR;
    else return false;

    return t1 == ht;
}

bool isNotHardwareType(HardwareType t1, String t2) {
    return !matchHardwareType(t1, t2);
}

bool matchTaskType(TaskType t1, String t2) {
    TaskType tt;
    if(t2 == "T_INPUTOUTPUT") {
        tt = T_INPUTOUTPUT;
    } else if(t2 == "T_LCD") {
        tt = T_LCD;
    } else if(t2 == "T_UPDATEVALVE") {
        tt = T_UPDATEVALVE;
    } else if (t2 == "T_MANUALVALVE") {
        tt = T_MANUALVALVE;
    } else {
        return false;
    }
    return (t1 == tt);
}

bool isNotTaskType(TaskType t1, String t2) {
    return !(matchTaskType(t1, t2));
}

WorkState State::workState = AUTOMATIC;
ProblemState State::systemState = OK;
HandshakeState State::handshakeState = IDLE;
int State::valvePercentage = 0;
float State::waterLevel = 0.0f;

void State::setWorkState(WorkState newState) { workState = newState; }
bool State::matchWorkState(WorkState state) { return workState == state; }
bool State::isNotWorkState(WorkState state) { return workState != state; }

WorkState State::stringToWorkState(const char* stateString) {
    if (stateString == nullptr) return UNKNOWN_WORK_STATE;
    if (strcasecmp(stateString, "Automatic") == 0) return AUTOMATIC;
    if (strcasecmp(stateString, "Manual") == 0) return MANUAL;
    return UNKNOWN_WORK_STATE;
}

String State::workStateToString(WorkState state) {
    switch (state) {
        case AUTOMATIC: return "Automatic";
        case MANUAL: return "Manual";
    }
    return "Unknown";
}

String State::currentWorkStateString() { return workStateToString(workState); }

void State::setSystemState(ProblemState newState) { systemState = newState; }
bool State::matchSystemState(ProblemState state) { return systemState == state; }
bool State::isNotSystemState(ProblemState state) { return systemState != state; }

ProblemState State::stringToSystemState(const char* stateString) {
    if (stateString == nullptr) return UNKNOWN_PROBLEM_STATE;
    if (strcasecmp(stateString, "ok") == 0) return OK;
    if (strcasecmp(stateString, "unconnected") == 0) return UNCONNECTED;
    if (strcasecmp(stateString, "not_available") == 0) return NOT_AVAILABLE;
    if (strcasecmp(stateString, "uncon_notavail") == 0) return UNCON_NOTAVAIL;
    return UNKNOWN_PROBLEM_STATE;
}

String State::systemStateToString(ProblemState state) {
    switch (state) {
        case OK: return "OK";
        case UNCONNECTED: return "Unconnected";
        case NOT_AVAILABLE: return "Not Available";
        case UNCON_NOTAVAIL: return "Unconnected and not available";
    }
    return "Unknown";
}

String State::currentSystemStateString() { return systemStateToString(systemState); }

void State::setHandshakeState(HandshakeState newState){
    handshakeState = newState;
}

bool State::matchHandshakeState(HandshakeState state){
    return handshakeState == state;
}

bool State::isNotHandshakeState(HandshakeState state){
    return handshakeState != state;
}

String State::handshakeStateToString(HandshakeState state){
    switch (state) {
        case IDLE: return "Idle";
        case STATE: return "Waiting";
        case VALVE: return "Waiting";
        case ALL: return "Waiting";
    }
    return "Unknown";
}
HandshakeState State::stringToHandshakeState(const char *stateString){
    if (stateString == nullptr) return UNKNOWN_HANDSHAKE_STATE;
    if (strcasecmp(stateString, "idle") == 0) return IDLE;
    if (strcasecmp(stateString, "state") == 0) return STATE;
    if (strcasecmp(stateString, "valve") == 0) return VALVE;
    if (strcasecmp(stateString, "all") == 0) return ALL;
    return UNKNOWN_HANDSHAKE_STATE;
}
