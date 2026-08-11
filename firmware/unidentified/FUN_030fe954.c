/**
 * FUN_030fe954 @ 0x030fe954
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined8 FUN_030fe954(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  
  if ((param_2 & 0x7fffffff) != 0 || param_1 != 0) {
    uVar2 = (param_2 & 0x7fffffff) >> 0x14;
    iVar1 = -(uint)(uVar2 != 0);
    iVar3 = (int)param_3 >> 0x1f;
    bVar4 = -uVar2 < param_3;
    if ((int)((iVar1 - iVar3) - (uint)bVar4) < 0 !=
        (SBORROW4(iVar1,iVar3) != SBORROW4(iVar1 - iVar3,(uint)bVar4))) {
      return CONCAT44(param_2 + param_3 * 0x100000,param_1);
    }
    param_1 = 0;
    param_2 = 0;
  }
  return CONCAT44(param_2,param_1);
}


