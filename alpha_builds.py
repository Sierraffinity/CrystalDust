#!/usr/bin/python3

from sys import argv
from pathlib import Path
from shlex import quote
import os, subprocess, zlib

def flips(params):
    subprocess.call(["/mnt/c/Hacking/Tools/Flips/flips-linux"] + params)

def create_bps(name):
    flips(["--create", "--bps", "/mnt/c/Hacking/Pokemon 3rd generation/Pokemon - Emerald Version (U).gba", "CrystalDust.gba", "alphas/CrystalDust_" + name + ".bps"])

def apply_bps(name):
    flips(["--apply", "--bps", "alphas/CrystalDust_" + name + ".bps", "/mnt/c/Hacking/Pokemon 3rd generation/Pokemon - Emerald Version (U).gba", "alphas/CrystalDust_" + name + ".gba"])

def build_and_encrypt(name):
    crc = hex(zlib.crc32(bytes(name, encoding='utf8')))
    subprocess.call(["make", "tidy"])
    subprocess.call(["make", "-j8", "modern", "RELEASE_ID=" + crc])
    create_bps(name)
    apply_bps(name)
    print(crc)

if __name__ == '__main__':
    os.makedirs("alphas", exist_ok=True)
    if len(argv) > 1:
        build_and_encrypt(argv[1])
    else:
        with open("alpha_testers.txt", 'r') as f:
            for _, line in enumerate(f):
                line = line.rstrip('\n')
                build_and_encrypt(line)
    subprocess.call(["make", "tidy"])
