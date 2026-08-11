/**
 * FUN_030047cc @ 0x030047cc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030047cc(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int unaff_r5;
  ushort *unaff_r6;
  char *unaff_r7;
  uint uVar6;
  char in_ZR;
  bool bVar7;
  
  if (in_ZR == '\0') {
    uVar1 = FUN_02fe5872();
  }
  else {
    uVar1 = FUN_02fe59fa(unaff_r6 + 0x28,*(undefined4 *)(unaff_r6 + 8));
  }
  *unaff_r6 = uVar1;
  iVar2 = 0;
  do {
    if (*(short *)(unaff_r5 + iVar2 * 2) == 0) break;
    iVar2 = (int)(short)((short)iVar2 + 1);
  } while (iVar2 < 0x80);
  uVar5 = iVar2 - 4U & 0xffff;
  iVar2 = FUN_02fe57ac(unaff_r6 + 10,unaff_r6 + 0x1a,*(undefined4 *)(unaff_r6 + 8));
  if ((iVar2 == 0) && (unaff_r6[1] = 1, *unaff_r6 != 0)) {
    do {
      if (*unaff_r7 == '\x03') {
        FUN_02fe4f14(unaff_r6 + 0x28,*(int *)(unaff_r6 + 0x1c) + -1);
      }
      else {
        FUN_02fe5d7c(*(undefined4 *)(unaff_r6 + 0x1a));
      }
      uVar4 = 0;
      if (uVar5 != 0) {
        do {
          uVar3 = (uint)*(byte *)(unaff_r5 + uVar4 * 2);
          uVar6 = (uint)(byte)(&stack0x00000000)[uVar4 * 2];
          if (uVar3 - 0x61 < 0x1a) {
            uVar3 = uVar3 - 0x20 & 0xff;
          }
          if (uVar6 - 0x61 < 0x1a) {
            uVar6 = uVar6 - 0x20 & 0xff;
          }
        } while ((uVar3 == uVar6) &&
                (uVar4 = (uint)(short)((short)uVar4 + 1), (int)uVar4 < (int)uVar5));
      }
      if (uVar4 == uVar5) {
        return 0;
      }
      iVar2 = FUN_02fe5780(unaff_r6 + 10,unaff_r6 + 0x1a,*(undefined4 *)(unaff_r6 + 8));
      uVar1 = unaff_r6[1] + 1;
      unaff_r6[1] = uVar1;
      bVar7 = uVar1 == *unaff_r6;
      if (uVar1 <= *unaff_r6) {
        bVar7 = iVar2 == 0;
      }
    } while (bVar7);
  }
  return 0xffffffff;
}


