/**
 * FUN_0301c780 @ 0x0301c780
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301c780(uint *param_1,char *param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  if (param_2[1] == '\0') {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  if (*param_2 == '\x01') {
    iVar2 = 0xc;
  }
  else if ((*param_2 == '\x03') && ((*(ushort *)(param_2 + 0x18) & 0x1000) != 0)) {
    iVar2 = 0x12;
  }
  else {
    iVar2 = 0x24;
  }
  param_1[1] = *(uint *)(param_2 + 0x10);
  *(undefined2 *)(param_1 + 2) = uVar1;
  *(short *)((int)param_1 + 10) = (short)(iVar2 << 5);
  *param_1 = (uint)(byte)*param_1 + iVar2 & 0xf;
  return;
}


