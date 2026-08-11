/**
 * FUN_03029730 @ 0x03029730
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4
FUN_03029730(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
            ,undefined4 param_6,undefined4 param_7)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 unaff_r5;
  
  if (*(int *)(param_5 + 0x1e) == 0) {
    sVar1 = *(short *)(param_5 + 0x1c);
    if (sVar1 == 0x10) {
      unaff_r5 = FUN_03029654(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
    else {
      if (sVar1 < 0x11) {
        if (sVar1 == 1) {
          uVar2 = FUN_030295d0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
          return uVar2;
        }
        if (sVar1 == 4) {
          uVar2 = FUN_030295fc(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
          return uVar2;
        }
        if (sVar1 == 8) {
          uVar2 = FUN_03029628(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
          return uVar2;
        }
      }
      else {
        if (sVar1 == 0x18) {
          uVar2 = FUN_03029680(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
          return uVar2;
        }
        if (sVar1 == 0x20) {
          uVar2 = FUN_030296ac(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
          return uVar2;
        }
      }
      unaff_r5 = 0;
    }
  }
  else if (*(int *)(param_5 + 0x1e) == 3) {
    if (*(short *)(param_5 + 0x1c) == 0x10) {
      unaff_r5 = FUN_030296d8(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
    else if (*(short *)(param_5 + 0x1c) == 0x20) {
      unaff_r5 = FUN_03029704(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    unaff_r5 = 0;
  }
  return unaff_r5;
}


