/**
 * FUN_0304d022 @ 0x0304d022
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0304d022(void)

{
  uint unaff_r4;
  uint unaff_r5;
  
  while( true ) {
    FUN_0302bdda();
    unaff_r4 = unaff_r4 + 1 & 0xffff;
    if (unaff_r5 <= unaff_r4) break;
    FUN_030249f4();
    FUN_03030d3c();
    MusicInit();
    FUN_0302bd38(2,7);
  }
  FUN_0302bd38(2,7);
  FUN_030185a6(DAT_0304d060,0x1000,0xff);
  FUN_0302bdda();
  return;
}


