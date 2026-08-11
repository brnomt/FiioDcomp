/**
 * FUN_030e7210 @ 0x030e7210
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e7210(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_20;
  uint local_1c [2];
  
  local_20 = 0;
  local_1c[0] = 0;
  uVar3 = buffered_fread_ovl_0e65(&local_20,1,4,param_1);
  iVar1 = DAT_030e7634;
  if (3 < uVar3) {
    uVar3 = local_20 << 0x18;
    local_20 = uVar3 | (local_20 >> 8 & 0xff) << 0x10 | (local_20 >> 0x10 & 0xff) << 8 |
               local_20 >> 0x18;
    if (uVar3 == 0) {
      buffered_fseek_ovl_0e64(param_1,8,1);
      uVar3 = buffered_fread_ovl_0e65(local_1c,1,4,param_1);
      if (3 < uVar3) {
        local_1c[0] = local_1c[0] << 0x18 | (local_1c[0] >> 8 & 0xff) << 0x10 |
                      (local_1c[0] >> 0x10 & 0xff) << 8 | local_1c[0] >> 0x18;
        if (*(int *)(iVar1 + 0x18) == 1) {
          *(uint *)(param_2 + 0xa0) = local_1c[0];
          uVar3 = buffered_fread_ovl_0e65(param_2 + 0xa8,1,4,param_1);
          if (uVar3 < 4) {
            return 0xfffffffb;
          }
          uVar3 = *(uint *)(param_2 + 0xa8);
          *(uint *)(param_2 + 0xa8) =
               uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
               uVar3 >> 0x18;
        }
        else if (*(int *)(iVar1 + 0x18) == 0) {
          *(uint *)(param_2 + 0x9c) = local_1c[0];
          *(uint *)(iVar1 + 0x10) = local_1c[0];
          uVar3 = buffered_fread_ovl_0e65(param_2 + 0xa4,1,4,param_1);
          if (uVar3 < 4) {
            return 0xfffffffb;
          }
          uVar3 = *(uint *)(param_2 + 0xa4);
          uVar3 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
                  uVar3 >> 0x18;
          *(uint *)(param_2 + 0xa4) = uVar3;
          *(uint *)(iVar1 + 0x14) = uVar3;
          uVar5 = *(uint *)(param_2 + 0x9c);
          uVar4 = (uVar3 * 1000) / uVar5;
          *(uint *)(param_2 + 0xbc) = ((uVar3 * 1000 - uVar5 * uVar4) * 1000) / uVar5 + uVar4;
        }
        else {
          *(uint *)(iVar1 + 0x10) = local_1c[0];
          uVar3 = buffered_fread_ovl_0e65(DAT_030e763c,1,4,param_1);
          if (uVar3 < 4) {
            return 0xfffffffb;
          }
          uVar3 = *(uint *)(iVar1 + 0x14);
          *(uint *)(iVar1 + 0x14) =
               uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
               uVar3 >> 0x18;
        }
        buffered_fseek_ovl_0e64(param_1,param_3 + -0x1c,1);
        return 0;
      }
    }
    else {
      buffered_fseek_ovl_0e64(param_1,0x10,1);
      uVar3 = buffered_fread_ovl_0e65(local_1c,1,4,param_1);
      if (3 < uVar3) {
        local_1c[0] = local_1c[0] << 0x18 | (local_1c[0] >> 8 & 0xff) << 0x10 |
                      (local_1c[0] >> 0x10 & 0xff) << 8 | local_1c[0] >> 0x18;
        if (*(int *)(iVar1 + 0x18) == 1) {
          *(uint *)(param_2 + 0xa0) = local_1c[0];
          buffered_fread_ovl_0e65(param_2 + 0xb4,1,4,param_1);
          return 0xfffffffb;
        }
        if (*(int *)(iVar1 + 0x18) == 0) {
          *(uint *)(param_2 + 0x9c) = local_1c[0];
          *(uint *)(iVar1 + 0x10) = local_1c[0];
          uVar3 = buffered_fread_ovl_0e65(param_2 + 0xac,1,4,param_1);
          if (uVar3 < 4) {
            return 0xfffffffb;
          }
          uVar3 = buffered_fread_ovl_0e65(param_2 + 0xb0,1,4,param_1);
          puVar2 = DAT_030e7638;
          if (uVar3 < 4) {
            return 0xfffffffb;
          }
          uVar3 = *(uint *)(param_2 + 0xac);
          uVar5 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
                  uVar3 >> 0x18;
          *(uint *)(param_2 + 0xac) = uVar5;
          uVar3 = *(uint *)(param_2 + 0xb0);
          uVar3 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
                  uVar3 >> 0x18;
          *(uint *)(param_2 + 0xb0) = uVar3;
          *puVar2 = uVar5;
          puVar2[1] = uVar3;
          uVar3 = *(uint *)(param_2 + 0x9c);
          *(uint *)(param_2 + 0xbc) =
               ((uVar5 - uVar3 * (uVar5 / uVar3)) * 1000) / uVar3 + (uVar5 / uVar3) * 1000;
        }
        else {
          *(uint *)(iVar1 + 0x10) = local_1c[0];
          uVar3 = buffered_fread_ovl_0e65(param_2 + 0xac,1,4,param_1);
          if (uVar3 < 4) {
            return 0xfffffffb;
          }
          uVar3 = buffered_fread_ovl_0e65(param_2 + 0xb0,1,4,param_1);
          if (uVar3 < 4) {
            return 0xfffffffb;
          }
          uVar3 = *(uint *)(param_2 + 0xac);
          *(uint *)(param_2 + 0xac) =
               uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
               uVar3 >> 0x18;
          uVar3 = *(uint *)(param_2 + 0xb0);
          *(uint *)(param_2 + 0xb0) =
               uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
               uVar3 >> 0x18;
        }
        buffered_fseek_ovl_0e64(param_1,param_3 + -0x28,1);
        return 0;
      }
    }
  }
  return 0xfffffffb;
}


