/* Copyright (C) 2011 ROCK-CHIP FUZHOU. All Rights Reserved. */
/*
File: SD.c
Desc: 

Author: chenfen
Date: 12-01-10
Notes:

$Log: $
 *
 *
*/

/*-------------------------------- Includes ----------------------------------*/
#include "SDConfig.h"

#if (CONFIG_SD_SPEC ==1)

/*------------------------------------ Defines -------------------------------*/


/*----------------------------------- Typedefs -------------------------------*/



/*-------------------------- Forward Declarations ----------------------------*/


/* ------------------------------- Globals ---------------------------------- */

/*-------------------------------- Local Statics: ----------------------------*/

/*--------------------------- Local Function Prototypes ----------------------*/


/*------------------------ Function Implement --------------------------------*/

/****************************************************************/
//函数名:SD_DecodeCID
//描述:解析读到的CID寄存器，获取需要的信息
//参数说明:pCID           输入参数  指向存放CID信息的指针
//         pCardInfo      输入参数  指向存放卡信息的指针
//返回值:
//相关全局变量:
//注意:
/****************************************************************/
_ATTR_SD_INIT_CODE_
static void _SD_DecodeCID(uint32 *pCID, pSDM_CARD_INFO pCard)
{
    #if 0
    pCard->year   = (uint16)(2000 + ((pCID[0] >> 12) & 0xFF));   //[19:12]
    pCard->month  = (uint8)((pCID[0] >> 8) & 0xF);                //[11:8]
    pCard->psn    = ((pCID[1] & 0x00FFFFFF) << 8) | ((pCID[0] & 0xFF000000) >> 24);  //[55:24]
    pCard->prv    = (uint8)((pCID[1] >> 24) & 0xFF);              //[63:56]
    pCard->pnm[0] = (uint8)(pCID[3] & 0xFF);                      //[103:64]
    pCard->pnm[1] = (uint8)((pCID[2] >> 24) & 0xFF);
    pCard->pnm[2] = (uint8)((pCID[2] >> 16) & 0xFF);
    pCard->pnm[3] = (uint8)((pCID[2] >> 8) & 0xFF);
    pCard->pnm[4] = (uint8)(pCID[2] & 0xFF);
    pCard->pnm[5] = 0x0; //字符串结束符
    pCard->oid[0] = (uint8)((pCID[3] >> 16) & 0xFF);              //[119:104]
    pCard->oid[1] = (uint8)((pCID[3] >> 8) & 0xFF);
    pCard->oid[2] = 0x0; //字符串结束符
    pCard->mid    = (uint8)((pCID[3] >> 24) & 0xFF);              //[127:120]
    #endif
    return;
}

/****************************************************************/
//函数名:SD_DecodeCSD
//描述:解析读到的CSD寄存器，获取需要的信息
//参数说明:pCSD           输入参数  指向存放CID信息的指针
//         pCardInfo      输入参数  指向存放卡信息的指针
//返回值:
//相关全局变量:
//注意:
/****************************************************************/
_ATTR_SD_INIT_CODE_
static void _SD_DecodeCSD(uint32 *pCSD, pSDM_CARD_INFO pCard)
{
    uint32           tmp = 0;
    uint32           c_size = 0;
    uint32           c_size_mult = 0;
    uint32           read_bl_len = 0;
    /*uint32           taac = 0;
    uint32           nsac = 0;
    uint32           r2w_factor = 0;*/
    uint32           transfer_rate_unit[4] = {10, 100, 1000, 10000};
    uint32           time_value[16] = {10/*reserved*/, 10, 12, 13, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 70, 80};

    tmp = (pCSD[3] >> 30);
    if (tmp == 0)      //CSD version 1.0
    {
        c_size            = ((pCSD[2] & 0x3FF) << 2) | (pCSD[1] >> 30); //[73:62]
        c_size_mult       = (pCSD[1] >> 15) & 0x7;                      //[49:47]
        read_bl_len       = (pCSD[2] >> 16) & 0xF;                      //[83:80]
        pCard->capability = (((c_size + 1)*(0x1 << (c_size_mult + 2))*(0x1 << read_bl_len)) >> 9);
    }
    else if (tmp == 1) //CSD version 2.0
    {
        c_size            = (pCSD[1] >> 16) | ((pCSD[2] & 0x3F) << 16); //[69:48]
        pCard->capability = ((c_size + 1) << 10);
    }
    else
    {
        //reserved
    }
    
    pCard->TranSpeed = transfer_rate_unit[pCSD[3] & 0x3]*time_value[(pCSD[3] >> 3) & 0x7]; //[103:96]
    #if 0
    taac       = (pCSD[3] >> 16) & 0xFF;            //[119:112]
    nsac       = (pCSD[3] >> 8) & 0xFF;             //[111:104]
    r2w_factor = (0x1 << ((pCSD[0] >> 26) & 0x7)); //[28:26]

    pCard->dsr_imp    = (pCSD[2] >> 12) & 0x1;             //[76]
    pCard->ccc        = (uint16)((pCSD[2] >> 20) & 0xFFF); //[95:84]
    #endif
}



