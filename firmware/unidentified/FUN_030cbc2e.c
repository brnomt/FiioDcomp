/**
 * FUN_030cbc2e @ 0x030cbc2e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030cbc2e(int *param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  uVar4 = param_1[2];
  iVar5 = param_1[3];
  iVar1 = FUN_030cbb76();
  if (iVar1 != 0) {
    return iVar1;
  }
  if (*param_1 != -1) {
    (*(code *)param_1[0x25])(*param_1,(code *)param_1[0x25],uVar4,iVar5,0);
    param_1[2] = uVar4;
    param_1[3] = iVar5;
    FUN_030c6c66(param_1[6]);
  }
  puVar2 = (uint *)(param_1[8] + param_2 * 8);
  uVar3 = puVar2[1];
  bVar6 = uVar4 < *puVar2;
  if (((int)((iVar5 - uVar3) - (uint)bVar6) < 0 !=
       (SBORROW4(iVar5,uVar3) != SBORROW4(iVar5 - uVar3,(uint)bVar6))) ||
     (puVar2 = (uint *)(param_2 * 8 + 8 + param_1[8]), uVar3 = puVar2[1], bVar6 = uVar4 < *puVar2,
     (int)((iVar5 - uVar3) - (uint)bVar6) < 0 ==
     (SBORROW4(iVar5,uVar3) != SBORROW4(iVar5 - uVar3,(uint)bVar6)))) {
    param_1[0x1a] = 3;
  }
  return 0;
}


