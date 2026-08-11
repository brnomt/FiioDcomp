/**
 * FUN_030ad63e @ 0x030ad63e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_030ad63e(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  puVar1 = DAT_030ad6dc;
  uVar3 = FUN_030acaf4(*DAT_030ad6dc);
  uVar4 = FUN_030acaf4(puVar1[3]);
  uVar4 = FUN_030ac932((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,_DAT_030ad6f0);
  uVar3 = FUN_030aca16((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),(int)uVar3,
                       (int)((ulonglong)uVar3 >> 0x20));
  iVar2 = puVar1[5];
  if ((int)puVar1[2] < (int)puVar1[5]) {
    iVar2 = puVar1[2];
  }
  puVar1[5] = iVar2;
  uVar4 = FUN_030acaf4();
  FUN_030ac932((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),(int)uVar3,(int)((ulonglong)uVar3 >> 0x20)
              );
  FUN_030acb16();
  return;
}


