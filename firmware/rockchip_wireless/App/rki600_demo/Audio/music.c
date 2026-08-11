/*
********************************************************************************************
*
*        Copyright (c):  Fuzhou Rockchip Electronics Co., Ltd
*                             All rights reserved.
*
* FileName: rk-iot\App\Audio\music.c
* Owner: cjh
* Date: 2015.7.17
* Time: 16:38:34
* Version: 1.0
* Desc:
* History:
*    <author>    <date>       <time>     <version>     <Desc>
*    cjh     2015.7.17     16:38:34   1.0
********************************************************************************************
*/


#include "BspConfig.h"
#ifdef __APP_AUDIO_MUSIC_C__

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   #include define
*
*---------------------------------------------------------------------------------------------------------------------
*/
#include "RKOS.h"
#include "DeviceInclude.h"
#include "music.h"
#include "effect.h"
#include "BSP.h"
#include "http.h"
#include "wiced_management.h"
/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   #define / #typedef define
*
*---------------------------------------------------------------------------------------------------------------------
*/


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
rk_err_t music_shell_set_rp(uint8 * pstr);
rk_err_t music_shell_set_sf(uint8 * pstr);
rk_err_t music_shell_ff_pause(uint8 * pstr);
rk_err_t music_shell_ff_resume(uint8 * pstr);
rk_err_t music_shell_mute(uint8 * pstr);
rk_err_t music_shell_unmute(uint8 * pstr);
rk_err_t music_shell_pause(uint8 * pstr);
rk_err_t music_shell_play(uint8 * pstr);
rk_err_t music_shell_stop(uint8 * pstr);
rk_err_t music_shell_prev(uint8 * pstr);
rk_err_t music_shell_next(uint8 * pstr);
rk_err_t music_shell_ffw(uint8 * pstr);
rk_err_t music_shell_ffw_stop(uint8 * pstr);
rk_err_t music_shell_ffd(uint8 * pstr);
rk_err_t music_shell_ffd_stop( uint8 * pstr);
rk_err_t music_shell_set_eq(uint8 * pstr);
rk_err_t music_shell_set_vol(uint8 * pstr);
rk_err_t music_shell_create(uint8 * pstr);
rk_err_t music_shell_del(uint8 * pstr);
rk_err_t music_shell_help(void);

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   API(common) define
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local function(common) define
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   API(init) define
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local function(init) define
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   API(shell) define
*
*---------------------------------------------------------------------------------------------------------------------
*/
_APP_AUDIO_MUSIC_SHELL_
static SHELL_CMD ShellMusicName[] =
{
    "play",NULL,"NULL","NULL",
    "stop",NULL,"NULL","NULL",
    "prev",NULL,"NULL","NULL",
    "next",NULL,"NULL","NULL",
    "ffw",NULL,"NULL","NULL",
    "ffws",NULL,"NULL","NULL",
    "ffd",NULL,"NULL","NULL",
    "ffds",NULL,"NULL","NULL",
    "eq",NULL,"NULL","NULL",
    "sf",NULL,"NULL","NULL",
    "rp",NULL,"NULL","NULL",
    "vol",NULL,"NULL","NULL",
    "create",NULL,"NULL","NULL",
    "pause",NULL,"NULL","NULL",
    "ffr",NULL,"NULL","NULL",
    "ffp",NULL,"NULL","NULL",
    "delete",NULL,"NULL","NULL",
    "help",NULL,"NULL","NULL",
    "\b",NULL,"NULL","NULL",               // the end
};

