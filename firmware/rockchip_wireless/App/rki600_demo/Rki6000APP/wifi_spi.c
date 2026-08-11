#include "FreeRTOS.h"
#include "RKOS.h"
#include "wifi_spi.h"
#include "Bsp.h"
#include "DeviceInclude.h"
#include "device.h"
//#include "spi_dma.h"
//#include "debug_print.h"
#ifdef __DRIVER_I6000_WIFI_C__
extern int wifi_interrupt(void);

#define RKNANOD_SDK_MAIN_V12_20150515HJH 0
#define RKNANOD_SDK_MAIN_V10_20150126HJH 1
#define RKNANOD_SDK_MAIN_V12_20150908HJH 2
#define RKNANOD_SDK_MAIN_MCP 3
#define SPI_WIFI_BOARD_VERSIONS RKNANOD_SDK_MAIN_V12_20150908HJH
static HDC g_hSpi;
#define WIFI_SPI_CLK GPIOPortC_Pin2
#define WIFI_SPI_IN  GPIOPortC_Pin1
#define WIFI_SPI_OUT GPIOPortC_Pin0
#define WIFI_SPI_CS  GPIOPortC_Pin5
#define WIFI_SPI_INT GPIOPortC_Pin7
//   0: MISO is driven at rising edge of spi_clk
#define SPI_CTL_TXRX_MASTER ( SPI_MASTER_MODE | TRANSMIT_RECEIVE | MOTOROLA_SPI \
                            | RXD_SAMPLE_NO_DELAY | APB_BYTE_WR \
                            | MSB_FBIT | LITTLE_ENDIAN_MODE | CS_2_SCLK_OUT_1_2_CK \
                            | CS_KEEP_LOW | SERIAL_CLOCK_POLARITY_HIGH\
                            | SERIAL_CLOCK_PHASE_MIDDLE | DATA_FRAME_8BIT)

//    1: MISO is driven at faling edge of spi_clk
//#define SPI_CTL_TXRX_MASTER ( SPI_MASTER_MODE | TRANSMIT_RECEIVE | MOTOROLA_SPI \
//                            | RXD_SAMPLE_NO_DELAY | APB_BYTE_WR \
//                            | MSB_FBIT | LITTLE_ENDIAN_MODE | CS_2_SCLK_OUT_1_2_CK \
//                            | CS_KEEP_LOW | SERIAL_CLOCK_POLARITY_HIGH\
//                            | SERIAL_CLOCK_PHASE_START | DATA_FRAME_8BIT)

//#define SPI_CTL_TXRX_MASTER ( SPI_MASTER_MODE | TRANSMIT_RECEIVE | MOTOROLA_SPI \
//                            | RXD_SAMPLE_NO_DELAY | APB_BYTE_WR \
//                            | MSB_FBIT | LITTLE_ENDIAN_MODE | CS_2_SCLK_OUT_1_2_CK \
//                            | CS_KEEP_LOW | SERIAL_CLOCK_POLARITY_HIGH\
//                            | SERIAL_CLOCK_PHASE_MIDDLE | DATA_FRAME_8BIT)

