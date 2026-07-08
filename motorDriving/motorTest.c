#include <pigpio.h>
#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>

int dirPin = 14; // PWM pin
int stepPin = 15; // non-PWM pin

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
  while(1)
  {
    gpioWrite(dirPin, 1);
    for(int x = 0; x < 200; x++)
    {
      gpioWrite(stepPin, 1);
      gpioDelay(500);
      gpioWrite(stepPin, 0);
      gpioDelay(500);
    }
  }
}

void handleExit(int signum)
{
  printf("\nClearing everything...\n");
  gpioTerminate();
  exit(0);
}