/*******************************************************************************
** Name: music_shell
** Input:(HDC dev,  uint8 * pstr)
** Return: rk_err_t
** Owner:cjh
** Date: 2015.7.17
** Time: 16:48:43
*******************************************************************************/
_APP_AUDIO_MUSIC_SHELL_
SHELL API rk_err_t music_shell(HDC dev, uint8 * pstr)
{
    uint32 i = 0;
    uint8  *pItem;
    uint16 StrCnt = 0;
    rk_err_t   ret;
    uint8 Space;

    StrCnt = ShellItemExtract(pstr,&pItem, &Space);

    if (StrCnt == 0)
    {
        printf("\n StrCnt = 0 \n");
        return RK_ERROR;
    }
    ret = ShellCheckCmd(ShellMusicName, pItem, StrCnt);
    if (ret < 0)
    {
        printf("\n ret < 0 \n");
        return RK_ERROR;
    }
    i = (uint32)ret;
    pItem += StrCnt;
    pItem++;         //remove '.',the point is the useful item

    switch (i)
    {
        case 0x00:
            ret = music_shell_play(pItem);
            break;

        case 0x01:
            ret = music_shell_stop(pItem);
            break;

        case 0x02:
            ret = music_shell_prev(pItem);
            break;

        case 0x03:
            ret = music_shell_next(pItem);
            break;

        case 0x04:
            ret = music_shell_ffw(pItem);
            break;

        case 0x05:
            ret = music_shell_ffw_stop(pItem);
            break;

        case 0x06:
            ret = music_shell_ffd(pItem);
            break;

        case 0x07:
            ret = music_shell_ffd_stop(pItem);
            break;

        case 0x08:
            ret = music_shell_set_eq(pItem);
            break;

        case 0x09:
            ret = music_shell_set_sf(pItem);
            break;

        case 0x0a:
            ret = music_shell_set_rp(pItem);
            break;

        case 0x0b:
            ret = music_shell_set_vol(pItem);
            break;

        case 0x0c:
            ret = music_shell_create(pItem);
            break;

        case 0x0d:
            ret = music_shell_pause(pItem);
            break;

        case 0x0e:
            ret = music_shell_ff_resume(pItem);
            break;

        case 0x0f:
            ret = music_shell_ff_pause(pItem);
            break;

        case 0x10:
            ret = music_shell_del(pItem);
            break;

        case 0x11:
            ret = music_shell_help();
            break;

        default:
            ret = RK_ERROR;
            break;
    }
    return ret;
}

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local function(shell) define
*
*---------------------------------------------------------------------------------------------------------------------
*/
/*******************************************************************************
** Name: music_shell_set_rp
** Input:uint8 * pstr
** Return: rk_err_t
** Owner:aaron.sun
** Date: 2016.1.21
** Time: 19:47:02
*******************************************************************************/
_APP_AUDIO_MUSIC_SHELL_
SHELL FUN rk_err_t music_shell_set_rp(uint8 * pstr)
{

#ifdef SHELL_HELP
    pstr--;
    if (pstr[0] == '.')
    {
        //list have sub cmd
        pstr++;
        if (StrCmpA(pstr, "help", 4) == 0)
        {
            rk_print_string("\n   music.rp /d : set repeate dir mode");
            rk_print_string("\n   music.rp /o : set repeate one song mode");
            rk_print_string("\n   music.rp /e : exit repeate mode");
            return RK_SUCCESS;
        }
        else
        {
            return RK_ERROR;
        }
    }
    else
    {
        pstr++;
    }
#endif

    if (StrCmpA(pstr, "/d", 2) == 0)
    {
        AudioControlTask_SendCmd(AUDIO_CMD_REPEATSET, (void *)AUIDO_FOLDER_REPEAT, SYNC_MODE);
        return RK_SUCCESS;
    }
    else if(StrCmpA(pstr, "/o", 2) == 0)
    {
        AudioControlTask_SendCmd(AUDIO_CMD_REPEATSET, (void *)AUDIO_REPEAT, SYNC_MODE);
        return RK_SUCCESS;
    }
    else if(StrCmpA(pstr, "/e", 2) == 0)
    {
        AudioControlTask_SendCmd(AUDIO_CMD_REPEATSET, (void *)AUDIO_FOLDER_ONCE, SYNC_MODE);
        return RK_SUCCESS;
    }

    return RK_ERROR;


}

