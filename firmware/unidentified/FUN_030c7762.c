/**
 * FUN_030c7762 @ 0x030c7762
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Removing unreachable block (ram,0x030c7684) */
/* WARNING: Removing unreachable block (ram,0x030c76da) */
/* WARNING: Removing unreachable block (ram,0x030c76ea) */
/* WARNING: Removing unreachable block (ram,0x030c7690) */
/* WARNING: Removing unreachable block (ram,0x030c76ec) */
/* WARNING: Removing unreachable block (ram,0x030c76fc) */
/* WARNING: Removing unreachable block (ram,0x030c7714) */
/* WARNING: Removing unreachable block (ram,0x030c7720) */
/* WARNING: Removing unreachable block (ram,0x030c7728) */
/* WARNING: Removing unreachable block (ram,0x030c772a) */

undefined4 FUN_030c7762(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (param_2 != (undefined4 *)0x0) {
    FUN_030c673e(*param_2);
    memset_byte(param_2,0,0x20);
  }
  FUN_030c71a0(param_1);
  iVar1 = DAT_030c7788;
  if (*(int *)(DAT_030c7788 + 8) == -1) {
    uVar3 = *(uint *)(DAT_030c7788 + 0x14);
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(uint *)(param_1 + 0x34) = uVar3 | 0x80000000;
    *(undefined4 *)(iVar1 + 8) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 != 0) {
    if (*(int *)(param_1 + 0x40) == 0) {
      *(undefined4 *)(param_1 + 0x38) = 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x38) = 0;
    }
    if (iVar1 == 2) {
      uVar3 = *(uint *)(param_1 + 0x20);
      *(uint *)(param_1 + 0x20) = uVar3 + 1;
      *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(0xfffffffe < uVar3);
      return 0xfffffff6;
    }
  }
  iVar1 = *(int *)(param_1 + 0x3c);
  if (iVar1 != 0) {
    if (*(int *)(param_1 + 0x40) == 0) {
      *(undefined4 *)(param_1 + 0x3c) = 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x3c) = 0;
    }
    if (iVar1 == 2) {
      uVar3 = *(uint *)(param_1 + 0x20);
      *(uint *)(param_1 + 0x20) = uVar3 + 1;
      *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(0xfffffffe < uVar3);
      return 0xfffffff5;
    }
  }
  if ((*(uint *)(param_1 + 0x34) & 0x80000000) != 0) {
    if (param_2 != (undefined4 *)0x0) {
      if (param_2 != (undefined4 *)0x0) {
        param_2[2] = *(undefined4 *)(param_1 + 0x14);
        if ((*(int *)(param_1 + 0x10) == 0) || (*(int *)(param_1 + 0x48) != 0)) {
          param_2[3] = 0;
        }
        else {
          param_2[3] = *(int *)(param_1 + 0x10);
        }
        if (((*(uint *)(param_1 + 0x34) & 0x80000000) == 0) ||
           ((*(uint *)(param_1 + 0x48) & 0x80000000) != 0)) {
          uVar2 = 0xffffffff;
          uVar4 = 0xffffffff;
        }
        else {
          uVar2 = *(undefined4 *)(param_1 + 0x28);
          uVar4 = *(undefined4 *)(param_1 + 0x2c);
        }
        param_2[4] = uVar2;
        param_2[5] = uVar4;
        uVar2 = *(undefined4 *)(param_1 + 0x24);
        param_2[6] = *(undefined4 *)(param_1 + 0x20);
        param_2[7] = uVar2;
      }
      if (param_2 != (undefined4 *)0x0) {
        uVar2 = FUN_030c64e2(*(undefined4 *)(param_1 + 0xc),*(uint *)(param_1 + 0x34) & 0x7fffffff);
        *param_2 = uVar2;
        param_2[1] = *(uint *)(param_1 + 0x34) & 0x7fffffff;
      }
    }
    return 1;
  }
  return 0;
}


