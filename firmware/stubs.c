/* stubs.c — ReChord link stubs.
 * Auto-generated: defines globals (zero) + function stubs referenced
 * by the Rockchip SDK that come from the FiiO layer / ROM API.
 * These are placeholders until the real implementations are linked.
 */
#include <stdint.h>
#include <string.h>

/* ---- globals (zero-init) ---- */
uint32_t AdcPowerDown __attribute__((used));
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
uint32_t BluetoothReConnectResult __attribute__((used));
uint32_t BtWinStatus __attribute__((used));
uint32_t BuildDirInfo __attribute__((used));
uint32_t ChargeFullFlag __attribute__((used));
uint32_t ChargeWin __attribute__((used));
uint32_t CheckAdcState __attribute__((used));
uint32_t CodeLogicAddress __attribute__((used));
uint32_t CodecClose2 __attribute__((used));
uint32_t CodecDecode2 __attribute__((used));
uint32_t CodecGetBitrate2 __attribute__((used));
uint32_t CodecGetBps2 __attribute__((used));
uint32_t CodecGetCaptureBuffer2 __attribute__((used));
uint32_t CodecGetChannels2 __attribute__((used));
uint32_t CodecGetLength2 __attribute__((used));
uint32_t CodecGetSampleRate2 __attribute__((used));
uint32_t CodecGetTime2 __attribute__((used));
uint32_t CodecOpen2 __attribute__((used));
uint32_t CodecSeek2 __attribute__((used));
uint32_t Codec_DeInitial __attribute__((used));
uint32_t Codec_ExitMode __attribute__((used));
uint32_t Codec_SetMode __attribute__((used));
uint32_t Codec_SetSampleRate __attribute__((used));
uint32_t Codec_SetVolumet __attribute__((used));
uint32_t CurrentCodec2 __attribute__((used));
uint32_t DataDiskID __attribute__((used));
uint32_t DefaultLanguage __attribute__((used));
uint32_t DefaultLanguageID __attribute__((used));
uint32_t DmaTransting __attribute__((used));
uint32_t FMThread __attribute__((used));
uint32_t FM_State_StepStation __attribute__((used));
uint32_t FileInfo __attribute__((used));
uint32_t FileOpenStringR __attribute__((used));
uint32_t FindFirstFile __attribute__((used));
uint32_t FindNextFile __attribute__((used));
uint32_t FmStandbyFlag __attribute__((used));
uint32_t GBKLogicAddress __attribute__((used));
uint32_t GetAdcData __attribute__((used));
uint32_t GetCurFileNum __attribute__((used));
uint32_t GetGlobeFileNum __attribute__((used));
uint32_t GetLongFileName __attribute__((used));
uint32_t GetTotalFiles __attribute__((used));
uint32_t Gpio_SetPortDirec __attribute__((used));
uint32_t Grf_NOC_Remap_Sel __attribute__((used));
uint32_t Grf_otgphy_suspend __attribute__((used));
uint32_t HostGetChannelInfo __attribute__((used));
uint32_t IsBTOpened __attribute__((used));
uint32_t IsBackLightOn __attribute__((used));
uint32_t LanguageNum __attribute__((used));
uint32_t LowPowerWin __attribute__((used));
uint32_t MDDeInitAll __attribute__((used));
uint32_t MailBoxClearB2AInt __attribute__((used));
uint32_t MailBoxDisableB2AInt __attribute__((used));
uint32_t MailBoxEnableA2BInt __attribute__((used));
uint32_t MailBoxEnableB2AInt __attribute__((used));
uint32_t MailBoxReadB2ACmd __attribute__((used));
uint32_t MailBoxReadB2AData __attribute__((used));
uint32_t MailBoxWriteA2BCmd __attribute__((used));
uint32_t MailBoxWriteA2BData __attribute__((used));
uint32_t MainMenuWin __attribute__((used));
uint32_t MaxShuffleAllCount __attribute__((used));
uint32_t MdbBuildWin __attribute__((used));
uint32_t MenuLogicAddress __attribute__((used));
uint32_t MusicFileExtString __attribute__((used));
uint32_t MusicWin __attribute__((used));
uint32_t MusicWinPaint __attribute__((used));
uint32_t OutputVolOffset __attribute__((used));
uint32_t PicWin __attribute__((used));
uint32_t PowerOff __attribute__((used));
uint32_t RadioWin __attribute__((used));
uint32_t RebootTag __attribute__((used));
uint32_t RecordFileExtString __attribute__((used));
uint32_t RecordThread __attribute__((used));
uint32_t RecordWin __attribute__((used));
uint32_t SFlashGetBluetoothMac __attribute__((used));
uint32_t ScuClockGateCtr __attribute__((used));
uint32_t SetMenuLanguageInfo __attribute__((used));
uint32_t SetPllDefault __attribute__((used));
uint32_t SetPowerOffFlag __attribute__((used));
uint32_t SysDiskID __attribute__((used));
uint32_t SysProgRawDiskCapacity __attribute__((used));
uint32_t SysTickClkSourceSet2 __attribute__((used));
uint32_t SysTickCounter __attribute__((used));
uint32_t SysTickDisable2 __attribute__((used));
uint32_t SysTickEnable2 __attribute__((used));
uint32_t SysTickPeriodSet2 __attribute__((used));
uint32_t System_Power_On __attribute__((used));
uint32_t TaskID2Str __attribute__((used));
uint32_t ValidSysDisk __attribute__((used));
uint32_t __CPU_IntDefaultHandler2 __attribute__((used));
uint32_t __RESETFAULTMASK2 __attribute__((used));
uint32_t __RESETPRIMASK2 __attribute__((used));
uint32_t __SETFAULTMASK2 __attribute__((used));
uint32_t __SETPRIMASK2 __attribute__((used));
uint32_t __WFI2 __attribute__((used));
uint32_t bb_printf1 __attribute__((used));
uint32_t bt_a2dp_connect __attribute__((used));
uint32_t chip_freq __attribute__((used));
uint32_t gBattery __attribute__((used));
uint32_t gLangSel __attribute__((used));
uint32_t gSysConfig __attribute__((used));
uint32_t gSysSetBLTimeArray __attribute__((used));
uint32_t gpRadioplayerRegKey __attribute__((used));
uint32_t rk_print_string2 __attribute__((used));

/* ---- function stubs (return 0) ---- */
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
__attribute__((weak)) int MailBoxClearA2BInt(void) { return 0; }
__attribute__((weak)) int MailBoxReadA2BCmd(void) { return 0; }
__attribute__((weak)) int MailBoxReadA2BData(void) { return 0; }
__attribute__((weak)) int MailBoxWriteB2ACmd(void) { return 0; }
__attribute__((weak)) int MailBoxWriteB2AData(void) { return 0; }
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
