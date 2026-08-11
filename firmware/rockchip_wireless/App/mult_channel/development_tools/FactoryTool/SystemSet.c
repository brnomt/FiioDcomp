/*
********************************************************************************
*                   Copyright (C),2004-2015, Fuzhou Rockchip Electronics Co.,Ltd.
*                         All rights reserved.
*
* File Name¡êo  SystemSet.c
*
* Description:  set menu execution function configuration
*
* History:      <author>          <time>        <version>
*               anzhiguo      2009-3-3          1.0
*    desc:      the functions below will be excuted when press sure key and it has not child item,
                the itemNum be force set to CurItemInFatherID,that is the index of current item,so it can
                be used to do porper contorl in inside of function.
********************************************************************************
*/
#define _SYSTEMSET_IN_

#include "SysInclude.h"

#ifdef _SYSSET_


#include "DialogBox.h"
#include "setcommon.h"
#include "SystemSet.h"
#include "SetMenuInterface.h"
#include "setmenu.h"
#include "hold.h"

#include "FsInclude.h"
#ifdef _MUSIC_
#include "AudioControl.h"
#endif

extern SYSTICK_LIST SetPowerDownTimer;

/*
--------------------------------------------------------------------------------
  Function name : UINT16 LanguegeSelect(UINT16 itemNum)
  Author        : anzhiguo
  Description   :

  Input         :
  Return        :

  History:     <author>         <time>         <version>
                anzhiguo     2009-3-3       Ver1.0
  desc:         ORG
--------------------------------------------------------------------------------
*/
_ATTR_SYS_SET_SYSTEM_CODE_//_ATTR_SYS_SET_SERVICE_CODE_
UINT32 LanguegeSelect(UINT32 itemNum)
{
    UINT32 retVal = 0;

    SetLanguage = SetMenuLanguageInfo[itemNum];
    gLangSel = gSysConfig.SysLanguage;
    DefaultLanguage = itemNum;

    return retVal;
}


/*
--------------------------------------------------------------------------------
  Function name : UINT16 BackLightOffTimeSet(UINT16 itemNum)
  Author        : anzhiguo
  Description   :

  Input         :
  Return        :

  History:     <author>         <time>         <version>
                anzhiguo     2009-3-3       Ver1.0
  desc:         ORG
--------------------------------------------------------------------------------
*/
_ATTR_SYS_SET_SYSTEM_CODE_
UINT32 BackLightOffTimeSet(UINT32 itemNum)
{
    UINT32 retVal = 0;

    SetLightOffTime = itemNum;
    BacklightSystickCounterBack = SysTickCounter;
    return retVal;
}

/*
--------------------------------------------------------------------------------
 Function name : UINT16 BackLightLevelSet(UINT16 itemNum)
 Author        : anzhiguo
 Description   :

 Input         :
 Return        :

 History:     <author>         <time>         <version>
               anzhiguo     2009-3-3       Ver1.0
 desc:         ORG
--------------------------------------------------------------------------------
*/
_ATTR_SYS_SET_SYSTEM_CODE_
UINT32 BackLightLevelSet(UINT32 itemNum)
{
    UINT32 retVal = 0;

    BacklightBackup = itemNum;

    return retVal;
}

/*
--------------------------------------------------------------------------------
 Function name : UINT16 BackLightDispModeSet(UINT16 itemNum)
 Author        : anzhiguo
 Description   :

 Input         :
 Return        :

 History:     <author>         <time>         <version>
               anzhiguo     2009-3-3       Ver1.0
 desc:         ORG
--------------------------------------------------------------------------------
*/
_ATTR_SYS_SET_SYSTEM_CODE_
UINT32 BackLightDispModeSet(UINT32 itemNum)
{
    UINT32 retVal = 0;

    SetBackLightMode = itemNum;

    return retVal;
}

