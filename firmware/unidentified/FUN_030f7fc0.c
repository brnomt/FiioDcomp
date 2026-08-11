/**
 * FUN_030f7fc0 @ 0x030f7fc0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030f7fc0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  
  puVar1 = DAT_030f80c0;
  *DAT_030f80c0 = param_1;
  iVar3 = FUN_030f7548();
  if (iVar3 == 0) {
    return -1;
  }
  uVar6 = (uint)*(ushort *)(puVar1 + 4);
  puVar1[0xc] = uVar6;
  puVar2 = DAT_030f80c4;
  uVar5 = puVar1[2];
  puVar1[0x10] = uVar5;
  if (uVar5 == 0x2b1100) {
    *puVar2 = 0;
    puVar1[0xe] = 0xac44;
  }
  else {
    if (uVar5 == 0x562200) {
      puVar1[0xe] = 0xac44;
      uVar4 = 1;
    }
    else {
      if (uVar5 != 0xac4400) {
        if (uVar5 == 0x1588800) {
          puVar1[0xe] = 8000;
          *puVar2 = 3;
        }
        goto LAB_030f802e;
      }
      puVar1[0xe] = 0xac44;
      uVar4 = 2;
    }
    *puVar2 = uVar4;
  }
LAB_030f802e:
  *(undefined2 *)(puVar1 + 0x11) = 0x20;
  uVar8 = puVar1[0xe];
  uVar7 = puVar1[9];
  puVar1[0x12] = uVar5 * uVar6;
  uVar9 = FUN_030f67e4(uVar6 * uVar5);
  uVar10 = FUN_030f67e4(uVar7 * 8000);
  uVar9 = FUN_030f6706((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar9,
                       (int)((ulonglong)uVar9 >> 0x20));
  *DAT_030f80c8 = uVar9;
  FUN_030f7c6e(DAT_030f80cc,uVar6,uVar5,uVar8);
  return (int)(uVar7 / (uVar5 / uVar8 >> 3)) / (int)uVar6;
}