/*******************************************************************************
** Name: music_shell_set_sf
** Input:uint8 * pstr
** Return: rk_err_t
** Owner:aaron.sun
** Date: 2016.1.21
** Time: 19:45:32
*******************************************************************************/
_APP_AUDIO_MUSIC_SHELL_
SHELL FUN rk_err_t music_shell_set_sf(uint8 * pstr)
{
#ifdef SHELL_HELP
    pstr--;
    if (pstr[0] == '.')
    {
        //list have sub cmd
        pstr++;
        if (StrCmpA(pstr, "help", 4) == 0)
        {
            rk_print_string("\n    music.sf /on : turn on shuffle mode");
            rk_print_string("\n    music.rp /off : turn off shuffle mode");
            return RK_SUCCESS;
        }
        else
        {
            return RK_ERROR;
        }
    }
    else
    {
        pstr++;
    }
#endif

    if (StrCmpA(pstr, "/on", 3) == 0)
    {
        AudioControlTask_SendCmd(AUDIO_CMD_SHUFFLESET, (void *)AUDIO_RAND, SYNC_MODE);
        return RK_SUCCESS;
    }
    else if(StrCmpA(pstr, "/off", 4) == 0)
    {
        AudioControlTask_SendCmd(AUDIO_CMD_SHUFFLESET, (void *)AUDIO_INTURN, SYNC_MODE);
        return RK_SUCCESS;
    }
    return RK_ERROR;

}

/*******************************************************************************
** Name: music_shell_ff_pause
** Input:uint8 * pstr
** Return: rk_err_t
** Owner:aaron.sun
** Date: 2015.11.6
** Time: 9:10:33
*******************************************************************************/
_APP_AUDIO_MUSIC_SHELL_
SHELL FUN rk_err_t music_shell_ff_pause(uint8 * pstr)
{
#ifdef SHELL_HELP
    pstr--;
    if (pstr[0] == '.')
    {
        //list have sub cmd
        pstr++;
        if (StrCmpA(pstr, "help", 4) == 0)
        {
            rk_print_string("\n    music.ffp : mute");
            return RK_SUCCESS;
        }
        else
        {
            return RK_ERROR;
        }
    }
    else
    {
        pstr++;
    }
#endif
    AudioControlTask_SendCmd(AUDIO_CMD_FF_PAUSE, NULL, SYNC_MODE);
    return RK_SUCCESS;
}

/*******************************************************************************
** Name: music_shell_ff_resume
** Input:void
** Return: rk_err_t
** Owner:cjh
** Date: 2015.7.23
** Time: 14:52:44
*******************************************************************************/
_APP_AUDIO_MUSIC_SHELL_
SHELL FUN rk_err_t music_shell_ff_resume(uint8 * pstr)
{
#ifdef SHELL_HELP
    pstr--;
    if (pstr[0] == '.')
    {
        //list have sub cmd
        pstr++;
        if (StrCmpA(pstr, "help", 4) == 0)
        {
            rk_print_string("\n    music.ffr : mute");
            return RK_SUCCESS;
        }
        else
        {
            return RK_ERROR;
        }
    }
    else
    {
        pstr++;
    }
#endif
    AudioControlTask_SendCmd(AUDIO_CMD_FF_RESUME, NULL, SYNC_MODE);
    return RK_SUCCESS;
}


/*******************************************************************************
** Name: music_shell_pause
** Input:void
** Return: rk_err_t
** Owner:cjh
** Date: 2015.7.23
** Time: 14:51:20
*******************************************************************************/
_APP_AUDIO_MUSIC_SHELL_
SHELL FUN rk_err_t music_shell_pause(uint8 * pstr)
{
    uint32 msg;
#ifdef SHELL_HELP
    pstr--;
    if (pstr[0] == '.')
    {
        //list have sub cmd
        pstr++;
        if (StrCmpA(pstr, "help", 4) == 0)
        {
            rk_print_string("\n    music.pause : pause play music");
            return RK_SUCCESS;
        }
        else
        {
            return RK_ERROR;
        }
    }
    else
    {
        pstr++;
    }
#endif
    //AudioPause();
    msg = 1;
    AudioControlTask_SendCmd(AUDIO_CMD_PAUSE, &msg, SYNC_MODE);
    return RK_SUCCESS;
}

