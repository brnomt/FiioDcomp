/**
 * FUN_030039d2 @ 0x030039d2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030039d2(void)

{
  uint uVar1;
  int iVar2;
  uint unaff_r4;
  int unaff_r5;
  undefined2 *unaff_r7;
  undefined2 *unaff_r8;
  undefined2 unaff_r10;
  int unaff_r11;
  bool bVar3;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  
  while( true ) {
    *unaff_r7 = *DAT_03003abc;
    uVar1 = (uint)*(byte *)(unaff_r11 + 3);
    bVar3 = uVar1 != unaff_r4;
    if (bVar3) {
      uVar1 = (uint)*(byte *)(unaff_r11 + 4);
    }
    if (!bVar3 || uVar1 == unaff_r4) {
      if (*(byte *)(unaff_r11 + 4) == unaff_r4) {
        FUN_02fec65a(0x7a,0,0,unaff_r5);
      }
      if (*(byte *)(unaff_r11 + 3) == unaff_r4) {
        *unaff_r7 = *unaff_r8;
        FUN_02fecabe(0x85,4,unaff_r5);
      }
      FUN_02febe20();
    }
    uVar1 = unaff_r4 + 1;
    unaff_r4 = uVar1 & 0xffff;
    if (1 < unaff_r4) break;
    unaff_r5 = (int)(short)((short)uVar1 * 0x18 + 0x17);
  }
  FUN_02fec116(0);
  iVar2 = FUN_02ff0650(1);
  if ((iVar2 != 0) && (iVar2 = FUN_02ff060c(0x3e), iVar2 == 1)) {
    FUN_02fecb14(*(byte *)(DAT_03003aac + 0x12) + 0xd2,0,0x50);
  }
  FUN_02febd74(in_stack_00000018);
  *unaff_r7 = unaff_r10;
  FUN_02febd50(in_stack_0000001c);
  return;
}


