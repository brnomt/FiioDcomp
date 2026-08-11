/**
 * FUN_030816c6 @ 0x030816c6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030816c6(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = DAT_0308171c;
  if (*param_1 != '\r') {
    uVar2 = FUN_0308282e(param_1);
    wma_memmove(iVar1 + 5,param_1,uVar2);
    return;
  }
  FUN_03091114(DAT_0308171c,s__B__03081720);
  iVar3 = FUN_0308282e(param_1);
  wma_memmove(iVar1 + 5,param_1 + 2,iVar3 + -2);
  return;
}


