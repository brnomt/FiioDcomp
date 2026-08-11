/**
 * FUN_03070b00 @ 0x03070b00
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03070b00(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  piVar1 = DAT_0306f164;
  iVar4 = *(int *)(param_1 + 0x24);
  DAT_0306f164[8] = 1;
  piVar1[6] = 1;
  piVar1[4] = 0;
  piVar1[3] = param_3;
  piVar1[2] = param_2;
  iVar6 = param_1 + param_2 * 4;
  *piVar1 = param_1;
  piVar1[1] = iVar4;
  iVar5 = *(int *)(iVar6 + 0x3c);
  piVar1[5] = iVar5;
  piVar1[7] = (uint)(*(char *)(param_1 + 1) != '\0');
  if (piVar1[3] != 0) {
    *DAT_0306f170 = param_2 | (0xf - iVar5) * 2;
    iVar4 = FUN_0306e3a4(iVar4);
    puVar2 = DAT_0306f174;
    if (iVar4 == 0) {
      puVar3 = (undefined4 *)(piVar1[1] + piVar1[4] * 0x80);
      iVar6 = (int)&DAT_60050000 - (int)puVar3 >> 2;
      bVar7 = iVar6 == 0;
      iVar4 = iVar6;
      iVar5 = iVar6;
      if (0 < iVar6) {
        iVar5 = 0x20;
        iVar4 = 0x20 - iVar6;
        bVar7 = iVar6 == 0x20;
      }
      if (bVar7 || iVar4 < 0 != (0 < iVar6 && SBORROW4(iVar5,iVar6))) {
        hifi_memmove(DAT_0306f174,puVar3,0x80);
      }
      else {
        *DAT_0306f174 = *puVar3;
        puVar2[1] = puVar3[1];
        puVar2[2] = puVar3[2];
        puVar2[3] = puVar3[3];
        puVar2[4] = puVar3[4];
        puVar2[5] = puVar3[5];
        puVar2[6] = puVar3[6];
        puVar2[7] = puVar3[7];
        puVar2[8] = puVar3[8];
        puVar2[9] = puVar3[9];
        puVar2[10] = puVar3[10];
        puVar2[0xb] = puVar3[0xb];
        puVar2[0xc] = puVar3[0xc];
        puVar2[0xd] = puVar3[0xd];
        puVar2[0xe] = puVar3[0xe];
        puVar2[0xf] = puVar3[0xf];
        puVar2[0x10] = puVar3[0x10];
        puVar2[0x11] = puVar3[0x11];
        puVar2[0x12] = puVar3[0x12];
        puVar2[0x13] = puVar3[0x13];
        puVar2[0x14] = puVar3[0x14];
        puVar2[0x15] = puVar3[0x15];
        puVar2[0x16] = puVar3[0x16];
        puVar2[0x17] = puVar3[0x17];
        puVar2[0x18] = puVar3[0x18];
        puVar2[0x19] = puVar3[0x19];
        puVar2[0x1a] = puVar3[0x1a];
        puVar2[0x1b] = puVar3[0x1b];
        puVar2[0x1c] = puVar3[0x1c];
        puVar2[0x1d] = puVar3[0x1d];
        puVar2[0x1e] = puVar3[0x1e];
        puVar2[0x1f] = puVar3[0x1f];
      }
    }
    piVar1[5] = *(byte *)(piVar1 + 5) + 1 & 0xf;
    piVar1[4] = piVar1[4] + 1;
    return;
  }
  *(int *)(iVar6 + 0x3c) = iVar5;
  piVar1[6] = 0;
  return;
}