/*******************************************************************************
** Name: music_shell_play
** Input:uint8 * pstr
** Return: rk_err_t
** Owner:cjh
** Date: 2015.7.17
** Time: 16:48:43
*******************************************************************************/
_APP_AUDIO_MUSIC_SHELL_
SHELL COMMON rk_err_t music_shell_play(uint8 * pstr)
{
    uint32 msg;
#ifdef SHELL_HELP
    pstr--;
    if (pstr[0] == '.')
    {
        //list have sub cmd
        pstr++;
        if (StrCmpA(pstr, "help", 4) == 0)
        {
            rk_print_string("\n    music.play : play music");
            return RK_SUCCESS;
        }
        else
        {
            return RK_ERROR;
        }
    }
    else
    {
        pstr++;
    }
#endif
    msg = 1;
    AudioControlTask_SendCmd(AUDIO_CMD_RESUME, &msg, SYNC_MODE);

    return RK_SUCCESS;
}


/*******************************************************************************
** Name: music_shell_stop
** Input:HDC dev,  uint8 * pstr
** Return: rk_err_t
** Owner:cjh
** Date: 2015.7.17
** Time: 16:48:43
*******************************************************************************/
_APP_AUDIO_MUSIC_SHELL_
SHELL COMMON rk_err_t music_shell_stop(uint8 * pstr)
{
#ifdef SHELL_HELP
    pstr--;
    if (pstr[0] == '.')
    {
        //list have sub cmd
        pstr++;
        if (StrCmpA(pstr, "help", 4) == 0)
        {
            rk_print_string("\n    music.stop : stop music");
            return RK_SUCCESS;
        }
        else
        {
            return RK_ERROR;
        }
    }
    else
    {
        pstr++;
    }
#endif
    AudioControlTask_SendCmd(AUDIO_CMD_STOP, (void *)Audio_Stop_Force, SYNC_MODE);
    return RK_SUCCESS;
}


/*******************************************************************************
** Name: music_shell_prev
** Input:HDC dev,  uint8 * pstr
** Return: rk_err_t
** Owner:cjh
** Date: 2015.7.17
** Time: 16:48:43
*******************************************************************************/
_APP_AUDIO_MUSIC_SHELL_
SHELL COMMON rk_err_t music_shell_prev(uint8 * pstr)
{
#ifdef SHELL_HELP
    pstr--;
    if (pstr[0] == '.')
    {
        //list have sub cmd
        pstr++;
        if (StrCmpA(pstr, "help", 4) == 0)
        {
            rk_print_string("\n    music.prev : pre song");
            return RK_SUCCESS;
        }
        else
        {
            return RK_ERROR;
        }
    }
    else
    {
        pstr++;
    }
#endif

    AudioControlTask_SendCmd(AUDIO_CMD_PREVFILE, NULL, SYNC_MODE);
    return RK_SUCCESS;
}

/*******************************************************************************
** Name: music_shell_next
** Input:HDC dev,  uint8 * pstr
** Return: rk_err_t
** Owner:cjh
** Date: 2015.7.17
** Time: 16:48:43
*******************************************************************************/
_APP_AUDIO_MUSIC_SHELL_
SHELL COMMON rk_err_t music_shell_next(uint8 * pstr)
{
    uint32 msg;

#ifdef SHELL_HELP
    pstr--;
    if (pstr[0] == '.')
    {
        //list have sub cmd
        pstr++;
        if (StrCmpA(pstr, "help", 4) == 0)
        {
            rk_print_string("\n    music.next : next song");
            return RK_SUCCESS;
        }
        else
        {
            return RK_ERROR;
        }
    }
    else
    {
        pstr++;
    }
#endif

    msg = 1;
    AudioControlTask_SendCmd(AUDIO_CMD_NEXTFILE, &msg, SYNC_MODE);
    return RK_SUCCESS;
}


/*******************************************************************************
** Name: music_shell_ffw
** Input:HDC dev,  uint8 * pstr
** Return: rk_err_t
** Owner:cjh
** Date: 2015.7.17
** Time: 16:48:43
*******************************************************************************/
_APP_AUDIO_MUSIC_SHELL_
SHELL COMMON rk_err_t music_shell_ffw(uint8 * pstr)
{
    uint32 msg;
#ifdef SHELL_HELP
    pstr--;
    if (pstr[0] == '.')
    {
        //list have sub cmd
        pstr++;
        if (StrCmpA(pstr, "help", 4) == 0)
        {
            rk_print_string("\n    music.ffw : ffw");
            return RK_SUCCESS;
        }
        else
        {
            return RK_ERROR;
        }
    }
    else
    {
        pstr++;
    }
#endif
    msg = 2000;
    AudioControlTask_SendCmd(AUDIO_CMD_FFW, (void *)msg, SYNC_MODE);
    return RK_SUCCESS;
}


