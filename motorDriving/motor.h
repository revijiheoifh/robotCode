#ifndef MOTOR
#define MOTOR

typedef struct motorParams* motorParams_t;

motorParams_t motorParamsCreate(int stepPin, int dirPin, int dirPinValue, int noOfPulses, float delayNum);


// do I need these?
int getStepPin(motorParams_t motorParamsInst);
int getDirPin(motorParams_t motorParamsInst);
int getDirPinValue(motorParams_t motorParamsInst);
int getNoOfPulses(motorParams_t motorParamsInst);
float getDelayNum(motorParams_t motorParamsInst);
void destroyMotorParams(motorParams_t motorParamsInst);


void motorInit(motorParams_t motorInitP);
void motorControl(motorParams_t motorParams);

#endif
