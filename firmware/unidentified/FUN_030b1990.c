/**
 * FUN_030b1990 @ 0x030b1990
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_030b1990(int *param_1,int *param_2,uint *param_3,int *param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  byte *pbVar9;
  int unaff_r5;
  uint uVar10;
  undefined1 auStack_54 [24];
  undefined1 *puStack_3c;
  int *piStack_34;
  int *piStack_30;
  uint *puStack_2c;
  int *piStack_28;
  
  if (param_1 != (int *)0x0) {
    unaff_r5 = *param_1;
  }
  if (param_1 == (int *)0x0 || unaff_r5 == 0) {
    return 0xfffffffe;
  }
  piStack_34 = param_1;
  piStack_30 = param_2;
  puStack_2c = param_3;
  piStack_28 = param_4;
  FUN_030b1524(auStack_54,*param_4 + 7 >> 3,*param_2);
  FUN_030b16a6(auStack_54,*param_3);
  param_1[9] = param_1[10];
  iVar4 = bitstream_getbits(auStack_54,3);
  param_1[10] = iVar4;
  *(undefined4 *)(unaff_r5 + 0x8f0) = 0;
  switch(param_1[10]) {
  case 0:
    iVar4 = *param_1;
    goto joined_r0x030b1a9e;
  case 1:
    iVar4 = *param_1;
    if (iVar4 == 0) {
      return 0xfffffff8;
    }
    iVar8 = bitstream_getbits(auStack_54,4);
    param_1[0xb] = iVar8;
    iVar8 = bitstream_getbits(auStack_54,1);
    *(int *)(iVar4 + 0x8f0) = iVar8;
    if (iVar8 != 0) {
      FUN_030b26e8(auStack_54,iVar4 + 0x87c,*(undefined4 *)(iVar4 + 0x878));
      iVar8 = bitstream_getbits(auStack_54,2);
      *(int *)(iVar4 + 0xbc4) = iVar8;
      if (iVar8 == 1) {
        *(undefined1 *)(iVar4 + 0xbc8) = 0;
        uVar10 = 0;
        pbVar9 = (byte *)(iVar4 + 0xbc8);
        iVar8 = 0;
        if (*(char *)(iVar4 + 0x8ad) != '\0') {
          do {
            iVar6 = 0;
            if (*(char *)(iVar4 + 0x87f) != '\0') {
              do {
                iVar5 = bitstream_getbits(auStack_54,1);
                uVar1 = uVar10 & 0xff;
                uVar10 = uVar10 + 1;
                *pbVar9 = (byte)(iVar5 << uVar1) | *pbVar9;
                if (uVar10 == 8) {
                  pbVar9 = pbVar9 + 1;
                  *pbVar9 = 0;
                  uVar10 = 0;
                }
                iVar6 = iVar6 + 1;
              } while (iVar6 < (int)(uint)*(byte *)(iVar4 + 0x87f));
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 < (int)(uint)*(byte *)(iVar4 + 0x8ad));
        }
      }
    }
    break;
  case 3:
    iVar4 = *param_1;
joined_r0x030b1a9e:
    if (iVar4 == 0) {
      return 0xfffffff8;
    }
    iVar4 = bitstream_getbits(auStack_54,4);
    param_1[0xb] = iVar4;
    break;
  case 4:
    iVar4 = *param_1;
    if (iVar4 == 0) {
      return 0xfffffff8;
    }
    iVar8 = bitstream_getbits(auStack_54,4);
    param_1[0xb] = iVar8;
    iVar6 = bitstream_getbits(auStack_54,1);
    iVar8 = bitstream_getbits(auStack_54,8);
    if (iVar8 == 0xff) {
      iVar8 = bitstream_getbits(auStack_54,8);
      iVar8 = iVar8 + 0xff;
    }
    if (iVar6 != 0) {
      FUN_030b1718(auStack_54);
    }
    *(int *)(iVar4 + 0x558) = iVar8;
    puVar2 = (undefined1 *)(iVar4 + 0x55c);
    for (; iVar8 != 0; iVar8 = iVar8 + -1) {
      uVar3 = bitstream_getbits(auStack_54,8);
      *puVar2 = uVar3;
      puVar2 = puVar2 + 1;
    }
    break;
  case 5:
    iVar4 = FUN_030b17a8(unaff_r5 + 0x38,auStack_54);
    if (iVar4 != 0) {
      return 0xfffffff8;
    }
    break;
  case 6:
    puStack_3c = auStack_54;
    iVar4 = *param_1;
    if (iVar4 == 0) {
      return 0xfffffff8;
    }
    iVar8 = bitstream_getbits(puStack_3c,4);
    if (iVar8 == 0xf) {
      iVar8 = bitstream_getbits(puStack_3c,8);
      iVar8 = iVar8 + 0xe;
    }
    *(int *)(iVar4 + 0x75c) = iVar8;
    puVar2 = (undefined1 *)(iVar4 + 0x760);
    for (; iVar8 != 0; iVar8 = iVar8 + -1) {
      uVar3 = bitstream_getbits(puStack_3c,8);
      *puVar2 = uVar3;
      puVar2 = puVar2 + 1;
    }
    param_1[8] = 0;
    param_1[0xb] = -1;
    param_1[6] = iVar4 + 0x760;
    param_1[7] = *(int *)(iVar4 + 0x75c);
  }
  iVar4 = FUN_030b16fc(auStack_54,*param_2,*param_3);
  *param_2 = *param_2 + ((int)(*param_3 + iVar4) >> 3);
  *param_3 = (uint)(byte)*param_3 + iVar4 & 7;
  iVar8 = *piStack_28;
  *piStack_28 = iVar8 - iVar4;
  if (iVar8 - iVar4 < 0) {
    uVar7 = 0xffffffff;
  }
  else {
    uVar7 = 0;
  }
  return uVar7;
}


