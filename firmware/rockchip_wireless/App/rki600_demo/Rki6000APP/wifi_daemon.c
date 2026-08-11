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
#ifdef __DRIVER_I6000_WIFI_C__


#define LCD_ShowString(a,b,c,d,e,f)
#define command_test_mode()
#define ENABLE_DHCP_CONFIG_IP
#ifdef __WIFI_DLNA_C__
#define ENABLE_RUN_DLAN
#endif
//#define ENABLE_RK_WIFI_CONFIG

#define WIFI_SEND_EVENT(event_type,parameter, param_size,err)        \
    if( wifi_event_handler != NULL)                                  \
    {                                                                \
        wifi_event_handler(event_type, parameter, param_size,err);   \
    }



uint8 need_do_dhcp = TRUE;
uint8 lwip_init_wifi = 0;
uint8 exit_cmd_mode = 0;
static uint8 g_wlan_mac_addr[6] = {0x76,0xba,0xed,0xaa,0xbb,0xcc};
uint8  dhcp_ip_got = FALSE;
void (* wifi_event_handler)(uint32 event_type, void *parameter, uint32 param_size,err_t err);

extern WIFI_NETLINK_INFO_T *p_wifi_netlink;
extern uint8  dhcp_ip_got;
extern struct netif wifi_netif;
extern WIFI_NETLINK_OPERATIONS_T wifi_netlink_ops;
extern _os_task  wifi_daemon_task_tcb;

extern void dhcpd_daemon(void);
extern void ping_entry(char* target, unsigned long count, size_t size);
extern void cmd_ttcp(int argc, char **argv);
extern void cmd_tcp(char *tcp_type, size_t buffer_size, char *ipaddr);
extern void cmd_udp(int argc, char **argv);
static void cmd_help(int argc, char **argv);
extern void ttcp_test(int test_mode);
err_t rki6000_ethernetif_init(struct netif *netif);
err_t tcpip_input(struct pbuf *p, struct netif *inp);
extern xQueueHandle wifi_event_queue_handle;
void httpd_ssi_init(void);
void httpd_cgi_init(void);


#if 1
#include "lwip/api.h"

void led_test_init(void)
{
    Grf_GpioMuxSet(GPIO_CH2, GPIOPortB_Pin5, 0); // led 1
    Gpio_SetPinDirection(GPIO_CH2, GPIOPortB_Pin5, GPIO_OUT);
    Gpio_SetPinLevel(GPIO_CH2, GPIOPortB_Pin5, GPIO_HIGH);
    Grf_GPIO_SetPinPull(GPIO_CH2, GPIOPortB_Pin5, DISABLE);

    Grf_GpioMuxSet(GPIO_CH2, GPIOPortB_Pin4, 0); // led 2
    Gpio_SetPinDirection(GPIO_CH2, GPIOPortB_Pin4, GPIO_OUT);
    Gpio_SetPinLevel(GPIO_CH2, GPIOPortB_Pin4, GPIO_LOW);
    Grf_GPIO_SetPinPull(GPIO_CH2, GPIOPortB_Pin4, DISABLE);
}

void led_set_onoff(uint id, uint on_off)
{
    if(id == 1)
    {
        if(on_off)
        {
            Gpio_SetPinLevel(GPIO_CH2, GPIOPortB_Pin5, GPIO_LOW);
        }
        else
        {
            Gpio_SetPinLevel(GPIO_CH2, GPIOPortB_Pin5, GPIO_HIGH);
        }
    }
    else if(id == 2)
    {
        if(on_off)
        {
            Gpio_SetPinLevel(GPIO_CH2, GPIOPortB_Pin4, GPIO_HIGH);
        }
        else
        {
            Gpio_SetPinLevel(GPIO_CH2, GPIOPortB_Pin4, GPIO_LOW);
        }
    }
}

