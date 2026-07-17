#include "motor.h"
#include <pigpio.h>
#include <stdlib.h>



struct motorParams
{
  int dirPin, stepPin;
  int dirPinValue;
  int noOfPulses;
  int delayNum;
};



motorParams_t motorParamsCreate(int stepPin, int dirPin)
{
  motorParams_t motorParamsInst = calloc(1, sizeof(struct motorParams));
  motorParamsInst->dirPin = dirPin;
  motorParamsInst->stepPin = stepPin;
  return motorParamsInst;
}







int getStepPin(motorParams_t motorParamsInst)
{
  return motorParamsInst->stepPin;
}

int getDirPin(motorParams_t motorParamsInst)
{
  return motorParamsInst->dirPin;
}







void setDirPinValue(motorParams_t motorParamsInst, int dirPinValue)
{
  motorParamsInst->dirPinValue = dirPinValue;
}
int getDirPinValue(motorParams_t motorParamsInst)
{
  return motorParamsInst->dirPinValue;
}





void setNoOfPulses(motorParams_t motorParamsInst, int noOfPulses)
{
  motorParamsInst->noOfPulses = noOfPulses;
}
int getNoOfPulses(motorParams_t motorParamsInst)
{
  return motorParamsInst->noOfPulses;
}




void setDelayNum(motorParams_t motorParamsInst, int delayNum)
{
  motorParamsInst->delayNum = delayNum;
}

int getDelayNum(motorParams_t motorParamsInst)
{
  return motorParamsInst->delayNum;
}






void motorInit(motorParams_t motorParamsInst)
{
  gpioSetMode(motorParamsInst->stepPin, PI_OUTPUT);
  gpioSetMode(motorParamsInst->dirPin, PI_OUTPUT);
}

void motorControl(motorParams_t params)
{
  gpioWrite(params->dirPin, params->dirPinValue);
  for(int x = 0; x < params->noOfPulses; x++)
  {
    gpioWrite(params->stepPin, 1);
    gpioDelay(params->delayNum);
    gpioWrite(params->stepPin, 0);
    gpioDelay(params->delayNum);

  }
}




void destroyMotorParams(motorParams_t motorParamsInst)
{
  free(motorParamsInst);
}

