/**
 * FUN_03014756 @ 0x03014756
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03014756(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  puVar3 = DAT_030147dc;
  uVar1 = *DAT_030147dc;
  uVar2 = DAT_030147dc[1];
  uVar4 = FUN_02ffc718(1);
  uVar5 = FUN_02ffc6f4(2);
  *puVar3 = *DAT_030147e0;
  puVar3[1] = *DAT_030147e4;
  iVar6 = MediaLib_GetTotalFiles_d(0x26);
  if ((iVar6 != 0) || (iVar6 = MediaLib_GetTotalFiles_d(0x2f), iVar6 != 0)) {
    MediaLib_GetTotalFiles(0x33);
    FUN_02ffcaba(1);
  }
  FUN_02ffcaba(0);
  MediaLib_GetTotalFiles_b(0x33);
  FUN_02ffc718(uVar4);
  puVar3[1] = uVar2;
  *puVar3 = uVar1;
  FUN_02ffc6f4(uVar5);
  return;
}


