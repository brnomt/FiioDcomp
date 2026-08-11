/**
 * FUN_0301e8f2 @ 0x0301e8f2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301e8f2(undefined4 param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = DAT_0301eae0;
  iVar4 = 0;
  iVar6 = 0;
  do {
    iVar3 = bitreader_peek(param_1,8);
    bitreader_refill(param_1,8);
    iVar5 = iVar4 + 1;
    *(char *)(param_2 + (uint)*(byte *)(iVar2 + iVar4)) = (char)iVar3;
    if (iVar3 == 0) {
      if (0x3f < iVar4) {
        return;
      }
      do {
        pbVar1 = (byte *)(iVar2 + iVar4);
        iVar4 = iVar4 + 1;
        *(char *)(param_2 + (uint)*pbVar1) = (char)iVar6;
      } while (iVar4 < 0x40);
      return;
    }
    iVar4 = iVar5;
    iVar6 = iVar3;
  } while (iVar5 < 0x40);
  return;
}


