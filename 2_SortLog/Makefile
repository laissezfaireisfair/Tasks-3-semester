CC = g++
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c++17 -I include/
C_DEBUG_FLAGS = -Wall -Wextra -Werror -pedantic -std=c++17 -I include/ -g
HEADERS = include/ConsoleLogger.h include/Elem.h
SRC = src/main.cpp src/Elem.cpp src/ConsoleLogger.cpp

all: build
	./build/main.out

build: build/main.out

build-debug: build/mainDebug.out

clean:
	rm -rf build/*

build/main.out: $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) src/*.cpp -o $@

build/mainDebug.out: $(SRC) $(HEADERS)
	$(CC) $(C_DEBUG_FLAGS) src/*.cpp -o $@
