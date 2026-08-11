/**
 * FUN_03004064 @ 0x03004064
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03004064(void)

{
  int *piVar1;
  undefined2 *puVar2;
  
  if (*DAT_030040b4 == '\x01') {
    FUN_030046e0();
  }
  piVar1 = DAT_030040d0;
  if (*DAT_030040d0 != -1) {
    FUN_02fe3c0c((int)(char)*DAT_030040d0);
    *piVar1 = -1;
  }
  FUN_02ff2e26(0x11c);
  *DAT_03004104 = 0;
  puVar2 = DAT_030040ec;
  DAT_030040ec[1] = 0;
  puVar2[3] = 0;
  *puVar2 = 0;
  puVar2[2] = 0;
  *DAT_030040f0 = 0;
  FUN_0300410c();
  FUN_030111fe(0);
  *DAT_030040bc = 0;
  return;
}


