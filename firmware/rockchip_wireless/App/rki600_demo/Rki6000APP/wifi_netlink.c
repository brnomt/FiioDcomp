#include "debug_print.h"
#include "FreeRTOS.h"
#include "RKOS.h"
//#include <includes.h>
#include "app_cfg.h"
#include "bsp.h"
#include "nvic.h"
#include "delay.h"
#include "uart.h"
#include "lcd.h"
//#include "sram.h"
//#include "malloc.h"

//#include "lwip_cfg.h"
//#include "sys_task.h"
#include "wifi_netlink.h"

#include "wlan_intf_def.h"
#include "wlan_intf.h"

#ifdef __DRIVER_I6000_WIFI_C__
WIFI_NETLINK_INFO_T *p_wifi_netlink = NULL;
_os_task  wifi_daemon_task_tcb;
xQueueHandle wifi_event_queue_handle;

#ifdef CONFIG_WIFI_STA_MODE

extern WIFI_OPS_ENTRY_T wifi_ops_entry;
extern _os_task wifi_task_tcb[];

/* same ssid ap info process */
BOOL ap_need_add_to_list(WIFISUPP_SCAN_AP_INFO_T *insert_node, WIFISUPP_SCAN_AP_INFO_T *scan_list_head)
{
    WIFISUPP_SCAN_AP_INFO_T *p_scan_list = scan_list_head;

    while (p_scan_list != NULL)
    {
        if ((insert_node->ssid.ssid_len == p_scan_list->ssid.ssid_len) &&
            (!memcmp(&insert_node->ssid.ssid, &p_scan_list->ssid.ssid, insert_node->ssid.ssid_len)))
        {
            if (insert_node->encryp_protocol != p_scan_list->encryp_protocol)
            {
                return TRUE;
            }
            else
            {
                if (insert_node->rssi > p_scan_list->rssi)
                {
                    // use insert_node ap info replacing the previous one except next_ptr
                    memcpy(&p_scan_list->ssid, &insert_node->ssid, sizeof(WIFISUPP_SCAN_AP_INFO_T)-sizeof(p_scan_list->next_ptr));
                }
                return FALSE;
            }
        }

        p_scan_list = p_scan_list->next_ptr;
    }

    return TRUE;
}

