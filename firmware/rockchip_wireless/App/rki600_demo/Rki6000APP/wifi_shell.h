#ifndef _WIFI_SHELL_H
#define _WIFI_SHELL_H

#define MAX_SSID_LEN 32

#define _ATTR_I6000_SHELL_               __attribute__((section("i6000_shell")))

void  wifi_test_task (void *p_arg);
rk_err_t i6000_wifi_dev_shell(HDC dev, uint8 * pstr);

#endif
