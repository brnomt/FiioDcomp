/**
 * FUN_03013880 @ 0x03013880
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03013880(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  bool bVar9;
  
  iVar2 = DAT_03013aec;
  uVar8 = 0;
  uVar4 = (uint)*(ushort *)(DAT_03013aec + (uint)*(ushort *)(DAT_03013aec + 0x1cc) * 0x38 + 0xc);
  if (*(short *)(DAT_03013ae0 + 0xc) == 0) {
    uVar6 = uVar4 - *(ushort *)(DAT_03013aec + (uint)*(ushort *)(DAT_03013aec + 0x1cc) * 2 + 0x1ce)
            & 0xffff;
  }
  else {
    iVar5 = FUN_02fec170();
    if (iVar5 == 0) {
      uVar4 = 1;
      uVar6 = uVar4;
    }
    else {
      uVar4 = 2;
      uVar6 = uVar4;
    }
  }
  uVar3 = DAT_03013af0;
  uVar7 = (uint)*(ushort *)(iVar2 + 0x1ee);
  if ((uVar4 != 0) && ((int)param_1 <= (int)(uVar4 - 1))) {
    bVar9 = uVar7 != param_1;
    uVar1 = DAT_03013af0;
    if (bVar9) {
      uVar7 = uVar6;
      uVar1 = uVar8;
    }
    uVar8 = uVar1;
    if (param_1 <= uVar7 && (bVar9 && uVar6 != param_1)) {
      *(ushort *)(iVar2 + 0x1f0) = *(ushort *)(iVar2 + 0x1ee);
      *(short *)(iVar2 + 0x1ee) =
           *(short *)(iVar2 + (uint)*(ushort *)(iVar2 + 0x1cc) * 2 + 0x1ce) + (short)param_1;
      MediaLib_GetTotalFiles(0x153);
      MediaLib_GetTotalFiles(0x150);
      FUN_03013826();
      FUN_02ffdd04();
      FUN_02ffa29c();
      uVar8 = uVar3;
    }
  }
  return uVar8;
}


