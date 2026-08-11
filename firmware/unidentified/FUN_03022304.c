/**
 * FUN_03022304 @ 0x03022304
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4
FUN_03022304(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  undefined2 *unaff_r4;
  undefined4 in_r12;
  undefined2 in_stack_00000128;
  
  *(undefined4 *)(unaff_r4 + 0x8c) = param_1;
  *(undefined4 *)(unaff_r4 + 0x8e) = param_3;
  *(undefined4 *)(unaff_r4 + 0x90) = param_4;
  *(undefined4 *)(unaff_r4 + 0x92) = in_r12;
  *(undefined4 *)(unaff_r4 + 2) = param_6;
  unaff_r4[0x94] = in_stack_00000128;
  FUN_02ff890e(unaff_r4 + 4,param_2,0x100);
  *unaff_r4 = (undefined2)param_5;
  unaff_r4[1] = param_5._2_2_;
  return 0;
}


