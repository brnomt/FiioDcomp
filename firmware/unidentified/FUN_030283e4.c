/**
 * FUN_030283e4 @ 0x030283e4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030283e4(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint local_528 [257];
  byte local_124 [260];
  
  iVar2 = 0;
  iVar3 = 1;
  do {
    bVar1 = *(byte *)(param_1 * 0x11 + DAT_030285e8 + iVar3);
    for (iVar6 = 1; iVar6 <= (int)(uint)bVar1; iVar6 = iVar6 + 1) {
      local_124[iVar2] = (byte)iVar3;
      iVar2 = iVar2 + 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x11);
  uVar4 = 0;
  local_124[iVar2] = 0;
  uVar7 = (uint)local_124[0];
  iVar3 = 0;
  while (local_124[iVar3] != 0) {
    for (; local_124[iVar3] == uVar7; iVar3 = iVar3 + 1) {
      local_528[iVar3] = uVar4;
      uVar4 = uVar4 + 1;
    }
    uVar4 = uVar4 << 1;
    uVar7 = uVar7 + 1;
  }
  FUN_02ff6d7a(param_2,0,0x20);
  FUN_02ff6d7a(param_2 + 0x500,0,0x40);
  FUN_02ff6d7a(param_2 + 0x400,0,8);
  iVar3 = -1;
  for (iVar6 = 0; iVar6 < iVar2; iVar6 = iVar6 + 1) {
    uVar7 = local_528[iVar6];
    bVar1 = *(byte *)(DAT_030285ec + param_1 * 0x100 + iVar6);
    uVar4 = (uint)local_124[iVar6];
    if (uVar4 < 9) {
      iVar5 = uVar7 << (8 - uVar4 & 0xff);
      for (iVar8 = 1 << (8 - uVar4 & 0xff); 0 < iVar8; iVar8 = iVar8 + -1) {
        *(uint *)(param_2 + iVar5 * 4) = uVar4;
        iVar9 = param_2 + iVar5;
        iVar5 = iVar5 + 1;
        *(byte *)(iVar9 + 0x400) = bVar1;
      }
    }
    else {
      uVar10 = uVar7 >> (uVar4 - 8 & 0xff) & 0xff;
      iVar5 = *(int *)(param_2 + uVar10 * 4);
      iVar8 = iVar3;
      if (iVar5 == 0) {
        *(int *)(param_2 + uVar10 * 4) = iVar3;
        iVar8 = iVar3 + -2;
        iVar5 = iVar3;
      }
      iVar9 = uVar7 << (0x18 - uVar4 & 0xff);
      iVar3 = iVar8;
      for (; 9 < (int)uVar4; uVar4 = uVar4 - 1) {
        if (-1 < iVar9 << 0x10) {
          iVar5 = iVar5 + -1;
        }
        iVar11 = param_2 + iVar5 * -4;
        iVar5 = *(int *)(iVar11 + 0x4fc);
        iVar8 = iVar3;
        if (iVar5 == 0) {
          *(int *)(iVar11 + 0x4fc) = iVar3;
          iVar8 = iVar3 + -2;
          iVar5 = iVar3;
        }
        iVar9 = iVar9 << 1;
        iVar3 = iVar8;
      }
      if (-1 < iVar9 << 0x10) {
        iVar5 = iVar5 + -1;
      }
      *(uint *)(param_2 + iVar5 * -4 + 0x4fc) = (uint)bVar1;
    }
  }
  return;
}


