/**
 * FUN_0302b0aa @ 0x0302b0aa
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0302b0aa(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  iVar1 = DAT_0302b528;
  if (*DAT_0302b0f8 == 0) {
    FUN_0302c950(*(undefined4 *)(*(int *)(DAT_0302b528 + 0xc) + 4),0);
    FUN_0302c932();
    puVar3 = DAT_0302b530;
    piVar2 = DAT_0302b52c;
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    FUN_0302ca40(puVar3,piVar2);
    puVar3 = DAT_0302b530;
    FUN_03009fe8(*DAT_0302b530,DAT_0302b52c,*(undefined4 *)(*(int *)(iVar1 + 0xc) + 0x9c));
    piVar2 = DAT_0302b52c;
    rom_memzero(*puVar3,*DAT_0302b52c << 2);
    *DAT_0302b534 = 0;
    *DAT_0302b538 = 1;
    shared_mid_entry_c6f6(0x59);
    FUN_03004608(5,*puVar3,DAT_0302b544,*piVar2,DAT_0302b540,DAT_0302b53c);
    *DAT_0302b548 = 1;
    FUN_0300bb32();
    rom_dac_mute(1,4);
    return 1;
  }
  if (*DAT_0302b0f4 == 2) {
    *DAT_0302b128 = 0xffffffff;
  }
  else if (*DAT_0302b0f4 == 1) {
    *DAT_0302b128 = 1;
  }
  shared_frame_epilogue_c6b4(0x39);
  return 0;
}


