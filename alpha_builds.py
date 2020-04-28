#!/usr/bin/python3

from sys import argv
from pathlib import Path
import os, subprocess, zlib

if __name__ == '__main__':
    with open("alpha_testers.txt", 'r') as f:
        for _, line in enumerate(f):
            line = line.rstrip('\n')
            crc = hex(zlib.crc32(bytes(line, encoding='utf8')))
            print(crc)
            subprocess.call(["make", "tidy"])
            subprocess.call(["make", "-j8", "RELEASE_ID=" + crc])
            os.rename(r'CrystalDust.gba', r'CrystalDust_' + line + r'.gba')
        subprocess.call(["make", "tidy"])
