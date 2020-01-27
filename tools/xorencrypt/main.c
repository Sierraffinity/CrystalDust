// Copyright(c) 2020 huderlem
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

#ifdef _MSC_VER

#define FATAL_ERROR(format, ...)           \
do                                         \
{                                          \
    fprintf(stderr, format, __VA_ARGS__);  \
    exit(1);                               \
} while (0)

#else

#define FATAL_ERROR(format, ...)            \
do                                          \
{                                           \
    fprintf(stderr, format, ##__VA_ARGS__); \
    exit(1);                                \
} while (0)

#endif // _MSC_VER

void usage(void)
{
	fprintf(stderr, "Usage: xorencrypt input_file start_address end_address encrypt_key\n");
}

int main(int argc, char **argv)
{
	if (argc < 5)
	{
		usage();
		exit(1);
	}

	char *input_filepath = argv[1];
	unsigned long start_addr = strtoul(argv[2], NULL, 0);
	unsigned long end_addr = strtoul(argv[3], NULL, 0);
	unsigned long encryption_key = strtoul(argv[4], NULL, 0);

	if (end_addr < start_addr)
		FATAL_ERROR("end_addr must be greater than or equal to start_addr!\n");

	unsigned long num_bytes = end_addr - start_addr;

	FILE *f = fopen(input_filepath, "r+");
	if (!f)
		FATAL_ERROR("Failed to open '%s' for reading!\n", input_filepath);

	if (fseek(f, start_addr, SEEK_SET) != 0)
		FATAL_ERROR("Failed to seek to offset '%lu' in file '%s'!\n", start_addr, input_filepath);

	unsigned char *bytes = malloc(num_bytes);
	unsigned long read = fread(bytes, num_bytes, sizeof(unsigned char), f);
	if (read <= 0)
	{
		FATAL_ERROR("Failed to read bytes from '%s'!\n", input_filepath);
	}

	for (unsigned int i = 0; i < num_bytes; i++)
	{
		int shift = 8 * (i % 4);
		bytes[i] ^= (encryption_key >> shift) & 0xFF;
	}

	if (fseek(f, start_addr, SEEK_SET) != 0)
		FATAL_ERROR("Failed to seek to offset '%lu' in file '%s'!\n", start_addr, input_filepath);

	fwrite(bytes, sizeof(unsigned char), num_bytes, f);
	free(bytes);
	fclose(f);
	return 0;
}
