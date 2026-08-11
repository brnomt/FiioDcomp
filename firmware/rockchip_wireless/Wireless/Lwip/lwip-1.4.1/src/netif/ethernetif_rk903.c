/**
 * @file
 * Ethernet Interface Skeleton
 *
 */

/*
 * Copyright (c) 2001-2004 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Adam Dunkels <adam@sics.se>
 *
 */

/*
 * This file is a skeleton for developing Ethernet network interface
 * drivers for lwIP. Add code to the low_level functions and do a
 * search-and-replace for the word "ethernetif" to replace it with
 * something that better describes your network interface.
 */

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "RKOS.h"
#include "BSP.h"
#include "DeviceInclude.h"




#include "lwip/opt.h"
#ifdef USE_LWIP /* don't build, this is only a skeleton, see previous comment */

#include "lwip/def.h"
#include "lwip/mem.h"
#include "lwip/pbuf.h"
#include "lwip/sys.h"
#include <lwip/stats.h>
#include <lwip/snmp.h>
#include "netif/etharp.h"
//#include "netif/ppp_oe.h"

/* Define those to better describe your network interface. */
#define IFNAME0 'e'
#define IFNAME1 'n'

/* When a packet is ready to be sent, if it cannot be sent immediately then
 * the task performing the transmit will block for netifTX_BUFFER_FREE_WAIT
 * milliseconds.  It will do this a maximum of netifMAX_TX_ATTEMPTS before
 * giving up.
 */
#define netifTX_BUFFER_FREE_WAIT    ( ( portTickType ) 2UL / portTICK_RATE_MS )
#define netifMAX_TX_ATTEMPTS        ( 5 )

#define NETIF_MAX_MTU 1500


/**
 * Helper struct to hold private data used to operate your ethernet interface.
 * Keeping the ethernet address of the MAC in this struct is not necessary
 * as it is already kept in the struct netif.
 * But this is only an example, anyway...
 */
struct ethernetif {
  struct eth_addr *ethaddr;
  /* Add whatever per-interface state that is needed here. */
};

/* Forward declarations. */
//static void  ethernetif_input(struct netif *netif,u8 * buf, int len )
//static err_t ethernetif_output(struct netif *netif, struct pbuf *p, struct ip_addr *ipaddr);

#if 0
extern int khead_room;
#else
int khead_room = 0;
#endif

extern void wlan_main( struct netif *netif );
//Return ERR_OK if success, others if no success
 int wlan_hard_start_xmit(u8_t* tx_buf, u32_t len);
 unsigned char hwaddr[6];


/**
 * In this function, the hardware should be initialized.
 * Called from ethernetif_init().
 *
 * @param netif the already initialized lwip network interface structure
 *        for this ethernetif
 */
static void low_level_init(struct netif *netif)
{
    #if 0
    struct ethernetif *ethernetif = netif->state;

    /* set MAC hardware address length */
    netif->hwaddr_len = ETHARP_HWADDR_LEN;


    /* set MAC hardware address */

    netif->hwaddr[0] = hwaddr[0];
    netif->hwaddr[1] = hwaddr[1];
    netif->hwaddr[2] = hwaddr[2];
    netif->hwaddr[3] = hwaddr[3];
    netif->hwaddr[4] = hwaddr[4];
    netif->hwaddr[5] = hwaddr[5];

    /* maximum transfer unit */
    netif->mtu = NETIF_MAX_MTU;

    /* device capabilities */
    /* don't set NETIF_FLAG_ETHARP if this device is not an ethernet one */
    netif->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_LINK_UP;

    /* Do whatever else is needed to initialize interface. */
    //wlan_main(netif);
    #endif

    char       pmac[6];

    /* set MAC hardware address length */
    netif->hwaddr_len = ETHARP_HWADDR_LEN;
    RK903Dev_GetMac(pmac);
    memcpy((char *)netif->hwaddr, pmac, ETHARP_HWADDR_LEN);

    rk_printf("mac:%02x-%02x-%02x-%02x-%02x-%02x",
              netif->hwaddr[0], netif->hwaddr[1], netif->hwaddr[2],
              netif->hwaddr[3], netif->hwaddr[4], netif->hwaddr[5]);

    /* maximum transfer unit */
    netif->mtu = 1500;

    /* device capabilities */
    /* don't set NETIF_FLAG_ETHARP if this device is not an ethernet one */
    netif->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_LINK_UP;
}

