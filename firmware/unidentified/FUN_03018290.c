/**
 * FUN_03018290 @ 0x03018290
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03018290(int param_1)

{
  short sVar1;
  undefined2 *puVar2;
  short *psVar3;
  short *psVar4;
  uint uVar5;
  
  psVar3 = DAT_030184a0;
  puVar2 = DAT_0301849c;
  if ((ushort)(*DAT_030184a0 - DAT_0301849c[0x14]) <= (ushort)DAT_0301849c[0x16]) {
    return;
  }
  uVar5 = 0;
  psVar4 = (short *)(param_1 + (uint)(ushort)DAT_0301849c[5] * 2);
  sVar1 = *psVar4;
  while (sVar1 != 0) {
    if (sVar1 == 10) goto LAB_030182d4;
    psVar4 = psVar4 + 1;
    uVar5 = uVar5 + 1 & 0xffff;
    sVar1 = *psVar4;
  }
  uVar5 = 0;
LAB_030182d4:
  if (uVar5 == 0) {
    DAT_0301849c[7] = 1;
    *puVar2 = puVar2[0x11];
    puVar2[5] = 0;
  }
  else {
    uVar5 = (ushort)DAT_0301849c[5] + uVar5 + 1;
    DAT_0301849c[5] = (short)uVar5;
    param_1 = param_1 + (uVar5 & 0xffff) * 2;
  }
  FUN_02fff812(puVar2[10],(int)(short)puVar2[0xc],(int)(short)puVar2[0xd],(int)(short)puVar2[0xe],
               (int)(short)puVar2[0xf]);
  FUN_02ffe3dc(DAT_0301849c,DAT_0301849c,param_1,0);
  puVar2[7] = puVar2[7] + 1;
  *(undefined4 *)(puVar2 + 0x14) = *(undefined4 *)psVar3;
  return;
}


