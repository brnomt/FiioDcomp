/*
********************************************************************************************
*
*        Copyright (c):  Fuzhou Rockchip Electronics Co., Ltd
*                             All rights reserved.
*
* FileName: Driver\WatchDog\WatchDogDevice.c
* Owner: wrm
* Date: 2015.5.19
* Time: 10:15:57
* Version: 1.0
* Desc:
* History:
*    <author>    <date>       <time>     <version>     <Desc>
*    wrm     2015.5.19     10:15:57   1.0
********************************************************************************************
*/


#include "BspConfig.h"
#ifdef __DRIVER_WATCHDOG_WATCHDOGDEVICE_C__

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   #include define
*
*---------------------------------------------------------------------------------------------------------------------
*/
#include "RKOS.h"
#include "BSP.h"
#include "DeviceInclude.h"

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   #define / #typedef define
*
*---------------------------------------------------------------------------------------------------------------------
*/
#define WDT_DEV_NUM 2


#define WDT_RST_PLUSE_LENGT_OFFSET   2
#define WDT_RESP_MODE_OFFSET         1

typedef __packed struct _WATCHDOG_REG
{
    UINT32 WDT_CR;
    UINT32 WDT_TORR; /*This field is used to select the timeout period from
                       which the watchdog counter restarts. A change of the
                        timeout period takes effect only after the next
                        counter restart (kick).
                        The range of values available for a 32-bit watchdog*/
    UINT32 WDT_CCVR; /*Current counter value
                        This register, when read, is the current value of the
                        internal counter. This value is read coherently when
                        ever it is read*/
    UINT32 WDT_CRR;  /*This register is used to restart the WDT counter. As a
                        safety feature to prevent accidental restarts, the
                        value 0x76 must be written. A restart also clears the
                        WDT interrupt. Reading this register returns zero.*/

    UINT32 WDT_STAT; /*This register shows the interrupt status of the WDT.
                        1’b1: Interrupt is active regardless of polarity.
                        1’b0: Interrupt is inactive.*/
    UINT32 WDT_EOI;

}WDTReg_t, *pWDTReg_t;

#define Wdt  ((WDTReg_t *) WDT_BASE)

typedef  struct _WDT_DEVICE_CLASS
{
    DEVICE_CLASS stWDTDevice;
    pSemaphore osWDTReadReqSem;
    pSemaphore osWDTReadSem;
    pSemaphore osWDTWriteReqSem;
    pSemaphore osWDTWriteSem;
    pSemaphore osWDTOperReqSem;
    pSemaphore osWDTOperSem;

}WDT_DEVICE_CLASS;

typedef  struct _WDT_DEV_ARG
{
    WDT_DEVICE_CLASS wdtdev;
       uint8 DevID;
       uint8 Channel;
}WDT_DEV_ARG;

#define COMMON

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local variable define
*
*---------------------------------------------------------------------------------------------------------------------
*/
static WDT_DEVICE_CLASS * gpstWDTDevISR[WDT_DEV_NUM] = {(WDT_DEVICE_CLASS *)NULL,(WDT_DEVICE_CLASS *)NULL};

typedef enum WdtRespMode
{
    RESP_MODE_RESET,/*Generate a system reset */

    RESP_MODE_INT_RESET,/*First generate an interrupt and if it is not
                        cleared by the time a second timeout occurs then
                       generate a system reset*/

}WdtRespMode_t;


typedef enum WdtRstPluseLenth
{
/*This is used to select the number of pclk cycles
for which the system reset stays asserted.*/
    PCLK_CYCLES_2,
    PCLK_CYCLES_4,
    PCLK_CYCLES_8,
    PCLK_CYCLES_16,
    PCLK_CYCLES_32,
    PCLK_CYCLES_64,
    PCLK_CYCLES_128,
    PCLK_CYCLES_256,

}WdtRstPluseLenth_t;

