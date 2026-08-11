/**
 * FUN_03003094 @ 0x03003094
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03003094(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  puVar3 = DAT_03003114;
  uVar1 = *DAT_03003114;
  uVar2 = DAT_03003114[1];
  uVar4 = FUN_02feb810(1);
  uVar5 = FUN_02feb7ec(2);
  *puVar3 = *DAT_03003118;
  puVar3[1] = *DAT_0300311c;
  iVar6 = FUN_02ff00ec(0x26);
  if ((iVar6 != 0) || (iVar6 = FUN_02ff00ec(0x2f), iVar6 != 0)) {
    FUN_02ff008c(0x33);
    FUN_02febbb2(1);
  }
  FUN_02febbb2(0);
  FUN_02feb810(uVar4);
  puVar3[1] = uVar2;
  *puVar3 = uVar1;
  FUN_02feb7ec(uVar5);
  return;
}


