/**
 * FUN_0302344a @ 0x0302344a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_0302344a(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                uint param_6,uint param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint unaff_r4;
  int *unaff_r6;
  uint in_r12;
  bool bVar5;
  bool bVar6;
  
  if (param_1 < 1) {
    return 0;
  }
  bVar5 = (char)param_5 == 'I';
  if (bVar5) {
    param_5._0_1_ = param_5._1_1_;
  }
  bVar6 = bVar5 && (char)param_5 == 'D';
  if (bVar5 && (char)param_5 == 'D') {
    bVar6 = param_5._2_1_ == '3';
  }
  if (bVar6) {
    bVar5 = 0xfe < (byte)param_6;
    if ((byte)param_6 != 0xff) {
      param_3 = param_6 >> 0x10 & 0xff;
      bVar5 = 0x7f < param_3;
    }
    if (!bVar5) {
      bVar5 = param_6 >> 0x18 < 0x80;
      if (bVar5) {
        in_r12 = param_7 & 0xff;
      }
      if (bVar5 && in_r12 < 0x80) {
        unaff_r4 = param_7 >> 8 & 0xff;
      }
      if ((bVar5 && in_r12 < 0x80) && unaff_r4 < 0x80) {
        uVar4 = unaff_r4 | param_3 << 0x15 | (param_6 >> 0x18) << 0xe | in_r12 << 7;
        goto LAB_0302349e;
      }
    }
  }
  uVar4 = 0;
LAB_0302349e:
  if (uVar4 != 0) {
    iVar1 = FUN_03022b94();
    return iVar1;
  }
  thunk_FUN_03025648();
  thunk_FUN_030254a2();
  iVar1 = thunk_FUN_03025652();
  iVar2 = thunk_FUN_03025658();
  iVar3 = thunk_FUN_0302565e();
  if ((iVar1 < 0 || iVar2 < 0) || iVar3 < 0) {
    return 0;
  }
  *unaff_r6 = iVar3;
  FUN_02ffcece(iVar1,0);
  return iVar2;
}


