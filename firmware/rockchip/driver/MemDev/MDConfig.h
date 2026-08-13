/********************************************************************************
*********************************************************************************
            COPYRIGHT (c)   2004 BY ROCK-CHIP FUZHOU
                --  ALL RIGHTS RESERVED  --

File Name:      config.h
Author:         XUESHAN LIN
Created:        1st Dec 2008
Modified:
Revision:       1.00
********************************************************************************
********************************************************************************/
#ifndef _MDCONFIG_H
#define  _MDCONFIG_H

#include    <stdio.h>
#include    <string.h>
#include    "SysConfig.h"

#include    "typedef.h"
#include    "Macro.h"

#include    "hw_memap.h"
#include    "hook.h"
#include    "MemDev.h"
#include    "USBConfig.h"


#include    "SPIFlash\SPIFlash.h"

#include    "sd_mmc\SDConfig.h"


#define UNUSED(x)           ( void )(x)

#if defined(_SDCARD_)
#define     SDC0_DRIVER
#endif

#if defined(_EMMC_)
#define     EMMC_DRIVER
#endif

#if defined(EMMC_DRIVER) || defined(SDC0_DRIVER)
#define     SDMMC_DRIVER
#endif

#if defined(_USB_HOST_)
#define     USBHOST_DRIVER
#endif

#ifdef _SPINOR_
#define   SPINOR_DRIVER
#endif

//#define       SPINAND_DRIVER

#if defined(SPINAND_DRIVER) || defined(SPINOR_DRIVER)
#define SPIFLASH_DRIVER
#endif



//SD卡初始化代码、数据段
#define     _ATTR_SD_INIT_CODE_         __attribute__((section("SDInitCode")))
#define     _ATTR_SD_INIT_DATA_         __attribute__((section("SDInitData")))
#define     _ATTR_SD_INIT_BSS_          __attribute__((section("SDInitBss"),zero_init))

//SD卡基本操作及读取操作代码、数据段
#define     _ATTR_SD_CODE_              __attribute__((section("SDCode")))
#define     _ATTR_SD_DATA_              __attribute__((section("SDData")))
#define     _ATTR_SD_BSS_               __attribute__((section("SDBss"),zero_init))
#define     IRAM_SD                     _ATTR_SD_CODE_

//SD卡写操作代码、数据段
#define     _ATTR_SD_WRITE_CODE_        __attribute__((section("SDWriteCode")))
#define     _ATTR_SD_WRITE_DATA_        __attribute__((section("SDWriteData")))
#define     _ATTR_SD_WRITE_BSS_         __attribute__((section("SDWriteBss"),zero_init))


#define     _ATTR_FLASH_INIT_CODE_      __attribute__((section("FlashCode")))//__attribute__((section("FlashInitCode")))
#define     _ATTR_FLASH_INIT_DATA_      __attribute__((section("FlashData")))//__attribute__((section("FlashInitData")))
#define     _ATTR_FLASH_INIT_BSS_       __attribute__((section("FlashBss"),zero_init))//__attribute__((section("FlashInitBss"),zero_init))

#define     _ATTR_FLASH_CODE_           __attribute__((section("FlashCode")))
#define     _ATTR_FLASH_DATA_           __attribute__((section("FlashData")))
#define     _ATTR_FLASH_BSS_            __attribute__((section("FlashBss"),zero_init))

#define     _ATTR_FLASH_WRITE_CODE_      __attribute__((section("FlashCode")))//__attribute__((section("FlashWriteCode")))
#define     _ATTR_FLASH_WRITE_DATA_      __attribute__((section("FlashData")))//__attribute__((section("FlashWriteData")))
#define     _ATTR_FLASH_WRITE_BSS_       __attribute__((section("FlashBss"),zero_init))//__attribute__((section("FlashWriteBss"),zero_init))

#define     IRAM_FLASH_INIT             _ATTR_FLASH_INIT_CODE_

#endif


