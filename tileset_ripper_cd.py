#!/usr/bin/python3

from sys import argv
import os, subprocess, struct

NUM_TILES_IN_PRIMARY = 640
NUM_TILES_TOTAL = 1024
NUM_METATILES_IN_PRIMARY = 640
NUM_METATILES_TOTAL = 1024

def gbagfx(params):
    subprocess.call([os.sep.join([os.curdir, 'tools', 'gbagfx', 'gbagfx'])] + params)

def create_image(path, data, is_compressed):
    filename = os.sep.join([path, "tiles"])
    with open(filename + (".4bpp" if not is_compressed else ".4bpp.lz"), 'wb+') as f:
        f.write(data)
    if is_compressed:
        gbagfx([filename + ".4bpp.lz", filename + ".4bpp"])
    gbagfx([filename + ".4bpp", filename + ".png", "-width", "16", "-palette", os.sep.join([path, "palettes/00.gbapal"])])

def create_pals(path, data):
    subdir = os.sep.join([path, 'palettes'])
    os.makedirs(subdir, exist_ok=True)
    for i in range(0, 16):
        filename = os.sep.join([subdir, format(i, '02')])
        with open(filename + '.gbapal', 'wb+') as f:
            f.write(data[i * 32:i * 32 + 32])
        gbagfx([filename + '.gbapal', filename + '.pal'])

def create_metatiles(path, data, num_metatiles):
    # Uncomment and edit the 9 in the last row to make mass palette edits
    data = bytearray(data)
    for i in range(0, num_metatiles):
        for j in range(0, 16, 2):
            if (data[(i * 16) + j + 1] >> 4) == 6:
                data[(i * 16) + j + 1] = (data[(i * 16) + j + 1] & 3) | (7 << 4)

    with open(os.sep.join([path, 'metatiles.bin']), 'wb+') as f:
        f.write(data)

def create_behavior(path, data, num_metatiles):
    new_data = bytearray(num_metatiles * 2)
    for i in range(0, num_metatiles):
        behavior = data[i * 2]
        new_data[i * 2] = behavior
        bg = data[i * 2 + 1]
        if bg == 0x30:
            bg = 0x10
        bg = bg ^ 1
        new_data[i * 2 + 1] = bg

    with open(os.sep.join([path, 'metatile_attributes.bin']), 'wb+') as f:
        f.write(new_data)

if __name__ == '__main__':
    with open(argv[1], 'rb') as f:
        f.seek(int(argv[2], base=16))
        tileset_header = struct.unpack('<??xxIIIII', f.read(24))

        is_compressed = tileset_header[0]
        is_secondary = tileset_header[1]

        num_tiles = NUM_TILES_IN_PRIMARY if not is_secondary else NUM_TILES_TOTAL - NUM_TILES_IN_PRIMARY
        num_metatiles = NUM_METATILES_IN_PRIMARY if not is_secondary else NUM_METATILES_TOTAL - NUM_METATILES_IN_PRIMARY
        
        if len(argv) > 4:
            num_metatiles = int(argv[4])
        
        image_ptr = tileset_header[2] - 0x8000000
        palette_ptr = tileset_header[3] - 0x8000000
        metatiles_ptr = tileset_header[4] - 0x8000000
        behavior_ptr = tileset_header[5] - 0x8000000

        f.seek(image_ptr)
        image = f.read(num_tiles * 32)
        f.seek(palette_ptr)
        palettes = f.read(512)
        f.seek(metatiles_ptr)
        metatiles = f.read(num_metatiles * 16)
        f.seek(behavior_ptr)
        behavior = f.read(num_metatiles * 2)

    path = os.sep.join([os.curdir, 'data', 'tilesets', 'primary' if not is_secondary else 'secondary', argv[3]])
    os.makedirs(path, exist_ok=True)
    create_pals(path, palettes)
    create_image(path, image, is_compressed)
    create_metatiles(path, metatiles, num_metatiles)
    create_behavior(path, behavior, num_metatiles)
