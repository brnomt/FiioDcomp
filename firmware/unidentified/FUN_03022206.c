/**
 * FUN_03022206 @ 0x03022206
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4
FUN_03022206(int param_1,ushort param_2,int param_3,int param_4,int param_5,int param_6,
            ushort *param_7)

{
  int iVar1;
  int iVar2;
  ushort uStack_150;
  ushort uStack_14e;
  int iStack_14c;
  int aiStack_148 [64];
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  ushort uStack_28;
  
  if (param_1 != 0) {
    FUN_02ff895c(&uStack_150,0x134);
    uStack_14e = (ushort)param_3;
    if (param_4 != 0) {
      uStack_150 = param_2;
      iStack_14c = param_4;
      if (param_5 == 0) {
        if (param_6 == 0) {
          uStack_28 = 1;
        }
        else {
          FUN_02ff890e(&uStack_48,param_6,param_4);
        }
      }
      else {
        if ((param_3 == 5 || param_3 == 10) && (param_4 = param_4 * 2, 0x1f < param_4)) {
          param_4 = 0x1f;
        }
        iVar1 = 0;
        if (0 < param_4) {
          do {
            iVar2 = iVar1 + 1;
            aiStack_148[iVar1] = *(int *)(param_5 + iVar1 * 4);
            iVar1 = iVar2;
          } while (iVar2 < param_4);
        }
      }
      if (uStack_150 == 0x9003) {
        FUN_02ff890e(DAT_030225e8,&uStack_48,iStack_14c);
      }
      else if (uStack_150 < 0x9004) {
        if (uStack_150 == 0x112) {
          *(int *)(DAT_030225e4 + 0x1c) = aiStack_148[0];
        }
        else if (uStack_150 == 0x201) {
          *(int *)(DAT_030225e4 + 0x28) = aiStack_148[0] + *(int *)(DAT_030225e4 + 4) + 10;
        }
        else if (uStack_150 == 0x202) {
          *(int *)(DAT_030225e4 + 0x24) = aiStack_148[0];
        }
        else if (uStack_150 == 0x8769) {
          *(undefined4 *)(param_7 + 0x84) = uStack_48;
          *(undefined4 *)(param_7 + 0x86) = uStack_44;
          *(undefined4 *)(param_7 + 0x88) = uStack_40;
          *(undefined4 *)(param_7 + 0x8a) = uStack_3c;
          *(undefined4 *)(param_7 + 0x8c) = uStack_38;
          *(undefined4 *)(param_7 + 0x8e) = uStack_34;
          *(undefined4 *)(param_7 + 0x90) = uStack_30;
          *(undefined4 *)(param_7 + 0x92) = uStack_2c;
          *(int *)(param_7 + 2) = iStack_14c;
          param_7[0x94] = uStack_28;
          FUN_02ff890e(param_7 + 4,aiStack_148,0x100);
          *param_7 = uStack_150;
          param_7[1] = uStack_14e;
        }
      }
      else if (uStack_150 == 0xa001) {
        *(int *)(DAT_030225e4 + 0x20) = aiStack_148[0];
      }
      else if (uStack_150 == 0xa002) {
        *(int *)(DAT_030225e4 + 0x14) = aiStack_148[0];
      }
      else if (uStack_150 == 0xa003) {
        *(int *)(DAT_030225e4 + 0x18) = aiStack_148[0];
      }
    }
    return 0;
  }
  return 0;
}


