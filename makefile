CC=gcc
CFLAGS=-ansi -pedantic -Wall -Wextra -Wconversion -Wstrict-overflow -Wformat=2
INSTALL=/usr/bin/install
SHELL=/bin/bash
DESTDIR=
bindir=/usr/bin

compile: dur.c
	$(CC) dur.c -o dur $(CFLAGS)

install: dur
	$(INSTALL) -d $(DESTDIR)$(bindir)
	$(INSTALL) -m755 dur $(DESTDIR)$(bindir)
