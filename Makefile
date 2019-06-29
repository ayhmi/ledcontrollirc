PROJECT = ledcontrollirc
IDIR =src
SRCDIR=src
CC=gcc
CFLAGS=-Wno-nonnull -I$(IDIR)

ODIR=src
LDIR=lib

LIBS=-lwiringPi -llirc_client

_DEPS = colorControl.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o colorControl.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(PROJECT): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

