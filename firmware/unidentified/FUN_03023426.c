/**
 * FUN_03023426 @ 0x03023426
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_03023426(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint extraout_r2;
  uint unaff_r4;
  uint extraout_r12;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  undefined4 local_20;
  uint local_1c;
  uint uStack_18;
  
  local_20 = *(uint *)(DAT_03023688 + 0x8c);
  local_1c = *(uint *)(DAT_03023688 + 0x90);
  uStack_18 = *(uint *)(DAT_03023688 + 0x94);
  iVar1 = FUN_02ffc9d6(&local_20,10);
  if (iVar1 < 1) {
    return 0;
  }
  uVar2 = local_20 & 0xff;
  bVar6 = uVar2 == 0x49;
  if (bVar6) {
    uVar2 = local_20 >> 8 & 0xff;
  }
  bVar7 = bVar6 && uVar2 == 0x44;
  if (bVar6 && uVar2 == 0x44) {
    bVar7 = local_20._2_1_ == '3';
  }
  if (bVar7) {
    bVar6 = 0xfe < (local_1c & 0xff);
    uVar2 = extraout_r2;
    if ((local_1c & 0xff) != 0xff) {
      uVar2 = local_1c >> 0x10 & 0xff;
      bVar6 = 0x7f < uVar2;
    }
    if (!bVar6) {
      bVar6 = local_1c >> 0x18 < 0x80;
      uVar5 = extraout_r12;
      if (bVar6) {
        uVar5 = uStack_18 & 0xff;
      }
      if (bVar6 && uVar5 < 0x80) {
        unaff_r4 = uStack_18 >> 8 & 0xff;
      }
      if ((bVar6 && uVar5 < 0x80) && unaff_r4 < 0x80) {
        uVar2 = unaff_r4 | uVar2 << 0x15 | (local_1c >> 0x18) << 0xe | uVar5 << 7;
        goto LAB_0302349e;
      }
    }
  }
  uVar2 = 0;
LAB_0302349e:
  if (uVar2 != 0) {
    iVar1 = FUN_03022b94(param_1,param_2);
    return iVar1;
  }
  thunk_FUN_03025648(param_1);
  thunk_FUN_030254a2();
  iVar1 = thunk_FUN_03025652();
  iVar3 = thunk_FUN_03025658();
  iVar4 = thunk_FUN_0302565e();
  if ((iVar1 < 0 || iVar3 < 0) || iVar4 < 0) {
    return 0;
  }
  *param_2 = iVar4;
  FUN_02ffcece(iVar1,0,(int)(char)param_1);
  return iVar3;
}


