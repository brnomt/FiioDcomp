# RE-HISTORY — The Reverse-Engineering Phase (2026)

> The decompilation phase of this project (2026) is **completed and
> archived**. It produced the knowledge, SDK integration, and tooling that
> power ReChord (the custom firmware). This doc points to that history —
> most of it remains useful reference for understanding the Echo Mini
> hardware and the FiiO app layer.

## What the RE phase achieved

1. **Extracted & analyzed all 23 firmware versions** (v1.2.5 → v3.8.0),
   each verified unique.
2. **Decompiled 2,764 / 2,776 functions** to pseudocode (Ghidra).
3. **Named 852 functions** (30.7%) via changelog-anchored cross-version
   analysis + SDK structural matching.
4. **Mapped the hardware**: SoC registers (CRU/DMA/INTC/GRF/ADC/I2S/PMU),
   ROM API (0x02FExxxx), segment table, LCD/DAC/SD pins.
5. **Integrated the Rockchip RKnanoD SDK**: all 53 source files now
   compile — this is the foundation of ReChord.

## Why the project pivoted

The original goal was "decompile the FiiO firmware into compilable C".
That was impractical: Ghidra output is unreadable (`param_1`, `undefined4`,
`DAT_030xxxxx`) and would never rebuild faithfully.

The pivot: the firmware is **~90% Rockchip SDK** (the chip vendor's own
code) + **~10% FiiO app layer**. So ReChord compiles the real SDK from
source and rebuilds the FiiO layer as clean C — a Rockbox-style custom
firmware, not a clone.

## Archived docs (reference)

| Doc | Content | Status |
|-----|---------|--------|
| `docs/MULTI-VERSION-PLAN.md` | The full RE handoff: version diffing, changelog anchoring, naming | 📚 archived reference |
| `docs/HARDWARE.md` (was memory-map) | SoC addresses, segment table, pins | ✅ still current |
| `docs/changelog-string-diff.md` | Changelog × string correlation | 📚 archived |
| `docs/symbol-index.md` | Named functions reference | 🟨 partially useful |
| `docs/c-cleanup-status.md` | Decompiled-tree cleanup (327/394) | 📚 archived |
| `docs/sdk-matching-progress.md` | SDK matching approach | 📚 archived |
| `docs/decompilation-plan.md` | Ghidra progress | 📚 archived |

## What carries forward into ReChord

- **SDK integration headers** (`firmware/rockchip/include/`) — the bridge
  that makes the Keil-written SDK compile with GCC.
- **Register map** (`docs/HARDWARE.md`) — where everything lives.
- **pack_img.py** — verified safe flashing (resource mods tested on device).
- **The FiiO app layer knowledge** — named functions in `docs/symbol-index.md`
  are the spec for rebuilding the UI/menus.
