IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -W -Wall -pedantic -ansi -g

ODIR=obj
LDIR =../lib

LIBS= -lm

_DEPS = position.h dfs.h pathNode.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o position.o dfs.o pathNode.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

prog: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
		rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
