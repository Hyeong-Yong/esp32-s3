#ifndef MAIN_COMMON_HW_INCLUDE_CDC
#define MAIN_COMMON_HW_INCLUDE_CDC

#include "hw_def.h"


#ifdef _USE_HW_CDC


bool     cdcInit(void);
bool     cdcIsInit(void);
uint32_t cdcAvailable(void);
uint8_t  cdcRead(void);
void     cdcDataIn(uint8_t rx_data);
uint32_t cdcWrite(uint8_t *p_data, uint32_t length);
uint32_t cdcGetBaud(void);


#endif

#endif /* MAIN_COMMON_HW_INCLUDE_CDC */
