/**
 * FUN_03011ef4 @ 0x03011ef4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03011ef4(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char extraout_r2;
  char extraout_r2_00;
  int unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  uint unaff_r7;
  int unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  int unaff_r11;
  char in_ZR;
  char in_CY;
  bool bVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined4 in_stack_00000000;
  uint in_stack_00000004;
  int in_stack_00000018;
  
  uVar5 = CONCAT44(unaff_r10,unaff_r9);
  uVar6 = CONCAT44(unaff_r6,unaff_r5);
  while( true ) {
    if (in_CY == '\0') {
      uVar5 = FUN_02feccb4((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),10,0);
      *(char *)((unaff_r4 - unaff_r7) + 0xf) = extraout_r2 + '0';
    }
    else if (in_ZR == '\0') {
      uVar6 = FUN_02feccb4((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),10,0);
      *(char *)((unaff_r4 - unaff_r7) + 0xf) = extraout_r2_00 + '0';
    }
    else {
      *(undefined1 *)((unaff_r4 - unaff_r7) + 0xf) = 0x3a;
    }
    unaff_r7 = unaff_r7 + 1;
    if (0xf < unaff_r7) break;
    in_CY = in_stack_00000004 <= unaff_r7;
    in_ZR = unaff_r7 == in_stack_00000004;
  }
  uVar3 = 0;
  if (unaff_r8 == 0) {
    do {
      if (*(char *)(unaff_r4 + uVar3) != '0') break;
      *(undefined1 *)(unaff_r4 + uVar3) = 0x20;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0xf);
  }
  else if (unaff_r8 != 0xf) {
    do {
      if (*(char *)(unaff_r4 + uVar3) != '0') break;
      *(undefined1 *)(unaff_r4 + uVar3) = 0x20;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0xfU - unaff_r8);
  }
  iVar2 = DAT_0301205c;
  if (in_stack_00000018 == 0) {
    if (*(char *)(DAT_0301205c + 8) == '7') {
      *(undefined1 *)(unaff_r4 + uVar3) = 0x20;
      return in_stack_00000000;
    }
    if (unaff_r11 != 0xc) {
      return in_stack_00000000;
    }
  }
  else {
    cVar1 = *(char *)(DAT_0301205c + 8);
    bVar4 = cVar1 == '\x01';
    if (bVar4) {
      cVar1 = *(char *)(DAT_0301205c + 1);
    }
    if (bVar4 && cVar1 == '\0') {
      *(undefined1 *)(unaff_r4 + 0xe) = 0x20;
      cVar1 = *(char *)(iVar2 + 10);
      if (cVar1 == '\x0f') {
        *(undefined1 *)(unaff_r4 + 0xf) = 0x3d;
        return in_stack_00000000;
      }
      if (cVar1 == '\x10') {
        *(undefined1 *)(unaff_r4 + 0xf) = 0x3c;
        return in_stack_00000000;
      }
      if (cVar1 == '\x11') {
        *(undefined1 *)(unaff_r4 + 0xf) = 0x3b;
        return in_stack_00000000;
      }
      if (cVar1 != '\x0e') {
        return in_stack_00000000;
      }
      *(undefined1 *)(unaff_r4 + 0xf) = 0x3e;
      return in_stack_00000000;
    }
    cVar1 = *(char *)(DAT_0301205c + 10);
    if (cVar1 == '\x0f') {
      *(undefined1 *)(uVar3 + unaff_r4 + -1) = 0x3d;
      return in_stack_00000000;
    }
    if (cVar1 != '\x10') {
      if (cVar1 == '\x11') {
        *(undefined1 *)(uVar3 + unaff_r4 + -1) = 0x3b;
        return in_stack_00000000;
      }
      if (cVar1 != '\x0e') {
        return in_stack_00000000;
      }
      *(undefined1 *)(uVar3 + unaff_r4 + -1) = 0x3e;
      return in_stack_00000000;
    }
  }
  *(undefined1 *)(uVar3 + unaff_r4 + -1) = 0x3c;
  return in_stack_00000000;
}


