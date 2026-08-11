/**
 * FUN_030e641a @ 0x030e641a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030e641a(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  iVar1 = *(int *)(DAT_030e6800 + 0x800);
  iVar2 = 0x800 - iVar1;
  bVar4 = iVar2 == param_1;
  iVar3 = iVar2 - param_1;
  if (iVar2 >= param_1) {
    bVar4 = param_1 == 0;
    iVar3 = param_1;
  }
  if (!bVar4 && iVar3 < 0 == (iVar2 < param_1 && SBORROW4(iVar2,param_1))) {
    iVar3 = DAT_030e6800 + iVar1;
    *(uint *)(DAT_030e6800 + 0x800) = param_1 + (4U - param_1 & 3) + iVar1;
    return iVar3;
  }
  return 0;
}


