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
    MANUAL
} WorkState;

typedef enum
{
    OK,
    UNCONNECTED
} ProblemState;

/* ---- CLASS STATE ---- */
class State
{
public:
private:
    static WorkState workState;
    static ProblemState systemState;
    static int valvePercentage;

public:
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

    static inline int getPercentage() {
        return valvePercentage;
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