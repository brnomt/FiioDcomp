/**
 * FUN_030ae10c @ 0x030ae10c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_030ae10c(int *param_1,int *param_2,uint *param_3,int *param_4)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int unaff_r7;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  undefined1 auStack_48 [20];
  int *piStack_34;
  int *piStack_30;
  uint *puStack_2c;
  int *piStack_28;
  
  if (param_1 != (int *)0x0) {
    unaff_r7 = *param_1;
  }
  if (param_1 == (int *)0x0 || unaff_r7 == 0) {
    return 0xfffffffe;
  }
  piStack_34 = param_1;
  piStack_30 = param_2;
  puStack_2c = param_3;
  piStack_28 = param_4;
  FUN_030b1524(auStack_48,*param_4 + 7 >> 3,*param_2);
  bitstream_getbits(auStack_48,*param_3);
  iVar9 = unaff_r7 + 0x38;
  iVar4 = bitstream_getbits(auStack_48,8);
  if ((((iVar4 == 0x41) && (iVar4 = bitstream_getbits(auStack_48,8), iVar4 == 0x44)) &&
      (iVar4 = bitstream_getbits(auStack_48,8), iVar4 == 0x49)) &&
     (iVar4 = bitstream_getbits(auStack_48,8), iVar4 == 0x46)) {
    cVar2 = bitstream_getbits(auStack_48,1);
    *(char *)(unaff_r7 + 0x1c) = cVar2;
    if (cVar2 != '\0') {
      iVar4 = 0;
      do {
        cVar2 = bitstream_getbits(auStack_48,8);
        iVar10 = iVar4 + 1;
        ((char *)(unaff_r7 + 0x1c))[iVar4 + 0x10] = cVar2;
        iVar4 = iVar10;
      } while (iVar10 < 9);
    }
    uVar3 = bitstream_getbits(auStack_48,1);
    *(undefined1 *)(unaff_r7 + 0x1d) = uVar3;
    uVar3 = bitstream_getbits(auStack_48,1);
    *(undefined1 *)(unaff_r7 + 0x1e) = uVar3;
    uVar3 = bitstream_getbits(auStack_48,1);
    *(undefined1 *)(unaff_r7 + 0x1f) = uVar3;
    uVar5 = bitstream_getbits(auStack_48,0x17);
    *(undefined4 *)(unaff_r7 + 0x20) = uVar5;
    cVar2 = bitstream_getbits(auStack_48,4);
    *(char *)(unaff_r7 + 0x24) = cVar2 + '\x01';
    if (*(char *)(unaff_r7 + 0x1f) == '\0') {
      uVar5 = bitstream_getbits(auStack_48,0x14);
      *(undefined4 *)(unaff_r7 + 0x28) = uVar5;
    }
    iVar4 = 0;
    if (*(char *)(unaff_r7 + 0x24) != '\0') {
      do {
        FUN_030b17a8(iVar9 + iVar4 * 0x52,auStack_48);
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)(uint)*(byte *)(unaff_r7 + 0x24));
    }
    FUN_030b1718(auStack_48);
    uVar13 = (uint)*(byte *)(unaff_r7 + 0x24);
    if (uVar13 - 1 < 0x10) {
      iVar4 = 0;
      iVar10 = 0;
      if (uVar13 != 0) {
        do {
          iVar7 = iVar9 + iVar10 * 0x52;
          cVar2 = *(char *)(iVar7 + 1);
          bVar14 = cVar2 == '\x01';
          if (bVar14) {
            cVar2 = *(char *)(iVar7 + 8);
          }
          if (!bVar14 || cVar2 != '\0') goto LAB_030ae250;
          uVar8 = (uint)*(byte *)(iVar7 + 3);
          uVar12 = (uint)*(byte *)(iVar7 + 4);
          uVar11 = (uint)*(byte *)(iVar7 + 5);
          iVar4 = (uint)*(byte *)(iVar7 + 6) + uVar8 + iVar4 + uVar12 + uVar11;
          if (uVar8 != 0) {
            pbVar6 = (byte *)(iVar7 + 0xc);
            do {
              if ((*pbVar6 & 0x10) != 0) {
                iVar4 = iVar4 + 1;
              }
              uVar8 = uVar8 - 1;
              pbVar6 = pbVar6 + 1;
            } while (uVar8 != 0);
          }
          if (uVar12 != 0) {
            pbVar6 = (byte *)(iVar7 + 0x1b);
            do {
              if ((*pbVar6 & 0x10) != 0) {
                iVar4 = iVar4 + 1;
              }
              uVar12 = uVar12 - 1;
              pbVar6 = pbVar6 + 1;
            } while (uVar12 != 0);
          }
          if (uVar11 != 0) {
            pbVar6 = (byte *)(iVar7 + 0x2a);
            do {
              if ((*pbVar6 & 0x10) != 0) {
                iVar4 = iVar4 + 1;
              }
              uVar11 = uVar11 - 1;
              pbVar6 = pbVar6 + 1;
            } while (uVar11 != 0);
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < (int)uVar13);
      }
    }
    else {
LAB_030ae250:
      iVar4 = -1;
    }
    *(int *)(unaff_r7 + 0x870) = iVar4;
    if (2 < iVar4) {
      iVar4 = 2;
    }
    *(int *)(unaff_r7 + 0x870) = iVar4;
    uVar13 = (uint)*(byte *)(unaff_r7 + 0x24);
    if (uVar13 - 1 < 0x10) {
      uVar8 = (uint)*(byte *)(unaff_r7 + 0x3a);
      if (uVar13 < 2) {
        uVar11 = 0;
      }
      else {
        uVar11 = ~uVar13 & 1;
      }
      iVar10 = 1;
      uVar11 = uVar11 + 1;
      if (1 < uVar11) {
        do {
          if (*(byte *)(iVar9 + iVar10 * 0x52 + 2) != uVar8) goto LAB_030ae384;
          iVar10 = iVar10 + 1;
        } while (iVar10 < (int)uVar11);
      }
      if (uVar11 < uVar13) {
        do {
          uVar12 = iVar9 + uVar11 * 0x52;
          bVar14 = *(byte *)(uVar12 + 2) == uVar8;
          if (bVar14) {
            uVar12 = (uint)*(byte *)(uVar12 + 0x54);
          }
          if (!bVar14 || uVar12 != uVar8) goto LAB_030ae384;
          uVar11 = uVar11 + 2;
        } while ((int)uVar11 < (int)uVar13);
      }
    }
    else {
LAB_030ae384:
      uVar8 = 0xffffffff;
    }
    *(uint *)(unaff_r7 + 0x878) = uVar8;
    if ((-1 < iVar4 && -1 < (int)uVar8) && ((int)uVar8 < 0xc)) {
      param_1[9] = -1;
      param_1[10] = -1;
      param_1[0xb] = -1;
      param_1[0xf] = 0;
      piVar1 = DAT_030ae53c;
      param_1[0x10] = *(int *)(unaff_r7 + 0x870);
      param_1[0x11] = *(int *)(*piVar1 + *(int *)(unaff_r7 + 0x878) * 4);
      param_1[0x12] = (uint)*(byte *)(unaff_r7 + 0x39);
      param_1[0x14] = 0;
      iVar4 = FUN_030b16fc(auStack_48,*piStack_30,*param_3);
      *piStack_30 = *piStack_30 + ((int)(*param_3 + iVar4) >> 3);
      *param_3 = (uint)(byte)*param_3 + iVar4 & 7;
      iVar9 = *piStack_28;
      *piStack_28 = iVar9 - iVar4;
      if (iVar9 - iVar4 < 0) {
        uVar5 = 0xffffffff;
      }
      else {
        uVar5 = 0;
      }
      return uVar5;
    }
  }
  return 0xfffffffc;
}


