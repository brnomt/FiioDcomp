/**
 * FUN_03086254 @ 0x03086254
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_03086254(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6,
                int param_7,int param_8,undefined1 *param_9)

{
  int iVar1;
  short sVar2;
  bool bVar3;
  
  if (param_1 == (int *)0x0) {
    return DAT_03086748;
  }
  if ((*param_1 == 0) || ((param_2 == 0 && (param_3 != 0)))) {
    iVar1 = DAT_03086748;
    if (param_9 == (undefined1 *)0x0) {
      return DAT_03086748;
    }
  }
  else {
    if (param_9 == (undefined1 *)0x0) {
      return DAT_03086748;
    }
    *(undefined1 *)(param_1 + 0x72) = 0;
    if (param_4 != 0 && param_6 != 0) {
      if (1 < (short)param_1[0xf]) {
        *(short *)(param_1 + 0xf) = (short)param_1[0xf] + -1;
      }
      if (param_1[0x10] != param_7 || param_1[0x11] != param_8) {
        if (param_1[0xe] == 0) {
          param_1[0x10] = param_7;
          param_1[0xe] = 1;
          param_1[0x11] = param_8;
          *(undefined2 *)(param_1 + 0xf) = 1;
        }
        else {
          param_1[0x12] = param_7;
          param_1[0x13] = param_8;
          sVar2 = (short)param_1[0xf] + 1;
          *(short *)(param_1 + 0xf) = sVar2;
          if (sVar2 != 2) {
            param_1[0xe] = 0;
            *(undefined2 *)(param_1 + 0xf) = 0;
          }
        }
      }
    }
    iVar1 = FUN_0308463e(param_1 + 0x21);
    bVar3 = iVar1 == 0;
    if (-1 < iVar1) {
      bVar3 = iVar1 == 6;
    }
    if (bVar3) {
      iVar1 = 6;
      *(undefined1 *)(*param_1 + 0x48) = 6;
      param_1[0x73] = 1;
    }
    else if (iVar1 < 0) goto LAB_03086316;
    *(undefined1 *)(param_1 + 0x72) = 2;
  }
LAB_03086316:
  *param_9 = (char)param_1[0x72];
  return iVar1;
}


