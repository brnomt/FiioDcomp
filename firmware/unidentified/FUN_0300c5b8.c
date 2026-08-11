/**
 * FUN_0300c5b8 @ 0x0300c5b8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_0300c5b8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_b8 [160];
  
  FUN_02febace(param_2,0,param_4);
  if (*DAT_0300c824 == 1) {
    uVar1 = FUN_02feb5d6(param_1,0x9e,param_4);
    *(undefined1 *)(param_1 + (uint)uVar1) = 0;
    uVar2 = FUN_0300c50a(param_3,param_1);
    uVar3 = (uVar2 & 0x7fff) << 1;
  }
  else if (*DAT_0300c824 == 3) {
    uVar1 = FUN_02feb5d6(auStack_b8,0x4e,param_4);
    auStack_b8[uVar1] = 0;
    uVar1 = FUN_02ff49c8(auStack_b8,param_1,(uint)uVar1,3);
    uVar3 = (uint)uVar1;
    uVar2 = FUN_0300c50a(param_3,param_1);
  }
  else {
    uVar1 = FUN_02feb5d6(auStack_b8,0x4e,param_4);
    auStack_b8[uVar1] = 0;
    FUN_02ff4bb4(auStack_b8,param_1);
    uVar2 = FUN_0300c50a(param_3,param_1);
    uVar3 = FUN_0300c418(auStack_b8,uVar2);
  }
  *(undefined2 *)(param_1 + uVar2 * 2) = 0;
  return uVar3;
}


