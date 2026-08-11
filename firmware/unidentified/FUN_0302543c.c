/**
 * FUN_0302543c @ 0x0302543c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0302543c(int param_1,undefined4 param_2,uint param_3,char param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  if ((param_3 << 0x18 | (param_3 >> 8 & 0xff) << 0x10 | (param_3 >> 0x10 & 0xff) << 8 |
      param_3 >> 0x18) < 9) {
    return 0xffffffff;
  }
  uVar1 = FUN_02ffc9d6(param_1,8,(int)param_4);
  if (7 < uVar1) {
    uVar2 = FUN_02ff89ce(param_1 + 4,param_2,4);
    return uVar2;
  }
  return 0xffffffff;
}


