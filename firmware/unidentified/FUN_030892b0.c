/**
 * FUN_030892b0 @ 0x030892b0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030892b0(int *param_1)

{
  char cVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 unaff_r8;
  bool bVar9;
  int iVar10;
  int local_38 [2];
  undefined4 local_30;
  undefined4 uStack_2c;
  
  iVar10 = DAT_03089594;
  puVar7 = (undefined4 *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x1f);
  iVar8 = 0;
joined_r0x030892c0:
  if (cVar1 == '\b') {
    return iVar8;
  }
LAB_030892d0:
  switch(*(undefined1 *)((int)param_1 + 0x1f)) {
  case 0:
    break;
  case 1:
    if (*(char *)(iVar10 + 8) == '\x01') {
      iVar8 = FUN_0308974a(param_1,puVar7[0x36]);
    }
    else {
      iVar8 = FUN_0308975e();
    }
    if (iVar8 < 0) {
      return iVar8;
    }
    *(undefined1 *)((int)param_1 + 0x1f) = 5;
    goto LAB_030892d0;
  default:
    goto switchD_030892d6_caseD_2;
  case 5:
    goto switchD_030892d6_caseD_5;
  }
  iVar8 = FUN_03086e2c(param_1);
  if (iVar8 < 0) {
    return iVar8;
  }
  *(undefined1 *)((int)param_1 + 0x1f) = 1;
  *(undefined2 *)(*param_1 + 0x6c) = 0;
  *(undefined2 *)(param_1 + 0xd) = 0;
  if (*(int *)(*param_1 + 0x40) < 3) {
    *(undefined1 *)(param_1 + 9) = 0;
  }
switchD_030892d6_caseD_2:
  cVar1 = *(char *)((int)param_1 + 0x1f);
  goto joined_r0x030892c0;
switchD_030892d6_caseD_5:
  if ((*(char *)(puVar7 + 0x12) == '\x03') && (iVar10 = 0, *(short *)((int)puVar7 + 0x26) != 0)) {
    do {
      puVar6 = (undefined4 *)(puVar7[0x36] + *(short *)(puVar7[99] + iVar10 * 2) * 0xfc);
      if (puVar6[0xc] != 0) {
        FUN_03089278(*puVar6,puVar6[0xb],puVar6,*(undefined1 *)(puVar7 + 0x12));
      }
      iVar10 = (int)(short)((short)iVar10 + 1);
    } while (iVar10 < (int)(uint)*(ushort *)((int)puVar7 + 0x26));
  }
  FUN_0308809c(&local_30,puVar7[0x31],local_38);
  *puVar7 = local_30;
  puVar7[1] = uStack_2c;
  if (local_38[0] == -1) {
    return -0xe;
  }
  iVar10 = 0;
  if (*(short *)((int)puVar7 + 0x26) != 0) {
    do {
      iVar4 = puVar7[0x36] + *(short *)(puVar7[99] + iVar10 * 2) * 0xfc;
      if (*(int *)(iVar4 + 0x30) == 0) {
        wma_memclr(*(undefined4 *)(iVar4 + 0x44),(int)*(short *)(iVar4 + 0x80) << 2);
      }
      else {
        if (puVar7[0x2d] == 1) {
          if (puVar7[0xb] == 0) {
            puVar7[0x57] = 0;
          }
          else {
            iVar8 = FUN_0308ab5a(puVar7,iVar4,*(undefined4 *)(iVar4 + 0x40));
          }
        }
        else {
          iVar8 = FUN_03089e38(puVar7,iVar4,*(undefined4 *)(iVar4 + 0x40));
        }
        if (iVar8 < 0) {
          return iVar8;
        }
      }
      iVar10 = (int)(short)((short)iVar10 + 1);
    } while (iVar10 < (int)(uint)*(ushort *)((int)puVar7 + 0x26));
  }
  FUN_03088254(puVar7,1);
  FUN_03088254(puVar7,0);
  iVar10 = 0;
  bVar9 = true;
  if (0 < *(short *)(puVar7 + 0x62)) {
    do {
      if (*(int *)(puVar7[0x36] + *(short *)(puVar7[99] + iVar10 * 2) * 0xfc + 0x30) != 0) {
        bVar9 = false;
        break;
      }
      iVar10 = (int)(short)((short)iVar10 + 1);
    } while (iVar10 < *(short *)(puVar7 + 0x62));
  }
  if (((2 < (int)puVar7[0x10]) && (!bVar9)) && (iVar10 = 0, *(short *)((int)puVar7 + 0x26) != 0)) {
    do {
      iVar5 = (int)*(short *)(puVar7[99] + iVar10 * 2);
      iVar4 = puVar7[0x36] + iVar5 * 0xfc;
      if (*(short *)(puVar7 + 0x1a) == iVar5) {
        wma_memclr(*(int *)(iVar4 + 0x44) + puVar7[0x34] * 4,
                   ((int)*(short *)(iVar4 + 0x82) - puVar7[0x34]) * 4);
      }
      *(undefined2 *)(puVar7 + 0x1b) = 0xffff;
      iVar10 = (int)(short)((short)iVar10 + 1);
    } while (iVar10 < (int)(uint)*(ushort *)((int)puVar7 + 0x26));
  }
  if ((puVar7[0xb] == 0) && (iVar10 = 0, *(short *)((int)puVar7 + 0x26) != 0)) {
    do {
      iVar4 = puVar7[0x36] + *(short *)(puVar7[99] + iVar10 * 2) * 0xfc;
      wma_memclr(*(int *)(iVar4 + 0x44) + puVar7[0x56] * 4,
                 ((int)*(short *)(iVar4 + 0x82) - puVar7[0x56]) * 4);
      iVar10 = (int)(short)((short)iVar10 + 1);
    } while (iVar10 < (int)(uint)*(ushort *)((int)puVar7 + 0x26));
  }
  uVar3 = DAT_03089598;
  if ((!bVar9) && (iVar10 = 0, *(short *)((int)puVar7 + 0x26) != 0)) {
    do {
      iVar5 = puVar7[0x10];
      iVar4 = puVar7[0x36] + *(short *)(puVar7[99] + iVar10 * 2) * 0xfc;
      if (iVar5 == 1) {
        sVar2 = *(short *)(iVar4 + 0x82);
        if ((sVar2 == 0x800 || sVar2 == 0x200) || (unaff_r8 = uVar3, sVar2 == 0x80)) {
          unaff_r8 = 0x7fffffff;
        }
      }
      else if (iVar5 == 2) {
        unaff_r8 = 0x40000000;
      }
      if ((*(int *)(iVar4 + 0x30) != 0) || (2 < iVar5)) {
        FUN_030878ba(*(undefined4 *)(iVar4 + 0x44),unaff_r8,(int)*(short *)(iVar4 + 0x82));
      }
      iVar10 = (int)(short)((short)iVar10 + 1);
    } while (iVar10 < (int)(uint)*(ushort *)((int)puVar7 + 0x26));
  }
  *(undefined1 *)((int)param_1 + 0x1f) = 8;
  return iVar8;
}