BOOL be_prior_to(WIFISUPP_SCAN_AP_INFO_T *insert_node, WIFISUPP_SCAN_AP_INFO_T *original_node)
{
    if ((insert_node->encryp_protocol == WIFISUPP_ENCRYP_PROTOCOL_OPENSYS) &&
        (original_node->encryp_protocol != WIFISUPP_ENCRYP_PROTOCOL_OPENSYS))
    {
        return TRUE;
    }

    if ((insert_node->encryp_protocol != WIFISUPP_ENCRYP_PROTOCOL_OPENSYS) &&
        (original_node->encryp_protocol == WIFISUPP_ENCRYP_PROTOCOL_OPENSYS))
    {
        return FALSE;
    }

    if (insert_node->rssi > original_node->rssi)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void sorting_scan_list(WIFI_NETLINK_INFO_T *wifi_netlink)
{
    unsigned char i;
    WIFISUPP_SCAN_AP_INFO_T *p_scan_list, *p_next;
    WIFISUPP_SCAN_AP_INFO_T *scan_list_head = NULL;
    WIFISUPP_SCAN_AP_INFO_T *scan_list_node = wifi_netlink->scan_list;

    for (i=0; i<wifi_netlink->scan_ap_num; i++)
    {
        if (scan_list_head == NULL)
        {
            scan_list_head = scan_list_node;
        }
        else
        {
            if (ap_need_add_to_list(scan_list_node, scan_list_head))
            {
                p_scan_list = scan_list_head;
                if (be_prior_to(scan_list_node, p_scan_list))
                {
                    scan_list_node->next_ptr = p_scan_list;
                    scan_list_head = scan_list_node;
                }
                else
                {
                    while (p_scan_list->next_ptr != NULL)
                    {
                        p_next = p_scan_list->next_ptr;
                        if (be_prior_to(scan_list_node, p_next))
                        {
                            scan_list_node->next_ptr = p_next;
                            p_scan_list->next_ptr = scan_list_node;
                            break;
                        }
                        p_scan_list = p_scan_list->next_ptr;
                    }
                    if (p_scan_list->next_ptr == NULL)
                    {
                        p_scan_list->next_ptr = scan_list_node;
                        scan_list_node->next_ptr = NULL;
                    }
                }
            }
        }
        scan_list_node++;
    }

    wifi_netlink->scan_list_head = scan_list_head;

}

void print_bitrate(unsigned long bitrate)
{
    double rate = bitrate;
    char    scale;
    int divisor;

    if(rate >= GIGA)
    {
        scale = 'G';
        divisor = GIGA;
    }
    else
    {
        if(rate >= MEGA)
        {
            scale = 'M';
            divisor = MEGA;
        }
        else
        {
            scale = 'k';
            divisor = KILO;
        }
    }

    DEBUGPRINT("Rate: %g %cb/s\n", rate/divisor, scale);
}

void print_scan_info(WIFI_NETLINK_INFO_T *wifi_netlink)
{
    WIFISUPP_SCAN_AP_INFO_T *p_scan_list = wifi_netlink->scan_list_head;

    DEBUGPRINT("[Scanned AP list]\n");

    while (p_scan_list != NULL)
    {
        DEBUGPRINT("----------------------------------------------------\n");
        DEBUGPRINT("SSID:		%s\n", &p_scan_list->ssid.ssid);
        DEBUGPRINT("Channel:	%d\n", p_scan_list->channel);
        switch (p_scan_list->encryp_protocol)
        {
            case WIFISUPP_ENCRYP_PROTOCOL_OPENSYS:
                DEBUGPRINT("Security:	Open\n");
                break;
            case WIFISUPP_ENCRYP_PROTOCOL_WEP:
                DEBUGPRINT("Security:	WEP\n");
                break;
            case WIFISUPP_ENCRYP_PROTOCOL_WPA:
                DEBUGPRINT("Security:	WPA\n");
                break;
            case WIFISUPP_ENCRYP_PROTOCOL_WPA2:
                DEBUGPRINT("Security:	WPA2\n");
                break;
            default:
                DEBUGPRINT("Security:	Unknown\n");
                break;
        }

        if (p_scan_list->network_mode == WIFISUPP_NETWORK_MODE_INFRASTRUCTURE)
        {
            DEBUGPRINT("Network:	Infrastructure\n");
        }
        else if (p_scan_list->network_mode == WIFISUPP_NETWORK_MODE_ADHOC)
        {
            DEBUGPRINT("Network:	Adhoc\n");
        }
        else
        {
            DEBUGPRINT("Network:	Unknown\n");
        }

        //print_bitrate(p_scan_list->rate);
        DEBUGPRINT("Rate:		%d Mbps\n", p_scan_list->rate);
        DEBUGPRINT("RSSI:		%d\n", p_scan_list->rssi);

        DEBUGPRINT("\n\r");
        p_scan_list = p_scan_list->next_ptr;
    }
}

WIFI_NETLINK_INFO_T *
wifi_netlink_init(void)
{
    WIFI_NETLINK_INFO_T *wifi_netlink;

    wifi_netlink = (WIFI_NETLINK_INFO_T *)freertos_malloc(sizeof(WIFI_NETLINK_INFO_T));

    memset(wifi_netlink, 0, sizeof(WIFI_NETLINK_INFO_T));

    p_wifi_netlink = wifi_netlink;
    wifi_event_queue_handle = xQueueCreate(50,sizeof(WIFI_MESSAGE_T));
    return wifi_netlink;
}

int wifi_netlink_deinit(WIFI_NETLINK_INFO_T *wifi_netlink)
{
    freertos_mfree(wifi_netlink);
    p_wifi_netlink = NULL;

    return 0;
}

int wifi_netlink_set_scan(WIFI_NETLINK_INFO_T *wifi_netlink)
{
    WIFISUPP_SCAN_REQ_INFO_T scan_req;

    memset(&scan_req.ssid.ssid, 0, WIFISUPP_SSID_MAX_LEN);
    scan_req.ssid.ssid_len = 0;

    wifi_netlink->saved_link_status = wifi_netlink->link_status;
    if (wifi_netlink->link_status == WIFI_NETLINK_STATUS_NO_LINK)
    {
        wifi_netlink->link_status = WIFI_NETLINK_STATUS_NO_LINK_SCAN;
    }
    else if (wifi_netlink->link_status >= WIFI_NETLINK_STATUS_LINKED)
    {
        wifi_netlink->link_status = WIFI_NETLINK_STATUS_LINKED_SCAN;
    }

    wifi_ops_entry.wifi_scan_proc_func(&scan_req);

    return 0;
}

int wifi_netlink_get_scan_list(WIFI_NETLINK_INFO_T *wifi_netlink)
{
    printf("wifi_netlink_get_scan_list\n");
    wifi_netlink->scan_ap_num = 0;
    wifi_netlink->scan_list_head = NULL;
    memset(wifi_netlink->scan_list, 0, sizeof(WIFISUPP_SCAN_AP_INFO_T)*SUPPORT_MAX_AP_NUM);

    wifi_ops_entry.wifi_get_scan_list_func(wifi_netlink->scan_list, &wifi_netlink->scan_ap_num);

    DEBUGPRINT("\n\rwifi netlink: scan finished, scanned ap number: %d\n", wifi_netlink->scan_ap_num);

    sorting_scan_list(wifi_netlink);

    print_scan_info(wifi_netlink);

    wifi_netlink->link_status = wifi_netlink->saved_link_status;

    return 0;
}
/*
 @param is_use_db
    when set 1, wifi connect to the AP that has be save in wifi_info_db,when scan list
    can not found match ap, return fail.
*/
int wifi_netlink_connect_req(WIFI_NETLINK_INFO_T *wifi_netlink, uint8 *ssid, uint8 *password)
{
    uint8  i;
    uint8 found_ap = 0;
    WIFISUPP_SSID_CONFIG_T *connect_info = &wifi_netlink->connect_info;
    WIFISUPP_SCAN_AP_INFO_T *p_scan_list = wifi_netlink->scan_list_head;
    unsigned char key[5] = {0x12,0x34,0x56,0x78,0x90};

    if (p_scan_list == NULL)
    {
        DEBUGPRINT("\n\rwifi netlink: scan list empty!\n");
        return -1;
    }

    if (ssid != NULL)
    {
        //for (i=0; (i<wifi_netlink->scan_ap_num && p_scan_list ); i++)
        while(p_scan_list != NULL)
        {
            if ((p_scan_list->ssid.ssid_len == strlen((const char *)ssid)) &&
                (!memcmp(p_scan_list->ssid.ssid, ssid, p_scan_list->ssid.ssid_len)))
            {
                found_ap = 1;
                break;

            }
            else
            {
                p_scan_list = p_scan_list->next_ptr;
            }
        }

        if (!found_ap)
        {
            DEBUGPRINT("\n\rwifi netlink: can not find matched ap to connect!\n");
            return -1;
        }
    }

    memcpy(&connect_info->ssid, &p_scan_list->ssid, sizeof(WIFISUPP_SSID_T));
    memcpy(&connect_info->bssid_info, &p_scan_list->bssid_info, sizeof(WIFISUPP_BSSID_T));
    connect_info->network_mode = p_scan_list->network_mode;
    connect_info->encryp_protocol = p_scan_list->encryp_protocol;
    connect_info->channel = p_scan_list->channel;
    connect_info->pairwise_cipher = p_scan_list->pairwise_cipher;
    connect_info->group_cipher = p_scan_list->group_cipher;

    if (connect_info->encryp_protocol == WIFISUPP_ENCRYP_PROTOCOL_OPENSYS)
    {

    }
    else if (connect_info->encryp_protocol == WIFISUPP_ENCRYP_PROTOCOL_WPA ||
             connect_info->encryp_protocol == WIFISUPP_ENCRYP_PROTOCOL_WPA2)
    {
        connect_info->credential.wpa_credential.credential_type = WIFISUPP_WPA_CREDENTIAL_TYPE_PSK;
        if (password == NULL)
        {
            memcpy(connect_info->credential.wpa_credential.credential_info.wpa_psk_info.psk, CONFIG_STA_PASSWORD, strlen(CONFIG_STA_PASSWORD) + 1);
        }
        else
        {
            memcpy(connect_info->credential.wpa_credential.credential_info.wpa_psk_info.psk, password, strlen((const char *)password) + 1);
        }
    }
    else if (connect_info->encryp_protocol == WIFISUPP_ENCRYP_PROTOCOL_WEP)
    {
        connect_info->credential.wep_credential.key_type = WIFISUPP_WEP_KEY_TYPE_64BITS;
        connect_info->credential.wep_credential.is_open_mode = 1;
        connect_info->credential.wep_credential.key_in_use = 0;//[idx0 - idx3]
        memcpy(connect_info->credential.wep_credential.key.key_64bits_arr[0], key, 5);
    }
    else
    {
        DEBUGPRINT("\n\rwifi netlink: not supported security mode!\n");
        return -1;
    }


    wifi_netlink->link_status = WIFI_NETLINK_STATUS_LINKING;

    wifi_ops_entry.wifi_connect_req_func(connect_info);

    return 0;
}

int wifi_netlink_disconnect_req(WIFI_NETLINK_INFO_T *wifi_netlink)
{
    WIFISUPP_DISCONNECT_REQ_INFO_T disconnect_info;

    if (wifi_netlink->link_status >= WIFI_NETLINK_STATUS_LINKED)
    {
        memcpy(&disconnect_info.ssid, &wifi_netlink->connected_ap_info.ssid, sizeof(WIFISUPP_SSID_T));

        wifi_ops_entry.wifi_disconnect_req_func(&disconnect_info);

        DEBUGPRINT("\n\rwifi netlink: disconnect with ap %s!\n", &wifi_netlink->connected_ap_info.ssid.ssid);

        memset(&wifi_netlink->connected_ap_info, 0, sizeof(WIFISUPP_CONNECT_RESULT_T));
        wifi_netlink->link_status = WIFI_NETLINK_STATUS_NO_LINK;
    }
    else
    {
        DEBUGPRINT("\n\rwifi netlink: wifi is not connected!\n");
    }

    return 0;
}

int wifi_netlink_open_dev(WIFI_NETLINK_INFO_T *wifi_netlink)
{
    if (!wifi_netlink->device_opened)
    {
        wifi_ops_entry.wifi_open_func();

        wifi_netlink->device_opened = 1;
        DEBUGPRINT("\n\rwifi netlink: device opened!\n");
    }
    else
    {
        DEBUGPRINT("\n\rwifi netlink: device had been opened!\n");
    }

    return 0;
}

int wifi_netlink_close_dev(WIFI_NETLINK_INFO_T *wifi_netlink)
{
    if (wifi_netlink->device_opened)
    {
        if (wifi_netlink->link_status >= WIFI_NETLINK_STATUS_LINKED)
        {
            wifi_netlink_disconnect_req(wifi_netlink);
        }

        wifi_ops_entry.wifi_close_func();

        wifi_netlink->device_opened = 0;
        memset(wifi_netlink, 0, sizeof(WIFI_NETLINK_INFO_T));
        DEBUGPRINT("\n\rwifi netlink: device closed!\n");
    }
    else
    {
        DEBUGPRINT("\n\rwifi netlink: device had been closed!\n");
    }

    return 0;
}

int wifi_netlink_set_ipaddr(WIFI_NETLINK_INFO_T *wifi_netlink, unsigned int *ipaddr)
{
    wifi_netlink->ip_addr[0] = ((unsigned char *)(ipaddr))[0];
    wifi_netlink->ip_addr[1] = ((unsigned char *)(ipaddr))[1];
    wifi_netlink->ip_addr[2] = ((unsigned char *)(ipaddr))[2];
    wifi_netlink->ip_addr[3] = ((unsigned char *)(ipaddr))[3];

    wifi_ops_entry.wifi_set_ipaddr_func(wifi_netlink->ip_addr);

    wifi_netlink->link_status = WIFI_NETLINK_STATUS_LINKED_CONFIGED;

    return 0;
}

int wifi_netlink_start_ap(WIFI_NETLINK_INFO_T *wifi_netlink, uint8 *ssid, uint8 *password)
{
    if (wifi_netlink->link_status >= WIFI_NETLINK_STATUS_LINKED)
    {
        wifi_netlink_close_dev(wifi_netlink);
        wifi_netlink_open_dev(wifi_netlink);
    }

    //softap security mode: WPA2-AES only
    DEBUGPRINT("\n\rwifi netlink: starting softap ...\n");
    if (password != NULL)
    {
        wifi_ops_entry.wifi_softap_func(ssid, 3, password);
        wifi_netlink->ap_security = 3;
        memcpy((uint8 *)wifi_netlink->ap_password, password, strlen((const char *)password)+1);
    }
    else
    {
        wifi_ops_entry.wifi_softap_func(ssid, 0, NULL);
        wifi_netlink->ap_security = 0;
    }
    wifi_netlink->ap_started = 1;
    memcpy((uint8 *)wifi_netlink->ap_ssid, ssid, strlen((const char *)ssid)+1);
    //memcpy((uint8 *)wifi_netlink->ap_password, password, strlen((const char *)password)+1);
    DEBUGPRINT("\n\rwifi netlink: softap %s started!\n", ssid);

    return 0;
}

int wifi_netlink_get_status(WIFI_NETLINK_INFO_T *wifi_netlink)
{
    if (!wifi_netlink->device_opened)
    {
        DEBUGPRINT("\n\r\nWIFI Status: Closed");
        DEBUGPRINT("\n\r==============================");
        DEBUGPRINT("\n\r");
        return 0;
    }

    if (wifi_netlink->ap_started)
    {
        DEBUGPRINT("\n\r\nWIFI Status: AP Started");
        DEBUGPRINT("\n\r==============================");
        DEBUGPRINT("\n\rMODE:		AP");
        DEBUGPRINT("\n\rSSID:		%s", wifi_netlink->ap_ssid);
        if (wifi_netlink->ap_security == 3)
        {
            DEBUGPRINT("\n\rSECURITY:	WPA2");
            DEBUGPRINT("\n\rPASSWORD:	%s", wifi_netlink->ap_password);
        }
        else if (wifi_netlink->ap_security == 0)
        {
            DEBUGPRINT("\n\rSECURITY:	Open");
        }
    }
    else
    {
        if (wifi_netlink->link_status >= WIFI_NETLINK_STATUS_LINKED)
        {
            DEBUGPRINT("\n\r\nWIFI Status: Connected");
            DEBUGPRINT("\n\r==============================");
            DEBUGPRINT("\n\rMODE:		STATION");
            DEBUGPRINT("\n\rSSID:		%s", wifi_netlink->connected_ap_info.ssid.ssid);
            DEBUGPRINT("\n\rCHANNEL:  	%d", wifi_netlink->connected_ap_info.channel);
            switch (wifi_netlink->connect_info.encryp_protocol)
            {
                case WIFISUPP_ENCRYP_PROTOCOL_OPENSYS:
                    DEBUGPRINT("\n\rSECURITY:	Open   ");
                    break;
                case WIFISUPP_ENCRYP_PROTOCOL_WEP:
                    DEBUGPRINT("\n\rSECURITY:	WEP   ");
                    break;
                case WIFISUPP_ENCRYP_PROTOCOL_WPA:
                    DEBUGPRINT("\n\rSECURITY:	WPA   ");
                    break;
                case WIFISUPP_ENCRYP_PROTOCOL_WPA2:
                    DEBUGPRINT("\n\rSECURITY:	WPA2   ");
                    break;
                default:
                    DEBUGPRINT("\n\rSECURITY:	Unknown   ");
                    break;
            }
        }
        else
        {
            DEBUGPRINT("\n\r\nWIFI Status: Opened");
            DEBUGPRINT("\n\r==============================");
        }
    }

    DEBUGPRINT("\n\r");

    return 0;
}

int wifi_netlink_get_memory(WIFI_NETLINK_INFO_T *wifi_netlink)
{
    WIFISUPP_USED_HEAP_INFO_T used_heap_info;
    uint8 i;

    wifi_ops_entry.wifi_get_heap_usage_func(&used_heap_info);

    DEBUGPRINT("\n\r\nHeap Information");
    DEBUGPRINT("\n\r==================================");
    DEBUGPRINT("\n\rwifi netlink: driver used heap size = %d", used_heap_info.used_heap_size);
    DEBUGPRINT("\n\rwifi netlink: driver max used heap size = %d", used_heap_info.max_used_heap_size);
    DEBUGPRINT("\n\rwifi netlink: total free heap size = %d", used_heap_info.free_heap_size);
    DEBUGPRINT("\n\rwifi netlink: total min free heap size = %d", used_heap_info.min_free_heap_size);

#if OS_CFG_DBG_EN
    DEBUGPRINT("\n\r\nTask Stack Information");
    DEBUGPRINT("\n\r==================================");
    DEBUGPRINT("\n\rwifi test task: used stack = %d, free stack = %d", wifi_daemon_task_tcb.StkUsed, wifi_daemon_task_tcb.StkFree);
    for (i=0; i<LWIP_TASK_MAX; i++)
    {
        DEBUGPRINT("\n\rlwip task %d: used stack = %d, free stack = %d", i, lwip_task_tcb[i].StkUsed, lwip_task_tcb[i].StkFree);
    }
    for (i=0; i<WIFI_TASK_MAX; i++)
    {
        DEBUGPRINT("\n\rwifi task %d: used stack = %d, free stack = %d", i, wifi_task_tcb[i].StkUsed, wifi_task_tcb[i].StkFree);
    }
#endif

    return 0;
}

int wifi_netlink_suspend_query(WIFI_NETLINK_INFO_T *wifi_netlink)
{
    uint8 can_suspended;

    can_suspended = wifi_ops_entry.wifi_suspend_query_func();
    DEBUGPRINT("\n\rwifi netlink: wifi suspend query result is %d\n", can_suspended);

    return can_suspended;
}

int wifi_netlink_suspend(WIFI_NETLINK_INFO_T *wifi_netlink)
{
    wifi_ops_entry.wifi_suspend_func();
    DEBUGPRINT("\n\rwifi netlink: wifi suspend finished!\n");

    return 0;
}

int wifi_netlink_resume(WIFI_NETLINK_INFO_T *wifi_netlink)
{
    wifi_ops_entry.wifi_resume_func();
    DEBUGPRINT("\n\rwifi netlink: wifi resume finished!\n");

    return 0;
}

#if CONFIG_INTERNAL_DEBUG
int wifi_netlink_read_mac_reg(WIFI_NETLINK_INFO_T *wifi_netlink, uint32 read_addr)
{
    uint32 read_value = 0;
    WIFISUPP_PRIV_REQ_INFO_T *priv_req_info = &wifi_netlink->priv_req;

    if (read_addr >= 0x0800)
    {
        DEBUGPRINT("\n\rwifi netlink: read MAC reg, invalid MAC address!\n");
        return -1;
    }

    if (read_addr % 4 != 0)
    {
        DEBUGPRINT("\n\rwifi netlink: read MAC reg, address must 4 bytes aligned!\n");
        return -1;
    }

    priv_req_info->priv_req = WIFISUPP_PRIV_READ_MAC_REG;
    priv_req_info->priv_param1 = read_addr;
    priv_req_info->result_data = &read_value;
    wifi_ops_entry.wifi_priv_req_func(priv_req_info);
    DEBUGPRINT("\n\rrmac 0x%04x: %08x\n", read_addr, read_value);

    return 0;
}

int wifi_netlink_write_mac_reg(WIFI_NETLINK_INFO_T *wifi_netlink, uint32 write_addr, uint32 write_value)
{
    uint32 read_value = 0;
    WIFISUPP_PRIV_REQ_INFO_T *priv_req_info = &wifi_netlink->priv_req;

    if (write_addr >= 0x0800)
    {
        DEBUGPRINT("\n\rwifi netlink: write MAC reg, invalid MAC address!\n");
        return -1;
    }

    if (write_addr % 4 != 0)
    {
        DEBUGPRINT("\n\rwifi netlink: write MAC reg, address must 4 bytes aligned!\n");
        return -1;
    }

    priv_req_info->priv_req = WIFISUPP_PRIV_WRITE_MAC_REG;
    priv_req_info->priv_param1 = write_addr;
    priv_req_info->priv_param2 = write_value;
    priv_req_info->result_data = &read_value;
    wifi_ops_entry.wifi_priv_req_func(priv_req_info);
    DEBUGPRINT("\n\rwmac 0x%04x: %08x\n", write_addr, write_value);
    DEBUGPRINT("rmac 0x%04x: %08x\n", write_addr, read_value);

    return 0;
}

int wifi_netlink_read_phy_reg(WIFI_NETLINK_INFO_T *wifi_netlink, uint32 read_addr)
{
    uint32 read_value = 0;
    WIFISUPP_PRIV_REQ_INFO_T *priv_req_info = &wifi_netlink->priv_req;

    if (read_addr >= 0x0100)
    {
        DEBUGPRINT("\n\rwifi netlink: read PHY reg, invalid PHY address!\n");
        return -1;
    }

    priv_req_info->priv_req = WIFISUPP_PRIV_READ_PHY_REG;
    priv_req_info->priv_param1 = read_addr;
    priv_req_info->result_data = &read_value;
    wifi_ops_entry.wifi_priv_req_func(priv_req_info);
    DEBUGPRINT("\n\rrphy 0x%02x: %08x\n", read_addr, read_value);

    return 0;
}

int wifi_netlink_write_phy_reg(WIFI_NETLINK_INFO_T *wifi_netlink, uint32 write_addr, uint32 write_value)
{
    uint32 read_value = 0;
    WIFISUPP_PRIV_REQ_INFO_T *priv_req_info = &wifi_netlink->priv_req;

    if (write_addr >= 0x0100)
    {
        DEBUGPRINT("\n\rwifi netlink: write PHY reg, invalid PHY address!\n");
        return -1;
    }

    priv_req_info->priv_req = WIFISUPP_PRIV_WRITE_PHY_REG;
    priv_req_info->priv_param1 = write_addr;
    priv_req_info->priv_param2 = write_value;
    priv_req_info->result_data = &read_value;
    wifi_ops_entry.wifi_priv_req_func(priv_req_info);
    DEBUGPRINT("\n\rwphy 0x%02x: %08x\n", write_addr, write_value);
    DEBUGPRINT("rphy 0x%02x: %08x\n", write_addr, read_value);

    return 0;
}

int wifi_netlink_set_channel(WIFI_NETLINK_INFO_T *wifi_netlink, uint32 channel)
{
    WIFISUPP_PRIV_REQ_INFO_T *priv_req_info = &wifi_netlink->priv_req;

    if (channel == 0 || channel > 14)
    {
        DEBUGPRINT("\n\rwifi netlink: set channel, invalid channel!\n");
        return -1;
    }

    priv_req_info->priv_req = WIFISUPP_PRIV_SET_CHANNEL;
    priv_req_info->priv_param1 = channel;
    wifi_ops_entry.wifi_priv_req_func(priv_req_info);
    DEBUGPRINT("\n\rset channel to %d\n", channel);

    return 0;
}

int wifi_netlink_set_rate(WIFI_NETLINK_INFO_T *wifi_netlink, uint32 rate)
{
    WIFISUPP_PRIV_REQ_INFO_T *priv_req_info = &wifi_netlink->priv_req;

    if (rate >= 4)
    {
        DEBUGPRINT("\n\rwifi netlink: set tx rate, invalid rate!\n");
        return -1;
    }

    priv_req_info->priv_req = WIFISUPP_PRIV_SET_TX_RATE;
    priv_req_info->priv_param1 = rate;
    wifi_ops_entry.wifi_priv_req_func(priv_req_info);
    DEBUGPRINT("\n\rset tx rate to %d\n", rate);

    return 0;
}

int wifi_netlink_enable_ps(WIFI_NETLINK_INFO_T *wifi_netlink)
{
    WIFISUPP_PRIV_REQ_INFO_T *priv_req_info = &wifi_netlink->priv_req;

    priv_req_info->priv_req = WIFISUPP_PRIV_ENABLE_PS;
    wifi_ops_entry.wifi_priv_req_func(priv_req_info);
    DEBUGPRINT("\n\rwifi netlink: power save enabled!\n");

    return 0;
}

int wifi_netlink_disable_ps(WIFI_NETLINK_INFO_T *wifi_netlink)
{
    WIFISUPP_PRIV_REQ_INFO_T *priv_req_info = &wifi_netlink->priv_req;

    priv_req_info->priv_req = WIFISUPP_PRIV_DISABLE_PS;
    wifi_ops_entry.wifi_priv_req_func(priv_req_info);
    DEBUGPRINT("\n\rwifi netlink: power save disabled!\n");

    return 0;
}

int wifi_netlink_get_ps(WIFI_NETLINK_INFO_T *wifi_netlink)
{
    uint32 ps_state;
    WIFISUPP_PRIV_REQ_INFO_T *priv_req_info = &wifi_netlink->priv_req;

    priv_req_info->priv_req = WIFISUPP_PRIV_GET_PS;
    priv_req_info->result_data = &ps_state;
    wifi_ops_entry.wifi_priv_req_func(priv_req_info);
    DEBUGPRINT("\n\rwifi netlink: power save state is %d!\n", ps_state);

    return 0;
}

#endif

#if 0
int wifi_netlink_user_connect_action(uint8 ap_index)
{
    rk_err_t      err;
    int ret = 0;
    void    *msg_ptr = NULL;
    OS_MSG_SIZE msg_size = 0;
    OS_TCB  *receiver_tcb;
    WIFI_MESSAGE_T *wifi_msg;

    wifi_msg = (WIFI_MESSAGE_T *)freertos_malloc(SRAMIN, sizeof(WIFI_MESSAGE_T));

    receiver_tcb = &wifi_daemon_task_tcb;
    msg_size = sizeof(*wifi_msg);
    msg_ptr = (void*)wifi_msg;
    OSTaskQPost(receiver_tcb, msg_ptr, msg_size, OS_OPT_POST_FIFO, &err);

    if (err == rk_err_t_NONE)
    {
        DEBUGPRINT("wifi_netlink_user_connect_action: OSTaskQPost ok!\n");
        ret = 0;
    }
    else if (err == rk_err_t_Q_MAX)
    {
        DEBUGPRINT("target task wifi_test_task msg queue is full!\n");
        ret = -1;
    }
    else if (err == rk_err_t_MSG_POOL_EMPTY)
    {
        DEBUGPRINT("wifi_netlink_user_connect_action: os msg pool is empty, no msg got!\n");
        ret = -1;
    }

    return ret;
}

int wifi_netlink_user_disconnect_action()
{
    rk_err_t      err;
    int ret = 0;
    void    *msg_ptr = NULL;
    OS_MSG_SIZE msg_size = 0;
    OS_TCB  *receiver_tcb;
    WIFI_MESSAGE_T *wifi_msg;

    wifi_msg = (WIFI_MESSAGE_T *)freertos_malloc(SRAMIN, sizeof(WIFI_MESSAGE_T));

    receiver_tcb = &wifi_daemon_task_tcb;
    msg_size = sizeof(*wifi_msg);
    msg_ptr = (void*)wifi_msg;
    OSTaskQPost(receiver_tcb, msg_ptr, msg_size, OS_OPT_POST_FIFO, &err);

    if (err == rk_err_t_NONE)
    {
        DEBUGPRINT("wifi_netlink_user_disconnect_action: OSTaskQPost ok!\n");
        ret = 0;
    }
    else if (err == rk_err_t_Q_MAX)
    {
        DEBUGPRINT("target task wifi_test_task msg queue is full!\n");
        ret = -1;
    }
    else if (err == rk_err_t_MSG_POOL_EMPTY)
    {
        DEBUGPRINT("wifi_netlink_user_disconnect_action: os msg pool is empty, no msg got!\n");
        ret = -1;
    }

    return ret;
}
#endif

int wifi_netlink_notify_scan_result(WIFISUPP_RESULT_E *result)
{
    rk_err_t      err;
    int ret = 0;
    void    *msg_ptr = NULL;
    int msg_size = 0;
    _os_task    *receiver_tcb;
    WIFI_MESSAGE_T *wifi_msg;
    WIFISUPP_RESULT_E scan_result = *result;
    printf("wifi_netlink_notify_scan_result\n");

    wifi_msg = (WIFI_MESSAGE_T *)freertos_malloc(sizeof(WIFI_MESSAGE_T));

    if (scan_result == WIFISUPP_RESULT_SUCC)
    {
        wifi_msg->msg_type = WIFI_MESSAGE_NOTIFY_SCAN_RESULT_SUCC;
    }
    else if (scan_result == WIFISUPP_RESULT_FAIL)
    {
        wifi_msg->msg_type = WIFI_MESSAGE_NOTIFY_SCAN_RESULT_FAIL;
    }
    else
    {
        wifi_msg->msg_type = WIFI_MESSAGE_NUM;
    }
    wifi_msg->msg_data = NULL;

    receiver_tcb = &wifi_daemon_task_tcb;
    msg_size = sizeof(*wifi_msg);
    msg_ptr = (void*)wifi_msg;
    //OSTaskQPost(receiver_tcb, msg_ptr, msg_size, OS_OPT_POST_FIFO, &err);

    err = xQueueSend(wifi_event_queue_handle, msg_ptr, 0);
    if (err == pdTRUE)
    {
        //DEBUGPRINT("\n\rwifi_netlink_notify_scan_result: OSTaskQPost ok!\n");
        ret = 0;
    }
    else if (err == errQUEUE_FULL)
    {
        DEBUGPRINT("\n\rwifi netlink: target task wifi_test_task msg queue is full!\n");
        ret = -1;
    }

    return ret;
}

int wifi_netlink_indicate_connect(WIFISUPP_CONNECT_RESULT_T *connect_result)
{
    rk_err_t      err;
    int ret = 0;
    void    *msg_ptr = NULL;
    int msg_size = 0;
    _os_task    *receiver_tcb;
    WIFI_MESSAGE_T *wifi_msg;

    if (!p_wifi_netlink)
    {
        DEBUGPRINT("\n\rwifi netlink: indicate connect error, wifi_netlink not initialized!\n");
        return -1;
    }

    wifi_msg = (WIFI_MESSAGE_T *)freertos_malloc(sizeof(WIFI_MESSAGE_T));

    if (connect_result->result == WIFISUPP_RESULT_SUCC)
    {
        memcpy(&p_wifi_netlink->connected_ap_info, connect_result, sizeof(WIFISUPP_CONNECT_RESULT_T));
        p_wifi_netlink->link_status = WIFI_NETLINK_STATUS_LINKED;
        wifi_msg->msg_type = WIFI_MESSAGE_INDICATE_CONNECT;
        DEBUGPRINT("\n\rwifi netlink: indicate connect, connected to ap: %s\n", &connect_result->ssid.ssid);
    }
    else
    {
        p_wifi_netlink->link_status = WIFI_NETLINK_STATUS_NO_LINK;
        wifi_msg->msg_type = WIFI_MESSAGE_INDICATE_DISCONNECT;
        DEBUGPRINT("\n\rwifi netlink: indicate connect, connect failed!\n");
    }
    wifi_msg->msg_data = NULL;

    receiver_tcb = &wifi_daemon_task_tcb;
    msg_size = sizeof(*wifi_msg);
    msg_ptr = (void*)wifi_msg;
    //OSTaskQPost(receiver_tcb, msg_ptr, msg_size, OS_OPT_POST_FIFO, &err);
    err = xQueueSend(wifi_event_queue_handle, msg_ptr, 0);
    if (err == pdTRUE)
    {
        //DEBUGPRINT("\n\rwifi_netlink_indicate_connect: OSTaskQPost ok!\n");
        ret = 0;
    }
    else if (err == errQUEUE_FULL)
    {
        DEBUGPRINT("\n\rwifi netlink: target task wifi_test_task msg queue is full!\n");
        ret = -1;
    }
    return ret;
}

int wifi_netlink_indicate_disconnect(WIFISUPP_DISCONNECT_INFO_T *disconnect_result)
{
    rk_err_t      err;
    int ret = 0;
    void    *msg_ptr = NULL;
    int msg_size = 0;
    _os_task    *receiver_tcb;
    WIFI_MESSAGE_T *wifi_msg;

    if (!p_wifi_netlink)
    {
        DEBUGPRINT("\n\rwifi netlink: indicate disconnect error, wifi_netlink not initialized!\n");
        return -1;
    }

    if ((p_wifi_netlink->link_status == WIFI_NETLINK_STATUS_NO_LINK ||
         p_wifi_netlink->link_status == WIFI_NETLINK_STATUS_NO_LINK_SCAN))
    {
        //do nothing
        return 0;
    }
    else if (p_wifi_netlink->link_status == WIFI_NETLINK_STATUS_LINKING)
    {

        p_wifi_netlink->link_status = WIFI_NETLINK_STATUS_NO_LINK;
        //DEBUGPRINT("\n\rwifi_netlink_indicate_disconnect, disconnect with ap: %s", &disconnect_result->ssid.ssid);
    }
    else
    {
        if ((disconnect_result->ssid.ssid_len == p_wifi_netlink->connected_ap_info.ssid.ssid_len) &&
            (!memcmp(&disconnect_result->ssid.ssid, &p_wifi_netlink->connected_ap_info.ssid.ssid, disconnect_result->ssid.ssid_len)))
        {
            memset(&p_wifi_netlink->connected_ap_info, 0, sizeof(WIFISUPP_CONNECT_RESULT_T));
            p_wifi_netlink->link_status = WIFI_NETLINK_STATUS_NO_LINK;

            dhcp_client_stop();

            DEBUGPRINT("\n\rwifi netlink: indicate disconnect, disconnected with ap: %s\n", &disconnect_result->ssid.ssid);
        }
        else
        {
            DEBUGPRINT("\n\rwifi netlink: indicate disconnect, ssid not match, ignored!\n");
            DEBUGPRINT("disconnect ssid %s len %d connected ssid %s len %d\n", &disconnect_result->ssid.ssid, disconnect_result->ssid.ssid_len,
                       &p_wifi_netlink->connected_ap_info.ssid.ssid, p_wifi_netlink->connected_ap_info.ssid.ssid_len);
            return ret;
        }
    }

    wifi_msg = (WIFI_MESSAGE_T *)freertos_malloc(sizeof(WIFI_MESSAGE_T));

    wifi_msg->msg_type = WIFI_MESSAGE_INDICATE_DISCONNECT;
    wifi_msg->msg_data = NULL;

    receiver_tcb = &wifi_daemon_task_tcb;
    msg_size = sizeof(*wifi_msg);
    msg_ptr = (void*)wifi_msg;
//  OSTaskQPost(receiver_tcb, msg_ptr, msg_size, OS_OPT_POST_FIFO, &err);
    err = xQueueSend(wifi_event_queue_handle, msg_ptr, 0);
    if (err == pdTRUE)
    {
        //DEBUGPRINT("\n\rwifi_netlink_indicate_disconnect: OSTaskQPost ok!\n");
        ret = 0;
    }
    else if (err == errQUEUE_FULL)
    {
        DEBUGPRINT("\n\rwifi netlink: target task wifi_test_task msg queue is full!\n");
        ret = -1;
    }
    return ret;
}

WIFI_NETLINK_OPERATIONS_T wifi_netlink_ops =
{
    wifi_netlink_init,
    wifi_netlink_deinit,
    wifi_netlink_open_dev,
    wifi_netlink_close_dev,
    wifi_netlink_set_scan,
    wifi_netlink_get_scan_list,
    wifi_netlink_connect_req,
    wifi_netlink_disconnect_req,
    wifi_netlink_set_ipaddr,
    wifi_netlink_start_ap,
    wifi_netlink_get_status,
    wifi_netlink_get_memory,
    wifi_netlink_suspend_query,
    wifi_netlink_suspend,
    wifi_netlink_resume,
#if CONFIG_INTERNAL_DEBUG
    wifi_netlink_read_mac_reg,
    wifi_netlink_write_mac_reg,
    wifi_netlink_read_phy_reg,
    wifi_netlink_write_phy_reg,
    wifi_netlink_set_channel,
    wifi_netlink_set_rate,
    wifi_netlink_enable_ps,
    wifi_netlink_disable_ps,
    wifi_netlink_get_ps,
#endif
    //wifi_netlink_user_connect_action,
    //wifi_netlink_user_disconnect_action,
    wifi_netlink_notify_scan_result,
    wifi_netlink_indicate_connect,
    wifi_netlink_indicate_disconnect,
};

#else

WIFI_NETLINK_OPERATIONS_T wifi_netlink_ops =
{
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
#if CONFIG_INTERNAL_DEBUG
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
#endif
    //wifi_netlink_user_connect_action,
    //wifi_netlink_user_disconnect_action,
    NULL,
    NULL,
    NULL,
};

#endif

//#pragma arm section code
#endif /*#ifdef __DRIVER_I6000_WIFI_C__*/
