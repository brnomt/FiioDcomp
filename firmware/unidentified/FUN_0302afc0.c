/**
 * FUN_0302afc0 @ 0x0302afc0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0302afc0(void)

{
  int iVar1;
  undefined2 *puVar2;
  undefined4 *puVar3;
  short *psVar4;
  int *piVar5;
  
  psVar4 = DAT_0302b0f4;
  if (*DAT_0302b0f4 != 0) {
    if (*DAT_0302b0f4 == 3) {
      FUN_0300a926();
    }
    puVar2 = DAT_0302b0e8;
    iVar1 = DAT_0302b0dc;
    if (*DAT_0302b0f8 == 0) {
      *(undefined4 *)(DAT_0302b0dc + 0x1c) = 0;
      shared_frame_epilogue_c6b4(0x42);
      FUN_0302ca40(DAT_0302b100,DAT_0302b0fc);
      puVar3 = DAT_0302b100;
      piVar5 = DAT_0302b0fc;
      rom_memzero(*DAT_0302b100,*DAT_0302b0fc << 2);
      FUN_03009fe8(*puVar3,piVar5,*(undefined4 *)(*(int *)(iVar1 + 0xc) + 0x9c));
      *DAT_0302b0f0 = 1;
      shared_mid_entry_c6f6(0x59);
      FUN_03004608(5,*puVar3,DAT_0302b10c,*piVar5);
      puVar3 = DAT_0302b0ec;
      *psVar4 = 0;
      *puVar2 = 0;
      *puVar3 = 1;
      FUN_0300bb32();
      rom_dac_mute(1,4);
      if (*(char *)(DAT_0302b110 + 0x34a) != '\0') {
        shared_frame_epilogue_c6b4(0x1d5);
        shared_mid_entry_c6f6(0x1d4);
      }
      *DAT_0302b114 = 0;
      *DAT_0302b118 = 0;
      shared_frame_epilogue_c6b4(0x2b);
      *DAT_0302b11c = 2;
      shared_frame_epilogue_c6b4(0x23);
      *DAT_0302b124 = *DAT_0302b120;
    }
    else {
      *psVar4 = 0;
      *puVar2 = 4;
      shared_frame_epilogue_c6b4(0x55);
    }
    return 1;
  }
  return 0;
}


