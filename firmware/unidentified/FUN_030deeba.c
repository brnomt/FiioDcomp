/**
 * FUN_030deeba @ 0x030deeba
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030deeba(char *param_1)

{
  byte bVar1;
  uint uVar2;
  int local_40 [12];
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_10 = *DAT_030df0e4;
  uStack_c = DAT_030df0e4[1];
  local_40[1] = *(undefined4 *)(DAT_030df0e8 + 4);
  local_40[2] = *(undefined4 *)(DAT_030df0e8 + 8);
  local_40[3] = *(undefined4 *)(DAT_030df0e8 + 0xc);
  local_40[4] = *(undefined4 *)(DAT_030df0e8 + 0x10);
  local_40[5] = *(undefined4 *)(DAT_030df0e8 + 0x14);
  local_40[6] = *(undefined4 *)(DAT_030df0e8 + 0x18);
  local_40[7] = *(undefined4 *)(DAT_030df0e8 + 0x1c);
  local_40[10] = *(undefined4 *)(DAT_030df0e8 + 0x28);
  local_40[0xb] = *(undefined4 *)(DAT_030df0e8 + 0x2c);
  local_40[8] = *(undefined4 *)(DAT_030df0e8 + 0x20);
  local_40[9] = *(undefined4 *)(DAT_030df0e8 + 0x24);
  if ((*param_1 == -1) && (param_1[1] == *DAT_030df0ec)) {
    bVar1 = param_1[3];
    uVar2 = (byte)param_1[2] & 0xf;
    if ((uVar2 != 0xf) && ((10 < uVar2 - 1 || (*DAT_030df0f0 == local_40[uVar2])))) {
      uVar2 = (bVar1 & 0xf) >> 1;
      if ((((bVar1 & 1) == 0) && (bVar1 >> 4 < 0xd)) &&
         ((uVar2 == 0 ||
          ((uVar2 != 3 && uVar2 != 7 && (DAT_030df0f0[2] == (uint)*(byte *)((int)&local_10 + uVar2))
           ))))) {
        return 1;
      }
    }
  }
  return 0;
}


