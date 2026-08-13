/*
********************************************************************************
*                   Copyright (C),2004-2015, Fuzhou Rockchip Electronics Co.,Ltd.
*                         All rights reserved.
*
* File Name£º  SetRadio.h
* 
* Description:  
*
* History:      <author>          <time>        <version>       
*             anzhiguo      2009-1-14          1.0
*    desc:    ORG.
********************************************************************************
*/

#ifndef _SETRADIO_H_
#define _SETRADIO_H_

#undef  EXT
#ifdef  _SETRADIO_IN_
#define EXT
#else
#define EXT extern
#endif
/******************************************************************************/
/*                                                                            */
/*                          Macro Define                                      */
/*                                                                            */
/******************************************************************************/

//radio menu permanent code.
#define _ATTR_SYS_SET_RADIO_CODE_         __attribute__((section("SetMenuServiceCode")))
#define _ATTR_SYS_SET_RADIO_DATA_         __attribute__((section("SetMenuServiceData")))
#define _ATTR_SYS_SET_RADIO_BSS_          __attribute__((section("SetMenuServiceBss"),zero_init))

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
EXT UINT32 RadioSetMenuFmArea (UINT32 iSelectedItem);
EXT UINT32 RadioSetMenuFmStereo (UINT32 iSelectedItem);
EXT UINT32 RadioSetMenuFmScanSensitivity (UINT32 iSelectedItem);


/*
********************************************************************************
*
*                         End of SetRadio.h
*
********************************************************************************
*/
#endif

