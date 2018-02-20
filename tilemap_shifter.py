#!/usr/local/bin/python3

import sys

with open(sys.argv[1], 'rb') as f:
    data = bytearray(f.read())
    for x in range(0, len(data)):
        if x % 2 == 0:
            data[x] += int(sys.argv[2]) & 0xFF
        else:
            data[x] += (int(sys.argv[2]) >> 8) & 0x3

with open(sys.argv[1], 'wb') as f:
    f.write(data)
