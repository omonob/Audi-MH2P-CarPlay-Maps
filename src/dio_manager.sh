#!/bin/sh
# Artifact label: 2026-10-24; universal test adaptation: 2026-11-04.
# Plain, reviewable launch shim. No identity reads, service kills or network edits.
BASE=/mnt/app/eso/hmi/lib/mh2p-universal-test
STOCK=/mnt/app/eso/bin/apps/dio_manager.mh2p-test-stock
MODE=/mnt/persist_new/carplay/mhi2p_altscreen_stage/mode
if [ -r "$MODE" ] && [ -r "$BASE/libcarplay_altscreen_hook.so" ] && [ -r "$BASE/libcarplay_rgi_hook.so" ]; then
    read mode < "$MODE"
    if [ "$mode" = altscreen ]; then
        CP_RGI_ENABLE=1
        CP_RGI_INJECT=1
        CP_RGI_START_API=1
        CP_RGI_START_DEPLOY=0
        LD_PRELOAD="$BASE/libcarplay_altscreen_hook.so:$BASE/libcarplay_rgi_hook.so${LD_PRELOAD:+:$LD_PRELOAD}"
        export CP_RGI_ENABLE CP_RGI_INJECT CP_RGI_START_API CP_RGI_START_DEPLOY LD_PRELOAD
    fi
fi
exec "$STOCK" "$@"
