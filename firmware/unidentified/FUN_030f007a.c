/**
 * FUN_030f007a @ 0x030f007a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint FUN_030f007a(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = DAT_030f02e0;
  uVar3 = *(uint *)(DAT_030f02e0 + 0x18);
  if (uVar3 == 0) {
    return 0;
  }
  uVar4 = uVar3;
  if (0xfff < (int)uVar3) {
    uVar4 = 0x1000;
  }
  *(uint *)(DAT_030f02e0 + 0x18) = uVar3 - uVar4;
  param_1[0x2280] = 0;
  if ((*param_1 == 1) || ((*(byte *)(param_1 + 7) & 4) != 0)) {
    if ((*(byte *)(param_1 + 7) & 3) == 0) {
      FUN_030f03cc(param_1,uVar4,0);
      if (1000 < param_1[3]) {
        FUN_030f1934(0,uVar4);
        FUN_030eeeee(0,param_1[2],param_1[3]);
        FUN_030f191c(0,uVar4);
        FUN_030f188a(param_1 + 0x255,DAT_030f02dc,uVar4,DAT_030f02d8);
      }
      FUN_030efd2c(param_1,uVar4);
    }
    else {
      FUN_030f03cc(param_1,uVar4,0);
    }
  }
  else {
    FUN_030efef4(param_1,uVar4);
  }
  uVar2 = DAT_030f02e4;
  if ((param_1[0x2280] == 0) && ((uint)param_1[0x227f] <= (uint)param_1[0x227e])) {
    FUN_030f0824(param_1 + 0x255,param_1 + 0x1255,param_2,uVar4 & 0xffff);
    *(uint *)(iVar1 + 0x78) = *(int *)(iVar1 + 0x78) + uVar4;
    return uVar4;
  }
  param_1[1] = 0;
  log_printf_ts(uVar2);
  return 0;
}


