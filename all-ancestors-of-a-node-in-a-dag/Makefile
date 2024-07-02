CC=gcc
CFLAGS=-Wall -pedantic -Wextra -fsanitize=address -g 
# -Werror
TARGET=build/main

all: $(TARGET)

$(TARGET): main.c
	mkdir -p build
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -rf build/
