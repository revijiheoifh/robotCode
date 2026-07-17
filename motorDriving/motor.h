#ifndef MOTOR
#define MOTOR

typedef struct motorParams* motorParams_t;

motorParams_t motorParamsCreate(int stepPin, int dirPin);
void destroyMotorParams(motorParams_t motorParamsInst);

// do I need these? yes
int getStepPin(motorParams_t motorParamsInst);
int getDirPin(motorParams_t motorParamsInst);

void setDirPinValue(motorParams_t motorParamsInst, int dirPinValue);
int getDirPinValue(motorParams_t motorParamsInst);

void setNoOfPulses(motorParams_t motorParamsInst, int noOfPulses);
int getNoOfPulses(motorParams_t motorParamsInst);

void setDelayNum(motorParams_t motorParamsInst, int delayNum);
int getDelayNum(motorParams_t motorParamsInst);

void destroyMotorParams(motorParams_t motorParamsInst);

// you do need those

void motorInit(motorParams_t motorInitP);
void motorControl(motorParams_t motorParams);

#endif
