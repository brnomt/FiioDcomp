/*
********************************************************************************
*                   Copyright (C),2004-2015, Fuzhou Rockchip Electronics Co.,Ltd.
*                         All rights reserved.
*
* File Name£º   DriverConfig.h
* 
* Description:  
*
* History:      <author>          <time>        <version>       
*             anzhiguo      2009-1-14          1.0
*    desc:    ORG.
********************************************************************************
*/

#ifndef _DRIVER_CONFIG_H_
#define _DRIVER_CONFIG_H_

/*
*-------------------------------------------------------------------------------
*
*                            Macro define
*
*-------------------------------------------------------------------------------
*/
//section define
#define _ATTR_DRIVER_CODE_          __attribute__((section("SysCode")))
#define _ATTR_DRIVER_DATA_          __attribute__((section("SysData")))
#define _ATTR_DRIVER_BSS_           __attribute__((section("SysBss"), zero_init))

#define _ATTR_DRIVERLIB_CODE_       __attribute__((section("DriverLib")))

//LCD Driver Section Define
#define _ATTR_LCDDRIVER_ST7735S_CODE_          __attribute__((section("ST7735SDriverCode")))
#define _ATTR_LCDDRIVER_ST7735S_DATA_          __attribute__((section("ST7735SDriverData")))
#define _ATTR_LCDDRIVER_ST7735S_BSS_           __attribute__((section("ST7735SDriverBss"), zero_init))

#define _ATTR_LCDDRIVER_ST7735_CODE_          __attribute__((section("ST7735DriverCode")))
#define _ATTR_LCDDRIVER_ST7735_DATA_          __attribute__((section("ST7735DriverData")))
#define _ATTR_LCDDRIVER_ST7735_BSS_           __attribute__((section("ST7735DriverBss"), zero_init))

//#define _ATTR_LCDDRIVER_JWM12864_CODE_          __attribute__((section("JWM12864DriverCode")))
//#define _ATTR_LCDDRIVER_JWM12864_DATA_          __attribute__((section("JWM12864DriverData")))
//#define _ATTR_LCDDRIVER_JWM12864_BSS_           __attribute__((section("JWM12864DriverBss"), zero_init))

#define _ATTR_LCDDRIVER_UC1604C_CODE_          __attribute__((section("UC1604CDriverCode")))
#define _ATTR_LCDDRIVER_UC1604C_DATA_          __attribute__((section("UC1604CDriverData")))
#define _ATTR_LCDDRIVER_UC1604C_BSS_           __attribute__((section("UC1604CDriverBss"), zero_init))

//#define _ATTR_LCDDRIVER_LD7032_CODE_          __attribute__((section("LD7032CDriverCode")))
//#define _ATTR_LCDDRIVER_LD7032_DATA_          __attribute__((section("LD7032CDriverData")))
//#define _ATTR_LCDDRIVER_LD7032_BSS_           __attribute__((section("LD7032CDriverBss"), zero_init))


//FM Driver section define
#define _ATTR_FMDRIVER_QN8035_TEXT_     __attribute__((section("Qn8035DriverCode")))
#define _ATTR_FMDRIVERL_QN8035_DATA_    __attribute__((section("Qn8035DriverData")))
#define _ATTR_FMDRIVER_QN8035_BSS_      __attribute__((section("Qn8035DriverBss"),zero_init))

#define _ATTR_FMDRIVER_FM5807_TEXT_     __attribute__((section("Fm5807DriverCode")))
#define _ATTR_FMDRIVERL_FM5807_DATA_    __attribute__((section("Fm5807DriverData")))
#define _ATTR_FMDRIVER_FM5807_BSS_      __attribute__((section("Fm5807DriverBss"),zero_init))

/*
********************************************************************************
*
*                         End of DriverConfig.h
*
********************************************************************************
*/
#endif