_os_task  wifi_state_led_task_tcb;
void wifi_state_led_task(void *arg)
{
    err_t err;
    WIFI_DAEMON_STATE_TYPE_E *state_type = arg;
    int delay_time = 0;
    printf("wifi_state_led_task\n");

    while(1)
    {
        if(*state_type == WIFI_DAEMON_STATE_IP_CONFIGED)
        {
            delay_time = 500;
        }
        else
        {
            delay_time = 50;
        }
        led_set_onoff(2,0);
        freertos_msleep(delay_time);
        led_set_onoff(2,1);
        freertos_msleep(delay_time);
    }


}

void wifi_state_led_task_start(void *arg)
{
    freertos_create_task(&wifi_state_led_task_tcb,"wifi_led",512,0,WIFI_DEFUALT_TASK_PRIO-7, wifi_state_led_task, arg);
}

#include "Bsp.h"
#include "DeviceInclude.h"

_os_task  ad_check_task_tcb;

uint wifi_ad_value = 0;

uint get_ad_value(void)
{
    return wifi_ad_value;
}

void ad_check_output_task(void *arg)
{
    err_t err;
    int adc_channel = 1;
    uint32 temp;
    uint32 adc_val;
    printf("ad_check_output_task\n");
    ScuClockGateCtr(CLK_SARADC_GATE, 1);
    ScuClockGateCtr(PCLK_SARADC_GATE, 1);
    ScuSoftResetCtr(SARADC_SRST, 0);
    SetSarAdcFreq(1000000);        // 1M

    Grf_Set_ADC_Vref_PowerOn(GRF_VREF_PWON);
    Grf_Verf_Trim_Sel(GRF_VREF_TRIM_2500);
    Grf_Verf_Vbg_Sel(GRF_VREF_TRIM_2550);
    adc_channel = 1;
    Adc->ADC_CTRL = adc_channel | ADC_START | ADC_POWERUP;
    while(1)
    {
        adc_val = 0;
        Adc->ADC_CTRL = adc_channel | ADC_START | ADC_POWERUP;
        while(1)
        {
            freertos_msleep(20);
            temp = Adc->ADC_STAS;
            if ((temp & 0x01) == 0)
            {
                break;
            }
        }
        adc_val = (UINT32)(Adc->ADC_DATA);
        wifi_ad_value = adc_val;
        //printf("Adc channel %d read value = %d\n", adc_channel, adc_val);
    }


}

void ad_check_output_init(void)
{
    freertos_create_task(&ad_check_task_tcb,"ad_check_output_task",256*4,0,WIFI_DEFUALT_TASK_PRIO+8, ad_check_output_task, NULL);
}
#endif
#define I6000_DEBUG(format,...)    printf("%s,L:%d:"format"\n", __MODULE__, __LINE__, ##__VA_ARGS__)


void wifi_register_event_handler(
    void (* wifi_event_handler)(uint32 event_type, void *parameter, uint32 param_size,err_t err))
{
    wifi_event_handler = wifi_event_handler;
}

void lwip_i6000_init(void)
{
    struct ip_addr ipaddr;
    struct ip_addr netmask;
    struct ip_addr gw;

    tcpip_init(NULL,NULL);

#ifdef CONFIG_WIFI_SOFTAP_MODE
    IP4_ADDR(&ipaddr, 192, 168, 237, 1);
    IP4_ADDR(&netmask, 255, 255, 255, 0);
    IP4_ADDR(&gw, 192, 168, 237, 1);
#else

#ifdef ENABLE_DHCP_CONFIG_IP
    IP4_ADDR(&ipaddr, 0, 0, 0, 0);
    IP4_ADDR(&netmask, 0, 0, 0, 0);
    IP4_ADDR(&gw, 0, 0, 0, 0);
#else
    //IP4_ADDR(&ipaddr, 192, 168, 1, 60);
    IP4_ADDR(&ipaddr, 192, 168, 1, 80);
    IP4_ADDR(&netmask, 255, 255, 255, 0);
    IP4_ADDR(&gw, 192, 168, 1, 1);
#endif
#endif
    netif_add(&wifi_netif, &ipaddr, &netmask, &gw, NULL, &rki6000_ethernetif_init, &tcpip_input);
    netif_set_default(&wifi_netif);
    /*  When the netif is fully configured this function must be called.*/
    netif_set_up(&wifi_netif);
#if 1
    //tcp_test_init();

#ifdef __WICE_HTTP_SERVER__
    //ad_check_output_init();
    I6000_DEBUG();
    httpd_init();
    I6000_DEBUG();
    httpd_ssi_init();
    I6000_DEBUG();
    httpd_cgi_init();
    I6000_DEBUG();
#endif
#endif
    lwip_init_wifi = 1;
}

