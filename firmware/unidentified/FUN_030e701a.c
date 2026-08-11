/**
 * FUN_030e701a @ 0x030e701a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e701a(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint local_18;
  
  iVar1 = DAT_030e7148;
  local_18 = 0;
  if (*(int *)(DAT_030e7148 + 0x18) == 0) {
    buffered_fseek_ovl_0e64(param_1,4,1);
    uVar2 = buffered_fread_ovl_0e65(&local_18,1,4,param_1);
    if (uVar2 < 4) {
      return 0xfffffffb;
    }
    local_18 = local_18 << 0x18 | (local_18 >> 8 & 0xff) << 0x10 | (local_18 >> 0x10 & 0xff) << 8 |
               local_18 >> 0x18;
    *(uint *)(param_2 + 0x98) = local_18;
    if (0 < (int)local_18) {
      iVar3 = FUN_030e641a(local_18 << 2);
      *(int *)(iVar1 + 0x3c) = iVar3;
      if (iVar3 == 0) {
        return 0xfffffff9;
      }
      uVar2 = buffered_fread_ovl_0e65(iVar3,1,*(int *)(param_2 + 0x98) << 2,param_1);
      if (uVar2 < (uint)(*(int *)(param_2 + 0x98) << 2)) {
        return 0xfffffffb;
      }
    }
  }
  else {
    buffered_fseek_ovl_0e64(param_1,param_3 + -8,1);
  }
  return 0;
}


