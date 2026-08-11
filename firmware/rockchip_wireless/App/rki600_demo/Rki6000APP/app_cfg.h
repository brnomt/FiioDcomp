#ifndef _APP_CFG_H
#define _APP_CFG_H

#define CONFIG_WIFI_STA_MODE
//#define CONFIG_WIFI_SOFTAP_MODE

#define CONFIG_SOFTAP_SSID          "u_soft_ap"
#define CONFIG_SECURITY_MODE        3       //0: open; 1: wep; 2: wpa-tkip; 3: wpa2-aes
#define CONFIG_SOFTAP_PASSWORD  "12345678"

#define CONFIG_STA_PASSWORD "12345678"

#define CONFIG_LCD_SHOW

#define CONFIG_INTERNAL_DEBUG    1

#define OS_UCOS         0
#define OS_FREERTOS     1
#define CONFIG_OS       OS_UCOS


/*for task stack*/

#define  START_TASK_PRIO                            17
#define  WIFI_DEFUALT_TASK_PRIO            17

#define  START_TASK_STK_SIZE                    256 //2048 //128
#define  WIFI_DEFUALT_TASK_STK_SIZE            1024 //128

#define OS_CRITICAL_METHOD

/* for debug usage */
#define DEBUG    1


#if DEBUG == 1
#define DBG_DEBUG_PRINT_ENABLE                           1
#define DBG_COBUF_NEED_STATISTIC                1
#else  /*must NOT change the following macro*/
#define DBG_DEBUG_PRINT_ENABLE                           0
#define DBG_COBUF_NEED_STATISTIC                0
#endif

/*
#define LCD_Init()
#define LCD_ShowString(a,b,c,d,e,f)
#define POINT_COLOR count
#define RED     0
#define GREEN   1
#define BLACK   2
#define BLUE    3
*/

#endif
