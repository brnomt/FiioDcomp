/**
 * FUN_030ade84 @ 0x030ade84
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030ade84(int *param_1,int *param_2,uint *param_3,int *param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined1 uVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined1 *unaff_r4;
  bool bVar10;
  undefined1 auStack_30 [20];
  
  iVar6 = DAT_030ae2d8;
  *(int *)(DAT_030ae2d8 + 0x14) = *(int *)(DAT_030ae2d8 + 0x14) + 1;
  if (param_1 != (int *)0x0) {
    unaff_r4 = (undefined1 *)*param_1;
  }
  if (param_1 == (int *)0x0 || unaff_r4 == (undefined1 *)0x0) {
    return 0xfffffffe;
  }
  FUN_030b1524(auStack_30,*param_4 + 7 >> 3,*param_2);
  bitstream_getbits(auStack_30,*param_3);
  puVar1 = DAT_030ae2dc;
  if (*(int *)(iVar6 + 0x14) == 1) {
    uVar5 = FUN_030b1610(auStack_30,0x18);
    *puVar1 = uVar5;
    hifi_debug_printf_ovl(s_sameheader_0x_x_030ae2e0,uVar5);
  }
  iVar6 = bitstream_getbits(auStack_30,0xc);
  if (iVar6 == 0xfff) {
    uVar3 = bitstream_getbits(auStack_30,1);
    *unaff_r4 = uVar3;
    uVar3 = bitstream_getbits(auStack_30,2);
    unaff_r4[1] = uVar3;
    uVar3 = bitstream_getbits(auStack_30,1);
    unaff_r4[2] = uVar3;
    uVar3 = bitstream_getbits(auStack_30,2);
    unaff_r4[3] = uVar3;
    uVar3 = bitstream_getbits(auStack_30,4);
    unaff_r4[4] = uVar3;
    uVar3 = bitstream_getbits(auStack_30,1);
    unaff_r4[5] = uVar3;
    uVar3 = bitstream_getbits(auStack_30,3);
    unaff_r4[6] = uVar3;
    uVar3 = bitstream_getbits(auStack_30,1);
    unaff_r4[7] = uVar3;
    uVar3 = bitstream_getbits(auStack_30,1);
    unaff_r4[8] = uVar3;
    uVar3 = bitstream_getbits(auStack_30,1);
    unaff_r4[9] = uVar3;
    uVar3 = bitstream_getbits(auStack_30,1);
    unaff_r4[10] = uVar3;
    uVar5 = bitstream_getbits(auStack_30,0xd);
    piVar2 = DAT_030ae2f4;
    *(undefined4 *)(unaff_r4 + 0xc) = uVar5;
    if (*piVar2 == 1) {
      puVar1[1] = uVar5;
    }
    uVar5 = bitstream_getbits(auStack_30,0xb);
    *(undefined4 *)(unaff_r4 + 0x10) = uVar5;
    cVar4 = bitstream_getbits(auStack_30,2);
    unaff_r4[0x14] = cVar4 + '\x01';
    if (unaff_r4[2] == '\0') {
      uVar5 = bitstream_getbits(auStack_30,0x10);
      *(undefined4 *)(unaff_r4 + 0x18) = uVar5;
    }
    FUN_030b1718(auStack_30);
    uVar7 = (uint)(byte)unaff_r4[1];
    bVar10 = uVar7 == 0;
    if (bVar10) {
      uVar7 = (uint)(byte)unaff_r4[3];
    }
    if (bVar10 && uVar7 == 1) {
      uVar8 = (uint)(byte)unaff_r4[4];
      if (uVar8 < 0xc) {
        uVar7 = (uint)(byte)unaff_r4[6];
      }
      if (uVar8 < 0xc && uVar7 < 8) {
        *(uint *)(unaff_r4 + 0x878) = uVar8;
        if (*(int *)(unaff_r4 + 0x874) == 0) {
          *(undefined4 *)(unaff_r4 + 0x870) = *(undefined4 *)(*DAT_030ae314 + uVar7 * 4);
        }
        iVar6 = *(int *)(unaff_r4 + 0x870);
        if (2 < iVar6) {
          iVar6 = 2;
        }
        *(int *)(unaff_r4 + 0x870) = iVar6;
        param_1[9] = -1;
        param_1[10] = -1;
        param_1[0xb] = -1;
        param_1[0xf] = 0;
        piVar2 = DAT_030ae318;
        param_1[0x10] = *(int *)(unaff_r4 + 0x870);
        param_1[0x11] = *(int *)(*piVar2 + *(int *)(unaff_r4 + 0x878) * 4);
        param_1[0x12] = (uint)(byte)unaff_r4[3];
        param_1[0x14] = 0;
        param_1[0xe] = (uint)(byte)unaff_r4[0x14];
        iVar6 = FUN_030b16fc(auStack_30,*param_2,*param_3);
        *param_2 = *param_2 + ((int)(*param_3 + iVar6) >> 3);
        *param_3 = (uint)(byte)*param_3 + iVar6 & 7;
        iVar9 = *param_4;
        *param_4 = iVar9 - iVar6;
        if (iVar9 - iVar6 < 0) {
          uVar5 = 0xffffffff;
        }
        else {
          uVar5 = 0;
        }
        return uVar5;
      }
    }
    hifi_debug_printf_ovl(s_aac_frofile____d_return_030ae2f8,unaff_r4[3]);
    return 0xfffffffd;
  }
  return 0xfffffffd;
}


