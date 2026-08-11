/* lm3s6965evb (Cortex-M3): UART0 @ 0x4000C000. Blink GPIO + UART output. */
#define UART0 0x4000C000u
#define GPIOF 0x40025000u   /* LED on PF1..PF3 */

static void uart_putc(char c) {
    volatile unsigned int *dr = (volatile unsigned int *)(UART0 + 0x000);
    volatile unsigned int *fr = (volatile unsigned int *)(UART0 + 0x018);
    while (*fr & (1 << 5)) ;
    *dr = c;
}
void _start(void)
{
    const char *msg = "ReChord-lm3s-OK\r\n";
    while (*msg) uart_putc(*msg++);
    for (;;) ;
}
void _default_handler(void) { for (;;) ; }
__attribute__((section(".vectors")))
const unsigned int vector_table[8] = {
    0x20010000, (unsigned int)_start,
    (unsigned int)_default_handler, (unsigned int)_default_handler,
    (unsigned int)_default_handler, (unsigned int)_default_handler,
    (unsigned int)_default_handler, 0,
};
