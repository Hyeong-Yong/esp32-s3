#ifndef MAIN_HW_HW_DEF
#define MAIN_HW_HW_DEF



#include "def.h"
#include "bsp.h"

#define _USE_HW_GPIO
#define      HW_GPIO_MAX_CH     1

#define _USE_HW_LED
#define      HW_LED_MAX_CH      1

#define _USE_HW_UART
#define      HW_UART_MAX_CH     2


#define _USE_HW_CDC

#define _USE_HW_CLI
#define      HW_CLI_CMD_LIST_MAX    32
#define      HW_CLI_CMD_NAME_MAX    16
#define      HW_CLI_LINE_HIS_MAX    8
#define      HW_CLI_LINE_BUF_MAX    64

#endif /* MAIN_HW_HW_DEF */
