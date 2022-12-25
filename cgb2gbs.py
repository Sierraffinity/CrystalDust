from genericpath import isfile
import sys
import os
import re
from pathlib import Path

def buildsong(lines, songname, newname, channels):
    inchannel = False
    currentchannel = ""
    neededchannels = dict(channels)
    outLines = ['\t.include "asm/macros.inc"', '', '\t.section .rodata', '\t.align 1']
    for line in lines:
        line = line.replace(';', '@')
        cleanline = line.strip()
        command = cleanline.split()
        if len(command) > 0:
            if inchannel:
                if cleanline.startswith('.'):
                    line = currentchannel.replace(songname, newname) + cleanline
                    if not cleanline.endswith(':'):
                        line = line + ':'
                    outLines.append(line)
                elif cleanline.endswith(':'):
                    inchannel = False
                elif command[0] == "sound_loop":
                    if songname in command[2]:
                        command[2] = command[2].replace(songname, newname)
                    elif command[2].find('.') > 0:
                        parts = command[2].split('_')
                        parts[0] = parts[0].replace('Music', 'gbs')
                        parts[1] = parts[1].lower()
                        command[2] = '_'.join(parts)
                    else:
                        command[2] = currentchannel.replace(songname, newname) + command[2]
                    line = '\t' + ' '.join(command)
                    outLines.append(line)
                elif command[0] == "sound_call" or command[0] == "sound_jump":
                    if songname in command[1]:
                        command[1] = command[1].replace(songname, newname)
                    elif command[1].find('.') > 0:
                        parts = command[1].split('_')
                        parts[0] = parts[0].replace('Music', 'gbs')
                        parts[1] = parts[1].lower()
                        command[1] = '_'.join(parts)
                    else:
                        command[1] = currentchannel.replace(songname, newname) + command[1]
                    outLines.append('\t' + ' '.join(command))
                else:
                    outLines.append(line.replace('#', 's'))

            if not inchannel:
                for channel in neededchannels:
                    if channel in cleanline and cleanline.endswith(':'):
                        outLines.append(line.replace(songname, newname))
                        outLines.append("\tgbs_switch {}".format((neededchannels[channel] - 1)))
                        currentchannel = channel
                        del neededchannels[channel]
                        inchannel = True
                        break
        else:
            outLines.append(line)

    if neededchannels:
        raise ValueError("Could not find channels", neededchannels.keys())

    outLines.append('')
    outLines.append('\t.align 4')
    outLines.append('\t.global {}_Header'.format(newname))
    outLines.append('{}_Header:'.format(newname))
    outLines.append('\t.byte {}\t@ NumTrks'.format(len(channels)))
    outLines.append('\t.byte 0\t@ NumBlks')
    outLines.append('\t.byte 0\t@ Priority')
    outLines.append('\t.byte 0\t@ Reverb')
    outLines.append('')
    outLines.append('\t.int voicegroup000')
    outLines.append('')
    for channel in channels:
        outLines.append('\t.int {}'.format(channel.replace(songname, newname)))
    outLines.append('')
    return outLines

def convert(inFile, outFile, newname):
    lines = inFile.read().splitlines()
    songname = ""
    channelcount = 0
    channels = {}
    for line in lines:
        cleanline = line.strip()
        command = cleanline.split()
        if len(command) > 0:
            if command[0] == "channel_count":
                if not songname:
                    raise ValueError("Encountered channel_count before song name", cleanline)
                channelcount = int(command[1])
                channels.clear()
            elif command[0] == "channel":
                if not songname:
                    raise ValueError("Encountered channel before song name", cleanline)
                channelcmd = [x.strip(',') for x in command][1:]
                channels[channelcmd[1]] = int(channelcmd[0])
                if len(channels) == channelcount:
                    outFile.write('\n'.join(buildsong(lines, songname, newname, channels)))
                    channelcount = 0
                    channels.clear()
                    songname = ""
            elif not cleanline.startswith('.') and cleanline.endswith(':'):
                if channelcount == 0:
                    songname = cleanline[:-1]
                else:
                    raise ValueError("Encountered symbol when channel expected", cleanline)
            elif channelcount != 0:
                raise ValueError("Encountered non-channel", cleanline)

def convertFile(path, outDir):
    try:
        with open(path, 'r') as inFile:
            newname = 'gbs_{}'.format(path.stem).lower()
            with open(outDir / (newname + '.s'), 'w') as outFile:
                convert(inFile, outFile, newname)
    except:
        raise ValueError("Error processing file.", path.name)

def main():
    if len(sys.argv) < 3:
        print("Usage: {} <input directory> <output directory>".format(sys.argv[0]))
        sys.exit()

    if os.path.isdir(sys.argv[1]):
        inDir = Path(sys.argv[1])
        outDir = Path(sys.argv[2])

        pathList = list(inDir.glob('*.asm'))
        outDir.mkdir(parents=True, exist_ok=True)
        
        count = 0
        for path in pathList:
            try:
                convertFile(path, outDir)
                count += 1
                print("%s processed..." % path.name)
            except:
                break

        if count == len(pathList):
            print("%d files successfully processed." % count)
        else:
            sys.exit('\nError during processing: %d files processed.' % count)
    elif os.path.isfile(sys.argv[1]):
        path = Path(sys.argv[1])
        outDir = Path(sys.argv[2])
        outDir.mkdir(parents=True, exist_ok=True)
        convertFile(path, outDir)
        print("%s successfully processed." % path.name)
    else:
        print("File or directory '{}' does not exist. Exiting...".format(sys.argv[1]))
        sys.exit()    

if __name__ == '__main__':
    main()
