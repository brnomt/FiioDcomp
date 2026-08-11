/**
 * FUN_03025f44 @ 0x03025f44
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Removing unreachable block (ram,0x030260c0) */
/* WARNING: Removing unreachable block (ram,0x030260c4) */
/* WARNING: Removing unreachable block (ram,0x030260f0) */
/* WARNING: Removing unreachable block (ram,0x03026146) */
/* WARNING: Removing unreachable block (ram,0x030260fc) */
/* WARNING: Removing unreachable block (ram,0x03026114) */

undefined4 FUN_03025f44(char param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uStack0000000c;
  undefined4 uStack00000010;
  undefined4 uStack00000014;
  undefined4 uStack00000018;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 in_stack_00000044;
  undefined4 in_stack_00000048;
  undefined4 in_stack_0000004c;
  uint uStack00000050;
  undefined4 uStack00000054;
  undefined4 uStack00000058;
  undefined4 in_stack_0000005c;
  
  iVar3 = (int)param_1;
  uStack00000050 = 0;
  uStack00000054 = 0;
  uStack00000058 = 0;
  uStack0000000c = 0;
  uStack00000010 = 0;
  uStack00000014 = 0;
  uStack00000018 = 0;
  uStack0000001c = 0;
  uStack00000020 = 0;
  uStack00000024 = 0;
  uVar1 = FUN_02ffc9d6(&stack0x00000050,8);
  if ((7 < uVar1) &&
     (uStack00000050 =
           uStack00000050 << 0x18 | (uStack00000050 >> 8 & 0xff) << 0x10 |
           (uStack00000050 >> 0x10 & 0xff) << 8 | uStack00000050 >> 0x18, 7 < uStack00000050)) {
    FUN_02ffcece(uStack00000050 - 8,1,iVar3);
    in_stack_0000005c = FUN_02ffce8c(iVar3);
    in_stack_00000048 = 0;
    in_stack_00000044 = 0;
    in_stack_0000004c = 0;
    uVar1 = FUN_02ffc9d6(&stack0x00000044,8,iVar3);
    if (uVar1 < 8) {
      return 0xffffffff;
    }
    FUN_02ffce6c(iVar3);
    uVar2 = FUN_02ff89ce(&stack0x00000048,&DAT_0302628c,4);
    return uVar2;
  }
  return 0xffffffff;
}


