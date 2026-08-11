/**
 * FUN_0306f026 @ 0x0306f026
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0306f026(void)

{
  int iVar1;
  
  *DAT_0306f178 = 0;
  iVar1 = FUN_0306e3a8(DAT_0306f168);
  if (iVar1 != 0) {
    return;
  }
  hifi_memmove(DAT_0306f168,DAT_0306f174,0x80);
  *DAT_0306f17c = 1;
  FUN_0306edd6();
  FUN_0306ef32();
  return;
}


