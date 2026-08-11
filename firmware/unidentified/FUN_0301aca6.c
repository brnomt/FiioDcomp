/**
 * FUN_0301aca6 @ 0x0301aca6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301aca6(short param_1)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  
  puVar2 = DAT_0301ad00;
  iVar1 = DAT_0301ace0;
  if (((uint)*DAT_0301ad00 <= *(uint *)(DAT_0301ace0 + 0xc)) && (*(int *)(DAT_0301ace0 + 8) != 1)) {
    *(undefined4 *)(DAT_0301ace0 + 0xc) = 0;
  }
  FUN_02ffe6d4(DAT_0301ad00,(int)param_1);
  if ((uint)*puVar2 <= *(uint *)(iVar1 + 0xc)) {
    *(undefined4 *)(iVar1 + 0xc) = 0;
  }
  iVar3 = FUN_0301abb2(0x11a,0);
  if (iVar3 != 0) {
    *(undefined2 *)(iVar1 + 4) = 4;
    FUN_03008eb4(0x130);
    return 0;
  }
  return 1;
}


