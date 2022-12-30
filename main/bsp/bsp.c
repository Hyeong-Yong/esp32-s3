
#include "bsp.h"
#include "soc/rtc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"





void bspInit(void)
{
}

uint32_t bspGetCpuFreqMhz(void)
{
  rtc_cpu_freq_config_t conf;
  rtc_clk_cpu_freq_get_config(&conf);

  return conf.freq_mhz;
}

void delay(uint32_t ms)
{
  vTaskDelay(ms / portTICK_PERIOD_MS);
}

uint32_t IRAM_ATTR millis(void)
{
  return (uint32_t)(esp_timer_get_time() / 1000ULL);
}

uint32_t IRAM_ATTR micros(void)
{
  return (uint32_t) (esp_timer_get_time());
}

