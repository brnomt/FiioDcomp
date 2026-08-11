/**
 * FUN_030df114 @ 0x030df114
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined8 FUN_030df114(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar2 = flac_bitstream_getbits_u(param_1,8);
  iVar3 = FUN_030dd956(uVar2 ^ 0xff | 1);
  if (iVar3 - 0x18U != 1) {
    uVar2 = 0x7fU >> (iVar3 - 0x18U & 0xff) & uVar2;
    iVar7 = 0;
    iVar3 = iVar3 + -0x19;
    while( true ) {
      if (iVar3 < 1) {
        return CONCAT44(iVar7,uVar2);
      }
      iVar4 = flac_bitstream_getbits_u(param_1,8);
      uVar5 = iVar4 - 0x80;
      if ((int)uVar5 >> 6 != 0) break;
      uVar1 = uVar2 >> 0x1a;
      uVar6 = uVar2 * 0x40;
      uVar2 = uVar6 + uVar5;
      iVar7 = (iVar7 << 6 | uVar1) + ((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar6,uVar5);
      iVar3 = iVar3 + -1;
    }
  }
  return 0xffffffffffffffff;
}