/*
--------------------------------------------------------------------------------
 Function name : UINT16 PowerOffTimeSet(UINT16 itemNum)
 Author        : anzhiguo
 Description   :

 Input         :
 Return        :

 History:     <author>         <time>         <version>
               anzhiguo     2009-3-3       Ver1.0
 desc:         ORG
--------------------------------------------------------------------------------
*/
_ATTR_SYS_SET_SYSTEM_CODE_
UINT32 PowerOffTimeSet(UINT32 itemNum)
{
    UINT32 retVal = 0;
    uint32 PowerOffBuff[6] = {0, 10*60*100, 15*60*100, 30*60*100, 60*60*100, 120*60*100};

    SetPowerDownTimer.Counter = 0;

    if (SetPowerOffTime == itemNum)
        return 0;

    SetPowerOffTime = itemNum;
    if (itemNum)
    {
        SetPowerDownTimer.Reload = PowerOffBuff[itemNum];

        if (SetPowerOffFlag == 0)
        {
            SetPowerOffFlag = 1;
            SystickTimerStart(&SetPowerDownTimer);
        }
    }
    else
    {
        if (SetPowerOffFlag == 1)
        {
            SystickTimerStop(&SetPowerDownTimer);
            SetPowerOffFlag = 0;
        }
    }

    return retVal;
}

/*
--------------------------------------------------------------------------------
  Function name : UINT16 ConvertMemMB(UINT16 *pBuff, UINT32 *Mem)
  Author        : anzhiguo
  Description   : proudct information

  Input         :
  Return        :

  History:     <author>         <time>         <version>
                anzhiguo     2009-3-3       Ver1.0
  desc:         ORG
--------------------------------------------------------------------------------
*/

_ATTR_SYS_SET_SYSTEM_CODE_
UINT32 ConvertMemMB(UINT16 *pBuff, UINT32 *Mem)
{
    unsigned long Frememery;
    unsigned int i;
    UINT16 retVal = 0;
    Frememery = (*Mem) >> 10;

    *(pBuff + 4) = Frememery%10 + '0';
    Frememery = Frememery / 10 ;

    *(pBuff + 3) = (Frememery%10) + '0';
    Frememery = Frememery / 10 ;

    *(pBuff + 2) = (Frememery%10) + '0';
    Frememery = Frememery / 10 ;

    *(pBuff + 1) = (Frememery%10) + '0';
    *(pBuff + 0) = (Frememery/10) + '0';

    for (i = 0; i < 4; i++)
    {
        if (*(pBuff + i) == '0')
        {
            *(pBuff + i) = ' ';
        }
        else
        {
            break;
        }
    }
    return retVal;
}
/*
--------------------------------------------------------------------------------
  Function name : UINT16 BeepEnableSet(UINT16 itemNum)
  Author        : Jeff Wu
  Description   :

  Input         :
  Return        :

  History:     <author>         <time>         <version>
                Jeff Wu     2013-10-1       Ver1.0
  desc:         ORG
--------------------------------------------------------------------------------
*/
_ATTR_SYS_SET_SYSTEM_CODE_
UINT32 BeepEnableSet(UINT32 itemNum)
{
    UINT32 retVal = 0;

    SetBeepEnabled = itemNum;

    return retVal;
}

 /*
--------------------------------------------------------------------------------
  Function name : UINT16 FirmwareUpgradeSet(UINT16 itemNum)
  Author        : anzhiguo
  Description   :

  Input         :
  Return        :

  History:     <author>         <time>         <version>
                anzhiguo     2009-3-3       Ver1.0
  desc:         ORG
--------------------------------------------------------------------------------
*/

_ATTR_SYS_SET_SYSTEM_CODE_
UINT32 FirmwareUpgradeSet(UINT32 itemNum)
{
    UINT32 retVal = 0;
    TASK_ARG TaskArg;

    TaskArg.Dialog.Button = DIALOG_BUTTON_NO;
    TaskArg.Dialog.TitleID = SID_WARNING;
    TaskArg.Dialog.ContentID = SID_FIRMWARE_UPGRADE;
    WinCreat(&SetMenuWin, &DialogWin, &TaskArg);

    SendMsg(MSG_FIRMWAREUPGRADE);

    SendMsg(MSG_SETDIALOG_FLAG);

    return retVal;
}

