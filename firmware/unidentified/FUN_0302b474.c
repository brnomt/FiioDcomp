/**
 * FUN_0302b474 @ 0x0302b474
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0302b474(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  piVar2 = DAT_0302b560;
  if (*DAT_0302b560 != 1) {
    return;
  }
  iVar3 = FUN_0300c6d0(0x107);
  iVar1 = DAT_0302b528;
  if (iVar3 == 0) {
    FUN_0302c96e(*(int *)(DAT_0302b528 + 0xc) + 4);
  }
  else {
    *(int *)(*(int *)(DAT_0302b528 + 0xc) + 4) = piVar2[2];
  }
  iVar3 = FUN_0300c6d0(0x106);
  if (iVar3 != 0) {
    piVar2[2] = *(int *)(*(int *)(iVar1 + 0xc) + 4);
  }
  *piVar2 = 2;
  if (*DAT_0302b584 == 0) {
    FUN_0302a69e();
  }
  *(undefined4 *)(iVar1 + 0x34) = *DAT_0302b588;
  uVar4 = piVar2[1] + 1000;
  if ((uint)piVar2[2] < uVar4) {
    piVar2[2] = uVar4;
  }
  iVar3 = DAT_0302b54c;
  if ((uint)piVar2[2] < uVar4) goto LAB_0302b526;
  uVar4 = piVar2[2] - piVar2[1];
  iVar5 = *(int *)(iVar1 + 0xc);
  uVar6 = *(uint *)(iVar5 + 4);
  if (*(int *)(DAT_0302b54c + 0x44) == 1) {
    if (uVar4 < uVar6) {
      uVar6 = uVar6 - uVar4;
      if (uVar6 <= *(uint *)(DAT_0302b54c + 0x48)) {
        uVar6 = *(uint *)(DAT_0302b54c + 0x48) + 0x5dc;
      }
      goto LAB_0302b4ec;
    }
    *(int *)(iVar5 + 4) = *(int *)(DAT_0302b54c + 0x48) + 0x5dc;
  }
  else {
    if (uVar4 < uVar6) {
      uVar6 = uVar6 - uVar4;
    }
    else {
      uVar6 = 0;
    }
LAB_0302b4ec:
    *(uint *)(iVar5 + 4) = uVar6;
  }
  if (*(int *)(iVar3 + 0x44) == 1) {
    iVar3 = *(int *)(iVar3 + 0x48) + *(int *)(*(int *)(iVar1 + 0xc) + 4);
  }
  else {
    iVar3 = *(int *)(*(int *)(iVar1 + 0xc) + 4);
  }
  *(int *)(iVar1 + 0x2c) = iVar3;
  FUN_0302c950(*(undefined4 *)(*(int *)(iVar1 + 0xc) + 4),0);
  FUN_0302c932();
LAB_0302b526:
  FUN_0302afc0();
  return;
}


