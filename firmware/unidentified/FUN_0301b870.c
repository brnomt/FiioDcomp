/**
 * FUN_0301b870 @ 0x0301b870
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0301b870(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  *DAT_0301b9c0 = *DAT_0301b9bc;
  _DAT_e000e180 = 0x60;
  *DAT_0301b9a4 = 0;
  if (*DAT_0301b9b4 < param_1) {
    param_1 = *DAT_0301b9b4;
  }
  uVar2 = FUN_02ff5cbe((int)((longlong)param_1 * (longlong)*DAT_0301b9b0),
                       (int)((ulonglong)((longlong)param_1 * (longlong)*DAT_0301b9b0) >> 0x20),8000,
                       0);
  (*(code *)*DAT_0301b9c8)(uVar2,0,*DAT_0301b9c4);
  uVar2 = FUN_02ff5cbe((int)((longlong)param_1 * (longlong)*DAT_0301b9a8),
                       (int)((ulonglong)((longlong)param_1 * (longlong)*DAT_0301b9a8) >> 0x20),1000,
                       0);
  *DAT_0301b99c = uVar2;
  FUN_02ff5da8(DAT_0301b9cc,0x1200);
  FUN_02ff5da8(DAT_0301b9d0,0x1200);
  *DAT_0301b9d4 = DAT_0301b9cc;
  iVar1 = DAT_0301b9b8;
  *(undefined4 *)(DAT_0301b9b8 + 0x14) = DAT_0301b9d8;
  *DAT_0301b998 = *(int *)(iVar1 + 0x14);
  *DAT_0301b9dc = *(int *)(DAT_0301b9b8 + 0x14) + 0x40;
  uVar2 = DAT_0301b9cc;
  *DAT_0301b9e0 = DAT_0301b9cc;
  *DAT_0301b9e4 = uVar2;
  *(undefined4 *)(*DAT_0301b9dc + 0x2c) = *DAT_0301b9e0;
  *(undefined4 *)(*DAT_0301b9dc + 0x30) = *DAT_0301b9e4;
  *(undefined4 *)(*DAT_0301b998 + 0x14) = 0;
  *(undefined4 *)(*DAT_0301b998 + 0x18) = 0;
  (**(code **)(DAT_0301b9b8 + 0x1c))(*(undefined4 *)(DAT_0301b9b8 + 0x18),*DAT_0301b998);
  *(undefined4 *)(*DAT_0301b9dc + 0x34) = 0;
  *(undefined4 *)(*DAT_0301b9dc + 0x38) = 0;
  *(undefined4 *)(*DAT_0301b9dc + 0x3c) = 0;
  *(undefined4 *)(*DAT_0301b9dc + 0x40) = 0;
  *DAT_0301b9e8 = 0;
  FUN_0301c35e();
  *DAT_0301b9ec = 0x60;
  *DAT_0301b9f0 = 0;
  FUN_0301b2a8();
  _DAT_e000e100 = *DAT_0301b9c0;
  return;
}


