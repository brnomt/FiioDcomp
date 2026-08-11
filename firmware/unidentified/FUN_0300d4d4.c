/**
 * FUN_0300d4d4 @ 0x0300d4d4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300d4d4(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined2 unaff_r6;
  undefined4 *unaff_r7;
  int unaff_r8;
  
  uVar2 = FUN_0300d090(param_4,(int)*param_1);
  unaff_r7[8] = uVar2;
  *unaff_r7 = uVar2;
  uVar1 = 0;
  unaff_r7[1] = uVar2;
  do {
    **(undefined2 **)(unaff_r8 + 0xc) = unaff_r6;
    FUN_0300c65a();
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0xc);
  unaff_r7[7] = unaff_r7[7] + -1;
  FUN_02ffa694(0x13d);
  FUN_02ffa694(0x13b);
  return;
}