#if SPI_WIFI_BOARD_VERSIONS == RKNANOD_SDK_MAIN_V12_20150908HJH
void spi_interrupt_task(void *arg);
pSemaphore spi_int_sema;
pSemaphore spi_int_lock_sema;
int spi_int_lock = 0;
void wifi_spi_enable_interrupt(void);
void wifi_spi_disable_interrupt(void);
void wifi_spi_init(void)
{
    SPI_DEV_ARG stSpiArg;
    HDC hSpi,hStorage;
    HDC hDma;
    rk_err_t ret;
//    hal_set_spi_phase(1);
    stSpiArg.Ch = 0;
    stSpiArg.CtrlMode = SPI_CTL_TXRX_MASTER;//SPI_CTL_MODE;
    stSpiArg.SpiRate = 12000*1000;


    printf("\r\nspi device init...12M");
    printf("RKNANOD_SDK_MAIN_V12_20150908HJH\n");

    ret = RKDev_Create(DEV_CLASS_SPI, 1, &stSpiArg);
    if (ret != RK_SUCCESS)
    {
        goto err;
    }

    hSpi = RKDev_Open(DEV_CLASS_SPI, 1, NOT_CARE);
    g_hSpi = hSpi;
    if ((hSpi == NULL) || (hSpi == (HDC)RK_ERROR) || (hSpi == (HDC)RK_PARA_ERR))
    {
        goto err;
    }
err:

    Grf_GpioMuxSet(GPIO_CH1, GPIOPortA_Pin5, 0); // cs
    Gpio_SetPinDirection(GPIO_CH1, GPIOPortA_Pin5, GPIO_OUT);
    Gpio_SetPinLevel(GPIO_CH1, GPIOPortA_Pin5, GPIO_HIGH);
    Grf_GPIO_SetPinPull(GPIO_CH1, GPIOPortA_Pin5, DISABLE);

    Grf_GpioMuxSet(GPIO_CH1, GPIOPortB_Pin2, 0);  // wifi en
    Gpio_SetPinDirection(GPIO_CH1, GPIOPortB_Pin2, GPIO_OUT);
    Gpio_SetPinLevel(GPIO_CH1, GPIOPortB_Pin2, GPIO_LOW);
    Grf_GPIO_SetPinPull(GPIO_CH1, GPIOPortB_Pin2, DISABLE);


    Grf_GpioMuxSet(GPIO_CH2, GPIOPortA_Pin2, 0);  // wifi rst
    Gpio_SetPinDirection(GPIO_CH2, GPIOPortA_Pin2, GPIO_OUT);
    Gpio_SetPinLevel(GPIO_CH2, GPIOPortA_Pin2, GPIO_LOW);
    Grf_GPIO_SetPinPull(GPIO_CH2, GPIOPortA_Pin2, DISABLE);

    DelayMs(20);
    Gpio_SetPinLevel(GPIO_CH1, GPIOPortB_Pin2, GPIO_HIGH);
    //rkos_sleep(10);
    DelayMs(20);
    Gpio_SetPinLevel(GPIO_CH2, GPIOPortA_Pin2, GPIO_HIGH);
    //rkos_sleep(10);


    HDC spi_interrupt_tcb;
    spi_int_sema = rkos_semaphore_create(100, 0);
    spi_int_lock_sema = rkos_semaphore_create(1, 1);
    spi_int_lock = 0;
    xTaskCreate( spi_interrupt_task, "spi_int_task", 512, NULL, configMAX_PRIORITIES, &spi_interrupt_tcb,NULL);

    rkos_sleep(300);
    return;

}

void wifi_spi_irq_hook(void)
{
    //printf("wifi_spi_irq\n");
    //wifi_interrupt();
    rkos_semaphore_give_fromisr(spi_int_sema);

}

#define WIFI_SPI_INT_PORT GPIO_CH2
#define WIFI_SPI_INT GPIOPortA_Pin0

void spi_interrupt_task(void *arg)
{
    printf("spi_interrupt_task\n");
    while(1)
    {
        rkos_semaphore_take(spi_int_sema, MAX_DELAY);
        wifi_interrupt();
    }
}

