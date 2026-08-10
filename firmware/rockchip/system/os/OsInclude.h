/*
********************************************************************************
*                   Copyright (C),2004-2015, Fuzhou Rockchip Electronics Co.,Ltd.
*                         All rights reserved.
*
* File Name£º   Task.h
* 
* Description:  
*
* History:      <author>          <time>        <version>       
*             ZhengYongzhi      2008-9-13          1.0
*    desc:    ORG.
********************************************************************************
*/

#ifndef _OS_SECTION_H_
#define _OS_SECTION_H_

/*
*-------------------------------------------------------------------------------
*  
*                           Macro define
*  
*-------------------------------------------------------------------------------
*/
//section define
#define _ATTR_OS_CODE_        __attribute__((section("SysCode")))
#define _ATTR_OS_DATA_        __attribute__((section("SysData")))
#define _ATTR_OS_BSS_         __attribute__((section("SysBss"),zero_init))

/*
*-------------------------------------------------------------------------------
*  
*                           Include HeadFile
*  
*-------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <string.h>
#include "SysConfig.h"
#include "driverlib_def.h"
#include "typedef.h"
#include "Macro.h"
#include "global.h"
#include "debug.h"
#include "delay.h"

#include "Os.h"
#include "Msg.h"
#include "Thread.h"
#include "Win.h"
#include "Task.h"
#include "interrupt.h"
#include "SysTickHandler.h"
#include "OsHook.h"

#include "ModuleInfoTab.h"
#include "ModuleOverlay.h"

/*
********************************************************************************
*
*                         End of Task.h
*
********************************************************************************
*/
#endif
