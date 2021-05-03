#include <Arduino.h>

#include "io.h"

void ioSleepMs(const uint16_t ms)
{
    delay(ms);
}

void ioLedsInit(const uint16_t *const leds, const size_t count)
{
    for(size_t i = 0; i < count; i++)
    {
        pinMode(leds[i], OUTPUT);
    }
}

int ioLedWrite(const uint16_t led, const bool doAnalogWrite, const int value)
{
    if(doAnalogWrite)
    {
        analogWrite(led, value);
    }
    else if(value == HIGH || value == LOW)
    {
        digitalWrite(led, value);
    }
    else
    {
        Serial.printf("error performing digital write to LED: value (%d) is not binary\n",
                       value);
        return -1;
    }

    return 0;
}

void ioPushButtonsInit(const uint16_t *const pushButtons, const size_t count)
{
    for(size_t i = 0; i < count; i++)
    {
        pinMode(pushButtons[i], INPUT);
    }
}

int ioPushButtonRead(const uint16_t pushButton)
{
    return analogRead(pushButton);
}