void exti_init(void)
{
    printf("exti_init enter\n");
    Grf_GpioMuxSet(WIFI_SPI_INT_PORT, WIFI_SPI_INT, 0);
    Gpio_SetPinDirection(WIFI_SPI_INT_PORT, WIFI_SPI_INT, GPIO_IN);
    Grf_GPIO_SetPinPull(WIFI_SPI_INT_PORT, WIFI_SPI_INT, DISABLE);
    Gpio_SetIntMode(WIFI_SPI_INT_PORT,WIFI_SPI_INT, IntrTypeRisingEdge);//IntrTypeRisingEdge
    //Gpio_SetIntMode(WIFI_SPI_INT_PORT,WIFI_SPI_INT, IntrTypeHighLevel);

    GpioIsrRegister(WIFI_SPI_INT_PORT,WIFI_SPI_INT, wifi_spi_irq_hook);
    Gpio_UnMaskInt(WIFI_SPI_INT_PORT,WIFI_SPI_INT);
    Gpio_EnableInt(WIFI_SPI_INT_PORT,WIFI_SPI_INT);

    IntRegister(INT_ID_GPIO2,GpioInt2);
    IntPendingClear(INT_ID_GPIO2);
    IntEnable(INT_ID_GPIO2);

    if(Gpio_GetPinLevel(WIFI_SPI_INT_PORT, WIFI_SPI_INT))
    {
        printf("spi int has happen\n");
        //wifi_interrupt();
    }


}

void exti_deinit()
{
    IntDisable(INT_ID_GPIO2);
}

void wifi_spi_ctl_bus(uint8 cs_select)
{
    if(cs_select)
    {
        //DelayUs(1);
        Gpio_SetPinLevel(GPIO_CH1, GPIOPortA_Pin5, GPIO_LOW);

    }
    else
    {
        //DelayUs(1);
        Gpio_SetPinLevel(GPIO_CH1, GPIOPortA_Pin5, GPIO_HIGH);

    }
}

uint32 wifi_spi_read( uint8 * buf_ptr, uint32 length)
{
    uint32 len = length;
    uint8 *data = buf_ptr;
    SpiDev_Read(g_hSpi,buf_ptr, length,0, SYNC_MODE, NULL);
    return 0;
}

uint32 wifi_spi_write( uint8 * buf_ptr, uint32 length)
{
    uint len = length;
    uint len1 =0;
    SpiDev_Write(g_hSpi,buf_ptr, length, SYNC_MODE, NULL);
    return 0;
}

uint32 wifi_spi_rx( uint8 * buf_ptr, uint32 length)
{
    wifi_spi_read(buf_ptr, length);
    return 0;
}

uint32 wifi_spi_tx( uint8 * buf_ptr, uint32 length)
{
    //printf("-\n");
    wifi_spi_write(buf_ptr,length);
    return 0;
}

void wifi_spi_enable_interrupt(void)
{
    //Gpio_EnableInt(WIFI_SPI_INT_PORT,WIFI_SPI_INT);
    spi_int_lock = 0;
    rkos_semaphore_give(spi_int_lock_sema);
}




void wifi_spi_disable_interrupt(void)
{
    spi_int_lock = 1;
    //Gpio_DisableInt(WIFI_SPI_INT_PORT,WIFI_SPI_INT);
    rkos_semaphore_take(spi_int_lock_sema,MAX_DELAY);

}

void wifi_spi_change_clk(uint8 force_low_clk)
{
    if (force_low_clk)
    {
    }
    else
    {
    }
}
#endif


