/**
 * FUN_030905f8 @ 0x030905f8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030905f8(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x2c) = 1;
  iVar3 = *(int *)(param_1 + 0x50);
  uVar1 = FUN_03082bfa(iVar3);
  uVar1 = FUN_030829f2(uVar1,0xffffffff);
  *(undefined4 *)(param_1 + 0x120) = uVar1;
  iVar2 = DAT_030908c0;
  if (*(int *)(param_1 + 0x40) == 1) {
    if (iVar3 == 0x5622) {
      if (DAT_030908ac <= *(int *)(param_1 + 0x34)) goto LAB_0309075e;
      if (DAT_030908b0 <= *(int *)(param_1 + 0x34)) {
        iVar2 = DAT_030908c8;
      }
    }
    else if (iVar3 == 0xac44) {
      iVar2 = DAT_030908c4;
      if (DAT_030908b4 <= *(int *)(param_1 + 0x34)) goto LAB_0309075e;
    }
    else {
      if (iVar3 != 16000) {
        if (iVar3 == 0x2b11) {
          uVar1 = FUN_03082906(uVar1,DAT_030908c8);
          *(undefined4 *)(param_1 + 0x120) = uVar1;
          if (*(int *)(param_1 + 0x30) < DAT_030908cc) {
            return 0;
          }
LAB_03090742:
          *(undefined4 *)(param_1 + 300) = 3;
          return 0;
        }
        if (iVar3 == 8000) {
          if (DAT_030908b8 < *(int *)(param_1 + 0x30)) {
            iVar2 = DAT_030908d4;
            if (0x3f400000 < *(int *)(param_1 + 0x30)) goto LAB_0309075e;
            goto LAB_0309066c;
          }
        }
        else {
          if (DAT_030908bc <= *(int *)(param_1 + 0x30)) {
LAB_0309076c:
            uVar1 = FUN_03082906(uVar1,0x3f400000);
            goto LAB_030906e6;
          }
          if (DAT_030908c0 <= *(int *)(param_1 + 0x30)) goto LAB_030906fc;
        }
LAB_030906c8:
        uVar1 = FUN_030829f2(uVar1,0xffffffff);
        goto LAB_030906e6;
      }
      iVar2 = DAT_030908d0;
      if (0x3f000000 < *(int *)(param_1 + 0x30)) {
LAB_03090716:
        uVar1 = FUN_030829f2(uVar1,0xffffffff);
        *(undefined4 *)(param_1 + 300) = 3;
        *(undefined4 *)(param_1 + 0x120) = uVar1;
        return 0;
      }
    }
LAB_0309066c:
    uVar1 = FUN_03082906(uVar1,iVar2);
    *(undefined4 *)(param_1 + 0x120) = uVar1;
  }
  else {
    if (48000 < iVar3) {
LAB_0309075e:
      *(undefined4 *)(param_1 + 0x2c) = 0;
      return 0;
    }
    if (iVar3 < 0xac44) {
      if (iVar3 < 0x5622) {
        if (iVar3 < 16000) {
          if (0x2b10 < iVar3) {
            uVar1 = FUN_03082906(uVar1,DAT_030908c8);
            *(undefined4 *)(param_1 + 0x120) = uVar1;
            if (*(int *)(param_1 + 0x30) < DAT_030908cc) {
              return 0;
            }
            goto LAB_03090742;
          }
          if (iVar3 < 8000) {
            if (DAT_030908bc <= *(int *)(param_1 + 0x30)) goto LAB_0309076c;
            if (*(int *)(param_1 + 0x30) < DAT_030908c0) goto LAB_030906c8;
          }
          else {
            if (*(int *)(param_1 + 0x30) <= DAT_030908b8) goto LAB_030906c8;
            iVar2 = DAT_030908d4;
            if (0x3f400000 < *(int *)(param_1 + 0x30)) goto LAB_0309075e;
          }
        }
        else {
          iVar2 = DAT_030908d0;
          if (0x3f000000 < *(int *)(param_1 + 0x30)) goto LAB_03090716;
        }
      }
      else {
        if (DAT_030908ac <= *(int *)(param_1 + 0x34)) goto LAB_0309075e;
        if (DAT_030908b0 <= *(int *)(param_1 + 0x34)) {
          iVar2 = DAT_030908c8;
        }
      }
    }
    else {
      iVar2 = DAT_030908c4;
      if (DAT_030908b4 <= *(int *)(param_1 + 0x34)) goto LAB_0309075e;
    }
LAB_030906fc:
    uVar1 = FUN_03082906(uVar1,iVar2);
LAB_030906e6:
    *(undefined4 *)(param_1 + 0x120) = uVar1;
  }
  return 0;
}


