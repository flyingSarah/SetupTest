#include <unistd.h>
#include <stm32f4xx_hal.h>

#include "io.h"

void ioSleepMs(const uint16_t ms)
{
    usleep(ms * 1000);
    //for(uint16_t i = 0; i < ms * 4000; i++) {}
}

void ioLedsInit(const uint16_t *const leds, const size_t count)
{
    __HAL_RCC_GPIOD_CLK_ENABLE();
    GPIO_InitTypeDef boardLeds;
    boardLeds.Mode = GPIO_MODE_OUTPUT_PP;
    for(size_t i = 0; i < count; i++)
    {
        boardLeds.Pin |= leds[i];
    }
    HAL_GPIO_Init(ENV_LED_GROUP, &boardLeds);
}

int ioLedWrite(const uint16_t led, const bool doAnalogWrite, const int value)
{
    if(doAnalogWrite)
    {
        return -1; // not implemented yet
    }
    else if(value == GPIO_PIN_SET || value == GPIO_PIN_RESET)
    {
        HAL_GPIO_WritePin(ENV_LED_GROUP, led, value);
    }
    else
    {
        return -1; // value out of range for digital write
    }

    return 0;
}

void ioPushButtonsInit(const uint16_t *const pushButtons, const size_t count)
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
    GPIO_InitTypeDef pushButtons;
    pushButtons.Mode = GPIO_MODE_INPUT;
    for(size_t i = 0; i < count; i++)
    {
        pushButtons.Pin |= pushButtons[i];
    }
    HAL_GPIO_Init(ENV_PUSH_BUTTON_GROUP, &pushButtons);
}

int ioPushButtonRead(const uint16_t pushButton)
{
    return HAL_GPIO_ReadPin(ENV_PUSH_BUTTON_GROUP, pushButton);
}

#endif
