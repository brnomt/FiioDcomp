/**
 * FUN_030254a2 @ 0x030254a2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Removing unreachable block (ram,0x030255e2) */
/* WARNING: Removing unreachable block (ram,0x030255ec) */
/* WARNING: Removing unreachable block (ram,0x03025638) */
/* WARNING: Removing unreachable block (ram,0x030255da) */

void FUN_030254a2(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  
  iVar2 = DAT_03025534;
  FUN_02ffcece(0,0,(int)*(char *)(DAT_03025534 + 8));
  iVar1 = DAT_0302552c;
  *(undefined4 *)(iVar2 + 0xc) = 0xffffffff;
  *(undefined4 *)(iVar2 + 0x10) = 0xffffffff;
  *(undefined4 *)(iVar1 + 10) = 0;
  *(undefined4 *)(iVar1 + 0xe) = 0;
  *(undefined2 *)(iVar1 + 0x12) = 0;
  iVar3 = DAT_03025944;
  *(undefined1 *)(iVar1 + 0x14) = 0;
  local_38 = *(undefined4 *)(iVar3 + 8);
  uStack_34 = *(undefined4 *)(iVar3 + 0xc);
  uStack_30 = *(undefined4 *)(iVar3 + 0x10);
  uStack_2c = *(undefined4 *)(iVar3 + 0x14);
  local_28 = *(undefined4 *)(iVar3 + 0x18);
  local_50 = 0;
  local_3c = 0;
  local_58 = 0;
  local_54 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  uVar4 = FUN_02ffc9d6(&local_58,0x10,(int)*(char *)(iVar2 + 8));
  if ((9 < uVar4) && (0 < (int)uVar4)) {
    FUN_02ff89ce(&local_58,&DAT_03025530,3);
    return;
  }
  *(undefined4 *)(iVar2 + 0xc) = 0xffffffff;
  *(undefined4 *)(iVar2 + 0x10) = 0xffffffff;
  *(undefined4 *)(iVar1 + 10) = 0;
  *(undefined4 *)(iVar1 + 0xe) = 0;
  *(undefined2 *)(iVar1 + 0x12) = 0;
  *(undefined1 *)(iVar1 + 0x14) = 0;
  FUN_02ffcece(0,0,(int)*(char *)(iVar2 + 8));
  return;
}