typedef enum WdtTimeoutPeriod
{
/*This field is used to select the timeout period from
which the watchdog counter restarts. A change of the
timeout period takes effect only after the next
counter restart (kick).
The range of values available for a 32-bit watchdog*/

   PERIOD_RANGE_0X0000FFFF,
   PERIOD_RANGE_0X0001FFFF,
   PERIOD_RANGE_0X0003FFFF,
   PERIOD_RANGE_0X0007FFFF,

   PERIOD_RANGE_0X000FFFFF,
   PERIOD_RANGE_0X001FFFFF,
   PERIOD_RANGE_0X003FFFFF,
   PERIOD_RANGE_0X007FFFFF,

   PERIOD_RANGE_0X00FFFFFF,
   PERIOD_RANGE_0X01FFFFFF,
   PERIOD_RANGE_0X03FFFFFF,
   PERIOD_RANGE_0X07FFFFFF,

   PERIOD_RANGE_0X0FFFFFFF,
   PERIOD_RANGE_0X1FFFFFFF,
   PERIOD_RANGE_0X3FFFFFFF,
   PERIOD_RANGE_0X7FFFFFFF,


}WdtTimeoutPeriod_t;

int IsWatchDogTestClearInt = 0;

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
rk_err_t WTDDevShellHelp(HDC dev,  uint8 * pstr);
rk_err_t WDTDevShellTest(HDC dev, uint8 * pstr);
rk_err_t WDTDevShellDel(HDC dev, uint8 * pstr);
rk_err_t WDTDevShellMc(HDC dev, uint8 * pstr);
rk_err_t WDTDevShellPcb(HDC dev, uint8 * pstr);
rk_err_t WDTDevDeInit(WDT_DEVICE_CLASS * pstWDTDev);
rk_err_t WDTDevInit(WDT_DEVICE_CLASS * pstWDTDev);
rk_err_t WDTDevResume(HDC dev);
rk_err_t WDTDevSuspend(HDC dev);

