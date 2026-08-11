/**
 * FUN_030261be @ 0x030261be
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030261be(char param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  
  local_30 = *(undefined4 *)(DAT_030262c4 + 0x60);
  uStack_2c = *(undefined4 *)(DAT_030262c4 + 100);
  uStack_28 = *(undefined4 *)(DAT_030262c4 + 0x68);
  uStack_24 = *(undefined4 *)(DAT_030262c4 + 0x6c);
  local_20 = *(undefined4 *)(DAT_030262c4 + 0x70);
  local_48 = 0;
  local_34 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  if (param_2 < 1) {
    return 0xffffffff;
  }
  FUN_02ffce8c((int)param_1);
  uVar1 = FUN_02ffc9d6(&local_48,0x18,(int)param_1);
  if (uVar1 < 0x18) {
    return 0xffffffff;
  }
  uVar2 = FUN_02ff89ce(&local_48,&local_30,0x10);
  return uVar2;
}


