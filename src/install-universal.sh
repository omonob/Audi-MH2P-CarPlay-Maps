#!/bin/ksh
# Artifact label: 2026-10-24. Test adaptation prepared: 2026-11-04.
# Based on the original audijiJQ installation workflow, SPDX: MIT (installer only).
# No package-wide license is implied. No challenge/identity inputs are used.
PATH=/proc/boot:/bin:/usr/bin:/sbin:/usr/sbin:/armle/bin:/armle/usr/bin
export PATH
umask 077
VERSION=2026.10.24-universal-test.1
APP=/mnt/app
CP=/mnt/persist_new/carplay
BASE=$APP/eso/hmi/lib/mh2p-universal-test
JAR=$APP/eso/hmi/lsd/jars/AppDevelopment-MH2P-Test.jar
LSD=$APP/eso/hmi/lsd/lsd.sh
DIO=$APP/eso/bin/apps/dio_manager
STOCK=$APP/eso/bin/apps/dio_manager.mh2p-test-stock
BACKUP=$CP/mh2p-universal-test-backup
MODE=$CP/mhi2p_altscreen_stage/mode
LOCK=/tmp/mh2p-universal-install.lock
media=
for p in /fs/sda0 /fs/sdb0 /fs/usb0_0; do
    if [[ -s "$p/Data/MH2P_TEST_PAYLOAD.cksum" && -s "$p/Data/AUDIJI" ]]; then
        [[ -z "$media" ]] || exit 7
        media=$p
    fi
done
[[ -n "$media" ]] || exit 7
mount -uw "$media" || exit 16
LOG=$media/INSTALL.log
ERROR=$media/ERROR.txt
DONE=$media/Done.txt
printf 'VERSION=%s\nSTATUS=PREFLIGHT\n' "$VERSION" > "$LOG"
fail(){
    printf 'INSTALL FAILED\nCODE=%s\nREASON=%s\nVERSION=%s\n' "$2" "$1" "$VERSION" > "$ERROR"
    printf 'FAILED code=%s reason=%s\n' "$2" "$1" >> "$LOG"
    sync
    exit "$2"
}
[[ ! -e "$DONE" && ! -e "$ERROR" ]] || fail "old result files present; use a fresh extracted card" 40
mkdir "$LOCK" || fail "another installer or interrupted attempt exists" 40
mounted=0
backup_ready=0
committed=0
cleanup(){
    result=$?
    if [[ "$result" -ne 0 && "$backup_ready" -eq 1 && "$mounted" -eq 1 ]]; then
        printf 'ROLLBACK_ATTEMPT=1\n' >> "$LOG"
        if cp -p "$BACKUP/lsd.sh" "$LSD" && cp -p "$BACKUP/dio_manager" "$DIO"; then
            printf 'ENTRYPOINT_ROLLBACK=OK; inactive test files retained for diagnosis\n' >> "$LOG"
        else
            printf 'ENTRYPOINT_ROLLBACK=FAILED; recover from backup before reboot\n' >> "$LOG"
        fi
    fi
    if [[ "$mounted" -eq 1 ]]; then sync; mount -ur "$APP" >> "$LOG" 2>&1; fi
    rmdir "$LOCK" 2>/dev/null
    exit "$result"
}
trap cleanup 0
trap 'fail "installation interrupted" 45' 1 2 15
[[ "$(uname -s)" = QNX ]] || fail "QNX required" 41
case "$(uname -m)" in armle|arm) ;; *) fail "32-bit ARM ABI required" 41 ;; esac
VERSION_FILE=/net/rcc/dev/shmem/version.txt
[[ -r "$VERSION_FILE" ]] || fail "firmware identity record unavailable; stop for compatibility review" 41
grep -E "^Variant[[:space:]]*=[[:space:]]*'M2P-" "$VERSION_FILE" >/dev/null || fail "MH2P M2P variant required" 41
# Conservative test scope. This is the input manifest's MU reference, NOT proof
# that all MU2678 trains are compatible. No VIN/FAZIT/UID is collected.
grep -E "^MainUnit version[[:space:]]*=[[:space:]]*'2678'" "$VERSION_FILE" >/dev/null || fail "MU outside the initial 2678 test scope; do not force installation" 41
for f in "$LSD" "$DIO"; do [[ -s "$f" && ! -L "$f" ]] || fail "original entry missing or symlinked" 41; done
for p in "$STOCK" "$DIO.org" "$APP/eso/bin/servicemgrmibhigh_orgapp" /mnt/swup/eso/bin/servicemgrmibhigh_orgapp "$APP/eso/hmi/lsd/.j" "$JAR" "$BASE" "$BACKUP" "$MODE"; do
    [[ ! -e "$p" && ! -L "$p" ]] || fail "existing installation or backup detected; no overlay upgrade" 40
