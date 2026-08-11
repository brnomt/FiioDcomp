/**
 * FUN_03086780 @ 0x03086780
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_03086780(int *param_1)

{
  ushort uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int extraout_r2;
  int iVar6;
  bool bVar7;
  bool bVar8;
  undefined8 uVar9;
  
  iVar6 = *param_1;
  if (*(char *)((int)param_1 + 0x1e) == '\x01') goto LAB_0308685e;
  *(undefined1 *)((int)param_1 + 0x1e) = 0;
  *(undefined2 *)(param_1 + 4) = 1;
  if ((*(int *)(iVar6 + 0x70) == 0) && (*(int *)(iVar6 + 0x40) < 3)) {
    param_1[3] = 0;
    if (*(int *)(iVar6 + 8) < 0) {
      *(undefined4 *)(iVar6 + 8) = 0;
      param_1[3] = 1;
    }
    if (param_1[0x24] != *(int *)(iVar6 + 8)) {
      FUN_03088416(param_1 + 0x21);
    }
    if (param_1[0x24] == *(int *)(iVar6 + 8)) {
      FUN_030845a4(param_1 + 0x21);
      return DAT_03086bdc;
    }
    *(int *)(iVar6 + 8) = param_1[0x24];
  }
  else {
    while (iVar3 = param_1[0x24], iVar3 == 0) {
      if (param_1[0x25] == 0) {
        FUN_030845a4();
        uVar5 = FUN_0308458c(param_1,0);
        iVar3 = FUN_030847b2(param_1 + 0x21,3,uVar5);
        if (iVar3 < 0) {
          return iVar3;
        }
      }
      else {
        param_1[0x24] = param_1[0x25];
        param_1[0x25] = 0;
      }
    }
    *(ushort *)(param_1 + 4) = (ushort)((uint)(iVar3 << 4) >> 0x1c);
    uVar4 = (uint)(iVar3 << 8) >> (0x1dU - *(int *)(iVar6 + 0xc) & 0xff);
    param_1[0xb] = uVar4;
    param_1[0xc] = uVar4;
    if (uVar4 == 0) {
      FUN_03088416(param_1 + 0x21);
    }
    param_1[0x24] = 0;
  }
  if (param_1[0xe] == 1) {
    if ((short)param_1[0xf] == 1) {
      uVar4 = param_1[0x3c];
      lVar2 = (ulonglong)(uint)param_1[0x10] * (ulonglong)uVar4;
      uVar9 = FUN_03082732((int)lVar2,
                           param_1[0x10] * ((int)uVar4 >> 0x1f) +
                           param_1[0x11] * uVar4 + (int)((ulonglong)lVar2 >> 0x20),DAT_03086be0,0);
      param_1[0xe] = 0;
      *(undefined8 *)(param_1 + 0x14) = uVar9;
LAB_03086850:
      *(undefined2 *)(param_1 + 0xf) = 0;
    }
    else {
      if ((short)param_1[0xf] != 2) {
        param_1[0xe] = 0;
        goto LAB_03086850;
      }
      uVar4 = param_1[0x3c];
      lVar2 = (ulonglong)(uint)param_1[0x10] * (ulonglong)uVar4;
      uVar9 = FUN_03082732((int)lVar2,
                           param_1[0x10] * ((int)uVar4 >> 0x1f) +
                           param_1[0x11] * uVar4 + (int)((ulonglong)lVar2 >> 0x20),DAT_03086be0,0);
      *(undefined8 *)(param_1 + 0x14) = uVar9;
      param_1[0x10] = param_1[0x12];
      param_1[0x11] = param_1[0x13];
      *(undefined2 *)(param_1 + 0xf) = 1;
    }
    param_1[0x16] = 1;
  }
  if (param_1[3] == 0) {
    return 0;
  }
LAB_0308685e:
  *(undefined1 *)((int)param_1 + 0x1e) = 1;
  iVar3 = param_1[0xb];
  while (0x18 < iVar3) {
    iVar3 = FUN_030848dc(param_1 + 0x21,0x18);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = param_1[0xb] + -0x18;
    param_1[0xb] = iVar3;
  }
  iVar3 = FUN_030848dc(param_1 + 0x21,iVar3);
  if (-1 < iVar3) {
    uVar1 = *(ushort *)(iVar6 + 0x26);
    bVar7 = uVar1 != 0;
    uVar4 = 0;
    if (bVar7) {
      uVar4 = uVar1 & 1;
    }
    bVar8 = (uVar1 & 1) != 0;
    iVar3 = extraout_r2;
    if (bVar7 && bVar8) {
      iVar3 = *(int *)(iVar6 + 0xd8);
    }
    if (bVar7 && bVar8) {
      *(undefined2 *)(iVar3 + 0x52) = 0x7fff;
    }
    if (uVar4 < *(ushort *)(iVar6 + 0x26)) {
      do {
        iVar3 = uVar4 * 0xfc;
        *(undefined2 *)(*(int *)(iVar6 + 0xd8) + uVar4 * 0xfc + 0x52) = 0x7fff;
        uVar4 = (uint)(short)((short)uVar4 + 2);
        *(undefined2 *)(iVar3 + *(int *)(iVar6 + 0xd8) + 0x14e) = 0x7fff;
      } while ((int)uVar4 < (int)(uint)*(ushort *)(iVar6 + 0x26));
    }
    *(undefined1 *)(iVar6 + 0x48) = 3;
    *(undefined1 *)((int)param_1 + 0x1e) = 0;
    return 0;
  }
  return iVar3;
}


