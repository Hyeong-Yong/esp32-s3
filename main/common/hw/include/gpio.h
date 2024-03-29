#ifndef MAIN_COMMON_HW_INCLUDE_GPIO
#define MAIN_COMMON_HW_INCLUDE_GPIO

#include "hw_def.h"

#ifdef _USE_HW_GPIO


#define GPIO_MAX_CH	    HW_GPIO_MAX_CH

bool gpioInit(void);
bool gpioPinMode(uint8_t ch, uint8_t mode);
void gpioPinWrite(uint8_t ch, uint8_t value);
uint8_t gpioPinRead(uint8_t ch);
void gpioPinToggle(uint8_t ch);

#endif

#endif /* MAIN_COMMON_HW_INCLUDE_GPIO */
