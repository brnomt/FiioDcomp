/**
 * FUN_0305006e @ 0x0305006e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4
FUN_0305006e(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int *param_7)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  if (param_1 == 0 && param_2 == 0) {
    return 0;
  }
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if (param_2 == 0) {
    return 1;
  }
  if (param_7 != (int *)0x0) {
    *param_7 = 0;
  }
  iVar4 = 0;
  iVar5 = 0;
LAB_03050154:
  if ((param_5 <= iVar4) && (param_5 != 0x7fffffff)) {
    return 0;
  }
  uVar3 = (uint)*(byte *)(param_2 + iVar5);
  bVar1 = *(byte *)(param_1 + iVar4);
  while (uVar7 = (uint)bVar1, uVar7 != 0) {
    if ((param_3 == 0) || (uVar7 < 0x80)) {
      if (param_6 == 0) break;
      uVar6 = uVar7 - 0x61;
      bVar8 = 0x19 < uVar6;
      if (bVar8) {
        uVar6 = uVar7 - 0x41;
      }
      if (!bVar8 || uVar6 < 0x1a) break;
    }
    iVar4 = iVar4 + 1;
    if (param_5 != 0x7fffffff) {
      param_5 = param_5 + 1;
    }
    bVar1 = *(byte *)(param_1 + iVar4);
  }
  do {
    if (uVar3 == 0) break;
    if ((param_3 == 0) || (uVar3 < 0x80)) {
      if (param_6 == 0) break;
      uVar6 = uVar3 - 0x61;
      bVar8 = 0x19 < uVar6;
      if (bVar8) {
        uVar6 = uVar3 - 0x41;
      }
      if (!bVar8 || uVar6 < 0x1a) break;
    }
    iVar5 = iVar5 + 1;
    uVar3 = (uint)*(byte *)(param_2 + iVar5);
  } while( true );
  if (param_4 != 0) {
    if (uVar7 - 0x41 < 0x1a) {
      uVar7 = uVar7 + 0x20 & 0xff;
    }
    if (uVar3 - 0x41 < 0x1a) {
      uVar3 = uVar3 + 0x20 & 0xff;
    }
  }
  if (uVar7 != uVar3) {
    if (uVar7 < uVar3) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 1;
    }
    return uVar2;
  }
  if (uVar7 == 0) {
    return 0;
  }
  if (param_7 != (int *)0x0) {
    *param_7 = *param_7 + 1;
  }
  iVar4 = iVar4 + 1;
  iVar5 = iVar5 + 1;
  goto LAB_03050154;
}


