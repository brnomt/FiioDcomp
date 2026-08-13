/* stubs.c — ReChord link stubs.
 *
 * Defines globals (zero) + function stubs referenced by the Rockchip
 * SDK that come from the FiiO layer / ROM API.
 *
 * CRITICAL RULE (learned the hard way, twice):
 *   A symbol the SDK CALLS with () MUST be defined as a FUNCTION, never
 *   as a zeroed VARIABLE. If stubs.c defines `uint32_t Foo;` and the SDK
 *   does `Foo(...)`, the CPU branches to the DATA address and executes
 *   zeros -> hard fault at the first call (BSP_Init2 -> MailBoxEnableA2BInt
 *   -> crash before Main2's loop; this was the V0.2-V0.5 "no heartbeat"
 *   bug). Classification is by call-site audit: `name(` in SDK .c files
 *   => function; `&name` or plain data use => variable.
 *
 * Fixed in this revision: MailBox*A2B/B2A, SysTick*2, Codec*2, bb_printf1,
 * TaskID2Str, FindFirst/NextFile, GetCurFileNum, GetGlobeFileNum,
 * GetLongFileName, GetTotalFiles, BuildDirInfo, PowerOff, GetAdcData,
 * ScuClockGateCtr, SetPllDefault, System_Power_On, MDDeInitAll,
 * HostGetChannelInfo, Gpio_SetPortDirec, Grf_*, SFlashGetBluetoothMac,
 * CheckAdcState, AdcPowerDown, BluetoothReconnectResult, Codec_*,
 * MusicWinPaint, bt_a2dp_connect, rk_print_string2.
 */
#include <stdint.h>
#include <string.h>

typedef unsigned int   uint32;
typedef unsigned long  ulong;
typedef unsigned short uint16;

/* ---- globals (zero-init) — DATA ONLY, never called with () ---- */
uint32_t AdcSamplingCh __attribute__((used));
uint32_t AudioCodecOpenErr __attribute__((used));
uint32_t AudioDecodeCnt __attribute__((used));
uint32_t AudioDecodeing __attribute__((used));
uint32_t AudioFileExtString __attribute__((used));
uint32_t AudioLen __attribute__((used));
uint32_t AudioNeedDecode __attribute__((used));
uint32_t AudioPlayState __attribute__((used));
uint32_t AudioPlayerState __attribute__((used));
uint32_t AudioPtr __attribute__((used));
uint32_t AutoPowerOffDisableCounter __attribute__((used));
uint32_t BacklightSystickCounterBack __attribute__((used));
uint32_t Batt_Level __attribute__((used));
uint32_t BatteryCounter __attribute__((used));
uint32_t BatteryCounter1 __attribute__((used));
uint32_t BatterySystickCounterBack __attribute__((used));
uint32_t BlueToothThread __attribute__((used));
uint32_t BtWinStatus __attribute__((used));
uint32_t ChargeFullFlag __attribute__((used));
uint32_t ChargeWin __attribute__((used));
uint32_t CodeLogicAddress __attribute__((used));
uint32_t CurrentCodec2 __attribute__((used));
uint32_t DataDiskID __attribute__((used));
uint32_t DefaultLanguage __attribute__((used));
uint32_t DefaultLanguageID __attribute__((used));
uint32_t DmaTransting __attribute__((used));
uint32_t FMThread __attribute__((used));
uint32_t FM_State_StepStation __attribute__((used));
uint32_t FileInfo __attribute__((used));
uint32_t FileOpenStringR __attribute__((used));
uint32_t FmStandbyFlag __attribute__((used));
uint32_t GBKLogicAddress __attribute__((used));
uint32_t IsBTOpened __attribute__((used));
uint32_t IsBackLightOn __attribute__((used));
uint32_t LanguageNum __attribute__((used));
uint32_t LowPowerWin __attribute__((used));
uint32_t MaxShuffleAllCount __attribute__((used));
uint32_t MdbBuildWin __attribute__((used));
uint32_t MenuLogicAddress __attribute__((used));
uint32_t MusicFileExtString __attribute__((used));
uint32_t MusicWin __attribute__((used));
uint32_t OutputVolOffset __attribute__((used));
uint32_t PicWin __attribute__((used));
uint32_t RadioWin __attribute__((used));
uint32_t RebootTag __attribute__((used));
uint32_t RecordFileExtString __attribute__((used));
uint32_t RecordThread __attribute__((used));
uint32_t RecordWin __attribute__((used));
uint32_t SetMenuLanguageInfo __attribute__((used));
uint32_t SetPowerOffFlag __attribute__((used));
uint32_t SysDiskID __attribute__((used));
uint32_t SysProgRawDiskCapacity __attribute__((used));
uint32_t SysTickCounter __attribute__((used));
uint32_t gBattery __attribute__((used));
uint32_t gLangSel __attribute__((used));
uint32_t gSysConfig __attribute__((used));
uint32_t gSysSetBLTimeArray __attribute__((used));
uint32_t gpRadioplayerRegKey __attribute__((used));
uint32_t chip_freq __attribute__((used));

