#include "motor.h"
#include <pigpio.h>

struct motorParams
{
  int dirPin, stepPin;
  int noOfPulses;
  float delayNum;
};

void motorInit(motorParams_t* motorInitP)
{
  gpioSetMode(motorInitP->stepPin, PI_OUTPUT);
  gpioSetMode(motorInitP->dirPin, PI_OUTPUT);
}

void motorControl(motorParams_t *params)
{
  gpioWrite(params->dirPin, 1);
  for(int x = 0; x < params->noOfPulses; x++)
  {
    gpioWrite(params->stepPin, 1);
    gpioDelay(params->delayNum = 500);
    gpioWrite(params->stepPin, 0);
    gpioDelay(params->delayNum = 500);

  }
}
