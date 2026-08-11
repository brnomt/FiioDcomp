/**
 * FUN_03029b00 @ 0x03029b00
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03029b00(int param_1)

{
  char cVar1;
  char *pcVar2;
  undefined1 *puVar3;
  int *piVar4;
  undefined2 uVar5;
  int iVar6;
  uint uVar7;
  uint local_18;
  
  pcVar2 = DAT_03029efc;
  pcVar2[1] = '\f';
  pcVar2[2] = '\0';
  cVar1 = *pcVar2;
  if (cVar1 == '\x02' || cVar1 == '\b') {
    pcVar2[1] = '\n';
    pcVar2[2] = '\0';
  }
  else {
    if (cVar1 == '\x05' || cVar1 == '\x06') {
      if (param_1 < 0x24) goto LAB_03029b36;
      uVar5 = 1;
    }
    else {
      if ((cVar1 != '\x04' && cVar1 != '\x03') || (param_1 < 0x1f)) goto LAB_03029b36;
      uVar5 = 4;
    }
    *(undefined2 *)(pcVar2 + 1) = uVar5;
  }
LAB_03029b36:
  puVar3 = DAT_0302ce58;
  local_18 = 0xac44;
  FUN_0302c9aa(&local_18);
  FUN_0300ba82();
  piVar4 = DAT_0302ce60;
  switch(*puVar3) {
  case 0:
    iVar6 = *DAT_0302ce60;
    if (iVar6 != 0) {
      if (iVar6 == 1) {
        FUN_0300c5a4(0x17);
        *piVar4 = 0;
      }
      else if (iVar6 == 2) {
        FUN_0300c5a4(0x18);
        *piVar4 = 0;
      }
      else if (iVar6 == 3) {
        FUN_0300c5a4(0x19);
        *piVar4 = 0;
      }
    }
    break;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
    FUN_0300cd00(0x25,7);
    uVar7 = *DAT_0302ce64 >> 1;
    if ((uVar7 < 0x481) && (local_18 < 0xbb81)) {
      FUN_0300c558(0x17);
      *piVar4 = 1;
    }
    else {
      if ((uVar7 < 0x1000) &&
         ((local_18 < 0xbb81 || ((uVar7 < 0x481 && (local_18 - 0xbb81 < 0x9d08)))))) {
        FUN_0300c558(0x18);
        iVar6 = 2;
      }
      else {
        FUN_0300c558(0x19);
        iVar6 = 3;
      }
      *piVar4 = iVar6;
    }
    FUN_0302cab0(puVar3);
    shared_frame_epilogue_c6b4(0x104);
  }
  FUN_0300bada();
  *(undefined4 *)(*DAT_0302ce5c + 0x98) = 0;
  return 0;
}


