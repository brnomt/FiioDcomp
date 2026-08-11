/**
 * FUN_03010340 @ 0x03010340
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03010340(void)

{
  int iVar1;
  
  if (*(int *)(DAT_030104d0 + 4) != -1) {
    FUN_03020886();
  }
  iVar1 = rom_event_pending(0x159);
  if (iVar1 != 0) {
    return;
  }
  iVar1 = rom_event_pending(0x158);
  if (iVar1 == 0) {
    return;
  }
  rom_event_clear_id(0x158);
  *(undefined1 *)(DAT_030104ec + 0x1bc) = 0;
  return;
}


