/**
 * FUN_03022252 @ 0x03022252
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03022252(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 *unaff_r4;
  int unaff_r5;
  int unaff_r6;
  int in_r12;
  ushort uStack00000000;
  undefined2 uStack00000002;
  undefined4 in_stack_00000004;
  int in_stack_00000008;
  undefined4 in_stack_00000108;
  undefined4 in_stack_0000010c;
  undefined4 in_stack_00000110;
  undefined4 in_stack_00000114;
  undefined4 in_stack_00000118;
  undefined4 in_stack_0000011c;
  undefined4 in_stack_00000120;
  undefined4 in_stack_00000124;
  undefined2 in_stack_00000128;
  
  iVar3 = 0;
  if (0 < unaff_r5) {
    do {
      iVar1 = iVar3 * 4;
      iVar2 = iVar3 * 4;
      iVar3 = iVar3 + 1;
      *(undefined4 *)(in_r12 + iVar2 + 8) = *(undefined4 *)(unaff_r6 + iVar1);
    } while (iVar3 < unaff_r5);
  }
  if (uStack00000000 == 0x9003) {
    FUN_02ff890e(DAT_030225e8,&stack0x00000108,in_stack_00000004);
  }
  else if (uStack00000000 < 0x9004) {
    if (uStack00000000 == 0x112) {
      *(int *)(DAT_030225e4 + 0x1c) = in_stack_00000008;
    }
    else if (uStack00000000 == 0x201) {
      *(int *)(DAT_030225e4 + 0x28) = in_stack_00000008 + *(int *)(DAT_030225e4 + 4) + 10;
    }
    else if (uStack00000000 == 0x202) {
      *(int *)(DAT_030225e4 + 0x24) = in_stack_00000008;
    }
    else if (uStack00000000 == 0x8769) {
      *(undefined4 *)(unaff_r4 + 0x84) = in_stack_00000108;
      *(undefined4 *)(unaff_r4 + 0x86) = in_stack_0000010c;
      *(undefined4 *)(unaff_r4 + 0x88) = in_stack_00000110;
      *(undefined4 *)(unaff_r4 + 0x8a) = in_stack_00000114;
      *(undefined4 *)(unaff_r4 + 0x8c) = in_stack_00000118;
      *(undefined4 *)(unaff_r4 + 0x8e) = in_stack_0000011c;
      *(undefined4 *)(unaff_r4 + 0x90) = in_stack_00000120;
      *(undefined4 *)(unaff_r4 + 0x92) = in_stack_00000124;
      *(undefined4 *)(unaff_r4 + 2) = in_stack_00000004;
      unaff_r4[0x94] = in_stack_00000128;
      FUN_02ff890e(unaff_r4 + 4,&stack0x00000008,0x100);
      *unaff_r4 = 0x8769;
      unaff_r4[1] = uStack00000002;
    }
  }
  else if (uStack00000000 == 0xa001) {
    *(int *)(DAT_030225e4 + 0x20) = in_stack_00000008;
  }
  else if (uStack00000000 == 0xa002) {
    *(int *)(DAT_030225e4 + 0x14) = in_stack_00000008;
  }
  else if (uStack00000000 == 0xa003) {
    *(int *)(DAT_030225e4 + 0x18) = in_stack_00000008;
  }
  return 0;
}


