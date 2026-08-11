/**
 * FUN_03004580 @ 0x03004580
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03004580(void)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  int unaff_r4;
  uint unaff_r5;
  int unaff_r6;
  int unaff_r7;
  int unaff_r8;
  uint unaff_r9;
  int unaff_r10;
  undefined1 unaff_r11;
  bool bVar8;
  
code_r0x03004580:
  do {
    bVar2 = *(byte *)(unaff_r8 + (uint)*(ushort *)(unaff_r7 + 4));
    uVar4 = (uint)bVar2;
    if ((uVar4 == 0x5b || uVar4 == 0xd) || uVar4 == 10) goto LAB_030045e8;
    if ((uVar4 == 0x3c) && (*(char *)((uint)*(ushort *)(unaff_r7 + 4) + unaff_r8 + 9) == '>')) {
      unaff_r9 = 1;
LAB_030045a8:
      if (9 < uVar4 - 0x30) {
        bVar8 = 0x3b < uVar4;
        if (uVar4 != 0x3c) {
          bVar8 = 0x3d < uVar4;
        }
        if (bVar8 && (uVar4 != 0x3c && uVar4 != 0x3e)) goto LAB_030045b8;
      }
    }
    else {
      if (unaff_r9 != 0) goto LAB_030045a8;
LAB_030045b8:
      *(byte *)(unaff_r10 + unaff_r4) = bVar2;
      unaff_r4 = unaff_r4 + 1;
    }
    if (1 < unaff_r4) {
      iVar5 = unaff_r10 + unaff_r4;
      cVar1 = *(char *)(iVar5 + -2);
      bVar8 = cVar1 == -0x3e;
      if (bVar8) {
        cVar1 = *(char *)(iVar5 + -1);
      }
      if (bVar8 && cVar1 == -0x60) {
        *(undefined1 *)(iVar5 + -2) = unaff_r11;
        *(undefined1 *)(iVar5 + -1) = 0x20;
      }
    }
    iVar5 = FUN_03004338();
    if (iVar5 == -1) {
LAB_030045e8:
      *(undefined1 *)(unaff_r10 + unaff_r4) = 0;
LAB_030045f6:
      iVar5 = DAT_03004708;
      unaff_r5 = unaff_r5 + 1;
      if (3 < unaff_r5) {
        return 0;
      }
      do {
        iVar3 = FUN_03004382();
        if (iVar3 == 0) {
          iVar3 = unaff_r8 + (uint)*(ushort *)(unaff_r7 + 4);
          if (*(char *)(iVar3 + 6) == ':') {
            if ((*(byte *)(iVar3 + 7) - 0x30 < 10) && (*(byte *)(iVar3 + 8) - 0x30 < 10)) {
              iVar7 = (*(byte *)(iVar3 + 1) - 0x30) * 10 + -0x30 + (uint)*(byte *)(iVar3 + 2);
              unaff_r10 = iVar7 * 0x1f;
              if (((uint)*(byte *)(iVar3 + 5) + (*(byte *)(iVar3 + 4) - 0x30) * 10) * 0x3c +
                  (uint)*(byte *)(iVar3 + 7) * 10 + (uint)*(byte *)(iVar3 + 8) + iVar7 * 0xe10 +
                  -0xd50 != unaff_r6) {
                sVar6 = 8;
                goto LAB_03004524;
              }
              sVar6 = *(short *)(unaff_r7 + 4) + 8;
              goto LAB_03004520;
            }
          }
          else {
            if (iVar5 + (uint)*(byte *)(iVar3 + 4) * 10 +
                (uint)*(byte *)(iVar3 + 5) +
                ((*(byte *)(iVar3 + 1) - 0x30) * 10 + -0x30 + (uint)*(byte *)(iVar3 + 2)) * 0x3c ==
                unaff_r6) goto code_r0x030044b8;
            sVar6 = 5;
LAB_03004524:
            *(ushort *)(unaff_r7 + 4) = *(ushort *)(unaff_r7 + 4) + sVar6;
          }
          iVar3 = FUN_03004338();
        }
        if (iVar3 == -1) {
          return 0xffffffff;
        }
      } while( true );
    }
  } while( true );
code_r0x030044b8:
  sVar6 = *(short *)(unaff_r7 + 4) + 5;
LAB_03004520:
  *(short *)(unaff_r7 + 4) = sVar6;
  while ((*(char *)(unaff_r8 + (uint)*(ushort *)(unaff_r7 + 4)) != ']' ||
         (*(char *)((uint)*(ushort *)(unaff_r7 + 4) + unaff_r8 + 1) == '['))) {
    iVar5 = FUN_03004338();
    if (iVar5 == -1) {
      return 0xffffffff;
    }
  }
  cVar1 = *(char *)((uint)*(ushort *)(unaff_r7 + 4) + unaff_r8 + 1);
  if (cVar1 != '\r') {
    unaff_r10 = unaff_r8;
  }
  if (cVar1 != '\r' && cVar1 != '\n') goto code_r0x03004552;
  *(undefined1 *)(DAT_0300470c + unaff_r4) = 0;
  goto LAB_030045f6;
code_r0x03004552:
  iVar5 = FUN_03004338();
  if (iVar5 == -1) {
    return 0xffffffff;
  }
  if (unaff_r5 == 0) {
    unaff_r4 = 0;
  }
  uVar4 = (uint)*(ushort *)(unaff_r7 + 4) + unaff_r10;
  bVar8 = *(char *)(uVar4 + 1) == '<';
  if (bVar8) {
    uVar4 = (uint)*(byte *)(uVar4 + 10);
  }
  unaff_r9 = (uint)(bVar8 && uVar4 == 0x3e);
  unaff_r11 = 2;
  unaff_r8 = unaff_r10;
  unaff_r10 = DAT_0300470c;
  goto code_r0x03004580;
}


