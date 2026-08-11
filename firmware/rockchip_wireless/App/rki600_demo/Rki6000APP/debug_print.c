/*
     debug print module

*/

#include "debug_print.h"

#ifdef DEBUGPRINT

/*use DEBUG_DUMP_DATA to invoke*/
void _debug_print_dump_data(char *mem, int mem_size)
{
    int i;
    char j;
    char *pchar=mem;

    if (mem_size == 0) return;

    for(i=0; i<mem_size; i++)
    {
        /* print hex*/
        DEBUGPRINT("%02X ",*pchar);
        pchar++;

        /* print ascii */
        if ((i+1)%16==0)
        {
            DEBUGPRINT("        ");  /*8 spaces*/
            for(j=0; j<16; j++)
            {
                if((*(pchar-16+j))>0x1f && (*(pchar-16+j))<0x7f)     /* is print */
                {
                    DEBUGPRINT("%c",*(pchar-16+j));
                }
                else
                {
                    DEBUGPRINT(".");
                }

            }
            DEBUGPRINT("\r\n");
        }

    }

    /*print last line ascii */
    j = 16-(i%16);
    if(j!=16)
    {
        for(i=0; i<j; i++)
        {
            DEBUGPRINT("   ");
        }
        DEBUGPRINT("        ");  /*8 spaces*/
        for(i=0; i<16-j; i++)
        {
            if((*(pchar-(16-j)+i))>0x1f && (*(pchar-(16-j)+i))<0x7f)    /* is print */
            {
                DEBUGPRINT("%c",*(pchar-(16-j)+i));
            }
            else
            {
                DEBUGPRINT(".");
            }

        }
        DEBUGPRINT("\r\n");
    }

}

#endif
