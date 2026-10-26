#ifndef GLOBALS
#define GLOBALS

#include "ArduinoCompability.h"

/* ---- PINS FOR HARDWARE ---- */
#define B_SWITCH 2          // pin
#define P_SERVOMOTOR 10     // pin
#define P_VALVE A3          // pin

/* ---- ENUM FOR THE STATUSES ---- */

typedef enum
{
    AUTOMATIC,
    MANUAL,
    UNKNOWN_WORK_STATE
} WorkState;

typedef enum
{
    OK,
    UNCONNECTED,
    NOT_AVAILABLE,
    UNCON_NOTAVAIL,
    UNKNOWN_PROBLEM_STATE
} ProblemState;

typedef enum
{
    IDLE,
    STATE,
    VALVE,
    ALL,
    UNKNOWN_HANDSHAKE_STATE
} HandshakeState;

/* ---- CLASS STATE ---- */
class State
{
public:
private:
    static WorkState workState;
    static ProblemState systemState;
    static HandshakeState handshakeState;
    static int valvePercentage;
    static float waterLevel;

public:
    static void setHandshakeState(HandshakeState newState);
    static bool matchHandshakeState(HandshakeState state);
    static bool isNotHandshakeState(HandshakeState state);
    static String handshakeStateToString(HandshakeState state);
    static HandshakeState stringToHandshakeState(const char *stateString);
    static void setWorkState(WorkState newState);
    static bool matchWorkState(WorkState state);
    static bool isNotWorkState(WorkState state);
    static WorkState stringToWorkState(const char *stateString);
    static String workStateToString(WorkState state);
    static String currentWorkStateString();
    static void setSystemState(ProblemState newState);
    static bool matchSystemState(ProblemState state);
    static bool isNotSystemState(ProblemState state);
    static ProblemState stringToSystemState(const char *stateString);
    static String systemStateToString(ProblemState state);
    static String currentSystemStateString();
    static inline void setPercentage(int percentage) {
        valvePercentage = percentage;
    }
    static inline void setWaterLevel(float water) {
        waterLevel = water;
    }
    static inline HandshakeState getHandshake(){
        return handshakeState;
    }
    static inline ProblemState getSystemState(){
        return systemState;
    }
    static inline int getPercentage() {
        return valvePercentage;
    }
    static inline float getWaterLevel() {
        return waterLevel;
    }
};

/* ---- ENUM FOR THE HARDWARE ---- */

typedef enum
{
    BUTTON,
    SERVO_MOTOR,
    LCD,
    POTENTIOMETER,
} HardwareType;

inline bool matchHardwareType(HardwareType t1, HardwareType t2)
{
    return (t1 == t2);
}

inline bool isNotHardwareType(HardwareType t1, HardwareType t2)
{
    return (t1 != t2);
}

bool matchHardwareType(HardwareType t1, String t2);

bool isNotHardwareType(HardwareType t1, String t2);

/* ---- ENUM FOR THE TASKS ---- */

typedef enum
{
    T_INPUTOUTPUT,
    T_LCD,
    T_UPDATEVALVE,
    T_MANUALVALVE
} TaskType;

inline bool matchTaskType(TaskType t1, TaskType t2)
{
    return (t1 == t2);
}

inline bool isNotTaskType(TaskType t1, TaskType t2)
{
    return (t1 != t2);
}

bool matchTaskType(TaskType t1, String t2);

bool isNotTaskType(TaskType t1, String t2);

#endif