/**
 * FUN_03024334 @ 0x03024334
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03024334(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int unaff_r4;
  int unaff_r5;
  uint *unaff_r6;
  int *unaff_r8;
  int *unaff_r9;
  undefined4 *unaff_r10;
  int unaff_r11;
  char in_ZR;
  
  while( true ) {
    if (in_ZR == '\0') {
      in_ZR = unaff_r4 == 0x40000008;
    }
    if (in_ZR != '\0') {
      *unaff_r6 = *unaff_r6 | 1;
      return 1;
    }
    iVar1 = 0;
    if (unaff_r4 != 0x10000004) {
      iVar1 = unaff_r4 + -0x10000000;
    }
    if (unaff_r4 == 0x10000004 || iVar1 == 8) break;
    do {
      if (unaff_r4 != 0) {
        *unaff_r6 = *unaff_r6 | 1;
      }
LAB_03024368:
      do {
        uVar3 = *(int *)(unaff_r5 + 0x2c) - *(int *)(unaff_r11 + 0xc);
        uVar2 = *(uint *)(unaff_r5 + 0x18);
        if (uVar2 <= uVar3) {
          return 1;
        }
        iVar1 = *(int *)(unaff_r5 + 0x20);
        if (iVar1 < 0x7d1) {
          iVar1 = *(int *)(unaff_r5 + 0x1c);
        }
        if ((2000 < iVar1) &&
           (uVar2 = (int)(uVar2 + ((uint)((int)uVar2 >> 0x1f) >> 0x1e)) >> 2,
           uVar3 == uVar2 * (uVar3 / uVar2))) {
          func_0x03004d9c();
        }
        iVar1 = FUN_03027dfa(DAT_030243e4);
        iVar4 = *unaff_r8 + *(int *)(unaff_r5 + 0x2c);
        if (iVar1 == 0) {
          FUN_03007810(*unaff_r10,iVar4,*unaff_r9,1);
          return 1;
        }
        FUN_03007810(*unaff_r10,iVar4,*unaff_r9 + -1,1);
        *(int *)(unaff_r5 + 0x2c) = *(int *)(unaff_r5 + 0x2c) + 1;
      } while (*DAT_03024408 != '\x01');
    } while ((*unaff_r6 & 1) == 0);
    unaff_r4 = func_0x03005586();
    in_ZR = unaff_r4 == 0x40000004;
  }
  unaff_r4 = 0;
  goto LAB_03024368;
}


