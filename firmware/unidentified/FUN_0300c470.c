/**
 * FUN_0300c470 @ 0x0300c470
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0300c470(uint param_1)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  
  if (param_1 - 0x30 < 10) {
    return 1;
  }
  uVar1 = param_1 - 0x61;
  if (0x19 < uVar1) {
    uVar1 = param_1 - 0x41;
  }
  if ((0x19 < uVar1) && ((0x3f < param_1 - 0xc0 || (param_1 == 0xd7 || param_1 == 0xf7)))) {
    uVar1 = param_1 - 0x100;
    bVar4 = 0x7e < uVar1;
    bVar3 = uVar1 == 0x7f;
    if (0x7f < uVar1) {
      bVar4 = 0x3e < param_1 - 0x180;
      bVar3 = param_1 - 0x180 == 0x3f;
    }
    if (bVar4 && !bVar3) {
      uVar1 = param_1 - 0x1c4;
      bVar4 = 0x7c < uVar1;
      bVar3 = uVar1 == 0x7d;
      if (0x7d < uVar1) {
        bVar4 = 0x5d < param_1 - 0x401;
        bVar3 = param_1 - 0x401 == 0x5e;
      }
      if (bVar4 && !bVar3) {
        bVar4 = param_1 != 0x490;
        bVar3 = param_1 == 0x491;
      }
      if (((bVar4 && !bVar3) &&
          (((0x79 < param_1 - 0x386 || (param_1 - 0x386 == 1)) &&
           (iVar2 = FUN_02fe8f22(param_1), iVar2 != 1)))) &&
         (iVar2 = FUN_02fe8efc(param_1), iVar2 != 1)) {
        if (((param_1 != 0x20 && param_1 != 0x2c) &&
            ((param_1 != 0x2e && param_1 != 0x2d) && param_1 != 0x3000)) && (param_1 < 0x100)) {
          return 0;
        }
        return 0x8000;
      }
    }
  }
  return 2;
}


