/**
 * FUN_030ca028 @ 0x030ca028
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030ca028(uint param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  
  for (uVar3 = 4; (1 << (uVar3 & 0xff) & param_1) == 0; uVar3 = uVar3 + 1) {
  }
  uVar3 = 0xd - uVar3;
  iVar10 = 2 << (uVar3 & 0xff);
  iVar6 = (int)param_1 >> 1;
  FUN_030c93d8(param_2,iVar6,iVar10);
  FUN_030c99e8(param_2,iVar6,uVar3);
  iVar2 = DAT_030ca288;
  uVar9 = 0;
  puVar4 = param_2 + iVar6;
  do {
    uVar1 = uVar9 & 0xff;
    uVar11 = uVar9 & 0xf;
    iVar6 = (int)uVar9 >> 8;
    uVar9 = uVar9 + 1;
    puVar8 = param_2 + ((int)((uint)*(byte *)(iVar2 + iVar6) |
                             (uint)*(byte *)(iVar2 + (uVar1 >> 4)) << 4 |
                             (uint)*(byte *)(iVar2 + uVar11) << 8) >> (uVar3 & 0xff));
    puVar5 = puVar4 + -2;
    if (puVar8 < puVar5) {
      uVar7 = *puVar8;
      *puVar8 = *puVar5;
      *puVar5 = uVar7;
      uVar7 = puVar8[1];
      puVar8[1] = puVar4[-1];
      puVar4[-1] = uVar7;
    }
    puVar4 = puVar5;
  } while (param_2 < puVar5);
  FUN_030c9c00(param_2,param_1,iVar10);
  FUN_030c9cdc(param_2,param_1,iVar10);
  return;
}


