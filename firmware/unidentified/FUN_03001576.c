/**
 * FUN_03001576 @ 0x03001576
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03001576(int param_1,undefined4 param_2,uint param_3)

{
  char in_CY;
  
  while ((in_CY == '\0' && (*(short *)(param_1 + param_3 * 2) == 0))) {
    param_3 = param_3 + 1;
    in_CY = 0x7f < param_3;
  }
  if (param_3 != 0x80) {
    return;
  }
  FUN_02feb762(0x18,param_1,0x80);
  *DAT_0300166c = 1;
  return;
}


