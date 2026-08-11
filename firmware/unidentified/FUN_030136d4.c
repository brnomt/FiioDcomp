/**
 * FUN_030136d4 @ 0x030136d4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030136d4(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*(char *)(DAT_03013ac4 + 0x12) != '\0') {
    *(char *)(DAT_03013ac4 + 0x12) = *(char *)(DAT_03013ac4 + 0x12) + -1;
  }
  puVar1 = DAT_03013acc;
  iVar2 = FUN_02ff0020(*DAT_03013acc,DAT_03013ac8);
  if (iVar2 == 1) {
    FUN_0301e3dc(0xff,0);
  }
  iVar2 = FUN_02ff0020(*puVar1,DAT_03013ad0);
  if (iVar2 == 1) {
    FUN_0302b252(0xb6,0);
  }
  MediaLib_GetTotalFiles(0x3e);
  return;
}


