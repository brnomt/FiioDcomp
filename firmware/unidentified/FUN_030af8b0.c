/**
 * FUN_030af8b0 @ 0x030af8b0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_030af8b0(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_20;
  uint local_1c [2];
  
  local_1c[0] = 0;
  local_20 = 0;
  if ((param_1 != 0) && (param_2 == 0)) {
    return 0xffffffff;
  }
  uVar3 = buffered_fread(local_1c,1,4,param_1);
  iVar1 = DAT_030afb60;
  if (3 < uVar3) {
    uVar3 = local_1c[0] << 0x18;
    local_1c[0] = uVar3 | (local_1c[0] >> 8 & 0xff) << 0x10 | (local_1c[0] >> 0x10 & 0xff) << 8 |
                  local_1c[0] >> 0x18;
    if (uVar3 == 0) {
      buffered_fseek(param_1,8,1);
      uVar3 = buffered_fread(&local_20,1,4,param_1);
      if (3 < uVar3) {
        local_20 = local_20 << 0x18 | (local_20 >> 8 & 0xff) << 0x10 |
                   (local_20 >> 0x10 & 0xff) << 8 | local_20 >> 0x18;
        if (*(int *)(iVar1 + 0x24) == 1) {
          *(uint *)(param_2 + 0xa4) = local_20;
          uVar3 = buffered_fread(param_2 + 0xac,1,4,param_1);
          if (uVar3 < 4) {
            return 0xfffffffb;
          }
          uVar3 = *(uint *)(param_2 + 0xac);
          *(uint *)(param_2 + 0xac) =
               uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
               uVar3 >> 0x18;
        }
        else if (*(int *)(iVar1 + 0x24) == 0) {
          *(uint *)(param_2 + 0xa0) = local_20;
          *(uint *)(iVar1 + 0x1c) = local_20;
          uVar3 = buffered_fread(param_2 + 0xa8,1,4,param_1);
          if (uVar3 < 4) {
            return 0xfffffffb;
          }
          uVar3 = *(uint *)(param_2 + 0xa8);
          uVar3 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
                  uVar3 >> 0x18;
          *(uint *)(param_2 + 0xa8) = uVar3;
          *(uint *)(iVar1 + 0x20) = uVar3;
          uVar4 = *(uint *)(param_2 + 0xa0);
          uVar5 = (uVar3 * 1000) / uVar4;
          *(uint *)(param_2 + 0xc0) = ((uVar3 * 1000 - uVar4 * uVar5) * 1000) / uVar4 + uVar5;
        }
        else {
          *(uint *)(iVar1 + 0x1c) = local_20;
          uVar3 = buffered_fread(DAT_030afb68,1,4,param_1);
          if (uVar3 < 4) {
            return 0xfffffffb;
          }
          uVar3 = *(uint *)(iVar1 + 0x20);
          *(uint *)(iVar1 + 0x20) =
               uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
               uVar3 >> 0x18;
        }
        buffered_fseek(param_1,param_3 + -0x1c,1);
        return 0;
      }
    }
    else {
      buffered_fseek(param_1,0x10,1);
      uVar3 = buffered_fread(&local_20,1,4,param_1);
      if (3 < uVar3) {
        local_20 = local_20 << 0x18 | (local_20 >> 8 & 0xff) << 0x10 |
                   (local_20 >> 0x10 & 0xff) << 8 | local_20 >> 0x18;
        if (*(int *)(iVar1 + 0x24) == 1) {
          *(uint *)(param_2 + 0xa4) = local_20;
          uVar3 = buffered_fread(param_2 + 0xb8,1,4,param_1);
          if (uVar3 < 4) {
            return 0xfffffffb;
          }
          uVar3 = buffered_fread(param_2 + 0xbc,1,4,param_1);
          if (uVar3 < 4) {
            return 0xfffffffb;
          }
          uVar3 = *(uint *)(param_2 + 0xb8);
          *(uint *)(param_2 + 0xb8) =
               uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
               uVar3 >> 0x18;
          uVar3 = *(uint *)(param_2 + 0xbc);
          uVar3 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
                  uVar3 >> 0x18;
          *(uint *)(param_2 + 0xbc) = uVar3;
          *(uint *)(param_2 + 0xac) = uVar3;
        }
        else if (*(int *)(iVar1 + 0x24) == 0) {
          *(uint *)(param_2 + 0xa0) = local_20;
          *(uint *)(iVar1 + 0x1c) = local_20;
          uVar3 = buffered_fread(param_2 + 0xb0,1,4,param_1);
          if (uVar3 < 4) {
            return 0xfffffffb;
          }
          uVar3 = buffered_fread(param_2 + 0xb4,1,4,param_1);
          if (uVar3 < 4) {
            return 0xfffffffb;
          }
          uVar3 = *(uint *)(param_2 + 0xb0);
          uVar3 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
                  uVar3 >> 0x18;
          *(uint *)(param_2 + 0xb0) = uVar3;
          puVar2 = DAT_030afb64;
          uVar4 = *(uint *)(param_2 + 0xb4);
          uVar4 = uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                  uVar4 >> 0x18;
          *(uint *)(param_2 + 0xb4) = uVar4;
          *puVar2 = uVar3;
          puVar2[1] = uVar4;
          uVar4 = *(uint *)(param_2 + 0xa0);
          *(uint *)(param_2 + 0xc0) =
               ((uVar3 - uVar4 * (uVar3 / uVar4)) * 1000) / uVar4 + (uVar3 / uVar4) * 1000;
        }
        else {
          *(uint *)(iVar1 + 0x1c) = local_20;
          uVar3 = buffered_fread(param_2 + 0xb0,1,4,param_1);
          if (uVar3 < 4) {
            return 0xfffffffb;
          }
          uVar3 = buffered_fread(param_2 + 0xb4,1,4,param_1);
          if (uVar3 < 4) {
            return 0xfffffffb;
          }
          uVar3 = *(uint *)(param_2 + 0xb0);
          *(uint *)(param_2 + 0xb0) =
               uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
               uVar3 >> 0x18;
          uVar3 = *(uint *)(param_2 + 0xb4);
          *(uint *)(param_2 + 0xb4) =
               uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
               uVar3 >> 0x18;
        }
        buffered_fseek(param_1,param_3 + -0x28,1);
        return 0;
      }
    }
  }
  return 0xfffffffb;
}


