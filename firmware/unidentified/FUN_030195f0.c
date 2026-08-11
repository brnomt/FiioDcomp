/**
 * FUN_030195f0 @ 0x030195f0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030195f0(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  puVar3 = DAT_03019670;
  uVar1 = *DAT_03019670;
  uVar2 = DAT_03019670[1];
  uVar4 = FUN_02ffef2c(1);
  uVar5 = FUN_02ffef08(2);
  *puVar3 = *DAT_03019678;
  puVar3[1] = *DAT_03019674;
  iVar6 = ui_refresh_and_redraw(0x26);
  if ((iVar6 != 0) || (iVar6 = ui_refresh_and_redraw(0x2f), iVar6 != 0)) {
    func_0x030037a8(0x33);
  }
  FUN_02ffef2c(uVar4);
  puVar3[1] = uVar2;
  *puVar3 = uVar1;
  FUN_02ffef08(uVar5);
  return;
}


