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
    subprocess.call(["make", "tidy"])
    subprocess.call(["make", "-j8", "modern"])
    create_bps(name)
    apply_bps(name)

if __name__ == '__main__':
    os.makedirs("alphas", exist_ok=True)
    build_and_encrypt(argv[1])
    subprocess.call(["make", "tidy"])
