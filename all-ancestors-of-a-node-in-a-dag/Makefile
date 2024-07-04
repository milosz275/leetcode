CC=g++
CFLAGS=-Wall -pedantic -Wextra -fsanitize=address -g 
TARGET=build/main

all: $(TARGET)

$(TARGET): main.cpp
	mkdir -p build
	$(CC) $(CFLAGS) main.cpp -o $(TARGET)

clean:
	rm -rf build/
