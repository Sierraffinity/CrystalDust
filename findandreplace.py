import sys
import os
import re

def replace_keep_case(word, replacement, text):
    def func(match):
        g = match.group()
        if g.islower(): return replacement.lower()
        if g.istitle(): return replacement.title()
        if g.isupper(): return replacement.upper()
        return replacement      
    return re.sub(word, func, text, flags=re.I)

def main():
    files = sys.argv[1]
    find_replace = sys.argv[2]

    if not os.path.isfile(files):
        print("File path {} does not exist. Exiting...".format(files))
        sys.exit()
  
    if not os.path.isfile(find_replace):
        print("File path {} does not exist. Exiting...".format(find_replace))
        sys.exit()

    with open(files) as fp:
        filelist = [line.rstrip() for line in fp]

    with open(find_replace) as fp:
        frtokens = [line.rstrip().split() for line in fp]

    count = 0
    for f in filelist:
        try:
            with open(f, 'r+') as fp:
                content = fp.read()
                for frtoken in frtokens:
                    content = replace_keep_case(r'\b%s\b' % frtoken[0], frtoken[1], content)
                fp.seek(0)
                fp.write(content)
                fp.truncate()
                count += 1
                sys.stdout.write('\033[K')
                print("%s processed..." % f, end='\r')
        except:
            sys.stderr.write('\033[KError processing file %s: %d files processed before error.\n' % (f, count))
            raise

    if count == len(filelist):
        print("%d files successfully processed." % count)
    else:
        sys.exit('\nError during processing: %d files processed.' % count)

if __name__ == '__main__':
    main()
