/**
 * FUN_03064616 @ 0x03064616
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03064616(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  FUN_03033790();
  iVar2 = DAT_03064884;
  if (param_1 != 0) {
    (**(code **)(DAT_03064884 + 0x1c))(1);
  }
  iVar3 = DAT_0306487c;
  iVar1 = FUN_030644c4(*(undefined2 *)(*(int *)(DAT_0306487c + 0x14) + 2),param_1);
  if (iVar1 == 2) {
    iVar3 = *(int *)(iVar3 + 0x14);
    *(undefined1 *)(iVar3 + 0x50) = 0;
    *(undefined2 *)(iVar3 + 10) = 0;
    (**(code **)(iVar2 + 0x1c))(0);
  }
  else {
    iVar2 = FUN_0304d022();
    iVar1 = *(int *)(iVar3 + 0x14);
    if ((iVar2 == 1) || (uVar4 = *(uint *)(iVar1 + 0xc), uVar4 == *(ushort *)(iVar3 + 2))) {
      *(undefined1 *)(iVar1 + 0x50) = 0;
      *(undefined2 *)(iVar1 + 10) = 0;
      return 0;
    }
    if (*(short *)(iVar1 + 10) == 2) {
      FUN_03064746(0xae,0);
      return 1;
    }
    if ((uVar4 < *(ushort *)(iVar3 + 6)) || (*(ushort *)(iVar3 + 4) < uVar4)) {
      *(uint *)(iVar1 + 0xc) = (uint)*(ushort *)(iVar3 + 6);
    }
    *(undefined1 *)(iVar1 + 0x50) = 0;
    *(undefined2 *)(iVar1 + 10) = 0;
  }
  return 0;
}


