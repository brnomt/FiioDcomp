/**
 * FUN_030ad2e0 @ 0x030ad2e0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030ad2e0(int *param_1,undefined4 *param_2,undefined4 *param_3,int *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint extraout_r1;
  undefined1 auStack_30 [24];
  
  puVar2 = DAT_030ad6dc;
  DAT_030ad6dc[2] = DAT_030ad6dc[2] + 1;
  FUN_030b1524(auStack_30,*param_4 + 7 >> 3,*param_2);
  bitstream_getbits(auStack_30,*param_3);
  iVar6 = bitstream_getbits(auStack_30,0xc);
  if (iVar6 == 0xfff) {
    bitstream_getbits(auStack_30,1);
    cVar3 = bitstream_getbits(auStack_30,2);
    cVar4 = bitstream_getbits(auStack_30,1);
    cVar5 = bitstream_getbits(auStack_30,2);
    uVar7 = bitstream_getbits(auStack_30,4);
    uVar7 = uVar7 & 0xff;
    bitstream_getbits(auStack_30,1);
    uVar8 = bitstream_getbits(auStack_30,3);
    bitstream_getbits(auStack_30,1);
    bitstream_getbits(auStack_30,1);
    bitstream_getbits(auStack_30,1);
    bitstream_getbits(auStack_30,1);
    iVar6 = bitstream_getbits(auStack_30,0xd);
    *param_1 = *param_1 + iVar6;
    puVar2[4] = iVar6 + puVar2[4];
    bitstream_getbits(auStack_30,0xb);
    bitstream_getbits(auStack_30,2);
    if (cVar4 == '\0') {
      bitstream_getbits(auStack_30,0x10);
    }
    FUN_030b1718(auStack_30);
    cVar4 = cVar3;
    if (cVar3 == '\0') {
      cVar4 = cVar5;
    }
    if (cVar3 == '\0' && cVar4 == '\x01') {
      uVar1 = extraout_r1;
      if (uVar7 < 0xc) {
        uVar1 = uVar8 & 0xff;
      }
      if (uVar7 < 0xc && uVar1 < 8) {
        puVar2[1] = *(undefined4 *)(*DAT_030ad6e0 + uVar1 * 4);
        *puVar2 = *(undefined4 *)(*DAT_030ad6e4 + uVar7 * 4);
        puVar2[3] = 0x400;
        return 0;
      }
    }
  }
  return 0xfffffffd;
}


