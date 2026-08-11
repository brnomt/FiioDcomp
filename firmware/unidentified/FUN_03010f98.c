/**
 * FUN_03010f98 @ 0x03010f98
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03010f98(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  puVar3 = DAT_03011014;
  uVar1 = *DAT_03011014;
  uVar2 = DAT_03011014[1];
  uVar4 = FUN_02ffb34c(1);
  uVar5 = FUN_02ffb328(2);
  *puVar3 = 0xffff;
  puVar3[1] = *DAT_03011018;
  iVar6 = FUN_02fffbe4(0x21);
  if (iVar6 == 1) {
    FUN_02ffbbfa(*DAT_0301101c + 0x5f);
  }
  FUN_02ffb34c(uVar4);
  puVar3[1] = uVar2;
  *puVar3 = uVar1;
  FUN_02ffb328(uVar5);
  return;
}


