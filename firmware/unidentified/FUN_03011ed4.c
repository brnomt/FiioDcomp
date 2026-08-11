/**
 * FUN_03011ed4 @ 0x03011ed4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03011ed4(void)

{
  char cVar1;
  char extraout_r2;
  char extraout_r2_00;
  char extraout_r2_01;
  char extraout_r2_02;
  int iVar2;
  int unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  int unaff_r8;
  undefined4 unaff_r9;
  uint uVar3;
  undefined4 unaff_r10;
  int unaff_r11;
  bool bVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined4 in_stack_00000000;
  int in_stack_00000018;
  
  uVar5 = CONCAT44(unaff_r10,unaff_r9);
  uVar6 = CONCAT44(unaff_r6,unaff_r5);
  if (unaff_r8 == 1) {
    uVar3 = 0;
    do {
      *(undefined1 *)(unaff_r4 + 0xf) = 0x3a;
      while( true ) {
        uVar3 = uVar3 + 1;
        if (0xf < uVar3) goto LAB_03011f94;
        if (uVar3 == 0) break;
        uVar6 = FUN_02feccb4((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),10,0);
        *(char *)((unaff_r4 - uVar3) + 0xf) = extraout_r2_00 + '0';
      }
    } while( true );
  }
  if (unaff_r8 == 0) {
    uVar3 = 0;
    do {
      uVar6 = FUN_02feccb4((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),10,0);
      iVar2 = unaff_r4 - uVar3;
      uVar3 = uVar3 + 1;
      *(char *)(iVar2 + 0xf) = extraout_r2_02 + '0';
    } while (uVar3 < 0x10);
  }
  else {
    uVar3 = 0;
    do {
      if (uVar3 < unaff_r8 - 1U) {
        uVar5 = FUN_02feccb4((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),10,0);
        *(char *)((unaff_r4 - uVar3) + 0xf) = extraout_r2 + '0';
      }
      else if (uVar3 == unaff_r8 - 1U) {
        *(undefined1 *)((unaff_r4 - uVar3) + 0xf) = 0x3a;
      }
      else {
        uVar6 = FUN_02feccb4((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),10,0);
        *(char *)((unaff_r4 - uVar3) + 0xf) = extraout_r2_01 + '0';
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x10);
  }
LAB_03011f94:
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


