#include "FreeRTOS.h"
#include "RKOS.h"
#include <stdarg.h>
#include "app_cfg.h"
#include "wlan_intf_def.h"
#include "wifi_db.h"
#ifdef __DRIVER_I6000_WIFI_C__


RKI6000_WIFI_SAVEINFO g_wifi_ap_saveinfo;
pSemaphore wifi_saveinfo_rwlock;

void wifi_init_db(void)
{
    if(g_wifi_ap_saveinfo.checksum != 0xA567)
        memset(&g_wifi_ap_saveinfo, 0, sizeof(RKI6000_WIFI_SAVEINFO));
    g_wifi_ap_saveinfo.checksum = 0xA567;
    wifi_saveinfo_rwlock = rkos_semaphore_create(1, 1);
}

void wifi_deinit_db(void)
{
    rkos_semaphore_delete(wifi_saveinfo_rwlock);
}


size_t wifi_add_db(RKI6000_WIFI_AP * p_ap)
{
    int found = 0;
    int index = 0;
    int i;
    rkos_semaphore_take(wifi_saveinfo_rwlock, MAX_DELAY);
    for(i=0; i<MAX_WIFI_DB_MUN; i++)
    {
        if(memcmp(g_wifi_ap_saveinfo.ap[i].bssid,p_ap->bssid, 6) == 0)
        {
            found = 1;
            break;
        }

    }
    index = found ? found :g_wifi_ap_saveinfo.w_index;
    memcpy(&g_wifi_ap_saveinfo.ap[index],p_ap, sizeof(RKI6000_WIFI_AP));
    if(found == 0)
    {
        g_wifi_ap_saveinfo.w_index++;
        if(g_wifi_ap_saveinfo.w_index == MAX_WIFI_DB_MUN)
        {
            g_wifi_ap_saveinfo.w_index = 0;

        }
        if(g_wifi_ap_saveinfo.total_num < (MAX_WIFI_DB_MUN+1))
        {
            g_wifi_ap_saveinfo.total_num++;

        }
    }
    rkos_semaphore_give(wifi_saveinfo_rwlock);
}

size_t wifi_delete_db(RKI6000_WIFI_AP * p_ap)
{
    int i;
    rkos_semaphore_take(wifi_saveinfo_rwlock, MAX_DELAY);
    for(i=0; i<MAX_WIFI_DB_MUN; i++)
    {
        if(memcmp(g_wifi_ap_saveinfo.ap[i].bssid,p_ap->bssid, 6) == 0)
        {
            memset(&g_wifi_ap_saveinfo.ap[i],0,sizeof(sizeof(RKI6000_WIFI_AP)));
            if(i == (g_wifi_ap_saveinfo.w_index-1))
            {
                g_wifi_ap_saveinfo.w_index = i;
            }

            if(g_wifi_ap_saveinfo.total_num >0)
            {
                g_wifi_ap_saveinfo.total_num--;

            }
            break;
        }

    }

    rkos_semaphore_give(wifi_saveinfo_rwlock);
}

void wifi_savedb_to_disk(void)
{
    uint8* buf;
    rkos_semaphore_take(wifi_saveinfo_rwlock, MAX_DELAY);
    buf = rkos_memory_malloc(sizeof(RKI6000_WIFI_SAVEINFO)+512);
    memset(buf, 0, sizeof(RKI6000_WIFI_SAVEINFO)+512);
    memcpy(buf, &g_wifi_ap_saveinfo, sizeof(RKI6000_WIFI_SAVEINFO));
    LUNWriteDB(gSysConfig.WifiSSIDStartLBA, sizeof(RKI6000_WIFI_SAVEINFO)/512+1, buf);
    rkos_memory_free(buf);
    rkos_semaphore_give(wifi_saveinfo_rwlock);

}
void wifi_loaddb_from_disk(void)
{
    uint8* buf;
    //rkos_semaphore_take(wifi_saveinfo_rwlock, MAX_DELAY);
    buf = rkos_memory_malloc(sizeof(RKI6000_WIFI_SAVEINFO)+512);
    LUNReadDB(gSysConfig.WifiSSIDStartLBA, sizeof(RKI6000_WIFI_SAVEINFO)/512+1, buf);
    memcpy(&g_wifi_ap_saveinfo, buf, sizeof(RKI6000_WIFI_SAVEINFO));
    rkos_memory_free(buf);
    //rkos_semaphore_give(wifi_saveinfo_rwlock);
}

size_t wifi_get_bd_num(void)
{
    return g_wifi_ap_saveinfo.total_num;

}

void wifi_db_rw_lock(void)
{
    rkos_semaphore_take(wifi_saveinfo_rwlock, MAX_DELAY);
}

void wifi_db_rw_unlock(void)
{
    rkos_semaphore_give(wifi_saveinfo_rwlock);
}

void wifi_update_last_ap_index(char *bssid)
{
    int len_new_ssid;
    int len_db_ssid;
    int i;
    for(i=0; i<MAX_WIFI_DB_MUN; i++)
    {
        if(memcmp(g_wifi_ap_saveinfo.ap[i].bssid,bssid, 6) == 0)
        {
            g_wifi_ap_saveinfo.last_index = i;

            break;
        }
    }
}


#endif /*#ifdef __DRIVER_I6000_WIFI_C__*/
