/* Copyright (C) 2011 ROCK-CHIP FUZHOU. All Rights Reserved. */
/*
File: SDConfig.h
Desc:

Author:
Date: 12-01-10
Notes:

$Log: $
 *
 *
*/

#ifndef _SDCONFIG_H
#define _SDCONFIG_H

/*-------------------------------- Includes ----------------------------------*/

#include "MDconfig.h"


/*------------------------------ Global Defines ------------------------------*/

#if defined(EMMC_DRIVER)
#define CONFIG_EMMC_SPEC        (1)     //定义支持EMMC协议
//#define CONFIG_SD_SPEC          (0)     //定义支持SD协议
#endif

#if defined(SDC0_DRIVER)
//#define CONFIG_EMMC_SPEC        (0)
#define CONFIG_SD_SPEC          (1)
#endif

#define CONFIG_EMMC_BUS_WIDTH        8
#define CONFIG_SD_BUS_WIDTH          4

#define MAX_SDC_NUM             2

#define MAX_SCU_CLK_DIV         32       //时钟外部分频器最大分频值

//#define PRE_DEFINE_BLKCNT                 //预定义长度读写
#define ASYNC_WAIT_IO                       //异步等待IO完成

#define EN_SD_DMA             (0)//(1)      //是否用DMA来进行数据传输，1:DMA方式，0:中断方式

#define EN_SD_INT             (1)      //是否采用中断发生来查询一些SDMMC控制器的重要位，1:用中断方式，0:用轮询方式，目前就算用轮询方式，卡检测还是设成中断的
#define EN_SD_BUSY_INT        (0)      //使能busy完成中断，部分控制器支持
#define EN_SD_PRINTF          (0)      //是否允许SD驱动内部调试信息打印，1:开启打印，0:关闭打印
#define DEBOUNCE_TIME         (25)     //卡拔插的消抖动时间,单位ms


#define FOD_FREQ              (400)    //卡识别阶段使用的频率,单位KHz,协议规定最大400KHz
//卡正常工作的最低频率为FREQ_HCLK_MAX/8
#define SD_FPP_FREQ           (24000)  //标准SD卡正常工作频率，单位KHz，协议规定最大25MHz
#define SDHC_FPP_FREQ         (48000)  //SDHC卡在高速模式下的工作频率，单位KHz，协议规定最大50MHz
#define MMC_FPP_FREQ          (24000)  //标准MMC卡正常工作频率，单位KHz，协议规定最大20MHz
#define MMCHS_26_FPP_FREQ     (25000)  //高速模式只支持最大26M的HS-MMC卡，在高速模式下的工作频率，单位KHz，协议规定最大26MHz
#define MMCHS_52_FPP_FREQ     (50000)  //高速模式能支持最大52M的HS-MMC卡，在高速模式下的工作频率，单位KHz，协议规定最大52MHz
#define MAX_CLKIN_FREQ        (50000)


#include "SDCommon.h"
#include "SDAdapt.h"

#include "SDM.h"
#include "SDCtrl.h"

#include "SD.h"
#include "MMC.h"
#include "eMMC.h"


/*------------------------------ Global Typedefs -----------------------------*/

/*----------------------------- External Variables ---------------------------*/

/*------------------------- Global Function Prototypes -----------------------*/

#endif
