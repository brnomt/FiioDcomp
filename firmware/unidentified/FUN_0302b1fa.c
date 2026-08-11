/**
 * FUN_0302b1fa @ 0x0302b1fa
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0302b1fa(uint param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = DAT_0302b54c;
  iVar1 = DAT_0302b528;
  puVar3 = *(uint **)(DAT_0302b528 + 0xc);
  if (*(int *)(DAT_0302b54c + 0x44) == 1) {
    uVar4 = *(uint *)(DAT_0302b54c + 0x4c);
    if ((uVar4 <= param_1) || (uVar5 = puVar3[1], uVar4 - param_1 <= uVar5)) goto LAB_0302b22e;
  }
  else {
    uVar4 = *puVar3;
    if ((uVar4 <= param_1) || (uVar5 = puVar3[1], uVar4 - param_1 <= uVar5)) goto LAB_0302b22e;
  }
  uVar4 = uVar5 + param_1;
LAB_0302b22e:
  puVar3[1] = uVar4;
  if (*(int *)(iVar2 + 0x44) == 1) {
    *(uint *)(iVar1 + 0x2c) = *(int *)(iVar2 + 0x48) + uVar4;
  }
  else {
    *(uint *)(iVar1 + 0x2c) = uVar4;
  }
  return 1;
}