/**
 * This function should do the actual transmission of the packet. The packet is
 * contained in the pbuf that is passed to the function. This pbuf
 * might be chained.
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @param p the MAC packet to send (e.g. IP packet including MAC addresses and type)
 * @return ERR_OK if the packet could be sent
 *         an err_t value if the packet couldn't be sent
 *
 * @note Returning ERR_MEM here if a DMA queue of your MAC is full can lead to
 *       strange results. You might consider waiting for space in the DMA queue
 *       to become availale since the stack doesn't retry to send a packet
 *       dropped because of memory failure (except for the TCP timers).
 */

static err_t low_level_output(struct netif *netif, struct pbuf *p)
{
    struct ethernetif *ethernetif = netif->state;
    struct pbuf *q;
    unsigned char* tx_buf;
    u32_t l = 0, pl = 0;
    int i,x;
    err_t xReturn = ERR_OK;

     //initiate transfer();

#if ETH_PAD_SIZE
    pbuf_header(p, -ETH_PAD_SIZE); /* drop the padding word */
#endif

    for(q = p; q != NULL; q = q->next)
    {
        /* Send the data from the pbuf to the interface, one pbuf at a
        time. The size of the data in each pbuf is kept in the ->len
        variable. */
        //send data from(q->payload, q->len);
        l += q->len;
    }

    i=0;
    l += khead_room;// rerserv room for wlan tx header


    //xinghua 20100826, this is called in the thread context of tcpip_thread
    //if failed to malloc for some reason, we should be blocking here.
    //But if failed always, something must go wrong with Wifi...
    while(1)
    {
        tx_buf = rkos_memory_malloc(l);
        if(tx_buf != NULL)
            break;
        if(i>300)
            break;
        vTaskDelay(2);
        i++;
    }

    if(tx_buf != NULL)
    {
        for(q = p; q != NULL; q = q->next)
        {
            /* Send the data from the pbuf to the interface, one pbuf at a
            time. The size of the data in each pbuf is kept in the ->len
            variable. */
            memcpy(tx_buf+khead_room+pl, (u8_t*)q->payload, q->len);
            pl += q->len;
        }
        for( x = 0; x < netifMAX_TX_ATTEMPTS; x++ )
        {
           // xReturn =  wlan_hard_start_xmit(tx_buf, l);         //zhu Special note
             xReturn = dhd_senddata(NULL,tx_buf,l);
            if( xReturn == ERR_OK )
            {
                rkos_memory_free(tx_buf);
                break;
            }
            else
            {
                vTaskDelay( netifTX_BUFFER_FREE_WAIT );
            }
        }
    }
    else
    {
        xReturn = ERR_MEM;
    }

#if ETH_PAD_SIZE
        pbuf_header(p, ETH_PAD_SIZE); /* reclaim the padding word */
#endif

        LINK_STATS_INC(link.xmit);

  return xReturn;
}

/**
 * Should allocate a pbuf and transfer the bytes of the incoming
 * packet from the interface into the pbuf.
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @return a pbuf filled with the received packet (including MAC header)
 *         NULL on memory error
 */
static struct pbuf *low_level_input(struct netif *netif,u8_t *rx_buf, int len)
{
    struct ethernetif *ethernetif = netif->state;
    struct pbuf *p=NULL, *q;

