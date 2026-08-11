/**
 * FUN_03013634 @ 0x03013634
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03013634(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*(byte *)(DAT_03013684 + 0x12) < *(byte *)(DAT_03013684 + 0x1e)) {
    *(byte *)(DAT_03013684 + 0x12) = *(byte *)(DAT_03013684 + 0x12) + 1;
  }
  puVar1 = DAT_03013694;
  iVar2 = FUN_02ff0020(*DAT_03013694,DAT_03013690);
  if (iVar2 == 1) {
    FUN_0301e3dc(0xff,0);
  }
  iVar2 = FUN_02ff0020(*puVar1,DAT_030136c8);
  if (iVar2 == 1) {
    FUN_0302b252(0xb6,0);
  }
  MediaLib_GetTotalFiles(0x3e);
  return;
}