/* ---- function stubs (return 0 / no-op) — these were mistakenly
 *      defined as VARIABLES before; every SDK call to them hard-faulted.
 *      They must stay FUNCTIONS (weak, so a real impl can override). ---- */

/* --- mailbox ROM APIs (A2B = AP->BB, B2A = BB->AP) --- */
__attribute__((weak)) int MailBoxWriteA2BCmd(uint32 cmd, uint32 id, uint32 channel) { (void)cmd; (void)id; (void)channel; return 0; }
__attribute__((weak)) int MailBoxWriteA2BData(uint32 data, uint32 id, uint32 channel) { (void)data; (void)id; (void)channel; return 0; }
__attribute__((weak)) int MailBoxReadB2ACmd(uint32 id, uint32 channel) { (void)id; (void)channel; return 0; }
__attribute__((weak)) int MailBoxReadB2AData(uint32 id, uint32 channel) { (void)id; (void)channel; return 0; }
__attribute__((weak)) int MailBoxEnableA2BInt(uint32 id, uint32 int_sel) { (void)id; (void)int_sel; return 0; }
__attribute__((weak)) int MailBoxEnableB2AInt(uint32 id, uint32 int_sel) { (void)id; (void)int_sel; return 0; }
__attribute__((weak)) int MailBoxClearB2AInt(uint32 id, uint32 int_sel) { (void)id; (void)int_sel; return 0; }
__attribute__((weak)) int MailBoxDisableB2AInt(uint32 id, uint32 int_sel) { (void)id; (void)int_sel; return 0; }
/* (these were already functions; kept for completeness) */
__attribute__((weak)) int MailBoxClearA2BInt(uint32 id, uint32 int_sel) { (void)id; (void)int_sel; return 0; }
__attribute__((weak)) int MailBoxReadA2BCmd(uint32 id, uint32 channel) { (void)id; (void)channel; return 0; }
__attribute__((weak)) int MailBoxReadA2BData(uint32 id, uint32 channel) { (void)id; (void)channel; return 0; }
__attribute__((weak)) int MailBoxWriteB2ACmd(uint32 cmd, uint32 id, uint32 channel) { (void)cmd; (void)id; (void)channel; return 0; }
__attribute__((weak)) int MailBoxWriteB2AData(uint32 data, uint32 id, uint32 channel) { (void)data; (void)id; (void)channel; return 0; }

/* --- SysTick (systick2.c excluded -> these were variables!) --- */
__attribute__((weak)) void SysTickClkSourceSet2(uint32 Source) { (void)Source; }
__attribute__((weak)) void SysTickEnable2(void) { }
__attribute__((weak)) void SysTickDisable2(void) { }
__attribute__((weak)) void SysTickPeriodSet2(uint32 mstick) { (void)mstick; }

/* --- codec API (pCODECS2.c excluded -> variables!) --- */
__attribute__((weak)) ulong CodecOpen2(ulong ulCodec, ulong ulFlags) { (void)ulCodec; (void)ulFlags; return 0; }
__attribute__((weak)) ulong CodecDecode2(void) { return 0; }
__attribute__((weak)) ulong CodecSeek2(ulong ulTime, ulong ulSeekType) { (void)ulTime; (void)ulSeekType; return 0; }
__attribute__((weak)) ulong CodecGetTime2(ulong *pulTime) { (void)pulTime; return 0; }
__attribute__((weak)) ulong CodecGetBitrate2(ulong *pulBitrate) { (void)pulBitrate; return 0; }
__attribute__((weak)) ulong CodecGetSampleRate2(ulong *pulSampleRate) { (void)pulSampleRate; return 0; }
__attribute__((weak)) ulong CodecGetChannels2(ulong *pulChannels) { (void)pulChannels; return 0; }
__attribute__((weak)) ulong CodecGetLength2(ulong *pulLength) { (void)pulLength; return 0; }
__attribute__((weak)) ulong CodecGetBps2(ulong *pulBps) { (void)pulBps; return 0; }
__attribute__((weak)) ulong CodecGetCaptureBuffer2(short *ppsBuffer, long *plLength) { (void)ppsBuffer; (void)plLength; return 0; }
__attribute__((weak)) ulong CodecClose2(void) { return 0; }

