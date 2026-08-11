/**
 * FUN_030098d8 @ 0x030098d8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030098d8(void)

{
  if (1 < *(byte *)(DAT_03009cd4 + 0x1c0) && *(byte *)(DAT_03009cd4 + 0x1c0) != 3) {
    *(uint *)(DAT_03009cdc + 0xc) =
         (uint)(DAT_03009ce0 * (*(int *)(*DAT_03009cd8 + 0xc) + -0x1db0)) / 0x578 & 0xffff;
    return;
  }
  *(uint *)(DAT_03009cdc + 0xc) =
       (uint)((*(int *)(*DAT_03009cd8 + 0xc) + -0x21fc) * 200) / 0x834 & 0xffff;
  return;
}


