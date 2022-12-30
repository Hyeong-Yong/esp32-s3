#ifndef MAIN_BSP_BSP
#define MAIN_BSP_BSP

#include "def.h"
#include "sdkconfig.h"


#if 0
#define _USE_LOG_PRINT    1

#if _USE_LOG_PRINT
#define logPrintf(fmt, ...)     printf(fmt, ##__VA_ARGS__)
#else
#define logPrintf(fmt, ...)
#endif
#endif

void logPrintf(const char *fmt, ...);


void bspInit(void);
uint32_t bspGetCpuFreqMhz(void);

void delay(uint32_t ms);
uint32_t millis(void);
uint32_t micros(void);


#endif /* MAIN_BSP_BSP */
