/**
 * FUN_030e7094 @ 0x030e7094
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_030e7094(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint local_30;
  int local_2c;
  uint local_28;
  
  iVar3 = DAT_030e7154;
  iVar2 = DAT_030e7150;
  iVar1 = DAT_030e7148;
  local_30 = 0;
  iVar6 = 0;
  local_2c = 0;
  if (8 < (int)param_3) {
    do {
      uVar4 = buffered_fread_ovl_0e65(&local_30,1,4,param_1);
      if (uVar4 < 4) {
        return 0xfffffffb;
      }
      local_30 = local_30 << 0x18 | (local_30 >> 8 & 0xff) << 0x10 | (local_30 >> 0x10 & 0xff) << 8
                 | local_30 >> 0x18;
      iVar6 = iVar6 + local_30;
      uVar4 = buffered_fread_ovl_0e65(&local_2c,1,4,param_1);
      if (uVar4 < 4) {
        return 0xfffffffb;
      }
      iVar5 = local_2c - iVar2;
      if (local_2c == iVar2) {
        iVar5 = FUN_030e6f76(param_1,param_2,local_30);
joined_r0x030e7176:
        if (iVar5 != 0) {
          return 0xffffffff;
        }
      }
      else if (local_2c < iVar2) {
        if (local_2c + iVar3 != 0) {
          iVar5 = local_2c + iVar3 + DAT_030e7158;
          if (iVar5 == 0) {
            iVar5 = FUN_030e6dcc(param_1,param_2,local_30);
          }
          else {
            if (iVar5 != 0x1000000) goto LAB_030e7128;
            iVar5 = FUN_030e68e8(param_1,param_2,local_30);
          }
          goto joined_r0x030e7176;
        }
LAB_030e7128:
        buffered_fseek_ovl_0e64(param_1,local_30 - 8,1);
      }
      else {
        if (iVar5 != 0x4100000) {
          if (iVar5 == 0x4110000) {
            iVar5 = FUN_030e6d2c(param_1,param_2,local_30);
          }
          else {
            if (iVar5 != 0xb100000) goto LAB_030e7128;
            iVar5 = FUN_030e6e84(param_1,param_2,local_30);
          }
          goto joined_r0x030e7176;
        }
        local_28 = 0;
        if (*(int *)(iVar1 + 0x18) == 0) {
          buffered_fseek_ovl_0e64(param_1,4,1);
          uVar4 = buffered_fread_ovl_0e65(&local_28,1,4,param_1);
          if (uVar4 < 4) {
            return 0xffffffff;
          }
          local_28 = local_28 << 0x18 | (local_28 >> 8 & 0xff) << 0x10 |
                     (local_28 >> 0x10 & 0xff) << 8 | local_28 >> 0x18;
          *(uint *)(param_2 + 0x98) = local_28;
          if (0 < (int)local_28) {
            iVar5 = FUN_030e641a(local_28 << 2);
            *(int *)(iVar1 + 0x3c) = iVar5;
            if (iVar5 == 0) {
              return 0xffffffff;
            }
            uVar4 = buffered_fread_ovl_0e65(iVar5,1,*(int *)(param_2 + 0x98) << 2,param_1);
            if (uVar4 < (uint)(*(int *)(param_2 + 0x98) << 2)) {
              return 0xffffffff;
            }
          }
        }
        else {
          buffered_fseek_ovl_0e64(param_1,local_30 - 8,1);
        }
      }
    } while (iVar6 + 8U < param_3);
  }
  return 0;
}


