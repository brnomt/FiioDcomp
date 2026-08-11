/**
 * FUN_03024308 @ 0x03024308
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03024308(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int unaff_r4;
  uint *unaff_r6;
  int unaff_r11;
  
  piVar4 = DAT_030243fc;
  puVar3 = DAT_030243f8;
  piVar2 = DAT_030243e8;
  iVar1 = DAT_030243e4;
  do {
    if (*DAT_03024408 == '\x01') {
      if ((*unaff_r6 & 1) != 0) {
        unaff_r4 = func_0x03005586();
        iVar5 = unaff_r4;
        if (unaff_r4 != 0x40000004) {
          iVar5 = unaff_r4 + -0x40000000;
        }
        if (unaff_r4 == 0x40000004 || iVar5 == 8) {
          *unaff_r6 = *unaff_r6 | 1;
          return 1;
        }
        iVar5 = 0;
        if (unaff_r4 != 0x10000004) {
          iVar5 = unaff_r4 + -0x10000000;
        }
        if (unaff_r4 == 0x10000004 || iVar5 == 8) {
          unaff_r4 = 0;
          goto LAB_03024368;
        }
      }
      if (unaff_r4 != 0) {
        *unaff_r6 = *unaff_r6 | 1;
      }
    }
LAB_03024368:
    uVar7 = *(int *)(iVar1 + 0x2c) - *(int *)(unaff_r11 + 0xc);
    uVar6 = *(uint *)(iVar1 + 0x18);
    if (uVar6 <= uVar7) {
      return 1;
    }
    iVar5 = *(int *)(iVar1 + 0x20);
    if (iVar5 < 0x7d1) {
      iVar5 = *(int *)(iVar1 + 0x1c);
    }
    if ((2000 < iVar5) &&
       (uVar6 = (int)(uVar6 + ((uint)((int)uVar6 >> 0x1f) >> 0x1e)) >> 2,
       uVar7 == uVar6 * (uVar7 / uVar6))) {
      func_0x03004d9c();
    }
    iVar5 = FUN_03027dfa(DAT_030243e4);
    iVar8 = *piVar4 + *(int *)(iVar1 + 0x2c);
    if (iVar5 == 0) {
      FUN_03007810(*puVar3,iVar8,*piVar2,1);
      return 1;
    }
    FUN_03007810(*puVar3,iVar8,*piVar2 + -1,1);
    *(int *)(iVar1 + 0x2c) = *(int *)(iVar1 + 0x2c) + 1;
  } while( true );
}


