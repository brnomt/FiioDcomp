#include "BspConfig.h"
#include "source_macro.h"
#include "debug_print.h"

//#include <includes.h>
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
#include "BSP.h"
//#include "wifi_shell.h"
#define I6000_DEBUG(format,...)    printf("%s,L:%d:"format"\n", __MODULE__, __LINE__, ##__VA_ARGS__)
#ifdef __DRIVER_I6000_WIFI_C__
extern uint8  dhcp_ip_got;
extern xQueueHandle wifi_event_queue_handle;
#define LCD_ShowString(a,b,c,d,e,f)

#define command_test_mode()
err_t tcpip_input(struct pbuf *p, struct netif *inp);
#if 1 //def CONFIG_WIFI_STA_MODE

extern struct netif wifi_netif;
extern uint8 need_do_dhcp;
extern WIFI_NETLINK_OPERATIONS_T wifi_netlink_ops;
extern _os_task  wifi_test_task_tcb;
//struct netif wifi_netif;
extern uint8 lwip_init_wifi;

extern uint8 exit_cmd_mode;
extern WIFI_NETLINK_INFO_T *p_wifi_netlink;
extern uint8  dhcp_ip_got;

extern void dhcpd_daemon(void);
extern void ping_entry(char* target, unsigned long count, size_t size);
extern void cmd_ttcp(int argc, char **argv);
extern void cmd_tcp(int argc, char **argv);
extern void cmd_udp(int argc, char **argv);
static void cmd_help(int argc, char **argv);
extern void ttcp_test(int test_mode);

void httpd_ssi_init(void);
void httpd_cgi_init(void);
#define ENABLE_DHCP_CONFIG_IP
#if 1
#include "lwip/api.h"
_os_task  tcp_task_tcb;

uint8 tcp_buf[2048];

void tcp_test_task(void *arg)
{
    struct tcp_pcb *pcb;
    struct netconn *conn;
    struct netconn *conn_new;
    struct netbuf * buf;
    err_t err;

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
    memset(tcp_buf, 0x55, 2048);
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

void tcp_test_init(void)
{
    freertos_create_task(&tcp_task_tcb,"tcp_test_task",256*4,0,120, tcp_test_task, NULL);
}

_os_task  tcp_output_task_tcb;

void udp_test_output_task(void *arg)
{
    struct tcp_pcb *pcb;
    struct netconn *conn;
    struct netconn *conn_new;
    struct netbuf * buf;
    err_t err;

    struct sockaddr_in remote;
    int s, ret, i;
    char sendbuf[] = "udp client test!\n";
    int broadcast = 1;

    s = socket(AF_INET, SOCK_DGRAM, 0);
    printf("tcp_test_output_task\n");
    while(1)
    {
        freertos_msleep(100);

        memset(&remote, 0, sizeof(remote));
        remote.sin_family = AF_INET;
        remote.sin_port = htons(8080);
        remote.sin_addr.s_addr = inet_addr("255.255.255.255");
        // enable BROADCAST
        setsockopt(s, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast));
        ret = sendto(s, sendbuf, sizeof(sendbuf), 0, (struct sockaddr *)&remote, sizeof(remote));
        if (ret > 0)
            printf("\nsend %d data!\n", ret);
    }
    close(s);

}

void udp_test_output_init(void)
{
    freertos_create_task(&tcp_output_task_tcb,"tcp_test_output",256*4,0,WIFI_DEFUALT_TASK_PRIO+7, udp_test_output_task, NULL);
}
_os_task  tcp_receive_task_tcb;
void udp_test_receive_task(void *arg)
{
    struct sockaddr_in local, remote;
    int s, len;
    char recvbuf[1024]= {0}, sendbuf[60]= {0};
    int ret, strlen;
    int broadcast = 1;

    printf("\nEnter socket udp server demo\n");

    memset(&local, 0, sizeof(local));
    local.sin_family = AF_INET;
    local.sin_addr.s_addr = htons(INADDR_ANY);
    local.sin_port = htons(8080);

    s = socket(AF_INET, SOCK_DGRAM, 0);
    bind(s, (struct sockaddr *)&local, sizeof(struct sockaddr_in));
    setsockopt(s, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast));
    while (1)
    {
        len = sizeof(struct sockaddr_in);
        ret = recvfrom(s, recvbuf, 1024, 0, (struct sockaddr *)&remote, &len);
        printf("\nrecv data:%s\n", recvbuf);

        //strlen = sprintf(sendbuf, "recv data:%s\n", recvbuf);
        //sendto(s, sendbuf, strlen, 0, (struct sockaddr *)&remote, len);
    }
    close(s);

}

