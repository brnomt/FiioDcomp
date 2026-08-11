/**
 * FUN_030a1116 @ 0x030a1116
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Removing unreachable block (ram,0x030a11b4) */
/* WARNING: Removing unreachable block (ram,0x030a11b8) */
/* WARNING: Removing unreachable block (ram,0x030a11c4) */

uint * FUN_030a1116(uint param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  puVar2 = DAT_030a1518;
  *DAT_030a1518 = param_1;
  puVar2[1] = param_1;
  puVar2[3] = 0xffffffc4;
  puVar2[4] = 0xffffffd8;
  puVar2[5] = 0xfffffff1;
  *(undefined2 *)(puVar2 + 6) = 0x7333;
  *(undefined2 *)((int)puVar2 + 0x1a) = 0x4ccd;
  uVar3 = FUN_030a2bfa(0x18,param_2,param_1,1);
  puVar2[2] = uVar3;
  FUN_030a0c6e(puVar2 + 0x6e0,param_1 << 1);
  if (0 < (int)((puVar2[1] - param_1) * 2)) {
    iVar5 = 0;
    iVar4 = 0;
    if (0 < (int)((puVar2[1] - param_1) * 2)) {
      do {
        iVar6 = iVar5 + 1;
        *(undefined2 *)((int)puVar2 + (iVar5 + param_1 * 2) * 2 + 0x1b80) = 0x7fff;
        iVar5 = iVar5 + 2;
        *(undefined2 *)((int)puVar2 + (iVar6 + param_1 * 2) * 2 + 0x1b80) = 0x7fff;
        iVar4 = iVar4 + 2;
      } while (iVar4 < (int)((puVar2[1] - param_1) * 2));
    }
  }
  if (0 < (int)(param_1 + 0x18)) {
    iVar5 = param_1 + 0x18;
    iVar4 = 0;
    do {
      puVar2[iVar4 + 0x920] = 0x80;
      puVar2[iVar4 + 0xb78] = 1;
      iVar5 = iVar5 + -1;
      iVar4 = iVar4 + 1;
    } while (iVar5 != 0);
  }
  if (0 < (int)param_1) {
    uVar3 = param_1 & 1;
    if (uVar3 != 0) {
      puVar2[0x1490] = 1;
    }
    uVar1 = (uint)(uVar3 != 0);
    for (; (int)uVar3 < (int)param_1; uVar3 = uVar3 + 2) {
      puVar2[uVar1 + 0x1490] = 1;
      puVar2[uVar1 + 0x1491] = 1;
      uVar1 = uVar1 + 2;
    }
  }
  if (0 < (int)param_1) {
    iVar4 = 0;
    do {
      *(undefined2 *)((int)puVar2 + iVar4 * 2 + 0x6950) = 0;
      *(undefined2 *)((int)puVar2 + iVar4 * 2 + 0x6dd0) = 0;
      param_1 = param_1 - 1;
      iVar4 = iVar4 + 1;
    } while (param_1 != 0);
  }
  puVar2[0x1c94] = 0;
  puVar2[0x1c95] = 0;
  puVar2[0x1c96] = param_3;
  return puVar2;
}