/****************************************************************/
//函数名:_SD_SwitchSpeedMode
//描述: 切换卡的速度模式
//参数说明:pCardInfo     输入参数  指向卡信息的指针 mode 速度模式
//返回值:
//相关全局变量:
//注意:
/****************************************************************/
_ATTR_SD_INIT_CODE_
static int32 _SD_SwitchBusWidth(pSDM_CARD_INFO pCard, HOST_BUS_WIDTH width)
{
    uint32           data[(64/(8*4))];    //不知道会不会太大，导致栈溢出
    uint32           status = 0;
    int32            ret = SDM_SUCCESS;

    ret = SDC_SendCmd(pCard->SDCPort, (SD_APP_CMD | SD_NODATA_OP | SD_RSP_R1 | WAIT_PREV), (pCard->rca << 16), &status);

    if (SDC_SUCCESS != ret)
    {
        return ret;
    }
    ret = SDC_SendCmd(pCard->SDCPort, (SDA_SET_BUS_WIDTH | SD_NODATA_OP | SD_RSP_R1 | WAIT_PREV), 2, &status);
    if (SDC_SUCCESS != ret)
    {
        return ret;
    }
    ret = SDC_SetBusWidth(pCard->SDCPort, width);
    if (SDC_SUCCESS != ret)
    {
        return ret;
    }

    //再读一下SCR，用于验证4bit数据线宽是否有问题，因为发现有的卡能支持4bit线宽，但是一旦切换到4bit线宽，就发生data start bit error
    ret = SDC_SendCmd(pCard->SDCPort, (SD_APP_CMD | SD_NODATA_OP | SD_RSP_R1 | WAIT_PREV), (pCard->rca << 16), &status);
    if (SDC_SUCCESS != ret)
    {
        return ret;
    }

    ret = SDC_Request(pCard->SDCPort, 
                     (SDA_SEND_SCR | SD_READ_OP | SD_RSP_R1 | WAIT_PREV), 
                     0, 
                     &status, 
                     (64 >> 3), 
                     (64 >> 3), 
                     data);
    if (SDC_SUCCESS == ret)
    {
        pCard->WorkMode |= SDM_WIDE_BUS_MODE;
    }
    else
    {
        ret = SDC_SendCmd(pCard->SDCPort, (SD_APP_CMD | SD_NODATA_OP | SD_RSP_R1 | WAIT_PREV), (pCard->rca << 16), &status);
        if (SDC_SUCCESS != ret)
        {
            return ret;
        }
        ret = SDC_SendCmd(pCard->SDCPort, (SDA_SET_BUS_WIDTH | SD_NODATA_OP | SD_RSP_R1 | WAIT_PREV), 0, &status);
        if (SDC_SUCCESS != ret)
        {
            return ret;
        }
        ret = SDC_SetBusWidth(pCard->SDCPort, BUS_WIDTH_1_BIT);
        if (SDC_SUCCESS != ret)
        {
            return ret;
        }
    }
    return ret;
}

