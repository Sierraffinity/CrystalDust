#!/usr/bin/python3

from sys import argv
import os, subprocess, struct

NUM_BYTES_PER_TILE = 32
NUM_FRAMES_PER_ANIMATION = 3
NUM_TILES_PER_SIZE = 4

def gbagfx(params):
    subprocess.call([os.sep.join([os.curdir, 'tools', 'gbagfx', 'gbagfx'])] + params)

def create_image(path, data, size):
    with open(path + ".4bpp", 'wb+') as f:
        f.write(data)
    frame_width = 2
    frame_height = 2
    if size > 1:
        frame_height = 4
    if size == 3:
        frame_width = 4
    gbagfx([path + ".4bpp", path + ".png", "-mwidth", str(frame_width), "-mheight", str(frame_height)])

def create_pal(path, data):
    with open(path + '.txt', 'w+') as f:
        f.write("const u8 DoorAnimPalettes_Test[] = { ")
        for pal in data:
            f.write(str(pal) + ", ")
        f.write("};")

if __name__ == '__main__':
    with open(argv[1], 'rb') as f:
        door_anim_table = 0x35B5D8
        if int(argv[2]) != 0:
            door_anim_table = int(argv[2], base=16)
        f.seek(door_anim_table)

        door_header = struct.unpack('<HBBII', f.read(12))

        while door_header[3] != 0 and door_header[0] != int(argv[3], base=16):
            door_header = struct.unpack('<HBBII', f.read(12))
        
        if door_header[3] != 0:
            size = door_header[2] + 1

            f.seek(door_header[3] - 0x8000000)
            image_data = f.read(size * NUM_BYTES_PER_TILE * NUM_TILES_PER_SIZE * NUM_FRAMES_PER_ANIMATION)
            f.seek(door_header[4] - 0x8000000)
            pal_data = f.read(size * NUM_TILES_PER_SIZE)

            path = os.sep.join([os.curdir, 'graphics', 'door_anims', argv[4]])
            create_image(path, image_data, size)
            create_pal(path, pal_data)
        else:
            print("Could not find door associated with metatile.")

