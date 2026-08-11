/**
 * FUN_03024576 @ 0x03024576
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03024576(undefined2 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 *puVar3;
  
  puVar3 = *(undefined2 **)(DAT_030245dc + 0x28);
  uVar1 = FUN_03027dfa();
  iVar2 = 0;
  do {
    iVar2 = iVar2 + 1;
    *param_1 = *puVar3;
    puVar3 = puVar3 + 1;
    param_1 = param_1 + 1;
  } while (iVar2 < 0xc);
  return uVar1;
}


