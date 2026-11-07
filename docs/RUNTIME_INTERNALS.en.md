# MH2P CarPlay cluster projection: runtime internals

[中文](RUNTIME_INTERNALS.zh-CN.md) · [Project overview](../README.en.md) · [Upstream full edition](UPSTREAM_AND_FULL_EDITION.md)

Documentation date: **2026-11-07, Asia/Shanghai**. Historical material label: 2026-10-24. Full-sample offline analysis: 2026-11-01. No-card universal V1 adaptation: 2026-11-04.

## 1. Scope and evidence

This explanation separates **video, display control, navigation data and card presentation**. Much of the implementation basis and research material originates from [audijiJQ / AUDIJI's MH2P program](https://github.com/audijiJQ/AUDI_MH2P_Altscreen_Carplay-maps), not original code written from scratch by this repository's maintainers. This is an independently written explanation, not an additional full third-party source distribution.

The evidence consists primarily of existing binary disassembly/decompilation and Java-class analysis. It is not a live trace collected by this update and not a complete original-source project. Three products must remain distinct:

- The **historical full sample** contains the navigation-card renderer and platform integration discussed below.
- This repository's **V1 test candidate** intentionally removes that presentation chain while preserving native video and navigation data interfaces.
- The **new upstream ZIP** has only been checked for archive structure, CRC and SHA256 here. Its latest runtime payload has not been executed or recovered in this update. Historical function behavior and offsets are not independently verified facts about that new ZIP.

All display IDs, dimensions and layout details below are sample-specific. They are not portable constants for MHI2, MHI2Q or every MH2P firmware.

## 2. Four cooperating paths

```text
iPhone CarPlay session
  +-- Type111 video --> AltScreen hook --> OEM Screen receiver/decoder --> DInt 62 --+
  +-- navigation data --> RGI data hook --> state --> Java maneuver/BAP/Komo --+    |
                                                                            |    |
Historical full sample: navigation + nav_dint hook --> EGL/KDK card --> DInt 20 +    |
                                                                                 |
Java DisplayManager / DSI: preserve OEM context; compose map33/video62/card20 -------+
  --> OEM display services --> instrument-cluster output
```

The phone produces a separate alternate-screen video stream. This is not repeated center-display screenshot copying. Navigation instructions also have a separate platform-data/presentation path. A working video stream, a visible maneuver arrow, a registered window and a successfully decoded first frame are different outcomes.

## 3. Component responsibilities

| Component | Responsibility | What it is not |
| --- | --- | --- |
| `dio_manager` and launch shim | Load hooks in the intended process, then run the local OEM decoder entry with its arguments | A complete replacement video decoder |
| `libcarplay_altscreen_hook.so` | Alternate-screen advertisement, session/TCP handoff, clock integration, DInt adaptation | A center-display screenshotter or proven software H.264 decoder |
| `libcarplay_rgi_hook.so` | Navigation capability/message handling and state publication | A disposable card-only graphics library |
| `CarPlayDSIManager`, `CarPlayClusterIntegration` | Session/display lifecycle and navigation-service integration | The OEM video-decoding backend |
| `CarPlayManeuverMapper` | Translate phone maneuvers, directions and angles into platform descriptors | A single arrow image |
| `DisplayManager` / DSI | Select/confirm displayable compositions and restore the OEM context | A direct physical-display port selector |
| Historical `navigation_dint_launcher`, `libnav_dint_hook.so` | Hook navigation-process DInt/EGL presentation | Type111 packet reception or video decoding |
| plate / pos / layout controls | Card backing, shape, position and layout selection | The alternate-video resolution itself |

## 4. Startup requires both Native and Java integration

A `.so` copied to storage is not proof of a loaded hook. It must be present in the process that actually calls the intended receiver/display interfaces. Java integration must likewise be loaded from the active classpath to coordinate the display and navigation services.

The no-card V1 installer adds a dedicated JAR ahead of the existing HMI boot classpath and installs a readable `dio_manager` shim. The shim preserves the original arguments and ultimately `exec`s the local backed-up OEM decoder. In the existing `altscreen` mode it loads the AltScreen hook, then the RGI data hook, preserving previous preload content. Its configuration includes `CP_RGI_ENABLE=1`, `CP_RGI_INJECT=1`, `CP_RGI_START_API=1`, and `CP_RGI_START_DEPLOY=0`; the last value does not deploy the card renderer.

The historical full package also depends on navigation-process wrapping, card rendering and layout controls. Flipping one variable is not a complete restoration of that dependency chain. The historical original installer also includes maintenance-network/SSH shutdown behavior; copying it into a new candidate is not a reviewed migration strategy. See [installation and recovery](INSTALL_AND_RECOVERY.md).

## 5. Capability advertisement and phone-side layout

The historical hook adapts capability queries such as `AirPlayCopyServerInfo` and platform properties to advertise another display. The sample describes 1920×600 pixels, physical dimensions 293×92, a separate screen identifier and `maxFPS=60`, with several view-area/safe-area configurations.

These properties tell the phone how to lay out a separate cluster view. They do not establish that a receiver window exists or that frames are arriving. Pixel dimensions, physical dimensions, view areas and safe areas have different roles.

The sample can update the view area at runtime, causing the phone to reconsider its drawing area. Platform card-position files belong to another coordinate layer. Neither form of layout control replaces video reception, decoding or composition.

## 6. SETUP and the independent video connection

The historical hook first calls the original `AirPlayReceiverSessionSetup`, then handles an eligible `type=111` stream with a valid `streamConnectionID`. It creates a **separate Screen object** rather than replacing the main-screen object.

```text
Original SessionSetup
  -> alternate Screen_Create / Screen_Setup
  -> derive/set security using the current paired session
  -> open a separate TCP listener and return its dataPort
  -> phone connects; SocketAccept -> NetSocket_CreateWithNative
  -> wait for the matching main session's successful StartSession
  -> set time synchronizer -> StartSession -> UpdateState(1) -> ProcessFrames
```

The analyzed branch uses `PairingSessionDeriveKey` and `Screen_SetChaChaSecurityInfo`. This is media-session security, not installation-package challenge binding and not a replacement for OEM CarPlay authorization. No pairing keys, device identity or OEM authorization credentials are distributed in this explanation.

This branch alone does not prove compatibility with every USB/wireless transport or phone. Those combinations require separate evidence. Removal of the upstream package's per-device binding is also a different issue from phone-session security.

## 7. Startup ordering, clocks and socket ownership

The alternate-screen startup depends on the matching main session and its context. The sample uses a condition variable to wait for the main `StartSession`, with thread-local markers distinguishing main-screen calls from alternate-screen calls.

The time synchronizer forwards the OEM AirTunesClock-related synchronized NTP time and ticks. Arbitrary local wall-clock timestamps are not an equivalent substitute. A successful `StartSession` return is an API result, not proof of the first visible frame.

`ProcessFrames` receives the Screen object, OEM NetSocket and session parameters, **not a single RGB image**. The analyzed hook delegates continuous packet/frame handling to the OEM backend. Once the native socket is wrapped, ownership is transferred; a separate duplicate is retained for shutdown wakeup. Closing resources twice or reusing an in-flight object on reconnection would violate that lifetime model.

## 8. Decoder, CPU and GPU: known and unknown

The hook calls OEM `AirPlayReceiverSessionScreen_*` APIs rather than implementing a complete H.264-to-RGB screenshot loop itself. That delegation is visible in the analyzed call sites.

The complete matching MH2P OEM backend is not present in the research material. Consequently this document does not identify a verified decoder engine, OMX component, exact CPU/GPU split, zero-copy path, buffer count or final scan-out route. **The MHI2Q Qualcomm OMX/NV12/RGB-snapshot path must not be presented as an MH2P fact.** Delegating to the OEM decoder does not imply zero CPU overhead elsewhere.

Similarly, hooking an EGL presentation stage for cards does not make that hook a video decoder. The existence of graphics APIs alone does not prove end-to-end hardware acceleration or zero-copy presentation.

## 9. DInt and Java/DSI composition

The historical `dint_create_window` wrapper changes request 59 into displayable 62 only under alternate-screen ownership or strict geometry conditions. Unrelated windows retain their identifiers. Successful creation is reported before Java asks the cluster's display manager to include the new element in the current context.

| Identifier space | Meaning in the analyzed sample |
| --- | --- |
| Type110 / Type111 | Main/alternate media stream types, not DInt window numbers |
| 59 -> 62 | Alternate-screen DInt window/displayable adaptation |
| 33 | Preserved OEM-map displayable |
| 20 | Platform KDK/RGI navigation presentation in the full sample |
| External terminal 1 -> internal display 4 | This Java/DSI cluster mapping; a different namespace from 59/62 |

`DisplayManager` preserves other members of the OEM context, adds 62, and in the full sample coordinates the ordering of 20 when present. It requests `showDisplayables`, waits for the matching `showDisplayablesResult` session ID, and checks the returned list. Sending the request is not a composition acknowledgment.

OEM-map / phone-view selection uses composition and opacity of map33/video62. It neither selects a physical connector by number nor necessarily stops the receiver. A decompiled function containing a position-setting call is not proof that its branch is reachable in normal operation.

## 10. Request IDs, generations and state transitions

Java writes request-tagged control state to `/tmp/cluster_ctl`; Native reports through `/tmp/cluster_mirror.state`. Acknowledgments must belong to the same request. Process/stream generations distinguish the current session from stale state left by a previous one.

```text
Session available -> rendering request -> starting -> registered
  -> DSI composition request -> matching acknowledgment -> health check -> display
Exit / display-off / generation change
  -> retire old request -> idle/released confirmation -> restore OEM context
```

| Observation | Establishes | Does not establish |
| --- | --- | --- |
| Returned dataPort | SETUP provided an endpoint | Phone connection or video arrival |
| `registered` | Alternate DInt window creation | Visible first video frame |
| DSI acknowledgment containing 62 | Accepted composition | Non-black, advancing video |
| `/tmp/carplay_kdk.ready` | Navigation/KDK presentation readiness | Type111 decoder success |
| `maxFPS=60` | Advertised/requested upper limit | Measured 60 FPS, scan rate or throughput |

A cached file or an ACK from an earlier generation is not current registration or successful cleanup.

## 11. How navigation information becomes an arrow

`libcarplay_rgi_hook.so` processes navigation-related iAP2/AirPlay capabilities, messages and transport activity, then publishes `/tmp/cluster_cp.state`. Java reads the state and feeds platform services. The handled data includes current/next roads and city, maneuver type, direction/angle, next-maneuver distance and unit, remaining destination distance/time, ETA, lanes, roundabouts and route start/stop.

**An arrow is not just a bitmap or a single enable flag.** In the historical Java implementation, `CarPlayManeuverMapper` translates phone maneuvers into platform maneuver/direction values. `CarPlayClusterIntegration` builds descriptors and updates `CombiBAPServiceNavi`; Komo/OEM navigation integration publishes corresponding road, distance and route state.

```text
Phone maneuver + turn angle/direction + roundabout information
  -> maneuver mapping
  -> platform descriptor + distance/unit + road text
  -> CombiBAP / Komo / navigation services
  -> platform arrow, text, lane and card presentation
```

Related paths include `updateLaneGuidance`, `publishPhoneEta`, `pushKomoNavInfo`, guidance start/stop and stale-state cleanup. Correctly displaying one symbol does not prove correct ETA, units, lanes or roundabout exits. Available fields also depend on the navigation app.

BAP/Komo here denotes observed service interfaces. It is not proof that the hook directly transmits raw frames on a physical CAN/MOST bus, or that every service output was vehicle-tested by this update.

## 12. Who renders the card?

In **this historical MH2P full sample**, navigation data passes through Java and OEM services into the platform presentation path. `libnav_dint_hook.so` runs in the navigation process, cooperates with DInt/EGL lifecycle and selected `eglSwapBuffers` stages to render/clear the RGI overlay, and publishes KDK readiness. Displayable20 then cooperates with the map/video composition.

This should not be described as “the iPhone already draws every card into the video.” The phone provides video and navigation state, but platform descriptors, services, presentation layers and the navigation hook participate in this card path. A phone-composed view-area card on another platform is a different implementation.

The full dependency chain includes the navigation-data hook, Java mapping/integration, OEM BAP/Komo services, navigation wrapper and hook, DInt/EGL, plate/position layouts and display composition. Restoring one library in isolation can leave data without presentation, a blank backing layer, an occluded card or stale graphics.

The old no-card V1 intentionally omits the graphics library, wrapper, layouts and Java presentation integration. Adding this document does not restore them to that installer.

## 13. Layout and coordinate layers

The historical control material includes `sport_big`, `sport_small`, `classic_big` and `classic_small` plate/position variants. They arrange the card within the active cluster layout, not four separate video decoders.

- Type111 pixel/physical dimensions influence phone-side layout.
- View areas/safe areas constrain the phone's drawing region.
- Plate controls affect platform-card backing, shape and drawing parameters.
- Position controls affect card location. The historical layout script describes rereading the plate per frame, while position changes apply at the next route push.
- DSI context and layer order determine whether cluster elements cover the map/card.

These controls require target-firmware and visual verification. Historical reload timing is not a verified promise about the new upstream ZIP. Nor can MU1003 layout mappings replace MH2P-specific evidence.

## 14. Buttons, map selection and zoom

The historical sample has an approximately two-second BACK long-press path switching OEM-map33 / alternate-video62 while keeping the alternate session alive. Short-press forwarding and long-press consumption are state-dependent to avoid duplicate actions.

When the phone view is selected, wheel-related control can reach `changeMapZoomLevel` through the navigation/control path. This is not video re-encoding or general control of every phone UI.

**Map-source selection is not center-screen mirroring.** Future mirroring requires its own main-screen-output binding, object ownership, display routing, input and lifecycle tests. Renaming the existing BACK action does not implement that feature.

## 15. Shutdown, reconnect and OEM-map restoration

The analyzed stop path marks the current operation for exit, wakes condition waits and blocked reception, retires the worker, stops/releases the Screen object and clears current window state. A new session must not reuse an in-flight Screen pointer, fd, request ID or composition acknowledgment.

Java coordinates session/stream generations with original-context restoration. A late `registered` or ACK from an exited generation must not re-enter display mode. Restoring the map requires composition/visibility confirmation, not merely process termination.

Connection, a static page, wheel input, returning to the OEM UI, actual disconnect, reconnect and cold boot are separate tests. Returning to the OEM UI may only change foreground ownership, leaving the phone and alternate stream active. Continued cluster video does not establish healthy center-screen video or input.

## 16. Performance, wireless and audio boundaries

A static phone view may emit fewer frames. Advertised limits, received frames, decoded frames, submitted buffers, compositor refreshes and physical scans must be counted separately. Bandwidth reporting should distinguish media payload, TCP/wireless overhead, averages/peaks and Wi-Fi link rate. Link rate is not actual video throughput.

This update does not measure MH2P FPS, latency, drops, bandwidth or decoder load, and adds no wireless receiver. Results from MHI2Q wireless experiments, another display's 59 Hz, or upstream statements are not measurements for this candidate.

Type111/video/navigation success also does not establish a new audio path. Future Apple-ecosystem surround work must verify transport, format, channels, authorized interfaces, decoding/rendering and hardware output separately. Bluetooth stereo, an audio effect and genuine multichannel/spatial audio are not interchangeable. No implementation, compatibility or certification is claimed here.

## 17. Failure isolation

| Symptom | First checks | Unsupported shortcut |
| --- | --- | --- |
| No alternate stream | Capabilities, matching SETUP, type/connectionID | Assume resolution is the cause |
| Endpoint but no video | TCP acceptance, security context, main-start gate, ProcessFrames lifetime | Treat listening as a connected session |
| Registered but black | Current-generation frame activity, OEM results, DSI list and opacity | Treat `registered` as visible playback |
| Video but no arrows | Navigation input, mapper, BAP/Komo, whether the variant contains presentation | Delete the data hook or rebuild the decoder |
| Arrow but missing ETA/lanes | App fields, units, guidance state and per-field publication | Treat one symbol as complete navigation acceptance |
| Blank card / missing corner | Original context, displayable20, plate/EGL state, cleanup | Change video buffers without evidence |
| Bad reconnect | Generation, stale ACKs, object/fd retirement, main-screen gate | Repeatedly erase pairing or copy foreign offsets |
| Center UI exits, cluster continues | Foreground/input and media-session states independently | Declare the phone disconnected |

## 18. Validation and evidence boundaries

The new documentation adds no vehicle result. Existing V1 offline records are described in [validation status](VALIDATION.md), `validation/JAVA_VARIANT.json`, `validation/NATIVE_PATCHES.json` and the other retained reports. A representative historical full-sample AltScreen input has SHA256 `ab20bb0316c71971a6f591ef090dce1e13c1422c082ceb03209d22ebd9cda17a`; that is not function-level validation of the new upstream ZIP.

The published `research` material covers the old V1 allowlist, not the full card chain it excluded. Explanations of that chain derive from existing local research; they do not mean that unreleased third-party source has been added as an attachment. The [upstream record](UPSTREAM_AND_FULL_EDITION.md) pins the newly public package URL, commit and hash to avoid version confusion.

A future full candidate should separately verify actual library/class loading, main/alternate first frames, each layout, each card combination, maneuver families and units, lanes/ETA, stop/reconnect/cold boot, BACK/zoom, USB and wireless independently, uninstall and power-loss recovery. Record **exact payload hashes, target firmware, phone/app, actual date, visible results and restoration**. Static interfaces, emulation or a successful test on another platform are not substitutes.
