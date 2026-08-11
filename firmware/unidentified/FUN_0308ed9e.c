/**
 * FUN_0308ed9e @ 0x0308ed9e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_0308ed9e(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  iVar8 = *(int *)(param_1 + 0x40);
  if (2 < iVar8) {
    *(undefined4 *)(param_1 + 0x70) = 1;
  }
  *(byte *)(param_1 + 0x60) =
       (char)*(int *)(param_1 + 0x58) - 1U | *(char *)(param_1 + 0x6a) * '\x04' - 4U;
  *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x58) << 3;
  uVar7 = (uint)*(ushort *)(param_1 + 0x26);
  uVar1 = FUN_03082bfa(uVar7 * *(int *)(param_1 + 0x50));
  iVar9 = *(int *)(param_1 + 0x54);
  uVar2 = FUN_03082bfa(iVar9);
  uVar2 = FUN_030829f2(uVar2,3);
  uVar1 = FUN_03082972(uVar2,uVar1);
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  if (uVar7 == 2) {
    uVar1 = FUN_03082906(uVar1,DAT_0308efb0);
    *(undefined4 *)(param_1 + 0x34) = uVar1;
  }
  else if (2 < uVar7) {
    uVar1 = FUN_03082906(uVar1,DAT_0308efa0);
    *(undefined4 *)(param_1 + 0x34) = uVar1;
  }
  iVar4 = *(int *)(param_1 + 0x9c) * 2;
  *(int *)(param_1 + 0x98) = iVar4;
  *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0x9c) / 2;
  uVar3 = *(uint *)(param_1 + 0x44);
  *(uint *)(param_1 + 0xb4) = uVar3 & 1;
  *(uint *)(param_1 + 0x78) = (uVar3 & 0x3f) >> 5;
  iVar5 = -((int)(uVar3 << 0x1e) >> 0x1f);
  *(int *)(param_1 + 0x70) = iVar5;
  uVar6 = (uint)(iVar5 != 0 && (uVar3 & 4) != 0);
  *(uint *)(param_1 + 0x74) = uVar6;
  if (uVar6 == 0) {
    iVar9 = 1;
    *(undefined4 *)(param_1 + 0x80) = 1;
  }
  else {
    uVar3 = (uVar3 & 0x1f) >> 3;
    *(uint *)(param_1 + 0x80) = uVar3;
    if (iVar9 / (int)uVar7 < 4000) {
      iVar9 = 2 << uVar3;
    }
    else {
      iVar9 = 8 << uVar3;
    }
    *(int *)(param_1 + 0x80) = iVar9;
  }
  iVar4 = (int)(iVar4 + ((uint)(iVar4 >> 0x1f) >> 0x18)) >> 8;
  if (iVar4 < iVar9) {
    iVar9 = iVar4;
  }
  *(int *)(param_1 + 0x80) = iVar9;
  if (iVar8 == 1) {
    *(undefined4 *)(param_1 + 0x90) = 1;
  }
  else {
    iVar8 = wma_floor_log2();
    *(int *)(param_1 + 0x90) = iVar8 + 1;
  }
  iVar8 = (*(int *)(param_1 + 0x9c) << 1) / *(int *)(param_1 + 0x80);
  *(int *)(param_1 + 0x84) = iVar8;
  iVar8 = iVar8 / 2;
  *(int *)(param_1 + 0x88) = iVar8;
  *(int *)(param_1 + 0x8c) = iVar8 / 2;
  uVar1 = DAT_0308ef9c;
  if (*(int *)(param_1 + 0xb4) != 0) {
    uVar1 = DAT_0308efa4;
  }
  *(undefined4 *)(param_1 + 0xc0) = uVar1;
  iVar8 = FUN_030905f8(param_1);
  if (iVar8 < 0) {
    return iVar8;
  }
  uVar1 = wma_floor_log2(*(undefined4 *)(param_1 + 0x9c));
  *(undefined4 *)(param_1 + 0x94) = uVar1;
  iVar9 = *(int *)(param_1 + 0x40);
  if (iVar9 == 1) {
    *(undefined4 *)(param_1 + 0xac) = 3;
  }
  else {
    *(undefined4 *)(param_1 + 0xac) = 0;
    if (2 < iVar9) {
      iVar4 = *(int *)(param_1 + 0x9c);
      goto LAB_0308ef12;
    }
  }
  iVar4 = (int)((ulonglong)((longlong)DAT_0308efa8 * (longlong)(*(int *)(param_1 + 0x9c) * 9)) >>
               0x20);
  iVar4 = *(int *)(param_1 + 0x9c) - ((iVar4 >> 5) - (iVar4 >> 0x1f));
LAB_0308ef12:
  *(int *)(param_1 + 0xb0) = iVar4;
  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0xb0);
  if (iVar9 < 3) {
    *(undefined4 *)(param_1 + 0xbc) = 3;
    if (*(int *)(param_1 + 0x34) < DAT_0308efac) {
      if (31999 < *(int *)(param_1 + 0x50)) {
        *(undefined4 *)(param_1 + 0xbc) = 1;
      }
    }
    else if ((*(int *)(param_1 + 0x34) < DAT_0308efb4) && (31999 < *(int *)(param_1 + 0x50))) {
      *(undefined4 *)(param_1 + 0xbc) = 2;
    }
  }
  *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(param_1 + 0x154) = *(undefined4 *)(param_1 + 0x9c);
  *(undefined4 *)(param_1 + 0x158) = *(undefined4 *)(param_1 + 0xb0);
  if (iVar9 < 3) {
    uVar1 = FUN_03082bfa(*(undefined4 *)(param_1 + 0x9c));
    uVar1 = FUN_03082906(uVar1,*(undefined4 *)(param_1 + 0x30));
    uVar7 = FUN_030829f2(uVar1,0xfffffffd);
    if (uVar7 < 0x80800000) {
      FUN_03082856(uVar7,0x3f000000);
    }
    else {
      FUN_030828fa();
    }
    FUN_03082c38();
    iVar9 = wma_floor_log2();
    *(int *)(param_1 + 0xc) = iVar9 + 2;
  }
  FUN_030908e0(param_1);
  return iVar8;
}


