#!/usr/bin/python3

from sys import argv
import os, subprocess, struct

def gbagfx(params):
    subprocess.call([os.sep.join([os.curdir, 'tools', 'gbagfx', 'gbagfx'])] + params)

def create_pal(path, data):
    with open(path + '.gbapal', 'wb+') as f:
        f.write(data)
    gbagfx([path + '.gbapal', path + '.pal'])

def create_image(path, data):
    with open(path + ".4bpp", 'wb+') as f:
        f.write(data)
    gbagfx([path + ".4bpp", path + ".png", "-width", "18", "-mwidth", "2", "-mheight", "4", "-palette", path + ".gbapal"])

if __name__ == '__main__':
    with open(argv[1], 'rb') as f:
        f.seek(int(argv[2], base=16))
        image_data = f.read(64 * 4 * 9)
        f.seek(int(argv[3], base=16))
        pal_data = f.read(32)

    path = os.sep.join([os.curdir, argv[4]])
    create_pal(path, pal_data)
    create_image(path, image_data)
