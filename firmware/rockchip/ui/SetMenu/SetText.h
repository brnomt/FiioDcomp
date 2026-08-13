/*
********************************************************************************
*                   Copyright (C),2004-2015, Fuzhou Rockchip Electronics Co.,Ltd.
*                         All rights reserved.
*
* File Name£º  SetText.h
* 
* Description:  
*
* History:      <author>          <time>        <version>       
*             anzhiguo      2009-1-14          1.0
*    desc:    ORG.
********************************************************************************
*/

#ifndef _SETTEXT_H_
#define _SETTEXT_H_

#undef  EXT
#ifdef  _SETTEXT_IN_
#define EXT
#else
#define EXT extern
#endif
/******************************************************************************/
/*                                                                            */
/*                          Macro Define                                      */
/*                                                                            */
/******************************************************************************/

//setting menu permanent code.
#define _ATTR_SYS_SET_TEXT_CODE_         __attribute__((section("SetMenuServiceCode")))
#define _ATTR_SYS_SET_TEXT_DATA_         __attribute__((section("SetMenuServiceData")))
#define _ATTR_SYS_SET_TEXT_BSS_          __attribute__((section("SetMenuServiceBss"),zero_init))

/*
--------------------------------------------------------------------------------
  
                ENUMERATIONS AND STRUCTURES
  
--------------------------------------------------------------------------------
*/

/*
--------------------------------------------------------------------------------
  
                        Funtion Declaration
  
--------------------------------------------------------------------------------
*/

EXT UINT32 TextSetAutoBrowseTime (UINT32 iSelectedItem);
EXT UINT32 TextSetAutoBrowseStatus (UINT32 iSelectedItem);

/*
********************************************************************************
*
*                         End of SetText.h
*
********************************************************************************
*/
#endif

