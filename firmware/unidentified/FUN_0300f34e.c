/**
 * FUN_0300f34e @ 0x0300f34e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0300f34e(void)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined1 unaff_r6;
  int unaff_r7;
  undefined1 unaff_r9;
  int iVar7;
  undefined4 in_stack_00000020;
  
  iVar3 = FUN_02ffc8c0(0x1c8);
  iVar5 = DAT_0300f3b0;
  if (iVar3 != 0) {
    uVar6 = 0;
    do {
      uVar4 = 0;
      iVar3 = iVar5 + uVar6 * 0x26;
      do {
        *(undefined1 *)(iVar3 + uVar4) = unaff_r6;
        uVar4 = uVar4 + 1 & 0xff;
      } while (uVar4 < 6);
      uVar4 = 0;
      do {
        iVar7 = iVar3 + uVar4;
        uVar4 = uVar4 + 1 & 0xff;
        *(undefined1 *)(iVar7 + 6) = unaff_r6;
      } while (uVar4 < 0x20);
      uVar6 = uVar6 + 1 & 0xff;
    } while (uVar6 < 6);
    uVar6 = 0;
    do {
      *(undefined1 *)(iVar5 + uVar6) = *(undefined1 *)(unaff_r7 + uVar6 + 0x23e);
      uVar6 = uVar6 + 1 & 0xff;
    } while (uVar6 < 6);
    uVar6 = 0;
    do {
      iVar3 = unaff_r7 + uVar6;
      iVar7 = iVar5 + uVar6;
      uVar6 = uVar6 + 1 & 0xff;
      *(undefined1 *)(iVar7 + 6) = *(undefined1 *)(iVar3 + 0x328);
      uVar2 = DAT_0300f4b4;
      puVar1 = DAT_0300f4b0;
    } while (uVar6 < 0x20);
    DAT_0300f4b0[1] = unaff_r9;
    *puVar1 = unaff_r9;
    FUN_02feb7a0(DAT_0300f4b8,uVar2);
  }
  iVar5 = FUN_02ffc8c0(0x1cb);
  if (iVar5 != 0) {
    FUN_02feb7a0(DAT_0300f4b8,DAT_0300f4b4);
  }
  iVar5 = FUN_02ffc8c0(0xdf);
  if (iVar5 != 0) {
    if (*(char *)(unaff_r7 + 0x34a) != '\0') {
      FUN_02ffb1c8(0x54);
      iVar5 = DAT_0300f4bc;
      uVar6 = 0;
      do {
        uVar4 = 0;
        iVar3 = iVar5 + uVar6 * 0x26;
        do {
          *(undefined1 *)(iVar3 + uVar4) = unaff_r6;
          uVar4 = uVar4 + 1 & 0xff;
        } while (uVar4 < 6);
        uVar4 = 0;
        do {
          iVar7 = iVar3 + uVar4;
          uVar4 = uVar4 + 1 & 0xff;
          *(undefined1 *)(iVar7 + 6) = unaff_r6;
          puVar1 = DAT_0300f4b0;
        } while (uVar4 < 0x20);
        uVar6 = uVar6 + 1 & 0xff;
      } while (uVar6 < 6);
      *DAT_0300f4b0 = unaff_r6;
      *(undefined2 *)(puVar1 + 4) = 50000;
      FUN_02ffc8a4(0x1c9);
    }
    FUN_02ffc8a4(0x1c6);
  }
  iVar5 = FUN_02ffc8c0(0xe0);
  if (iVar5 != 0) {
    FUN_02ffc8a4(0x1c6);
  }
  iVar5 = FUN_02ffc8c0(0xe3);
  if (iVar5 != 0) {
    FUN_02ffc8a4(0x1c6);
  }
  return in_stack_00000020;
}


