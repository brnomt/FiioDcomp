/**
 * FUN_0301e828 @ 0x0301e828
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_0301e828(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0x20 - param_1[3] & 7;
  if (uVar2 == 0) {
    uVar2 = 8;
  }
  uVar2 = uVar2 + param_1[3];
  uVar3 = (param_2 + uVar2) - 0x20;
  if ((int)uVar2 < 0x20) {
    if (0 < (int)uVar3) {
      return param_1[1] >> (0x20 - uVar3 & 0xff) |
             (*param_1 & 0xffffffffU >> (uVar2 & 0xff)) << (uVar3 & 0xff);
    }
    uVar1 = *param_1 & 0xffffffffU >> (uVar2 & 0xff);
    uVar3 = (0x20 - uVar2) - param_2;
  }
  else {
    uVar1 = param_1[1];
    uVar3 = 0x20 - uVar3;
  }
  return uVar1 >> (uVar3 & 0xff);
}


