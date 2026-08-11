#ifndef _WIFI_NETLINK_H
#define _WIFI_NETLINK_H
#include "app_cfg.h"
#include "wlan_intf_def.h"

#define SUPPORT_MAX_AP_NUM  32  //16

#define WIFI_TASK_MAX   4

/* Some usefull constants */
#define KILO    1e3
#define MEGA 1e6
#define GIGA    1e9

#undef TRUE
#define TRUE        1

#undef FALSE
#define FALSE   0

typedef enum
{
    WIFI_MESSAGE_NOTIFY_SCAN_RESULT_SUCC = 0,
    WIFI_MESSAGE_NOTIFY_SCAN_RESULT_FAIL,
    WIFI_MESSAGE_USER_CONNECT,
    WIFI_MESSAGE_USER_DISCONNECT,
    WIFI_MESSAGE_INDICATE_CONNECT,
    WIFI_MESSAGE_INDICATE_DISCONNECT,
    WIFI_MESSAGE_SHELL_COMMAND,
    WIFI_MESSAGE_NUM
} WIFI_MESSAGE_TYPE_E;

typedef enum
{
    WIFI_NETLINK_STATUS_NO_LINK = 0,
    WIFI_NETLINK_STATUS_NO_LINK_SCAN,
    WIFI_NETLINK_STATUS_LINKING,
    WIFI_NETLINK_STATUS_LINKED,
    WIFI_NETLINK_STATUS_LINKED_SCAN,
    WIFI_NETLINK_STATUS_LINKED_DHCP,
    WIFI_NETLINK_STATUS_LINKED_CONFIGED,
    WIFI_NETLINK_STATUS_NUM
} WIFI_NETLINK_STATUS_E;

typedef struct wifi_message
{
    WIFI_MESSAGE_TYPE_E msg_type;
    void    *msg_data;
} WIFI_MESSAGE_T;

typedef struct wifi_netlink_info
{
    uint8 device_opened;
    uint8 ap_started;
    WIFI_NETLINK_STATUS_E link_status;
    WIFI_NETLINK_STATUS_E saved_link_status;

    uint8 scan_ap_num;
    WIFISUPP_SCAN_AP_INFO_T scan_list[SUPPORT_MAX_AP_NUM];
    WIFISUPP_SCAN_AP_INFO_T *scan_list_head;

    WIFISUPP_SSID_CONFIG_T connect_info;
    WIFISUPP_CONNECT_RESULT_T connected_ap_info;
    uint8  ip_addr[4];

    uint8 ap_security;
    uint8 ap_ssid[32+1];
    uint8 ap_password[32+1];

#if CONFIG_INTERNAL_DEBUG
    WIFISUPP_PRIV_REQ_INFO_T priv_req;
#endif
} WIFI_NETLINK_INFO_T;

typedef struct
{
    WIFI_NETLINK_INFO_T * (*init_func)(void);
    int (*deinit_func)(WIFI_NETLINK_INFO_T *wifi_netlink);
    int (*open_dev_func)(WIFI_NETLINK_INFO_T *wifi_netlink);
    int (*close_dev_func)(WIFI_NETLINK_INFO_T *wifi_netlink);

    int (*set_scan_func)(WIFI_NETLINK_INFO_T *wifi_netlink);
    int (*get_scan_list_func)(WIFI_NETLINK_INFO_T *wifi_netlink);
    int (*connect_req_func)(WIFI_NETLINK_INFO_T *wifi_netlink, uint8 *ssid, uint8 *password);
    int (*disconnect_req_func)(WIFI_NETLINK_INFO_T *wifi_netlink);
    int (*set_ipaddr_func)(WIFI_NETLINK_INFO_T *wifi_netlink, unsigned int *ipaddr);
    int (*start_ap_func)(WIFI_NETLINK_INFO_T *wifi_netlink, uint8 *ssid, uint8 *password);
    int (*get_status_func)(WIFI_NETLINK_INFO_T *wifi_netlink);
    int (*get_memory_func)(WIFI_NETLINK_INFO_T *wifi_netlink);
    int (*suspend_query_func)(WIFI_NETLINK_INFO_T *wifi_netlink);
    int (*suspend_func)(WIFI_NETLINK_INFO_T *wifi_netlink);
    int (*resume_func)(WIFI_NETLINK_INFO_T *wifi_netlink);

#if CONFIG_INTERNAL_DEBUG
    int (*read_mac_reg)(WIFI_NETLINK_INFO_T *wifi_netlink, uint32 read_addr);
    int (*write_mac_reg)(WIFI_NETLINK_INFO_T *wifi_netlink, uint32 write_addr, uint32 write_value);
    int (*read_phy_reg)(WIFI_NETLINK_INFO_T *wifi_netlink, uint32 read_addr);
    int (*write_phy_reg)(WIFI_NETLINK_INFO_T *wifi_netlink, uint32 write_addr, uint32 write_value);
    int (*set_channel)(WIFI_NETLINK_INFO_T *wifi_netlink, uint32 channel);
    int (*set_rate)(WIFI_NETLINK_INFO_T *wifi_netlink, uint32 rate);
    int (*enable_ps)(WIFI_NETLINK_INFO_T *wifi_netlink);
    int (*disable_ps)(WIFI_NETLINK_INFO_T *wifi_netlink);
    int (*get_ps)(WIFI_NETLINK_INFO_T *wifi_netlink);
#endif
    //int (*user_connect_func)(void);
    //int (*user_disconnect_func)(void);

    int (*notify_scan_result_func)(WIFISUPP_RESULT_E *result);
    int (*indicate_connect_func)(WIFISUPP_CONNECT_RESULT_T *connect_result);
    int (*indicate_disconnect_func)(WIFISUPP_DISCONNECT_INFO_T *disconnect_result);
} WIFI_NETLINK_OPERATIONS_T;


#endif
