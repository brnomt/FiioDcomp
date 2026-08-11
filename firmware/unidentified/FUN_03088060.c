/**
 * FUN_03088060 @ 0x03088060
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03088060(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  
  uVar2 = 0xd;
  bVar3 = SBORROW4(param_2,5);
  iVar1 = param_2 + -5;
  if (4 < param_2) {
    bVar3 = SBORROW4(param_2,0xf);
    iVar1 = param_2 + -0xf;
  }
  if (iVar1 < 0 == bVar3) {
    if (param_2 < 0x20) {
      *(undefined4 *)(param_1 + 0x38) = 0xc;
      goto LAB_0308808c;
    }
    if (param_2 < 0x28) {
      uVar2 = 0xb;
    }
    else {
      if (0x2c < param_2) {
        uVar2 = 9;
        goto LAB_0308808a;
      }
      uVar2 = 10;
    }
    *(undefined4 *)(param_1 + 0x38) = uVar2;
  }
  else {
LAB_0308808a:
    *(undefined4 *)(param_1 + 0x38) = uVar2;
  }
LAB_0308808c:
  *(int *)(param_1 + 0x3c) = (1 << *(sbyte *)(param_1 + 0x38)) + -1;
  return;
}


