#!/usr/bin/python3.8

from sys import argv
import os, subprocess, struct
from pathlib import Path

def with_ext(path, ext):
    return path.with_name(path.stem.split('.')[0] + ext)

def scaninc(params):
    process = subprocess.run([os.sep.join([os.curdir, 'tools', 'scaninc', 'scaninc']), "-I", "include", "-I"] + [params], capture_output=True, text=True)
    return process.stdout.splitlines()

Path.with_ext = with_ext

if __name__ == '__main__':
    files = scaninc(argv[1])
    missing_files = [Path(x) for x in files if (os.path.exists(x) == False)]
    source_files = list()
    for file in missing_files:
        if ".4bpp" in file.suffixes or ".8bpp" in file.suffixes:
            source_files.append(file.with_ext('.png'))
        elif ".bin" in file.suffixes:
            source_files.append(file.with_ext('.bin'))
        elif ".gbapal" in file.suffixes:
            source_files.append(file.with_ext('.pal'))
    [print(x) for x in source_files]
    if len(argv) > 2 and argv[2]:
        [subprocess.run(["git", "checkout", x]) for x in source_files]
