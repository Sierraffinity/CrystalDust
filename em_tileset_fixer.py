#!/usr/bin/python3

from sys import argv
import os, subprocess, array

if __name__ == '__main__':
    is_secondary = argv[2] == "1"
    path = os.sep.join([os.curdir, 'data', 'tilesets', 'primary' if not is_secondary else 'secondary', argv[1]])

    with open(os.sep.join([path, 'metatiles.bin']), 'rb') as f:
        data = f.read()

    new_data = array.array('H')
    new_data.frombytes(data)

    for i in range(0, len(new_data)):
        tile_num = new_data[i] & 0x3FF
        pal_flip = new_data[i] & 0xFC00
        if tile_num >= 0x200:
            new_data[i] = ((tile_num + 0x80) & 0x3FF) | pal_flip

    with open(os.sep.join([path, 'metatiles.bin']), 'wb+') as f:
        f.write(new_data)

