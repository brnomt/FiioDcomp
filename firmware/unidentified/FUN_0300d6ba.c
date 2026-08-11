/**
 * FUN_0300d6ba @ 0x0300d6ba
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300d6ba(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint unaff_r6;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  
  local_20 = 0x17;
  local_1c = 0x68;
  local_1e = 4;
  local_1a = 0x13;
  uVar5 = param_3 & 0xffff | ((int)param_3 >> 0x10) << 0x10;
  iVar1 = ((int)unaff_r6 >> 0x10) << 0x10;
  *DAT_0300d7b0 = 0xffff;
  uVar3 = FUN_0300d5ae(*(int *)(DAT_0300d7b8 + 0x1c) + 1,*(undefined4 *)(DAT_0300d7b8 + 0x18),
                       DAT_0300d7b4);
  iVar2 = DAT_0300d7bc;
  FUN_0300ced6(DAT_0300d7b4,DAT_0300d7bc + 0x82,uVar3);
  uVar4 = FUN_02ff4f56(DAT_0300d7b4);
  if (0xf0 < uVar4) {
    FUN_02ff5b58(&local_20,uVar5,iVar1);
    FUN_02ffa694(0x13c);
  }
  FUN_02ff52c8(&local_20,&local_20,DAT_0300d7b4,2);
  uVar4 = FUN_02ff4f56(iVar2 + 0x82);
  if ((unaff_r6 & 0xffff) < uVar4) {
    FUN_02ff5b58(&local_20,uVar5,iVar1);
    FUN_02ffa694(0x13c);
  }
  FUN_02ff52c8(&local_20,&local_20,iVar2 + 0x82,2);
  return;
}


