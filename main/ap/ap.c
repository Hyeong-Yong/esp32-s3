

#include "ap.h"

void apInit(void)
{
    cliOpen(_DEF_UART2, 115200);
}


void apMain(void)
{
    uint32_t pre_time;
    pre_time=millis();

    while(1)
    {
        if (millis()-pre_time > 500)
        {
            ledToggle(_DEF_LED1);
            pre_time=millis();            
        }
        cliMain();

        delay(10);   
    }
}
 