/**
 * FUN_030ad494 @ 0x030ad494
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_030ad494(undefined4 param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  byte abStack_78 [64];
  int local_38 [2];
  byte *local_30;
  int aiStack_2c [2];
  
  local_38[1] = 0;
  local_38[0] = 0;
  FUN_030ab3d6(DAT_030ad6dc,0,0x24);
  puVar2 = DAT_030ad6ec;
  *DAT_030ad6e8 = param_3;
  local_38[0] = param_3;
  iVar5 = (*(code *)*puVar2)(abStack_78,0x40,param_1);
  iVar6 = FUN_030ad412(abStack_78,iVar5);
  uVar3 = _DAT_030ad6f0;
  puVar1 = DAT_030ad6dc;
  if (iVar6 < 0) {
    uVar10 = FUN_030acaf4(*DAT_030ad6dc);
    uVar9 = puVar1[2];
    uVar11 = FUN_030acaf4(uVar9 * puVar1[3]);
    uVar10 = FUN_030aca16((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar10,
                          (int)((ulonglong)uVar10 >> 0x20));
    FUN_030ac932((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,uVar3);
    uVar7 = FUN_030acb16();
    puVar1[7] = uVar7;
    puVar1[8] = (uint)(puVar1[4] << 3) / uVar7;
    puVar1[4] = (uint)puVar1[4] / uVar9;
    return 0xffffffff;
  }
  local_38[0] = local_38[0] + iVar6;
  local_30 = abStack_78 + iVar6;
  aiStack_2c[0] = (iVar5 - iVar6) * 8;
  if (aiStack_2c[0] < 0x20) {
    hifi_debug_printf_ovl(s__less_bits_may_be_error_030ad6f3 + 1);
  }
  iVar5 = FUN_030ad2e0(local_38,&local_30,local_38 + 1,aiStack_2c);
  puVar4 = DAT_030ad710;
  if (iVar5 != -3) {
    local_38[1] = 0;
    (*(code *)*DAT_030ad710)(local_38[0],0,param_1);
    while( true ) {
      uVar8 = (*(code *)*puVar2)(abStack_78,0x40,param_1);
      iVar5 = FUN_030ad412(abStack_78,uVar8);
      if (iVar5 < 0) {
        uVar10 = FUN_030acaf4(*puVar1);
        uVar9 = puVar1[2];
        uVar11 = FUN_030acaf4(uVar9 * puVar1[3]);
        uVar10 = FUN_030aca16((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar10,
                              (int)((ulonglong)uVar10 >> 0x20));
        FUN_030ac932((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,uVar3);
        uVar7 = FUN_030acb16();
        puVar1[7] = uVar7;
        puVar1[8] = (uint)(puVar1[4] << 3) / uVar7;
        puVar1[4] = (uint)puVar1[4] / uVar9;
        return 0xffffffff;
      }
      puVar1[2] = puVar1[2] + 1;
      uVar7 = (abStack_78[iVar5 + 3] & 3) << 0xb | (uint)abStack_78[iVar5 + 4] << 3 |
              (uint)(abStack_78[iVar5 + 5] >> 5);
      puVar1[4] = puVar1[4] + uVar7;
      local_38[0] = iVar5 + uVar7 + local_38[0];
      if (param_2 <= local_38[0]) break;
      (*(code *)*puVar4)(local_38[0],0,param_1);
    }
    uVar10 = FUN_030acaf4(*puVar1);
    uVar9 = puVar1[2];
    uVar11 = FUN_030acaf4(uVar9 * puVar1[3]);
    uVar10 = FUN_030aca16((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar10,
                          (int)((ulonglong)uVar10 >> 0x20));
    FUN_030ac932((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,uVar3);
    uVar7 = FUN_030acb16();
    puVar1[7] = uVar7;
    puVar1[8] = (uint)(puVar1[4] << 3) / uVar7;
    puVar1[4] = (uint)puVar1[4] / uVar9;
    return 0;
  }
  return 0xfffffffd;
}