/*
--------------------------------------------------------------------------------
 Function name : void SysSetDefaultValue(void)
 Author        : anzhiguo
 Description   : restore system default value.

 Input         :
 Return        :

 History:     <author>         <time>         <version>
               anzhiguo     2009-3-3       Ver1.0
 desc:         ORG
--------------------------------------------------------------------------------
*/
_ATTR_SYS_SET_SYSTEM_CODE_
void SysSetDefaultValue(void)
{
    uint32 i;
    uint32 Len;
    uint32 SystemDefaultParaAddr;
    uint8  FlashBuf[512];

    FIRMWARE_INFO_T       *pFirmwareModuleInfo;
    SYSTEM_DEFAULT_PARA_T *pSystemDefaultPara;

    ////////////////////////////////////////////////////////////////////////////
    MDReadData(SysDiskID, CodeLogicAddress, 512, FlashBuf);
    pFirmwareModuleInfo = (FIRMWARE_INFO_T *)FlashBuf;

    SystemDefaultParaAddr  = CodeLogicAddress + sizeof(pFirmwareModuleInfo -> LoadStartBase);
    SystemDefaultParaAddr += sizeof(pFirmwareModuleInfo -> ModuleInfo.ModuleNum);
    SystemDefaultParaAddr += pFirmwareModuleInfo -> ModuleInfo.ModuleNum * sizeof(CODE_INFO_T);
    MDReadData(SysDiskID, SystemDefaultParaAddr, sizeof(SYSTEM_DEFAULT_PARA_T), FlashBuf);
    pSystemDefaultPara = (SYSTEM_DEFAULT_PARA_T *)FlashBuf;
    ///////////////////////////////////////////////////////////////////////

    DefaultLanguage = (uint8)pSystemDefaultPara->gLanguage;//HJ
    gSysConfig.SysLanguage = SetMenuLanguageInfo[DefaultLanguage];
    gSysConfig.SysLanguage = (uint8)pSystemDefaultPara->gLanguage;

    gSysConfig.OutputVolume = (uint8)pSystemDefaultPara->Volume;

    gSysConfig.BLmode = (uint8)pSystemDefaultPara->BLMode;

    gSysConfig.BLevel = (uint8)pSystemDefaultPara->BLevel;
    BL_SetLevel(SetBackLightLevel);

    gSysConfig.BLtime = (uint8)pSystemDefaultPara->BLtime;

    gSysConfig.ShutTime = (uint8)pSystemDefaultPara->SettingPowerOffTime;

    gSysConfig.BeepEnabled= (uint8)pSystemDefaultPara->BeepEnabled;

#ifdef _VIDEO_
#endif

#ifdef _MUSIC_
    gSysConfig.MusicConfig.RepeatMode = (uint8)pSystemDefaultPara->MusicRepMode;
    gSysConfig.MusicConfig.PlayOrder = (uint8)pSystemDefaultPara->MusicPlayOrder;
    gSysConfig.MusicConfig.Eq.Mode = pSystemDefaultPara->MusicEqSel;
#ifdef _RK_EQ_
    for (i = 0;i < 5;i++)
    {
        gSysConfig.MusicConfig.Eq.RKCoef.dbGain[i] = 3;
    }
#endif

    SendMsg(MSG_SERVICE_MUSIC_MODE_UPDATE);
    SendMsg(MSG_SERVICE_MUSIC_ORDER_UPDATE);
    SendMsg(MSG_AUDIO_EQSET_UPDATA);
#endif

#ifdef _RADIO_
    gSysConfig.RadioConfig.FmArea = (uint8)pSystemDefaultPara->FMArea;
    gSysConfig.RadioConfig.FmStereo = (uint8)pSystemDefaultPara->FMStereo;
    gSysConfig.RadioConfig.ScanSensitivity= (uint8)pSystemDefaultPara->FMScanSensitivity;
#endif

#ifdef _RECORD_
    gSysConfig.RecordConfig.RecordQuality = 1;
    gSysConfig.RecordConfig.RecordFmt = 1;  //wav
    gSysConfig.RecordConfig.RecordVol = 2;
#endif

#ifdef _EBOOK_
    gSysConfig.TextConfig.AutoPlayTime = (uint8)pSystemDefaultPara->TextAutoPlayTime;
#endif

#ifdef _PICTURE_
    gSysConfig.PicConfig.AutoPlayTime = (uint8)pSystemDefaultPara->PicAutoPlayTime;
#endif

}
void SysSetDefaultValueClone(void)
{
    uint32 i;
    uint32 Len;
    uint32 SystemDefaultParaAddr;
    uint8  FlashBuf[512];

    FIRMWARE_INFO_T       *pFirmwareModuleInfo;
    SYSTEM_DEFAULT_PARA_T *pSystemDefaultPara;
    //printf("set default value\n");
    ////////////////////////////////////////////////////////////////////////////
    MDReadData(SysDiskID, CodeLogicAddress, 512, FlashBuf);
    pFirmwareModuleInfo = (FIRMWARE_INFO_T *)FlashBuf;

    SystemDefaultParaAddr  = CodeLogicAddress + sizeof(pFirmwareModuleInfo -> LoadStartBase);
    SystemDefaultParaAddr += sizeof(pFirmwareModuleInfo -> ModuleInfo.ModuleNum);
    SystemDefaultParaAddr += pFirmwareModuleInfo -> ModuleInfo.ModuleNum * sizeof(CODE_INFO_T);
    MDReadData(SysDiskID, SystemDefaultParaAddr, sizeof(SYSTEM_DEFAULT_PARA_T), FlashBuf);
    pSystemDefaultPara = (SYSTEM_DEFAULT_PARA_T *)FlashBuf;
    ///////////////////////////////////////////////////////////////////////

    DefaultLanguage = DefaultLanguageID;
    gSysConfig.SysLanguage = SetMenuLanguageInfo[DefaultLanguage];
    gSysConfig.SysLanguage = (uint8)pSystemDefaultPara->gLanguage;

    gSysConfig.OutputVolume = (uint8)pSystemDefaultPara->Volume;

    gSysConfig.BLmode = (uint8)pSystemDefaultPara->BLMode;

    gSysConfig.BLevel = (uint8)pSystemDefaultPara->BLevel;
    BL_SetLevel(SetBackLightLevel);

    gSysConfig.BLtime = (uint8)pSystemDefaultPara->BLtime;

    gSysConfig.ShutTime = (uint8)pSystemDefaultPara->SettingPowerOffTime;

    gSysConfig.BeepEnabled= (uint8)pSystemDefaultPara->BeepEnabled;

    #ifdef _MUSIC_
    gSysConfig.MusicConfig.RepeatMode = (uint8)pSystemDefaultPara->MusicRepMode;
    gSysConfig.MusicConfig.PlayOrder = (uint8)pSystemDefaultPara->MusicPlayOrder;
    gSysConfig.MusicConfig.Eq.Mode = pSystemDefaultPara->MusicEqSel;

#ifdef _RK_EQ_
    for (i = 0;i < 5;i++)
    {
        gSysConfig.MusicConfig.Eq.RKCoef.dbGain[i] = 3;
    }
#endif

    SendMsg(MSG_SERVICE_MUSIC_MODE_UPDATE);
    SendMsg(MSG_SERVICE_MUSIC_ORDER_UPDATE);
    SendMsg(MSG_AUDIO_EQSET_UPDATA);
#endif

#ifdef _RADIO_
    gSysConfig.RadioConfig.FmArea = (uint8)pSystemDefaultPara->FMArea;
    gSysConfig.RadioConfig.FmStereo = (uint8)pSystemDefaultPara->FMStereo;
    gSysConfig.RadioConfig.ScanSensitivity= (uint8)pSystemDefaultPara->FMScanSensitivity;
#endif

#ifdef _RECORD_
    gSysConfig.RecordConfig.RecordQuality = 1;
    gSysConfig.RecordConfig.RecordFmt = 1;
    gSysConfig.RecordConfig.RecordVol = 2;
#endif

#ifdef _EBOOK_
    gSysConfig.TextConfig.AutoPlayTime = (uint8)pSystemDefaultPara->TextAutoPlayTime;
#endif

#ifdef _PICTURE_
    gSysConfig.PicConfig.AutoPlayTime = (uint8)pSystemDefaultPara->PicAutoPlayTime;
#endif

}
/*
--------------------------------------------------------------------------------
  Function name : UINT16 SysDefaultValSet(UINT16 itemNum)
  Author        : anzhiguo
  Description   :

  Input         :
  Return        :

  History:     <author>         <time>         <version>
                anzhiguo     2009-3-3       Ver1.0
  desc:         ORG
--------------------------------------------------------------------------------
*/
_ATTR_SYS_SET_SYSTEM_CODE_
UINT32 SysDefaultValSet(UINT32 itemNum)
{
    UINT32 retVal = 0;
    TASK_ARG TaskArg;

    TaskArg.Dialog.Button = DIALOG_BUTTON_NO;
    TaskArg.Dialog.TitleID = SID_WARNING;
    TaskArg.Dialog.ContentID = SID_RESTORE_DEFAULT_VAL;
    WinCreat(&SetMenuWin, &DialogWin, &TaskArg);

    SendMsg(MSG_SYSDEFAULTVALSET);
    // ClearMsg(MSG_FIRMWAREUPGRADE);

    SendMsg(MSG_SETDIALOG_FLAG);

    return retVal;

}


