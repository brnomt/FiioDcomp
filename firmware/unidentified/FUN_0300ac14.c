/**
 * FUN_0300ac14 @ 0x0300ac14
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Removing unreachable block (ram,0x0300acf6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0300ac14(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 unaff_r4;
  
  FUN_02fe85fc(DAT_0300af34,DAT_0300af30);
  iVar3 = FUN_02ff971c(0x6e);
  if ((iVar3 == 1) || (iVar3 = FUN_02ff971c(0x6f), iVar3 == 1)) {
    FUN_02fe85fc(DAT_0300af34,DAT_0300af30);
  }
  iVar3 = FUN_02ff971c(0x71);
  if (iVar3 == 1) {
    FUN_02fe85fc(DAT_0300af34,DAT_0300af30);
  }
  iVar3 = FUN_02ff971c(0xe3);
  puVar2 = puRam0300af3c;
  piVar1 = _FUN_0300af38;
  if (iVar3 == 1) {
    FUN_0300b034();
    if (*piVar1 == 0) {
      *puVar2 = 5;
      FUN_02ff992a(10);
      unaff_r4 = 1;
    }
    else {
      FUN_02ff9700(0xa1);
      *puVar2 = 5;
      FUN_02ff992a(5,0);
      unaff_r4 = 1;
    }
  }
  iVar3 = FUN_02ff971c(0x79);
  if (iVar3 == 1) {
    FUN_0300b034();
    if (*piVar1 == 0) {
      *puVar2 = 5;
      FUN_02ff992a(10);
      unaff_r4 = 1;
    }
    else {
      FUN_02ff9700(0xa1);
      *puVar2 = 5;
      FUN_02ff992a(5,0);
      unaff_r4 = 1;
    }
  }
  if ((DAT_0307a928 == '\x01' || DAT_0307a928 == '\x02') &&
     (iVar3 = FUN_02ff8bf2(), 1 < (uint)(iVar3 - DAT_0307a930))) {
    DAT_0307a92c = DAT_0307a92c + 1;
    DAT_0307a930 = iVar3;
    FUN_02ff9700(0x1b1);
  }
  return unaff_r4;
}


