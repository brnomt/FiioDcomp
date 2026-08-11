/**
 * FUN_030a4dfc @ 0x030a4dfc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030a4dfc(int param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  
  piVar1 = DAT_030a4e5c;
  *DAT_030a4e5c = DAT_030a4e58;
  iVar8 = param_1 + 8;
  uVar6 = *(uint *)(param_1 + 0x8214) + (uint)*(ushort *)(param_1 + 0x8232);
  uVar3 = *(uint *)(param_1 + 0x8218);
  bVar10 = uVar3 <= uVar6;
  bVar9 = uVar6 == uVar3;
  if (bVar10 && !bVar9) {
    bVar10 = uVar3 <= *(uint *)(param_1 + 0x8224);
    bVar9 = *(uint *)(param_1 + 0x8224) == uVar3;
  }
  if (bVar10 && !bVar9) {
    uVar6 = *(uint *)(param_1 + 0x8214) & 0xfffffffc;
    FUN_0309f692(iVar8,uVar6 + param_1 + 8,uVar3 - uVar6);
    iVar4 = *(int *)(param_1 + 0x8218) - (*(uint *)(param_1 + 0x8214) & 0xfffffffc);
    *(int *)(param_1 + 0x8218) = iVar4;
    uVar6 = 0x1200U - iVar4 & 0xfffffe00;
    uVar3 = (*(code *)*DAT_030a4f9c)(iVar4 + iVar8,uVar6,*DAT_030a4f98);
    if (uVar6 != uVar3) {
      *(undefined4 *)(param_1 + 0x8224) = 0;
      return 0;
    }
    *(uint *)(param_1 + 0x8224) = *(int *)(param_1 + 0x8224) - uVar3;
    *(uint *)(param_1 + 0x8218) = uVar3 + *(int *)(param_1 + 0x8218);
    *(uint *)(param_1 + 0x8214) = *(byte *)(param_1 + 0x8214) & 3;
  }
  piVar2 = DAT_030a4fa4;
  iVar4 = DAT_030a4fa0;
  uVar6 = *(int *)(param_1 + 0x8218) - *(int *)(param_1 + 0x8214);
  uVar3 = (uint)*(ushort *)(param_1 + 0x8232);
  if (uVar6 < *(ushort *)(param_1 + 0x8232)) {
    uVar3 = uVar6;
  }
  if (uVar3 != 0) {
    if (*(char *)(param_1 + 0x8230) == '\x01') {
      iVar5 = (int)(uVar3 * 8 + -0x20) / (int)(uint)*(ushort *)(param_1 + 6);
    }
    else {
      iVar5 = (int)(uVar3 * 4 + -0x20) / (int)(uint)*(ushort *)(param_1 + 6);
    }
    if (iVar5 != 0) {
      FUN_030a4aba(*(int *)(param_1 + 0x8214) + iVar8,uVar3 << 2,
                   *(int *)(DAT_030a4fa0 + *(int *)(param_1 + 0x8210) * 4) + *DAT_030a4fa4 * 2,
                   *piVar1);
      *(uint *)(param_1 + 0x8214) = *(int *)(param_1 + 0x8214) + (uVar3 & 0xffff);
      iVar7 = *piVar1;
      iVar4 = *(int *)(iVar4 + *(int *)(param_1 + 0x8210) * 4) + *piVar2 * 2;
      iVar8 = iVar5;
      while (iVar8 = iVar8 + -1, 0 < iVar8) {
        *(undefined2 *)(iVar4 + iVar8 * 4) = *(undefined2 *)(iVar4 + iVar8 * 2);
      }
      iVar8 = 0;
      if (*(char *)(param_1 + 0x8230) == '\x01') {
        if (0 < iVar5) {
          do {
            *(undefined2 *)(iVar4 + iVar8 * 4 + 2) = *(undefined2 *)(iVar4 + iVar8 * 4);
            iVar8 = iVar8 + 1;
          } while (iVar8 < iVar5);
        }
      }
      else if (0 < iVar5) {
        do {
          *(undefined2 *)(iVar4 + iVar8 * 4 + 2) = *(undefined2 *)(iVar7 + iVar8 * 2);
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar5);
      }
      return iVar5;
    }
    return 0;
  }
  return 0;
}


