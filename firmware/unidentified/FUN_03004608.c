/**
 * FUN_03004608 @ 0x03004608
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03004608(void)

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
  int unaff_r10;
  char in_ZR;
  bool bVar8;
  bool bVar9;
  
  do {
    if (in_ZR != '\0') {
      return 0xffffffff;
    }
LAB_03004530:
    if ((*(char *)(unaff_r8 + (uint)*(ushort *)(unaff_r7 + 4)) == ']') &&
       (*(char *)((uint)*(ushort *)(unaff_r7 + 4) + unaff_r8 + 1) != '[')) {
      cVar1 = *(char *)((uint)*(ushort *)(unaff_r7 + 4) + unaff_r8 + 1);
      if (cVar1 != '\r') {
        unaff_r10 = unaff_r8;
      }
      if (cVar1 == '\r' || cVar1 == '\n') {
        *(undefined1 *)(DAT_0300470c + unaff_r4) = 0;
      }
      else {
        iVar3 = FUN_03004338();
        iVar5 = DAT_0300470c;
        if (iVar3 == -1) {
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
        bVar8 = bVar8 && uVar4 == 0x3e;
        do {
          bVar2 = *(byte *)(unaff_r10 + (uint)*(ushort *)(unaff_r7 + 4));
          uVar4 = (uint)bVar2;
          if ((uVar4 == 0x5b || uVar4 == 0xd) || uVar4 == 10) break;
          if ((uVar4 == 0x3c) && (*(char *)((uint)*(ushort *)(unaff_r7 + 4) + unaff_r10 + 9) == '>')
             ) {
            bVar8 = true;
LAB_030045a8:
            if (9 < uVar4 - 0x30) {
              bVar9 = 0x3b < uVar4;
              if (uVar4 != 0x3c) {
                bVar9 = 0x3d < uVar4;
              }
              if (bVar9 && (uVar4 != 0x3c && uVar4 != 0x3e)) goto LAB_030045b8;
            }
          }
          else {
            if (bVar8) goto LAB_030045a8;
LAB_030045b8:
            *(byte *)(iVar5 + unaff_r4) = bVar2;
            unaff_r4 = unaff_r4 + 1;
          }
          if (1 < unaff_r4) {
            iVar3 = iVar5 + unaff_r4;
            cVar1 = *(char *)(iVar3 + -2);
            bVar9 = cVar1 == -0x3e;
            if (bVar9) {
              cVar1 = *(char *)(iVar3 + -1);
            }
            if (bVar9 && cVar1 == -0x60) {
              *(undefined1 *)(iVar3 + -2) = 2;
              *(undefined1 *)(iVar3 + -1) = 0x20;
            }
          }
          iVar3 = FUN_03004338();
        } while (iVar3 != -1);
        *(undefined1 *)(iVar5 + unaff_r4) = 0;
        unaff_r8 = unaff_r10;
        unaff_r10 = iVar5;
      }
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
    iVar5 = FUN_03004338();
    in_ZR = iVar5 == -1;
  } while( true );
code_r0x030044b8:
  sVar6 = *(short *)(unaff_r7 + 4) + 5;
LAB_03004520:
  *(short *)(unaff_r7 + 4) = sVar6;
  goto LAB_03004530;
}