static int wifi_connect_flag(void)
{
    return 0;//wifi_link;
}

void dhcp_client_stop(void)
{
    if (dhcp_ip_got)
    {

        netifapi_dhcp_stop(&wifi_netif);
        netifapi_netif_set_down(&wifi_netif);
        memset(&wifi_netif.ip_addr, 0, sizeof(wifi_netif.ip_addr));
        memset(&wifi_netif.gw, 0, sizeof(wifi_netif.gw));
        dhcp_ip_got = FALSE;
    }
}
void wifi_daemon_start()
{
    freertos_create_task(&wifi_daemon_task_tcb,"wifi_daemon_task",256*4*4,0,WIFI_DEFUALT_TASK_PRIO, wifi_daemon_task, NULL);
}

char *wlan_get_user_mac_addr(void)
{
    return g_wlan_mac_addr;
}
extern unsigned char *FwImgArray;
void lwip_i6000_main(void)
{
    uint8 spitestbuf[50];
    printf("lwip_test_main\n");
    printf("total memory = %d\n", rkos_GetFreeHeapSize());
    wifi_spi_init();

#ifdef CONFIG_LCD_SHOW
    LCD_ShowString(60,90,200,16,16,"Init Lwip and WiFi ... ");
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
    wifi_daemon_start();
    printf("total memory = %d\n", rkos_GetFreeHeapSize());

}



#ifdef CONFIG_LCD_SHOW
void LCD_show_scan_list(WIFI_NETLINK_INFO_T *wifi_netlink)
{
    uint8 count = 0;
    int8 buffer[MAX_SSID_LEN+8] = {0};
    WIFISUPP_SCAN_AP_INFO_T *p_scan_list = wifi_netlink->scan_list_head;

//  POINT_COLOR = RED;
    LCD_ShowString(60,180,200,16,16,"[WiFi Scan List:]");

//  POINT_COLOR = BLACK;
    LCD_ShowString(60, 200, 200, 12, 12, "------------------------");

    for (count=0; count<13; count++)
        LCD_ShowString(60, (220+count*20), 240, 12, 12, "                                        ");

    count = 0;
    while (p_scan_list != NULL)
    {
        snprintf((char *)buffer, (p_scan_list->ssid.ssid_len+1), "%s", (char *)&p_scan_list->ssid.ssid);
        switch (p_scan_list->encryp_protocol)
        {
            case WIFISUPP_ENCRYP_PROTOCOL_OPENSYS:
                snprintf(((char *)buffer+p_scan_list->ssid.ssid_len), sizeof(",Open"), ",Open");
                break;
            case WIFISUPP_ENCRYP_PROTOCOL_WEP:
                snprintf(((char *)buffer+p_scan_list->ssid.ssid_len), sizeof(",WEP"), ",WEP");
                break;
            case WIFISUPP_ENCRYP_PROTOCOL_WPA:
                snprintf(((char *)buffer+p_scan_list->ssid.ssid_len), sizeof(",WPA"), ",WPA");
                break;
            case WIFISUPP_ENCRYP_PROTOCOL_WPA2:
                snprintf(((char *)buffer+p_scan_list->ssid.ssid_len), sizeof(",WPA2"), ",WPA2");
                break;
            default:
                snprintf(((char *)buffer+p_scan_list->ssid.ssid_len), sizeof(",Unkwn"), ",Unkwn");
                break;
        }
        LCD_ShowString(60, (220+count*20), 240, 12, 12, (uint8 *)buffer);
        printf("get ap : %s\n", buffer);
        count++;
        if (count >= 13)
            break;
        p_scan_list = p_scan_list->next_ptr;
    }

//  POINT_COLOR = BLUE;
}
#endif

