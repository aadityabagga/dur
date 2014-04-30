PRGNAME=dur
VER=1.1
CC=gcc
CFLAGS=-ansi -pedantic -Wall -Wextra -Wconversion -Wstrict-overflow -Wformat=2
INSTALL=/usr/bin/install
SHELL=/bin/bash
rm=/usr/bin/rm
DESTDIR=
bindir=/usr/bin
mandir=/usr/man/man1
docdir=/usr/doc

make: dur.c
	$(CC) dur.c -o dur $(CFLAGS)

install: dur
	$(INSTALL) -d $(DESTDIR)$(bindir)
	$(INSTALL) -d $(DESTDIR)$(mandir)
	$(INSTALL) -d $(DESTDIR)$(docdir)/$(PRGNAME)-$(VER)
	$(INSTALL) -m755 dur $(DESTDIR)$(bindir)
	$(INSTALL) -m644 man/dur.1 $(DESTDIR)$(mandir)
	$(INSTALL) -m644 doc/use-cases $(DESTDIR)$(docdir)/$(PRGNAME)-$(VER)
	$(INSTALL) -m644 README $(DESTDIR)$(docdir)/$(PRGNAME)-$(VER)
	$(INSTALL) -m644 COPYING $(DESTDIR)$(docdir)/$(PRGNAME)-$(VER)

remove:
	$(rm) $(DESTDIR)$(bindir)/$(PRGNAME)
	$(rm) $(DESTDIR)$(mandir)/$(PRGNAME).1
	$(rm) -r $(DESTDIR)$(docdir)/$(PRGNAME)-$(VER)