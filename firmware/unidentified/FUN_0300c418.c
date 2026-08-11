/**
 * FUN_0300c418 @ 0x0300c418
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


short FUN_0300c418(byte *param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  short sVar3;
  
  uVar2 = 0;
  sVar3 = 0;
  if (*param_1 != 0) {
    bVar1 = *(byte *)(DAT_0300c820 + 0x10);
    do {
      if (param_2 <= uVar2) {
        return sVar3;
      }
      if (((bVar1 < 2) || (bVar1 == 3 || bVar1 == 4)) && (*param_1 - 0x81 < 0x7e)) {
        param_1 = param_1 + 2;
        sVar3 = sVar3 + 2;
      }
      else {
        param_1 = param_1 + 1;
        sVar3 = sVar3 + 1;
      }
      uVar2 = uVar2 + 1 & 0xffff;
    } while (*param_1 != 0);
  }
  return sVar3;
}


