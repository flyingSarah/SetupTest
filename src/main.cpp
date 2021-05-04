#include "../extra-libs/io/io.h"

#ifdef IOARDUINO
#include "../extra-libs/io/io-arduino/io-arduino.h"
#elif IOCUBE
#include "../extra-libs/io/io-cube/io-cube.h"
#endif

#define LOOP_DURATION_MS 100

void setup() {
  uint16_t leds[1] = { ENV_LED_01 };
  ioLedsInit(leds, 1);

  uint16_t pushButtons[1] = { ENV_PUSH_BUTTON_01 };
  ioPushButtonsInit(pushButtons, 1);
}

void loop() {
  int pushState = ioPushButtonRead(ENV_LED_01);

  if(pushState)
  {
    ioLedWrite(ENV_LED_01, false, 1);
  }

  ioSleepMs(LOOP_DURATION_MS);
}

#ifndef ARDUINO
int main()
{
  setup();

  while(1)
  {
    loop();
  }
}
#endif