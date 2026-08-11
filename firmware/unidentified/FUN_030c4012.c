/**
 * FUN_030c4012 @ 0x030c4012
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Type propagation algorithm not settling */

int FUN_030c4012(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  bool bVar6;
  bool bVar7;
  
  iVar4 = *param_1;
  iVar1 = param_1[9];
  piVar5 = *(int **)(iVar4 + 0x1c);
  bVar7 = SBORROW4(iVar1,-1);
  iVar3 = iVar1 + 1;
  bVar6 = iVar1 == -1;
  iVar2 = param_2;
  if (-1 < iVar1) {
    iVar2 = param_1[10];
    bVar7 = SBORROW4(iVar2,iVar1);
    iVar3 = iVar2 - iVar1;
    bVar6 = iVar2 == iVar1;
  }
  if (!bVar6 && iVar3 < 0 == bVar7) {
    iVar2 = iVar2 - iVar1;
    if (param_2 != 0) {
      if (param_3 < iVar2) {
        iVar2 = param_3;
      }
      iVar3 = 0;
      if (0 < *(int *)(iVar4 + 4)) {
        do {
          FUN_030ca0fe(*piVar5,piVar5[1],param_1[0xb],param_1[0xc]);
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)(iVar4 + 4));
      }
    }
    return iVar2;
  }
  return 0;
}


