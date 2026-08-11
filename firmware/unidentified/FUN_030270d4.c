/**
 * FUN_030270d4 @ 0x030270d4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030270d4(void)

{
  short sVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
LAB_030270d8:
  do {
    while( true ) {
      do {
        do {
          iVar3 = mp3_bitstream_getbits(8);
        } while (iVar3 != 0xff);
        do {
          iVar3 = mp3_bitstream_getbits(8);
        } while (iVar3 == 0xff);
      } while (iVar3 == 0);
      if (iVar3 == 0xce) {
        return;
      }
      if (iVar3 < 0xcf) break;
      switch(iVar3) {
      case 0xcf:
      case 0xd8:
      case 0xd9:
      case 0xda:
        goto switchD_0302713c_caseD_c7;
      case 0xd0:
      case 0xd1:
      case 0xd2:
      case 0xd3:
      case 0xd4:
      case 0xd5:
      case 0xd6:
      case 0xd7:
        break;
      case 0xdb:
        uVar7 = mp3_bitstream_getbits(0x10);
        iVar3 = DAT_030273cc;
        if (uVar7 < 2) {
          iVar3 = -0xcb;
        }
        else {
          for (uVar7 = uVar7 - 2; uVar7 != 0; uVar7 = uVar7 - uVar5) {
            uVar4 = mp3_bitstream_getbits(8);
            if (3 < (uVar4 & 0xf)) {
              iVar3 = -0xcc;
              goto LAB_030271ea;
            }
            iVar9 = iVar3 + (uVar4 & 0xf) * 0x80;
            if (iVar9 == 0) {
              iVar3 = -0xdd;
              goto LAB_030271ea;
            }
            iVar8 = 0;
            do {
              sVar1 = mp3_bitstream_getbits(8);
              if ((int)uVar4 >> 4 != 0) {
                sVar2 = mp3_bitstream_getbits(8);
                sVar1 = sVar2 + sVar1 * 0x100;
              }
              *(short *)(iVar9 + iVar8 * 2) = sVar1;
              iVar8 = iVar8 + 1;
            } while (iVar8 < 0x40);
            uVar5 = 0x41;
            if ((int)uVar4 >> 4 != 0) {
              uVar5 = 0x81;
            }
            if (uVar7 < uVar5) {
              iVar3 = -0xdb;
              goto LAB_030271ea;
            }
          }
          iVar3 = 0;
        }
LAB_030271ea:
        if (iVar3 != 0) {
          return;
        }
        break;
      default:
switchD_0302713c_default:
        uVar7 = mp3_bitstream_getbits(0x10);
        if (1 < uVar7) {
          for (iVar3 = uVar7 - 2; iVar3 != 0; iVar3 = iVar3 + -1) {
            FUN_03028338(8);
          }
        }
        break;
      case 0xdd:
        iVar3 = mp3_bitstream_getbits(0x10);
        if (iVar3 == 4) {
          uVar6 = mp3_bitstream_getbits(0x10);
          *DAT_030273f4 = uVar6;
          iVar3 = 0;
        }
        else {
          iVar3 = -0xd3;
        }
        if (iVar3 != 0) {
          return;
        }
      }
    }
    if (iVar3 == 0xc6) {
      return;
    }
    if (iVar3 < 199) {
      if (iVar3 == 0xc2) {
        return;
      }
      if (iVar3 < 0xc3) {
        if (iVar3 != 1) {
          if (iVar3 == 0xc0 || iVar3 == 0xc1) {
            return;
          }
          goto switchD_0302713c_default;
        }
      }
      else {
        if (iVar3 == 0xc3) {
          return;
        }
        if (iVar3 != 0xc4) {
          if (iVar3 == 0xc5) {
            return;
          }
          goto switchD_0302713c_default;
        }
        iVar3 = FUN_03026ece();
        if (iVar3 != 0) {
switchD_0302713c_caseD_c7:
          return;
        }
      }
      goto LAB_030270d8;
    }
    switch(iVar3) {
    case 199:
    case 0xc9:
    case 0xca:
    case 0xcb:
    case 0xcd:
      goto switchD_0302713c_caseD_c7;
    case 200:
    case 0xcc:
      break;
    default:
      goto switchD_0302713c_default;
    }
  } while( true );
}


