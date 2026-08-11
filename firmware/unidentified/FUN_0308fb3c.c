/**
 * FUN_0308fb3c @ 0x0308fb3c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_0308fb3c(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  
  if (((param_2 == 0) && (param_4 < 3)) || (3 < param_4)) {
    return 0;
  }
  if (param_1 < 0x3e81) {
    return 0x200;
  }
  if (param_1 < 0x5623) {
    return 0x400;
  }
  if (param_1 < 0x7d01) {
    if (param_4 == 1) {
      return 0x400;
    }
  }
  else {
    bVar3 = SBORROW4(param_1,0xac44);
    iVar1 = param_1 + -0xac44;
    bVar2 = param_1 == 0xac44;
    if (0xac44 < param_1) {
      bVar3 = SBORROW4(param_1,48000);
      iVar1 = param_1 + -48000;
      bVar2 = param_1 == 48000;
    }
    if (!bVar2 && iVar1 < 0 == bVar3) {
      return param_1;
    }
  }
  return 0x800;
}


