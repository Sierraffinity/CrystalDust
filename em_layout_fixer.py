#!/usr/bin/python3

from sys import argv
import os, subprocess, array

def fixit(path, name):
    with open(os.sep.join([path, name]), 'rb') as f:
        data = f.read()

    new_data = array.array('H')
    new_data.frombytes(data)

    for i in range(0, len(new_data)):
        metatile_num = new_data[i] & 0x3FF
        move_perm = new_data[i] & 0xFC00
        if metatile_num >= 0x200:
            new_data[i] = ((metatile_num + 0x80) & 0x3FF) | move_perm

    with open(os.sep.join([path, name]), 'wb+') as f:
        f.write(new_data)


if __name__ == '__main__':
    path = os.sep.join([os.curdir, 'data', 'layouts', argv[1]])

    fixit(path, 'map.bin')
    fixit(path, 'border.bin')
