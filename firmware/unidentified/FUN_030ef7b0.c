/**
 * FUN_030ef7b0 @ 0x030ef7b0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030ef7b0(int param_1)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  uint *puVar4;
  uint *puVar5;
  
  puVar5 = (uint *)(param_1 + 0x8964);
  if (0x800000 < *puVar5) {
    return;
  }
  puVar4 = (uint *)(param_1 + 0x89fc);
  puVar3 = (ushort *)(param_1 + 0x896c);
  do {
    *(int *)puVar3 = *(int *)puVar3 << 8;
    if (*puVar4 < *(uint *)(param_1 + 0x89f8)) {
      iVar1 = FUN_030f07ca(DAT_030efb44);
      *(int *)puVar3 = iVar1 + *(int *)puVar3;
    }
    *puVar4 = *puVar4 + 1;
    *(uint *)(param_1 + 0x8960) = (*puVar3 & 0x1ff) >> 1 | *(uint *)(param_1 + 0x8960) << 8;
    uVar2 = *puVar5;
    *puVar5 = uVar2 * 0x100;
  } while (uVar2 * 0x100 < 0x800001);
  return;
}


