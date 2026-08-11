/**
 * FUN_030a1596 @ 0x030a1596
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030a1596(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  uVar1 = *(uint *)(param_1 + 4);
  if ((int)uVar1 < 3) {
    uVar2 = 0;
  }
  else {
    uVar2 = uVar1 & 1;
    if (uVar2 != 0) {
      uVar9 = *(uint *)(param_1 + 0x3744);
      *(uint *)(param_1 + 0x3744) =
           ((int)(*(uint *)(param_1 + 0x1228) << 1) >> 0x10) * 0x666 +
           ((*(uint *)(param_1 + 0x1228) & 0x7fff) * 0x666 >> 0xf) +
           ((int)(uVar9 << 1) >> 0x10) * 0x6666 + ((uVar9 & 0x7fff) * 0x6666 >> 0xf) +
           ((int)(*(uint *)(param_1 + 0x1220) << 1) >> 0x10) * 0x666 +
           ((*(uint *)(param_1 + 0x1220) & 0x7fff) * 0x666 >> 0xf) +
           ((int)(*(uint *)(param_1 + 0x1224) << 1) >> 0x10) * 0xccd +
           ((*(uint *)(param_1 + 0x1224) & 0x7fff) * 0xccd >> 0xf);
    }
  }
  for (iVar3 = uVar2 + 1; iVar3 < (int)(uVar1 - 1); iVar3 = iVar3 + 2) {
    iVar4 = param_1 + iVar3 * 4;
    uVar2 = *(uint *)(iVar4 + 0x3740);
    iVar6 = (int)(*(uint *)(iVar4 + 0x1220) << 1) >> 0x10;
    uVar9 = *(uint *)(iVar4 + 0x1220) & 0x7fff;
    iVar8 = (int)(*(uint *)(iVar4 + 0x1224) << 1) >> 0x10;
    uVar7 = *(uint *)(iVar4 + 0x1224) & 0x7fff;
    *(uint *)(iVar4 + 0x3740) =
         ((int)(uVar2 << 1) >> 0x10) * 0x6666 + ((uVar2 & 0x7fff) * 0x6666 >> 0xf) +
         ((int)(*(uint *)(iVar4 + 0x121c) << 1) >> 0x10) * 0x666 +
         ((*(uint *)(iVar4 + 0x121c) & 0x7fff) * 0x666 >> 0xf) +
         iVar6 * 0xccd + (uVar9 * 0xccd >> 0xf) + iVar8 * 0x666 + (uVar7 * 0x666 >> 0xf);
    uVar2 = *(uint *)(iVar4 + 0x3744);
    *(uint *)(iVar4 + 0x3744) =
         ((int)(*(uint *)(iVar4 + 0x1228) << 1) >> 0x10) * 0x666 +
         ((*(uint *)(iVar4 + 0x1228) & 0x7fff) * 0x666 >> 0xf) +
         iVar8 * 0xccd + (uVar7 * 0xccd >> 0xf) +
         ((int)(uVar2 << 1) >> 0x10) * 0x6666 + ((uVar2 & 0x7fff) * 0x6666 >> 0xf) +
         iVar6 * 0x666 + (uVar9 * 0x666 >> 0xf);
  }
  uVar2 = *(uint *)(param_1 + 0x3740);
  *(uint *)(param_1 + 0x3740) =
       ((int)(*(uint *)(param_1 + 0x1220) << 1) >> 0x10) * 0x199a +
       ((*(uint *)(param_1 + 0x1220) & 0x7fff) * 0x199a >> 0xf) +
       ((int)(uVar2 << 1) >> 0x10) * 0x6666 + ((uVar2 & 0x7fff) * 0x6666 >> 0xf);
  iVar3 = param_1 + uVar1 * 4;
  puVar5 = (uint *)(iVar3 + 0x373c);
  uVar9 = *puVar5;
  uVar2 = *(uint *)(iVar3 + 0x121c);
  *puVar5 = ((int)(uVar2 << 1) >> 0x10) * 0x199a + ((uVar2 & 0x7fff) * 0x199a >> 0xf) +
            ((int)(uVar9 << 1) >> 0x10) * 0x6666 + ((uVar9 & 0x7fff) * 0x6666 >> 0xf);
  if (*(int *)(param_1 + 0x7250) == 1) {
    if (0 < (int)uVar1) {
      iVar3 = 0;
      uVar2 = uVar1;
      do {
        iVar4 = param_1 + iVar3 * 4;
        iVar3 = iVar3 + 1;
        *(undefined4 *)(iVar4 + 0x4940) = 0;
        uVar2 = uVar2 - 1;
        *(undefined4 *)(iVar4 + 0x4040) = 0;
      } while (uVar2 != 0);
      goto LAB_030a17ee;
    }
  }
  else {
LAB_030a17ee:
    iVar3 = *(int *)(param_1 + 0x7250);
    if (99 < iVar3) {
      if (iVar3 < 1000) {
        iVar3 = 0x32;
      }
      else if (iVar3 < 10000) {
        iVar3 = 0x96;
      }
      else {
        iVar3 = 300;
      }
      goto LAB_030a17f8;
    }
  }
  iVar3 = 0xf;
LAB_030a17f8:
  if (iVar3 < *(int *)(param_1 + 0x7254)) {
    *(undefined4 *)(param_1 + 0x7254) = 0;
    if ((int)uVar1 < 1) {
      return;
    }
    iVar3 = 0;
    uVar2 = uVar1;
    do {
      iVar8 = param_1 + iVar3 * 4;
      iVar4 = *(int *)(iVar8 + 0x4940);
      iVar6 = *(int *)(iVar8 + 0x3740);
      if (iVar6 < iVar4) {
        iVar4 = iVar6;
      }
      iVar3 = iVar3 + 1;
      *(int *)(iVar8 + 0x4040) = iVar4;
      *(int *)(iVar8 + 0x4940) = iVar6;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  else {
    if ((int)uVar1 < 1) {
      return;
    }
    iVar3 = 0;
    uVar2 = uVar1;
    do {
      iVar8 = param_1 + iVar3 * 4;
      iVar4 = *(int *)(iVar8 + 0x3740);
      iVar6 = *(int *)(iVar8 + 0x4040);
      if (iVar4 < *(int *)(iVar8 + 0x4040)) {
        iVar6 = iVar4;
      }
      *(int *)(iVar8 + 0x4040) = iVar6;
      iVar6 = *(int *)(iVar8 + 0x4940);
      if (iVar6 <= iVar4) {
        iVar4 = iVar6;
      }
      iVar3 = iVar3 + 1;
      *(int *)(iVar8 + 0x4940) = iVar4;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  if ((int)uVar1 < 1) {
    return;
  }
  iVar3 = 0;
  do {
    iVar4 = param_1 + iVar3 * 4;
    if (*(int *)(iVar4 + 0x4040) <
        (int)(((int)(*(uint *)(iVar4 + 0x3740) << 1) >> 0x10) * 0x3333 +
             ((*(uint *)(iVar4 + 0x3740) & 0x7fff) * 0x3333 >> 0xf))) {
      *(undefined4 *)(iVar4 + 0x5240) = 1;
    }
    else {
      *(undefined4 *)(iVar4 + 0x5240) = 0;
    }
    iVar3 = iVar3 + 1;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return;
}


