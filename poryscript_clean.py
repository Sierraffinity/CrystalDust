import glob, os

for filename in glob.iglob('data/maps/**/*.pory', recursive=True):
    pre, ext = os.path.splitext(filename)
    incpath = os.path.abspath(pre + ".inc")
    if os.path.exists(incpath):
        os.remove(incpath)
