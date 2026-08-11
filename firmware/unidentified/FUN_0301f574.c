/**
 * FUN_0301f574 @ 0x0301f574
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301f574(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0301e818();
  iVar2 = bitreader_peek(param_1,iVar1);
  if (((1 << (iVar1 - 1U & 0xff)) + -1 == iVar2) &&
     (iVar1 = FUN_0301e828(param_1,param_2 + 0x11), iVar1 == 1)) {
    return 1;
  }
  return 0;
}


