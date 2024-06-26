CC=gcc
CFLAGS=-Wall
TARGET=build/main

all: $(TARGET)

$(TARGET): main.c
	mkdir -p build
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -rf build/
