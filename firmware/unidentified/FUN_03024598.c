/**
 * FUN_03024598 @ 0x03024598
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03024598(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  puVar3 = DAT_030245ec;
  puVar2 = SUB_030245e8;
  piVar1 = DAT_030245e4;
  iVar5 = 0;
  iVar4 = 0;
  do {
    FUN_03007810(*puVar3,*piVar1 + iVar4,*puVar2,1,0x11,param_1);
    iVar4 = iVar4 + 1;
    param_1 = param_1 + 0x18;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0xc);
  return;
}


