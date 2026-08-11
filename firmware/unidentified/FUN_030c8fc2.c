/**
 * FUN_030c8fc2 @ 0x030c8fc2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030c8fc2(int *param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint extraout_r1;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  
  iVar8 = *(int *)(param_2 + 0x1c);
  memset_byte(param_1,0,0x14);
  iVar2 = sbuf_read_bits(param_3,1);
  if (iVar2 == 0) {
    iVar2 = 1;
  }
  else {
    iVar2 = sbuf_read_bits(param_3,4);
    iVar2 = iVar2 + 1;
  }
  *param_1 = iVar2;
  iVar2 = sbuf_read_bits(param_3,1);
  if (iVar2 != 0) {
    iVar2 = sbuf_read_bits(param_3,8);
    iVar7 = 0;
    param_1[3] = iVar2 + 1;
    if (0 < iVar2 + 1) {
      do {
        uVar3 = FUN_030c4222(*(undefined4 *)(param_2 + 4));
        bVar1 = sbuf_read_bits(param_3,uVar3);
        uVar6 = (uint)bVar1;
        *(byte *)((int)param_1 + iVar7 * 2 + 0x10) = bVar1;
        uVar3 = FUN_030c4222(*(undefined4 *)(param_2 + 4));
        bVar1 = sbuf_read_bits(param_3,uVar3);
        uVar4 = (uint)bVar1;
        *(byte *)((int)param_1 + iVar7 * 2 + 0x11) = bVar1;
        bVar12 = SBORROW4(uVar6,uVar4);
        iVar2 = uVar6 - uVar4;
        bVar10 = uVar6 == uVar4;
        uVar5 = extraout_r1;
        if (!bVar10) {
          uVar5 = *(uint *)(param_2 + 4);
          bVar12 = SBORROW4(uVar5,uVar6);
          iVar2 = uVar5 - uVar6;
        }
        bVar9 = iVar2 < 0;
        bVar11 = bVar10 || uVar5 == uVar6;
        if ((!bVar10 && uVar5 != uVar6) && bVar9 == bVar12) {
          bVar12 = SBORROW4(uVar5,uVar4);
          bVar9 = (int)(uVar5 - uVar4) < 0;
          bVar11 = uVar5 == uVar4;
        }
        if (bVar11 || bVar9 != bVar12) goto LAB_030c90d8;
        iVar7 = iVar7 + 1;
      } while (iVar7 < param_1[3]);
    }
  }
  iVar2 = sbuf_read_bits(param_3,2);
  if (0 < iVar2) {
LAB_030c90d8:
    memset_byte(param_1 + 1,0,2);
    memset_byte((int)param_1 + 6,0,2);
    memset_byte(param_1 + 4,0,2);
    memset_byte(param_1,0,0x14);
    return 0xffffffff;
  }
  if ((1 < *param_1) && (iVar2 = 0, 0 < *(int *)(param_2 + 4))) {
    do {
      bVar1 = sbuf_read_bits(param_3,4);
      *(byte *)((int)param_1 + iVar2 + 4) = bVar1;
      if (*param_1 <= (int)(uint)bVar1) goto LAB_030c90d8;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_2 + 4));
  }
  iVar2 = 0;
  if (0 < *param_1) {
    do {
      sbuf_read_bits(param_3,8);
      bVar1 = sbuf_read_bits(param_3,8);
      *(byte *)((int)param_1 + iVar2 * 2 + 6) = bVar1;
      if (*(int *)(iVar8 + 0x10) <= (int)(uint)bVar1) goto LAB_030c90d8;
      bVar1 = sbuf_read_bits(param_3,8);
      *(byte *)((int)param_1 + iVar2 * 2 + 7) = bVar1;
      if (*(int *)(iVar8 + 0x14) <= (int)(uint)bVar1) goto LAB_030c90d8;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *param_1);
  }
  return 0;
}


