/**
 * FUN_0302916a @ 0x0302916a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0302916a(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_r4;
  int unaff_r5;
  int unaff_r6;
  int unaff_r9;
  undefined8 uVar2;
  
  FUN_02ffb73e(param_1,param_2,*(undefined4 *)(unaff_r4 + 0x28),*(undefined4 *)(unaff_r4 + 0x2c));
  uVar1 = FUN_02ffb8f8();
  *(undefined4 *)(unaff_r4 + 0x18) = uVar1;
  uVar2 = FUN_02ffb862(*(undefined4 *)(unaff_r4 + 4));
  FUN_02ffb73e((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),*(undefined4 *)(unaff_r4 + 0x30),
               *(undefined4 *)(unaff_r4 + 0x34));
  uVar1 = FUN_02ffb8f8();
  *(undefined4 *)(unaff_r4 + 0x1c) = uVar1;
  if (*(int *)(unaff_r4 + 0x18) == 0) {
    *(undefined4 *)(unaff_r4 + 0x18) = 1;
  }
  if (*(int *)(unaff_r4 + 0x1c) == 0) {
    *(undefined4 *)(unaff_r4 + 0x1c) = 1;
  }
  *(int *)(unaff_r4 + 0x14) = unaff_r9 << 2;
  *(undefined4 *)(unaff_r6 + 4) = *(undefined4 *)(unaff_r4 + 0x18);
  *(undefined4 *)(unaff_r6 + 8) = *(undefined4 *)(unaff_r4 + 0x1c);
  *(undefined4 *)(unaff_r4 + 0x10) = *(undefined4 *)(unaff_r6 + 0xc);
  *(int *)(unaff_r4 + 0x20) =
       (int)((uint)*(ushort *)(unaff_r5 + 0x12) << 0x10) / *(int *)(unaff_r4 + 0x18) + 1;
  *(int *)(unaff_r4 + 0x24) =
       (int)((uint)*(ushort *)(unaff_r4 + 4) << 0x10) / *(int *)(unaff_r4 + 0x1c) + 1;
  *(undefined4 *)(unaff_r4 + 0x3c) = 0;
  return 1;
}


