/**
 * FUN_030af01e @ 0x030af01e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030af01e(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint local_18;
  
  local_18 = 0;
  if ((param_1 != 0) && (param_2 == 0)) {
    return 0xffffffff;
  }
  buffered_fseek(param_1,4,1);
  uVar2 = buffered_fread(&local_18,1,4,param_1);
  iVar1 = DAT_030af1dc;
  if (uVar2 < 4) {
    return 0xfffffffb;
  }
  local_18 = local_18 << 0x18 | (local_18 >> 8 & 0xff) << 0x10 | (local_18 >> 0x10 & 0xff) << 8 |
             local_18 >> 0x18;
  if (*(int *)(DAT_030af1dc + 0x24) == 0) {
    *(uint *)(param_2 + 0x98) = local_18;
    iVar3 = FUN_030ae552(local_18 << 3);
    *(int *)(iVar1 + 0x40) = iVar3;
    if (iVar3 == 0) {
      return 0xfffffff9;
    }
    uVar2 = buffered_fread(iVar3,1,local_18 << 3,param_1);
    if (uVar2 < local_18 << 3) {
      return 0xfffffffb;
    }
  }
  else if (*(int *)(DAT_030af1dc + 0x24) == 1) {
    *(uint *)(param_2 + 0x94) = local_18;
    iVar3 = FUN_030ae552(local_18 << 3);
    *(int *)(iVar1 + 0x44) = iVar3;
    if (iVar3 == 0) {
      return 0xfffffff9;
    }
    uVar2 = buffered_fread(iVar3,1,local_18 << 3,param_1);
    if (uVar2 < local_18 << 3) {
      return 0xfffffffb;
    }
  }
  else {
    buffered_fseek(param_1,param_3 + -0x10,1);
  }
  return 0;
}