/****************************************************************/
//函数名:_SD_SwitchSpeedMode
//描述: 切换卡的速度模式
//参数说明:pCardInfo     输入参数  指向卡信息的指针 mode 速度模式
//返回值:
//相关全局变量:
//注意:
/****************************************************************/
_ATTR_SD_INIT_CODE_
static int32 _SD_SwitchSpeedMode(pSDM_CARD_INFO pCard, SD_SPEED_MODE mode)
{
    uint32           data[(512/(8*4))];    //不知道会不会太大，导致栈溢出
    uint8           *pDataBuf = (uint8 *)data;
    uint8            tmp = 0;
    uint32           status = 0;
    int32            ret = SDM_SUCCESS;
    uint32           i = 0;

    memset(data, 0x00, (512 >> 3));
    ret = SDC_Request(pCard->SDCPort, \
                     (SD2_SWITCH_FUNC | SD_READ_OP | SD_RSP_R1 | WAIT_PREV), \
                     ((0x0U << 31) | (0xFFFFF0) | mode/*(0x1)*/), \
                     &status, \
                     (512 >> 3), \
                     (512 >> 3), \
                     data);
    if (SDC_SUCCESS != ret)
    {
        return ret;
    }

    //SD2_SWITCH_FUNC命令收到的数据也是Data Packet Format为Wide Width Data，数据也必须颠倒过来
    for (i=0; i<(512 >> 4); i++)
    {
        tmp         = pDataBuf[i];
        pDataBuf[i] = pDataBuf[(512 >> 3) - 1 - i];
        pDataBuf[(512 >> 3) - 1 - i] = tmp;
    }

    if ((pDataBuf[50] & (0x1<<mode)/*0x2*/)&& ((pDataBuf[47] & 0xF) == mode/*0x1*/))//bit 401:High Speed support//bit 379-376:whether function can be switched
    {
        if ((pDataBuf[46] == 0x0)                            //bit 375-368:indicate bit 273 defined
                || ((pDataBuf[46] == 0x1) && (!(pDataBuf[35] & (0x1<<mode)/*0x2*/))))//bit 273 defined:check whether High Speed ready
        {
            memset(data, 0x00, (512 >> 3));
            //(0xFFFFF0):specify 0xF will keep the current function for the function group
            ret = SDC_Request(pCard->SDCPort, \
                             (SD2_SWITCH_FUNC | SD_READ_OP | SD_RSP_R1 | WAIT_PREV), \
                             ((0x1U << 31) | (0xFFFFF0) | mode/*(0x1)*/), \
                             &status, \
                             (512 >> 3), \
                             (512 >> 3), \
                             data);
            if (SDC_SUCCESS != ret)
            {
                return ret;
            }

            for (i=0; i<(512 >> 4); i++)
            {
                tmp         = pDataBuf[i];
                pDataBuf[i] = pDataBuf[(512 >> 3) - 1 - i];
                pDataBuf[(512 >> 3) - 1 - i] = tmp;
            }

            if (((pDataBuf[47] & 0xF) == mode/*0x1*/)  //bit 379-376:whether function switched successful
                    && ((pDataBuf[47] & 0xF0) != 0xF0)
                    && ((pDataBuf[48] & 0xF) != 0xF)
                    && ((pDataBuf[48] & 0xF0) != 0xF0)
                    && ((pDataBuf[49] & 0xF) != 0xF)
                    && ((pDataBuf[49] & 0xF0) != 0xF0))
            {
                ret = SDC_UpdateFreq(pCard->SDCPort, SDHC_FPP_FREQ);
                if (SDC_SUCCESS != ret)
                {
                    return ret;
                }
                pCard->TranSpeed = SDHC_FPP_FREQ;
                pCard->WorkMode |= SDM_HIGH_SPEED_MODE;
            }
        }
    }
    return ret;
}