/*
--------------------------------------------------------------------------------
  Function name : void ProductInfoWinInit(void)
  Author        : Anzhiguo
  Description   :

  Input         :
  Return        :

  History:     <author>         <time>         <version>
               Anzhiguo       2009/03/01         Ver1.0
  desc:         ORG
--------------------------------------------------------------------------------
*/
_ATTR_SYS_SET_SYSTEM_CODE_
void ProductInfoWinInit(void)
{
    KeyReset();
    SendMsg(MSG_PRODUCTINFO);
}

/*
--------------------------------------------------------------------------------
  Function name : void ProductInfoWinDeInit(void)
  Author        : Anzhiguo
  Description   :

  Input         :
  Return        :

  History:     <author>         <time>         <version>
               Anzhiguo     2009/03/01         Ver1.0
  desc:         ORG
--------------------------------------------------------------------------------
*/
_ATTR_SYS_SET_SYSTEM_CODE_
void ProductInfoWinDeInit(void)
{

}

/*
--------------------------------------------------------------------------------
  Function name : UINT32 SetMusicEqService(void)
  Author        : Anzhiguo
  Description   :

  Input         :
  Return        :

  History:     <author>         <time>         <version>
                Anzhiguo     2009/03/01         Ver1.0
  desc:         ORG
--------------------------------------------------------------------------------
*/
_ATTR_SYS_SET_SYSTEM_CODE_
UINT32 ProductInfoWinService(void)
{
    TASK_ARG TaskArg;

    return(RETURN_OK);
}

