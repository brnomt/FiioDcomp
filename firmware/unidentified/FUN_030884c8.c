/**
 * FUN_030884c8 @ 0x030884c8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030884c8(int param_1,undefined4 param_2,int param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  short *psVar8;
  uint unaff_r7;
  int iVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  int local_68;
  int iStack_64;
  int local_60;
  int local_5c;
  int local_54;
  uint local_50;
  int local_4c;
  int local_48;
  int iStack_44;
  uint local_3c;
  uint local_38;
  int local_34;
  int iStack_30;
  undefined4 local_2c;
  int local_28;
  
  iVar7 = 0;
  psVar8 = (short *)(param_1 + 0x6c);
  iVar11 = *(int *)(param_3 + 0x44);
  iVar10 = -1;
  iVar2 = DAT_030889e8;
  if ((0 < *(int *)(param_1 + 0x7c)) && (0 < *(short *)(param_3 + 0x80))) {
    local_5c = (*(int *)(param_1 + 0x7c) << 0xc) / (int)*(short *)(param_3 + 0x80);
    iStack_30 = param_1;
    local_2c = param_2;
    local_28 = param_3;
    local_4c = wma_floor_log2();
    iVar2 = wma_floor_log2(*(int *)(param_1 + 0x9c) / *(int *)(param_1 + 0x7c));
    iVar9 = *(int *)(param_1 + 0xec) + iVar2 * 0x74;
    iVar2 = wma_floor_log2(*(int *)(param_1 + 0x9c) / *(int *)(param_1 + 0x7c));
    iVar3 = *(int *)(*(int *)(param_1 + 0xe8) + iVar2 * 4);
    local_54 = (int)(short)(*(short *)(local_28 + 0x2c) + -1);
    iVar2 = *(int *)(iVar9 + 4);
    while (iVar2 <= *psVar8 * local_5c >> 0xc) {
      iVar7 = iVar7 + 1;
      iVar2 = *(int *)(iVar9 + iVar7 * 4 + 4);
    }
    iVar4 = (**(code **)(param_1 + 0x164))(local_2c,local_28);
    iVar2 = iVar4;
    if (-1 < iVar4) {
      *psVar8 = *(short *)(param_1 + 0x14) + 1 + *psVar8;
      local_34 = 1 << (local_4c - 0xdU & 0xff);
      local_38 = local_4c - 0xc;
      local_3c = 0xc - local_4c;
      while( true ) {
        iVar6 = (int)*psVar8;
        bVar12 = SBORROW4(iVar6,local_54);
        iVar2 = iVar6 - local_54;
        if (iVar6 < local_54) {
          bVar12 = SBORROW4(iVar7,iVar3);
          iVar2 = iVar7 - iVar3;
        }
        if (iVar2 < 0 == bVar12) break;
        iVar2 = *(int *)(iVar9 + iVar7 * 4 + 4);
        while (iVar2 <= iVar6 * local_5c >> 0xc) {
          iVar7 = iVar7 + 1;
          iVar2 = *(int *)(iVar9 + iVar7 * 4 + 4);
        }
        if (iVar3 <= iVar7) break;
        if (iVar6 == iVar10) {
          iVar2 = (int)((ulonglong)
                        ((longlong)(int)((uint)*(ushort *)(param_1 + 0x18) << 0x10) *
                        (longlong)local_60) >> 0x20) << 1;
          if ((int)unaff_r7 < 0) {
            uVar5 = iVar2 << (-unaff_r7 & 0xff);
          }
          else {
            uVar5 = iVar2 >> (unaff_r7 & 0xff);
          }
          FUN_03087aee(&local_48,param_1,local_28,iVar7);
          unaff_r7 = local_48 - 0x14;
        }
        else {
          FUN_03087aee(&local_48,param_1,local_28,iVar7);
          unaff_r7 = local_48 - 0x14;
          iVar2 = (int)((ulonglong)
                        ((longlong)(int)((uint)*(ushort *)(param_1 + 0x18) << 0x10) *
                        (longlong)iStack_44) >> 0x20) << 1;
          if ((int)unaff_r7 < 0) {
            uVar5 = iVar2 << (-unaff_r7 & 0xff);
          }
          else {
            uVar5 = iVar2 >> (unaff_r7 & 0xff);
          }
        }
        iVar2 = iVar9 + iVar7 * 4;
        if (local_4c < 0xd) {
          sVar1 = *(short *)(iVar2 + 4) << (local_3c & 0xff);
        }
        else {
          sVar1 = (short)(*(int *)(iVar2 + 4) + local_34 >> (local_38 & 0xff));
        }
        iVar10 = (int)(short)(sVar1 + -1);
        if (local_54 < (short)(sVar1 + -1)) {
          iVar10 = local_54;
        }
        local_50 = -unaff_r7;
        local_60 = iStack_44;
        while( true ) {
          *(uint *)(iVar11 + *psVar8 * 4) =
               (*(uint *)(param_1 + 0x1c) ^ uVar5) - *(uint *)(param_1 + 0x1c);
          iVar4 = (**(code **)(param_1 + 0x164))(local_2c,local_28);
          if (iVar4 < 0) {
            return iVar4;
          }
          sVar1 = *(short *)(param_1 + 0x14) + 1 + *psVar8;
          *psVar8 = sVar1;
          if (iVar10 <= sVar1) break;
          iVar2 = (int)((ulonglong)
                        ((longlong)(int)((uint)*(ushort *)(param_1 + 0x18) << 0x10) *
                        (longlong)local_60) >> 0x20) << 1;
          if ((int)unaff_r7 < 0) {
            uVar5 = iVar2 << (local_50 & 0xff);
          }
          else {
            uVar5 = iVar2 >> (unaff_r7 & 0xff);
          }
        }
        iVar7 = iVar7 + 1;
      }
      if (*psVar8 == local_54) {
        if (iVar10 <= iVar6) {
          for (; (iVar7 + -1 < iVar3 && (*(int *)(iVar9 + iVar7 * 4) <= iVar6 * local_5c >> 0xc));
              iVar7 = iVar7 + 1) {
          }
          if (iVar7 + -1 <= iVar3) {
            FUN_03087aee(&local_68,param_1,local_28,iVar7 + -1);
            unaff_r7 = local_68 - 0x14;
            local_60 = iStack_64;
          }
        }
        iVar7 = (int)((ulonglong)
                      ((longlong)(int)((uint)*(ushort *)(param_1 + 0x18) << 0x10) *
                      (longlong)local_60) >> 0x20) << 1;
        if ((int)unaff_r7 < 0) {
          uVar5 = iVar7 << (-unaff_r7 & 0xff);
        }
        else {
          uVar5 = iVar7 >> (unaff_r7 & 0xff);
        }
        *(uint *)(iVar11 + *psVar8 * 4) =
             (uVar5 ^ *(uint *)(param_1 + 0x1c)) - *(uint *)(param_1 + 0x1c);
      }
      iVar2 = DAT_030889e8;
      if ((*psVar8 <= *(short *)(local_28 + 0x80)) && (iVar2 = iVar4, -1 < iVar4)) {
        if (0 < *(int *)(param_1 + 0xa4)) {
          wma_memclr(iVar11,*(int *)(param_1 + 0xa4) << 2);
        }
        wma_memclr(iVar11 + *(int *)(param_1 + 0x158) * 4,
                   ((int)*(short *)(local_28 + 0x82) - *(int *)(param_1 + 0x158)) * 4);
      }
    }
  }
  return iVar2;
}


