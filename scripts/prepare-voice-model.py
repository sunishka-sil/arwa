#!/usr/bin/env python3
"""Download/verify the voice-commands branch's model and package it for offline Android use."""
import hashlib
from pathlib import Path, PurePosixPath
import subprocess
import sys
import zipfile

ROOT = Path(__file__).resolve().parent.parent
NAME = "vosk-model-small-en-us-0.15"
SHA256 = "30f26242c4eb449f948e42cb302dd7a686cb29a3423a8367f99ff41780942498"
DEST = ROOT / "android-glasses/app/src/main/assets/model-en-us"
CACHE = ROOT / "android-glasses/.cache"

def main():
    if len(sys.argv) > 1:
        archive = Path(sys.argv[1])
    else:
        CACHE.mkdir(parents=True, exist_ok=True)
        archive = CACHE / (NAME + ".zip")
        if not archive.exists():
            subprocess.run(["curl", "--fail", "--location", "--max-time", "180",
                            "https://alphacephei.com/vosk/models/" + NAME + ".zip", "--output", str(archive)], check=True)
    if hashlib.sha256(archive.read_bytes()).hexdigest() != SHA256:
        raise SystemExit("Speech model checksum mismatch. Remove the cached download and try again.")
    DEST.mkdir(parents=True, exist_ok=True)
    with zipfile.ZipFile(archive) as source:
        for item in source.infolist():
            relative = PurePosixPath(item.filename).relative_to(NAME)
            if ".." in relative.parts or relative.is_absolute():
                raise SystemExit("Invalid path in model archive")
            target = DEST.joinpath(*relative.parts)
            if item.is_dir():
                target.mkdir(parents=True, exist_ok=True)
            else:
                target.parent.mkdir(parents=True, exist_ok=True)
                target.write_bytes(source.read(item))
    (DEST / "uuid").write_text(SHA256 + "\n")
    print("Prepared offline Vosk English model in", DEST)

if __name__ == "__main__":
    main()