/*******************************************************************************
** Name: music_shell_ffw_stop
** Input:uint8 * pstr
** Return: rk_err_t
** Owner:cjh
** Date: 2015.7.17
** Time: 16:48:43
*******************************************************************************/
_APP_AUDIO_MUSIC_SHELL_
SHELL COMMON rk_err_t music_shell_ffw_stop(uint8 * pstr)
{
    //uint32 msg;
#ifdef SHELL_HELP
    pstr--;
    if (pstr[0] == '.')
    {
        //list have sub cmd
        pstr++;
        if (StrCmpA(pstr, "help", 4) == 0)
        {
            rk_print_string("\n    music.ffws : ffw stop");
            return RK_SUCCESS;
        }
        else
        {
            return RK_ERROR;
        }
    }
    else
    {
        pstr++;
    }
#endif

    AudioControlTask_SendCmd(AUDIO_CMD_FF_STOP, NULL, SYNC_MODE);
    return RK_SUCCESS;
}

/*******************************************************************************
** Name: music_shell_ffd
** Input:HDC dev,  uint8 * pstr
** Return: rk_err_t
** Owner:cjh
** Date: 2015.7.17
** Time: 16:48:43
*******************************************************************************/
_APP_AUDIO_MUSIC_SHELL_
SHELL COMMON rk_err_t music_shell_ffd(uint8 * pstr)
{
    uint32 msg;
#ifdef SHELL_HELP
    pstr--;
    if (pstr[0] == '.')
    {
        //list have sub cmd
        pstr++;
        if (StrCmpA(pstr, "help", 4) == 0)
        {
            rk_print_string("\n    music.ffd : ffd");
            return RK_SUCCESS;
        }
        else
        {
            return RK_ERROR;
        }
    }
    else
    {
        pstr++;
    }
#endif

    msg = 2000;
    AudioControlTask_SendCmd(AUDIO_CMD_FFD, (void *)msg, SYNC_MODE);
    return RK_SUCCESS;
}

/*******************************************************************************
** Name: music_shell_ffd_stop
** Input:(HDC dev,  uint8 * pstr)
** Return: rk_err_t
** Owner:cjh
** Date: 2015.7.17
** Time: 16:48:43
*******************************************************************************/
_APP_AUDIO_MUSIC_SHELL_
SHELL COMMON rk_err_t music_shell_ffd_stop( uint8 * pstr)
{
    //uint32 msg;
#ifdef SHELL_HELP
    pstr--;
    if (pstr[0] == '.')
    {
        //list have sub cmd
        pstr++;
        if (StrCmpA(pstr, "help", 4) == 0)
        {
            rk_print_string("\n    music.ffds : ffd stop");
            return RK_SUCCESS;
        }
        else
        {
            return RK_ERROR;
        }
    }
    else
    {
        pstr++;
    }
#endif
    AudioControlTask_SendCmd(AUDIO_CMD_FF_STOP, NULL, SYNC_MODE);
    return RK_SUCCESS;
}


