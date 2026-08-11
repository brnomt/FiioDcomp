/* vexpress-a9: UART0 @ 0x10009000 (PL011). Send 'R' to prove code runs. */
#define UART0 0x10009000u
static void uart_putc(char c) {
    volatile unsigned int *dr = (volatile unsigned int *)UART0;
    volatile unsigned int *fr = (volatile unsigned int *)(UART0 + 0x18);
    while (*fr & (1 << 5)) ;  /* TXFF */
    *dr = c;
}
void _start(void)
{
    const char *msg = "ReChord-vexpress-OK\r\n";
    while (*msg) uart_putc(*msg++);
    for (;;) ;
}
