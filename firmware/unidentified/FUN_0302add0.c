/**
 * FUN_0302add0 @ 0x0302add0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Control flow encountered bad instruction data */

void FUN_0302add0(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  uVar1 = FUN_03012368(0,2);
  puVar2 = (undefined4 *)func_0x03012394(0,2);
  FUN_03012358(0,4);
  iVar3 = DAT_0302b0dc;
  switch(uVar1) {
  case 0x66:
  case 0x75:
    *(undefined4 *)(DAT_0302b0dc + 0x7c) = 1;
  case 0x67:
  case 0x68:
  case 0x6a:
  case 0x6c:
  case 0x6e:
  case 0x70:
  case 0x72:
  case 0x74:
    return;
  case 0x69:
    *(undefined4 **)(DAT_0302b0dc + 0x80) = puVar2;
    FUN_02ffdaee(*puVar2,*(undefined1 *)(puVar2 + 1),(int)*(char *)(puVar2 + 2));
    puVar2 = *(undefined4 **)(iVar3 + 0x80);
    *puVar2 = *(undefined4 *)(DAT_0302b0e4 + (uint)*(byte *)(puVar2 + 2) * 0x27e + 0x20);
    func_0x030124a0(0x6a,0,2);
    break;
  case 0x6b:
    *(undefined4 **)(DAT_0302b0dc + 0x84) = puVar2;
    FUN_02ffd5f6(*puVar2,puVar2[1],(int)*(char *)(puVar2 + 2));
    iVar3 = *(int *)(iVar3 + 0x84);
    *(undefined4 *)(iVar3 + 4) =
         *(undefined4 *)(DAT_0302b0e4 + (uint)*(byte *)(iVar3 + 8) * 0x27e + 0x20);
    func_0x030124a0(0x6c,0,2);
    break;
  case 0x6d:
    *(undefined4 **)(DAT_0302b0dc + 0x88) = puVar2;
    FUN_03001068(*puVar2,puVar2[1],puVar2[2],(int)*(char *)(puVar2 + 3));
    func_0x030124a0(0x6e,0,2);
    break;
  case 0x6f:
    func_0x030124a0(0x70,0,2);
    break;
  case 0x71:
    func_0x030124a0(0x72,0,2);
    break;
  case 0x73:
    FUN_02ffd4dc((int)(char)puVar2);
    func_0x030124a0(0x74,0,2);
    break;
  default:
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


