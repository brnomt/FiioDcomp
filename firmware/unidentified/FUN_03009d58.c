/**
 * FUN_03009d58 @ 0x03009d58
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03009d58(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  int *piVar4;
  uint uVar5;
  ushort uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  undefined2 local_38;
  undefined2 local_36;
  undefined2 local_34;
  short local_32;
  short local_30;
  undefined2 local_2e;
  
  puVar3 = DAT_0300a130;
  uVar1 = *DAT_0300a130;
  uVar2 = DAT_0300a130[1];
  uVar7 = FUN_02ff2b38(1);
  uVar8 = FUN_02ff2b14(2);
  piVar4 = DAT_0300a134;
  *puVar3 = 0xffff;
  puVar3[1] = 0xffff;
  uVar5 = DAT_0300a138;
  iVar9 = *piVar4;
  if (*(short *)(iVar9 + 10) != 2) {
    local_38 = 0x43;
    local_36 = 0x48;
    local_34 = 0x3a;
    local_32 = (short)(uint)((ulonglong)DAT_0300a138 * (ulonglong)(*(ushort *)(iVar9 + 0x54) + 1) >>
                            0x23) + 0x30;
    uVar10 = *(ushort *)(iVar9 + 0x54) + 1;
    local_30 = (short)uVar10 +
               (short)(uint)((ulonglong)DAT_0300a138 * (ulonglong)uVar10 >> 0x23) * -10 + 0x30;
    local_2e = 0;
    FUN_02ff1ed8(100,0x42,&local_38);
  }
  iVar9 = *piVar4;
  local_38 = (undefined2)(*(uint *)(iVar9 + 0xc) / 10000);
  local_36 = (undefined2)((*(uint *)(iVar9 + 0xc) % 10000) / 1000);
  local_34 = (undefined2)((*(uint *)(iVar9 + 0xc) % 1000) * 0x29 >> 0xc);
  local_32 = (short)(uint)((ulonglong)uVar5 *
                           (ulonglong)
                           (*(uint *)(iVar9 + 0xc) +
                           (uint)((ulonglong)DAT_0300a13c * (ulonglong)*(uint *)(iVar9 + 0xc) >>
                                 0x25) * -100) >> 0x23);
  uVar6 = 0;
  do {
    uVar6 = uVar6 + 1;
  } while (uVar6 < 3);
  FUN_030098d8();
  if (200 < *(uint *)(DAT_0300a12c + 0xc)) {
    *(undefined4 *)(DAT_0300a12c + 0xc) = 0;
  }
  FUN_02fe2d80();
  FUN_02ff2b38(uVar7);
  puVar3[1] = uVar2;
  *puVar3 = uVar1;
  FUN_02ff2b14(uVar8);
  return;
}


