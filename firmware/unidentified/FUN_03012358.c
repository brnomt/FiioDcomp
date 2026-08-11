/**
 * FUN_03012358 @ 0x03012358
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03012358(undefined4 param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int unaff_r4;
  int unaff_r5;
  int unaff_r6;
  int unaff_r7;
  int unaff_r8;
  int unaff_r9;
  char *unaff_r10;
  int unaff_r11;
  undefined4 in_stack_00000050;
  undefined4 in_stack_0000006c;
  
  do {
    FUN_02fede0e(unaff_r5 + 0x4f,param_2,param_3);
    *(undefined1 *)(unaff_r5 + 0x4e) = 0;
    *(undefined4 *)(unaff_r5 + 8) = param_5;
    FUN_02fede0e(unaff_r5 + 0x24,&stack0x0000001c,0x2a);
    *(int *)(unaff_r5 + 0xc) = param_6 + -1;
    if (*unaff_r10 == '\x03') {
      FUN_02ff30c4(unaff_r5 + 0x24,param_6 + -1);
    }
    else {
      FUN_02ff3f2c(param_5);
    }
    unaff_r5 = *(int *)(unaff_r5 + 4);
    unaff_r6 = (int)(short)((short)unaff_r6 + -1);
    while( true ) {
      do {
        while( true ) {
          if (unaff_r6 == 0 && unaff_r7 == 0) {
            return;
          }
          do {
            iVar2 = FUN_02ff3858(&stack0x00000048,&param_5,in_stack_0000006c);
            if (iVar2 != 0) {
              return;
            }
          } while ((in_stack_00000050._3_1_ & 2) != 0);
          if ((in_stack_00000050._3_1_ & 0x10) != 0) break;
          if (unaff_r7 != 0) {
            if (unaff_r9 == 0) {
              FUN_02fede0e(unaff_r4 + 0x4f,&stack0x00000048,0x20);
              *(undefined4 *)(unaff_r4 + 8) = param_5;
              FUN_02fede0e(unaff_r4 + 0x24,&stack0x0000001c,0x2a);
              *(int *)(unaff_r4 + 0xc) = param_6 + -1;
              if (*unaff_r10 == '\x03') {
                FUN_02ff30c4(unaff_r4 + 0x24,param_6 + -1);
              }
              else {
                FUN_02ff3f2c(param_5);
              }
              if (*unaff_r10 == '\x03') {
                FUN_02ff5638(&stack0x00000048,unaff_r4 + 0x70);
              }
              puVar3 = (undefined1 *)FUN_03012194(&stack0x00000048);
              if (unaff_r11 == 1) {
                uVar1 = 1;
              }
              else {
                uVar1 = *puVar3;
              }
              *(undefined1 *)(unaff_r4 + 0x4e) = uVar1;
              unaff_r4 = *(int *)(unaff_r4 + 4);
              unaff_r7 = (int)(short)((short)unaff_r7 + -1);
            }
            else {
              unaff_r9 = (int)(short)((short)unaff_r9 + -1);
            }
          }
        }
      } while (unaff_r6 == 0);
      if (unaff_r8 == 0) break;
      unaff_r8 = (int)(short)((short)unaff_r8 + -1);
    }
    param_3 = 0x20;
    param_2 = &stack0x00000048;
  } while( true );
}


