/**
 * FUN_03019688 @ 0x03019688
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03019688(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_030196e0;
  uVar2 = *(byte *)(DAT_030196e0 + 0x6d) & 3;
  if (*(char *)(DAT_030196e0 + 0x1a1) == '\0') {
    *(char *)(DAT_030196e0 + 0x6d) = (char)uVar2;
    if (uVar2 == param_1) {
      return 0;
    }
  }
  else {
    if (uVar2 == param_1) {
      return 0;
    }
    param_1 = param_1 + 4;
  }
  *(char *)(iVar1 + 0x6d) = (char)param_1;
  func_0x030037a8(0x113);
  return 0;
}


