/**
 * FUN_03025f3e @ 0x03025f3e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Removing unreachable block (ram,0x030260c0) */
/* WARNING: Removing unreachable block (ram,0x030260c4) */
/* WARNING: Removing unreachable block (ram,0x030260f0) */
/* WARNING: Removing unreachable block (ram,0x03026146) */
/* WARNING: Removing unreachable block (ram,0x030260fc) */
/* WARNING: Removing unreachable block (ram,0x03026114) */

undefined4 FUN_03025f3e(char param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_r3;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint auStack_38 [5];
  
  iVar2 = (int)param_1;
  auStack_38[0] = 0;
  auStack_38[1] = 0;
  auStack_38[2] = 0;
  uVar3 = 0;
  uVar4 = 0;
  uVar5 = 0;
  uVar6 = 0;
  uVar7 = 0;
  uVar8 = 0;
  uVar9 = 0;
  uVar1 = FUN_02ffc9d6(auStack_38,8);
  if ((7 < uVar1) &&
     (auStack_38[0] =
           auStack_38[0] << 0x18 | (auStack_38[0] >> 8 & 0xff) << 0x10 |
           (auStack_38[0] >> 0x10 & 0xff) << 8 | auStack_38[0] >> 0x18, 7 < auStack_38[0])) {
    FUN_02ffcece(auStack_38[0] - 8,1,iVar2);
    auStack_38[3] = FUN_02ffce8c(iVar2);
    uStack_40 = 0;
    uStack_44 = 0;
    uStack_3c = 0;
    uVar1 = FUN_02ffc9d6(&uStack_44,8,iVar2,extraout_r3,0,0,0,uVar3,uVar4,uVar5,uVar6,uVar7,uVar8,
                         uVar9);
    if (uVar1 < 8) {
      return 0xffffffff;
    }
    FUN_02ffce6c(iVar2);
    uVar3 = FUN_02ff89ce(&uStack_40,&DAT_0302628c,4);
    return uVar3;
  }
  return 0xffffffff;
}


