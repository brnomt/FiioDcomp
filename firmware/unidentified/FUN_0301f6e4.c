/**
 * FUN_0301f6e4 @ 0x0301f6e4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301f6e4(void)

{
  uint uVar1;
  uint *puVar2;
  undefined4 *unaff_r4;
  byte *unaff_r5;
  
  uVar1 = *unaff_r5 + 1 + unaff_r4[3];
  unaff_r4[3] = uVar1;
  if (0x1f < uVar1) {
    *unaff_r4 = unaff_r4[1];
    if (((uint)unaff_r4[6] < 5) && (unaff_r4[8] != 1)) {
      FUN_0301e7dc();
    }
    puVar2 = (uint *)unaff_r4[4];
    unaff_r4[4] = puVar2 + 1;
    uVar1 = *puVar2;
    unaff_r4[6] = unaff_r4[6] + -4;
    unaff_r4[1] = uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 |
                  uVar1 >> 0x18;
    unaff_r4[3] = unaff_r4[3] + -0x20;
  }
  return;
}


