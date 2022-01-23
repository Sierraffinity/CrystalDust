#!/usr/bin/python3

from sys import argv
import os, subprocess, struct

if __name__ == '__main__':
    is_secondary = argv[2] == "1"
    path = os.sep.join([os.curdir, 'data', 'tilesets', 'primary' if not is_secondary else 'secondary', argv[1]])

    with open(os.sep.join([path, 'metatile_attributes.bin']), 'rb') as f:
        data = f.read()

    num_metatiles = int(len(data) / 2)

    new_data = bytearray(num_metatiles * 2)
    for i in range(0, num_metatiles):
        behavior = data[i * 2]
        if behavior == 0x2A: # stairs
            behavior = 0
        elif behavior >= 0x6C and behavior <= 0x6F: # staircase
            behavior -= 0x40
        elif behavior == 0x81: # bookshelf
            behavior = 0xE2
        elif behavior == 0x82:  # pokemart shelf
            behavior = 0
        elif behavior == 0x84: # signpost
            behavior = 0x7E
        elif behavior == 0x87: # pokemon center
            behavior = 0x81
        elif behavior == 0x88: # pokemon mart
            behavior = 0x82
        elif behavior >= 0x89 and behavior <= 0x8B:  # dishes, sink, drawers
            behavior = 0
        elif behavior == 0x90: # fridge
            behavior = 0
        elif behavior == 0x93: # chart
            behavior = 0
        elif behavior == 0x94: # picture
            behavior = 0
        elif behavior == 0x95: # machine
            behavior = 0
        elif behavior == 0x96: # phone
            behavior = 0
        elif behavior == 0x97: # computer
            behavior = 0
        elif behavior == 0x9B: # coffee mug
            behavior = 0
        elif behavior >= 0x9C and behavior <= 0x9D: # window
            behavior = 0x88
        elif behavior == 0x9E: # machine
            behavior = 0
        elif behavior == 0xA3: # card thing
            behavior = 0
        new_data[i * 2] = behavior
        bg = data[i * 2 + 1]
        if bg & 0x20 == 0x20:
            bg = 0x10
        new_data[i * 2 + 1] = bg

    with open(os.sep.join([path, 'metatile_attributes.bin']), 'wb+') as f:
        f.write(new_data)

