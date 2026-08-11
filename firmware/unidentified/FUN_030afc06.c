/**
 * FUN_030afc06 @ 0x030afc06
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030afc06(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint local_20;
  int local_1c;
  
  iVar1 = DAT_030aff98;
  local_20 = 0;
  iVar4 = 0;
  local_1c = 0;
  if ((param_1 != 0) && (param_2 == 0)) {
    return 0xffffffff;
  }
  if (8 < (int)param_3) {
    do {
      uVar2 = buffered_fread(&local_20,1,4,param_1);
      if (uVar2 < 4) {
        hifi_debug_printf_ovl(DAT_030aff9c + -0x18,DAT_030aff9c,0x6ae);
        return 0xfffffffb;
      }
      local_20 = local_20 << 0x18 | (local_20 >> 8 & 0xff) << 0x10 | (local_20 >> 0x10 & 0xff) << 8
                 | local_20 >> 0x18;
      iVar4 = iVar4 + local_20;
      uVar2 = buffered_fread(&local_1c,1,4,param_1);
      if (uVar2 < 4) {
        hifi_debug_printf_ovl(DAT_030aff9c + -0x18,DAT_030aff9c,0x6b5);
        return 0xfffffffb;
      }
      if (local_1c + iVar1 == 0) {
        iVar3 = aac_dec_init(param_1,param_2,local_20);
        if (iVar3 != 0) {
          return 0xffffffff;
        }
      }
      else {
        buffered_fseek(param_1,local_20 - 8,1);
      }
    } while (iVar4 + 8U < param_3);
  }
  return 0;
}