void WDTDevIntIsr(uint32 DevID);



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   API(common) define
*
*---------------------------------------------------------------------------------------------------------------------
*/
/*******************************************************************************
** Name: WDTDev_Write
** Input:HDC dev
** Return: rk_err_t
** Owner:wrm
** Date: 2015.5.19
** Time: 10:16:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_COMMON_
COMMON API rk_err_t WDTDev_Write(HDC dev)
{
    //WDTDev Write...
    WDT_DEVICE_CLASS * pstWDTDev =  (WDT_DEVICE_CLASS *)dev;
    if(pstWDTDev == NULL)
    {
        return RK_ERROR;
    }

}
/*******************************************************************************
** Name: WDTDev_Read
** Input:HDC dev
** Return: rk_err_t
** Owner:wrm
** Date: 2015.5.19
** Time: 10:16:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_COMMON_
COMMON API rk_err_t WDTDev_Read(HDC dev)
{
    //WDTDev Read...
    WDT_DEVICE_CLASS * pstWDTDev =  (WDT_DEVICE_CLASS *)dev;
    if(pstWDTDev == NULL)
    {
        return RK_ERROR;
    }

}



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local function(common) define
*
*---------------------------------------------------------------------------------------------------------------------
*/
/*******************************************************************************
** Name: WatchDogStart
** Input:void
** Return: void
** Owner:wrm
** Date: 2015.5.19
** Time: 10:50:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_COMMON_
COMMON FUN rk_err_t WatchDogStart(void)
{
    int backup = Wdt->WDT_CR;
    Wdt->WDT_CR = 1 |backup;
    return OK;
}

/*******************************************************************************
** Name: WatchDogClearIntFlag
** Input:void
** Return: void
** Owner:wrm
** Date: 2015.5.19
** Time: 10:50:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_COMMON_
COMMON FUN rk_err_t WatchDogClearIntFlag(void)
{
    uint32 eoi;
    eoi = Wdt->WDT_EOI;
    return eoi;
}
/*******************************************************************************
** Name: WatchDogGetCurrentValue
** Input:void
** Return: void
** Owner:wrm
** Date: 2015.5.19
** Time: 10:50:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_COMMON_
COMMON FUN rk_size_t WatchDogGetCurrentValue(void)
{
    return Wdt->WDT_CCVR;
}
/*******************************************************************************
** Name: WatchDogSetPeriod
** Input:WdtTimeoutPeriod_t
** Return: OK
** Owner:wrm
** Date: 2015.5.19
** Time: 10:50:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_COMMON_
COMMON FUN rk_err_t WatchDogSetPeriod(WdtTimeoutPeriod_t period)
{
    Wdt->WDT_TORR = period;
    return OK;
}
/*******************************************************************************
** Name: WatchDogReload
** Input:void
** Return: void
** Owner:wrm
** Date: 2015.5.19
** Time: 10:50:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_COMMON_
COMMON FUN rk_err_t WatchDogReload(void)
{
    Wdt->WDT_CRR = 0x76;
    return OK;
}
/*******************************************************************************
** Name: WatchDogGetStat
** Input:void
** Return: void
** Owner:wrm
** Date: 2015.5.19
** Time: 10:50:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_COMMON_
COMMON FUN rk_size_t WatchDogGetStat(void)
{
    return Wdt->WDT_STAT;
}

/*******************************************************************************
** Name: WatchDogInit
** Input:WdtRespMode_t,WdtRstPluseLenth_t,WdtTimeoutPeriod_t
** Return: OK
** Owner:wrm
** Date: 2015.5.19
** Time: 10:50:13
*******************************************************************************/
COMMON FUN rk_err_t WatchDogInit(WdtRespMode_t mode , WdtRstPluseLenth_t RstPluse, WdtTimeoutPeriod_t period)
{
    ScuClockGateCtr(PCLK_WDT_GATE, TRUE);
    //rk_printf("ccvr = %d\n",WatchDogGetCurrentValue());
    Wdt->WDT_CR = (mode << WDT_RESP_MODE_OFFSET) | (RstPluse << WDT_RST_PLUSE_LENGT_OFFSET);

    WatchDogSetPeriod(period);
    WatchDogReload();
    //printf("CCRV = %d\n",WatchDogGetCurrentValue());
    //WatchDogStart();

    return OK;
}
/*******************************************************************************
** Name: WDTDevIntIsr1
** Input:void
** Return: void
** Owner:wrm
** Date: 2015.5.19
** Time: 10:16:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_COMMON_
COMMON FUN void WDTDevIntIsr1(void)
{
    //Call total int service...
    WDTDevIntIsr(1);

}
/*******************************************************************************
** Name: WDTDevIntIsr0
** Input:void
** Return: void
** Owner:wrm
** Date: 2015.5.19
** Time: 10:16:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_COMMON_
COMMON FUN void WDTDevIntIsr0(void)
{
    //Call total int service...
    //WDTDevIntIsr(0);
    if(IsWatchDogTestClearInt)
    {
        WatchDogClearIntFlag();
    }
}
/*******************************************************************************
** Name: WDTDevIntIsr
** Input:uint32 DevID
** Return: void
** Owner:wrm
** Date: 2015.5.19
** Time: 10:16:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_COMMON_
COMMON FUN void WDTDevIntIsr(uint32 DevID)
{
    uint32 WDTDevIntType;


    //Get WDTDev Int type...
    //WDTDevIntType = GetIntType();
    if (gpstWDTDevISR[DevID] != NULL)
    {
        //if (WDTDevIntType & INT_TYPE_MAP)
        {
            //write serice code...
        }

        //wirte other int service...
    }

}
/*******************************************************************************
** Name: WDTDevResume
** Input:HDC dev
** Return: rk_err_t
** Owner:wrm
** Date: 2015.5.19
** Time: 10:16:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_COMMON_
COMMON FUN rk_err_t WDTDevResume(HDC dev)
{
    //WDTDev Resume...
    WDT_DEVICE_CLASS * pstWDTDev =  (WDT_DEVICE_CLASS *)dev;
    if(pstWDTDev == NULL)
    {
        return RK_ERROR;
    }

}
/*******************************************************************************
** Name: WDTDevSuspend
** Input:HDC dev
** Return: rk_err_t
** Owner:wrm
** Date: 2015.5.19
** Time: 10:16:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_COMMON_
COMMON FUN rk_err_t WDTDevSuspend(HDC dev)
{
    //WDTDev Suspend...
    WDT_DEVICE_CLASS * pstWDTDev =  (WDT_DEVICE_CLASS *)dev;
    if(pstWDTDev == NULL)
    {
        return RK_ERROR;
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
** Name: WDTDev_Delete
** Input:uint32 DevID
** Return: rk_err_t
** Owner:wrm
** Date: 2015.5.19
** Time: 10:16:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_INIT_
INIT API rk_err_t WDTDev_Delete(uint32 DevID, void * arg)
{
    //Check WDTDev is not exist...
    if(gpstWDTDevISR[DevID] == NULL)
    {
        return RK_ERROR;
    }

    //WDTDev deinit...
    WDTDevDeInit(gpstWDTDevISR[DevID]);

    //Free WDTDev memory...
    rkos_semaphore_delete(gpstWDTDevISR[DevID]->osWDTOperReqSem);
    rkos_semaphore_delete(gpstWDTDevISR[DevID]->osWDTOperSem);
    rkos_semaphore_delete(gpstWDTDevISR[DevID]->osWDTReadReqSem);
    rkos_semaphore_delete(gpstWDTDevISR[DevID]->osWDTReadSem);
    rkos_semaphore_delete(gpstWDTDevISR[DevID]->osWDTWriteReqSem);
    rkos_semaphore_delete(gpstWDTDevISR[DevID]->osWDTWriteSem);
    rkos_memory_free(gpstWDTDevISR[DevID]);

    //Delete WDTDev...
    gpstWDTDevISR[DevID] = NULL;

    //Delete WDTDev Read and Write Module...
#ifdef __OS_FWANALYSIS_FWANALYSIS_C__
    //FW_RemoveSegment(SEGMENT_ID_WDT_DEV);
#endif

    return RK_SUCCESS;

}
/*******************************************************************************
** Name: WDTDev_Create
** Input:uint32 DevID, void * arg
** Return: HDC
** Owner:wrm
** Date: 2015.5.19
** Time: 10:16:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_INIT_
INIT API HDC WDTDev_Create(uint32 DevID, void * arg)
{
    WDT_DEV_ARG * pstWDTDevArg;
    DEVICE_CLASS* pstDev;
    WDT_DEVICE_CLASS * pstWDTDev;
    uint32 channel = 0;

    if(arg == NULL)
    {
        return (HDC)RK_PARA_ERR;
    }

    // Create handler...
    pstWDTDevArg = (WDT_DEV_ARG *)arg;
    pstWDTDev =  rkos_memory_malloc(sizeof(WDT_DEVICE_CLASS));
    memset(pstWDTDev, 0, sizeof(WDT_DEVICE_CLASS));
    if (pstWDTDev == NULL)
    {
        return NULL;
    }

    //init handler...
    pstWDTDev->osWDTOperReqSem  = rkos_semaphore_create(1,1);
    pstWDTDev->osWDTOperSem  = rkos_semaphore_create(1,0);

    pstWDTDev->osWDTReadReqSem  = rkos_semaphore_create(1,1);
    pstWDTDev->osWDTReadSem  = rkos_semaphore_create(1,0);

    pstWDTDev->osWDTWriteReqSem  = rkos_semaphore_create(1,1);
    pstWDTDev->osWDTWriteSem  = rkos_semaphore_create(1,0);
    if(((pstWDTDev->osWDTOperReqSem) == 0)
        || ((pstWDTDev->osWDTOperSem) == 0)
        || ((pstWDTDev->osWDTReadReqSem) == 0)
        || ((pstWDTDev->osWDTReadSem) == 0)
        || ((pstWDTDev->osWDTWriteReqSem) == 0)
        || ((pstWDTDev->osWDTWriteSem) == 0))
    {
        rkos_semaphore_delete(pstWDTDev->osWDTOperReqSem);
        rkos_semaphore_delete(pstWDTDev->osWDTOperSem);
        rkos_semaphore_delete(pstWDTDev->osWDTReadReqSem);
        rkos_semaphore_delete(pstWDTDev->osWDTReadSem);
        rkos_semaphore_delete(pstWDTDev->osWDTWriteReqSem);
        rkos_semaphore_delete(pstWDTDev->osWDTWriteSem);
        rkos_memory_free(pstWDTDev);
        return (HDC) RK_ERROR;
    }
    pstDev = (DEVICE_CLASS *)pstWDTDev;
    pstDev->suspend = WDTDevSuspend;
    pstDev->resume  = WDTDevResume;

    //init arg...
    //pstWDTDev->usbmode = pstWDTDevArg->usbmode;

#ifdef __OS_FWANALYSIS_FWANALYSIS_C__
    //FW_LoadSegment(SEGMENT_ID_WDT_DEV, SEGMENT_OVERLAY_CODE);
#endif
    //device init...
    gpstWDTDevISR[DevID] = NULL;
    if(WDTDevInit(pstWDTDev) != RK_SUCCESS)
    {
        rkos_semaphore_delete(pstWDTDev->osWDTOperReqSem);
        rkos_semaphore_delete(pstWDTDev->osWDTOperSem);
        rkos_semaphore_delete(pstWDTDev->osWDTReadReqSem);
        rkos_semaphore_delete(pstWDTDev->osWDTReadSem);
        rkos_semaphore_delete(pstWDTDev->osWDTWriteReqSem);
        rkos_semaphore_delete(pstWDTDev->osWDTWriteSem);
        rkos_memory_free(pstWDTDev);
        return (HDC) RK_ERROR;
    }
    gpstWDTDevISR[DevID] = pstWDTDev;
    WdtDevHwInit (DevID,channel);
    return (HDC)pstDev;

}



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local function(init) define
*
*---------------------------------------------------------------------------------------------------------------------
*/
/*******************************************************************************
** Name: WDTDevDeInit
** Input:WDT_DEVICE_CLASS * pstWDTDev
** Return: rk_err_t
** Owner:wrm
** Date: 2015.5.19
** Time: 10:16:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_INIT_
INIT FUN rk_err_t WDTDevDeInit(WDT_DEVICE_CLASS * pstWDTDev)
{
    //If ip device first step unregister int
    //IntDisable(INT_ID17_UART);
    //IntPendingClear(INT_ID17_UART);
    //IntUnregister(INT_ID17_UART);

    //If ip device second step close clk
    //ScuClockGateCtr(CLOCK_GATE_UART,0);
    return RK_ERROR;

}
/*******************************************************************************
** Name: WDTDevInit
** Input:WDT_DEVICE_CLASS * pstWDTDev
** Return: rk_err_t
** Owner:wrm
** Date: 2015.5.19
** Time: 10:16:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_INIT_
INIT FUN rk_err_t WDTDevInit(WDT_DEVICE_CLASS * pstWDTDev)
{
    //If ip device first step open ip clk...
    //ScuClockGateCtr(CLOCK_GATE_UART, 1);
    //SetUartFreq(24);

    //If ip device second step rst ip...
    //ScuSoftResetCtr(RST_UART, 1);
    //DelayMs(1);
    //ScuSoftResetCtr(RST_UART, 0);

    //If ip device three step call ip bsp function init ip...
    //UARTInit(pstUartDev->dwBitRate,pstUartDev->dwBitWidth,UART_ONE_STOPBIT,UART_PARITY_DISABLE);

    //If ip device four step register intreput service...
    //IntRegister(INT_ID17_UART ,UartIntIsr0);
    //IntPendingClear(INT_ID17_UART);
    //IntEnable(INT_ID17_UART);
    //some ip device,such as uart ip device, only a read fifo and a write fifo,
    //we can use fifo as buffer for save some data when shut off Ip int
    return RK_SUCCESS;

}




#ifdef _WDT_DEV_SHELL_
_DRIVER_WATCHDOG_WATCHDOGDEVICE_SHELL_DATA_
static SHELL_CMD ShellWDTName[] =
{
    "pcb",NULL,"NULL","NULL",
    "mc",NULL,"NULL","NULL",
    "del",NULL,"NULL","NULL",
    "test",NULL,"NULL","NULL",
    "help",NULL,"NULL","NULL",
    "\b",NULL,"NULL","NULL",
};

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   API(shell) define
*
*---------------------------------------------------------------------------------------------------------------------
*/
/*******************************************************************************
** Name: WDTDev_Shell
** Input:HDC dev, uint8 * pstr
** Return: rk_err_t
** Owner:wrm
** Date: 2015.5.19
** Time: 10:16:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_SHELL_
SHELL API rk_err_t WDTDev_Shell(HDC dev, uint8 * pstr)
{
    uint32 i = 0;
    uint8  *pItem;
    uint16 StrCnt = 0;
    rk_err_t   ret;
    uint8 Space;
    StrCnt = ShellItemExtract(pstr, &pItem, &Space);
    if (StrCnt == 0)
    {
        return RK_ERROR;
    }

    ret = ShellCheckCmd(ShellWDTName, pItem, StrCnt);
    if(ret < 0)
    {
        return RK_ERROR;
    }

    i = (uint32)ret;

    pItem += StrCnt;
    pItem++;
    switch (i)
    {
        case 0x00:
            ret = WDTDevShellPcb(dev,pItem);
            break;

        case 0x01:
            ret = WDTDevShellMc(dev,pItem);
            break;

        case 0x02:
            ret = WDTDevShellDel(dev,pItem);
            break;

        case 0x03:
            ret = WDTDevShellTest(dev,pItem);
            break;

        case 0x04:
            ret = WTDDevShellHelp(dev,pItem);
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
** Name: WDTDevShellHelp
** Input:HDC dev, uint8 * pstr
** Return: rk_err_t
** Owner:wrm
** Date: 2015.5.19
** Time: 10:24:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_SHELL_
SHELL FUN rk_err_t WTDDevShellHelp(HDC dev,  uint8 * pstr)
{
    pstr--;

    if( StrLenA((uint8 *) pstr) != 0)
        return RK_ERROR;

    rk_print_string("             WatchDog命令集提供了一系列的命令对Wtd进行操作\r\n");
    rk_print_string("WatchDog包含的子命令如下:           \r\n");
    rk_print_string("help      显示help信息           \r\n");
    rk_print_string("mc        打开WatchDog              \r\n");
    rk_print_string("del       删除WatchDog              \r\n");
    rk_print_string("test      测试WatchDog命令          \r\n");
    rk_print_string("pcb       显示pcb信息  \r\n");

    return RK_SUCCESS;
}


/*******************************************************************************
** Name: WDTDevShellTest
** Input:HDC dev, uint8 * pstr
** Return: rk_err_t
** Owner:wrm
** Date: 2015.5.19
** Time: 10:16:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_SHELL_
SHELL FUN rk_err_t WDTDevShellTest(HDC dev, uint8 * pstr)
{
    HDC hWDTDev;
    uint32 DevID;

    //Get WDTDev ID...
    if(StrCmpA(pstr, "0", 1) == 0)
    {
        DevID = 0;
    }
    else if(StrCmpA(pstr, "1", 1) == 0)
    {
        DevID = 1;
    }
    else
    {
        DevID = 0;
    }

    //Open WDTDev...
    hWDTDev = RKDev_Open(DEV_CLASS_WDT, 0, NOT_CARE);
    if((hWDTDev == NULL) || (hWDTDev == (HDC)RK_ERROR) || (hWDTDev == (HDC)RK_PARA_ERR))
    {
        rk_print_string("WDTDev open failure");
         return RK_SUCCESS;
    }

    //do test....
    rk_printf ("Test WatchDog Device\n");
    IsWatchDogTestClearInt= 0;

    WatchDogInit(RESP_MODE_INT_RESET, PCLK_CYCLES_128, PERIOD_RANGE_0X07FFFFFF);
    WatchDogStart();

    //close WDTDev...
    RKDev_Close(hWDTDev);
    return RK_SUCCESS;

}
/*******************************************************************************
** Name: WDTDevShellDel
** Input:HDC dev, uint8 * pstr
** Return: rk_err_t
** Owner:wrm
** Date: 2015.5.19
** Time: 10:16:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_SHELL_
SHELL FUN rk_err_t WDTDevShellDel(HDC dev, uint8 * pstr)
{
    uint32 DevID;

    //Get WDTDev ID...
    if(StrCmpA(pstr, "0", 1) == 0)
    {
        DevID = 0;
    }
    else if(StrCmpA(pstr, "1", 1) == 0)
    {
        DevID = 1;
    }
    else
    {
        DevID = 0;
    }
    if(RKDev_Delete(DEV_CLASS_WDT, DevID, NULL) != RK_SUCCESS)
    {
        rk_print_string("WDTDev delete failure");
    }
    return RK_SUCCESS;

}
/*******************************************************************************
** Name: WDTDevShellMc
** Input:HDC dev, uint8 * pstr
** Return: rk_err_t
** Owner:wrm
** Date: 2015.5.19
** Time: 10:16:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_SHELL_
SHELL FUN rk_err_t WDTDevShellMc(HDC dev, uint8 * pstr)
{
    WDT_DEV_ARG stWDTDevArg;
    rk_err_t ret;
    uint32 DevID;
    DevID = 0;

    if(StrCmpA(pstr, "0", 1) == 0)
    {
        DevID = 0;
    }
    else if(StrCmpA(pstr, "1", 1) == 0)
    {
        DevID = 1;
    }
    else
    {
        DevID = 0;
    }

    //Init WDTDev arg...
    //stWDTDevArg.usbmode = USBOTG_MODE_DEVICE;
    rk_printf ("Entry WatchDogDev Create\n");
    stWDTDevArg.Channel = 0;
    stWDTDevArg.DevID = 0;

    //Create WDTDev...
    ret = RKDev_Create(DEV_CLASS_WDT, DevID, &stWDTDevArg);
    if(ret != RK_SUCCESS)
    {
        rk_print_string("WDTDev create failure");
    }
    return RK_SUCCESS;

}
/*******************************************************************************
** Name: WDTDevShellPcb
** Input:HDC dev, uint8 * pstr
** Return: rk_err_t
** Owner:wrm
** Date: 2015.5.19
** Time: 10:16:13
*******************************************************************************/
_DRIVER_WATCHDOG_WATCHDOGDEVICE_SHELL_
SHELL FUN rk_err_t WDTDevShellPcb(HDC dev, uint8 * pstr)
{
    HDC hWDTDev;
    uint32 DevID;

    //Get WDTDev ID...
    if(StrCmpA(pstr, "0", 1) == 0)
    {
        DevID = 0;
    }
    else if(StrCmpA(pstr, "1", 1) == 0)
    {
        DevID = 1;
    }
    else
    {
        DevID = 0;
    }

    //Display pcb...
    if(gpstWDTDevISR[DevID] != NULL)
    {
        rk_print_string("rn");
        rk_printf_no_time("WDTDev ID = %d Pcb list as follow:", DevID);
        rk_printf_no_time("    &stWDTDevice---0x%08x", &gpstWDTDevISR[DevID]->stWDTDevice);
        rk_printf_no_time("    osWDTOperReqSem---0x%08x", gpstWDTDevISR[DevID]->osWDTOperReqSem);
        rk_printf_no_time("    osWDTOperSem---0x%08x", gpstWDTDevISR[DevID]->osWDTOperSem);
        rk_printf_no_time("    osWDTReadReqSem---0x%08x", gpstWDTDevISR[DevID]->osWDTReadReqSem);
        rk_printf_no_time("    osWDTReadSem---0x%08x", gpstWDTDevISR[DevID]->osWDTReadSem);
        rk_printf_no_time("    osWDTWriteReqSem---0x%08x", gpstWDTDevISR[DevID]->osWDTWriteReqSem);
        rk_printf_no_time("    osWDTWriteSem---0x%08x", gpstWDTDevISR[DevID]->osWDTWriteSem);
        //rk_printf_no_time("    usbmode---0x%08x", gpstUsbOtgDevISR[DevID]->usbmode);
        //rk_printf_no_time("    usbspeed---0x%08x", gpstUsbOtgDevISR[DevID]->usbspeed);
    }
    else
    {
        rk_print_string("rn");
        rk_printf_no_time("WDTDev ID = %d not exit", DevID);
    }
    return RK_SUCCESS;

}
#endif
#endif
