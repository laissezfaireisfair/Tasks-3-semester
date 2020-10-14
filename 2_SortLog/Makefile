CC = g++
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c++17 -I include/
C_DEBUG_FLAGS = -Wall -Wextra -Werror -pedantic -std=c++17 -I include/

all: build
	./build/main.out

build: build/main.out

build-debug: build/mainDebug.out

clean:
	rm -rf build/*

build/main.out: src/main.cpp src/Elem.cpp src/ConsoleLogger.cpp
	$(CC) $(CFLAGS) $< -o $@

build/mainDebug.out: src/main.cpp src/Elem.cpp src/ConsoleLogger.cpp
	$(CC) $(C_DEBUG_FLAGS) $< -o $@
