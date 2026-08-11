/**
 * FUN_030e7400 @ 0x030e7400
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e7400(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int local_18;
  
  local_18 = 0;
  buffered_fseek_ovl_0e64(param_1,8,1);
  uVar2 = buffered_fread_ovl_0e65(&local_18,1,4,param_1);
  iVar3 = DAT_030e7644;
  iVar1 = DAT_030e7634;
  if (3 < uVar2) {
    puVar4 = (uint *)(DAT_030e7634 + 0x50);
    if (local_18 == DAT_030e7640) {
      *(undefined4 *)(DAT_030e7634 + 0x18) = 0;
      uVar2 = *(uint *)(iVar1 + 0x10);
      *(uint *)(param_2 + 0x9c) = uVar2;
      *(undefined1 *)(param_2 + 0xd1) = 1;
      uVar5 = *(uint *)(iVar1 + 0x14);
      if (uVar5 == 0) {
        uVar5 = *puVar4;
        iVar3 = local_18;
        if (uVar5 == 0) {
          iVar3 = *(int *)(iVar1 + 0x54);
        }
        if (uVar5 != 0 || iVar3 != 0) {
          *(uint *)(param_2 + 0xac) = uVar5;
          *(undefined4 *)(param_2 + 0xb0) = *(undefined4 *)(iVar1 + 0x54);
          *(uint *)(param_2 + 0xbc) =
               ((uVar5 - uVar2 * (uVar5 / uVar2)) * 1000) / uVar2 + (uVar5 / uVar2) * 1000;
        }
      }
      else {
        *(uint *)(param_2 + 0xa4) = uVar5;
        *(uint *)(param_2 + 0xbc) =
             ((uVar5 - uVar2 * (uVar5 / uVar2)) * 1000) / uVar2 + (uVar5 / uVar2) * 1000;
      }
    }
    else if (local_18 == DAT_030e7644) {
      if (*(int *)(DAT_030e7634 + 0x18) == -1) {
        *(undefined4 *)(param_2 + 0xa0) = *(undefined4 *)(DAT_030e7634 + 0x10);
        if (*(int *)(iVar1 + 0x14) == 0) {
          uVar2 = *puVar4;
          if (uVar2 == 0) {
            iVar3 = *(int *)(iVar1 + 0x54);
          }
          if (uVar2 != 0 || iVar3 != 0) {
            *(uint *)(param_2 + 0xb4) = uVar2;
            *(undefined4 *)(param_2 + 0xb8) = *(undefined4 *)(iVar1 + 0x54);
          }
        }
        else {
          *(int *)(param_2 + 0xa8) = *(int *)(iVar1 + 0x14);
        }
      }
      *(undefined4 *)(iVar1 + 0x18) = 1;
      *(undefined1 *)(param_2 + 0xd0) = 1;
    }
    else {
      *(undefined4 *)(DAT_030e7634 + 0x18) = 2;
    }
    buffered_fseek_ovl_0e64(param_1,param_3 + -0x14,1);
    return 0;
  }
  return 0xfffffffb;
}


