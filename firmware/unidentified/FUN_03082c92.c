/**
 * FUN_03082c92 @ 0x03082c92
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_03082c92(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (param_2 & 0x7fffffff) >> 0x14;
  if (uVar2 < 0x3ff) {
    return 0;
  }
  if (uVar2 < 0x434) {
    iVar1 = FUN_030827aa(param_1,param_2 & 0xfffff | 0x100000,-(uVar2 - 0x433));
    return iVar1;
  }
  return param_1 << (uVar2 - 0x433 & 0xff);
}