void udp_test_receive(void)
{
    freertos_create_task(&tcp_receive_task_tcb,"tcp_test_receive",256*4,0,WIFI_DEFUALT_TASK_PRIO+7, udp_test_receive_task, NULL);
}
static void cmd_wifi_open(int argc, char **argv)
{
    wifi_netlink_ops.open_dev_func(p_wifi_netlink);
}

static void cmd_wifi_close(int argc, char **argv)
{
    wifi_netlink_ops.close_dev_func(p_wifi_netlink);

    dhcp_client_stop();
}
static void cmd_wifi_scan(int argc, char **argv)
{
    int   err;
    char msg_ptr[20];
    int msg_size = 0;
    WIFI_MESSAGE_T  *p_wifi_msg = NULL;

    printf("WiFi State: Scanning....!\n");

    xQueueReset(wifi_event_queue_handle);
    wifi_netlink_ops.set_scan_func(p_wifi_netlink);
    err = xQueueReceive(wifi_event_queue_handle, msg_ptr, portMAX_DELAY);
    if (err == pdTRUE)
    {
        if (msg_ptr != NULL)
        {
            p_wifi_msg = (WIFI_MESSAGE_T *) msg_ptr;
            if (p_wifi_msg->msg_type == WIFI_MESSAGE_NOTIFY_SCAN_RESULT_SUCC)
            {
                freertos_msleep(10);
                //get scan list
                wifi_netlink_ops.get_scan_list_func(p_wifi_netlink);
            }
        }
    }
    else
    {
        DEBUGPRINT("WIFI_TEST_STATE_SCANNING: OSTaskQPend error!\n");
    }
}

static void cmd_wifi_connect(int argc, char **argv)
{
    int   err;
    int err_status = 0;
    int  i;
    uint8 *ssid;
    uint8 *password;
    char msg_ptr[20];
    int msg_size = 0;
    WIFI_MESSAGE_T  *p_wifi_msg = NULL;
    if(argc == 2)
    {
        ssid = (uint8 *)argv[1];
        password = NULL;
        DEBUGPRINT("ssid:%s\n",ssid);
    }
    else if(argc == 3)
    {
        ssid = (uint8 *)argv[1];
        password = (uint8 *)argv[2];
        DEBUGPRINT("ssid:%s\n",ssid);
        DEBUGPRINT("password:%s\n",password);
    }
    else
    {
        DEBUGPRINT("\n\rUsage: wifi_connect SSID [PASSWORD]");
        return;
    }
    printf("!!!WiFi State: Connecting...\n");
    err_status = wifi_netlink_ops.connect_req_func(p_wifi_netlink, ssid, password);
    if (err_status == 0)
    {
        err = xQueueReceive(wifi_event_queue_handle, msg_ptr, portMAX_DELAY);
        if ((err == pdTRUE) && (msg_ptr != NULL))
        {
            p_wifi_msg = (WIFI_MESSAGE_T *) msg_ptr;
            if (p_wifi_msg->msg_type == WIFI_MESSAGE_INDICATE_CONNECT)
            {
                DEBUGPRINT("WIFI_CONNECT: connected!\n");
                netifapi_dhcp_start(&wifi_netif);
                for (i=0; i < 300; i++)
                {
                    freertos_msleep(100);
                    if (wifi_netif.dhcp->state == DHCP_BOUND)
                    {
                        dhcp_ip_got = TRUE;
                        wifi_netlink_ops.set_ipaddr_func(p_wifi_netlink, (unsigned int *)&wifi_netif.ip_addr);
                        break;
                    }
                }
                DEBUGPRINT("WIFI_CONNECT: ip configured, IP: %s\n", ip_ntoa(&wifi_netif.ip_addr));
            }
            else if (p_wifi_msg->msg_type == WIFI_MESSAGE_INDICATE_DISCONNECT)
            {
                DEBUGPRINT("WIFI_CONNECT: connect failed!\n");
            }
        }
        else
        {
            DEBUGPRINT("WIFI_CONNECT: OSTaskQPend error!\n");
        }
    }
}

