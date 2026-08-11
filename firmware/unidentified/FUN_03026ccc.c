/**
 * FUN_03026ccc @ 0x03026ccc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03026ccc(undefined2 *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *unaff_r4;
  int unaff_r6;
  int *in_r12;
  
  *param_1 = (short)param_1;
  *in_r12 = unaff_r6;
  *param_4 = unaff_r6;
  iVar1 = ((int)*DAT_03026e04 + *in_r12 + -1) / *in_r12;
  *DAT_03026e3c = iVar1;
  *DAT_03026e40 = ((int)*DAT_03026e08 + *param_4 + -1) / *param_4;
  iVar1 = *unaff_r4 * iVar1;
  *DAT_03026e44 = iVar1;
  if (iVar1 < 0x1f41) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffff1b;
  }
  return uVar2;
}


