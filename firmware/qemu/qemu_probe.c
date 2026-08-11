/* Probe: which base does the mps2 CLCD respond at? */
#define REG(o) (*(volatile unsigned int *)(0x40000000u + (o)))
volatile unsigned int sink;

void _start(void)
{
    /* Try writing+reading a marker at candidate CLCD offsets */
    unsigned int bases[] = {0x41000000u, 0x41100000u, 0x40020000u, 0x40030000u, 0x40000000u};
    for (int b = 0; b < 5; b++) {
        volatile unsigned int *p = (volatile unsigned int *)(bases[b]);
        *p = 0xABCD1234u;
        sink = *p;   /* read back */
    }
    for (;;) ;
}
void _default_handler(void) { for (;;) ; }
__attribute__((section(".vectors")))
const unsigned int vector_table[8] = {
    0x28040000, (unsigned int)_start,
    (unsigned int)_default_handler, (unsigned int)_default_handler,
    (unsigned int)_default_handler, (unsigned int)_default_handler,
    (unsigned int)_default_handler, 0,
};
