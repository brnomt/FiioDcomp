/*
********************************************************************************
*                   Copyright (C),2004-2015, Fuzhou Rockchip Electronics Co.,Ltd.
*                         All rights reserved.
*
* File Name£º  SetCommon.h
* 
* Description:  
*
* History:      <author>          <time>        <version>       
*             anzhiguo      2009-1-14          1.0
*    desc:    ORG.
********************************************************************************
*/

#ifndef _SETCOMMON_H_
#define _SETCOMMON_H_

#undef  EXT
#ifdef  _SETCOMMON_IN_
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
#define _ATTR_SYS_SET_COMMON_CODE_         __attribute__((section("SetMenuServiceCode")))
#define _ATTR_SYS_SET_COMMON_DATA_         __attribute__((section("SetMenuServiceData")))
#define _ATTR_SYS_SET_COMMON_BSS_          __attribute__((section("SetMenuServiceBss"),zero_init))

/*
--------------------------------------------------------------------------------
  
                ENUMERATIONS AND STRUCTURES
  
--------------------------------------------------------------------------------
*/


//  EXT SYS_SET_MenuVal  SysSet_sMenuVal[110]; 

/*
--------------------------------------------------------------------------------
  
                        Funtion Declaration
  
--------------------------------------------------------------------------------
*/
EXT UINT32 f_SYSSET_FuncNull( UINT32 itemNum );
EXT UINT32 ExcuteSetMenuFunc(UINT32 menuId, UINT32 itemNum);





/*
********************************************************************************
*
*                         End of SetCommon.h
*
********************************************************************************
*/
#endif