/*
--------------------------------------------------------------------------------
  Function name : UINT32 MainMenuKey(void)
  Author        : Anzhiguo
  Description   :

  Input         :
  Return        :

  History:     <author>         <time>         <version>
               Anzhiguo     2009/03/01         Ver1.0
  desc:         ORG
--------------------------------------------------------------------------------
*/
_ATTR_SYS_SET_SYSTEM_CODE_
UINT32 ProductInfoWinKey(void)
{
    UINT16 RetVal;
    UINT32 userEqSetKeyVal;
    TASK_ARG TaskArg;

    userEqSetKeyVal = GetKeyVal();
    switch (userEqSetKeyVal)
    {
        case KEY_VAL_ESC_SHORT_UP: //return up level
            WinDestroy(&ProductInfoWin);
            SendMsg(MSG_SYS_SET_DISPLAY);
            break;

        case KEY_VAL_PLAY_SHORT_UP:
            WinDestroy(&ProductInfoWin);
            SendMsg(MSG_SYS_SET_DISPLAY);
            break;

        case KEY_VAL_HOLD_ON:
            TaskArg.Hold.HoldAction = HOLD_STATE_ON;
            WinCreat(&ProductInfoWin, &HoldWin, &TaskArg);
            break;

        case KEY_VAL_HOLD_OFF:
            TaskArg.Hold.HoldAction = HOLD_STATE_OFF;
            WinCreat(&ProductInfoWin, &HoldWin, &TaskArg);

            break;

        default:
            break;
    }

    return (RetVal);
}

