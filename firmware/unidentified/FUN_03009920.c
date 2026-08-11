/**
 * FUN_03009920 @ 0x03009920
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03009920(void)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  psVar4 = DAT_03009ce4;
  iVar6 = DAT_03009cdc;
  piVar3 = DAT_03009cd8;
  if (*DAT_03009ce4 == 1) {
    iVar5 = FUN_02ff73d0(0xdf);
    if (iVar5 == 1) {
      iVar5 = *piVar3;
      *(undefined2 *)(iVar5 + (uint)*(ushort *)(iVar6 + 2) * 2 + 0x14) =
           *(undefined2 *)(iVar5 + 0xc);
      if (*(ushort *)(iVar5 + 0x12) < 0x1d) {
        *(ushort *)(iVar5 + 0x12) = *(ushort *)(iVar5 + 0x12) + 1;
      }
      return 1;
    }
    iVar5 = FUN_02ff73d0(0xe0);
    if (iVar5 == 1) {
      return 1;
    }
  }
  if (*psVar4 == 0) {
    iVar5 = FUN_02ff73d0(0xdf);
    if (iVar5 == 1) {
      iVar5 = *piVar3;
      uVar1 = *(ushort *)(iVar6 + 2);
      uVar2 = *(ushort *)(iVar5 + 0x12);
      if ((uint)uVar2 == (uint)uVar1) {
        uVar7 = 0;
        do {
          if (uVar7 != uVar1) {
            if (*(short *)(iVar5 + uVar7 * 2 + 0x14) != 0) {
              *(short *)(iVar5 + 0x54) = (short)uVar7;
              *(uint *)(iVar5 + 0xc) = (uint)*(ushort *)(iVar5 + uVar7 * 2 + 0x14);
              break;
            }
            *(undefined4 *)(iVar5 + 0xc) = 0x222e;
          }
          uVar7 = uVar7 + 1;
        } while ((int)uVar7 < 0x1e);
        if (uVar2 != 0) {
          *(ushort *)(iVar5 + 0x12) = uVar2 - 1;
        }
        FUN_03021672(0xac,1);
      }
      *(undefined2 *)(*piVar3 + (uint)*(ushort *)(iVar6 + 2) * 2 + 0x14) = 0;
      return 1;
    }
    iVar6 = FUN_02ff73d0(0xe0);
    if (iVar6 == 1) {
      return 1;
    }
  }
  return 0;
}