#if SPI_WIFI_BOARD_VERSIONS == RKNANOD_SDK_MAIN_MCP
void spi_interrupt_task(void *arg);
pSemaphore spi_int_sema;
pSemaphore spi_int_lock_sema;
int spi_int_lock = 0;
void wifi_spi_enable_interrupt(void);
void wifi_spi_disable_interrupt(void);
void wifi_spi_init(void)
{
    SPI_DEV_ARG stSpiArg;
    HDC hSpi,hStorage;
    HDC hDma;
    rk_err_t ret;

    stSpiArg.Ch = 1;
    stSpiArg.CtrlMode = SPI_CTL_TXRX_MASTER;//SPI_CTL_MODE;
    stSpiArg.SpiRate = 12000*1000; //spi 时钟只能偶数分频
    //hal_set_spi_phase(1);
    Grf_Force_Jtag_Set (0);
    printf("\r\nspi device init...12M\n");
    printf("\r\nRKNANOD_SDK_MAIN_MCP\n");
    ret = RKDev_Create(DEV_CLASS_SPI, 1, &stSpiArg);
    if (ret != RK_SUCCESS)
    {
        goto err;
    }

    hSpi = RKDev_Open(DEV_CLASS_SPI, 1, NOT_CARE);
    g_hSpi = hSpi;
    if ((hSpi == NULL) || (hSpi == (HDC)RK_ERROR) || (hSpi == (HDC)RK_PARA_ERR))
    {
        //goto err;
    }

//    Grf_GPIO_SetPinPull(GPIO_CH2, GPIOPortC_Pin1, DISABLE);
//    Grf_GPIO_SetPinPull(GPIO_CH2, GPIOPortC_Pin0, DISABLE);
//    Grf_GPIO_SetPinPull(GPIO_CH2, GPIOPortB_Pin6, DISABLE);
//    Grf_GPIO_SetPinPull(GPIO_CH2, GPIOPortB_Pin7, DISABLE);


    Grf_GpioMuxSet(GPIO_CH2, GPIOPortB_Pin6, 0); // cs
    Gpio_SetPinDirection(GPIO_CH2, GPIOPortB_Pin6, GPIO_OUT);
    Gpio_SetPinLevel(GPIO_CH2, GPIOPortB_Pin6, GPIO_HIGH);
    Grf_GPIO_SetPinPull(GPIO_CH2, GPIOPortB_Pin6, DISABLE);

//    Grf_GpioMuxSet(GPIO_CH2, GPIOPortA_Pin4, 0); // cs
//    Gpio_SetPinDirection(GPIO_CH2, GPIOPortA_Pin4, GPIO_OUT);
//    Gpio_SetPinLevel(GPIO_CH2, GPIOPortA_Pin4, GPIO_HIGH);
//    Grf_GPIO_SetPinPull(GPIO_CH2, GPIOPortA_Pin4, DISABLE);

    Grf_GpioMuxSet(GPIO_CH2, GPIOPortA_Pin4, 0);  // wifi en
    Gpio_SetPinDirection(GPIO_CH2, GPIOPortA_Pin4, GPIO_OUT);
    Gpio_SetPinLevel(GPIO_CH2, GPIOPortA_Pin4, GPIO_LOW);
    Grf_GPIO_SetPinPull(GPIO_CH2, GPIOPortA_Pin4, DISABLE);


    Grf_GpioMuxSet(GPIO_CH2, GPIOPortB_Pin1, 0);  // wifi rst
    Gpio_SetPinDirection(GPIO_CH2, GPIOPortB_Pin1, GPIO_OUT);
    Gpio_SetPinLevel(GPIO_CH2, GPIOPortB_Pin1, GPIO_LOW);
    Grf_GPIO_SetPinPull(GPIO_CH2, GPIOPortB_Pin1, DISABLE);


    //rkos_sleep(10);
    DelayMs(20);
    Gpio_SetPinLevel(GPIO_CH2, GPIOPortA_Pin4, GPIO_HIGH); //en
    //rkos_sleep(10);
    DelayMs(20);
    Gpio_SetPinLevel(GPIO_CH2, GPIOPortB_Pin1, GPIO_HIGH); //rst

    HDC spi_interrupt_tcb;
    spi_int_sema = rkos_semaphore_create(100, 0);
    spi_int_lock_sema = rkos_semaphore_create(1, 1);
    spi_int_lock = 0;
    xTaskCreate( spi_interrupt_task, "spi_int_task", 512, NULL, configMAX_PRIORITIES, &spi_interrupt_tcb,NULL);
    rkos_sleep(300);
err:
    return;



}

void wifi_spi_irq_hook(void)
{
    //printf("wifi_spi_irq\n");
    //wifi_interrupt();
    rkos_semaphore_give_fromisr(spi_int_sema);

}

