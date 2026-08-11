/**
 * FUN_03001e64 @ 0x03001e64
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_03001e64(short *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE_00;
  int in_stack_00000010;
  uint in_stack_00000014;
  int in_stack_00000018;
  int in_stack_0000001c;
  byte abStack_138 [256];
  ushort local_38 [4];
  ushort auStack_30 [4];
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = in_stack_00000018;
  uVar4 = in_stack_00000014;
  uVar3 = DAT_03001f84;
  uStack_4 = param_4;
  uStack_8 = param_3;
  if (in_stack_0000001c == 0) {
    FUN_02ff0378(DAT_03001f84,
                 *(int *)(&stack0x00000004 + in_stack_00000018 * 4) * 0x200 + in_stack_00000010 * 8,
                 8,local_38);
    FUN_02ff0378(uVar3,param_5 * 0x200 + (uint)local_38[0] * 2,2,auStack_30);
  }
  else {
    FUN_02ff0378(DAT_03001f84,param_5 * 0x200 + in_stack_00000010 * 2,2,local_38);
    auStack_30[0] = (local_38[0] & 0xff) + (local_38[0] & 0xff00);
  }
  FUN_02ff0378(uVar3,(uint)*(ushort *)((int)&uStack_8 + iVar1 * 2) + (uint)auStack_30[0] * 0x800 +
                     param_2 * 0x200,uVar4 << 1,abStack_138);
  uVar5 = 0;
  if (uVar4 != 0) {
    do {
      iVar1 = uVar5 * 2;
      iVar2 = uVar5 * 2;
      uVar5 = uVar5 + 1 & 0xffff;
      *param_1 = (ushort)abStack_138[iVar1] + (ushort)abStack_138[iVar2 + 1] * 0x100;
      param_1 = param_1 + 1;
    } while (uVar5 < uVar4);
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