/****************************************************************/
//函数名:SD_SwitchFunction
//描述:读取SCR寄存器，根据卡是否支持宽数据线，改变数据线的宽度
//     以及根据卡是否支持高速模式，切换到高速模式
//参数说明:pCardInfo     输入参数  指向卡信息的指针
//返回值:
//相关全局变量:
//注意:
/****************************************************************/
_ATTR_SD_INIT_CODE_
static void _SD_SwitchFunction(pSDM_CARD_INFO pCard)
{
    HOST_BUS_WIDTH   wide = BUS_WIDTH_INVALID;
    uint32           data[(64/(8*4))];    //不知道会不会太大，导致栈溢出
    uint8           *pDataBuf = (uint8 *)data;
    uint8            tmp = 0;
    uint32           status = 0;
    int32            ret = SDM_SUCCESS;
    uint32           i = 0;
    
    //read card SCR, get SD specification version and check whether wide bus supported
    ret = SDC_SendCmd(pCard->SDCPort, (SD_APP_CMD | SD_NODATA_OP | SD_RSP_R1 | WAIT_PREV), (pCard->rca << 16), &status);
    if (SDC_SUCCESS != ret)
    {
        return;
    }

    memset(data, 0x00, (64 >> 3));
    ret = SDC_Request(pCard->SDCPort,
                         (SDA_SEND_SCR | SD_READ_OP | SD_RSP_R1 | WAIT_PREV), 
                         0, 
                         &status, 
                         (64 >> 3), 
                         (64 >> 3), 
                         data);
    if (SDC_SUCCESS != ret)
    {
        return;
    }
    //我们SDMMC控制器接收到Data Packet Format为Wide Width Data的数据时，数据顺序会颠倒，
    //最高字节变成最低字节，最低字节变成最高字节，因此我们这边需要颠回来
    for (i=0; i<(64 >> 4); i++)
    {
        tmp         = pDataBuf[i];
        pDataBuf[i] = pDataBuf[(64 >> 3) - 1 - i];
        pDataBuf[(64 >> 3) - 1 - i] = tmp;
    }

    switch (pDataBuf[7] & 0xF) //bit 59-56:SD specification version
    {
        case 0:
            pCard->SpecVer = SD_SPEC_VER_10;
            break;
        case 1:
            pCard->SpecVer = SD_SPEC_VER_11;
            break;
        case 2:
        {
            pCard->SpecVer = SD_SPEC_VER_20;
            if (pDataBuf[5] & 0x80)     // bit 47
            {
                pCard->SpecVer = SD_SPEC_VER_30;       
            } 
            break;
        }
        default:
            pCard->SpecVer = SPEC_VER_INVALID;
            break;
    }

    do
    {
        if (pCard->type == UHS1)
            break;
    
        ret = SDC_GetBusWidth(pCard->SDCPort, &wide);
        if (SDC_SUCCESS != ret)
        {
            break;
        }

        if((wide == BUS_WIDTH_INVALID) || (wide == BUS_WIDTH_MAX))
        {
            ret = SDC_SDC_ERROR;
            break;
        }
        //whether SDC iomux support wide bus and card internal support wide bus
        if ((wide >= BUS_WIDTH_4_BIT) && (pDataBuf[6] & 0x4)) //bit 50:whether wide bus support
        {
            _SD_SwitchBusWidth(pCard, BUS_WIDTH_4_BIT);
        }
    }while(0);

    //切换线宽有不成功不直接return，高速模式的切换可以继续
    //switch to high speed mode
    if (pCard->SpecVer >= SD_SPEC_VER_11)
    {
        SD_SPEED_MODE mode = SD_SM_HIGH_SPEED;

        if (pCard->type == UHS1)
            mode = SD_SM_DDR50;
            
        _SD_SwitchSpeedMode(pCard, mode);
    }

    return;
}

/****************************************************************/
//函数名:SD_IsCardWriteProtected
//描述:检查指定cardId的卡是否被机械开关写写保护
//参数说明:cardId           输入参数  需要检查的卡
//返回值:TRUE      卡被写保护
//       FALSE     卡没有被写保护
//相关全局变量:
//注意:
/****************************************************************/
_ATTR_SD_INIT_CODE_
static bool _SD_IsCardWriteProt(int32 nSDCPort)
{
    return FALSE;//SDC_IsCardWriteProt(nSDCPort);
}

