/* FunUSBInterface.h — USB interface hooks (Service.c). */
#ifndef FUNUSBINTERFACE_H
#define FUNUSBINTERFACE_H
#include "typedef.h"
#endif

/* ---- USB host channel info (Service.c) ---- */
#ifndef FUNUSB_CHN
#define FUNUSB_CHN
typedef struct {
    uint32 chn_id;
    uint32 ep_addr;
    uint32 max_pkt;
    uint32 xfer_len;
    uint32 status;
} UHC_CHN_INFO;
#endif

/* ---- USB host channel info (Service.c) ---- */
#ifndef FUNUSB_CHN
#define FUNUSB_CHN
typedef struct {
    uint32 chn_id;
    uint32 ep_addr;
    uint32 max_pkt;
    uint32 xfer_len;
    uint32 status;
} UHC_CHN_INFO;
#endif
