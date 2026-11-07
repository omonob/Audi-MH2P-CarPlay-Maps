"""Read-only checks for the 2026-11-07 bilingual MH2P documentation update.

Run from any directory. No vehicle, updater, proprietary SDK or network I/O.
The default baseline is the last existing V1 documentation commit. This is
an update-scope check, not an assertion of vehicle compatibility or rights.
"""
from pathlib import Path
import argparse
import hashlib
import json
import re
import subprocess
from urllib.parse import unquote, urlsplit

ROOT = Path(__file__).resolve().parents[1]
BASE = '071cb9d252e84104b4abda140b289aa669a254b1'
ALLOWED = {
    'README.md', 'README.en.md', 'THIRD_PARTY_NOTICES.md', 'CHANGELOG.md',
    'SHA256SUMS.txt', 'docs/ARCHITECTURE.md',
    'docs/RUNTIME_INTERNALS.zh-CN.md', 'docs/RUNTIME_INTERNALS.en.md',
    'docs/UPSTREAM_AND_FULL_EDITION.md',
    'tools/verify_documentation.py',
    'validation/DOCUMENTATION_UPDATE_20261107.json',
}
DOCS = sorted(n for n in ALLOWED if n.endswith('.md'))


def git(*args):
    proc = subprocess.run(['git', *args], cwd=ROOT, capture_output=True,
                          text=True, encoding='utf-8', errors='strict', check=True)
    return proc.stdout.splitlines()


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--base', default=BASE)
    parser.add_argument('--check-sums', action='store_true')
    args = parser.parse_args()
    errors = []
    changed = set(git('diff', '--name-only', args.base, '--'))
    changed.update(git('ls-files', '--others', '--exclude-standard'))
    if changed - ALLOWED:
        errors.append('Changes outside documentation allowlist: ' + repr(sorted(changed - ALLOWED)))

    link_count = 0
    for name in DOCS:
        path = ROOT / name
        content = path.read_text(encoding='utf-8')
        if '\ufffd' in content:
            errors.append('Encoding replacement character: ' + name)
        if len(re.findall(r'^```', content, re.M)) % 2:
            errors.append('Unpaired fenced block: ' + name)
        if re.search(r'(?:gh[pousr]_[A-Za-z0-9]{30,}|github_pat_[A-Za-z0-9_]{30,}'
                     r'|-----BEGIN (?:RSA |EC |OPENSSH )?PRIVATE KEY-----'
                     r'|C:\\Users\\|D:\\VW\\|159\.75\.149\.99)', content):
            errors.append('Potential private material in changed documentation: ' + name)
        for target in re.findall(r'(?<!!)\[[^\]]+\]\(([^\s)]+)\)', content):
            parts = urlsplit(target)
            if parts.scheme or not parts.path:
                continue
            local = (path.parent / unquote(parts.path)).resolve()
            if not local.is_relative_to(ROOT.resolve()) or not local.is_file():
                errors.append('Broken/out-of-tree link: ' + name + ' -> ' + target)
            link_count += 1

    for name in ('README.en.md', 'docs/RUNTIME_INTERNALS.en.md', 'docs/RUNTIME_INTERNALS.zh-CN.md'):
        text = (ROOT / name).read_text(encoding='utf-8')
        for marker in ('Type111', 'audijiJQ', 'MHI2Q'):
            if marker not in text:
                errors.append('Missing scope/provenance marker: ' + name + ' / ' + marker)

    upstream = (ROOT / 'docs/UPSTREAM_AND_FULL_EDITION.md').read_text(encoding='utf-8')
    for marker in ('117ae13c1197099d20c3d40b80a2af9aaab99e97',
                   'a62292f82fab79780c775f55127dbe3402bdb0eb752a8ef62027b8a1294074f4',
                   '1249288', 'v1.0.0-test.1'):
        if marker not in upstream:
            errors.append('Missing upstream/version identity: ' + marker)

    if args.check_sums:
        listed = set()
        for line in (ROOT / 'SHA256SUMS.txt').read_text(encoding='utf-8').splitlines():
            sha, name = line.split('  ', 1)
            path = (ROOT / name).resolve()
            if name in listed or not path.is_relative_to(ROOT.resolve()) or not path.is_file():
                errors.append('Invalid checksum entry: ' + name)
            elif digest(path) != sha:
                errors.append('Checksum differs: ' + name)
            listed.add(name)
        actual = {p.relative_to(ROOT).as_posix() for p in ROOT.rglob('*') if p.is_file()
                  and '.git' not in p.relative_to(ROOT).parts
                  and p.name != 'SHA256SUMS.txt'}
        if actual != listed:
            errors.append('Checksum inventory differs: ' + repr(sorted(actual ^ listed)))

    result = dict(result='FAIL' if errors else 'PASS', documentation_files=len(DOCS),
                  relative_file_links_checked=link_count,
                  changed_files=sorted(changed), checksum_check=args.check_sums,
                  runtime_or_installer_changes=False if not changed - ALLOWED else 'NOT_ESTABLISHED',
                  vehicle_io=False, errors=errors)
    print(json.dumps(result, ensure_ascii=False, indent=2))
    raise SystemExit(1 if errors else 0)


if __name__ == '__main__':
    main()
