/**
 * FUN_030897d8 @ 0x030897d8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030897d8(int *param_1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  short *psVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  undefined1 auStack_50 [40];
  undefined4 local_28;
  
  iVar11 = *param_1;
  piVar9 = param_1 + 0xd;
  psVar7 = (short *)((int)param_1 + 0x36);
  iVar10 = 0;
  if ((short)param_1[0xd] < *(short *)(iVar11 + 0x188)) {
    do {
      iVar8 = *(int *)(iVar11 + 0xd8) +
              *(short *)(*(int *)(iVar11 + 0x18c) + (short)*piVar9 * 2) * 0xfc;
      cVar1 = **(char **)(*(int *)(iVar8 + 0xc0) + 0x10);
      if (*(int *)(iVar8 + 0x30) == 0) {
        if (cVar1 != '\x01') {
          sVar2 = *(short *)(iVar8 + 0x7c);
          goto joined_r0x030898a6;
        }
        puVar5 = *(undefined4 **)(iVar8 + 0x40);
        *(undefined4 *)(iVar8 + 0xa4) = 0x200000;
        if (0 < (short)*(ushort *)(iVar8 + 0x80)) {
          puVar6 = puVar5 + -1;
          if ((*(ushort *)(iVar8 + 0x80) & 1) != 0) {
            *puVar5 = 0x200000;
            puVar6 = puVar5;
          }
          for (iVar8 = (int)*(short *)(iVar8 + 0x80) >> 1; iVar8 != 0; iVar8 = iVar8 + -1) {
            puVar6[1] = 0x200000;
            puVar6 = puVar6 + 2;
            *puVar6 = 0x200000;
          }
        }
      }
      else if (cVar1 == '\x01') {
        sVar2 = *psVar7;
        iVar10 = *(int *)(iVar8 + 0x40);
        while (sVar2 < 10) {
          sVar2 = *psVar7;
          if ((sVar2 == 0 || sVar2 == 8) || (sVar2 == 9)) {
            uVar4 = 3;
          }
          else {
            uVar4 = 4;
          }
          iVar3 = wma_bitreader_getbits(param_1 + 0x21,uVar4,&local_28);
          if (iVar3 < 0) {
            return iVar3;
          }
          *(char *)(iVar10 + *psVar7) = (char)local_28;
          sVar2 = *psVar7 + 1;
          *psVar7 = sVar2;
        }
        FUN_0308b9ae(iVar11,iVar10,auStack_50,10);
        iVar10 = FUN_0308bcb4(iVar11,auStack_50,iVar8);
        if (iVar10 < 0) {
          return iVar10;
        }
      }
      else {
        sVar2 = *(short *)(iVar8 + 0x7c);
joined_r0x030898a6:
        if (0 < sVar2) {
          FUN_0308aa9a(iVar11,iVar8);
        }
      }
      *psVar7 = 0;
      sVar2 = (short)*piVar9 + 1;
      *(short *)piVar9 = sVar2;
    } while (sVar2 < *(short *)(iVar11 + 0x188));
  }
  return iVar10;
}


