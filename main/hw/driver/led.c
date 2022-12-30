/*
 * led.c
 *
 *  Created on: 2021. 6. 14.
 *      Author: baram
 */


#include "led.h"
#include "cli.h"

#ifdef _USE_HW_LED
#include "driver/gpio.h"


typedef struct
{
  uint32_t    pin;
  uint8_t     on_state;
  uint8_t     off_state;
  uint8_t     data;
} led_tbl_t;



static led_tbl_t led_tbl[LED_MAX_CH] =
{
    {GPIO_NUM_19, _DEF_HIGH, _DEF_LOW, 0},
};


#ifdef _USE_HW_CLI
static void cliLED(cli_args_t *args);
#endif

bool ledInit(void)
{
  for (int i=0; i<LED_MAX_CH; i++)
  {
    gpio_reset_pin(led_tbl[i].pin);
    gpio_set_direction(led_tbl[i].pin, GPIO_MODE_OUTPUT);
    ledOff(i);
  }

#ifdef _USE_HW_CLI
  cliAdd("led", cliLED);
#endif

  return true;
}

void ledOn(uint8_t ch)
{
  if (ch >= LED_MAX_CH) return;

  led_tbl[ch].data = led_tbl[ch].on_state;
  gpio_set_level(led_tbl[ch].pin, led_tbl[ch].data);
}

void ledOff(uint8_t ch)
{
  if (ch >= LED_MAX_CH) return;

  led_tbl[ch].data = led_tbl[ch].off_state;
  gpio_set_level(led_tbl[ch].pin, led_tbl[ch].data);
}

void ledToggle(uint8_t ch)
{
  if (ch >= LED_MAX_CH) return;

  led_tbl[ch].data = !led_tbl[ch].data;
  gpio_set_level(led_tbl[ch].pin, led_tbl[ch].data);
}


void cliLED(cli_args_t *args)
{
  bool ret = false;

  if (args->argc == 3 && args->isStr(0, "toggle") == true)
    {
      uint8_t led_ch;
      uint32_t toggle_time;
      uint32_t pre_time;

      led_ch = (uint8_t)args->getData(1);
      toggle_time = (uint32_t)args->getData(2);

      if (led_ch >0)
        {
          led_ch--;
        }
      pre_time=millis();
      while (cliKeepLoop())
        {
          if (millis()-pre_time >= toggle_time)
            {
              pre_time = millis();
              ledToggle(led_ch);
            }
            delay(10);
        }
      ret=true;
    }

  if (ret != true)
    {
      cliPrintf("led toggle ch[1~%d] time_ms\n", LED_MAX_CH);
    }
}



#endif