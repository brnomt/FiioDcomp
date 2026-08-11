/**
 * FUN_030c5e28 @ 0x030c5e28
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030c5e28(int param_1,int param_2,uint param_3,uint param_4,int param_5)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = (param_4 & 0x7fff) - (param_3 & 0x7fff);
  bVar2 = iVar1 < 0;
  if (bVar2) {
    iVar1 = -iVar1;
  }
  iVar1 = ((param_5 - param_1) * iVar1) / (param_2 - param_1);
  if (bVar2) {
    iVar1 = -iVar1;
  }
  return (param_3 & 0x7fff) + iVar1;
}


