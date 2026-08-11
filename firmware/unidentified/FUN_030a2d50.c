/**
 * FUN_030a2d50 @ 0x030a2d50
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030a2d50(int *param_1,uint *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  uVar2 = param_1[0x6c0];
  if (0 < (int)uVar2) {
    puVar1 = param_3 + -1;
    if ((uVar2 & 1) != 0) {
      *param_3 = 0;
      puVar1 = param_3;
    }
    for (iVar5 = param_1[0x6c0] >> 1; iVar5 != 0; iVar5 = iVar5 + -1) {
      puVar1[1] = 0;
      puVar1 = puVar1 + 2;
      *puVar1 = 0;
    }
  }
  iVar5 = param_1[0x6c1];
  if (iVar5 < 1) {
    return;
  }
  piVar3 = param_1 + 0x480;
  piVar4 = param_1 + 0x5a0;
  piVar6 = param_1 + 0x240;
  do {
    param_3[*param_1] =
         (int)(short)*piVar3 * ((int)(*param_2 << 1) >> 0x10) + param_3[*param_1] +
         ((int)((int)(short)*piVar3 * (*param_2 & 0x7fff) + 0x4000) >> 0xf);
    param_1 = param_1 + 1;
    piVar3 = (int *)((int)piVar3 + 2);
    param_3[*piVar6] =
         (int)(short)*piVar4 * ((int)(*param_2 << 1) >> 0x10) + param_3[*piVar6] +
         ((int)((int)(short)*piVar4 * (*param_2 & 0x7fff) + 0x4000) >> 0xf);
    iVar5 = iVar5 + -1;
    param_2 = param_2 + 1;
    piVar4 = (int *)((int)piVar4 + 2);
    piVar6 = piVar6 + 1;
  } while (iVar5 != 0);
  return;
}


