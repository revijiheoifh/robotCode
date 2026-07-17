#include <pigpio.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "motor.h"

void setup();
void update();
void handleExit();

int main()
{
  if (gpioInitialise() < 0)
  {
    printf("initialisation failed\n");
  }
  else
  {
    signal(SIGINT, handleExit);
    signal(SIGTERM, handleExit);

    setup();
    update();
  }
}

void setup()
{
  // struct
  int stepPin = 14; // should be const
  int dirPin = 15; // should be const
  int dirPinValue = 1;
  int noOfPulses = 200;
  int delayNum = 500;

  motorParams_t a = motorParamsCreate(stepPin, dirPin, dirPinValue, noOfPulses, delayNum);
  // destroyMotorParams(a);
  printf("%d",getStepPin(a));
}

void update()
{
  /*while(1)
  {
    printf("smd\n");
  }*/
}

void handleExit(int signum)
{
  printf("\nClearing everything...\n");
  gpioTerminate();
  exit(0);
}
