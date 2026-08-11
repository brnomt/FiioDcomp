/**
 * FUN_030048c0 @ 0x030048c0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030048c0(ushort *param_1,ushort *param_2,uint param_3,int param_4)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_4 == 1) {
    if (param_3 != 0) {
      do {
        uVar1 = uVar1 + 1;
        *param_1 = *param_2;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
      } while (uVar1 < param_3);
      return;
    }
    return;
  }
  if (param_3 != 0) {
    do {
      uVar1 = uVar1 + 1;
      *param_1 = (*param_2 >> 8) + *param_2 * 0x100 & 0xff00;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    } while (uVar1 < param_3);
    return;
  }
  return;
}