/*
Name:       SendAppCmd
Desc:       发送application命令
Param:      
Return:     
Global: 
Note:   
Author: 
Log:
*/
_ATTR_SD_INIT_CODE_
static int32 _SD_SendAppCmd(SDMMC_PORT_E SDCPort,
                                    uint16 rca,
                                    uint32 cmd,
                                    uint32 cmdArg,
                                    uint32 *responseBuf,
                                    uint32  blockSize,
                                    uint32  dataLen,
                                    void   *pDataBuf)
{
    int32  ret = SDM_SUCCESS;
    uint32 status = 0;

    ret = SDC_Request(SDCPort, 
                         (SD_APP_CMD | SD_NODATA_OP | SD_RSP_R1 | WAIT_PREV), 
                         (rca << 16), 
                         &status, 
                         0, 
                         0, 
                         NULL);
    if ((ret == SDC_SUCCESS) && (status & 0x20))
    {
        ret = SDC_Request(SDCPort, cmd, cmdArg, responseBuf, blockSize, dataLen, pDataBuf);
    }

    return ret;
}

/****************************************************************/
//函数名:_IsRCAUsable
//描述:判断当前给出的RCA是否可用，如果与已有的卡RCA冲突，则不可用
//     如果没有冲突，则可用
//参数说明:rca   输入参数    需要检查的RCA
//返回值:TRUE     可用
//       FALSE    不可用
//相关全局变量:读取gSDMDriver[i].cardInfo.rca
//注意:
/****************************************************************/
_ATTR_SD_INIT_CODE_
bool _SD_IsRCAUsable(uint16 rca)
{
    uint32 i;
    pSDM_CARD_INFO  pCard = NULL;
    
    for (i=0; i<MAX_SDC_NUM; i++)
    {
        pCard = SDM_GetCardInfo(i);
        if (pCard != NULL && SDM_INVALID_CARDID != pCard->CardId)     //有效卡
        {
            if (pCard->rca == rca)
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}


/****************************************************************/
//函数名:SDxx_Init
//描述:SD1X卡的初始化
//参数说明:pCardInfo 输入参数  卡信息的指针
//返回值:
//相关全局变量:
//注意:
/****************************************************************/
_ATTR_SD_INIT_CODE_
int32 SDXX_Init(void *pCardInfo, bool SupportCmd8)
{
    pSDM_CARD_INFO   pCard;
    uint32           type = UNKNOW_CARD;
    uint32           longResp[4];
    uint32           status = 0;
    uint16           rca = 0;
    uint32           i = 0;
    int32            ret = SDC_SUCCESS;
    uint32           Acmd41Arg = (TRUE ==SupportCmd8)? 0x41ff8000 : 0x00ff8000;

    pCard = (pSDM_CARD_INFO)pCardInfo;

    /**************************************************/
    // 让卡进入Ready State
    /**************************************************/
    for (i=0; i<((FOD_FREQ*1000)/((48+48+2) << 1)); i++) //按照协议的规定，这里最长可以有1s的时间，我们根据每条命令执行的时间，把它换算成循环次数
    {
        /*0x41ff8000: sd3.0 arg 24bit is S18R*/
        ret = _SD_SendAppCmd(pCard->SDCPort, 0, (SDA_SD_APP_OP_COND | SD_NODATA_OP | SD_RSP_R3 | WAIT_PREV), Acmd41Arg, &status, 0, 0, NULL);
        if (SDC_SUCCESS == ret)
        {
            if (status & 0x80000000)
            {
                if (SupportCmd8)
                {
                    if ((0xc0ff8000 == status) || (0xc0ff8080 == status) || (0xc1ff8000 == status))
                        type = SDHC;
                    else if ((0x80ff8000 == status) || (0x80ff8080 == status))
                        type = SD20;
                    else
                        ret = SDM_UNKNOWABLECARD;
                }
                else
                {
                    type = SD1X;
                }
                break;
            }
        }
        else if (SDC_RESP_TIMEOUT == ret)
        {
            // Card can not perform data transfer in the specified voltage range,
            // so it discard themselves and go into "Inactive State"
            if (TRUE == SDC_CheckCard(pCard->SDCPort, MD_EVENT_PRESENT))
            {
                ret = SDM_VOLTAGE_NOT_SUPPORT;
                break;
            }
            else
            {
                ret = SDM_CARD_NOTPRESENT;
                break;
            }
        }
        else
        {
            /* error occured */
            break;
        }
    }

    if (ret != SDC_SUCCESS)
    {
        return ret;
    }
    //长时间busy,SDM_VOLTAGE_NOT_SUPPORT
    if (((FOD_FREQ*1000)/((48+48+2) << 1)) == i)
    {
        ret = SDM_VOLTAGE_NOT_SUPPORT;
        return ret;
    }
    /**************************************************/
    // 让卡进入Stand-by State
    /**************************************************/
    longResp[0] = 0;
    longResp[1] = 0;
    longResp[2] = 0;
    longResp[3] = 0;
    ret = SDC_SendCmd(pCard->SDCPort, (SD_ALL_SEND_CID | SD_NODATA_OP | SD_RSP_R2 | WAIT_PREV), 0, longResp);
    if (SDC_SUCCESS != ret)
    {
        return ret;
    }
    //decode CID
    _SD_DecodeCID(longResp, pCard);
    
    do
    {
        ret = SDC_SendCmd(pCard->SDCPort, (SD_SEND_RELATIVE_ADDR | SD_NODATA_OP | SD_RSP_R6 | WAIT_PREV), 0, &status);
        if (SDC_SUCCESS != ret)
        {
            break;
        }
        rca = (uint16)(status >> 16);
    }while (!_SD_IsRCAUsable(rca));
    if (ret != SDC_SUCCESS)
    {
        return ret;
    }

    pCard->rca = rca;
    
    longResp[0] = 0;
    longResp[1] = 0;
    longResp[2] = 0;
    longResp[3] = 0;
    ret = SDC_SendCmd(pCard->SDCPort, (SD_SEND_CSD | SD_NODATA_OP | SD_RSP_R2 | WAIT_PREV), (rca << 16), longResp);
    if (SDC_SUCCESS != ret)
    {
        return ret;
    }
    //decode CSD
    _SD_DecodeCSD(longResp, pCard);

    pCard->TranSpeed = (pCard->TranSpeed > SD_FPP_FREQ) ? SD_FPP_FREQ : (pCard->TranSpeed);
    ret = SDC_UpdateFreq(pCard->SDCPort, pCard->TranSpeed);
    if (SDC_SUCCESS != ret)
    {
        return ret;
    }
    /**************************************************/
    // 让卡进入Transfer State
    /**************************************************/
    ret = SDC_SendCmd(pCard->SDCPort, (SD_SELECT_DESELECT_CARD | SD_NODATA_OP | SD_RSP_R1B | WAIT_PREV), (rca << 16), &status);
    if (SDC_SUCCESS != ret)
    {
        return ret;
    }

    /* 协议规定不管是SD1.X或者SD2.0或者SDHC都必须支持block大小为512, 而且我们一般也只用512，因此这里直接设为512 */
    ret = SDC_SendCmd(pCard->SDCPort, (SD_SET_BLOCKLEN | SD_NODATA_OP | SD_RSP_R1 | WAIT_PREV), 512, &status);
    if (SDC_SUCCESS != ret)
    {
        return ret;
    }

    ret = _SD_SendAppCmd(pCard->SDCPort, rca, (SDA_SET_CLR_CARD_DETECT | SD_NODATA_OP | SD_RSP_R1 | WAIT_PREV), 0, &status, 0, 0, NULL);
    if (SDC_SUCCESS != ret)
    {
        return ret;
    }

    pCard->WriteProt = _SD_IsCardWriteProt(pCard->SDCPort);
    //卡输入开启密码在这里做
    if (status & CARD_IS_LOCKED)
    {
        pCard->bPassword = TRUE;
    }
    else
    {
        pCard->bPassword = FALSE;
        _SD_SwitchFunction(pCard);
    }

    pCard->type |= type;
    return ret;

}

#endif //end of #ifdef DRIVERS_SDMMC

