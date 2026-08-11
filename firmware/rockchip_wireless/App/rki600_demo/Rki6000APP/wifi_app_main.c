/*
********************************************************************************************
*
*        Copyright (c): Fuzhou Rockchip Electronics Co., Ltd
*                             All rights reserved.
*
* FileName: wifi_app_main.c
* Owner:
* Date: 2016.5.3
* Time: 9:30:28
* Version: 1.0
* Desc:
* History:
*    <author>    <date>       <time>     <version>     <Desc>
*          2016.5.3     9:30:28   1.0
********************************************************************************************
*/


/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   #include define
*
*---------------------------------------------------------------------------------------------------------------------
*/

#include "BspConfig.h"
#include "source_macro.h"
#include "debug_print.h"
#include "app_cfg.h"
#include "lwip/netifapi.h"
#include "FreeRTOS.h"
#include "RKOS.h"
#include "lwip/dhcp.h"
#include "lwip/ip_addr.h"
#include "lwip/sockets.h"
#include "wifi_daemon.h"
#include "wifi_netlink.h"
#include "dhcpd.h"
#include "wifi_db.h"
#include "lwip/api.h"
#ifdef __DRIVER_I6000_WIFI_C__


/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   #define / #typedef define
*
*---------------------------------------------------------------------------------------------------------------------
*/
extern struct netif wifi_netif;

typedef struct wifi_event_struct
{
    uint16 event_group;
    uint32 event_code;
    void* event_arg;
    uint16 arg_len;
}WIFI_EVENT_STRUCT;

#define WIFI_EVENT_GROUP_DEFAULT (0)
/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local variable define
*
*---------------------------------------------------------------------------------------------------------------------
*/
_os_task  wifi_user_task_tcb;
_os_task  wifi_user_tcpip_task_tcb;
pQueue wifi_user_queue;

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
void wifi_user_task_start(void);


/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   API(common) define
*
*---------------------------------------------------------------------------------------------------------------------
*/
_ATTR_SYS_CODE_
void wifi_app_start(void)
{
    FREQ_ExitModule(FREQ_BLON);
    FREQ_ExitModule(FREQ_MIN);
    FREQ_EnterModule(FREQ_RKI6000);
    FREQ_EnterModule(FREQ_INIT);
    //cpu_usage_rate_start();
    FW_LoadSegment(SEGMENT_ID_I6000_WIFI, SEGMENT_OVERLAY_ALL);
    FW_LoadSegment(SEGMENT_ID_I6000_WIFI2, SEGMENT_OVERLAY_ALL);
    FW_LoadSegment(SEGMENT_ID_LWIP, SEGMENT_OVERLAY_ALL);
    FW_LoadSegment(SEGMENT_ID_LWIP_API, SEGMENT_OVERLAY_ALL);
    FW_LoadSegment(SEGMENT_ID_HTTP, SEGMENT_OVERLAY_ALL);
    FW_LoadSegment(SEGMENT_ID_HTTPD, SEGMENT_OVERLAY_ALL);
    lwip_i6000_main();
    //wifi_user_task_start();
    //tcp_test_init();
    //wifi_state_led_task_start();
}

_ATTR_SYS_CODE_
void wifi_app_stop(void)
{

//    FW_RemoveSegment(SEGMENT_ID_I6000_WIFI);
//    FW_RemoveSegment(SEGMENT_ID_I6000_WIFI2);
//    FW_RemoveSegment(SEGMENT_ID_LWIP);
//    FW_RemoveSegment(SEGMENT_ID_LWIP_API);
//    FW_RemoveSegment(SEGMENT_ID_HTTP);
//    FW_RemoveSegment(SEGMENT_ID_HTTPD);

}


/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local function(common) define
*
*---------------------------------------------------------------------------------------------------------------------
*/
void wifi_event_handle(uint32 event_type, void *parameter, uint32 param_size,err_t err)
{
    WIFI_EVENT_STRUCT wifi_event;
    wifi_event.event_group = WIFI_EVENT_GROUP_DEFAULT;
    wifi_event.event_code = event_type;
    wifi_event.arg_len= 0;
    wifi_event.event_arg= NULL;

    if(wifi_user_queue)
    {
        rkos_queue_send(wifi_user_queue, &wifi_event, MAX_DELAY);
    }
}

void wifi_user_task(void *arg)
{
    wifi_user_queue = rkos_queue_create(100, sizeof(WIFI_EVENT_STRUCT));
    WIFI_EVENT_STRUCT wifi_event;
    while(1)
    {
        rkos_queue_receive(wifi_user_queue, &wifi_event, MAX_DELAY);
        if(wifi_event.event_group == WIFI_EVENT_GROUP_DEFAULT)
        {
            switch(wifi_event.event_code)
            {
                case WIFI_EVENT_TYPE_DISCONNECTED:

                break;

                case WIFI_EVENT_TYPE_CONNECTED:

                break;


                case WIFI_EVENT_TYPE_IP_CONFIGED:

                break;
            }
        }
    }
}

void wifi_user_tcpip_task(void *arg)
{
    struct tcp_pcb *pcb;
    struct netconn *conn;
    struct netconn *conn_new;
    struct netbuf * buf;
    err_t err;

    while(1)
    {
        if(netif_is_up(&wifi_netif)) //wait for dhcp get ip addr;
        {
            break;
        }
        freertos_msleep(50);
    }

    conn = netconn_new(NETCONN_TCP);
    if(conn == NULL)
    {
        printf("netconn_new alloc fail\n");

        while(1)
        {
            freertos_msleep(100);
        }
    }

    netconn_bind(conn , IP_ADDR_ANY, 90);

    netconn_listen(conn);

    netconn_accept(conn, &conn_new);
    while(1)
    {
        if(netconn_recv(conn_new, &buf) == 0)
        {
            netbuf_delete(buf);
            //printf("get data len = %d\n");
            //netconn_write(conn_new, tcp_buf, 512, NETCONN_COPY);
        }
        else
        {
            printf("netconn_close\n");
            netconn_close(conn_new);
            netconn_delete(conn_new);
            netconn_accept(conn, &conn_new);
            printf("netconn_accept\n");
        }
    }
}

void wifi_user_task_start(void)
{
    freertos_create_task(&wifi_user_task_tcb,"wifi_uesr_task",256*4*4,0,WIFI_DEFUALT_TASK_PRIO, wifi_user_task, NULL);
    freertos_create_task(&wifi_user_tcpip_task_tcb,"wifi_uesr_task",256*4*4,0,WIFI_DEFUALT_TASK_PRIO, wifi_user_tcpip_task, NULL);
}

void wifi_user_task_stop(void)
{
    freertos_delete_task(&wifi_user_task_tcb);
    freertos_delete_task(&wifi_user_tcpip_task_tcb);
    rkos_queue_delete(wifi_user_queue);
}

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



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local function(shell) define
*
*---------------------------------------------------------------------------------------------------------------------
*/



#endif /*#ifdef __DRIVER_I6000_WIFI_C__*/
