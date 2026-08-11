/**
 * FUN_030196e4 @ 0x030196e4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030196e4(undefined1 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = DAT_03019754;
  iVar1 = DAT_0301974c;
  *(undefined1 *)(DAT_0301974c + 0x1c0) = param_1;
  iVar3 = FUN_02ff2834(*puVar2,DAT_03019750);
  if ((iVar3 == 1) && (*(uint *)(DAT_03019758 + 4) != (uint)*(byte *)(iVar1 + 0x1c0))) {
    FUN_02ff278c(DAT_03019754,DAT_03019750);
    *(undefined1 *)(iVar1 + 0x1c0) = param_1;
    FUN_02ff274e(DAT_03019754,DAT_03019750,0);
    *DAT_0301975c = 0;
  }
  return 0;
}


