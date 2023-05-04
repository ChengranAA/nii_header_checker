CC=gcc
CFLAGS=-I./include
LDFLAGS=-L./lib -lniftiio -lznz -lnifticdf -lfslio -lz

SOURCES=main.c
OBJECTS=$(SOURCES:.c=.o)

EXECUTABLE=niihc

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
