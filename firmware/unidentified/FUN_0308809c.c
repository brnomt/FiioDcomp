/**
 * FUN_0308809c @ 0x0308809c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0308809c(int *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int aiStack_2c0 [90];
  short asStack_158 [112];
  undefined1 auStack_78 [68];
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  wma_memmove(auStack_78,DAT_03088380,0x44);
  local_34 = *(undefined4 *)(DAT_03088380 + 0x44);
  uStack_30 = *(undefined4 *)(DAT_03088380 + 0x48);
  uStack_2c = *(undefined4 *)(DAT_03088380 + 0x4c);
  uStack_28 = *(undefined4 *)(DAT_03088380 + 0x50);
  local_24 = *(undefined4 *)(DAT_03088380 + 0x54);
  uStack_20 = *(undefined4 *)(DAT_03088380 + 0x58);
  uStack_1c = *(undefined4 *)(DAT_03088380 + 0x5c);
  uStack_18 = *(undefined4 *)(DAT_03088380 + 0x60);
  local_14 = *(undefined4 *)(DAT_03088380 + 100);
  iVar1 = param_2 >> 3;
  if (0x11 < param_2) {
    if (param_2 < 0x92) {
      iVar2 = *(int *)(*DAT_0308838c + param_2 * 4 + -0x48);
      iVar1 = 0x18 - iVar1;
      do {
        if (0x1ffffffe < iVar2) goto joined_r0x0308815c;
        iVar2 = iVar2 * 4;
        iVar1 = iVar1 + 2;
      } while (iVar2 != 0);
    }
    else {
      if (0xa2 < param_2) {
        iVar2 = -1;
        iVar1 = 5;
        goto LAB_0308814e;
      }
      iVar2 = aiStack_2c0[param_2];
      iVar1 = (int)asStack_158[param_2];
      do {
        if (0x1ffffffe < iVar2) goto joined_r0x0308815c;
LAB_0308814e:
        iVar2 = iVar2 * 4;
        iVar1 = iVar1 + 2;
      } while (iVar2 != 0);
    }
    *param_3 = 0xffffffff;
    *param_1 = iVar1;
    param_1[1] = 0;
    return;
  }
  iVar2 = DAT_03088384;
  if (param_2 < 0) {
    iVar1 = -param_2 >> 3;
    iVar2 = DAT_03088388;
  }
  iVar1 = 0x1b - iVar1;
LAB_03088162:
  *param_1 = iVar1;
  param_1[1] = iVar2;
  return;
joined_r0x0308815c:
  if (iVar2 < 0x3fffffff) {
    iVar2 = iVar2 << 1;
    iVar1 = iVar1 + 1;
  }
  goto LAB_03088162;
}


