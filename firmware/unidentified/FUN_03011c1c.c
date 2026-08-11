/**
 * FUN_03011c1c @ 0x03011c1c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03011c1c(uint param_1,int param_2,char param_3,undefined1 param_4)

{
  uint uVar1;
  int iVar2;
  char *unaff_r4;
  int unaff_r5;
  char unaff_r6;
  undefined1 unaff_r7;
  undefined1 unaff_r8;
  int unaff_r9;
  undefined1 in_r12;
  
  if (unaff_r9 == 0) {
    unaff_r4[0xb] = param_3;
    iVar2 = DAT_03011d10;
    if (param_1 == 1) {
      *(undefined1 *)(DAT_03011d10 + 5) = *(undefined1 *)(DAT_03011d10 + 2);
      *(undefined1 *)(iVar2 + 4) = in_r12;
      *(undefined1 *)(iVar2 + 3) = unaff_r8;
      *(undefined1 *)(iVar2 + 2) = param_4;
      *(undefined1 *)(unaff_r5 + 1) = unaff_r8;
    }
    else {
      if (param_1 != 2) {
        if (2 < param_1) {
          *(undefined1 *)(param_2 + 2) = unaff_r7;
          *(undefined1 *)(param_2 + 1) = *(undefined1 *)(unaff_r5 + param_1);
          *(undefined1 *)(unaff_r5 + param_1) = *(undefined1 *)(param_2 + -1);
          *(undefined1 *)(param_2 + -1) = param_4;
          *unaff_r4 = *unaff_r4 + '\x01';
        }
        goto LAB_03011ca0;
      }
      *(undefined1 *)(DAT_03011d10 + 5) = *(undefined1 *)(DAT_03011d10 + 3);
      *(undefined1 *)(iVar2 + 4) = *(undefined1 *)(unaff_r5 + 2);
      *(undefined1 *)(iVar2 + 3) = in_r12;
      *(undefined1 *)(unaff_r5 + 2) = param_4;
      *(undefined1 *)(iVar2 + 1) = unaff_r8;
    }
    unaff_r4[1] = unaff_r6;
  }
  else {
    uVar1 = 0;
    do {
      iVar2 = (param_1 - uVar1) + unaff_r5;
      if (*(char *)(iVar2 + 1) == '\x12') {
        *(undefined1 *)((param_1 - uVar1) + unaff_r5 + 2) = unaff_r8;
        *(undefined1 *)(iVar2 + 3) = unaff_r8;
        break;
      }
      uVar1 = uVar1 + 1 & 0xff;
      *(char *)(iVar2 + 3) = *(char *)(iVar2 + 1);
    } while (uVar1 <= param_1 + 2);
    unaff_r4[1] = (char)(param_1 + 2);
  }
LAB_03011ca0:
  FUN_03011192(1);
  FUN_02ffff38(0x33);
  return;
}


