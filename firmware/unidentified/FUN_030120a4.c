/**
 * FUN_030120a4 @ 0x030120a4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030120a4(int param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined2 uStack_38;
  undefined1 uStack_36;
  undefined1 auStack_30 [11];
  byte bStack_25;
  ushort uStack_1c;
  ushort uStack_16;
  int iStack_10;
  uint uStack_c;
  int iStack_8;
  
  uStack_c = param_2 >> 0x18;
  iStack_10 = param_1 << 0x14;
  iStack_8 = param_1 >> 0x20;
  puVar2 = (undefined4 *)(param_1 * 0x100);
  param_1 = param_1 >> 8;
  uStack_40 = *puVar2;
  uStack_3c = puVar2[1];
  uStack_38 = *(undefined2 *)(puVar2 + 2);
  uStack_36 = *(undefined1 *)((int)puVar2 + 10);
  uVar3 = 0x13;
  iVar1 = FUN_02ff1166(auStack_30,param_1,&uStack_40,param_3 >> 0x10);
  if ((iVar1 == 0) && ((bStack_25 & 0x10) == 0)) {
    uVar3 = 0x12;
    iVar1 = rom_i2s_master_config(param_1,puVar2);
    if (7 < iVar1) {
      FUN_02ff42a0((uint)uStack_16 + (uint)uStack_1c * 0x10000);
      FUN_02ff4ed6(param_1,&uStack_40);
      uVar3 = 0;
    }
  }
  return uVar3;
}