/*******************************************************************************
** Name: music_shell_set_eq
** Input:uint8 * pstr
** Return: rk_err_t
** Owner:cjh
** Date: 2015.7.17
** Time: 16:48:43
*******************************************************************************/
_APP_AUDIO_MUSIC_SHELL_
SHELL COMMON rk_err_t music_shell_set_eq(uint8 * pstr)
{
    //MUSIC_CLASS * pstMusic;
    AUDIO_DEV_ARG stParg;

#ifdef SHELL_HELP
    pstr--;
    if (pstr[0] == '.')
    {
        //list have sub cmd
        pstr++;
        if (StrCmpA(pstr, "help", 4) == 0)
        {
            rk_print_string("\n    music.eq /h  : set eq heavy mode");
            rk_print_string("\n    music.eq /p  : set eq pop mode");
            rk_print_string("\n    music.eq /j  : set eq jazz mode");
            rk_print_string("\n    music.eq /un : set eq unique mode");
            rk_print_string("\n    music.eq /c  : set eq class mode");
            rk_print_string("\n    music.eq /b  : set eq bass mode");
            rk_print_string("\n    music.eq /r  : set eq rock mode");
            rk_print_string("\n    music.eq /us : set eq user mode");
            rk_print_string("\n    music.eq /n  : set eq nor mode");
            return RK_SUCCESS;
        }
        else
        {
            return RK_ERROR;
        }
    }
    else
    {
        pstr++;
    }
#endif

    if (StrCmpA(pstr, "/h", 2) == 0)
    {
        AudioControlTask_SendCmd(AUDIO_CMD_EQSET, (void *)EQ_HEAVY, SYNC_MODE);
        return RK_SUCCESS;
    }
    else if(StrCmpA(pstr, "/p", 2) == 0)
    {
        AudioControlTask_SendCmd(AUDIO_CMD_EQSET, (void *)EQ_POP, SYNC_MODE);
        return RK_SUCCESS;
    }
    else if(StrCmpA(pstr, "/j", 2) == 0)
    {
        AudioControlTask_SendCmd(AUDIO_CMD_EQSET, (void *)EQ_JAZZ, SYNC_MODE);
        return RK_SUCCESS;
    }
    else if(StrCmpA(pstr, "/un", 3) == 0)
    {
        AudioControlTask_SendCmd(AUDIO_CMD_EQSET, (void *)EQ_UNIQUE, SYNC_MODE);
        return RK_SUCCESS;
    }
    else if(StrCmpA(pstr, "/c", 2) == 0)
    {
        AudioControlTask_SendCmd(AUDIO_CMD_EQSET, (void *)EQ_CLASS, SYNC_MODE);
        return RK_SUCCESS;
    }
    else if(StrCmpA(pstr, "/b", 2) == 0)
    {
        AudioControlTask_SendCmd(AUDIO_CMD_EQSET, (void *)EQ_BASS, SYNC_MODE);
        return RK_SUCCESS;
    }
    else if(StrCmpA(pstr, "/r", 2) == 0)
    {
        AudioControlTask_SendCmd(AUDIO_CMD_EQSET, (void *)EQ_ROCK, SYNC_MODE);
        return RK_SUCCESS;
    }
    else if(StrCmpA(pstr, "/us", 4) == 0)
    {
        AudioControlTask_SendCmd(AUDIO_CMD_EQSET, (void *)EQ_USER, SYNC_MODE);
        return RK_SUCCESS;
    }
    else if(StrCmpA(pstr, "/n", 2) == 0)
    {
        AudioControlTask_SendCmd(AUDIO_CMD_EQSET, (void *)EQ_NOR, SYNC_MODE);
        return RK_SUCCESS;
    }


    return RK_SUCCESS;
}


/*******************************************************************************
** Name: music_shell_set_vol
** Input:uint8 * pstr
** Return: rk_err_t
** Owner:cjh
** Date: 2015.7.17
** Time: 16:48:43
*******************************************************************************/
_APP_AUDIO_MUSIC_SHELL_
SHELL COMMON rk_err_t music_shell_set_vol(uint8 * pstr)
{
    //MUSIC_CLASS * pstMusic;
    AUDIO_DEV_ARG stParg;
    uint8 vol;

#ifdef SHELL_HELP
    pstr--;
    if (pstr[0] == '.')
    {
        //list have sub cmd
        pstr++;
        if (StrCmpA(pstr, "help", 4) == 0)
        {
            printf("music.set_vol Volume: set volume \r\n");
            return RK_SUCCESS;
        }
        else
        {
            return RK_ERROR;
        }
    }
    else
    {
        pstr++;
    }
#endif

    return RK_SUCCESS;
}

