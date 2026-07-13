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
//  struct motorParams m;
}

void update()
{
  while(1)
  {
    printf("smd\n");
  }
}

void handleExit(int signum)
{
  printf("\nClearing everything...\n");
  gpioTerminate();
  exit(0);
}
