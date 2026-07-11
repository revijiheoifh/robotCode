#include <pigpio.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int dirPin = 14;
int stepPin = 15;

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
  gpioSetMode(dirPin, PI_OUTPUT);
  gpioSetMode(stepPin, PI_OUTPUT);
}

void update()
{
  int pinDelayMicroSecs = 500;
  int noOfSteps = 400;

  while(1)
  {
    gpioWrite(dirPin, 1);
    for(int x=0; x<noOfSteps; x++)
    {
      gpioWrite(stepPin, 1);
      gpioDelay(pinDelayMicroSecs);
      gpioWrite(stepPin, 0);
      gpioDelay(pinDelayMicroSecs);
    }
  }
}

void handleExit(int signum)
{
  printf("\nClearing everything...\n");
  gpioTerminate();
  exit(0);
}
