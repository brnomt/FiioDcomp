/*
********************************************************************************************
*
*        Copyright (c):  Fuzhou Rockchip Electronics Co., Ltd
*                             All rights reserved.
*
* FileName: App\music\media_library.c
* Owner: wrm
* Date: 2015.8.20
* Time: 17:29:00
* Version: 1.0
* Desc: music play menu task
* History:
*    <author>    <date>       <time>     <version>     <Desc>
*    Benjo.lei        2016.1.26     17:29:00   1.0
********************************************************************************************
*/
#include "BspConfig.h"
#ifdef __APP_MEDIA_LIBRARY_C__

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   #include define
*
*---------------------------------------------------------------------------------------------------------------------
*/
#define NOT_INCLUDE_OTHER
#include "typedef.h"
#include "RKOS.h"
#include "Bsp.h"
#include "global.h"
#include "SysInfoSave.h"
#include "TaskPlugin.h"
#include "device.h"
#include "LCDDriver.h"
#include "GUITask.h"
#include "GUIManager.h"
#include "KeyDevice.h"
#include "..\Resource\ImageResourceID.h"
#include "..\Resource\MenuResourceID.h"
#include "media_library.h"

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   #define / #typedef define
*
*---------------------------------------------------------------------------------------------------------------------
*/
typedef enum
{
    MEDIA_TYPE_KEY = 0,
} eMEDIA_TYPE_CMD;

typedef  struct _MEDIA_ASK_QUEUE
{
    eMEDIA_TYPE_CMD type;
    uint32 cmd;
}MEDIA_ASK_QUEUE;

typedef  struct _MEDIA_TASK_DATA_BLOCK
{
    pQueue AskQueue;
    HGC hSelect;

    RKGUI_SELECT_ITEM item[8];
}MEDIA_TASK_DATA_BLOCK;

static MEDIA_TASK_DATA_BLOCK * gpstMediaData;
/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local variable define
*
*---------------------------------------------------------------------------------------------------------------------
*/


/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   global variable define
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local function declare
*
*---------------------------------------------------------------------------------------------------------------------
*/
/*******************************************************************************
** Name: MediaLibraryTask_ButtonCallBack
** Input:APP_RECIVE_MSG_EVENT event_type, uint32 event, void * arg, HGC pGc
** Return: rk_err_t
** Owner:Benjo.lei
** Date: 2016.1.26
** Time: 18:00:52
*******************************************************************************/
_APP_MEDIA_LIBRARY_COMMON_
COMMON FUN rk_err_t MediaLibraryTask_ButtonCallBack(APP_RECIVE_MSG_EVENT event_type, uint32 event, void * arg, HGC pGc)
{
#ifdef _USE_GUI_
   MEDIA_ASK_QUEUE AskQueue;

    if(event_type==APP_RECIVE_MSG_EVENT_KEY)
    {
        AskQueue.type = MEDIA_TYPE_KEY;
        AskQueue.cmd  = event;

        rkos_queue_send(gpstMediaData->AskQueue, &AskQueue, 0);
    }
#endif
    return RK_SUCCESS;
}

/*******************************************************************************
** Name: BrowserUITask_SelectCallBack
** Input:HGC pGc, eSELECT_EVENT_TYPE event_type, void * arg, int offset
** Return:  rk_err_t
** Owner:cjh
** Date: 2015.12.29
** Time: 17:59:39
*******************************************************************************/
_APP_MEDIA_LIBRARY_COMMON_
COMMON FUN  rk_err_t MediaLibrary_SelectCallBack(HGC pGc, eSELECT_EVENT_TYPE event_type, void * arg, int offset)
{
    RKGUI_SELECT_ITEM * item= (RKGUI_SELECT_ITEM *)arg;
    switch(event_type)
    {
        case SELECT_ENVEN_UPDATA:
            item->cmd= gpstMediaData->item[offset].cmd;
            item->text_id= gpstMediaData->item[offset].text_id;
            item->sel_icon= gpstMediaData->item[offset].sel_icon;
            item->unsel_icon= gpstMediaData->item[offset].unsel_icon;
            break;
    }
    return RK_SUCCESS;
}

/*******************************************************************************
** Name: MediaLibrary_GuiInit
** Input:void
** Return: rk_err_t
** Owner:Benjo.lei
** Date: 2016.1.26
** Time: 17:15:15
*******************************************************************************/
_APP_MEDIA_LIBRARY_COMMON_
COMMON API rk_err_t MediaLibrary_GuiInit(void)
{
    RKGUI_SELECT_ARG stSelectArg;

    gpstMediaData->item[0].cmd= TEXT_CMD_ID;
    gpstMediaData->item[0].text_id= SID_ALL_MUISC_FILE;
    gpstMediaData->item[0].sel_icon= -1;
    gpstMediaData->item[0].unsel_icon= IMG_ID_ALLMUSIC;

    gpstMediaData->item[1].cmd= TEXT_CMD_ID;
    gpstMediaData->item[1].text_id= SID_ARTIST;
    gpstMediaData->item[1].sel_icon= -1;
    gpstMediaData->item[1].unsel_icon= IMG_ID_MEDIA_RECORDFILE;

    gpstMediaData->item[2].cmd= TEXT_CMD_ID;
    gpstMediaData->item[2].text_id= SID_ALBUM;
    gpstMediaData->item[2].sel_icon= -1;
    gpstMediaData->item[2].unsel_icon= IMG_ID_ABLUM;

    gpstMediaData->item[3].cmd= TEXT_CMD_ID;
    gpstMediaData->item[3].text_id= SID_GENRE;
    gpstMediaData->item[3].sel_icon= -1;
    gpstMediaData->item[3].unsel_icon= IMG_ID_GENRE;

    gpstMediaData->item[4].cmd= TEXT_CMD_ID;
    gpstMediaData->item[4].text_id= SID_DIR_LIST;
    gpstMediaData->item[4].sel_icon= -1;
    gpstMediaData->item[4].unsel_icon= IMG_ID_LIST;

    gpstMediaData->item[5].cmd= TEXT_CMD_ID;
    gpstMediaData->item[5].text_id= SID_MY_FAVORITE;
    gpstMediaData->item[5].sel_icon= -1;
    gpstMediaData->item[5].unsel_icon= IMG_ID_LIST;

    stSelectArg.x= 0;
    stSelectArg.y= 20;
    stSelectArg.xSize= 128;
    stSelectArg.ySize= 137;
    stSelectArg.display = 1;
    stSelectArg.level= 0;

    stSelectArg.Background= IMG_ID_BROWSER_BACKGROUND;
    stSelectArg.SeekBar= IMG_ID_BROWSER_SCOLL2;
    stSelectArg.Cursor= 0;
    stSelectArg.ItemStartOffset= 0;
    stSelectArg.itemNum= 6;
    stSelectArg.MaxDisplayItem= 8;
    stSelectArg.IconBoxSize= 18;

    stSelectArg.pReviceMsg= MediaLibrary_SelectCallBack;
    stSelectArg.CursorStyle= IMG_ID_SEL_ICON;

    gpstMediaData->hSelect = GUITask_CreateWidget(GUI_CLASS_SELECT, &stSelectArg);

    return RK_SUCCESS;
}

