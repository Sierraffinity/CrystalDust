// Copyright (c) 2020 Sierraffinity

#include <stdio.h>
#include <string.h>
#include "global.h"
#include "gfx.h"
#include "util.h"

// Read/write Adobe Color Table palette files.

// Format of an Adobe Color Table palette file:
//
// 256 times:
// 1 byte - Red component
// 1 byte - Green component
// 1 byte - Blue component
//
// Optional:
// 2 bytes - Number of colors
// 2 bytes - Transparent color

void ReadActPalette(char *path, struct Palette *palette)
{
	int fileSize;
	unsigned char *data = ReadWholeFile(path, &fileSize);

    if (fileSize == 768)
    {
	    palette->numColors = 256;
    }
    else if (fileSize == 772)
    {
        // big endian
        palette->numColors = (data[256 * 3] << 8) | data[256 * 3 + 1];
        if (palette->numColors > 256)
            palette->numColors = 256;
    }
    else
    {
		FATAL_ERROR("The file size (%d) is not valid (expected 768 or 772).\n", fileSize);
    }
    

	for (int i = 0; i < palette->numColors; i++) {
		palette->colors[i].red = data[i * 3];
		palette->colors[i].green = data[i * 3 + 1];
		palette->colors[i].blue = data[i * 3 + 2];
	}

	// png can only accept 16 or 256 colors, so fill the remainder with black
	if (palette->numColors > 16)
    {
	    memset(&palette->colors[palette->numColors], 0, (256 - palette->numColors) * sizeof(struct Color));
	    palette->numColors = 256;
    }

	free(data);
}

void WriteActPalette(char *path, struct Palette *palette)
{
    int i = 0;
	FILE *fp = fopen(path, "wb");

	if (fp == NULL)
		FATAL_ERROR("Failed to open \"%s\" for writing.\n", path);

	for (; i < palette->numColors; i++) {
		fputc(palette->colors[i].red, fp);
		fputc(palette->colors[i].green, fp);
		fputc(palette->colors[i].blue, fp);
	}

    // act format always stores 256 colors, even if it doesn't use all of them
    for (; i < 256; i++)
    {
		fputc(0, fp);
		fputc(0, fp);
		fputc(0, fp);
    }

    // specify color count if less than 256
    if (palette->numColors < 256)
    {
        fputc(palette->numColors, fp);
		fputc(0, fp);
		fputc(0, fp);
		fputc(0, fp);
    }

	fclose(fp);
}
