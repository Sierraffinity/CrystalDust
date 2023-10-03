#!/usr/bin/python3

import sys, struct

with open(sys.argv[1], 'rb') as f:
    data = f.read()
    count = len(data) // 2
    shorts = struct.unpack('H'*count, data)
    data = list()
    for x in range(len(shorts)):
        tile = shorts[x] & 0x3FF
        palette = shorts[x] & 0xFC00
        tile += int(sys.argv[2])
        data.append((tile & 0x3FF) | palette)
    data = struct.pack('H'*count, *data)

with open(sys.argv[1], 'wb') as f:
    f.write(data)
