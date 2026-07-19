#ifndef MOTOR_MANAGER
#define MOTOR_MANAGER

#include <pigpio.h>
#include "motor.h"

// motor 1 parameters
int stepPin = 15;
int dirPin = 14;
int dirPinValue = 0;
int noOfPulses = 400;
int delayNum = 500; // microseconds

// motor2 params
int stepPin2 = 23;
int dirPin2 = 24;
int dirPinValue2 = 1;

motorParams_t a;
motorParams_t b;

void setup()
{
  // motor 1
  a = motorParamsCreate(stepPin, dirPin);
  setDirPinValue(a, dirPinValue);
  setNoOfPulses(a, noOfPulses);
  setDelayNum(a, delayNum);
  motorInit(a);

  // motor 2
  b = motorParamsCreate(stepPin2, dirPin2);
  setDirPinValue(b, dirPinValue2);
  setNoOfPulses(b , noOfPulses);
  setDelayNum(b, delayNum);
  motorInit(b);
}

void update()
{
  motorControl(a);
  motorControl(b);
}

void handleExit(int signum)
{
  printf("\nClearing everything...\n");
  gpioTerminate();
  destroyMotorParams(a);
  destroyMotorParams(b);
  printf("Cleared motor params\n");
  exit(0);
}

#endif