/*
--------------------------------------------------------------------------------
  Function name : void SetMusicEqDisplay(void)
  Author        : Anzhiguo
  Description   :

  Input         :
  Return        :

  History:     <author>         <time>         <version>
               Anzhiguo     2009/03/01         Ver1.0
  desc:         ORG
--------------------------------------------------------------------------------
*/
_ATTR_SYS_SET_SYSTEM_CODE_
UINT16 CheckhuanhangAtnumber(UINT16 *pstr)
{
    UINT16 *point,number;
    point=pstr;
    number=0;
    while (*point)
    {
        if ((*point)=='\n')
            break;
        point++;
        number++;
    }
    if (!(*point))
        return 0;
    return number;
}
_ATTR_SYS_SET_SYSTEM_CODE_
void SyssetScrollInit(LCD_RECT *pRect, uint16 ImageID, uint16 *pstr, uint16 Speed)
{
    PicturePartInfo     PicPartInfo;

    PicPartInfo.x       = pRect->x0;
    PicPartInfo.y       = pRect->y0;
    PicPartInfo.yoffset = 0;
    PicPartInfo.ysize   = CH_CHAR_XSIZE_12;

    PicPartInfo.pictureIDNump = ImageID;
    SetScrollStringInfo(pRect, PicPartInfo, pstr, Speed);
}
_ATTR_SYS_SET_SYSTEM_CODE_
void ScrollStringForInFo(UINT16 *pstr )
{
    UINT16    *pCurternStr;
    UINT16     TextMode;
    UINT16     Count;
    Count = SysTickCounter - ScrollString.SystickCounterBack;
    if (Count>ScrollString.ScrollSpeed)
    {
        Count=CheckhuanhangAtnumber(pstr+ScrollString.CharNumber);
        if (Count)
        {

            ScrollString.CharNumber+=Count;
            ScrollString.CharNumber++;
            pCurternStr =pstr+ScrollString.CharNumber;

        }
        else
        {
            ScrollString.ScrollNumber = 1;
            ScrollString.DiplayRect.x0 = ScrollString.StartX ;
            pCurternStr = pstr;
            ScrollString.CharNumber=0;
        }

#if (LCD_PIXEL == LCD_PIXEL_1)
        if (ScrollString.pictureID == NULL)
        {
            LCD_ClrRect(ScrollString.DiplayRect.x0,ScrollString.DiplayRect.y0,ScrollString.DiplayRect.x1,ScrollString.DiplayRect.y1);
        }
        else
#endif
        {
            DisplayPicture_part(ScrollString.pictureID,ScrollString.pictureInfo.x,ScrollString.pictureInfo.y,ScrollString.pictureInfo.yoffset,ScrollString.pictureInfo.ysize);
        }
        LCD_DispStringInRect(&(ScrollString.DiplayRect),&(ScrollString.DiplayRect), pCurternStr,LCD_TEXTALIGN_LEFT);
        ScrollString.ScrollNumber++;
        ScrollString.SystickCounterBack = SysTickCounter;
    }
}
/*********************************************************************/

