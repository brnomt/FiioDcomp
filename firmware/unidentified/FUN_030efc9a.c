/**
 * FUN_030efc9a @ 0x030efc9a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030efc9a(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_4114 [16620];
  
  puVar2 = (undefined4 *)(param_1 + 0x28);
  puVar4 = (undefined4 *)(param_1 + 0x4954);
  puVar5 = (undefined4 *)(param_1 + 0x954);
  FUN_030ed0a6(auStack_4114,*puVar2,0xcc);
  iVar3 = 0;
  if (0 < param_2) {
    do {
      puVar6 = auStack_4114 + iVar3 * 4;
      uVar1 = FUN_030efaa4(puVar2,*puVar5,0,puVar6,0x32,0x2a,0x12,10);
      *puVar5 = uVar1;
      uVar1 = FUN_030efaa4(puVar2,*puVar4,1,puVar6,0x22,0x1a,0xe,5);
      iVar3 = iVar3 + 1;
      *puVar4 = uVar1;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar3 < param_2);
  }
  FUN_030ed0a6(*puVar2,auStack_4114 + param_2 * 4,0xcc);
  return;
}


