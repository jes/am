#Makefile for alphametic solver
#James Stanley 2010

CFLAGS=-Wall -g
OBJS=am.o letters.o solver.o
PREFIX?=/usr

all: am
.PHONY: all

clean:
	-rm -f am $(OBJS)
.PHONY: clean

install:
	install -m 0755 am $(DESTDIR)$(PREFIX)/bin
.PHONY: install

am: $(OBJS)
