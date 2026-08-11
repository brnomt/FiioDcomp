/**
 * FUN_0308d814 @ 0x0308d814
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_0308d814(uint *param_1,int param_2,undefined4 param_3,int param_4)

{
  byte *pbVar1;
  byte *pbVar2;
  ushort *puVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iStack_58;
  ushort **ppuStack_54;
  ushort *local_50;
  uint uStack_4c;
  undefined1 auStack_48 [20];
  uint *puStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  
  local_50 = (ushort *)0x0;
  if (param_1 == (uint *)0x0) {
    return 2;
  }
  uVar10 = param_2 - 0x18;
  uVar9 = param_4 + 0x18;
  if (0x3f < uVar10) {
    ppuStack_54 = &local_50;
    iStack_58 = 4;
    puStack_34 = param_1;
    iStack_30 = param_2;
    uStack_2c = param_3;
    iStack_28 = param_4;
    iVar6 = wma_input_cache_read
                      (param_1,param_1[1],*param_1 + param_4 + 0x54U,
                       (uint)(0xffffffc3 < uVar9) + param_1[1] +
                       (uint)CARRY4(*param_1,param_4 + 0x54U));
    if ((iVar6 == 4) && (local_50 != (ushort *)0x0)) {
      uVar5 = *local_50;
      iVar6 = 0x40;
      uVar4 = local_50[1];
      local_50 = local_50 + 2;
      if (uVar5 != 0) {
        iVar12 = 0;
        uStack_4c = (uint)uVar5;
        do {
          if (uVar10 < iVar6 + 4U) {
            return 3;
          }
          ppuStack_54 = &local_50;
          iStack_58 = 2;
          uVar8 = uVar9 + iVar6 + 2U;
          iVar7 = wma_input_cache_read
                            (param_1,param_1[1],*param_1 + uVar8,
                             param_1[1] +
                             (uint)CARRY4(uVar9,iVar6 + 2U) + (uint)CARRY4(*param_1,uVar8));
          if (iVar7 != 2) {
            return 3;
          }
          if (local_50 == (ushort *)0x0) {
            return 3;
          }
          uVar5 = *local_50;
          local_50 = local_50 + 1;
          iVar6 = iVar6 + 4 + (uint)uVar5;
          iVar12 = iVar12 + 1;
        } while (iVar12 < (int)uStack_4c);
      }
      if (uVar4 != 0) {
        iVar12 = 0;
        uStack_4c = (uint)uVar4;
        do {
          if (uVar10 < iVar6 + 0x16U) {
            return 3;
          }
          ppuStack_54 = &local_50;
          iStack_58 = 4;
          uVar8 = uVar9 + iVar6 + 0x12U;
          iVar7 = wma_input_cache_read
                            (param_1,param_1[1],*param_1 + uVar8,
                             param_1[1] +
                             (uint)CARRY4(uVar9,iVar6 + 0x12U) + (uint)CARRY4(*param_1,uVar8));
          if (iVar7 != 4) {
            return 3;
          }
          if (local_50 == (ushort *)0x0) {
            return 3;
          }
          uVar5 = *local_50;
          pbVar2 = (byte *)((int)local_50 + 3);
          puVar3 = local_50 + 1;
          pbVar1 = (byte *)((int)local_50 + 1);
          local_50 = local_50 + 2;
          iVar6 = iVar6 + 0x16 +
                  (uint)(byte)uVar5 + (uint)*pbVar2 * 0x1000000 +
                  (uint)(byte)*puVar3 * 0x10000 + (uint)*pbVar1 * 0x100;
          iVar12 = iVar12 + 1;
        } while (iVar12 < (int)uStack_4c);
      }
      if (iVar6 + 0x18U < uVar10) {
        iVar12 = FUN_0308ca7c(param_1,auStack_48,&iStack_58,uVar9 + iVar6);
        if (iVar12 != 0) {
          return iVar12;
        }
        iVar12 = wma_memcmp(*DAT_0308dd8c,auStack_48,0x10);
        if ((iVar12 == 0) || (iVar12 = wma_memcmp(*DAT_0308dd90,auStack_48,0x10), iVar12 == 0)) {
          uVar8 = *param_1;
          uVar11 = param_1[1];
          uVar9 = uVar9 + iVar6 + 0x18;
          uVar10 = uVar8 + uVar9;
          uVar9 = uVar11 + CARRY4(uVar8,uVar9);
          *param_1 = uVar10;
          param_1[1] = uVar9;
          uVar9 = uVar9 + CARRY4(uVar10,iStack_58 - 0x18U);
          if (param_1[0xb] <= uVar9 &&
              (uint)(uVar10 + (iStack_58 - 0x18U) <= param_1[10]) <= param_1[0xb] - uVar9) {
            return 1;
          }
          iVar6 = wma_audio_parse(param_1,iStack_58,uStack_2c);
          if (iVar6 != 0) {
            return iVar6;
          }
          *param_1 = uVar8;
          param_1[1] = uVar11;
        }
      }
      return 0;
    }
  }
  return 3;
}