      /* Obtain the size of the packet and put it into the "len" variable. */
        if(len >0)
        {
#if ETH_PAD_SIZE
                len += ETH_PAD_SIZE; /* allow room for Ethernet padding */
#endif
                /* We allocate a pbuf chain of pbufs from the pool. */
                p = pbuf_alloc(PBUF_RAW, len, PBUF_POOL);

                if (p != NULL)
                {
#if ETH_PAD_SIZE
                        pbuf_header(p, -ETH_PAD_SIZE); /* drop the padding word */
#endif
                        /* We iterate over the pbuf chain until we have read the entire
                        * packet into the pbuf. */
                        len = 0;
                        for(q = p; q != NULL; q = q->next)
                        {
                                /* Read enough bytes to fill this pbuf in the chain. The
                                * available data in the pbuf is given by the q->len
                                * variable.
                                * This does not necessarily have to be a memcpy, you can also preallocate
                                * pbufs for a DMA-enabled MAC and after receiving truncate it to the
                                * actually received size. In this case, ensure the tot_len member of the
                                * pbuf is the sum of the chained pbuf len members.
                                */
                                //read data into(q->payload, q->len);
                                memcpy( q->payload, &( rx_buf[ len] ), q->len );
                                len += q->len;
                        }
                        //acknowledge that packet has been read();

#if ETH_PAD_SIZE
                        pbuf_header(p, ETH_PAD_SIZE); /* reclaim the padding word */
#endif
                        LINK_STATS_INC(link.recv);
                }
                else
                {
                        //drop packet();
                        LINK_STATS_INC(link.memerr);
                        LINK_STATS_INC(link.drop);
                }
        }
        return p;
}

/**
 * This fu tion should be called when a packet is ready to be read
 * from the interface. It uses the function low_level_input() that
 * should handle the actual reception of bytes from the network
 * interface. Then the type of the received packet is determined and
 * the appropriate input function is called.
 *
 * @param netif the lwip network interface structure for this ethernetif
 */
void ethernetif_input(struct netif *netif, uint8 * buf, int len )
{
    struct ethernetif *ethernetif;
    struct eth_hdr *ethhdr;
    struct pbuf *p;

    ethernetif = netif->state;

    /* move received packet into a new pbuf */
    p = low_level_input(netif, buf, len );

    /* no packet could be read, silently ignore this */
    if (p == NULL) return;
    /* points to packet payload, which starts with an Ethernet header */
    ethhdr = p->payload;
    switch (htons(ethhdr->type))
    {
            /* IP or ARP packet? */
        case ETHTYPE_IP:
        case ETHTYPE_ARP:
        /* full packet send to tcpip_thread to process */
            if (netif->input(p, netif)!=ERR_OK)
            {
                LWIP_DEBUGF(NETIF_DEBUG, ("ethernetif_input: IP input error\n"));
                pbuf_free(p);
                p = NULL;
            }
            break;

        default:
            pbuf_free(p);
            p = NULL;
            break;
    }
}

/**
 * Should be called at the beginning of the program to set up the
 * network interface. It calls the function low_level_init() to do the
 * actual setup of the hardware.
 *
 * This function should be passed as a parameter to netif_add().
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @return ERR_OK if the loopif is initialized
 *         ERR_MEM if private data couldn't be allocated
 *         any other err_t on error
 */
err_t ethernetif_init(struct netif *netif)
{
   // struct ethernetif *ethernetif;
//    LWIP_ASSERT("netif != NULL", (netif != NULL));
//    ethernetif = mem_malloc(sizeof(struct ethernetif));

   // if (ethernetif == NULL)
 //   {
 //       LWIP_DEBUGF(NETIF_DEBUG, ("ethernetif_init: out of memory\n"));
//        return ERR_MEM;
  //  }

#if LWIP_NETIF_HOSTNAME
      /* Initialize interface hostname */
      netif->hostname = "lwip_rock";
#endif /* LWIP_NETIF_HOSTNAME */

  /*
   * Initialize the snmp variables and counters inside the struct netif.
   * The last argument should be replaced with your link speed, in units
   * of bits per second.
   */
#if LWIP_SNMP
    NETIF_INIT_SNMP(netif, snmp_ifType_ethernet_csmacd, LINK_SPEED_OF_YOUR_NETIF_IN_BPS);
#endif

    //netif->state = ethernetif;
    netif->name[0] = IFNAME0;
    netif->name[1] = IFNAME1;
    /* We directly use etharp_output() here to save a function call.
    * You can instead declare your own function an call etharp_output()
    * from it if you have to do some checks before sending (e.g. if link
    * is available...) */
    netif->output = etharp_output;
    netif->linkoutput = low_level_output;

    //ethernetif->ethaddr = (struct eth_addr *)&(netif->hwaddr[0]);

    /* initialize the hardware */
    low_level_init(netif);

    return ERR_OK;
}

#endif /* 0 */
