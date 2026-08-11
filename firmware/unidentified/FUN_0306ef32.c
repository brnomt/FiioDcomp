/**
 * FUN_0306ef32 @ 0x0306ef32
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0306ef32(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  
  piVar1 = DAT_0306f164;
  uVar5 = DAT_0306f164[4];
  if ((uint)DAT_0306f164[3] <= uVar5) {
    *(int *)(*DAT_0306f164 + DAT_0306f164[2] * 4 + 0x3c) = DAT_0306f164[5];
    piVar1[6] = 0;
    return;
  }
  *DAT_0306f170 = DAT_0306f164[2] | (0xf - DAT_0306f164[5]) * 2;
  iVar3 = FUN_0306e3a4(piVar1[1] + uVar5 * 0x80);
  puVar2 = DAT_0306f174;
  if (iVar3 == 0) {
    puVar4 = (undefined4 *)(piVar1[1] + piVar1[4] * 0x80);
    iVar6 = (int)&DAT_60050000 - (int)puVar4 >> 2;
    bVar8 = iVar6 == 0;
    iVar3 = iVar6;
    iVar7 = iVar6;
    if (0 < iVar6) {
      iVar7 = 0x20;
      iVar3 = 0x20 - iVar6;
      bVar8 = iVar6 == 0x20;
    }
    if (bVar8 || iVar3 < 0 != (0 < iVar6 && SBORROW4(iVar7,iVar6))) {
      hifi_memmove(DAT_0306f174,puVar4,0x80);
    }
    else {
      *DAT_0306f174 = *puVar4;
      puVar2[1] = puVar4[1];
      puVar2[2] = puVar4[2];
      puVar2[3] = puVar4[3];
      puVar2[4] = puVar4[4];
      puVar2[5] = puVar4[5];
      puVar2[6] = puVar4[6];
      puVar2[7] = puVar4[7];
      puVar2[8] = puVar4[8];
      puVar2[9] = puVar4[9];
      puVar2[10] = puVar4[10];
      puVar2[0xb] = puVar4[0xb];
      puVar2[0xc] = puVar4[0xc];
      puVar2[0xd] = puVar4[0xd];
      puVar2[0xe] = puVar4[0xe];
      puVar2[0xf] = puVar4[0xf];
      puVar2[0x10] = puVar4[0x10];
      puVar2[0x11] = puVar4[0x11];
      puVar2[0x12] = puVar4[0x12];
      puVar2[0x13] = puVar4[0x13];
      puVar2[0x14] = puVar4[0x14];
      puVar2[0x15] = puVar4[0x15];
      puVar2[0x16] = puVar4[0x16];
      puVar2[0x17] = puVar4[0x17];
      puVar2[0x18] = puVar4[0x18];
      puVar2[0x19] = puVar4[0x19];
      puVar2[0x1a] = puVar4[0x1a];
      puVar2[0x1b] = puVar4[0x1b];
      puVar2[0x1c] = puVar4[0x1c];
      puVar2[0x1d] = puVar4[0x1d];
      puVar2[0x1e] = puVar4[0x1e];
      puVar2[0x1f] = puVar4[0x1f];
    }
  }
  piVar1[5] = *(byte *)(piVar1 + 5) + 1 & 0xf;
  piVar1[4] = piVar1[4] + 1;
  return;
}


