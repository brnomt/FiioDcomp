/**
 * FUN_0302747a @ 0x0302747a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0302747a(void)

{
  short sVar1;
  int iVar2;
  int in_r3;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int in_stack_00000000;
  
  iVar2 = DAT_03027874;
  sVar1 = *(short *)(DAT_03027874 + 4);
  uVar5 = (uint)*(short *)(DAT_03027874 + 0xc);
  iVar4 = in_r3;
  for (uVar3 = 0; (int)uVar3 < *(int *)(iVar2 + 0x40); uVar3 = uVar3 + 1 & 0xffff) {
    FUN_02ff89c2(iVar4,in_r3,uVar5);
    in_r3 = in_r3 + sVar1;
    iVar4 = iVar4 + uVar5;
  }
  iVar4 = in_stack_00000000;
  for (uVar3 = 0; (int)uVar3 < *(int *)(iVar2 + 0x40); uVar3 = uVar3 + 2 & 0xffff) {
    FUN_02ff89c2(in_stack_00000000,iVar4,uVar5);
    iVar4 = iVar4 + ((int)sVar1 & 0xfffffffeU);
    in_stack_00000000 = in_stack_00000000 + (uVar5 & 0xfffffffe);
  }
  return;
}