/* --- FiiO app layer / file system --- */
__attribute__((weak)) int BuildDirInfo(void) { return 0; }
__attribute__((weak)) int FindFirstFile(void *p) { (void)p; return 0; }
__attribute__((weak)) int FindNextFile(void *p) { (void)p; return 0; }
__attribute__((weak)) int GetCurFileNum(void) { return 0; }
__attribute__((weak)) int GetGlobeFileNum(void) { return 0; }
__attribute__((weak)) int GetLongFileName(void *p, void *q) { (void)p; (void)q; return 0; }
__attribute__((weak)) int GetTotalFiles(void) { return 0; }
__attribute__((weak)) int MDDeInitAll(void) { return 0; }
__attribute__((weak)) int SFlashGetBluetoothMac(void *p) { (void)p; return 0; }
__attribute__((weak)) int TaskID2Str(uint32 id) { (void)id; return 0; }
__attribute__((weak)) int MusicWinPaint(void) { return 0; }
__attribute__((weak)) void PowerOff(void) { }
__attribute__((weak)) int SetPllDefault(void) { return 0; }
__attribute__((weak)) int System_Power_On(void) { return 0; }
__attribute__((weak)) int CheckAdcState(void) { return 0; }
__attribute__((weak)) int GetAdcData(void) { return 0; }
__attribute__((weak)) int AdcPowerDown(void) { return 0; }
__attribute__((weak)) int BluetoothReConnectResult(void) { return 0; }

/* --- codec-mode helpers (FiiO AudioControl/RecordControl layer) --- */
__attribute__((weak)) int Codec_DeInitial(void) { return 0; }
__attribute__((weak)) int Codec_ExitMode(void) { return 0; }
__attribute__((weak)) int Codec_SetMode(void) { return 0; }
__attribute__((weak)) int Codec_SetSampleRate(void) { return 0; }
__attribute__((weak)) int Codec_SetVolumet(void) { return 0; }

/* --- GPIO / clock / power helpers --- */
__attribute__((weak)) int Gpio_SetPortDirec(void) { return 0; }
__attribute__((weak)) int Grf_NOC_Remap_Sel(void) { return 0; }
__attribute__((weak)) int Grf_otgphy_suspend(void) { return 0; }
__attribute__((weak)) int HostGetChannelInfo(void) { return 0; }
__attribute__((weak)) int ScuClockGateCtr(void) { return 0; }

/* --- debug prints --- */
__attribute__((weak)) int bb_printf1(const char *fmt, ...) { (void)fmt; return 0; }
__attribute__((weak)) int rk_print_string2(const char *fmt, ...) { (void)fmt; return 0; }
__attribute__((weak)) int bt_a2dp_connect(void) { return 0; }

