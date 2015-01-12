NAME = dur
VER = 1.1.1
CC = gcc
CFLAGS = -ansi -pedantic -Wall -Wextra -Wconversion -Wstrict-overflow -Wformat=2
INSTALL = /usr/bin/install
SHELL = /bin/bash
rm = /usr/bin/rm
DESTDIR=
bindir = /usr/bin
mandir = /usr/man/man1
docdir = /usr/doc/$(NAME)

make: src/dur.c
	$(CC) src/dur.c -o bin/dur $(CFLAGS)

install: bin/dur
	$(INSTALL) -d $(DESTDIR)$(bindir)
	$(INSTALL) -d $(DESTDIR)$(mandir)
	$(INSTALL) -d $(DESTDIR)$(docdir)
	$(INSTALL) -m755 dur $(DESTDIR)$(bindir)
	$(INSTALL) -m644 man/dur.1 $(DESTDIR)$(mandir)
	$(INSTALL) -m644 doc/use-cases.txt $(DESTDIR)$(docdir)
	$(INSTALL) -m644 README.md $(DESTDIR)$(docdir)
	$(INSTALL) -m644 COPYING $(DESTDIR)$(docdir)

remove:
	$(rm) $(DESTDIR)$(bindir)/$(NAME)
	$(rm) $(DESTDIR)$(mandir)/$(NAME).1
	$(rm) -r $(DESTDIR)$(docdir)/$(NAME)
