#ifndef _RKNANO_DISPLAY_STDINT_H_
#define _RKNANO_DISPLAY_STDINT_H_

/* ReChord: los typedefs int8_t/uint8_t/... los provee GCC <stdint.h>
   (incluido por armcc_compat.h). Solo se definen los tipos propios. */
#include <stdint.h>

typedef unsigned short Ucs2;


#define Font_Comp_Table_8859_START 0
#define Font_Comp_Table_8859_CNT (8449 - 11 + 1)
#define Font_Comp_Table_8859_LEN 2


#define Font12_8859_CompData_START (Font_Comp_Table_8859_CNT * Font_Comp_Table_8859_LEN + Font_Comp_Table_8859_START)
#define Font12_8859_CompData_CNT (436 - 13 + 1)
#define Font12_8859_CompData_LEN 24

#define Font12_8859_Width_START (Font12_8859_CompData_CNT * Font12_8859_CompData_LEN + Font12_8859_CompData_START)
#define Font12_8859_Width_CNT (436 - 13 + 1)
#define Font12_8859_Width_LEN 1

#define Font12_JKC_CompData_START (Font12_8859_Width_CNT * Font12_8859_Width_LEN + Font12_8859_Width_START)
#define Font12_JKC_CompData_CNT (31694 - 13 + 1)
#define Font12_JKC_CompData_LEN 24

#define Font12_CJK_CompData_START (Font12_JKC_CompData_CNT * Font12_JKC_CompData_LEN + Font12_JKC_CompData_START)
#define Font12_CJK_CompData_CNT (31694 - 13 + 1)
#define Font12_CJK_CompData_LEN 24

#define Font_Comp_Table_Asia_START (Font12_CJK_CompData_CNT * Font12_CJK_CompData_LEN + Font12_CJK_CompData_START)
#define Font_Comp_Table_Asia_CNT (65546 - 11 + 1)
#define Font_Comp_Table_Asia_LEN 2

#define FONT_TAIWEN_START (Font_Comp_Table_Asia_CNT * Font_Comp_Table_Asia_LEN + Font_Comp_Table_Asia_START)
#define FONT_TAIWEN_CNT (148 - 13 + 1)
#define FONT_TAIWEN_LEN 24

extern unsigned long FontLogicAddress;

#endif /* _RKNANO_DISPLAY_STDINT_H_ */


