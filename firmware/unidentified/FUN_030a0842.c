/**
 * FUN_030a0842 @ 0x030a0842
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030a0842(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  uVar1 = (uint)(byte)param_1[0x8a];
  if ((short)param_1[0x8c] != 2) {
    if ((short)param_1[0x8c] == 1) {
      if (*DAT_030a0984 == 0xf) {
        *(undefined2 *)((int)param_1 + 0x22a) = 0x3000;
        param_1[0x88] = uVar1 * param_1[0x89] * 2;
        *(short *)(param_1 + 0x8b) = (short)(0x3000 >> uVar1);
      }
      else {
        *DAT_030a0984 = 0x17;
        *(undefined2 *)((int)param_1 + 0x22a) = 0x3000;
        param_1[0x88] = uVar1 * param_1[0x89] * 3;
        *(short *)(param_1 + 0x8b) = (short)(0x3000 >> uVar1);
      }
    }
    goto LAB_030a094c;
  }
  uVar2 = param_1[0x89];
  iVar3 = 0xac44;
  if ((uVar2 == 0xac44) || (0xac44 < (int)uVar2)) goto LAB_030a08ec;
  if (uVar2 == 16000) {
LAB_030a0916:
    *(undefined2 *)((int)param_1 + 0x22a) = 0x100;
  }
  else {
    if ((int)uVar2 < 0x3e81) {
      bVar5 = uVar2 == 8000;
      if (!bVar5) {
        iVar3 = uVar2 - 0x2b11;
        bVar5 = iVar3 == 0;
      }
      if (!bVar5) {
        bVar5 = iVar3 == 0x3cf;
      }
      if (!bVar5) goto LAB_030a08ec;
      goto LAB_030a0916;
    }
    iVar3 = 0;
    if (uVar2 != 0x5622) {
      iVar3 = uVar2 - 0x5c22;
    }
    if (uVar2 != 0x5622 && iVar3 != 0x19e) {
LAB_030a08ec:
      *(undefined2 *)((int)param_1 + 0x22a) = 0x400;
    }
    else {
      *(undefined2 *)((int)param_1 + 0x22a) = 0x200;
    }
  }
  uVar4 = (((uint)*(ushort *)((int)param_1 + 0x22a) << 1) >> (uVar1 - 1 & 0xff)) - 0xc;
  *(short *)(param_1 + 0x8b) = (short)uVar4;
  param_1[0x88] = (*(ushort *)((int)param_1 + 0x22a) * uVar2) / (uVar4 & 0xffff);
LAB_030a094c:
  *param_1 = uVar1;
  *(short *)(param_1 + 1) = (short)param_1[0x8b];
  param_1[0x84] = 0x5a;
  param_1[0x86] = 0;
  param_1[0x8e] = 0;
  param_1[0x87] = 0;
  return;
}