/*******************************************************************************
** Name: music_shell_create
** Input:uint8 * pstr
** Return: rk_err_t
** Owner:cjh
** Date: 2015.7.17
** Time: 16:48:43
*******************************************************************************/
_APP_AUDIO_MUSIC_SHELL_
SHELL COMMON rk_err_t music_shell_create(uint8 * pstr)
{
    RK_TASK_AUDIOCONTROL_ARG Arg;

#ifdef SHELL_HELP
    pstr--;
    if (pstr[0] == '.')
    {
        //list have sub cmd
        pstr++;
        if (StrCmpA(pstr, "help", 4) == 0)
        {
            rk_print_string("music.open : open music    \r\n");
            return RK_SUCCESS;
        }
        else
        {
            return RK_ERROR;
        }
    }
    else
    {
        pstr++;
    }
#endif

    Arg.ucSelPlayType = SOURCE_FROM_FILE_BROWSER;
    Arg.FileNum = 0;
    Arg.pfAudioState = NULL;
    memcpy(Arg.filepath, L"C:\\01 Gloria.ogg", 34);

    if(RKTaskCreate(TASK_ID_AUDIOCONTROL, 0, &Arg, SYNC_MODE) != RK_SUCCESS)
    {
         rk_printf("Audio control task create failure");
         return RK_SUCCESS;
    }

    #if 0
    FW_LoadSegment(SEGMENT_ID_AUDIOCONTROL_INIT, SEGMENT_OVERLAY_ALL);
    AudioControlTask_Init(NULL, &Arg);
    FW_RemoveSegment(SEGMENT_ID_AUDIOCONTROL_INIT);

    FW_LoadSegment(SEGMENT_ID_STREAMCONTROL_INIT, SEGMENT_OVERLAY_ALL);
    StreamControlTask_Init(NULL, NULL);
    FW_RemoveSegment(SEGMENT_ID_STREAMCONTROL_INIT);

    RKTaskCreate2(AudioControlTask_Enter, NULL, NULL, "audio", 4096, 127, NULL);
    RKTaskCreate2(StreamControlTask_Enter, NULL, NULL, "stream", 4096, 100, NULL);
    #endif

    #if 0
    ret = HttpTask_Get("http://192.168.1.101/I%20love%20you.pcm");
    if(ret == RK_SUCCESS)
        printf("\nhttp ok\n");
    else
        printf("\nhttp error\n");

    RKTaskCreate(TASK_ID_MEDIA, 0, NULL, SYNC_MODE);
    #endif

    return RK_SUCCESS;
}

/*******************************************************************************
** Name: music_shell_del
** Input:uint8 * pstr
** Return: rk_err_t
** Owner:cjh
** Date: 2015.7.17
** Time: 16:48:43
*******************************************************************************/
_APP_AUDIO_MUSIC_SHELL_
SHELL COMMON rk_err_t music_shell_del(uint8 * pstr)
{
    uint32 msg;
#ifdef SHELL_HELP
    pstr--;
    if (pstr[0] == '.')
    {
        //list have sub cmd
        pstr++;
        if (StrCmpA(pstr, "help", 4) == 0)
        {
            rk_print_string("\nopen : open music");
            return RK_SUCCESS;
        }
        else
        {
            return RK_ERROR;
        }
    }
    else
    {
        pstr++;
    }
#endif
    RKTaskDelete(TASK_ID_AUDIOCONTROL, 0, SYNC_MODE);
    return RK_SUCCESS;
}

/*******************************************************************************
** Name: music_shell_help
** Input:void
** Return: rk_err_t
** Owner:cjh
** Date: 2015.7.17
** Time: 16:48:43
*******************************************************************************/
_APP_AUDIO_MUSIC_SHELL_
SHELL COMMON rk_err_t music_shell_help(void)
{
    rk_print_string("\nmusic命令集提供了一系列的命令对music进行操作");
    rk_print_string("\nmusic包含的子命令如下:");
    rk_print_string("\n    music.open     : 打开音乐播放");
    rk_print_string("\n    music.play     : 播放");
    rk_print_string("\n    music.stop     : 暂停");
    rk_print_string("\n    music.up       : 上一首");
    rk_print_string("\n    music.next     : 下一首");
    rk_print_string("\n    music.ffw      : 快进");
    rk_print_string("\n    music.ffws     : 停止快进");
    rk_print_string("\n    music.ffd      : 快退");
    rk_print_string("\n    music.ffds     : 停止快退");
    rk_print_string("\n    music.eq       : eq设置入口");
    rk_print_string("\n    music.vol      : 设置音量");
    rk_print_string("\n    music.rp       : 设置循环模式");
    rk_print_string("\n    music.sf       : 设置shuffle模式");

    return RK_SUCCESS;
}

#endif
