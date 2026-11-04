"""Read-only verification of downloaded MH2P TEST release assets and ZIPs."""
from pathlib import Path,PurePosixPath
from io import BytesIO
import argparse,hashlib,json,zipfile

def sha(b):return hashlib.sha256(b).hexdigest()
def checksum_zip(data):
    with zipfile.ZipFile(BytesIO(data)) as z:
        assert z.testzip() is None,'ZIP CRC failure'
        names=z.namelist();assert len(names)==len(set(names)),'Duplicate ZIP paths'
        for n in names:
            p=PurePosixPath(n);assert not p.is_absolute() and '..' not in p.parts and '\\' not in n,'Unsafe ZIP path'
        assert 'SHA256SUMS.txt' in names,'Missing inner checksums'
        for line in z.read('SHA256SUMS.txt').decode('utf-8-sig').splitlines():
            h,n=line.split('  ',1);assert n in names and sha(z.read(n))==h,('Inner hash',n)
        forbidden=['libnav_dint_hook','navigation_dint_launcher','ctl.bundle','.plate','.pos','DeviceBindingA','DeviceBindingB','DeviceBindingC','DeviceBindingD']
        assert not any(any(x in n for x in forbidden) for n in names),'Excluded card/binding asset'
        return len(names)

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('directory',type=Path);args=parser.parse_args()
    root=args.directory.resolve();m=json.loads((root/'RELEASE_MANIFEST.json').read_text(encoding='utf-8'))
    assert m['version']=='v1.0.0-test.1' and not m['formal_release'] and not m['device_binding']
    for line in (root/'SHA256SUMS.txt').read_text(encoding='utf-8-sig').splitlines():
        h,n=line.split('  ',1);p=(root/n).resolve();assert p.is_relative_to(root) and sha(p.read_bytes())==h,('Outer hash',n)
    out=[]
    for a in m['artifacts']:
        p=root/a['file'];b=p.read_bytes();assert len(b)==a['bytes'] and sha(b)==a['sha256']
        count=checksum_zip(b);out.append(dict(file=a['file'],bytes=len(b),sha256=a['sha256'],zip_entries=count))
    print(json.dumps(dict(result='PASS',artifacts=out,vehicle_io=False),ensure_ascii=False,indent=2))

if __name__=='__main__':main()
