/**
 * FUN_03083ec4 @ 0x03083ec4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03083ec4(int *param_1,undefined4 *param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  iVar2 = param_2[6];
  iVar3 = param_2[7];
  if (param_2[2] != 0 && param_2[4] != 0) {
    if (1 < (short)param_1[0xf]) {
      *(short *)(param_1 + 0xf) = (short)param_1[0xf] + -1;
    }
    if (param_1[0x10] != iVar2 || param_1[0x11] != iVar3) {
      if (param_1[0xe] == 0) {
        param_1[0xe] = 1;
        param_1[0x10] = iVar2;
        param_1[0x11] = iVar3;
        *(undefined2 *)(param_1 + 0xf) = 1;
      }
      else {
        param_1[0x12] = iVar2;
        param_1[0x13] = iVar3;
        sVar1 = (short)param_1[0xf] + 1;
        *(short *)(param_1 + 0xf) = sVar1;
        if (sVar1 != 2) {
          param_1[0xe] = 0;
          *(undefined2 *)(param_1 + 0xf) = 0;
        }
      }
    }
  }
  iVar2 = FUN_0308463e(param_1 + 0x21,*param_2,param_2[1],param_2[2],param_2[3],param_1[0x75],
                       *(undefined4 *)(*param_1 + 0x40));
  bVar4 = iVar2 == 0;
  if (-1 < iVar2) {
    bVar4 = iVar2 == 6;
  }
  if (bVar4) {
    *(undefined1 *)(*param_1 + 0x48) = 6;
    param_1[0x73] = 1;
    return;
  }
  return;
}


