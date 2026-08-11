/**
 * FUN_030c5f3e @ 0x030c5f3e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 * FUN_030c5f3e(int *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  bool bVar12;
  int local_40;
  
  iVar1 = *(int *)(*(int *)(*param_1 + 0x1c) + 0x30);
  iVar2 = *(int *)(DAT_030c62e0 + *(int *)(param_2 + 0x1a4) * 4 + -4);
  iVar3 = sbuf_read_bits(param_1 + 1,1);
  if (iVar3 != 1) {
    return (undefined4 *)0x0;
  }
  iVar3 = 0;
  for (uVar4 = iVar2 - 1; uVar4 != 0; uVar4 = uVar4 >> 1) {
    iVar3 = iVar3 + 1;
  }
  uVar5 = sbuf_read_bits(param_1 + 1,iVar3);
  *param_3 = uVar5;
  iVar3 = 0;
  for (uVar4 = iVar2 - 1; uVar4 != 0; uVar4 = uVar4 >> 1) {
    iVar3 = iVar3 + 1;
  }
  uVar5 = sbuf_read_bits(param_1 + 1,iVar3);
  param_3[1] = uVar5;
  local_40 = 0;
  iVar3 = 2;
  if (0 < *(int *)(param_2 + 0x19c)) {
    do {
      uVar4 = 0;
      iVar8 = (uint)*(byte *)(local_40 + param_2 + 0x37) * 0xb;
      iVar11 = iVar8 + param_2;
      uVar10 = (uint)*(byte *)(param_2 + iVar8);
      uVar9 = (uint)*(byte *)(iVar11 + 1);
      if ((uVar9 != 0) &&
         (uVar4 = FUN_030c3a42(iVar1 + (uint)*(byte *)(iVar11 + 2) * 0x40,param_1 + 1),
         uVar4 == 0xffffffff)) {
        return (undefined4 *)0x0;
      }
      iVar8 = 0;
      if (uVar10 != 0) {
        do {
          uVar6 = (1 << uVar9) - 1U & uVar4;
          uVar4 = (int)uVar4 >> uVar9;
          uVar6 = (uint)*(byte *)(uVar6 + iVar11 + 3);
          if (uVar6 == 0xff) {
            param_3[iVar3 + iVar8] = 0;
          }
          else {
            iVar7 = FUN_030c3a42(iVar1 + uVar6 * 0x40,param_1 + 1);
            param_3[iVar3 + iVar8] = iVar7;
            if (iVar7 == -1) {
              return (undefined4 *)0x0;
            }
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < (int)uVar10);
      }
      iVar3 = iVar3 + uVar10;
      local_40 = local_40 + 1;
    } while (local_40 < *(int *)(param_2 + 0x19c));
  }
  iVar1 = 2;
  if (2 < *(int *)(param_2 + 0x1a0)) {
    do {
      iVar8 = param_2 + iVar1;
      uVar4 = (uint)*(ushort *)(param_2 + (uint)*(byte *)(iVar8 + 0x158) * 2 + 0x58);
      iVar3 = (*(ushort *)(param_3 + *(byte *)(iVar8 + 0x119)) & 0x7fff) -
              (*(ushort *)(param_3 + *(byte *)(iVar8 + 0x158)) & 0x7fff);
      bVar12 = iVar3 < 0;
      if (bVar12) {
        iVar3 = -iVar3;
      }
      iVar3 = (int)((*(ushort *)(param_2 + iVar1 * 2 + 0x58) - uVar4) * iVar3) /
              (int)(*(ushort *)(param_2 + (uint)*(byte *)(iVar8 + 0x119) * 2 + 0x58) - uVar4);
      if (bVar12) {
        iVar3 = -iVar3;
      }
      uVar9 = (*(ushort *)(param_3 + *(byte *)(iVar8 + 0x158)) & 0x7fff) + iVar3;
      uVar10 = iVar2 - uVar9;
      uVar4 = uVar10;
      if ((int)uVar9 <= (int)uVar10) {
        uVar4 = uVar9;
      }
      uVar6 = param_3[iVar1];
      if (uVar6 == 0) {
        param_3[iVar1] = uVar9 | 0x8000;
      }
      else {
        if ((int)uVar6 < (int)(uVar4 * 2)) {
          if ((uVar6 & 1) == 0) {
            uVar6 = (int)uVar6 >> 1;
          }
          else {
            uVar6 = -((int)(uVar6 + 1) >> 1);
          }
        }
        else if ((int)uVar9 < (int)uVar10) {
          uVar6 = uVar6 - uVar9;
        }
        else {
          uVar6 = ~(uVar6 - uVar10);
        }
        param_3[iVar1] = uVar9 + uVar6;
        param_3[*(byte *)(iVar8 + 0x158)] = *(ushort *)(param_3 + *(byte *)(iVar8 + 0x158)) & 0x7fff
        ;
        param_3[*(byte *)(iVar8 + 0x119)] = *(ushort *)(param_3 + *(byte *)(iVar8 + 0x119)) & 0x7fff
        ;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_2 + 0x1a0));
  }
  return param_3;
}


