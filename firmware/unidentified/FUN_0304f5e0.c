/**
 * FUN_0304f5e0 @ 0x0304f5e0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0304f5e0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 == (int *)0x0) || (*param_1 == -1 || param_2 == -1)) {
    FUN_03033618(DAT_0304f8d8);
    return 0;
  }
  param_1[2] = -1;
  iVar2 = 0xf3;
  iVar1 = DICTDECODER_InitStream((short *)*param_1,param_2);
  if (iVar1 != 0) {
    param_1[2] = *param_1;
    iVar2 = FUN_0304fe12();
  }
  if (param_1[2] != -1) {
    if (iVar2 != 0) {
      FUN_03033618(DAT_0304f8d4);
      return 0;
    }
    return 1;
  }
  FUN_03033618(DAT_0304f8dc);
  return 0;
}


