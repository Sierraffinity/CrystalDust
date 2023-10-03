#!/usr/bin/python3

from sys import argv
import os, subprocess

with open(argv[1], 'rb') as f:
    f.seek(int(argv[2], base=16), 0)
    data = f.read(512)

for i in range(0, 16):
    filename = os.sep.join([argv[3], format(i, '02')])
    with open(filename + '.gbapal', 'wb+') as f:
        f.write(data[i * 32:i * 32 + 32])
    subprocess.call(["/mnt/c/CrystalDust/tools/gbagfx/gbagfx", filename + '.gbapal', filename + '.pal'])