done
grep 'Xbootclasspath' "$LSD" >/dev/null || fail "unknown HMI classpath layout" 43
count=$(awk '!/^[[:space:]]*#/ {s=$0;while(match(s,/Xbootclasspath(\/p)?:/)){n++;s=substr(s,RSTART+RLENGTH)}}END{print n+0}' "$LSD")
[[ "$count" = 1 ]] || fail "ambiguous HMI classpath; no automatic rewrite" 43
command -v cksum >/dev/null || fail "POSIX cksum unavailable" 42
command -v cmp >/dev/null || fail "comparison utility unavailable" 42
verify_payload(){
    seen='|'
    while read expected length name; do
        case "$name" in
            AppDevelopment.jar|libcarplay_altscreen_hook.so|libcarplay_rgi_hook.so|dio_manager.sh) ;;
            *) return 1 ;;
        esac
        case "$seen" in *"|$name|"*) return 1 ;; esac
        seen="$seen$name|"
        [[ -s "$media/Data/Payload/$name" && ! -L "$media/Data/Payload/$name" ]] || return 1
        actual=$(cksum "$media/Data/Payload/$name") || return 1
        set -- $actual
        [[ "$1" = "$expected" && "$2" = "$length" ]] || return 1
    done < "$media/Data/MH2P_TEST_PAYLOAD.cksum"
}
[[ "$(wc -l < "$media/Data/MH2P_TEST_PAYLOAD.cksum" | tr -d ' ')" = 4 ]] || fail "payload list incomplete" 42
verify_payload || fail "payload checksum/size mismatch" 42
[[ -d "$APP/eso/hmi/lsd/jars" && -d "$APP/eso/hmi/lib" && -d /mnt/persist_new && ! -L "$CP" && ! -L "$CP/mhi2p_altscreen_stage" ]] || fail "expected factory filesystem layout unavailable" 41
df -k "$APP" /mnt/persist_new >> "$LOG" 2>&1 || fail "filesystem status unavailable" 44
mkdir -p "$CP" || fail "persistent settings directory unavailable" 44
mkdir "$BACKUP" || fail "backup directory unavailable" 44
cp -p "$LSD" "$BACKUP/lsd.sh" && cp -p "$DIO" "$BACKUP/dio_manager" || fail "backup copy failed" 44
cmp "$LSD" "$BACKUP/lsd.sh" && cmp "$DIO" "$BACKUP/dio_manager" || fail "backup readback differs" 44
printf 'VERSION=%s\nSTATE=BACKED_UP_BEFORE_ENTRYPOINT_CHANGES\n' "$VERSION" > "$BACKUP/install.state"
backup_ready=1
mount -uw "$APP" >> "$LOG" 2>&1 || fail "app filesystem cannot be made writable" 44
mounted=1
mkdir "$BASE" || fail "test library directory unavailable" 44
cp -p "$BACKUP/dio_manager" "$STOCK" && chmod 755 "$STOCK" || fail "stock decoder recovery copy failed" 44
cmp "$STOCK" "$BACKUP/dio_manager" || fail "stock decoder copy differs" 44
cp "$media/Data/Payload/AppDevelopment.jar" "$JAR" && chmod 644 "$JAR" || fail "Java copy failed" 45
for n in libcarplay_altscreen_hook.so libcarplay_rgi_hook.so; do
    cp "$media/Data/Payload/$n" "$BASE/$n" && chmod 755 "$BASE/$n" || fail "native copy failed" 45
    cmp "$media/Data/Payload/$n" "$BASE/$n" || fail "native readback differs" 45
done
cmp "$media/Data/Payload/AppDevelopment.jar" "$JAR" || fail "Java readback differs" 45
sed 's#Xbootclasspath:#Xbootclasspath:/mnt/app/eso/hmi/lsd/jars/AppDevelopment-MH2P-Test.jar:#;s#Xbootclasspath/p:#Xbootclasspath/p:/mnt/app/eso/hmi/lsd/jars/AppDevelopment-MH2P-Test.jar:#' "$BACKUP/lsd.sh" > "$BASE/lsd.pending" || fail "HMI draft failed" 43
grep 'Xbootclasspath\(/p\)\?:/mnt/app/eso/hmi/lsd/jars/AppDevelopment-MH2P-Test.jar:' "$BASE/lsd.pending" >/dev/null || fail "HMI draft not recognized" 43
chmod 755 "$BASE/lsd.pending"
cp "$media/Data/Payload/dio_manager.sh" "$BASE/dio.pending" && chmod 755 "$BASE/dio.pending" || fail "decoder draft failed" 45
cmp "$media/Data/Payload/dio_manager.sh" "$BASE/dio.pending" || fail "decoder draft differs" 45
mkdir -p "$CP/mhi2p_altscreen_stage" || fail "mode directory failed" 45
printf 'altscreen\n' > "$CP/mhi2p_altscreen_stage/mode.pending" || fail "mode draft failed" 45
verify_payload || fail "media changed before activation" 42
mv "$BASE/dio.pending" "$DIO" && mv "$BASE/lsd.pending" "$LSD" && mv "$CP/mhi2p_altscreen_stage/mode.pending" "$MODE" || fail "entrypoint publication failed" 45
cmp "$DIO" "$media/Data/Payload/dio_manager.sh" || fail "installed decoder wrapper differs" 45
printf 'VERSION=%s\nSTATE=SCRIPT_COMPLETED_FUNCTIONAL_TEST_PENDING\n' "$VERSION" > "$BACKUP/install.state"
committed=1
sync
mount -ur "$APP" >> "$LOG" 2>&1 || fail "readonly remount failed; recover before reboot" 45
mounted=0
printf 'INSTALL_SCRIPT_COMPLETED_TEST_CANDIDATE\nVERSION=%s\nFUNCTIONAL_VALIDATION=PENDING\n' "$VERSION" > "$DONE"
printf 'STATUS=SCRIPT_COMPLETED; NO_REBOOT_OR_PLAYBACK_SENT\n' >> "$LOG"
sync
exit 0
