/**
 * FUN_030c4142 @ 0x030c4142
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030c4142(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  
  bVar4 = param_2 == 0;
  param_2 = *(int *)(param_1 + 0x24) + param_2;
  iVar1 = 0;
  iVar2 = 0;
  if (!bVar4) {
    iVar2 = *(int *)(param_1 + 0x28);
    iVar1 = param_2 - iVar2;
  }
  bVar3 = !bVar4 && SBORROW4(param_2,iVar2);
  if ((bVar4 || param_2 == iVar2) || iVar1 < 0 != bVar3) {
    *(int *)(param_1 + 0x24) = param_2;
    param_1 = 0;
  }
  if ((!bVar4 && param_2 != iVar2) && iVar1 < 0 == bVar3) {
    param_1 = -0x83;
  }
  return param_1;
}


