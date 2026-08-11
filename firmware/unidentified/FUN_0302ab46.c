/**
 * FUN_0302ab46 @ 0x0302ab46
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0302ab46(void)

{
  switch(*DAT_0302ace4) {
  case 0:
    FUN_0302aaf0();
    FUN_03011ed4();
    rom_dma_config(0xe,1);
    rom_dma_config(0xf,1);
    FUN_02ff67a4(0x6e,0);
    FUN_02ff67a4(0x7e,0);
    return;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
    FUN_0302aaf0();
    FUN_03011ed4();
    return;
  default:
    return;
  }
}


