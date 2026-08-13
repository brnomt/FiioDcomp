/*
********************************************************************************
*                   Copyright (C),2004-2015, Fuzhou Rockchip Electronics Co.,Ltd.
*                         All rights reserved.
*
* File Name£º   hw_config.h
*
* Description:
*
* History:      <author>          <time>        <version>
*             ZhengYongzhi      2008-8-13          1.0
*    desc:    ORG.
********************************************************************************
*/

#ifndef _LCDCONFIG_H_
#define _LCDCONFIG_H_

/*
*-------------------------------------------------------------------------------
*
*                            Macro define
*
*-------------------------------------------------------------------------------
*/

#define _ATTR_LCD_CODE_          __attribute__((section("SysCode")))
#define _ATTR_LCD_DATA_          __attribute__((section("SysData")))
#define _ATTR_LCD_BSS_           __attribute__((section("SysBss"), zero_init))
#define _ATTR_LCD_BUF_           __attribute__((section("FrameBuffer"), zero_init))

/*
********************************************************************************
*
*                         End of hw_config.h
*
********************************************************************************
*/
#endif