static void cmd_wifi_disconnect(int argc, char **argv)
{
    //disconnect req
    wifi_netlink_ops.disconnect_req_func(p_wifi_netlink);

    dhcp_client_stop();
}
static void cmd_wifi_status(int argc, char **argv)
{
    uint8 *mac = (uint8 *)wifi_netif.hwaddr;
    uint8 *ip = (uint8 *)&wifi_netif.ip_addr;
    uint8 *gw = (uint8 *)&wifi_netif.gw;

    wifi_netlink_ops.get_status_func(p_wifi_netlink);

    DEBUGPRINT("\n\rNetwork Interface Status");
    DEBUGPRINT("\n\r==============================");
    DEBUGPRINT("\n\rMAC:		[%02x:%02x:%02x:%02x:%02x:%02x]", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    DEBUGPRINT("\n\rIP:		[%d.%d.%d.%d]", ip[0], ip[1], ip[2], ip[3]);
    DEBUGPRINT("\n\rGW:		[%d.%d.%d.%d]\n\r", gw[0], gw[1], gw[2], gw[3]);
}

static void cmd_wifi_rssi(int argc, char **argv)
{
    DEBUGPRINT("\n\rwifi_rssi: command not supported yet");
}

static void cmd_wifi_ap(int argc, char **argv)
{
    struct ip_addr ipaddr;
    struct ip_addr netmask;
    struct ip_addr gw;
    uint8 ssid[32+1];
    uint8 password[32+1];

    memset(ssid,0,33);
    memset(password,0,33);
    if(argc == 2)
    {
        memcpy(ssid, (uint8 *)argv[1], strlen((const char *)argv[1])+1);
        memcpy(password, CONFIG_SOFTAP_PASSWORD, strlen(CONFIG_SOFTAP_PASSWORD)+1);
    }
    else if(argc == 3)
    {
        memcpy(ssid, (uint8 *)argv[1], strlen((const char *)argv[1])+1);
        memcpy(password, (uint8 *)argv[2], strlen((const char *)argv[2])+1);
    }
    else
    {
        DEBUGPRINT("\n\rUsage: wifi_ap SSID [PASSWORD]");
        return;
    }
    dhcp_client_stop();

    IP4_ADDR(&ipaddr, 192, 168, 237, 1);
    IP4_ADDR(&netmask, 255, 255, 255, 0);
    IP4_ADDR(&gw, 192, 168, 237, 1);

    netif_set_addr(&wifi_netif, &ipaddr, &netmask, &gw);

    wifi_netlink_ops.start_ap_func(p_wifi_netlink, ssid, password);

    dhcpd_daemon();

}

static void cmd_wifi_mem(int argc, char **argv)
{
    wifi_netlink_ops.get_memory_func(p_wifi_netlink);
}

static void cmd_ping(int argc, char **argv)
{
    if(argc == 2)
    {
        //ping_entry(argv[1], 5, 120);
        do_ping_test(argv[1], 120, 4, 2);
    }
    else if(argc == 3)
    {
        //ping_entry(argv[1], atoi(argv[2]), 120);
        do_ping_test(argv[1], 120, atoi(argv[2]), 2);
    }
    else if (argc == 4)
    {
        do_ping_test(argv[1], atoi(argv[3]), atoi(argv[2]), 2);
        //ping_entry(argv[1], atoi(argv[2]), atoi(argv[3]));
    }
    else
    {
        DEBUGPRINT("\n\rUsage: ping IP [COUNT] [LENGTH]");
    }
}

static void cmd_exit(int argc, char **argv)
{
    DEBUGPRINT("\n\rLEAVE COMMAND TEST MODE");
    exit_cmd_mode = 1;
}

void cmd_wifi_tcp_server(void *arg)
{
    struct tcp_pcb *pcb;
    struct netconn *conn;
    struct netconn *conn_new;
    struct netbuf * buf;
    err_t err;

    conn = netconn_new(NETCONN_TCP);
    if(conn == NULL)
    {
        printf("netconn_new alloc fail\n");

        while(1)
        {
            freertos_msleep(100);
        }
    }

    netconn_bind(conn , IP_ADDR_ANY, 5001);

    netconn_listen(conn);

    netconn_accept(conn, &conn_new);
    memset(tcp_buf, 0x55, 2048);
    while(1)
    {
        if(netconn_recv(conn_new, &buf) == 0)
        {
            netbuf_delete(buf);
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
void cmd_wifi_tcp_client(void *p_arg)
{
    struct tcp_pcb *pcb;
    struct netconn *conn;
    struct netconn *conn_new;
    struct netbuf * buf;
    err_t err;
    struct ip_addr ipaddr;
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
    IP4_ADDR(&ipaddr,192,168,1,107);
    netconn_connect(conn, &ipaddr, 5001);
    printf("netconn_connect\n");
    memset(tcp_buf, 0x55, 2048);
    while(1)
    {
        if(netconn_write(conn, tcp_buf, 1460, NETCONN_COPY) == ERR_OK)
        {

        }
        else
        {
            printf("netconn_close\n");
            netconn_close(conn);
            netconn_delete(conn);
            conn = netconn_new(NETCONN_TCP);
            netconn_bind(conn , IP_ADDR_ANY, 90);
            IP4_ADDR(&ipaddr,192,168,1,100);
            netconn_connect(conn, &ipaddr, 90);

            printf("netconn_connect\n");
        }
        rkos_delay(1);
    }

}

#endif

extern unsigned char *FwImgArray;
static void wifi_init_main(void)
{
    uint8 spitestbuf[50];
    printf("lwip_test_main\n");
    printf("total memory = %d\n", rkos_GetFreeHeapSize());
    wifi_spi_init();

//    memset(spitestbuf, 0, 50);

//    spitestbuf[0]= 0x0f;
//    spitestbuf[0]= 0x00;
//    spitestbuf[0]= 0x00;
//    spitestbuf[0]= 0x00;
//
#if 0
//    while(1)
//    {
//        SPISetRwMode(0,0);
//        SPISetRwMode(0,1);
//    }
    while(1)
    {
        spitestbuf[0]= 0x0f;
        spitestbuf[1]= 0x00;
        spitestbuf[2]= 0x00;
        spitestbuf[3]= 0x00;

//        spitestbuf[0]= 0x0f;
//        spitestbuf[1]= 0x04;
//        spitestbuf[2]= 0x04;
//        spitestbuf[3]= 0x10;

        wifi_spi_ctl_bus(1);
        wifi_spi_tx( spitestbuf, 4);
        memset(spitestbuf, 0, 50);
        wifi_spi_rx( spitestbuf, 4);
        if(spitestbuf[0] != 0x40 || spitestbuf[1] != 0x40 || spitestbuf[2] != 0x40 ||spitestbuf[3] != 0x00)
        {
            printf("read reg fail\n");
        }
        else
        {
            printf("read reg ok\n");
        }
        wifi_spi_rx( spitestbuf, 4);
        wifi_spi_rx( spitestbuf, 4);
        wifi_spi_ctl_bus(0);
        rkos_sleep(10);
    }
#endif

    printf("lwip_my_init\n");
    SEGMENT_INFO_T stCodeInfo;
    int loadAddr;
    int patchcodeLen;
    char * FwImgArray_backup;
    int ret = FW_GetSegmentInfo(SEGMENT_ID_WIFI_FIRMAVE_RKI6000, &stCodeInfo);
    if (ret)
    {

    }
    loadAddr = stCodeInfo.CodeLoadBase;
    patchcodeLen = stCodeInfo.CodeImageLength;
    FwImgArray = (void *)freertos_malloc(patchcodeLen);
    FwImgArray_backup = FwImgArray;
    printf("patchcodeLen = %d\n",patchcodeLen);
    FW_ReadFirmwaveByByte(loadAddr, FwImgArray, patchcodeLen);
    lwip_i6000_init();
    printf("exti_init\n");
    exti_init();
    printf("led_test_init\n");
    //led_test_init();
    freertos_mfree(FwImgArray_backup, patchcodeLen);
    printf("wifi_main\n");
    printf("total memory = %d\n", rkos_GetFreeHeapSize());

}

#endif


//#ifdef _USE_SHELL_
#ifdef _I6000_WIFI_SHELL_
_ATTR_I6000_SHELL_
SHELL_CMD ShellI6000WifiName[] =
{
    "open",NULL,"NULL","NULL",
    "close",NULL,"NULL","NULL",
    "broadcast",NULL,"NULL","NULL",
    "receive",NULL,"NULL","NULL",
    "help",NULL,"NULL","NULL",
    "wifi_init",NULL,"NULL","NULL",
    "wifi_open",NULL,"NULL","NULL",
    "wifi_close",NULL,"NULL","NULL",
    "wifi_scan",NULL,"NULL","NULL",
    "wifi_connect",NULL,"NULL","NULL",
    "wifi_disconnect",NULL,"NULL","NULL",
    "wifi_status",NULL,"NULL","NULL",
    "wifi_rssi",NULL,"NULL","NULL",
    "wifi_ap",NULL,"NULL","NULL",
    "wifi_mem",NULL,"NULL","NULL",
    "ping",NULL,"NULL","NULL",
    "ttcp",NULL,"NULL","NULL",
    "tcp",NULL,"NULL","NULL",
    "udp",NULL,"NULL","NULL",
    "exit",NULL,"NULL","NULL",
    "usage_start",NULL,"NULL","NULL",
    "usage_stop",NULL,"NULL","NULL",
#if CONFIG_INTERNAL_DEBUG
    "wifi_rmac",NULL,"NULL","NULL",
    "wifi_wmac",NULL,"NULL","NULL",
    "wifi_rphy",NULL,"NULL","NULL",
    "wifi_wphy",NULL,"NULL","NULL",
    "wifi_set_channel",NULL,"NULL","NULL",
    "wifi_set_rate",NULL,"NULL","NULL",
    "wifi_enable_ps",NULL,"NULL","NULL",
    "wifi_disable_ps",NULL,"NULL","NULL",
#endif
    "\b",NULL,"NULL","NULL",
};
typedef enum
{
    //system message
    I6000_CMD_OPEN = (UINT32)0x00,
    I6000_CMD_CLOSE,
    I6000_CMD_BROADCAST,
    I6000_CMD_RECEIVE,
    I6000_CMD_HELP,
    I6000_CMD_WIFI_INIT,
    I6000_CMD_WIFI_OPEN,
    I6000_CMD_WIFI_CLOSE,
    I6000_CMD_WIFI_SCAN,
    I6000_CMD_WIFI_CONNECT,
    I6000_CMD_WIFI_DISCONNECT,
    i6000_CMD_WIFI_STATUS,
    i6000_CMD_WIFI_RSSI,
    i6000_CMD_WIFI_AP,
    i6000_CMD_WIFI_MEM,
    i6000_CMD_WIFI_PING,
    i6000_CMD_WIFI_TTCP,
    i6000_CMD_WIFI_TCP,
    i6000_CMD_WIFI_UDP,
    i6000_CMD_WIFI_EXIT,
    i6000_CMD_USAGE_START,
    i6000_CMD_USAGE_STOP,
#if CONFIG_INTERNAL_DEBUG
    i6000_CMD_WIFI_RMAC,
    i6000_CMD_WIFI_WMAC,
    i6000_CMD_WIFI_RPHY,
    i6000_CMD_WIFI_WPHY,
    i6000_CMD_WIFI_SET_CHANNEL,
    i6000_CMD_WIFI_RATE,
    i6000_CMD_WIFI_ENABLE_PS,
    i6000_CMD_WIFI_DISABLE_PS,
#endif
} I6000_CMD;


#if CONFIG_INTERNAL_DEBUG
static void cmd_wifi_rmac(int argc, char **argv)
{
    char *endptr = NULL;
    uint32 read_addr = 0;

    if(argc == 2)
    {
        read_addr = (uint32)strtol((const char *)argv[1], &endptr, 16);
        if (*endptr == '\0')
        {
            wifi_netlink_ops.read_mac_reg(p_wifi_netlink, read_addr);
        }
        else
        {
            DEBUGPRINT("\n\rwifi_rmac: invalid address");
        }
    }
    else
    {
        DEBUGPRINT("\n\rUsage: wifi_rmac ADDR");
    }
}

static void cmd_wifi_wmac(int argc, char **argv)
{
    char *endptr = NULL;
    uint32 write_addr = 0;
    uint32 write_value = 0;

    if(argc == 3)
    {
        write_addr = (uint32)strtol((const char *)argv[1], &endptr, 16);
        if (*endptr != '\0')
        {
            DEBUGPRINT("\n\rwifi_wmac: invalid address");
        }
        else
        {
            write_value = (uint32)strtol((const char *)argv[2], &endptr, 16);
            if (*endptr != '\0')
            {
                DEBUGPRINT("\n\rwifi_wmac: invalid write value");
            }
            else
            {
                wifi_netlink_ops.write_mac_reg(p_wifi_netlink, write_addr, write_value);
            }
        }
    }
    else
    {
        DEBUGPRINT("\n\rUsage: wifi_wmac ADDR VALUE");
    }
}

static void cmd_wifi_rphy(int argc, char **argv)
{
    char *endptr = NULL;
    uint32 read_addr = 0;

    if(argc == 2)
    {
        read_addr = (uint32)strtol((const char *)argv[1], &endptr, 16);
        if (*endptr == '\0')
        {
            wifi_netlink_ops.read_phy_reg(p_wifi_netlink, read_addr);
        }
        else
        {
            DEBUGPRINT("\n\rwifi_rphy: invalid address");
        }
    }
    else
    {
        DEBUGPRINT("\n\rUsage: wifi_rphy ADDR");
    }
}

static void cmd_wifi_wphy(int argc, char **argv)
{
    char *endptr = NULL;
    uint32 write_addr = 0;
    uint32 write_value = 0;

    if(argc == 3)
    {
        write_addr = (uint32)strtol((const char *)argv[1], &endptr, 16);
        if (*endptr != '\0')
        {
            DEBUGPRINT("\n\rwifi_wphy: invalid address");
        }
        else
        {
            write_value = (uint32)strtol((const char *)argv[2], &endptr, 16);
            if (*endptr != '\0')
            {
                DEBUGPRINT("\n\rwifi_wphy: invalid write value");
            }
            else
            {
                wifi_netlink_ops.write_phy_reg(p_wifi_netlink, write_addr, write_value);
            }
        }
    }
    else
    {
        DEBUGPRINT("\n\rUsage: wifi_wphy ADDR VALUE");
    }
}

static void cmd_wifi_set_channel(int argc, char **argv)
{
    char *endptr = NULL;
    uint32 channel = 0;

    if(argc == 2)
    {
        channel = (uint32)strtol((const char *)argv[1], &endptr, 10);
        if (*endptr == '\0')
        {
            wifi_netlink_ops.set_channel(p_wifi_netlink, channel);
        }
        else
        {
            DEBUGPRINT("\n\rwifi_set_channel: invalid channel");
        }
    }
    else
    {
        DEBUGPRINT("\n\rUsage: wifi_set_channel CHANNEL");
    }
}

static void cmd_wifi_set_rate(int argc, char **argv)
{
    char *endptr = NULL;
    uint32 rate = 0;

    if(argc == 2)
    {
        rate = (uint32)strtol((const char *)argv[1], &endptr, 10);
        if (*endptr == '\0')
        {
            wifi_netlink_ops.set_rate(p_wifi_netlink, rate);
        }
        else
        {
            DEBUGPRINT("\n\rwifi_set_rate: invalid rate");
        }
    }
    else
    {
        DEBUGPRINT("\n\rUsage: wifi_set RATE");
    }
}

static void cmd_wifi_enable_ps(int argc, char **argv)
{
    wifi_netlink_ops.enable_ps(p_wifi_netlink);
}

static void cmd_wifi_disable_ps(int argc, char **argv)
{
    wifi_netlink_ops.disable_ps(p_wifi_netlink);
}

#endif
/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local function(shell) define
*
*---------------------------------------------------------------------------------------------------------------------
*/
extern void (*pIdleFun)(void);
extern void (*pIdleFunSave)(void);

static unsigned int total_cnt = 0;
static unsigned int run_cnt = 0;
static unsigned int usage_tick;
#define STAT_INTERVAL 100
static void cpu_usage_rate_func(void)
{
    unsigned int tick;
    if(total_cnt == 0)
    {
        vTaskSuspendAll();
        usage_tick = SysTickCounter;
        while(SysTickCounter <= usage_tick)
        {
            break;
        }
        usage_tick = SysTickCounter;
        while(1)
        {
            total_cnt++;
            if(SysTickCounter > usage_tick+STAT_INTERVAL)
            {
                break;
            }
        }
        xTaskResumeAll();
        usage_tick = SysTickCounter;
        run_cnt = 0;
        printf("total_cnt = %d\n",total_cnt);
    }
    else
    {
        usage_tick = SysTickCounter;
        run_cnt = 0;
        while(SysTickCounter <= usage_tick)
        {
            break;
        }
        usage_tick = SysTickCounter;
        while(1)
        {
            run_cnt++;
            if(SysTickCounter > usage_tick+STAT_INTERVAL)
            {
                vTaskSuspendAll();
                if(run_cnt> total_cnt)
                    run_cnt = total_cnt;
                float rate_temp = ((float)(total_cnt-run_cnt))/total_cnt;
                //printf("run_cnt =%d,total_cnt =%d\n",run_cnt, total_cnt);
                printf("cpu usage rate %f\n",rate_temp);
                run_cnt = 0;
                usage_tick = SysTickCounter;
                xTaskResumeAll();
                break;
            }
        }

    }
}

static void cpu_usage_rate_start(void)
{
    total_cnt= 0;
    pIdleFunSave = pIdleFun;
    pIdleFun =  cpu_usage_rate_func;
}

static void cpu_usage_rate_end(void)
{
    pIdleFun = pIdleFunSave;
    total_cnt = 0;
}

/******************************************************************************
 * I6000WifiShellHelp -
 * DESCRIPTION: -
 *
 * Input:
 * Output:
 * Returns:
 *
 * modification history
 * --------------------
 * Owner: wangping
 * Date : 2015.5.30  written
 * Time : 11:29:59
 * --------------------
 ******************************************************************************/
_ATTR_I6000_SHELL_
SHELL FUN rk_err_t I6000WifiShellHelp(HDC dev, uint8 * pstr)
{
    pstr--;

    //if (StrLenA(pstr) != 0)
    //    return RK_ERROR;

    printf("i6000 command list:\r\n");
    printf("help:      show help information\r\n");
    printf("wifi_init: wifi init ,run it before other cmd\r\n");
    printf("wifi_open \r\n");
    printf("wifi_scan\r\n");
    printf("wifi_connect\r\n");
    printf("wifi_disconnect\r\n");
    printf("wifi_status\r\n");
    printf("wifi_rssi\r\n");
    printf("wifi_ap\r\n");
    printf("wifi_mem\r\n");
    printf("ping\r\n");
    printf("tcp\r\n");
    printf("ttcp\r\n");
    printf("tcp\r\n");
    printf("udp\r\n");
    return RK_SUCCESS;
}

_ATTR_I6000_SHELL_
int parse_cmd_arg(uint8 * pItem, char **argv)
{
    int argc = 1;
    int i, j;
    i = 0;
    while (pItem[i] != NULL)
    {
        if (pItem[i] == ' ')
            argc++;
        ++i;
    }
    //printf("\nargc=%d\n", argc);
    i = 0;
    j = 1;
    for (j = 0; j < argc; ++j)
    {
        argv[j] = pItem + i;
        while(pItem[i] != '\0' && pItem[i] != ' ') ++i;
        pItem[i++] = '\0';
        //printf("argv[%d]=%s\n", j, argv[j]);
    }
    return argc;
}
/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   API(shell) define
*
*---------------------------------------------------------------------------------------------------------------------
*/

/******************************************************************************
 * i6000_wifi_dev_shell -
 * DESCRIPTION: -
 *
 * Input:
 * Output:
 * Returns:
 *
 * modification history
 * --------------------
 * Owner: wangping
 * Date : 2015.5.30  written
 * Time : 11:29:01
 * --------------------
 ******************************************************************************/
#define MAX_ARGC 20
_ATTR_I6000_SHELL_
SHELL API rk_err_t i6000_wifi_dev_shell(HDC dev, uint8 * pstr)
{
    uint32 i = 0, j = 0, k = 0;
    uint8  *pItem;
    uint16 StrCnt = 0;
    rk_err_t   ret;
    uint8 Space;
    int argc;
    char *argv[MAX_ARGC];

    StrCnt = ShellItemExtract(pstr, &pItem, &Space);
    if (StrCnt == 0)
    {
        return RK_ERROR;
    }
    argc = parse_cmd_arg(pItem,argv);
    //printf("argc = %d\n",argc);
    ret = ShellCheckCmd(ShellI6000WifiName, pItem, StrCnt);
    if (ret < 0)
    {
        return RK_ERROR;
    }
    i = (uint32)ret;

    pItem += StrCnt;
    pItem++;
    ret = 0;
    switch (i)
    {
        case I6000_CMD_OPEN:
#ifdef __DRIVER_I6000_WIFI_C__
        wifi_app_start();
#endif
            break;

        case I6000_CMD_CLOSE:
            Grf_GpioMuxSet(GPIO_CH1, GPIOPortB_Pin2, 0);  // wifi en
            Gpio_SetPinDirection(GPIO_CH1, GPIOPortB_Pin2, GPIO_OUT);

            Grf_GPIO_SetPinPull(GPIO_CH1, GPIOPortB_Pin2, DISABLE);
            Gpio_SetPinLevel(GPIO_CH1, GPIOPortB_Pin2, GPIO_LOW);
            Grf_GpioMuxSet(GPIO_CH1, GPIOPortA_Pin5, 0); // cs
            Gpio_SetPinDirection(GPIO_CH1, GPIOPortA_Pin5, GPIO_OUT);
            Gpio_SetPinLevel(GPIO_CH1, GPIOPortA_Pin5, GPIO_LOW);
            Grf_GPIO_SetPinPull(GPIO_CH1, GPIOPortA_Pin5, DISABLE);
            Grf_GpioMuxSet(GPIO_CH2, GPIOPortA_Pin2, 0);  // wifi rst
            Gpio_SetPinDirection(GPIO_CH2, GPIOPortA_Pin2, GPIO_OUT);
            Gpio_SetPinLevel(GPIO_CH2, GPIOPortA_Pin2, GPIO_LOW);
            Grf_GPIO_SetPinPull(GPIO_CH2, GPIOPortA_Pin2, DISABLE);
            Grf_GpioMuxSet(GPIO_CH1, GPIOPortB_Pin0, 0);
            Gpio_SetPinDirection(GPIO_CH1, GPIOPortB_Pin0, GPIO_OUT);
            Gpio_SetPinLevel(GPIO_CH1, GPIOPortB_Pin0, GPIO_LOW);
            Grf_GpioMuxSet(GPIO_CH1, GPIOPortA_Pin6, 0);
            Gpio_SetPinDirection(GPIO_CH1, GPIOPortA_Pin6, GPIO_OUT);
            Gpio_SetPinLevel(GPIO_CH1, GPIOPortA_Pin6, GPIO_LOW);
            Grf_GpioMuxSet(GPIO_CH1, GPIOPortA_Pin7, 0);
            Gpio_SetPinDirection(GPIO_CH1, GPIOPortA_Pin7, GPIO_OUT);
            Gpio_SetPinLevel(GPIO_CH1, GPIOPortA_Pin7, GPIO_LOW);

            Grf_GpioMuxSet(GPIO_CH2, GPIOPortA_Pin0, 0);
            Gpio_SetPinDirection(GPIO_CH2, GPIOPortA_Pin0, GPIO_OUT);
            Gpio_SetPinLevel(GPIO_CH2, GPIOPortA_Pin0, GPIO_LOW);
            break;

        case I6000_CMD_BROADCAST:
            udp_test_output_init();
            break;

        case I6000_CMD_RECEIVE:
            udp_test_receive();
            break;

        case I6000_CMD_HELP:
            ret = I6000WifiShellHelp(dev,pItem);
            break;
        case I6000_CMD_WIFI_INIT:
#ifdef __DRIVER_I6000_WIFI_C__
            FREQ_EnterModule(FREQ_BLON);
            FREQ_EnterModule(FREQ_INIT);
            FW_LoadSegment(SEGMENT_ID_I6000_WIFI, SEGMENT_OVERLAY_ALL);
            FW_LoadSegment(SEGMENT_ID_I6000_WIFI2, SEGMENT_OVERLAY_ALL);
            FW_LoadSegment(SEGMENT_ID_LWIP, SEGMENT_OVERLAY_ALL);
            FW_LoadSegment(SEGMENT_ID_LWIP_API, SEGMENT_OVERLAY_ALL);
            FW_LoadSegment(SEGMENT_ID_HTTP, SEGMENT_OVERLAY_ALL);
            FW_LoadSegment(SEGMENT_ID_HTTPD, SEGMENT_OVERLAY_ALL);
#endif

            wifi_init_main();
            p_wifi_netlink = wifi_netlink_ops.init_func();
            break;
        case I6000_CMD_WIFI_OPEN:
            cmd_wifi_open(argc,argv);
            break;

        case I6000_CMD_WIFI_CLOSE:
            cmd_wifi_close(argc, argv);
            break;

        case I6000_CMD_WIFI_SCAN:
            cmd_wifi_scan(argc, argv);
            ret = 0;
            break;

        case I6000_CMD_WIFI_CONNECT:
            cmd_wifi_connect(argc, argv);
            break;

        case I6000_CMD_WIFI_DISCONNECT:
            //disconnect req
            cmd_wifi_disconnect(argc,argv);
            break;

        case i6000_CMD_WIFI_STATUS:
            cmd_wifi_status(argc, argv);
            ret = 0;
            break;

        case i6000_CMD_WIFI_RSSI:
            DEBUGPRINT("\n\rwifi_rssi: command not supported yet");
            ret = 0;
            break;

        case i6000_CMD_WIFI_AP:
            cmd_wifi_ap(argc, argv);
            ret = 0;
            break;
        case i6000_CMD_WIFI_MEM:
            //wifi_mem
            cmd_wifi_mem(argc, argv);
            ret = 0;
            break;
        case i6000_CMD_WIFI_PING:
            //ping
            cmd_ping(argc, argv);
            break;
        case i6000_CMD_WIFI_TTCP:
            printf("receive mode  : ttcp r [length] , ex: ttcp r 1024 ; default port = 5001\r\n");
            printf("transmit mode : ttcp t [length] [number] [ip], ex: ttcp t 1024 2048 192.168.1.2 ; default port = 5002\r\n");
            printf("r + t mode    : ttcp rt [length] [number] [ip], ex: ttcp rt 1024 2048 192.168.1.2\r\n");
            cmd_ttcp(argc, argv);
            break;
        case i6000_CMD_WIFI_TCP:
            cmd_tcp(argc, argv);
            break;
        case i6000_CMD_WIFI_UDP:
            // udp
            cmd_udp(argc, argv);
            break;
        case i6000_CMD_WIFI_EXIT:
            // exit
            break;
#if CONFIG_INTERNAL_DEBUG
        case i6000_CMD_WIFI_RMAC:
            // wifi_rmac
            cmd_wifi_rmac(argc, argv);
            break;
        case i6000_CMD_WIFI_WMAC:
            // wifi_wmac
            cmd_wifi_wmac(argc, argv);
            break;
        case i6000_CMD_WIFI_RPHY:
            // wifi_rphy
            cmd_wifi_rphy(argc, argv);
            break;
        case i6000_CMD_WIFI_WPHY:
            // wifi_wphy
            cmd_wifi_wphy(argc, argv);
            break;
        case i6000_CMD_WIFI_SET_CHANNEL:
            // wifi_set_channel
            cmd_wifi_set_channel(argc, argv);
            break;
        case i6000_CMD_WIFI_RATE:
            // wifi_set_rate
            cmd_wifi_set_rate(argc, argv);
            break;
        case i6000_CMD_WIFI_ENABLE_PS:
            // wifi_enable_ps
            cmd_wifi_enable_ps(argc, argv);
            break;
        case i6000_CMD_WIFI_DISABLE_PS:
            // wifi_disable_ps
            cmd_wifi_disable_ps(argc, argv);
            break;
        case i6000_CMD_USAGE_START:
            cpu_usage_rate_start();
            break;

        case i6000_CMD_USAGE_STOP:
            cpu_usage_rate_end();
            break;
#endif
        default:
            ret = RK_ERROR;
            break;
    }
    return ret;

}
#endif /*_I6000_SHELL_*/

//#pragma arm section code
#endif /*#ifdef __DRIVER_I6000_WIFI_C__*/
