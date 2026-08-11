/**
 * FUN_030185a6 @ 0x030185a6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030185a6(undefined4 param_1,int param_2,int param_3,short param_4)

{
  undefined2 unaff_r6;
  undefined2 unaff_r7;
  undefined2 *unaff_r8;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  
  if (param_2 != 0) {
    FUN_02fffc76(0x113,(int)(short)((param_4 + (short)param_3) * 0x3a + 0x52),
                 (int)(short)(((short)(param_3 * 0x156 >> 10) - (short)(param_3 * 0x156 >> 0x1f)) *
                              0x4a + 0x13));
  }
  FUN_03018320();
  FUN_02ffef2c(in_stack_00000020);
  unaff_r8[1] = unaff_r6;
  *unaff_r8 = unaff_r7;
  FUN_02ffef08(in_stack_00000024);
  return;
}


