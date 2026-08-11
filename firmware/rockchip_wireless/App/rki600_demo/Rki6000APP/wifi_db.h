#ifndef _WIFI_DB_H
#define _WIFI_DB_H


#define MAX_WIFI_DB_MUN 5

typedef struct {
    uint8     key[64+1];               /* target AP's password */
    uint8     key_len;            /* length of password */
    uint8     ssid_len;              /* target AP's name */
    uint8     ssid_value[32+1];
    uint8     bssid[6];              /* target AP's mac address */
    uint32    security_type;
} RKI6000_WIFI_AP;


typedef struct {
    RKI6000_WIFI_AP ap[MAX_WIFI_DB_MUN];     /* target AP's password */
    uint8 last_index;
    uint8 w_index;
    uint8 total_num;
    uint16 checksum; /* after init ,checksum == 0xA567 */

} RKI6000_WIFI_SAVEINFO;


void wifi_init_db(void);
void wifi_deinit_db(void);
size_t wifi_add_db(RKI6000_WIFI_AP * p_ap);
size_t wifi_delete_db(RKI6000_WIFI_AP * p_ap);
void wifi_savedb_to_disk(void);
void wifi_loaddb_from_disk(void);
size_t wifi_get_bd_num(void);
void wifi_db_rw_lock(void);
void wifi_db_rw_unlock(void);

#endif
