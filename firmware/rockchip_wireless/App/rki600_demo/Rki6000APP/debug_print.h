#include "app_cfg.h"
#include "debug_cfg.h"

// used for global cfg control, to set if debug_print feature enable
#if DBG_DEBUG_PRINT_ENABLE == 1

#define _CONCAT(a, b) a##b
#define CONCAT(a, b) _CONCAT(a, b)
#define _NAME(a) #a
#define NAME(a) _NAME(a)

/************  Example  ***********************************************/
//      CO_DEBUG_PRINTF("WARN","hey, x=%d\n", x);
//
//      \r\nWARN[module aa,line 100]:hey, x=10
//

#define WHERESTR  "[module %s, line %d]: "
#define WHEREARG  NAME(MOUDLE), __LINE__
#define DEBUGPRINT(...)       printf(__VA_ARGS__)//DEBUG_PRINT(__VA_ARGS__)

#define CO_DEBUG_PRINTF(level,...)  do{ \
                                        DEBUGPRINT( level WHERESTR , WHEREARG);\
                                        DEBUGPRINT( __VA_ARGS__);\
                                        DEBUGPRINT( "\r\n");\
                                    }while(0);



#if ( CONCAT(MOUDLE, _LEVEL) >= INFO_LEVEL )
#define DEBUG_INFO(...) CO_DEBUG_PRINTF("INF", __VA_ARGS__)
#else
#define DEBUG_INFO(...)
#endif


#if ( CONCAT(MOUDLE, _LEVEL) >= WARNING_LEVEL )
#define DEBUG_WARNING(...)  CO_DEBUG_PRINTF("WAR", __VA_ARGS__)
#else
#define DEBUG_WARNING(...)
#endif


#if ( CONCAT(MOUDLE, _LEVEL) >= ERROR_LEVEL )
#define DEBUG_ERROR(...) CO_DEBUG_PRINTF("ERR", __VA_ARGS__)
#else
#define DEBUG_ERROR(...)
#endif




void _debug_print_dump_data(char *mem, int mem_size);

/*only dump at info level*/
#if ( CONCAT(MOUDLE, _LEVEL) >= INFO_LEVEL )
#define DEBUG_DUMP_DATA(memaddr, memlen) do{ \
                                            DEBUGPRINT("\r\n"  WHERESTR , WHEREARG);\
                                            DEBUGPRINT("\r\n");\
                                            _debug_print_dump_data(memaddr,memlen);\
                                           }while(0);

#else
#define DEBUG_DUMP_DATA(...)
#endif


#define DEBUG_RAW(...) DEBUG_PRINT(__VA_ARGS__)

#else

#define DEBUG_INFO(...)
#define DEBUG_WARNING(...)
#define DEBUG_ERROR(...)
#define DEBUG_DUMP_DATA(...)
#define DEBUG_RAW(...)
#define DEBUGPRINT(...)

#endif

#define DEBUG_ASSERT(expr)  do{\
                             if (expr)\
                                { ; }\
                             else \
                                {DEBUGPRINT("ASSERT","%s",#expr);}\
                             }while(0);


