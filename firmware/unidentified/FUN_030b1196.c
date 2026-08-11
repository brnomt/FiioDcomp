/**
 * FUN_030b1196 @ 0x030b1196
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_030b1196(uint param_1)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  int local_38;
  int local_34;
  uint local_30 [2];
  int local_28;
  int local_24 [3];
  
  iVar6 = DAT_030b1518;
  iVar5 = DAT_030b1514;
  local_34 = 0;
  local_38 = 0;
  local_28 = 0;
  local_24[1] = 0;
  local_24[2] = 0;
  local_24[0] = 0;
  uVar9 = (param_1 / 1000) * *(int *)(DAT_030b1514 + 0xa4) +
          (*(int *)(DAT_030b1514 + 0xa4) * (param_1 % 1000)) / 1000;
  sVar1 = *(short *)(DAT_030b1514 + 0xd0);
  if (sVar1 == 2) {
    iVar8 = FUN_030b04f2(DAT_030b1514 + 0x2e0,DAT_030b1514,uVar9);
    *(int *)(iVar5 + 0x68) = iVar8;
    *(undefined4 *)(iVar5 + 0x30) = 0;
    *(int *)(iVar5 + 0x70) = iVar8;
    if (*(int *)(iVar5 + 0x7c) + 1 == iVar8) {
      *(undefined4 *)(iVar5 + 0x38) = 0;
      *(uint *)(iVar6 + 100) = param_1;
    }
    else {
      FUN_030b033e(iVar5 + 0x2e0,DAT_030b1514,iVar8,&local_28,&local_34);
      iVar8 = local_28;
      puVar10 = *(undefined4 **)(iVar6 + 0x3c);
      buffered_fseek(*puVar10,(local_28 - puVar10[2]) * 4 + -4,1);
      puVar10[2] = iVar8;
      buffered_fread(local_30,1,4,*puVar10);
      uVar7 = local_30[0] >> 8;
      uVar2 = local_30[0] >> 0x10;
      uVar3 = local_30[0] >> 0x18;
      uVar4 = local_30[0] << 0x18;
      FUN_030b03f0(iVar5 + 0x2e0,DAT_030b1514,&local_28,local_24 + 1,&local_38,local_24 + 2);
      local_24[0] = local_38 + local_34 + -2;
      iVar8 = FUN_030b0272(iVar5 + 0x2e0,DAT_030b1514,&local_38,local_24);
      *(uint *)(iVar5 + 0x34) =
           iVar8 + (uVar4 | (uVar7 & 0xff) << 0x10 | (uVar2 & 0xff) << 8 | uVar3);
      iVar8 = *(int *)(iVar5 + 0x68);
      uVar7 = *(uint *)(DAT_030b1514 + 0x84);
      if (uVar7 == 0) {
        puVar10 = *(undefined4 **)(iVar6 + 0x2c);
        buffered_fseek(*puVar10,(iVar8 - puVar10[2]) * 4 + -4,1);
        puVar10[2] = iVar8;
        buffered_fread(local_30,1,4,*puVar10);
        uVar7 = local_30[0] << 0x18 | (local_30[0] >> 8 & 0xff) << 0x10 |
                (local_30[0] >> 0x10 & 0xff) << 8 | local_30[0] >> 0x18;
      }
      *(uint *)(iVar5 + 0x38) = uVar7;
      uVar7 = *(uint *)(iVar5 + 0xa4);
      *(uint *)(iVar6 + 100) =
           ((uVar9 - uVar7 * (uVar9 / uVar7)) * 1000) / uVar7 + (uVar9 / uVar7) * 1000;
    }
  }
  else if ((sVar1 == 1 || sVar1 == 3) &&
          (iVar8 = FUN_030b04f2(DAT_030b1514 + 0x2e0,DAT_030b1514,uVar9),
          *(int *)(iVar5 + 0x7c) + 1 == iVar8)) {
    *(int *)(iVar5 + 0x68) = iVar8;
    *(undefined4 *)(iVar5 + 0x30) = 0;
    *(undefined4 *)(iVar5 + 0x38) = 0;
    *(int *)(iVar5 + 0x70) = iVar8;
    *(undefined4 *)(iVar6 + 100) = 0;
  }
  return 0;
}


