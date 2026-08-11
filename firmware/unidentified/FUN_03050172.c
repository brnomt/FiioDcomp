/**
 * FUN_03050172 @ 0x03050172
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_03050172(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 auStack_28 [2];
  int iStack_24;
  
  if (param_1 == 0 || param_2 == -1) {
    return 0;
  }
  iVar2 = 0;
  iVar3 = *param_3 * (uint)*(ushort *)(param_1 + 0x10) +
          (uint)*(ushort *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 0xe) +
          (uint)*(ushort *)(param_1 + 0x16);
  auStack_28[0] = (undefined2)param_3[3];
  iStack_24 = param_3[2];
  if (0 < param_3[1]) {
    do {
      iVar1 = FUN_0304fed0(param_1,param_2,iVar3,auStack_28);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar3 = iVar3 + (uint)*(ushort *)(param_1 + 0x10);
      iVar2 = iVar2 + 1;
      iStack_24 = iStack_24 + param_3[3];
    } while (iVar2 < param_3[1]);
  }
  return iVar2;
}


