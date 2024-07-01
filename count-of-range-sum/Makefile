CC=gcc
CFLAGS=-Wall -Werror -pedantic -Wextra -fsanitize=address -g
TARGET=build/main

all: $(TARGET)

$(TARGET): main.c
	mkdir -p build
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -rf build/