WIFI_USER_ACTION_TYPE_E user_key_trigger_detected()
{
    uint8 key_value;
    WIFI_USER_ACTION_TYPE_E user_action = WIFI_USER_ACTION_MAX;

    return user_action;
}

extern RKI6000_WIFI_SAVEINFO g_wifi_ap_saveinfo;
int wifi_ap_auto_connect(void)
{
    int err_status;
    int err;
    int i;
    char msg_ptr[20];
    WIFI_MESSAGE_T  *p_wifi_msg = NULL;
    i =0;
    wifi_db_rw_lock();
retry_connect0:
    err_status = wifi_netlink_ops.connect_req_func(p_wifi_netlink,
                g_wifi_ap_saveinfo.ap[g_wifi_ap_saveinfo.last_index].ssid_value,
                g_wifi_ap_saveinfo.ap[g_wifi_ap_saveinfo.last_index].key);
    if(err_status == 0)
    {
        goto wait_connect;
    }

retry_connect1:
    for(;i<MAX_WIFI_DB_MUN;i++)
    {
         if(g_wifi_ap_saveinfo.ap[i].ssid_value[0] != 0)
         {
            err_status = wifi_netlink_ops.connect_req_func(p_wifi_netlink,
                g_wifi_ap_saveinfo.ap[i].ssid_value, g_wifi_ap_saveinfo.ap[i].key);
         }

         if(err_status == 0)
         {
            break;
         }
    }

    if(i == MAX_WIFI_DB_MUN)
    {
        wifi_db_rw_unlock();
        return -1;
    }
wait_connect:

    freertos_msleep(10);
    err = xQueueReceive(wifi_event_queue_handle, msg_ptr, portMAX_DELAY);
    if (err == pdTRUE)
    {
        if (msg_ptr != NULL)
        {
            p_wifi_msg = (WIFI_MESSAGE_T *) msg_ptr;
            if (p_wifi_msg->msg_type == WIFI_MESSAGE_INDICATE_CONNECT)
            {
                //state_type = WIFI_DAEMON_STATE_CONNECTED;
            }
            else if (p_wifi_msg->msg_type == WIFI_MESSAGE_INDICATE_DISCONNECT)
            {
                //state_type = WIFI_DAEMON_STATE_DISCONNECTED;

                if(i != MAX_WIFI_DB_MUN)
                    goto retry_connect1;
            }
        }
    }
    else
    {
        DEBUGPRINT("WIFI_DAEMON_STATE_CONNECTING: OSTaskQPend error!\n");
    }


    wifi_db_rw_unlock();

    return 0;
}

void printf_wifi_db(void)
{
    int i;
    printf("\n Rki6000 wifi db num = %d\n", g_wifi_ap_saveinfo.total_num);
    for(i=0;i<MAX_WIFI_DB_MUN;i++)
    {
        if(g_wifi_ap_saveinfo.ap[i].ssid_value[0] != 0)
        {
            printf("\n========================\n");
            printf("ssid =%s\n",g_wifi_ap_saveinfo.ap[i].ssid_value);
            printf("pwd =%s\n",g_wifi_ap_saveinfo.ap[i].key);
            printf("bssid = %02x-%02x-%02x-%02x-%02x-%02x\n",g_wifi_ap_saveinfo.ap[i].bssid[0],
            g_wifi_ap_saveinfo.ap[i].bssid[1],
            g_wifi_ap_saveinfo.ap[i].bssid[2],
            g_wifi_ap_saveinfo.ap[i].bssid[3],
            g_wifi_ap_saveinfo.ap[i].bssid[4],
            g_wifi_ap_saveinfo.ap[i].bssid[5]);
            printf("\n========================\n");
        }
    }
}

