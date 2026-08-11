/**
 * FUN_030b28b2 @ 0x030b28b2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_030b28b2(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  char cVar8;
  undefined1 uVar9;
  byte bVar10;
  byte bVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  undefined4 uVar15;
  int iVar16;
  int iVar17;
  undefined2 *puVar18;
  char *pcVar19;
  byte *pbVar20;
  int iVar21;
  int iVar22;
  byte *pbVar23;
  undefined1 *puVar24;
  undefined1 *puVar25;
  int iVar26;
  byte *pbVar27;
  int iVar28;
  int local_68;
  int local_64;
  int local_58;
  undefined1 *local_48;
  byte abStack_42 [2];
  undefined4 local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  
  if ((param_3 != 1) || (iVar16 = param_1, *(int *)(param_1 + 0x8f0) != 1)) {
    iVar16 = param_1 + param_3 * 0x3a;
  }
  local_30 = param_1;
  local_2c = param_2;
  local_28 = param_3;
  local_38 = bitstream_getbits(param_2,8);
  if (*(int *)(local_30 + 0x8f0) == 0) {
    FUN_030b26e8(local_2c,iVar16 + 0x87c,*(undefined4 *)(local_30 + 0x878));
  }
  uVar7 = local_2c;
  piVar4 = DAT_030b2d4c;
  bVar10 = *(byte *)(iVar16 + 0x8ad);
  iVar21 = 0;
  bVar1 = *(byte *)(iVar16 + 0x87f);
  local_40 = local_28 * 0xf;
  local_3c = local_30 + local_28 * 0x78;
  puVar24 = (undefined1 *)(local_3c + 0xad4);
  if (*(char *)(iVar16 + 0x87d) == '\x02') {
    iVar12 = 3;
  }
  else {
    iVar12 = 5;
  }
  iVar28 = 0;
  if (bVar10 != 0) {
    do {
      iVar26 = 0;
      if (bVar1 != 0) {
        do {
          local_34 = bitstream_getbits(uVar7,4);
          iVar17 = 0;
          iVar22 = iVar21;
          do {
            iVar21 = iVar22 + 1;
            if (0x7fff < iVar22) break;
            iVar13 = bitstream_getbits(uVar7,iVar12);
            iVar17 = iVar17 + iVar13;
            iVar22 = iVar21;
          } while (*piVar4 == 0 && iVar13 == (1 << iVar12) + -1);
          iVar26 = iVar26 + iVar17;
          if (iVar17 < 1) goto LAB_030b29ba;
          if (iVar17 != 0) {
            puVar25 = puVar24;
            do {
              iVar17 = iVar17 + -1;
              puVar24 = puVar25 + 1;
              *puVar25 = (char)local_34;
              if (*piVar4 != 0) break;
              puVar25 = puVar24;
            } while (iVar17 != 0);
          }
        } while (iVar26 < (int)(uint)bVar1);
      }
      iVar28 = iVar28 + 1;
    } while (iVar28 < (int)(uint)bVar10);
  }
LAB_030b29ba:
  uVar7 = local_2c;
  puVar6 = DAT_030b2d54;
  puVar5 = DAT_030b2d50;
  pbVar27 = (byte *)(local_3c + 0xad4);
  local_68 = local_38;
  local_58 = local_38 + -0x15a;
  iVar21 = 0;
  iVar28 = (uint)*(byte *)(iVar16 + 0x8ad) * (uint)*(byte *)(iVar16 + 0x87f);
  puVar18 = (undefined2 *)(local_30 + local_40 * 0x10 + 0x8f4);
  iVar12 = 0;
  local_40 = 1;
  if (iVar28 != 0) {
    do {
      uVar14 = (uint)*pbVar27;
      if (uVar14 == 0xe || uVar14 == 0xf) {
        iVar26 = FUN_030b1610(uVar7,*(undefined4 *)*puVar5);
        uVar15 = FUN_030b3be4(*puVar6,(int *)*puVar5,iVar26 << (0x20U - *(int *)*puVar5 & 0xff),
                              &local_3c);
        bitstream_getbits_copy(uVar7,uVar15);
        iVar21 = iVar21 + local_3c;
        *puVar18 = (short)iVar21;
      }
      else if (uVar14 == 0xd) {
        if (local_40 == 0) {
          iVar26 = FUN_030b1610(uVar7,*(undefined4 *)*puVar5);
          uVar15 = FUN_030b3be4(*puVar6,(int *)*puVar5,iVar26 << (0x20U - *(int *)*puVar5 & 0xff),
                                &local_3c);
          bitstream_getbits_copy(uVar7,uVar15);
          iVar26 = local_3c;
        }
        else {
          iVar26 = bitstream_getbits(uVar7,9);
          local_40 = 0;
        }
        local_58 = iVar26 + local_58;
        *puVar18 = (short)local_58;
      }
      else if (uVar14 - 1 < 0xb) {
        iVar26 = FUN_030b1610(uVar7,*(undefined4 *)*puVar5);
        uVar15 = FUN_030b3be4(*puVar6,(int *)*puVar5,iVar26 << (0x20U - *(int *)*puVar5 & 0xff),
                              &local_3c);
        bitstream_getbits_copy(uVar7,uVar15);
        local_68 = local_3c + local_68;
        *puVar18 = (short)local_68;
      }
      else {
        *puVar18 = 0;
      }
      puVar18 = puVar18 + 1;
      iVar12 = iVar12 + 1;
      pbVar27 = pbVar27 + 1;
    } while (iVar28 - iVar12 != 0 && iVar12 <= iVar28);
  }
  iVar21 = local_28 * 0xb + local_30;
  pcVar19 = (char *)(iVar21 + 0xbec);
  cVar8 = bitstream_getbits(local_2c,1);
  uVar7 = local_2c;
  *pcVar19 = cVar8;
  if (cVar8 != '\0') {
    cVar8 = bitstream_getbits(local_2c,2);
    *(char *)(iVar21 + 0xbed) = cVar8 + '\x01';
    uVar9 = bitstream_getbits(uVar7,6);
    *(undefined1 *)(iVar21 + 0xbee) = uVar9;
    iVar12 = 0;
    if (*(char *)(iVar21 + 0xbed) != '\0') {
      do {
        cVar8 = bitstream_getbits(uVar7,5);
        pcVar19[iVar12 + 3] = cVar8;
        cVar8 = bitstream_getbits(uVar7,4);
        pcVar19[iVar12 + 7] = cVar8;
        iVar12 = iVar12 + 1;
      } while (iVar12 < (int)(uint)*(byte *)(iVar21 + 0xbed));
    }
  }
  iVar21 = local_28 * 0x65 + local_30;
  pcVar19 = (char *)(iVar21 + 0xc02);
  cVar8 = bitstream_getbits(local_2c,1);
  uVar7 = local_2c;
  *pcVar19 = cVar8;
  if (cVar8 != '\0') {
    pbVar27 = (byte *)(iVar21 + 0xc2b);
    local_40 = DAT_030b2d58;
    puVar24 = (undefined1 *)(iVar21 + 0xc13);
    local_3c = DAT_030b2d5c;
    local_48 = (undefined1 *)(iVar21 + 0xc23);
    pbVar23 = (byte *)(iVar21 + 0xc1b);
    if (*(char *)(iVar16 + 0x87d) == '\x02') {
      iVar21 = 0;
      do {
        cVar8 = bitstream_getbits(uVar7,1);
        pcVar19[iVar21 + 1] = cVar8;
        if (cVar8 != '\0') {
          cVar8 = bitstream_getbits(uVar7,1);
          pcVar19[iVar21 + 9] = cVar8 + '\x03';
          uVar9 = bitstream_getbits(uVar7,4);
          *puVar24 = uVar9;
          bVar10 = bitstream_getbits(uVar7,3);
          *pbVar23 = bVar10;
          if (bVar10 != 0) {
            uVar9 = bitstream_getbits(uVar7,1);
            *local_48 = uVar9;
            local_48 = local_48 + 1;
            iVar12 = bitstream_getbits(uVar7,1);
            iVar28 = 0;
            iVar12 = (uint)(byte)pcVar19[iVar21 + 9] - iVar12;
            bVar10 = abStack_42[iVar12];
            bVar1 = *(byte *)((int)&local_40 + iVar12 + 2);
            pbVar20 = pbVar27;
            if (*pbVar23 != 0) {
              do {
                bVar11 = bitstream_getbits(uVar7,iVar12);
                if ((bVar11 & bVar10) != 0) {
                  bVar11 = bVar11 | bVar1;
                }
                pbVar27 = pbVar20 + 1;
                *pbVar20 = bVar11;
                iVar28 = iVar28 + 1;
                pbVar20 = pbVar27;
              } while (iVar28 < (int)(uint)*pbVar23);
            }
          }
          puVar24 = puVar24 + 1;
          pbVar23 = pbVar23 + 1;
        }
        iVar21 = iVar21 + 1;
      } while (iVar21 < 8);
    }
    else {
      cVar8 = bitstream_getbits(local_2c,2);
      *(char *)(iVar21 + 0xc03) = cVar8;
      if (cVar8 != '\0') {
        cVar8 = bitstream_getbits(uVar7,1);
        *(char *)(iVar21 + 0xc0b) = cVar8 + '\x03';
      }
      iVar12 = 0;
      if (*(char *)(iVar21 + 0xc03) != '\0') {
        do {
          uVar9 = bitstream_getbits(uVar7,6);
          *puVar24 = uVar9;
          bVar10 = bitstream_getbits(uVar7,5);
          *pbVar23 = bVar10;
          if (bVar10 != 0) {
            uVar9 = bitstream_getbits(uVar7,1);
            *local_48 = uVar9;
            local_48 = local_48 + 1;
            iVar28 = bitstream_getbits(uVar7,1);
            iVar26 = 0;
            iVar28 = (uint)*(byte *)(iVar21 + 0xc0b) - iVar28;
            bVar10 = abStack_42[iVar28];
            bVar1 = *(byte *)((int)&local_40 + iVar28 + 2);
            pbVar20 = pbVar27;
            if (*pbVar23 != 0) {
              do {
                bVar11 = bitstream_getbits(uVar7,iVar28);
                if ((bVar11 & bVar10) != 0) {
                  bVar11 = bVar11 | bVar1;
                }
                pbVar27 = pbVar20 + 1;
                *pbVar20 = bVar11;
                iVar26 = iVar26 + 1;
                pbVar20 = pbVar27;
              } while (iVar26 < (int)(uint)*pbVar23);
            }
          }
          pbVar23 = pbVar23 + 1;
          iVar12 = iVar12 + 1;
          puVar24 = puVar24 + 1;
        } while (iVar12 < (int)(uint)*(byte *)(iVar21 + 0xc03));
      }
    }
  }
  iVar21 = local_30 + local_28 * 0x16a;
  pcVar19 = (char *)(iVar21 + 0xd6c);
  cVar8 = bitstream_getbits(local_2c,1);
  uVar7 = local_2c;
  *pcVar19 = cVar8;
  if (cVar8 != '\0') {
    bVar10 = *(byte *)(iVar16 + 0x87d);
    cVar8 = bitstream_getbits(local_2c,2);
    piVar4 = DAT_030b2d60;
    *(char *)(iVar21 + 0xd6d) = cVar8;
    iVar16 = (uint)bVar10 * 3;
    uVar14 = (uint)*(byte *)(*piVar4 + iVar16);
    iVar16 = iVar16 + *piVar4;
    uVar9 = *(undefined1 *)(iVar16 + 1);
    uVar2 = *(undefined1 *)(iVar16 + 2);
    local_64 = 1;
    if (cVar8 != '\0') {
      do {
        iVar16 = 0;
        if (uVar14 != 0) {
          do {
            cVar8 = bitstream_getbits(uVar7,3);
            iVar12 = iVar16 + local_64 * 8;
            iVar28 = 0;
            pcVar19[iVar12 + 2] = cVar8;
            if (cVar8 != '\0') {
              do {
                cVar8 = bitstream_getbits(uVar7,4);
                iVar26 = iVar28 + iVar16 * 7 + local_64 * 0x38;
                pcVar19[iVar26 + 0x1a] = cVar8;
                uVar3 = uVar9;
                if (iVar16 != 0) {
                  uVar3 = uVar2;
                }
                cVar8 = bitstream_getbits(uVar7,uVar3);
                pcVar19[iVar26 + 0xc2] = cVar8;
                iVar28 = iVar28 + 1;
              } while (iVar28 < (int)(uint)(byte)pcVar19[iVar12 + 2]);
            }
            iVar16 = iVar16 + 1;
          } while (iVar16 < (int)uVar14);
        }
        local_64 = local_64 + 1;
      } while (local_64 <= (int)(uint)*(byte *)(iVar21 + 0xd6d));
      return;
    }
    return;
  }
  return;
}