#define WIFI_SPI_INT_PORT GPIO_CH2
#define WIFI_SPI_INT GPIOPortB_Pin0

void spi_interrupt_task(void *arg)
{
    printf("spi_interrupt_task\n");
    while(1)
    {
        rkos_semaphore_take(spi_int_sema, MAX_DELAY);
        wifi_interrupt();
    }
}

void exti_init(void)
{
    printf("exti_init enter\n");
    Grf_GpioMuxSet(WIFI_SPI_INT_PORT, WIFI_SPI_INT, 0);
    Gpio_SetPinDirection(WIFI_SPI_INT_PORT, WIFI_SPI_INT, GPIO_IN);
    Grf_GPIO_SetPinPull(WIFI_SPI_INT_PORT, WIFI_SPI_INT, DISABLE);
    Gpio_SetIntMode(WIFI_SPI_INT_PORT,WIFI_SPI_INT, IntrTypeRisingEdge);//IntrTypeRisingEdge
    //Gpio_SetIntMode(WIFI_SPI_INT_PORT,WIFI_SPI_INT, IntrTypeHighLevel);

    GpioIsrRegister(WIFI_SPI_INT_PORT,WIFI_SPI_INT, wifi_spi_irq_hook);
    Gpio_UnMaskInt(WIFI_SPI_INT_PORT,WIFI_SPI_INT);
    Gpio_EnableInt(WIFI_SPI_INT_PORT,WIFI_SPI_INT);

    IntRegister(INT_ID_GPIO2,GpioInt2);
    IntPendingClear(INT_ID_GPIO2);
    IntEnable(INT_ID_GPIO2);

    if(Gpio_GetPinLevel(WIFI_SPI_INT_PORT, WIFI_SPI_INT))
    {
        printf("spi int has happen\n");
        //wifi_interrupt();
    }


}

void exti_deinit()
{
    IntDisable(INT_ID_GPIO2);
}

void wifi_spi_ctl_bus(uint8 cs_select)
{
    if(cs_select)
    {
        //DelayUs(1);
        Gpio_SetPinLevel(GPIO_CH2, GPIOPortB_Pin6, GPIO_LOW);

    }
    else
    {
        //DelayUs(1);
        Gpio_SetPinLevel(GPIO_CH2, GPIOPortB_Pin6, GPIO_HIGH);

    }
}

uint32 wifi_spi_read( uint8 * buf_ptr, uint32 length)
{
    uint32 len = length;
    uint8 *data = buf_ptr;
    SpiDev_Read(g_hSpi,buf_ptr, length,0, SYNC_MODE, NULL);
    return 0;
}

uint32 wifi_spi_write( uint8 * buf_ptr, uint32 length)
{
    uint len = length;
    uint len1 =0;
    SpiDev_Write(g_hSpi,buf_ptr, length, SYNC_MODE, NULL);
    return 0;
}

uint32 wifi_spi_rx( uint8 * buf_ptr, uint32 length)
{
    wifi_spi_read(buf_ptr, length);
    return 0;
}

uint32 wifi_spi_tx( uint8 * buf_ptr, uint32 length)
{
    wifi_spi_write(buf_ptr,length);
    return 0;
}

void wifi_spi_enable_interrupt(void)
{
    spi_int_lock = 0;
    rkos_semaphore_give(spi_int_lock_sema);
}




void wifi_spi_disable_interrupt(void)
{
    spi_int_lock = 1;
    rkos_semaphore_take(spi_int_lock_sema,MAX_DELAY);

}

void wifi_spi_change_clk(uint8 force_low_clk)
{
    if (force_low_clk)
    {
        //SpiDev_SetRate(g_hSpi,8000*1000);
    }
    else
    {
        //SpiDev_SetRate(g_hSpi,12000*1000);
    }
}
#endif

//#pragma arm section code
#endif /*#ifdef __DRIVER_I6000_WIFI_C__*/
