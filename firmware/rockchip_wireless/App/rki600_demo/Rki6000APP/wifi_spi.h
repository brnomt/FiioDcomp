#ifndef __WIFI_SPI_H
#define __WIFI_SPI_H

//#include <includes.h>

#define SPI_MODE_CPU                0x01
#define SPI_MODE_DMA_POLLING        0x02
#define SPI_MODE_DMA_INTERRUPT  0x04


#ifndef SPI_OP_MODE
#define SPI_OP_MODE SPI_MODE_CPU
//#define SPI_OP_MODE SPI_MODE_DMA_POLLING
//#define SPI_OP_MODE SPI_MODE_DMA_INTERRUPT
#endif


#define WIFI_CS     PGout(8)    //片选信号
#define WIFI_RST    PGout(6)        //复位信号

#define TwoByteSwap(_twobyte)   (((_twobyte&0xff00)>>8) | ((_twobyte<<8) & 0xff00))

void wifi_spi_init(void);

void wifi_spi_ctl_bus(uint8 cs_select);

uint32 wifi_spi_read( uint8 * buf_ptr, uint32 length);
uint32 wifi_spi_write( uint8 * buf_ptr, uint32 length);

void wifi_spi_enable_interrupt(void);
void wifi_spi_disable_interrupt(void);

uint32 wifi_spi_tx( uint8 * buf_ptr, uint32 length);
uint32 wifi_spi_rx( uint8 * buf_ptr, uint32 length);

void exti_init(void);


#endif

