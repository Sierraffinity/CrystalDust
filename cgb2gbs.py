import sys
import os
import re
from pathlib import Path

def main():
    inDir = sys.argv[1]
    outDir = sys.argv[2]

    if not os.path.isdir(inDir):
        print("Directory {} does not exist. Exiting...".format(inDir))
        sys.exit()
  
    if not os.path.isdir(outDir):
        print("Directory {} does not exist. Exiting...".format(outDir))
        sys.exit()
    
    pathList = Path(inDir).glob('*.asm')
    outDirPath = Path(outDir)
    outDirPath.mkdir(parents=True, exist_ok=True)
    
    count = 0
    for path in pathList:
        try:
            with open(path, 'r') as inFile:
                with open(outDirPath / path.name, 'w') as outFile:
                    content = inFile.read()
                    outFile.write(content)
                    count += 1
                    print("%s processed..." % path.name, end='\r')
        except:
            sys.stderr.write('\033[KError processing file %s: %d files processed before error.\n' % (path.name, count))
            raise

    if count == len(pathList):
        print("%d files successfully processed." % count)
    else:
        sys.exit('\nError during processing: %d files processed.' % count)

if __name__ == '__main__':
    main()
