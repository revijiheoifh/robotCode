#include "motor.h"
#include <pigpio.h>
#include <stdlib.h>

struct motorParams
{
  int dirPin, stepPin;
  int dirPinValue;
  int noOfPulses;
  float delayNum;
};

motorParams_t motorParamsCreate(int stepPin, int dirPin, int dirPinValue, int noOfPulses, float delayNum)
{
  motorParams_t motorParamsInst = calloc(1, sizeof(struct motorParams));
  motorParamsInst->dirPin = dirPin;
  motorParamsInst->stepPin = stepPin;
  motorParamsInst->dirPinValue = dirPinValue;
  motorParamsInst->noOfPulses = noOfPulses;
  motorParamsInst->delayNum = delayNum;
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

int getDirPinValue(motorParams_t motorParamsInst)
{
  return motorParamsInst->dirPinValue;
}

int getNoOfPulses(motorParams_t motorParamsInst)
{
  return motorParamsInst->noOfPulses;
}

float getDelayNum(motorParams_t motorParamsInst)
{
  return motorParamsInst->delayNum;
}

void motorInit(motorParams_t motorInitP)
{
  gpioSetMode(motorInitP->stepPin, PI_OUTPUT);
  gpioSetMode(motorInitP->dirPin, PI_OUTPUT);
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