/*
--------------------------------------------------------------------------------
  Function name : void SetMusicEqDisplay(void)
  Author        : Anzhiguo
  Description   : ¨®??¡ìEq2?¦Ì£¤??¨º?¡ä|¨¤¨ª3¨¬D¨°

  Input         :
  Return        :

  History:     <author>         <time>         <version>
               Anzhiguo     2009/03/01         Ver1.0
  desc:         ORG
--------------------------------------------------------------------------------
*/
_ATTR_SYS_SET_SYSTEM_BSS_ UINT16  fillDialogBuf[80];
_ATTR_SYS_SET_SYSTEM_CODE_
void ProductInfoWinDisplay(void)
{
    UINT16  color_tmp,  cpuFreqTemp;
    UINT16  firmwareYear, firmwareDate, firmwareMonth;
    UINT16  masterVersion, slaveVersion, smallVersion;
    UINT32  temp;
    UINT16  *pFillDialogBuf = fillDialogBuf;
    LCD_RECT  r;
    uint8   SdCardStatus;
    UINT16  TempColor, TempBkColor, TempCharSize,TempTxtMode;

    //chad.ma add for SN infomation showing.Pls using  with FactoryTools and SN tool.
    uint8  SN_buf[RKDEVICE_SN_LEN];
    uint16 SN_length;
    uint16 index;

    PICTURE_INFO_STRUCT pictureInfoTemp;

    TempColor    = LCD_GetColor();
    TempBkColor  = LCD_GetBkColor();
    TempTxtMode  = LCD_SetTextMode(LCD_DRAWMODE_TRANS);
    TempCharSize = LCD_SetCharSize(FONT_12x12);
    LCD_SetColor(COLOR_WHITE);
    LCD_SetBkColor(COLOR_BLACK);

    if (GetMsg(MSG_PRODUCTINFO)||(CheckMsg(MSG_NEED_PAINT_ALL)))
    {
        LCD_ClrSrc();

        SetGetFirmwareVersion(&firmwareYear,&firmwareDate,&masterVersion,&slaveVersion,&smallVersion);

        fillDialogBuf[0] = 'V';
        fillDialogBuf[1] = 'e';
        fillDialogBuf[2] = 'r';
        fillDialogBuf[3] = ':';
        fillDialogBuf[4] = ' ';
        //fillDialogBuf[5] = (uint8)((masterVersion >> 4) & 0x0f) + '0';
        //fillDialogBuf[6] = (uint8)((masterVersion >> 0) & 0x0f) + '0';
        //fillDialogBuf[7] = '.';
        //fillDialogBuf[8] = (uint8)((slaveVersion >> 4) & 0x0f) + '0';
        //fillDialogBuf[9] = (uint8)((slaveVersion >> 0) & 0x0f) + '0';
        //fillDialogBuf[10] = '.';

        //fillDialogBuf[11] = (uint8)((smallVersion >> 12) & 0x0f) + '0';
        //fillDialogBuf[12] = (uint8)((smallVersion >>  8) & 0x0f) + '0';
        //fillDialogBuf[13] = (uint8)((smallVersion >>  4) & 0x0f) + '0';
        //fillDialogBuf[14] = (uint8)((smallVersion >>  0) & 0x0f) + '0';
        fillDialogBuf[5] = (uint8)((masterVersion >> 4) & 0x0f) + '0';
        fillDialogBuf[6] = (uint8)((masterVersion >> 0) & 0x0f) + '0';
        fillDialogBuf[7] = '.';
        fillDialogBuf[8] = (uint8)((slaveVersion >> 4) & 0x0f) + '0';
        fillDialogBuf[9] = (uint8)((slaveVersion >> 0) & 0x0f) + '0';
        fillDialogBuf[10] = '.';
        fillDialogBuf[11] = ((smallVersion >> 12) & 0x0f) + '0';
        fillDialogBuf[12] = ((smallVersion >> 8)  & 0x0f) + '0';
        fillDialogBuf[13] = ((smallVersion >> 4)  & 0x0f) + '0';
        fillDialogBuf[14] = ((smallVersion >> 0)  & 0x0f) + '0';
        fillDialogBuf[15] = '\n';

        fillDialogBuf[16] = 'D';
        fillDialogBuf[17] = 'a';
        fillDialogBuf[18] = 't';
        fillDialogBuf[19] = 'e';
        fillDialogBuf[20] = ':';

        fillDialogBuf[21] = (uint8)((firmwareYear >> 12) & 0x0f) + '0';
        fillDialogBuf[22] = (uint8)((firmwareYear >>  8) & 0x0f) + '0';
        fillDialogBuf[23] = (uint8)((firmwareYear >>  4) & 0x0f) + '0';
        fillDialogBuf[24] = (uint8)((firmwareYear >>  0) & 0x0f) + '0';

        fillDialogBuf[25] = '-';
        fillDialogBuf[26] = (uint8)((firmwareDate >> 12) & 0x0f) + '0';
        fillDialogBuf[27] = (uint8)((firmwareDate >>  8) & 0x0f) + '0';
        fillDialogBuf[28] = '-';
        fillDialogBuf[29] = (uint8)((firmwareDate >> 4) & 0x0f) + '0';
        fillDialogBuf[30] = (uint8)((firmwareDate >> 0) & 0x0f) + '0';
        fillDialogBuf[31] = '\n';

        fillDialogBuf[32] = 'C';
        fillDialogBuf[33] = ':';

        temp = sysTotalMemeryFlash0 - sysFreeMemeryFlash0;
        ConvertMemMB(&fillDialogBuf[34], &temp);

        fillDialogBuf[39] = '/';
        ConvertMemMB(&fillDialogBuf[40], &sysTotalMemeryFlash0);

        fillDialogBuf[45] = 'M';
        fillDialogBuf[46] = 'B';

        fillDialogBuf[47] = 0;

//        r.x0 = pictureInfoTemp.x+4 ;
//        r.x1 = pictureInfoTemp.x + pictureInfoTemp.xSize-4 ;
//
//        r.y0 = pictureInfoTemp.y + 4;
//        r.y1 = pictureInfoTemp.y + pictureInfoTemp.ySize;


        //<------add by chad.ma 20151127 begin
#ifdef _EMMC_
        SN_length = EmmcGetProductSn((uint8*)SN_buf);
        if(SN_length != 0)
        {
            fillDialogBuf[47] = '\n';
            //dumpMemoryCharA(SN_buf,SN_length,0);
            printf("\n SN length = %d \n",SN_length);

            fillDialogBuf[48] = 'S';
            fillDialogBuf[49] = 'N';
            fillDialogBuf[50] = ':';

            for(index = 0; index < SN_length;index++)
            {
                if(index + 51 > 80) //filldialogBuf have 80 elements
                    break;

                fillDialogBuf[51 + index] = SN_buf[index];
            }

            if(SN_length + 51 > 80)
                fillDialogBuf[79]= 0;

            fillDialogBuf[51 + SN_length] = 0;
        }
#endif
        //------>add by chad.ma 20151127 end


        r.x0=0;
        r.x1=127;
        r.y0=0;
        r.y1=63;
        if (LCD_GetStringSize(fillDialogBuf) >((r.x1-r.x0)*(r.y1-r.y0)/12))
        {
            SyssetScrollInit(&r, NULL, fillDialogBuf, 120);
            SendMsg(MSG_SYS_SET_INFO_SCROLL);
        }
        LCD_DispStringInRect(&r,&r,(UINT16*)fillDialogBuf, LCD_TEXTALIGN_LEFT);

    }

    if (CheckMsg(MSG_SYS_SET_INFO_SCROLL))
    {
        ScrollStringForInFo(fillDialogBuf);
    }

    LCD_SetTextMode(TempTxtMode);
    LCD_SetBkColor(TempBkColor);
    LCD_SetColor(TempColor);
    LCD_SetCharSize(TempCharSize);
}
/*
********************************************************************************
*
*                         End of SystemSet.c
*
********************************************************************************
*/
#endif

