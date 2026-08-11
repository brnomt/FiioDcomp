/**
 * FUN_0302a338 @ 0x0302a338
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0302a338(void)

{
  rom_usb_disconnect(0xe);
  FUN_02ffb29c(0xe,0xe0);
  FUN_0300b960(0xe,DAT_0302a394);
  rom_usb_connect(0xe);
  return;
}


