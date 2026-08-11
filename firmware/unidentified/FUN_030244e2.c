/**
 * FUN_030244e2 @ 0x030244e2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030244e2(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = DAT_030245dc;
  if (*(uint *)(DAT_030245dc + 0x18) <=
      (uint)(*(int *)(DAT_030245dc + 0x2c) - *(int *)(DAT_030245d8 + 0xc))) {
    return 0;
  }
  iVar4 = FUN_03027dfa(DAT_030245dc);
  puVar3 = DAT_030245e0;
  uVar1 = *DAT_030245e0;
  *DAT_030245e0 = 0;
  iVar5 = *DAT_030245e4 + *(int *)(iVar2 + 0x2c);
  if (iVar4 == 0) {
    FUN_03007810(*DAT_030245ec,iVar5,*SUB_030245e8,1);
    *puVar3 = uVar1;
    return 0;
  }
  FUN_03007810(*DAT_030245ec,iVar5,*SUB_030245e8 + -1,1);
  *(int *)(iVar2 + 0x2c) = *(int *)(iVar2 + 0x2c) + 1;
  *puVar3 = uVar1;
  return 1;
}


