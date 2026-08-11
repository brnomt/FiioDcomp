/**
 * FUN_030e7e4c @ 0x030e7e4c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030e7e4c(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = DAT_030e7f10;
  uVar3 = FUN_030e78e4(DAT_030e7f10 + 0x2dc,DAT_030e7f10,*(undefined4 *)(DAT_030e7f10 + 0x68));
  uVar4 = *(uint *)(iVar2 + 0xa0);
  uVar3 = ((uVar3 - uVar4 * (uVar3 / uVar4)) * 1000) / uVar4 + (uVar3 / uVar4) * 1000;
  sVar1 = *(short *)(iVar2 + 0xcc);
  if (sVar1 == 2 || sVar1 == 4) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0xb4;
  }
  if (uVar4 < uVar3) {
    uVar3 = uVar3 - uVar4;
  }
  return uVar3;
}


