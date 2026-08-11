/**
 * FUN_030efd2c @ 0x030efd2c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030efd2c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = *(int *)(param_1 + 0x2c);
  piVar3 = (int *)(param_1 + 0x28);
  iVar6 = param_1 + 0x954;
  iVar4 = 0;
  if (0 < param_2) {
    do {
      *(int *)(*piVar3 + 200) = iVar5;
      iVar5 = iVar5 - *(int *)(*piVar3 + 0xc4);
      *(int *)(*piVar3 + 0xc4) = iVar5;
      iVar2 = *piVar3;
      iVar1 = *(int *)(iVar2 + 200);
      iVar5 = *(int *)(iVar6 + iVar4 * 4) +
              (iVar5 * *(int *)(param_1 + 0x48) + iVar1 * *(int *)(param_1 + 0x44) +
               *(int *)(iVar2 + 0xbc) * *(int *)(param_1 + 0x50) +
               *(int *)(iVar2 + 0xc0) * *(int *)(param_1 + 0x4c) >> 10);
      *(uint *)(iVar2 + 0x48) = -(uint)(0 < iVar1) - (iVar1 >> 0x1f);
      iVar1 = *(int *)(*piVar3 + 0xc4);
      *(uint *)(*piVar3 + 0x44) = -(uint)(0 < iVar1) - (iVar1 >> 0x1f);
      iVar1 = *(int *)(iVar6 + iVar4 * 4);
      iVar1 = -(uint)(0 < iVar1) - (iVar1 >> 0x1f);
      iVar2 = *piVar3;
      *(int *)(param_1 + 0x44) = *(int *)(iVar2 + 0x48) * iVar1 + *(int *)(param_1 + 0x44);
      *(int *)(param_1 + 0x48) = *(int *)(iVar2 + 0x44) * iVar1 + *(int *)(param_1 + 0x48);
      *(int *)(param_1 + 0x4c) = *(int *)(iVar2 + 0x40) * iVar1 + *(int *)(param_1 + 0x4c);
      *(int *)(param_1 + 0x50) = *(int *)(iVar2 + 0x3c) * iVar1 + *(int *)(param_1 + 0x50);
      iVar1 = iVar5 + (*(int *)(param_1 + 0x34) * 0x1f >> 5);
      *(int *)(param_1 + 0x34) = iVar1;
      *(int *)(iVar6 + iVar4 * 4) = iVar1;
      FUN_030ee8d8(*piVar3,*piVar3 + 4,200);
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_2);
  }
  *(int *)(param_1 + 0x2c) = iVar5;
  return;
}


