/**
 * FUN_030f7a94 @ 0x030f7a94
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030f7a94(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  puVar1 = DAT_030f7af8;
  uVar3 = (*(code *)*DAT_030f7b04)(*DAT_030f7af8);
  puVar2 = DAT_030f7b00;
  uVar5 = ((uint)((longlong)param_1 * (longlong)(int)puVar1[0x12]) >> 3 |
          (int)((ulonglong)((longlong)param_1 * (longlong)(int)puVar1[0x12]) >> 0x20) << 0x1d) +
          puVar1[6];
  if ((uVar5 <= uVar3) && (iVar4 = (*(code *)*DAT_030f7b00)(uVar5,0,*puVar1), iVar4 == 0)) {
    uVar3 = puVar1[9];
    iVar4 = (uVar5 - puVar1[6]) - uVar3 * ((uVar5 - puVar1[6]) / uVar3);
    if (iVar4 != 0) {
      uVar5 = uVar5 + (uVar3 - iVar4);
    }
    iVar4 = (*(code *)*puVar2)(uVar5,0,*puVar1);
    if (iVar4 == 0) {
      puVar1[0xb] = uVar5 / (uint)puVar1[9];
      return 0;
    }
  }
  return 0xffffffff;
}


