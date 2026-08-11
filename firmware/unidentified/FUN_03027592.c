/**
 * FUN_03027592 @ 0x03027592
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_03027592(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar1 = DAT_03027874;
  uVar5 = *(uint *)(DAT_03027874 + 0x54);
  iVar6 = *(int *)(DAT_03027874 + 0x58) - param_1;
  if (iVar6 < 1) {
    uVar4 = -(param_1 + iVar6) & 0x1f;
    iVar2 = FUN_03027568();
    iVar3 = FUN_03027568();
    uVar4 = (uVar5 >> uVar4 | uVar5 << 0x20 - uVar4) & 0xffff | iVar2 << 0x18 | iVar3 << 0x10;
    uVar4 = uVar4 << (-iVar6 & 0xffU) | uVar4 >> (iVar6 + 0x20U & 0xff);
    iVar6 = iVar6 + 0x10;
  }
  else {
    uVar4 = uVar5 >> (-param_1 & 0x1f) | uVar5 << 0x20 - (-param_1 & 0x1f);
  }
  *(uint *)(iVar1 + 0x54) = uVar4;
  *(int *)(iVar1 + 0x58) = iVar6;
  return uVar5 >> (0x10 - param_1 & 0xff) & (1 << (param_1 & 0xff)) - 1U;
}


