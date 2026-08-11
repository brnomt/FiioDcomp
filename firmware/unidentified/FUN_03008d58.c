/**
 * FUN_03008d58 @ 0x03008d58
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03008d58(uint param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint in_r12;
  
  do {
    uVar1 = (uint)*(ushort *)(param_4 + param_1 * 2 + 0x14);
    if (param_3 <= uVar1 && uVar1 <= in_r12) {
      return 1;
    }
    param_1 = param_1 + 1 & 0xff;
  } while (param_1 < 0x1e);
  return 0;
}


