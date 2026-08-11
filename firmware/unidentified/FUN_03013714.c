/**
 * FUN_03013714 @ 0x03013714
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03013714(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [16];
  undefined4 local_30;
  undefined4 local_2c;
  
  puVar3 = DAT_03013ad4;
  uVar1 = *DAT_03013ad4;
  uVar2 = DAT_03013ad4[1];
  local_30 = FUN_02ffc718(1);
  local_2c = FUN_02ffc6f4(2);
  *puVar3 = *DAT_03013ad8;
  puVar3[1] = *DAT_03013adc;
  iVar4 = MediaLib_GetTotalFiles_d(0x26);
  if (((iVar4 != 0) || (iVar4 = MediaLib_GetTotalFiles_b(0x14d), iVar4 != 0)) ||
     (iVar4 = MediaLib_GetTotalFiles_b(0x2f), iVar4 != 0)) {
    FUN_02ffcfc6(0x7a);
    MediaLib_GetTotalFiles(0x14f);
    FUN_02ffcaba(1);
  }
  iVar4 = MediaLib_GetTotalFiles_b(0x14f);
  if (iVar4 != 0) {
    FUN_02ffccca(0x8c,auStack_50);
    FUN_02ffccca(0x9e,auStack_40);
    uVar6 = 0;
    do {
      if (uVar6 == *(byte *)(DAT_03013ae0 + 1)) {
        if (uVar6 == 0) {
          FUN_02ffd462(0x86,4,0x17);
        }
        else {
          if (uVar6 == 5) {
            uVar5 = 0x88;
          }
          else {
            uVar5 = 0x85;
          }
          FUN_02ffd462(uVar5,4,(int)(short)((short)uVar6 * 0x18 + 0x17));
        }
        *puVar3 = *DAT_03013ae4;
      }
      else {
        *puVar3 = *DAT_03013ad8;
      }
      FUN_02ffc7c4(0x1c,uVar6 * 0x18 + 0x1c & 0xffff,100,0x10,0,
                   *(undefined2 *)(DAT_03013ae8 + uVar6 * 4 + 2));
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < 3);
  }
  FUN_02ffcaba(0);
  FUN_02ffc718(local_30);
  puVar3[1] = uVar2;
  *puVar3 = uVar1;
  FUN_02ffc6f4(local_2c);
  return;
}


