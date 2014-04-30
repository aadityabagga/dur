CC=gcc
CFLAGS=-ansi -pedantic -Wall -Wextra -Wconversion -Wstrict-overflow -Wformat=2
INSTALL=/usr/bin/install
SHELL=/bin/bash
DESTDIR=
bindir=/usr/bin
mandir=/usr/man/man1

make: dur.c
	$(CC) dur.c -o dur $(CFLAGS)

install: dur
	$(INSTALL) -d $(DESTDIR)$(bindir)
	$(INSTALL) -m755 dur $(DESTDIR)$(bindir)
	$(INSTALL) -d $(DESTDIR)$(mandir)
	$(INSTALL) -m644 man/dur.1 $(DESTDIR)$(mandir)
