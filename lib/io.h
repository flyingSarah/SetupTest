#ifndef _IO_H_
#define _IO_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// TODO: this isn't really an I/O function - it should be in a different lib eventually
void ioSleepMs(const uint16_t ms);

void ioLedsInit(const uint16_t *const leds, const size_t count);

int ioLedWrite(const uint16_t led, const bool doAnalogWrite, const int value);

void ioPushButtonsInit(const uint16_t *const pushButtons, const size_t count);

int ioPushButtonRead(const uint16_t pushButton);

#endif // _IO_H_
