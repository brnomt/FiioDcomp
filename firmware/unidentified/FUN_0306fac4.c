/**
 * FUN_0306fac4 @ 0x0306fac4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_0306fac4(int param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  
  puVar2 = DAT_0306fd70;
  bVar1 = *(byte *)(param_1 + 1) >> 1;
  uVar4 = bVar1 & 0xc;
  uVar5 = (*(byte *)(param_1 + 1) & 7) >> 1;
  if (uVar5 == 1) {
    *DAT_0306fd6c = 2;
    if ((bVar1 & 0xc) == 0 || uVar4 == 8) {
      uVar7 = 0x240;
code_r0x0306fb42:
      *puVar2 = uVar7;
      goto code_r0x0306faf8;
    }
  }
  else if (uVar5 == 2) {
    *DAT_0306fd6c = 1;
  }
  else {
    if (uVar5 == 3) {
      *DAT_0306fd6c = 0;
      uVar7 = 0x180;
      goto code_r0x0306fb42;
    }
    *DAT_0306fd6c = 2;
  }
  *puVar2 = 0x480;
code_r0x0306faf8:
  uVar3 = (uint)*(byte *)(param_1 + 2);
  uVar6 = (uint)(*(byte *)(param_1 + 2) >> 4);
  uVar8 = (uVar3 & 0xf) >> 2;
  if (uVar5 == 1) {
    if ((bVar1 & 0xc) != 0) {
      uVar4 = uVar4 - 4 & 0xff;
    }
    return (uint)*(ushort *)(DAT_0306fd7c + (uVar4 | uVar8) * 0x20 + uVar6 * 2) -
           ((int)(uVar3 << 0x1e) >> 0x1f) & 0xffff;
  }
  if (uVar5 == 2) {
    if ((bVar1 & 0xc) != 0) {
      uVar4 = uVar4 - 8 & 0xff;
    }
    return (uint)*(ushort *)(iRam0306fd80 + (uVar4 | uVar8) * 0x20 + uVar6 * 2) -
           ((int)(uVar3 << 0x1e) >> 0x1f) & 0xffff;
  }
  if ((bVar1 & 0xc) != 0) {
    uVar4 = uVar4 - 8 & 0xff;
  }
  return (uint)*(ushort *)(DAT_0306fd78 + (uVar4 | uVar8) * 0x20 + uVar6 * 2) -
         ((int)(uVar3 << 0x1e) >> 0x1f) & 0xffff;
}


