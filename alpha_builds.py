#!/usr/bin/python3

from sys import argv
from pathlib import Path
import os, subprocess, zlib

if __name__ == '__main__':
    with open("alpha_testers.txt", 'r') as f:
        Path(r'src/main.c').touch()
        Path(r'src/day_night.c').touch()
        Path(r'src/debug/debug_menu.c').touch()
        Path(r'src/field_control_avatar.c').touch()
        Path(r'src/field_player_avatar.c').touch()
        for _, line in enumerate(f):
            line = line.rstrip('\n')
            crc = hex(zlib.crc32(bytes(line, encoding='utf8')))
            print(crc)
            subprocess.call(["make", "-j8", "RELEASE_ID=" + crc])
            Path(r'src/main.c').touch()
            Path(r'src/day_night.c').touch()
            Path(r'src/debug/debug_menu.c').touch()
            Path(r'src/field_control_avatar.c').touch()
            Path(r'src/field_player_avatar.c').touch()
            os.rename(r'CrystalDust.gba', r'CrystalDust_' + line + r'.gba')