/* ---- generic stubs (were functions already) ---- */
__attribute__((weak)) int ACodec_PLL_Set(void) { return 0; }
__attribute__((weak)) int AdcSleepEnter(void) { return 0; }
__attribute__((weak)) int AdcSleepExit(void) { return 0; }
__attribute__((weak)) int BBDebug(void) { return 0; }
__attribute__((weak)) int BBSystemDeInit(void) { return 0; }
__attribute__((weak)) int BBSystemInit(void) { return 0; }
__attribute__((weak)) int Charge_Current_Set(void) { return 0; }
__attribute__((weak)) int Charge_Enable(void) { return 0; }
__attribute__((weak)) int Charge_State_Get(void) { return 0; }
__attribute__((weak)) int Charger_Current_Get(void) { return 0; }
__attribute__((weak)) int Codec_DACUnMute(void) { return 0; }
__attribute__((weak)) int Codec_Resume(void) { return 0; }
__attribute__((weak)) int Codec_Suspend(void) { return 0; }
__attribute__((weak)) int CreateRandomList(void) { return 0; }
__attribute__((weak)) int DEBUG(void) { return 0; }
__attribute__((weak)) int Delay100cyc(void) { return 0; }
__attribute__((weak)) int DelayMs(void) { return 0; }
__attribute__((weak)) int DelayUs(void) { return 0; }
__attribute__((weak)) int DelayUs2(void) { return 0; }
__attribute__((weak)) int DmaGetState(void) { return 0; }
__attribute__((weak)) int DmaStart(void) { return 0; }
__attribute__((weak)) int FREQ_EnterModule(void) { return 0; }
__attribute__((weak)) int FREQ_ExitModule(void) { return 0; }
__attribute__((weak)) int FadeIsFinished(void) { return 0; }
__attribute__((weak)) int FileClose(void) { return 0; }
__attribute__((weak)) int FileOpen(void) { return 0; }
__attribute__((weak)) int FileRead(void) { return 0; }
__attribute__((weak)) int FileSeek(void) { return 0; }
__attribute__((weak)) int FileWrite(void) { return 0; }
__attribute__((weak)) int GPIOIsrUnRegister(void) { return 0; }
__attribute__((weak)) int GPIO_Suspend(void) { return 0; }
__attribute__((weak)) int GetAsicTableAdd(void) { return 0; }
__attribute__((weak)) int GpioIsrRegister(void) { return 0; }
__attribute__((weak)) int Gpio_DisableInt(void) { return 0; }
__attribute__((weak)) int Gpio_EnableInt(void) { return 0; }
__attribute__((weak)) int Gpio_Init(void) { return 0; }
__attribute__((weak)) int Gpio_SetIntMode(void) { return 0; }
__attribute__((weak)) int I2SDeInit(void) { return 0; }
__attribute__((weak)) int I2SInit(void) { return 0; }
__attribute__((weak)) int I2SStart(void) { return 0; }
__attribute__((weak)) int I2SStop(void) { return 0; }
__attribute__((weak)) int IntDisable(void) { return 0; }
__attribute__((weak)) int IntEnable(void) { return 0; }
__attribute__((weak)) int IntPendingClear(void) { return 0; }
__attribute__((weak)) int IntPrioritySet(void) { return 0; }
__attribute__((weak)) int IntRegister(void) { return 0; }
__attribute__((weak)) int IntUnregister(void) { return 0; }
__attribute__((weak)) int LcdStandby(void) { return 0; }
__attribute__((weak)) int LcdWakeUp(void) { return 0; }
__attribute__((weak)) int MDGetInfo(void) { return 0; }
__attribute__((weak)) int MDRead(void) { return 0; }
__attribute__((weak)) int MDWrite(void) { return 0; }
__attribute__((weak)) int PWM_Start(void) { return 0; }
__attribute__((weak)) int PWM_Stop(void) { return 0; }
__attribute__((weak)) int PowerPath_Set(void) { return 0; }
__attribute__((weak)) int PwmRateSet(void) { return 0; }
__attribute__((weak)) int RKFileFuncInit(void) { return 0; }
__attribute__((weak)) int SysTickDisable(void) { return 0; }
__attribute__((weak)) int SysTickEnable(void) { return 0; }
__attribute__((weak)) int SystickTimerStart(void) { return 0; }
__attribute__((weak)) int SystickTimerStop(void) { return 0; }
__attribute__((weak)) int UserIsrDisable(void) { return 0; }
__attribute__((weak)) int UserIsrEnable(void) { return 0; }
__attribute__((weak)) int UserIsrRequest(void) { return 0; }
__attribute__((weak)) int VDD_VoltageAdjust_Set(void) { return 0; }
__attribute__((weak)) int __WFI(void) { return 0; }
__attribute__((weak)) int randomGenerator(void) { return 0; }

/* ---- newlib syscalls (bare-metal) ---- */
#include <sys/stat.h>
#include <errno.h>
int _write(int fd, const void *buf, unsigned count) { (void)fd; (void)buf; return (int)count; }
int _read(int fd, void *buf, unsigned count) { (void)fd; (void)buf; return 0; }
int _close(int fd) { (void)fd; return -1; }
int _lseek(int fd, int off, int whence) { (void)fd; (void)off; (void)whence; return 0; }
int _fstat(int fd, struct stat *st) { (void)fd; st->st_mode = 0; return 0; }
int _isatty(int fd) { (void)fd; return 0; }
int _getpid(void) { return 1; }
int _kill(int pid, int sig) { (void)pid; (void)sig; return -1; }
void _exit(int status) { (void)status; for (;;); }
void _sbrk(void) { }  /* heap grows via _sbrk_r wrapper; no-op for now */
void *__dso_handle;

/* ---- ARM interrupt-master control (real impl — PRIMASK) ---- */
void IntMasterDisable(void)
{
    __asm volatile("cpsid i" ::: "memory");
}
void IntMasterEnable(void)
{
    __asm volatile("cpsie i" ::: "memory");
}

/* ---- ARM intrinsics the SDK calls as functions (real impls) ---- */
__attribute__((naked)) void __SETPRIMASK2(void)     { __asm__ volatile("cpsid i; bx lr"); }
__attribute__((naked)) void __RESETPRIMASK2(void)   { __asm__ volatile("cpsie i; bx lr"); }
__attribute__((naked)) void __SETFAULTMASK2(void)   { __asm__ volatile("cpsid f; bx lr"); }
__attribute__((naked)) void __RESETFAULTMASK2(void) { __asm__ volatile("cpsie f; bx lr"); }
__attribute__((naked)) void __WFI2(void)            { __asm__ volatile("wfi; bx lr"); }