#ifdef CONFIG_WIFI_STA_MODE
void  wifi_daemon_task (void *p_arg)
{
#ifdef CONFIG_LCD_SHOW
    int   err;
    char msg_ptr[20];
    int msg_size = 0;
    static WIFI_DAEMON_STATE_TYPE_E state_type = WIFI_DAEMON_STATE_DISCONNECTED;
    WIFI_MESSAGE_T  *p_wifi_msg = NULL;
    WIFI_NETLINK_INFO_T *wifi_netlink = NULL;
    uint32  i;
    WIFI_USER_ACTION_TYPE_E user_action;
    uint8  start_softap_mode = FALSE;
    uint8  err_status = 0;
    int8  buffer[MAX_SSID_LEN+8] = {0};
    int8  need_reconnect = 0;
    int8  smconfig_got = 0;
    wifi_netlink = wifi_netlink_ops.init_func();
    p_wifi_netlink = wifi_netlink;
//  POINT_COLOR = BLUE;

//    wifi_state_led_task_start(&state_type);
    wifi_loaddb_from_disk();
    wifi_init_db();
    if(wifi_get_bd_num())
    {
        goto printf_db;
    }
    #ifdef ENABLE_RK_WIFI_CONFIG

    smartconfig_start();
    int timeout = 3000;
    char sm_ssid[33];
    char sm_pwd[33];
    unsigned char sm_ssid_len = 0;
    unsigned char sm_pwd_len = 0;
    memset(sm_ssid, 0 ,33);
    memset(sm_pwd, 0 ,33);
    memcpy(sm_ssid ,"cpsb-wp-test", 12);
    memcpy(sm_pwd, "123456789",9);
    while(1)
    {
        if(smartconfig_wait_get_info(0, sm_ssid, &sm_ssid_len, sm_pwd, &sm_pwd_len))
        {
            printf("sm_ssid = %s\n", sm_ssid);
            printf("sm_pwd = %s\n", sm_pwd);
            smconfig_got = 1;
            break;
        }
        rkos_delay(10);
        if(timeout-- == 0)
        {
            printf("rk wifi config timeout\n");
            break;

        }
    }
    smartconfig_stop();
    #endif /*ENABLE_RK_WIFI_CONFIG*/
printf_db:
    printf_wifi_db();
    for (;;)
    {

        switch (state_type)
        {

            case WIFI_DAEMON_STATE_DISCONNECTED:
                LCD_ShowString(60,120,200,16,16,"WiFi State: Disconnected!");
                LCD_ShowString(60,140,240,12,12,"                                       ");
                LCD_ShowString(60,160,240,12,12,"                                       ");
                printf("WiFi State: Disconnected!\n");
                memset(buffer, 0, MAX_SSID_LEN+8);
                freertos_msleep(30);

                //set scan
                xQueueReset(wifi_event_queue_handle);
                wifi_netlink_ops.set_scan_func(wifi_netlink);
                state_type = WIFI_DAEMON_STATE_SCANNING;
                break;

            case WIFI_DAEMON_STATE_SCANNING:
                LCD_ShowString(60,120,200,16,16,"WiFi State: Scanning....!");
                printf("WiFi State: Scanning....!\n");
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
                            wifi_netlink_ops.get_scan_list_func(wifi_netlink);
                            //LCD_show_scan_list(wifi_netlink);
                            state_type =WIFI_DAEMON_STATE_SCAN_DONE;
                        }
                        else if (p_wifi_msg->msg_type == WIFI_MESSAGE_NOTIFY_SCAN_RESULT_FAIL)
                        {
                            state_type =WIFI_DAEMON_STATE_DISCONNECTED;
                        }
                    }
                }
                else
                {
                    DEBUGPRINT("WIFI_DAEMON_STATE_SCANNING: OSTaskQPend error!\n");
                }

                break;

            case WIFI_DAEMON_STATE_SCAN_DONE:
                LCD_ShowString(60,120,200,16,16,"WiFi State: Scan finish!!");
                printf("WiFi State: Scan finish!!\n");
                for (i=0; i < 3000; i++)
                {
                    user_action = user_key_trigger_detected();
                    if (user_action <= WIFI_USER_ACTION_MAX)
                    {
                        user_action = WIFI_USER_CONNECT_AP;
                        break;
                    }
                    else
                    {
                        freertos_msleep(10);
                    }
                }
                if ((user_action == WIFI_USER_CONNECT_AP) && (wifi_netlink->scan_ap_num >= 1))
                {
                    //connect req
                    xQueueReset(wifi_event_queue_handle);
                    LCD_ShowString(60,120,200,16,16,"WiFi State: Connecting...");
                    char ssid[] = {"cpsb-wp-test"};
                    //char ssid[] = {"ap_test"};
                    printf("!!!WiFi State: Connecting...\n");
                    if(need_reconnect)
                    {

state_type = WIFI_DAEMON_STATE_AUTO_CONNECT;
                         break;
                    }
                    #ifdef ENABLE_RK_WIFI_CONFIG
                    if(smconfig_got)
                    {
                        err_status = wifi_netlink_ops.connect_req_func(wifi_netlink, sm_ssid, sm_pwd);
                    }
                    else
                    #endif
                    {
                        err_status = wifi_netlink_ops.connect_req_func(wifi_netlink, ssid, "123456789");
                    }
                    if (err_status == 0)
                    {
                        state_type = WIFI_DAEMON_STATE_CONNECTING;
                    }
                    else
                    {
                        state_type =  WIFI_DAEMON_STATE_DISCONNECTED;
                    }
                }
                else if (user_action == WIFI_USER_ENTER_INTERACTIVE)
                {
                    //enter interactive mode
                    state_type = WIFI_DAEMON_STATE_COMMAND_TESTING;
                }
                else
                {
                    //set scan
                    xQueueReset(wifi_event_queue_handle);
                    wifi_netlink_ops.set_scan_func(wifi_netlink);
                    state_type = WIFI_DAEMON_STATE_SCANNING;
                }

                break;
            case WIFI_DAEMON_STATE_AUTO_CONNECT:

                err_status = wifi_ap_auto_connect();
                if(err_status == 0)
                {
                    state_type = WIFI_DAEMON_STATE_CONNECTED;
                    need_reconnect = 0;
                }
                else
                {
                     printf("WiFi will retry connect after 5s\n");
                     freertos_msleep(5000);

state_type = WIFI_DAEMON_STATE_DISCONNECTED;
                }

            break;

            case WIFI_DAEMON_STATE_CONNECTING:
                //LCD_ShowString(60,120,200,16,16,"WiFi State: Connecting...");
                printf("WiFi State: Connecting...\n");
                freertos_msleep(10);
                err = xQueueReceive(wifi_event_queue_handle, msg_ptr, portMAX_DELAY);
                if (err == pdTRUE)
                {
                    if (msg_ptr != NULL)
                    {
                        p_wifi_msg = (WIFI_MESSAGE_T *) msg_ptr;
                        if (p_wifi_msg->msg_type == WIFI_MESSAGE_INDICATE_CONNECT)
                        {
                            state_type = WIFI_DAEMON_STATE_CONNECTED;
                        }
                        else if (p_wifi_msg->msg_type == WIFI_MESSAGE_INDICATE_DISCONNECT)
                        {
                            state_type = WIFI_DAEMON_STATE_DISCONNECTED;
                        }
                    }
                }
                else
                {
                    DEBUGPRINT("WIFI_DAEMON_STATE_CONNECTING: OSTaskQPend error!\n");
                }

                break;

            case WIFI_DAEMON_STATE_CONNECTED:
            {
                RKI6000_WIFI_AP ap;
                LCD_ShowString(60,120,200,16,16,"WiFi State: Connected! :)");
                snprintf((char *)buffer, sizeof("SSID: "), "SSID: ");
                snprintf((char *)buffer+sizeof("SSID: ")-1, wifi_netlink->connected_ap_info.ssid.ssid_len+1, "%s", wifi_netlink->connected_ap_info.ssid.ssid);
                LCD_ShowString(60,140,240,12,12, (uint8 *)buffer);
                if(smconfig_got)
                {
                    memset(&ap, 0, sizeof(RKI6000_WIFI_AP));
                    memcpy(ap.bssid,wifi_netlink->connected_ap_info.bssid_info.bssid,6);
                    memcpy(ap.ssid_value,wifi_netlink->connected_ap_info.ssid.ssid,wifi_netlink->connected_ap_info.ssid.ssid_len);
                    #ifdef ENABLE_RK_WIFI_CONFIG
                    memcpy(ap.key, sm_pwd, strlen(sm_pwd));
                    ap.key_len = strlen(sm_pwd);
                    #else
                    memcpy(ap.key, "123456789", 9);
                    ap.key_len = 9;
                    #endif
                    ap.ssid_len = wifi_netlink->connected_ap_info.ssid.ssid_len+1;
                    wifi_add_db(&ap);

                }
                wifi_update_last_ap_index(wifi_netlink->connected_ap_info.bssid_info.bssid);

                if(smconfig_got)
                {
                    smconfig_got= 0;
                    wifi_savedb_to_disk();
                }
                printf_wifi_db();
                printf("%s\n", buffer);
                freertos_msleep(500);
                WIFI_SEND_EVENT(WIFI_EVENT_TYPE_CONNECTED, NULL,0,0);
#ifdef ENABLE_DHCP_CONFIG_IP
                if (need_do_dhcp)
                {
                    netifapi_dhcp_start(&wifi_netif);
                    state_type = WIFI_DAEMON_STATE_DHCP_DOING;
                }
#else
                state_type = WIFI_DAEMON_STATE_DHCP_DOING;
#endif
                break;
            }
            case WIFI_DAEMON_STATE_DHCP_DOING:
                LCD_ShowString(60,120,200,16,16,"WiFi State: DHCP doing...");
