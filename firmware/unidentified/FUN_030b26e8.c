/**
 * FUN_030b26e8 @ 0x030b26e8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030b26e8(undefined4 param_1,undefined1 *param_2,int param_3)

{
  int *piVar1;
  undefined1 uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  uVar2 = bitstream_getbits(param_1,1);
  *param_2 = uVar2;
  uVar2 = bitstream_getbits(param_1,2);
  param_2[1] = uVar2;
  uVar2 = bitstream_getbits(param_1,1);
  param_2[2] = uVar2;
  if (param_2[1] != '\x02') {
    uVar2 = bitstream_getbits(param_1,6);
    param_2[3] = uVar2;
    cVar3 = bitstream_getbits(param_1,1);
    param_2[5] = cVar3;
    if (cVar3 != '\0') {
      cVar3 = bitstream_getbits(param_1,1);
      param_2[6] = cVar3;
      if (cVar3 != '\0') {
        uVar2 = bitstream_getbits(param_1,5);
        param_2[7] = uVar2;
      }
      piVar1 = DAT_030b2d48;
      uVar4 = *(uint *)(*DAT_030b2d48 + param_3 * 4);
      if ((int)(uint)(byte)param_2[3] < (int)uVar4) {
        uVar4 = (uint)(byte)param_2[3];
      }
      iVar5 = 0;
      if (0 < (int)uVar4) {
        do {
          uVar2 = bitstream_getbits(param_1,1);
          iVar7 = iVar5 + 1;
          param_2[iVar5 + 8] = uVar2;
          uVar6 = *(uint *)(*piVar1 + param_3 * 4);
          uVar4 = (uint)(byte)param_2[3];
          if ((int)uVar6 <= (int)(uint)(byte)param_2[3]) {
            uVar4 = uVar6;
          }
          iVar5 = iVar7;
        } while (iVar7 < (int)uVar4);
      }
    }
    param_2[0x31] = 1;
    param_2[0x32] = 1;
    return;
  }
  uVar2 = bitstream_getbits(param_1,4);
  param_2[3] = uVar2;
  uVar2 = bitstream_getbits(param_1,7);
  param_2[4] = uVar2;
  param_2[0x31] = 1;
  uVar4 = 0x40;
  param_2[0x32] = 1;
  iVar5 = 0;
  do {
    uVar6 = (uint)(byte)param_2[0x31];
    if (((byte)param_2[4] & uVar4) == 0) {
      param_2[0x31] = (char)(uVar6 + 1);
      param_2[(uVar6 + 1 & 0xff) + 0x31] = 1;
    }
    else {
      param_2[uVar6 + 0x31] = param_2[uVar6 + 0x31] + '\x01';
    }
    uVar4 = (int)uVar4 >> 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 7);
  return;
}


