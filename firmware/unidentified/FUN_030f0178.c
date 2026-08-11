/**
 * FUN_030f0178 @ 0x030f0178
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030f0178(uint *param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar2 = DAT_030f02e0;
  param_1[2] = (int)*(short *)(DAT_030f02e0 + 0x20);
  uVar1 = *(ushort *)(iVar2 + 0x50);
  param_1[3] = (uint)uVar1;
  param_1[5] = (uint)*(ushort *)(iVar2 + 0x52);
  *param_1 = (uint)*(ushort *)(iVar2 + 0x62);
  param_1[4] = uVar1 / 1000 - 1;
  if (*(int *)(iVar2 + 0x18) == 0) {
    uVar4 = *(uint *)(*(int *)(iVar2 + 0x10) + *(int *)(iVar2 + 0x14) * 0x20 + 0xc);
    *(undefined1 *)(DAT_030f02e8 + 4) = 0;
    param_1[0x227f] = 0;
    param_1[0x227e] = uVar4;
    if (*(int *)(iVar2 + 0x14) == *(int *)(iVar2 + 0x5c) + -1) {
      uVar5 = *(undefined4 *)(iVar2 + 0x58);
    }
    else {
      uVar5 = *(undefined4 *)(iVar2 + 0x54);
    }
    *(undefined4 *)(iVar2 + 0x18) = uVar5;
    FUN_030ed106(param_1 + 0x255,0,0x4000);
    FUN_030ed106(param_1 + 0x1255,0,0x4000);
    puVar3 = DAT_030f02ec;
    if (*(uint *)(iVar2 + 0x5c) <= *(uint *)(iVar2 + 0x14)) {
      return 0xffffffff;
    }
    iVar6 = (*(code *)*DAT_030f02f0)(*DAT_030f02ec);
    (*(code *)*DAT_030f02f4)
              (*(int *)(*(int *)(iVar2 + 0x10) + *(int *)(iVar2 + 0x14) * 0x20) - iVar6,1,*puVar3);
    for (iVar6 = *(int *)(*(int *)(iVar2 + 0x10) + *(int *)(iVar2 + 0x14) * 0x20 + 0x10); iVar6 != 0
        ; iVar6 = iVar6 + -1) {
      FUN_030f07ca(DAT_030f02e8);
    }
    uVar4 = FUN_030f0740(DAT_030f02e8);
    param_1[6] = uVar4;
    param_1[7] = 0;
    iVar6 = DAT_030f02e8;
    if ((0xeec < (int)param_1[2]) && ((param_1[6] & 0x80000000) != 0)) {
      param_1[6] = param_1[6] & 0x7fffffff;
      uVar4 = FUN_030f0740(iVar6);
      param_1[7] = uVar4;
    }
    param_1[9] = 0;
    param_1[0x225c] = 10;
    param_1[0x225d] = 0x4000;
    param_1[0x225e] = 10;
    param_1[0x225f] = 0x4000;
    FUN_030f07ca(DAT_030f02e8);
    uVar4 = FUN_030f07ca(DAT_030f02e8);
    param_1[0x225b] = uVar4;
    param_1[0x2258] = uVar4 >> 1;
    param_1[0x2259] = 0x80;
    FUN_030ed106(param_1 + 0x23,0,200);
    param_1[10] = (uint)(param_1 + 0x23);
    FUN_030ed0a6(param_1 + 0x11,DAT_030f02f8,0x10);
    FUN_030ed0a6(param_1 + 0x15,DAT_030f02f8,0x10);
    FUN_030ed106(param_1 + 0x19,0,0x28);
    param_1[0xe] = 0;
    param_1[0xd] = 0;
    param_1[0x10] = 0;
    param_1[0xf] = 0;
    param_1[0xc] = 0;
    param_1[0xb] = 0;
    if (1000 < (int)param_1[3]) {
      FUN_030f1934(0,0x1000);
      FUN_030eeeee(0,param_1[2],param_1[3]);
      FUN_030eeed8(0);
      FUN_030f196e(0);
      FUN_030f195c(0);
      FUN_030f1948(0);
      FUN_030f191c(0,0x1000);
    }
    *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + 1;
  }
  return 0;
}


