CC ?= gcc

CFLAGS = -Wall -Wextra -Wno-switch -Werror -std=c11 -O2

LIBS = -lm

SRCS = main.c

.PHONY: all clean

all: xorencrypt
	@:

xorencrypt: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $@ $(LDFLAGS) $(LIBS)

clean:
	$(RM) xorencrypt xorencrypt.exe
