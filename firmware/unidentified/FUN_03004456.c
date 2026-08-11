/**
 * FUN_03004456 @ 0x03004456
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03004456(int param_1)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int unaff_r10;
  bool bVar12;
  bool bVar13;
  
  iVar3 = DAT_03004704;
  uVar11 = 0;
  iVar10 = 0;
  iVar7 = DAT_03004708;
  iVar5 = DAT_03004704;
  do {
    while (iVar4 = FUN_03004382(), iVar4 != 0) {
joined_r0x03004478:
      if (iVar4 == -1) {
        return 0xffffffff;
      }
    }
    iVar4 = iVar5 + (uint)*(ushort *)(iVar3 + -0x128);
    if (*(char *)(iVar4 + 6) == ':') {
      if ((9 < *(byte *)(iVar4 + 7) - 0x30) || (9 < *(byte *)(iVar4 + 8) - 0x30)) goto LAB_03004526;
      iVar9 = (*(byte *)(iVar4 + 1) - 0x30) * 10 + -0x30 + (uint)*(byte *)(iVar4 + 2);
      unaff_r10 = iVar9 * 0x1f;
      if (((uint)*(byte *)(iVar4 + 5) + (*(byte *)(iVar4 + 4) - 0x30) * 10) * 0x3c +
          (uint)*(byte *)(iVar4 + 7) * 10 + (uint)*(byte *)(iVar4 + 8) + iVar9 * 0xe10 + -0xd50 !=
          param_1) {
        sVar8 = 8;
        goto LAB_03004524;
      }
      sVar8 = *(short *)(iVar3 + -0x128) + 8;
    }
    else {
      if (iVar7 + (uint)*(byte *)(iVar4 + 4) * 10 +
          (uint)*(byte *)(iVar4 + 5) +
          ((*(byte *)(iVar4 + 1) - 0x30) * 10 + -0x30 + (uint)*(byte *)(iVar4 + 2)) * 0x3c !=
          param_1) {
        sVar8 = 5;
LAB_03004524:
        *(ushort *)(iVar3 + -0x128) = *(ushort *)(iVar3 + -0x128) + sVar8;
LAB_03004526:
        iVar4 = FUN_03004338();
        goto joined_r0x03004478;
      }
      sVar8 = *(short *)(iVar3 + -0x128) + 5;
    }
    *(short *)(iVar3 + -0x128) = sVar8;
    while ((*(char *)(iVar5 + (uint)*(ushort *)(iVar3 + -0x128)) != ']' ||
           (*(char *)((uint)*(ushort *)(iVar3 + -0x128) + iVar5 + 1) == '['))) {
      iVar7 = FUN_03004338();
      if (iVar7 == -1) {
        return 0xffffffff;
      }
    }
    cVar1 = *(char *)((uint)*(ushort *)(iVar3 + -0x128) + iVar5 + 1);
    if (cVar1 != '\r') {
      unaff_r10 = iVar5;
    }
    if (cVar1 == '\r' || cVar1 == '\n') {
      *(undefined1 *)(DAT_0300470c + iVar10) = 0;
    }
    else {
      iVar5 = FUN_03004338();
      iVar7 = DAT_0300470c;
      if (iVar5 == -1) {
        return 0xffffffff;
      }
      if (uVar11 == 0) {
        iVar10 = 0;
      }
      uVar6 = (uint)*(ushort *)(iVar3 + -0x128) + unaff_r10;
      bVar12 = *(char *)(uVar6 + 1) == '<';
      if (bVar12) {
        uVar6 = (uint)*(byte *)(uVar6 + 10);
      }
      bVar12 = bVar12 && uVar6 == 0x3e;
      do {
        bVar2 = *(byte *)(unaff_r10 + (uint)*(ushort *)(iVar3 + -0x128));
        uVar6 = (uint)bVar2;
        if ((uVar6 == 0x5b || uVar6 == 0xd) || uVar6 == 10) break;
        if ((uVar6 == 0x3c) && (*(char *)((uint)*(ushort *)(iVar3 + -0x128) + unaff_r10 + 9) == '>')
           ) {
          bVar12 = true;
LAB_030045a8:
          if (9 < uVar6 - 0x30) {
            bVar13 = 0x3b < uVar6;
            if (uVar6 != 0x3c) {
              bVar13 = 0x3d < uVar6;
            }
            if (bVar13 && (uVar6 != 0x3c && uVar6 != 0x3e)) goto LAB_030045b8;
          }
        }
        else {
          if (bVar12) goto LAB_030045a8;
LAB_030045b8:
          *(byte *)(iVar7 + iVar10) = bVar2;
          iVar10 = iVar10 + 1;
        }
        if (1 < iVar10) {
          iVar5 = iVar7 + iVar10;
          cVar1 = *(char *)(iVar5 + -2);
          bVar13 = cVar1 == -0x3e;
          if (bVar13) {
            cVar1 = *(char *)(iVar5 + -1);
          }
          if (bVar13 && cVar1 == -0x60) {
            *(undefined1 *)(iVar5 + -2) = 2;
            *(undefined1 *)(iVar5 + -1) = 0x20;
          }
        }
        iVar5 = FUN_03004338();
      } while (iVar5 != -1);
      *(undefined1 *)(iVar7 + iVar10) = 0;
      iVar5 = unaff_r10;
      unaff_r10 = iVar7;
    }
    uVar11 = uVar11 + 1;
    iVar7 = DAT_03004708;
    if (3 < uVar11) {
      return 0;
    }
  } while( true );
}


