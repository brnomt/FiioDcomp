/**
 * FUN_030222a2 @ 0x030222a2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4
FUN_030222a2(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,int param_7)

{
  undefined2 *unaff_r4;
  char in_ZR;
  undefined4 in_stack_00000108;
  undefined4 in_stack_0000010c;
  undefined4 in_stack_00000110;
  undefined4 in_stack_00000114;
  undefined4 in_stack_00000118;
  undefined4 in_stack_0000011c;
  undefined4 in_stack_00000120;
  undefined4 in_stack_00000124;
  undefined2 in_stack_00000128;
  
  if (in_ZR == '\0') {
    if (param_1 == 0x201) {
      *(int *)(param_3 + 0x28) = param_7 + *(int *)(param_3 + 4) + 10;
    }
    else if (param_1 == 0x202) {
      *(int *)(param_3 + 0x24) = param_7;
    }
    else if (param_1 == 0x8769) {
      *(undefined4 *)(unaff_r4 + 0x84) = in_stack_00000108;
      *(undefined4 *)(unaff_r4 + 0x86) = in_stack_0000010c;
      *(undefined4 *)(unaff_r4 + 0x88) = in_stack_00000110;
      *(undefined4 *)(unaff_r4 + 0x8a) = in_stack_00000114;
      *(undefined4 *)(unaff_r4 + 0x8c) = in_stack_00000118;
      *(undefined4 *)(unaff_r4 + 0x8e) = in_stack_0000011c;
      *(undefined4 *)(unaff_r4 + 0x90) = in_stack_00000120;
      *(undefined4 *)(unaff_r4 + 0x92) = in_stack_00000124;
      *(undefined4 *)(unaff_r4 + 2) = param_6;
      unaff_r4[0x94] = in_stack_00000128;
      FUN_02ff890e(unaff_r4 + 4,param_2 + 8,0x100);
      *unaff_r4 = (undefined2)param_5;
      unaff_r4[1] = param_5._2_2_;
    }
  }
  return 0;
}


