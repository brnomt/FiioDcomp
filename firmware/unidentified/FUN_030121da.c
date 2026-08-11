/**
 * FUN_030121da @ 0x030121da
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


bool FUN_030121da(int param_1,uint param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  
  if (param_2 != 6) {
    bVar2 = *DAT_03012214;
    pbVar1 = DAT_03012214;
    while ((bVar2 != 6 &&
           (iVar3 = FUN_02ff307c(param_1 + 8,*(undefined4 *)(pbVar1 + 4),0x20), iVar3 != 1))) {
      pbVar1 = pbVar1 + 8;
      bVar2 = *pbVar1;
    }
    return *pbVar1 == param_2;
  }
  return true;
}


