/**
 * FUN_03001cb6 @ 0x03001cb6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03001cb6(void)

{
  uint uVar1;
  uint unaff_r4;
  int unaff_r5;
  int unaff_r6;
  ushort *unaff_r7;
  undefined2 unaff_r8;
  undefined2 *unaff_r9;
  
  do {
    if (4 < unaff_r4) {
      return;
    }
    if (*unaff_r7 + 1 <= unaff_r4 + unaff_r6) {
      return;
    }
    FUN_03001592(unaff_r5 + 0xc,unaff_r6 + unaff_r4 & 0xffff);
    uVar1 = 0;
    if (*(short *)(unaff_r5 + 0xc) == 0) {
      do {
        if (*(short *)(unaff_r5 + 0xc + uVar1 * 2) != 0) break;
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x80);
      if (uVar1 == 0x80) {
        FUN_02feb762(0x18,unaff_r5 + 0xc,0x80);
        *unaff_r9 = unaff_r8;
      }
    }
    *(undefined2 *)(unaff_r5 + 8) = unaff_r8;
    if (4 < unaff_r4) {
      return;
    }
    unaff_r5 = *(int *)(unaff_r5 + 4);
    unaff_r4 = unaff_r4 + 1 & 0xffff;
  } while( true );
}


