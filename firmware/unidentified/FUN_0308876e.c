/**
 * FUN_0308876e @ 0x0308876e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_0308876e(int *param_1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  int unaff_r6;
  bool bVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 unaff_r9;
  int local_30 [2];
  undefined4 local_28;
  undefined4 uStack_24;
  
  puVar4 = (undefined4 *)*param_1;
  iVar8 = 0;
  cVar1 = *(char *)((int)param_1 + 0x1f);
  if (cVar1 == '\0') {
    iVar8 = FUN_03086e2c(param_1);
    if (iVar8 < 0) {
      return iVar8;
    }
    FUN_0308809c(&local_28,puVar4[0x31],local_30);
    *puVar4 = local_28;
    puVar4[1] = uStack_24;
    if (local_30[0] == -1) {
      return -0xe;
    }
    iVar6 = 0;
    if (0 < *(short *)(puVar4 + 0x62)) {
      do {
        unaff_r6 = puVar4[0x36] + *(short *)(puVar4[99] + iVar6 * 2) * 0xfc;
        wma_memclr(*(undefined4 *)(unaff_r6 + 0x44),puVar4[0x56] << 2);
        iVar6 = (int)(short)((short)iVar6 + 1);
      } while (iVar6 < *(short *)(puVar4 + 0x62));
    }
    *(undefined1 *)((int)param_1 + 0x1f) = 1;
    *(short *)(*param_1 + 0x6c) = *(short *)(puVar4 + 0x29) + -1;
    *(undefined2 *)(param_1 + 0xd) = 0;
    if (*(int *)(*param_1 + 0x40) < 3) {
      *(undefined1 *)(param_1 + 9) = 0;
    }
LAB_03088818:
    if ((short)param_1[0xd] < *(short *)(puVar4 + 0x62)) {
      do {
        unaff_r6 = puVar4[0x36] + *(short *)(puVar4[99] + (short)param_1[0xd] * 2) * 0xfc;
        sVar2 = wma_floor_log2(*(int *)(unaff_r6 + 0x2c) + -1);
        *(short *)(param_1 + 0x36) = sVar2 + 1;
        if ((*(int *)(unaff_r6 + 0x30) != 0) &&
           (iVar8 = FUN_030884c8(puVar4,param_1,unaff_r6), iVar8 < 0)) {
          return iVar8;
        }
        if (puVar4[0x10] == 1) {
          param_1[0x2b] = param_1[0x2b] - (param_1[0x2b] & 7U);
        }
        *(short *)(puVar4 + 0x1b) = *(short *)(puVar4 + 0x29) + -1;
        if (*(int *)(*param_1 + 0x40) < 3) {
          *(undefined1 *)(param_1 + 9) = 0;
        }
        sVar2 = (short)param_1[0xd] + 1;
        *(short *)(param_1 + 0xd) = sVar2;
      } while (sVar2 < *(short *)(puVar4 + 0x62));
    }
    *(undefined1 *)((int)param_1 + 0x1f) = 5;
  }
  else {
    if (cVar1 == '\x01') goto LAB_03088818;
    if (cVar1 != '\x05') {
      return 0;
    }
  }
  iVar6 = 0;
  if (0 < *(short *)(puVar4 + 0x62)) {
    do {
      unaff_r6 = puVar4[0x36] + *(short *)(puVar4[99] + iVar6 * 2) * 0xfc;
      if (*(int *)(unaff_r6 + 0x30) == 0) {
        wma_memclr(*(undefined4 *)(unaff_r6 + 0x44),(int)*(short *)(unaff_r6 + 0x82) << 2);
        *(undefined4 *)(unaff_r6 + 0x3c) = 0;
      }
      else {
        *(undefined4 *)(unaff_r6 + 0x3c) = 0;
        if (*(char *)(puVar4 + 0x12) == '\x03') {
          FUN_03088490(*(undefined4 *)(unaff_r6 + 0x44),(int)*(short *)(unaff_r6 + 0x80),unaff_r6);
        }
      }
      iVar6 = (int)(short)((short)iVar6 + 1);
    } while (iVar6 < *(short *)(puVar4 + 0x62));
  }
  bVar5 = true;
  iVar6 = 0;
  if (0 < *(short *)(puVar4 + 0x62)) {
    do {
      if (*(int *)(puVar4[0x36] + *(short *)(puVar4[99] + iVar6 * 2) * 0xfc + 0x30) != 0) {
        bVar5 = false;
        break;
      }
      iVar6 = (int)(short)((short)iVar6 + 1);
    } while (iVar6 < *(short *)(puVar4 + 0x62));
  }
  FUN_03088254(puVar4,1);
  FUN_03088254(puVar4,0);
  if (bVar5) goto LAB_030889dc;
  if (puVar4[0x10] == 1) {
    sVar2 = *(short *)(unaff_r6 + 0x82);
    if (sVar2 == 0x800) {
      unaff_r9 = 0x7fffffff;
LAB_03088994:
      uVar7 = 4;
    }
    else if (sVar2 == 0x200) {
      unaff_r9 = 0x7fffffff;
LAB_03088990:
      uVar7 = 3;
    }
    else {
      if (sVar2 == 0x80) {
        unaff_r9 = 0x7fffffff;
      }
      else {
        unaff_r9 = DAT_030889ec;
        if (sVar2 == 0x400) goto LAB_03088994;
        if (sVar2 == 0x100) goto LAB_03088990;
      }
      uVar7 = 2;
    }
  }
  else {
    if (puVar4[0x10] == 2) {
      unaff_r9 = 0x40000000;
    }
    uVar7 = 0;
  }
  iVar6 = 0;
  if (0 < *(short *)(puVar4 + 0x62)) {
    do {
      iVar3 = puVar4[0x36] + *(short *)(puVar4[99] + iVar6 * 2) * 0xfc;
      if ((*(int *)(iVar3 + 0x30) != 0) || (2 < (int)puVar4[0x10])) {
        FUN_030878ba(*(undefined4 *)(iVar3 + 0x44),unaff_r9,(int)*(short *)(iVar3 + 0x82),uVar7);
      }
      iVar6 = (int)(short)((short)iVar6 + 1);
    } while (iVar6 < *(short *)(puVar4 + 0x62));
  }
LAB_030889dc:
  *(undefined1 *)((int)param_1 + 0x1f) = 8;
  return iVar8;
}


