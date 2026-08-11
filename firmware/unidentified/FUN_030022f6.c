/**
 * FUN_030022f6 @ 0x030022f6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030022f6(undefined4 param_1,uint param_2,uint param_3)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint unaff_r4;
  int unaff_r5;
  uint unaff_r6;
  int unaff_r7;
  int unaff_r8;
  undefined2 *unaff_r9;
  short unaff_r10;
  undefined2 unaff_r11;
  undefined4 uStack00000000;
  uint uStack00000004;
  ushort in_stack_00000038;
  undefined4 in_stack_00000058;
  undefined4 in_stack_0000005c;
  undefined2 in_stack_00000060;
  
  while( true ) {
    uStack00000000 = param_1;
    uStack00000004 = param_2;
    FUN_02feb8bc(0x1c,unaff_r8 + unaff_r5 * 8 & 0xffff,param_3,0x10);
    uVar3 = unaff_r4 + 1;
    unaff_r4 = uVar3 & 0xffff;
    if (5 < unaff_r4 || unaff_r6 <= unaff_r4) break;
    unaff_r5 = unaff_r4 * 3;
    sVar1 = (short)uVar3;
    iVar4 = (int)(short)(sVar1 * 0x18 + 0x17);
    uVar3 = (uint)*DAT_030025e4;
    if ((uVar3 != 5 && uVar3 != 4) && (uVar3 != 3 && uVar3 != 2)) {
      uVar3 = 1;
    }
    if (unaff_r4 == uVar3) {
      if (unaff_r4 == 0) {
        FUN_02fec55a(0x86,4,iVar4);
      }
      else {
        if (unaff_r4 == 5) {
          uVar2 = 0x88;
        }
        else {
          uVar2 = 0x85;
        }
        FUN_02fec55a(uVar2,4,iVar4);
      }
      FUN_02fec55a(*(short *)(unaff_r7 + unaff_r4 * 6) + 9,5,(int)(short)(unaff_r10 + sVar1 * 0x18))
      ;
      *unaff_r9 = *DAT_030025e8;
    }
    else {
      FUN_02fec55a(*(undefined2 *)(unaff_r7 + unaff_r4 * 6),5,(int)(short)(unaff_r10 + sVar1 * 0x18)
                  );
      *unaff_r9 = *DAT_030025dc;
    }
    param_1 = 0;
    param_2 = (uint)*(ushort *)(unaff_r7 + unaff_r4 * 6 + 2);
    param_3 = (uint)in_stack_00000038;
  }
  FUN_02feb810(in_stack_00000058);
  unaff_r9[1] = unaff_r11;
  *unaff_r9 = in_stack_00000060;
  FUN_02feb7ec(in_stack_0000005c);
  return;
}


