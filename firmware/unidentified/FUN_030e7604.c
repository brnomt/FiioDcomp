/**
 * FUN_030e7604 @ 0x030e7604
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e7604(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint local_38;
  int local_34;
  uint local_30;
  int local_2c [2];
  
  iVar1 = DAT_030e7648;
  local_38 = 0;
  iVar6 = 0;
  local_34 = 0;
  if (8 < (int)param_3) {
    do {
      uVar2 = buffered_fread_ovl_0e65(&local_38,1,4,param_1);
      if (uVar2 < 4) {
        return 0xfffffffb;
      }
      local_38 = local_38 << 0x18 | (local_38 >> 8 & 0xff) << 0x10 | (local_38 >> 0x10 & 0xff) << 8
                 | local_38 >> 0x18;
      iVar6 = iVar6 + local_38;
      uVar3 = buffered_fread_ovl_0e65(&local_34,1,4,param_1);
      uVar2 = local_38;
      if (uVar3 < 4) {
        return 0xfffffffb;
      }
      if (local_34 + DAT_030e7a70 == 0) {
        iVar4 = FUN_030e7210(param_1,param_2,local_38);
joined_r0x030e76b2:
        if (iVar4 != 0) {
          return 0xffffffff;
        }
      }
      else {
        iVar4 = local_34 + DAT_030e7a70 + DAT_030e7a74;
        if (iVar4 == 0) {
          iVar4 = 0;
          local_30 = 0;
          local_2c[0] = 0;
          if (8 < (int)local_38) {
            do {
              uVar3 = buffered_fread_ovl_0e65(&local_30,1,4,param_1);
              if (uVar3 < 4) {
                return 0xffffffff;
              }
              local_30 = local_30 << 0x18 | (local_30 >> 8 & 0xff) << 0x10 |
                         (local_30 >> 0x10 & 0xff) << 8 | local_30 >> 0x18;
              iVar4 = iVar4 + local_30;
              uVar3 = buffered_fread_ovl_0e65(local_2c,1,4,param_1);
              if (uVar3 < 4) {
                return 0xffffffff;
              }
              if (local_2c[0] + iVar1 == 0) {
                iVar5 = FUN_030e7094(param_1,param_2,local_30);
                if (iVar5 != 0) {
                  return 0xffffffff;
                }
              }
              else {
                buffered_fseek_ovl_0e64(param_1,local_30 - 8,1);
              }
            } while (iVar4 + 8U < uVar2);
          }
        }
        else {
          if (iVar4 + DAT_030e7a78 == 0) {
            iVar4 = FUN_030e7400(param_1,param_2,local_38);
            goto joined_r0x030e76b2;
          }
          buffered_fseek_ovl_0e64(param_1,local_38 - 8,1);
        }
      }
    } while (iVar6 + 8U < param_3);
  }
  return 0;
}


