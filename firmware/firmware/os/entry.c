/*
 * firmware/firmware/os/entry.c
 * Reconstructed from Ghidra decompilation of firmware v3.7.0
 *
 * firmware_entry @ 0x03000010
 *   → calls boot ROM for init, then dispatches to subsystems
 *
 * RKnano boot sequence:
 *   1. Boot ROM initializes clocks, stack, flash controller
 *   2. Bootloader (section 2) verifies signatures, copies segments
 *   3. firmware_entry() starts at 0x03000010
 *   4. Calls ROM init functions, then enters main event loop
 */

#include "../firmware.h"
#include "os_api.h"
#include "../../apps/audio/audio_service.h"
#include "../../apps/ui/ui_theme.h"
#include "../../codecs/codec_api.h"
#include "../../drivers.h"

/* Global state structure (inferred from multiple function decompilations) */
typedef struct {
    uint8_t  current_mode;          /* 0x1ba: media type (0=flash,1=card?) */
    uint8_t  file_count;            /* 0x1bb: number of files */
    uint8_t  boot_stage;            /* 0x1bc: 0=init, 1=scan, 2=playback */
    uint16_t lcd_width;             /* 0x21d: display width */
    uint8_t  audio_output;          /* 0x34a: DAC filter/mode */
    uint8_t  dsp_active;            /* 0x356: DSP enabled flag */
    uint16_t format_signature[2];   /* 0x???: format detection bytes */
} GlobalState;

static GlobalState g_state;

/*
 * firmware_entry() - main entry point
 * @ 0x03000010
 *
 * Called by bootloader after segment copy. Sets up hardware,
 * initializes subsystems, enters main loop.
 */
void firmware_entry(uint16_t *param) {
    /* 
     * Boot ROM call at 0x02feeedc - allocate hardware context
     * The if-check confirms context allocation succeeded
     * 0x1dc = 476 bytes context size
     */
    void *context = rom_alloc(0x1dc);
    
    /* C runtime init - zero BSS, init data sections */
    firmware_init_runtime(); /* FUN_030000da @ 0x030000da */

    if (context != NULL) {
        /* ROM hardware init sequence */
        rom_init_timer(0x1dc);    /* func_0x02feeebe - init hardware timer */
        rom_init_gpio(0x16f);     /* func_0x02feeebe - GPIO bank init */
        rom_init_dma(0x16f);      /* func_0x02feeebe - DMA controller init */
    }

    /*
     * Main initialization sequence:
     *   FormatList_Init → MusicInit → MusicService_Init → event loop
     */
    FormatList_Init();           /* @ 0x03013c10 */
    MusicInit();                 /* @ 0x0302b9d8 */
    
    /* Enter event-driven main loop - never returns */
    while (1) {
        main_event_loop();
    }
}

/*
 * firmware_init_runtime()
 * @ 0x030000da
 *
 * Sets up the global state structure with defaults derived from
 * a format table lookup. The switch statement maps mode codes.
 */
void firmware_init_runtime(void) {
    uint16_t mode_codes[] = {0, 1, 2, 3, 4, 5, 8, 10};
    uint16_t mode = 0;
    uint8_t i;

    g_state.lcd_width = 8;
    
    /* Look up mode from parameter */
    for (i = 0; i < sizeof(mode_codes)/sizeof(mode_codes[0]); i++) {
        if (mode_codes[i] == g_state.current_mode) {
            mode = mode_codes[i];
            break;
        }
    }
    
    g_state.boot_stage = (uint8_t)mode;
    g_state.dsp_active = (uint8_t)mode;
    
    /* Clamp values */
    if (g_state.dsp_active > 12) g_state.dsp_active = 13;
    if (g_state.boot_stage > 12) g_state.boot_stage = 13;
    
    /* Calculate display dimensions (LCD character grid?) */
    uint8_t char_width = g_state.dsp_active;
    uint8_t cols = ((char_width / 6) * 3 & 0x7f) * 2;
    
    if (char_width > cols) {
        cols = cols - 6;
    }
    
    g_state.lcd_width = cols;
    uint8_t remaining = g_state.dsp_active - cols;
    
    uint8_t padding = 8 - (cols & 0xff);
    if (padding > 6) padding = 6;
    
    /* Padding calculation - likely LCD timing */
    uint8_t unknown = 0;
}

/*
 * main_event_loop()
 *
 * RKnano's cooperative event loop. Polls hardware events
 * (key presses, USB mode changes, timer ticks) and dispatches
 * to the appropriate handler.
 */
static void main_event_loop(void) {
    uint32_t event = 0;
    
    while (1) {
        /* Poll for pending events */
        event = event_check(0xFF);        
        if (event == 0) {
            os_delay_ms(10);
            continue;
        }
        
        /* Dispatch based on event */
        switch (event) {
        case 0x23: /* Audio init complete */
            break;
        case 0x2a: /* Music playback request */
            MusicInit();
            break;
        case 0x55: /* Timer tick / heartbeat */
            break;
        case 0x59: /* Playback started */
            AudioPlayback_Start(NULL);
            break;
        case 0xf5: /* USB mode change */
            /* USB mode switch handled by ROM */
            break;
        case 0x114: /* System ready - enter idle */
            break;
        case 0x159: /* File operation complete */
            break;
        default:
            break;
        }
    }
}
