#include <stdio.h>
#include <pigpio.h>

// to see which address the ht16k33 driver is at, use: sudo i2cdetect -y 1

void ht16k33_clear(int handle);

int main()
{
  if(gpioInitialise() < 0)
  {
    printf("gpio init failed\n");
  }
  else
  {
    int handle = i2cOpen(1, 0x71, 0);

    if (handle < 0) {
        fprintf(stderr, "i2cOpen failed\n");
        gpioTerminate();
        return 1;
    }

    // char data[2] = {0x04, 0x08};

    i2cWriteByte(handle, 0x21); // system setup
    i2cWriteByte(handle, 0x81); // display setup and define blinking freq

    i2cWriteByte(handle, 0xE0); // brightness
    // i2cWriteDevice(handle, data, 2);

    ht16k33_clear(handle);

    i2cClose(handle);
    gpioTerminate();
  }
}


/*
This function was initially meant to clear the dot matrix
but I have found that it can turn on the LEDs
The LEDs turn on through i2cWriteByteData
However, not all of them turn on.
*/
void ht16k33_clear(int handle)
{
    for (int addr = 0; addr < 16; addr++)
    {
        i2cWriteByteData(handle, addr, 0x04);
    }
}
