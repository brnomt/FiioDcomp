/**
 * FUN_03001e98 @ 0x03001e98
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03001e98(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  short *unaff_r4;
  uint unaff_r5;
  code *UNRECOVERED_JUMPTABLE_00;
  undefined4 in_stack_0000012c;
  
  FUN_02ff0378();
  uVar3 = 0;
  if (unaff_r5 != 0) {
    do {
      iVar1 = uVar3 * 2;
      iVar2 = uVar3 * 2;
      uVar3 = uVar3 + 1 & 0xffff;
      *unaff_r4 = (ushort)(byte)(&stack0x00000000)[iVar1] +
                  (ushort)(byte)(&stack0x00000001)[iVar2] * 0x100;
      unaff_r4 = unaff_r4 + 1;
    } while (uVar3 < unaff_r5);
                    /* WARNING: Could not recover jumptable at 0x03001f24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x03001f00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE_00)();
  return;
}


