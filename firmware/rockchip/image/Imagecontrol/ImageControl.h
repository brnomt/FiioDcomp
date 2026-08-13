/*
********************************************************************************
*                   Copyright (C),2004-2015, Fuzhou Rockchip Electronics Co.,Ltd.
*                         All rights reserved.
*
* File Name：   ImageControl.h
*
* Description:
*
* History:      <author>          <time>        <version>
*               anzhiguo      2008-9-13          1.0
*    desc:    ORG.
********************************************************************************
*/

#ifndef _IMAGE_CONTROL_H_
#define _IMAGE_CONTROL_H_

#include "FsInclude.h"
#include "..\ImageInclude\image_globals.h"
#undef  EXT
#ifdef _IN_IMAGE_CONTROL_
#define EXT
#else
#define EXT extern
#endif
//section define
#define _ATTR_IMAGE_TEXT_     __attribute__((section("ImageCode")))
#define _ATTR_IMAGE_DATA_     __attribute__((section("ImageData")))
#define _ATTR_IMAGE_BSS_      __attribute__((section("ImageBss"),zero_init))

typedef enum
{
	//dec state
	IMAGE_STATE_START,//status of decode head
    IMAGE_STATE_DECODING, //decode status.
    IMAGE_STATE_STOP,   //decode finish.

    //sliding state
	IMAGE_STATE_PAUSE,//the slide pause status.
    IMAGE_STATE_SLIDING//the slide playing status.
}IMAGE_STATE;

typedef struct IMAGE_OUTPUT_INFO
{
	unsigned long outptr;
	unsigned long len;
	unsigned long dispOffset;
}ImageOutputInfo;

/*
*-------------------------------------------------------------------------------
*
*                       预解码上下张图片, add by ctf
*
*-------------------------------------------------------------------------------
*/
//#ifdef _FRAME_BUFFER_
#if (BUFFER_MAX_NUM >= 3)
#define IMAGE_DEC_ADVANCE
#endif

#ifdef IMAGE_DEC_ADVANCE
typedef enum
{
    IMAGE_DEC_DECODING,     //正在解码
    IMAGE_DEC_STOP,         //解码完成
    IMAGE_DEC_UNSUPPORTED,    //格式不支持
    IMAGE_DEC_WAITING       //等待解码
}IMAGE_DEC_ADVANCE_STATE;

typedef enum
{
    MENU_KEY,
    FFD_KEY,    //next picture.
    FFW_KEY,    //previous picture.
    PLAY_KEY    //automatic scan
}KEY_INFO;

EXT IMAGE_DEC_ADVANCE_STATE CurImageDecState;
EXT IMAGE_DEC_ADVANCE_STATE NextImageDecState;
EXT IMAGE_DEC_ADVANCE_STATE PreImageDecState;

EXT KEY_INFO gCurKeyInfo;
EXT UINT16 gCurDisFrameIndex;       //当前屏幕显示的framebuffer
EXT UINT16 gUnsupportFrameIndex;
EXT UINT16 gIsContinueDecode;       //是否继续解码上一张或下一张图片

EXT uint32 gMarkSysTickCounter;     //按下play键，第一次自动播放下一张图片的时间间隔
EXT uint32 gCurImageSlideShowTick;  //播放两张图片之间的时间间隔

EXT UINT16 gIsDisNextImage;         //刷新下一张图片标志
EXT UINT16 gIsDisPreImage;          //刷新上一张图片标志
EXT UINT16 gClearLCD;

EXT TASK_ARG NextImageTaskArg;      //记录下一张图片文件格式不支持的信息
EXT TASK_ARG PreImageTaskArg;       //记录上一张图片文件格式不支持的信息
#endif
/*
*-------------------------------------------------------------------------------
*
*                           Variable define
*
*-------------------------------------------------------------------------------
*/
EXT int ImageDecState;//decode status--head, body,finish
EXT int ImageSlideState;//the status of slide.
_ATTR_IMAGE_BSS_
EXT BOOL  PicDirection;
_ATTR_IMAGE_BSS_
EXT UINT16  ImageErrorNum;
EXT uint32 ImageMaxWidth;
EXT uint32 ImageMaxHeight;
EXT uint32 ImageLeft;
EXT uint32 ImageTop;

/*
    image memset
*/
void ImageMemSet(uint32 *trg, int data, uint32 len);

/*
--------------------------------------------------------------------------------

   Functon Declaration

--------------------------------------------------------------------------------
*/
EXT void    PictureInit(void *pArg);
EXT UINT32  PictureService(void);
EXT void    PictureDeInit(void);
EXT BOOLEAN ImageDecodeProc(MSG_ID id,void * msg);

//slide state
EXT BOOLEAN ImageIsSliding(void);
EXT BOOLEAN ImageIsPause(void);

//dec state
EXT BOOLEAN ImageIsStart(void);
EXT BOOLEAN ImageIsDecoding(void);
EXT BOOLEAN ImageIsStop(void);

#ifdef IMAGE_DEC_ADVANCE
EXT BOOLEAN CurImageIsDecoding(void);
EXT BOOLEAN NextImageIsDecoding(void);
EXT BOOLEAN PreImageIsDecoding(void);

EXT BOOLEAN CurImageIsStop(void);
EXT BOOLEAN NextImageIsStop(void);
EXT BOOLEAN PreImageIsStop(void);

EXT BOOLEAN CurImageIsUnSupported(void);
EXT BOOLEAN NextImageIsUnSupported(void);
EXT BOOLEAN PreImageIsUnSupported(void);

EXT BOOLEAN NextImageIsWaiting(void);
EXT BOOLEAN PreImageIsWaiting(void);

EXT void AdvanceDecVariableInit(void);
#endif
/*
--------------------------------------------------------------------------------

  Description:  image thread.

--------------------------------------------------------------------------------
*/

#ifdef _IN_IMAGE_CONTROL_
EXT THREAD PictureThread = {

    NULL,
    NULL,

    PictureInit,
    PictureService,
    PictureDeInit,

    NULL
};
#else
EXT THREAD PictureThread;
#endif

/*
********************************************************************************
*
*                         End of PictureControl.h
*
********************************************************************************
*/

#endif