#ifdef ENABLE_DHCP_CONFIG_IP
                for (i=0; i < 300; i++)
                {
                    freertos_msleep(100);
                    if (wifi_netif.dhcp->state == DHCP_BOUND)
                    {
                        dhcp_ip_got = TRUE;
                        wifi_netlink_ops.set_ipaddr_func(wifi_netlink, (unsigned int *)&wifi_netif.ip_addr);
                        break;
                    }
                }
#else
                dhcp_ip_got = TRUE;
                wifi_netlink_ops.set_ipaddr_func(wifi_netlink, (unsigned int *)&wifi_netif.ip_addr);
#endif

                if (dhcp_ip_got)
                {
                    state_type = WIFI_DAEMON_STATE_IP_CONFIGED;
                }
                else
                {
                    DEBUGPRINT("wifi test task: dhcp timeout!\n");
                    state_type = WIFI_DAEMON_STATE_CONNECTED;
                }

                break;

            case WIFI_DAEMON_STATE_IP_CONFIGED:
                LCD_ShowString(60,120,200,16,16,"WiFi State: IP configed!!");
                snprintf((char *)buffer, sizeof("IP: "), "IP: ");
                snprintf((char *)buffer+sizeof("IP: ")-1, 16, "%s", ip_ntoa(&wifi_netif.ip_addr));
                LCD_ShowString(60,160,240,12,12, (uint8 *)buffer);
                printf("%s\n", buffer);

                FREQ_ExitModule(FREQ_INIT);
                #ifdef ENABLE_RUN_DLAN
                RKTaskCreate(TASK_ID_DLNA,0, NULL, SYNC_MODE);
                rk_dlna_start();
                #endif
                WIFI_SEND_EVENT(WIFI_EVENT_TYPE_IP_CONFIGED, NULL,0,0);
                if (user_action == WIFI_USER_ENTER_INTERACTIVE)
                {
                    //enter interactive mode
                    state_type = WIFI_DAEMON_STATE_COMMAND_TESTING;
                }
                else if (user_action == WIFI_USER_DISCONNECT_WITH_AP)
                {
                    //disconnect req
                    wifi_netlink_ops.disconnect_req_func(wifi_netlink);
#ifdef ENABLE_DHCP_CONFIG_IP
                    netifapi_dhcp_stop(&wifi_netif);
                    memset(&wifi_netif.ip_addr, 0, sizeof(wifi_netif.ip_addr));
                    memset(&wifi_netif.gw, 0, sizeof(wifi_netif.gw));
#endif
                    dhcp_ip_got = FALSE;
                    state_type = WIFI_DAEMON_STATE_DISCONNECTED;
                }
                else
                {
                    err = xQueueReceive(wifi_event_queue_handle, msg_ptr, portMAX_DELAY);
                    if (err == pdTRUE)
                    {
                        if (msg_ptr != NULL)
                        {
                            p_wifi_msg = (WIFI_MESSAGE_T *) msg_ptr;
                            if (p_wifi_msg->msg_type == WIFI_MESSAGE_INDICATE_DISCONNECT)
                            {
#ifdef ENABLE_DHCP_CONFIG_IP
                                netifapi_dhcp_stop(&wifi_netif);
                                memset(&wifi_netif.ip_addr, 0, sizeof(wifi_netif.ip_addr));
                                memset(&wifi_netif.gw, 0, sizeof(wifi_netif.gw));
#endif
                                dhcp_ip_got = FALSE;
                                WIFI_SEND_EVENT(WIFI_EVENT_TYPE_DISCONNECTED, NULL,0,0);
                                state_type = WIFI_DAEMON_STATE_DISCONNECTED;
                                need_reconnect = 1;
                                printf("watch dog start\n");
                                break;
                            }
                        }
                    }
                }
                break;

            case WIFI_DAEMON_STATE_COMMAND_TESTING:
                LCD_ShowString(60,120,200,16,16,"WiFi State: Cmd testing");
                printf("WiFi State: Cmd testing");
                command_test_mode();
                if (dhcp_ip_got)
                {
                    state_type = WIFI_DAEMON_STATE_IP_CONFIGED;
                }
                else
                {
                    state_type = WIFI_DAEMON_STATE_DISCONNECTED;
                }
                break;

            default:
                DEBUGPRINT("wifi test task: invalid wifi test state!!!\n");
                break;

        }

        if (start_softap_mode)
            break;
    }

    wifi_netlink_ops.deinit_func(wifi_netlink);

    for (i=0; i<4; i++)
        LCD_ShowString(60,(120+i*20),200,16,16,"                         ");
    for (i=0; i<14; i++)
        LCD_ShowString(60, (200+i*20), 240, 12, 12, "                                        ");