/*******************************************************************************
** Name: MediaLibrary_GuiDeInit
** Input:void
** Return: rk_err_t
** Owner:Benjo.lei
** Date: 2016.1.26
** Time: 17:15:15
*******************************************************************************/
_APP_MEDIA_LIBRARY_COMMON_
COMMON API rk_err_t MediaLibrary_GuiDeInit(void)
{
    GuiTask_ScreenLock();
    if( gpstMediaData->hSelect!= NULL )
    {
        GuiTask_DeleteWidget(gpstMediaData->hSelect);
    }
    GuiTask_ScreenUnLock();
    return RK_SUCCESS;
}
/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   API(common) define
*
*---------------------------------------------------------------------------------------------------------------------
*/
/*******************************************************************************
** Name: RecodTask_Enter
** Input:uint32 event
** Return: rk_err_t
** Owner:Benjo.lei
** Date: 2016.1.26
** Time: 17:15:15
*******************************************************************************/
_APP_MEDIA_LIBRARY_COMMON_
COMMON API rk_err_t MediaLibrary_KeyEventHD(uint32 event)
{
    switch(event)
    {
        case KEY_VAL_ESC_SHORT_UP:
            MediaLibrary_GuiDeInit();
            MainTask_TaskSwtich(TASK_ID_MEDIA_LIBRARY, 0, TASK_ID_MAIN, 0, NULL);
            while(1)
            {
                rkos_sleep(2000);
            }
            break;

        default :
            break;
    }
    return RK_SUCCESS;
}


/*******************************************************************************
** Name: MediaLibrary_Enter
** Input:void
** Return: void
** Owner:Benjo.lei
** Date: 2016.1.26
** Time: 17:15:15
*******************************************************************************/
_APP_MEDIA_LIBRARY_COMMON_
COMMON API void MediaLibrary_Enter(void)
{
    MEDIA_ASK_QUEUE MediaAskQueue;

    MediaLibrary_GuiInit();
    while(1)
    {
        rkos_queue_receive(gpstMediaData->AskQueue, &MediaAskQueue, MAX_DELAY);
        switch(MediaAskQueue.type)
        {
            case MEDIA_TYPE_KEY:
                MediaLibrary_KeyEventHD(MediaAskQueue.cmd);
                break;

            default :
                break;
        }
    }
}

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   API(init) define
*
*---------------------------------------------------------------------------------------------------------------------
*/
/*******************************************************************************
** Name: AppMediaTask_Init
** Input:void *pvParameters, void *arg
** Return: rk_err_t
** Owner:Benjo.lei
** Date: 2016.1.26
** Time: 17:15:15
*******************************************************************************/
_APP_MEDIA_LIBRARY_INIT_
INIT API rk_err_t MediaLibrary_Init(void *pvParameters, void *arg)
{
    gpstMediaData= (MEDIA_TASK_DATA_BLOCK *)rkos_memory_malloc(sizeof(MEDIA_TASK_DATA_BLOCK));
    if(gpstMediaData== NULL)
    {
        return RK_ERROR;
    }

    gpstMediaData->AskQueue= rkos_queue_create(1, sizeof(MEDIA_ASK_QUEUE));
    if( gpstMediaData->AskQueue== NULL )
    {
        rkos_memory_free(gpstMediaData);
        return RK_ERROR;
    }

    gpstMediaData->hSelect= NULL;
#ifdef _USE_GUI_
    GuiTask_AppReciveMsg(MediaLibraryTask_ButtonCallBack);
#endif

    return RK_SUCCESS;
}

/*******************************************************************************
** Name: MediaLibrary_DeInit
** Input:void *pvParameters
** Return: rk_err_t
** Owner:Benjo.lei
** Date: 2016.1.26
** Time: 17:15:15
*******************************************************************************/
_APP_MEDIA_LIBRARY_INIT_
INIT API rk_err_t MediaLibrary_DeInit(void *pvParameters)
{
    GuiTask_AppUnReciveMsg(MediaLibraryTask_ButtonCallBack);
    rkos_queue_delete(gpstMediaData->AskQueue);
    rkos_memory_free(gpstMediaData);
    return RK_SUCCESS;
}
#endif
