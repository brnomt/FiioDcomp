//#include "co_printf.h"

/////////////////////////////////////
/*      For Debug Print Module                       */
/*                                                                 */
/////////////////////////////////////

#define ERROR_LEVEL             1
#define WARNING_LEVEL           2
#define INFO_LEVEL              3


/*NEED TO DEFINE OUTPUT METHOD*/
#define DEBUG_PRINT co_printf
//#define DEBUG_PRINT printf

/*Moudle list need to set*/
/*set debug level for each file*/

#define ETHIF_LEVEL     INFO_LEVEL
#define MAIN_LEVEL  INFO_LEVEL
#define HTTPD_LEVEL     INFO_LEVEL
#define TCP_OUT_LEVEL   INFO_LEVEL
#define SYS_ARCH_LEVEL  INFO_LEVEL




