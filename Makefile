#Makefile for alphametic solver
#James Stanley 2010

CFLAGS=-Wall -g
OBJS=am.o

all: am
.PHONY: all

clean:
	-rm -f am $(OBJS)
.PHONY: clean

am: $(OBJS)

