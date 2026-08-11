/**
 * FUN_030147fc @ 0x030147fc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_030147fc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  
  Reset = 0;
  Reserved1 = 0;
  uRam00000050 = 0;
  NMI = 0;
  _MemManage = _MemManage & 0xffffff00;
  BusFault = 0;
  piVar3 = *(int **)(_MemManage + 0x70);
  *(char *)piVar3 = (char)piVar3;
  piVar3[4] = (int)piVar3;
  *(char *)(piVar3 + 3) = (char)piVar3;
  piVar3[0x10] = (int)piVar3;
  piVar3[0x18] = (int)piVar3;
  piVar3[0x1c] = (int)piVar3;
  bVar1 = *(byte *)(uint)*(byte *)(*(int *)(*(int *)(*(int *)(*piVar3 + 0x20) + 0x30) + 0x40) + 8);
  uVar4 = (uint)bVar1;
  *(uint *)(uVar4 + 0x30) = uVar4;
  *(byte *)(uVar4 + 0x18) = bVar1;
  *(uint *)(uVar4 + 0x20) = uVar4;
  pcVar5 = *(char **)(*(int *)(uVar4 + 0x60) + 0x50);
  pcVar5[0] = '\0';
  pcVar5[1] = '\0';
  pcVar5[2] = '\0';
  pcVar5[3] = '\0';
  cVar2 = *pcVar5;
  iVar6 = (int)cVar2;
  *(short *)(iVar6 * 2) = (short)cVar2;
  *(char *)(iVar6 * 2) = cVar2;
  uVar4 = *(uint *)(pcVar5 + iVar6);
  pcVar5[uVar4] = (char)uVar4;
  *(uint *)(uVar4 * 2) = uVar4;
  iVar6 = (int)uVar4 >> (uVar4 & 0xff);
  *(short *)(pcVar5 + iVar6) = (short)iVar6;
                    /* WARNING: Could not emulate address calculation at 0x0301484a */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(iVar6 * 2))((code *)(iVar6 * 2),0x50004f00,param_3,pcVar5);
  return;
}