#else

    WIFI_NETLINK_INFO_T *wifi_netlink = NULL;

    wifi_netlink = wifi_netlink_ops.init_func();

    for (;;)
    {
        command_test_mode();
        freertos_msleep(10000);
    }

    wifi_netlink_ops.deinit_func(wifi_netlink);

#endif
}
#endif

#ifdef CONFIG_WIFI_SOFTAP_MODE

extern int wifi_softap_entry(unsigned char *ssid, unsigned char security, unsigned char *password);
extern void dhcpd_daemon(void);
extern void ttcp_test(int test_mode);

void  wifi_daemon_task (void *p_arg)
{
    unsigned char security_mode;
    unsigned char ssid[32+1];
    unsigned char password[32+1];
    WIFI_NETLINK_INFO_T *wifi_netlink = NULL;

#ifdef CONFIG_LCD_SHOW
    LCD_ShowString(60,110,200,16,16,"Start SoftAP...");
#endif

    memcmp(ssid, CONFIG_SOFTAP_SSID, strlen(CONFIG_SOFTAP_SSID)+1);
    security_mode = CONFIG_SECURITY_MODE;
    memcmp(password, CONFIG_SOFTAP_PASSWORD, strlen(CONFIG_SOFTAP_PASSWORD)+1);

    wifi_softap_entry("i6000_softap", 2, "12345678");

#ifdef CONFIG_LCD_SHOW
    LCD_ShowString(60,130,200,16,16,"SoftAP: u_soft_ap started.");
    LCD_ShowString(60,150,200,16,16,"IP: 192.168.237.1");
#else

#endif
    printf("SoftAP: u_soft_ap started.");
    printf("IP: 192.168.237.1");
    dhcpd_daemon();
    char * tasklistbuf = rkos_memory_malloc(4096);
    memset(tasklistbuf,0,4096);
    vTaskList(tasklistbuf);
    printf("\n task list:\n");
    printf("%s:\n",tasklistbuf);
    for (;;)
    {
        command_test_mode();
        freertos_msleep(10000);
    }
}
#endif

//#pragma arm section code
#endif /*#ifdef __DRIVER_I6000_WIFI_C__*/
