#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "motorManager.h"
#include <pigpio.h>

int main()
{
  if (gpioInitialise() < 0)
  {
    printf("initialisation failed\n");
  }
  else
  {
    signal(SIGINT, handleExit);
    setup();

    while(1)
    {
      update();
    }

    signal(SIGTERM, handleExit);

  }
}
