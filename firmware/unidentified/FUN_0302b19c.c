/**
 * FUN_0302b19c @ 0x0302b19c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0302b19c(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = DAT_0302b54c;
  iVar1 = DAT_0302b528;
  iVar3 = *(int *)(DAT_0302b528 + 0xc);
  uVar4 = *(uint *)(iVar3 + 4);
  if (*(int *)(DAT_0302b54c + 0x44) == 1) {
    uVar5 = *(uint *)(DAT_0302b54c + 0x48);
    if (uVar4 <= param_1) {
      *(uint *)(iVar3 + 4) = uVar5 + 0x5dc;
      goto LAB_0302b1ba;
    }
    uVar4 = uVar4 - param_1;
    if (uVar4 <= uVar5) {
      uVar4 = uVar5 + 0x5dc;
    }
  }
  else if (param_1 < uVar4) {
    uVar4 = uVar4 - param_1;
  }
  else {
    uVar4 = 0;
  }
  *(uint *)(iVar3 + 4) = uVar4;
LAB_0302b1ba:
  if (*(int *)(iVar2 + 0x44) == 1) {
    iVar2 = *(int *)(iVar2 + 0x48) + *(int *)(iVar3 + 4);
  }
  else {
    iVar2 = *(int *)(iVar3 + 4);
  }
  *(int *)(iVar1 + 0x2c) = iVar2;
  return 1;
}


