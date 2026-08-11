/**
 * FUN_03084412 @ 0x03084412
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_03084412(int *param_1,int param_2)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint local_38 [3];
  int local_2c [2];
  int local_24;
  
  local_24 = 0;
  local_2c[0] = 0;
  piVar7 = param_1 + 0x21;
  iVar6 = *param_1;
  cVar1 = (char)param_1[9];
  if (cVar1 == '\0') {
LAB_03084466:
    iVar5 = FUN_03084a2c(*(undefined4 *)(param_2 + 0x18),piVar7,local_38,local_2c,&local_24);
    if (iVar5 < 0) {
      return iVar5;
    }
    iVar5 = FUN_030848dc(piVar7,local_38[0]);
    if (iVar5 < 0) {
      return iVar5;
    }
    if (local_2c[0] != 0) {
      if (local_2c[0] == 1) {
        *(undefined4 *)(iVar6 + 0x18) = 0;
        *(int *)(iVar6 + 0x14) =
             (int)(short)((*(short *)(param_2 + 0x2c) - *(short *)(iVar6 + 0x6c)) + -1);
        return iVar5;
      }
      iVar5 = FUN_030848dc(piVar7,1);
      if (iVar5 < 0) {
        return iVar5;
      }
      uVar3 = (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x1c),local_2c[0] + -2);
      *(uint *)(iVar6 + 0x14) = uVar3 & 0x7fffffff;
      uVar4 = (**(code **)(param_2 + 0x28))(*(undefined4 *)(param_2 + 0x20),local_2c[0] + -2);
      *(undefined4 *)(iVar6 + 0x18) = uVar4;
      *(int *)(iVar6 + 0x1c) = -1 - (local_24 >> 0x1f);
      return iVar5;
    }
    *(undefined1 *)(param_1 + 9) = 5;
  }
  else {
    if (cVar1 == '\x04') {
      iVar5 = wma_bitreader_getbits(piVar7,1,local_38);
      if (iVar5 < 0) {
        return iVar5;
      }
      FUN_03084338(param_1,param_2,(int)(short)local_38[0]);
      *(undefined1 *)(param_1 + 9) = 0;
      goto LAB_03084466;
    }
    if (cVar1 != '\x05') {
      if (cVar1 != '\x06') {
        return 0;
      }
      goto LAB_030844e4;
    }
  }
  iVar5 = wma_bitreader_getbits(piVar7,*(undefined2 *)(iVar6 + 0x38),local_38);
  if (iVar5 < 0) {
    return iVar5;
  }
  *(uint *)(iVar6 + 0x18) = local_38[0];
  *(undefined1 *)(param_1 + 9) = 6;
LAB_030844e4:
  iVar5 = wma_bitreader_getbits(piVar7,*(short *)(iVar6 + 0x94) + 1,local_38);
  if (-1 < iVar5) {
    sVar2 = *(short *)(*param_1 + 0x94);
    *(uint *)(iVar6 + 0x1c) = (local_38[0] & 1) - 1;
    *(uint *)(iVar6 + 0x14) =
         (int)((local_38[0] & 0xffffffffU >> (0x20 - (ushort)(sVar2 + 1) & 0xff)) << 0x10) >> 0x11 &
         0x7fffffff;
    *(undefined1 *)(param_1 + 9) = 0;
  }
  return iVar5;
}


