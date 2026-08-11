/**
 * FUN_03004626 @ 0x03004626
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03004626(int param_1)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int *unaff_r4;
  int unaff_r5;
  int unaff_r6;
  int unaff_r7;
  
  do {
    if (param_1 == 0) {
      uVar1 = *(ushort *)(unaff_r5 + 4);
      uVar4 = (uint)uVar1;
      iVar3 = unaff_r6 + uVar4;
      if (*(char *)(iVar3 + 6) != ':') {
        *unaff_r4 = DAT_03004708 + (uint)*(byte *)(iVar3 + 4) * 10 +
                    (uint)*(byte *)(iVar3 + 5) +
                    (unaff_r7 + (*(byte *)(iVar3 + 1) - 0x30) * 10 +
                    (uint)*(byte *)(uVar4 + unaff_r6 + 2)) * 0x3c;
        sVar2 = 5;
LAB_030046ce:
        *(ushort *)(unaff_r5 + 4) = uVar1 + sVar2;
        return 0;
      }
      if ((*(byte *)(iVar3 + 7) - 0x30 < 10) && (*(byte *)(iVar3 + 8) - 0x30 < 10)) {
        *unaff_r4 = ((uint)*(byte *)(iVar3 + 5) + (*(byte *)(iVar3 + 4) - 0x30) * 10) * 0x3c +
                    (uint)*(byte *)(iVar3 + 7) * 10 +
                    (uint)*(byte *)(iVar3 + 8) +
                    (unaff_r7 + (*(byte *)(iVar3 + 1) - 0x30) * 10 +
                    (uint)*(byte *)(uVar4 + unaff_r6 + 2)) * 0xe10 + -0xd50;
        sVar2 = 8;
        goto LAB_030046ce;
      }
      param_1 = FUN_03004338();
    }
    if (param_1 == -1) {
      return 0xffffffff;
    }
    param_1 = FUN_03004382();
  } while( true );
}


