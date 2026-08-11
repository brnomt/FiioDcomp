/**
 * FUN_030e7500 @ 0x030e7500
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e7500(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint local_20;
  int local_1c;
  
  iVar1 = DAT_030e7648;
  local_20 = 0;
  iVar4 = 0;
  local_1c = 0;
  if (8 < (int)param_3) {
    do {
      uVar2 = buffered_fread_ovl_0e65(&local_20,1,4,param_1);
      if (uVar2 < 4) {
        return 0xfffffffb;
      }
      local_20 = local_20 << 0x18 | (local_20 >> 8 & 0xff) << 0x10 | (local_20 >> 0x10 & 0xff) << 8
                 | local_20 >> 0x18;
      iVar4 = iVar4 + local_20;
      uVar2 = buffered_fread_ovl_0e65(&local_1c,1,4,param_1);
      if (uVar2 < 4) {
        return 0xfffffffb;
      }
      if (local_1c + iVar1 == 0) {
        iVar3 = FUN_030e7094(param_1,param_2,local_20);
        if (iVar3 != 0) {
          return 0xffffffff;
        }
      }
      else {
        buffered_fseek_ovl_0e64(param_1,local_20 - 8,1);
      }
    } while (iVar4 + 8U < param_3);
  }
  return 0;
}


