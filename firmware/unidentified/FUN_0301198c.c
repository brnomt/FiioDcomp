/**
 * FUN_0301198c @ 0x0301198c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301198c(int param_1,int param_2)

{
  byte bVar1;
  int unaff_r4;
  int unaff_r5;
  undefined1 unaff_r6;
  bool bVar2;
  
  if (param_2 == 2) {
    bVar1 = *(byte *)(unaff_r4 + 1);
    if (0xd < bVar1) {
      return;
    }
    bVar2 = param_1 == 0 && bVar1 == 1;
    if (param_1 == 0 && bVar1 == 1) {
      bVar2 = *(char *)(unaff_r5 + 1) == '\0';
    }
    if (bVar2) {
      return;
    }
    bVar1 = bVar1 + 1;
    *(byte *)(unaff_r4 + 1) = bVar1;
    *(char *)(unaff_r5 + (uint)bVar1) = (char)param_1;
    *(undefined1 *)(unaff_r5 + (uint)bVar1 + 1) = unaff_r6;
  }
  FUN_03011192(1);
  FUN_02ffff38(0x33);
  return;
}


