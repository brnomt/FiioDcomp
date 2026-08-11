/**
 * FUN_030e7736 @ 0x030e7736
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e7736(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint local_40;
  int local_3c;
  uint local_38;
  short local_34 [2];
  undefined4 uStack_30;
  undefined4 local_2c;
  uint uStack_28;
  
  iVar1 = DAT_030e7a7c;
  local_40 = 0;
  local_3c = 0;
  *(undefined4 *)(DAT_030e7a7c + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x50) = 0;
  *(undefined4 *)(iVar1 + 0x54) = 0;
  iVar5 = 0;
  *(undefined4 *)(iVar1 + 0x10) = 1;
  iVar2 = DAT_030e7a80;
  uStack_30 = param_1;
  local_2c = param_2;
  uStack_28 = param_3;
  if (8 < (int)param_3) {
    do {
      uVar3 = buffered_fread_ovl_0e65(&local_40,1,4,param_1);
      if (uVar3 < 4) {
        return 0xfffffffb;
      }
      local_40 = local_40 << 0x18 | (local_40 >> 8 & 0xff) << 0x10 | (local_40 >> 0x10 & 0xff) << 8
                 | local_40 >> 0x18;
      iVar5 = iVar5 + local_40;
      uVar3 = buffered_fread_ovl_0e65(&local_3c,1,4,param_1);
      if (uVar3 < 4) {
        return 0xfffffffb;
      }
      if (local_3c + iVar2 == 0) {
        iVar4 = FUN_030e7604(param_1,local_2c,local_40);
        if (iVar4 != 0) {
          return 0xffffffff;
        }
      }
      else if (local_3c + iVar2 + DAT_030e7a84 == 0) {
        local_38 = 0;
        local_34[0] = 0;
        uVar3 = buffered_fread_ovl_0e65(&local_38,1,4,param_1);
        if (uVar3 < 4) {
          return 0xffffffff;
        }
        uVar3 = local_38 << 0x18;
        local_38 = uVar3 | (local_38 >> 8 & 0xff) << 0x10 | (local_38 >> 0x10 & 0xff) << 8 |
                   local_38 >> 0x18;
        if (uVar3 == 0) {
          buffered_fseek_ovl_0e64(param_1,0x20,1);
        }
        else {
          buffered_fseek_ovl_0e64(param_1,0x2c,1);
        }
        uVar3 = buffered_fread_ovl_0e65(local_34,1,2,param_1);
        if (uVar3 < 2) {
          return 0xffffffff;
        }
        if (local_34[0] == 1) {
          *(undefined4 *)(iVar1 + 0x18) = 1;
        }
        else {
          *(undefined4 *)(iVar1 + 0x18) = 2;
        }
        buffered_fseek_ovl_0e64(param_1,0x2e,1);
      }
      else {
        buffered_fseek_ovl_0e64(param_1,local_40 - 8,1);
      }
    } while (iVar5 + 8U < param_3);
  }
  return 0;
}


