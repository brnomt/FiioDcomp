/**
 * FUN_03084338 @ 0x03084338
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03084338(int *param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(*param_1 + 0xbc);
  if (iVar2 == 3) {
    if (param_3 == 1) {
      *(undefined4 *)(param_2 + 0x18) = DAT_03084558;
      *(undefined4 *)(param_2 + 0x1c) = *DAT_0308455c;
      *(undefined4 *)(param_2 + 0x20) = *DAT_03084560;
      *(undefined1 **)(param_2 + 0x24) = &LAB_030842f2_1;
      *(undefined1 **)(param_2 + 0x28) = &LAB_030842f2_1;
LAB_030843ee:
      *(undefined2 *)((int)param_1 + 0xda) = 0x28;
      return;
    }
    *(undefined4 *)(param_2 + 0x18) = DAT_0308454c;
    *(undefined4 *)(param_2 + 0x1c) = DAT_03084550;
    *(undefined4 *)(param_2 + 0x20) = DAT_03084554;
    *(undefined1 **)(param_2 + 0x24) = &LAB_030842f2_1;
    *(undefined1 **)(param_2 + 0x28) = &LAB_030842f2_1;
    uVar1 = 0x46;
  }
  else if (iVar2 == 1) {
    if (param_3 == 1) {
      *(undefined4 *)(param_2 + 0x18) = DAT_03084570;
      *(undefined4 *)(param_2 + 0x1c) = *DAT_03084574;
      *(undefined4 *)(param_2 + 0x20) = *DAT_03084578;
      *(undefined1 **)(param_2 + 0x24) = &LAB_03084322_1;
      *(undefined1 **)(param_2 + 0x28) = &LAB_030842f2_1;
      goto LAB_030843ee;
    }
    *(undefined4 *)(param_2 + 0x18) = DAT_03084564;
    *(undefined4 *)(param_2 + 0x1c) = *DAT_03084568;
    *(undefined4 *)(param_2 + 0x20) = *DAT_0308456c;
    *(undefined1 **)(param_2 + 0x24) = &LAB_0308430c_1;
    *(undefined1 **)(param_2 + 0x28) = &LAB_030842f2_1;
    uVar1 = 0x3c;
  }
  else {
    if (iVar2 != 2) {
      return;
    }
    if (param_3 == 1) {
      *(undefined4 *)(param_2 + 0x18) = DAT_0308457c;
      *(undefined4 *)(param_2 + 0x1c) = *DAT_03084580;
      *(undefined4 *)(param_2 + 0x20) = *DAT_03084584;
      *(undefined1 **)(param_2 + 0x24) = &LAB_030842f6_1;
      *(undefined1 **)(param_2 + 0x28) = &LAB_030842f2_1;
      uVar1 = 0xb4;
    }
    else {
      *(undefined4 *)(param_2 + 0x18) = *DAT_03084540;
      *(undefined4 *)(param_2 + 0x1c) = *DAT_03084544;
      *(undefined4 *)(param_2 + 0x20) = *DAT_03084548;
      *(undefined1 **)(param_2 + 0x24) = &LAB_030842f2_1;
      *(undefined1 **)(param_2 + 0x28) = &LAB_030842e4_1;
      uVar1 = 0x154;
    }
  }
  *(undefined2 *)((int)param_1 + 0xda) = uVar1;
  return;
}


