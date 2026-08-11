/**
 * FUN_0300c0e0 @ 0x0300c0e0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300c0e0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int unaff_r4;
  int unaff_r5;
  uint uVar7;
  undefined1 unaff_r6;
  int unaff_r7;
  undefined2 in_stack_00000008;
  
  iVar3 = FUN_02ff3e56(param_2,param_2,0x3c,0x32);
  iVar5 = DAT_0300c3d4;
  if ((iVar3 == 0) && (iVar5 = unaff_r4, unaff_r4 != unaff_r5)) {
    uVar7 = 0;
    do {
      iVar3 = FUN_02ff3e56(0,uVar7 * 0x18 + 0x1b,0xf0,uVar7 * 0x18 + 0x6b);
      if (iVar3 != 0) {
        *(char *)(unaff_r7 + 3) = (char)uVar7;
        iVar5 = DAT_0300c3d8;
        FUN_02ffa694(0x149);
        FUN_02ffa6d6(0x14a);
        FUN_0300bf34();
        break;
      }
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < 3);
  }
  iVar3 = DAT_0300c3e8;
  puVar1 = DAT_0300c3e4;
  iVar4 = iVar5 - DAT_0300c3dc;
  if (iVar5 == DAT_0300c3dc) goto LAB_0300c362;
  if (DAT_0300c3dc <= iVar5) {
    iVar5 = iVar4 - DAT_0300c3f4;
    if (iVar4 == DAT_0300c3f4) {
      in_stack_00000008 = 1;
      FUN_02fe9590(DAT_0300c400,DAT_0300c404,&stack0x00000008);
      return;
    }
    if (iVar4 < DAT_0300c3f4) {
      if (iVar4 == 0xe00) {
LAB_0300c362:
        FUN_0300b86c();
        FUN_02fe95a8(DAT_0300c400);
        FUN_02ffa6d6(0x14a);
        FUN_02ffa694(0x135);
        return;
      }
      if (0xe00 < iVar4) {
        if (iVar4 != 0xfe00) {
          if (iVar4 != 0xfffe00) {
            return;
          }
          FUN_02fe9590(DAT_0300c400,DAT_0300c404,&stack0x00000008);
          return;
        }
        goto LAB_0300c362;
      }
      if (iVar4 != 0x200) {
        if (iVar4 != 0x600) {
          return;
        }
        goto LAB_0300c2e6;
      }
    }
    else {
      if (iVar5 == 0xe000200) goto LAB_0300c362;
      if (iVar5 != 0xe000400) {
        if (iVar5 != 0xe000800) {
          if (iVar5 != 0xe010000) {
            return;
          }
          goto LAB_0300c362;
        }
        goto LAB_0300c2e6;
      }
    }
    goto LAB_0300c2be;
  }
  iVar4 = iVar5 - DAT_0300c3e0;
  if (iVar5 == DAT_0300c3e0) {
LAB_0300c27a:
    iVar5 = FUN_02fe9720(*DAT_0300c3e4,DAT_0300c3f8);
    if ((iVar5 == 1) && (*(char *)(iVar3 + 0x12) != '\0')) {
      *(char *)(iVar3 + 0x12) = *(char *)(iVar3 + 0x12) + -1;
      FUN_03017adc(0xff,0);
    }
    iVar5 = FUN_02fe9720(*puVar1,DAT_0300c3fc);
    if (iVar5 != 1) {
      return;
    }
    if (*(char *)(iVar3 + 0x12) == '\0') {
      return;
    }
    *(char *)(iVar3 + 0x12) = *(char *)(iVar3 + 0x12) + -1;
    FUN_03024952(0xb6,0);
    return;
  }
  if (iVar5 < DAT_0300c3e0) {
    iVar4 = iVar5 - DAT_0300c3ec;
    if (iVar5 != DAT_0300c3ec) {
      if (iVar5 < DAT_0300c3ec) {
        if (iVar4 == -0x20000000) goto LAB_0300c2e6;
        if (iVar4 != -0x1ffffffc) {
          return;
        }
      }
      else if (iVar4 != 4) {
        if (iVar4 != 0xc) {
          return;
        }
        goto LAB_0300c22e;
      }
LAB_0300c2be:
      if (*(char *)(unaff_r7 + 3) == '\0') {
        cVar2 = '\x02';
      }
      else {
        cVar2 = *(char *)(unaff_r7 + 3) + -1;
      }
      *(char *)(unaff_r7 + 3) = cVar2;
      cVar2 = *(char *)(unaff_r7 + 5);
      goto joined_r0x0300c2f6;
    }
  }
  else {
    if (iVar4 == DAT_0300c3f0) {
LAB_0300c22e:
      iVar5 = FUN_02fe9720(*DAT_0300c3e4,DAT_0300c3f8);
      if ((iVar5 == 1) && (*(byte *)(iVar3 + 0x12) < *(byte *)(iVar3 + 0x1e))) {
        *(byte *)(iVar3 + 0x12) = *(byte *)(iVar3 + 0x12) + 1;
        FUN_03017adc(0xff,0);
      }
      iVar5 = FUN_02fe9720(*puVar1,DAT_0300c3fc);
      if (iVar5 != 1) {
        return;
      }
      if (*(byte *)(iVar3 + 0x1e) <= *(byte *)(iVar3 + 0x12)) {
        return;
      }
      *(byte *)(iVar3 + 0x12) = *(byte *)(iVar3 + 0x12) + 1;
      FUN_03024952(0xb6,0);
      return;
    }
    if (DAT_0300c3f0 <= iVar4) {
      if (iVar4 - DAT_0300c3f0 != 0x10) {
        if (iVar4 - DAT_0300c3f0 != 0x30) {
          return;
        }
        cVar2 = *(char *)(unaff_r7 + 2);
        if (cVar2 == '\x02') {
          FUN_0300ba2c(*(byte *)(unaff_r7 + 3) + 1);
        }
        else if (cVar2 == '\x01') {
          FUN_0300b8d4(*(byte *)(unaff_r7 + 3) + 1,0);
        }
        else if (cVar2 == '\x03') {
          FUN_0300b8d4(*(byte *)(unaff_r7 + 3) + 1,1);
          FUN_02ffa6d6(0x14a);
          *(undefined1 *)(unaff_r7 + 5) = unaff_r6;
        }
        FUN_0300b86c();
        if (*(char *)(unaff_r7 + 2) == '\x02') {
          FUN_02fe95a8(DAT_0300c400);
          FUN_02ffa6d6(0x14a);
          uVar6 = 0x135;
        }
        else {
          uVar6 = 0x143;
        }
        FUN_02ffa694(uVar6);
        return;
      }
      goto LAB_0300c27a;
    }
    if (iVar4 == 0x3e0) goto LAB_0300c2be;
    if (iVar4 != 0x7e0) {
      return;
    }
  }
LAB_0300c2e6:
  if (*(byte *)(unaff_r7 + 3) < 2) {
    *(byte *)(unaff_r7 + 3) = *(byte *)(unaff_r7 + 3) + 1;
  }
  else {
    *(undefined1 *)(unaff_r7 + 3) = unaff_r6;
  }
  cVar2 = *(char *)(unaff_r7 + 5);
joined_r0x0300c2f6:
  if (cVar2 == '\x01') {
    *(undefined1 *)(unaff_r7 + 5) = unaff_r6;
  }
  FUN_02ffa694(0x149);
  FUN_02ffa6d6(0x14a);
  return;
}


