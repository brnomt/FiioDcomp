/**
 * FUN_03028c1a @ 0x03028c1a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03028c1a(ushort *param_1,undefined2 *param_2)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 2;
  puVar2 = param_1;
  do {
    iVar5 = (uint)*puVar2 * 0x4000 + 0x800;
    iVar3 = iVar3 + -1;
    *puVar2 = (ushort)((uint)((iVar5 + (short)puVar2[8] * 0x39fe) * 0x10) >> 0x10);
    puVar2[8] = (ushort)((uint)((iVar5 + (short)puVar2[8] * -0x39fe) * 0x10) >> 0x10);
    puVar2 = puVar2 + 1;
  } while (0 < iVar3);
  iVar3 = 2;
  do {
    uVar1 = param_1[1];
    iVar4 = (short)*param_1 * 0x8000 + 0x8080000;
    iVar5 = iVar4 + (short)uVar1 * 0x73fc >> 0x14;
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    else if (0xff < iVar5) {
      iVar5 = 0xff;
    }
    *param_2 = (short)iVar5;
    iVar5 = iVar4 + (short)uVar1 * -0x73fc >> 0x14;
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    else if (0xff < iVar5) {
      iVar5 = 0xff;
    }
    param_2[1] = (short)iVar5;
    param_1 = param_1 + 8;
    param_2 = param_2 + 8;
    iVar3 = iVar3 + -1;
  } while (0 < iVar3);
  return;
}


