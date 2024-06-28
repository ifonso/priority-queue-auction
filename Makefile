CC = gcc
CFLAGS = -I . -g
SOURCES = $(wildcard *.c)
OUTPUT = out

all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SOURCES)

clean:
	rm -f $(OUTPUT)