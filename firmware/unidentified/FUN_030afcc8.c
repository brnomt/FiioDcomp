/**
 * FUN_030afcc8 @ 0x030afcc8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_030afcc8(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint local_10;
  short local_c [2];
  
  local_10 = 0;
  local_c[0] = 0;
  if ((param_1 != 0) && (param_2 == 0)) {
    return 0xffffffff;
  }
  uVar1 = buffered_fread(&local_10,1,4,param_1);
  if (3 < uVar1) {
    uVar1 = local_10 << 0x18;
    local_10 = uVar1 | (local_10 >> 8 & 0xff) << 0x10 | (local_10 >> 0x10 & 0xff) << 8 |
               local_10 >> 0x18;
    if (uVar1 == 0) {
      buffered_fseek(param_1,0x20,1);
    }
    else {
      buffered_fseek(param_1,0x2c,1);
    }
    uVar1 = buffered_fread(local_c,1,2,param_1);
    if (1 < uVar1) {
      uVar2 = 1;
      if (local_c[0] != 1) {
        uVar2 = 2;
      }
      *(undefined4 *)(DAT_030affa0 + 0x24) = uVar2;
      buffered_fseek(param_1,0x2e,1);
      return 0;
    }
  }
  return 0xfffffffb;
}


