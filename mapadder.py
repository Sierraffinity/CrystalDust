import os
import re
import sys
import json
from collections import OrderedDict
import fnmatch
import glob

def main():
    matches = []
    for root, dirnames, filenames in os.walk('data/maps'):
        for filename in fnmatch.filter(filenames, 'map.json'):
            matches.append(os.path.join(root, filename))

    for filepath in matches:
        print("Processing %s..." % filepath)

        with open(filepath) as file:
            text = file.read()

        modified = text.splitlines()
        offset = 1  # insert after line
        for index, line in enumerate(text.splitlines()):
            if 'trainer_type' in line:
                modified.insert(index + offset, '%s"type": "original",' % ((line.count(' ') - 1) * " "))
                offset += 1

        with open(filepath, "w", newline='\n') as file:
            file.writelines('\n'.join(modified))
            file.write('\n')

if __name__ == '__main__':
    main()
