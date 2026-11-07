# Audi MH2P CarPlay Maps — Universal V1 TEST

[中文](README.md) · [Detailed runtime internals](docs/RUNTIME_INTERNALS.en.md) · [Upstream full edition and attribution](docs/UPSTREAM_AND_FULL_EDITION.md)

Documentation updated on **2026-11-07 (Asia/Shanghai)**. The existing release remains `v1.0.0-test.1`, with payload build `2026.10.24-universal-test.1`. Historical material retains its **2026-10-24** label; the handoff and V1 offline adaptation took place on **2026-11-04**. Actual publication timestamps come from GitHub, not the material label.

## Read this before downloading

This repository's existing V1 assets are a **no-navigation-card test candidate**, not a newly verified full-card release. This documentation update does not change the installer, executable libraries, Java classes, old tags, or release attachments.

For the original author's publicly available full package, including navigation-card functionality, see [the upstream package record](docs/UPSTREAM_AND_FULL_EDITION.md). That package is a separate upstream product. It has not been executed, installed, or independently vehicle-validated by this documentation update. Do not mix its installation or removal scripts with this repository's V1 installer.

“Universal” describes removal of this candidate's original per-device binding. It does **not** mean compatibility with every MH2P firmware, another processor, another brand, MHI2, or MHI2Q. This is a prerelease for testing, not a general production firmware update.

## What the existing V1 retains

- Native CarPlay **Type111 alternate-screen video** for the instrument cluster. The phone renders a distinct cluster view; this is not a loop of center-screen screenshots.
- OEM-map / phone-alternate-screen selection and the existing BACK long-press handling.
- Navigation message parsing and interfaces for roads, maneuvers, distances and units, lanes, roundabouts, ETA, BAP / Komo, and map zoom.
- The OEM receiver, decoding and display stack as supplied by the target vehicle. The test adaptation does not implement a new OEM CarPlay authorization system.

V1 deliberately excludes the navigation-card renderer, its navigation-process wrapper, plate/position layouts, and Java card-presentation integration. **The navigation data hook is retained**; its RGI name is not a reason to delete the parser and interfaces.

The historical full sample additionally contains a distinct platform navigation-card path. Its arrows are derived from maneuver data and platform descriptor mapping, not simply a PNG pasted onto video. Read [the runtime explanation](docs/RUNTIME_INTERNALS.en.md) for the separation between the video, data and card-rendering paths.

## Downloading and installation boundaries

The existing [V1 test prerelease](https://github.com/omonob/Audi-MH2P-CarPlay-Maps/releases/tag/v1.0.0-test.1) contains separate SD-installation, source-research and documentation archives, plus a manifest and SHA256 list. Verify the matching checksums before use.

For that V1 candidate only:

- `Data` and `Meta` belong directly at the SD-card root.
- It is **first-install-only**. Existing installations, backups or test remnants cause a refusal; this is not an overlay-upgrade package.
- The initial reference gate is `M2P-*`, ARM32 and MU `2678`. This is a conservative input restriction, **not a compatibility approval**, even for all MU2678 units.
- Stable power and the target unit's normal update prerequisites are still required. Update completion does not establish successful library loading or visible video.
- A `Done.txt` marker records installer completion with functional validation still pending. No challenge code, vehicle identity, private key or OEM authorization credential is supplied.

See [installation and recovery](docs/INSTALL_AND_RECOVERY.md) (Chinese). Do not force a different firmware past the gate or use the upstream repair tools as a substitute for a reviewed migration plan.

## What has actually been checked

The V1 offline records cover the 44-file handoff, the unchanged 429-file frozen baseline, 68 Java classes / 613 methods, and byte-for-byte preservation of 67 non-binding classes. Two Native test-gate adaptations were checked against pinned input hashes and actual Thumb-instruction emulation. The original update entry was replayed in emulation; installer behavior was exercised with isolated host fixtures.

These are **offline checks**, not SD-installation or visible-projection acceptance on a vehicle. The modified universal V1 candidate still requires real loading, visible first-frame, map/compass transitions, USB and wireless tests separately, performance, recovery, upgrade and uninstall validation. The old `CODE=13` root cause is not declared resolved. Historical user reports about another payload do not validate this candidate.

The new upstream ZIP was checked for archive CRC and structure on 2026-11-07. Its author's statements about cold-start fixes and removal of device binding remain **upstream claims**, not new test results for this repository. See [validation status](docs/VALIDATION.md) and [the full-edition record](docs/UPSTREAM_AND_FULL_EDITION.md).

## Languages, source material and build limits

| Material | What it is |
| --- | --- |
| Java under `research` | Decompiled classes for reading and analysis; not a complete OEM source tree |
| Native C-like files | Decompiled pseudocode, with inferred types and analysis addresses; not the original compilable C/C++ project |
| ARM32 ELF libraries / disassembly | Existing runtime material and static analysis, with candidate changes documented separately |
| `src/UniversalVariant.java` | Actual Java/ASM transformation-tool source |
| `src/install-universal.sh`, `src/dio_manager.sh` | Reviewable installer and launch-shim shell source |
| Python / pyelftools / Unicorn | Offline packaging, hash, ELF and instruction-replay checks; not a QNX playback test |
| Markdown / JSON / ZIP / SHA256 | Documentation, manifests and separately managed publication assets |

Do not describe the recovered material as a complete original-source release or claim that the Native libraries can be rebuilt from the pseudocode. Target-specific OEM dependencies and ABI verification are still necessary. See [source and build notes](docs/SOURCE_AND_BUILD.md) and [runtime internals](docs/RUNTIME_INTERNALS.en.md).

## Attribution and collaboration

**Much of the implementation basis and research material originates from audijiJQ / AUDIJI's MH2P program.** The original author's public project is [AUDI_MH2P_Altscreen_Carplay-maps](https://github.com/audijiJQ/AUDI_MH2P_Altscreen_Carplay-maps). The Type111 and navigation implementations must not be represented as wholly original work written from scratch by this repository's maintainers.

Project maintenance and integration are organized by [omonob](https://github.com/omonob). [LuKa / luka-dev](https://github.com/luka-dev) is an invited joint developer; the repository invitation was still pending when checked on 2026-11-07. Actual contributions should be recorded through commits and reviews, not inferred from an invitation. Attribution to the original author is separate from project co-maintainer status and does not imply endorsement.

The original installer's `Copyright (c) 2026 audijiJQ` and SPDX MIT notice are retained. That notice is **not a package-wide license** for every ELF, Java class, OEM framework, asset or decompilation. An earlier publication date does not supply a missing third-party license. This update links to the upstream full package; it does not newly redistribute that ZIP or the unreleased full decompilation. See [third-party notices](THIRD_PARTY_NOTICES.md).

Private handoffs, internal maintenance inputs, device challenges and identity data, pairing secrets, private keys and SDK/license material are not publication assets. This project does not represent Audi, Apple or QNX, and makes no claim of their certification.

## Planned work — not shipped features

1. Long-press switching to a **center-screen mirror**. The existing OEM-map / Type111 selector is not that feature.
2. An OEM-style settings menu for map, mirroring, navigation-card and related options.
3. Feasibility work on Apple-ecosystem audio / surround effects. There is no MH2P implementation or verification of formats, discrete channels, rendering or audible results. No Apple Spatial Audio / Dolby Atmos support or certification is claimed.

Working features on MHI2 or MHI2Q do not automatically establish MH2P support. Future releases must identify their own payloads, firmware scope and test evidence.
