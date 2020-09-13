CC = g++
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c++17 -I include



build: build/test01.out build/test02.out build/test03.out build/test04.out build/test05.out build/test06.out build/test07.out build/test08.out build/test09.out build/test10.out

run: build
	./build/test01.out
	./build/test02.out
	./build/test03.out
	./build/test04.out
	./build/test05.out
	./build/test06.out
	./build/test07.out
	./build/test08.out
	./build/test09.out
	./build/test10.out
clean:
	rm -rf build/*

test1: build/test01.out
	./build/test1.out

test2: build/test02.out
	./build/test2.out

test3: build/test03.out
	./build/test3.out

test4: build/test04.out
	./build/test4.out

test5: build/test05.out
	./build/test5.out

test6: build/test06.out
	./build/test6.out

test7: build/test07.out
	./build/test7.out

test8: build/test08.out
	./build/test8.out

test9: build/test09.out
	./build/test9.out

test10: build/test10.out
	./build/test10.out

build/test01.out: test/01*.cpp include/CycleContainer.hpp
	$(CC) $(CFLAGS) -g $< -o $@

build/test02.out: test/02*.cpp include/CycleContainer.hpp
	$(CC) $(CFLAGS) -g $< -o $@

build/test03.out: test/03*.cpp include/CycleContainer.hpp
	$(CC) $(CFLAGS) -g $< -o $@

build/test04.out: test/04*.cpp include/CycleContainer.hpp
	$(CC) $(CFLAGS) -g $< -o $@

build/test05.out: test/05*.cpp include/CycleContainer.hpp
	$(CC) $(CFLAGS) -g $< -o $@

build/test06.out: test/06*.cpp include/CycleContainer.hpp
	$(CC) $(CFLAGS) -g $< -o $@

build/test07.out: test/07*.cpp include/CycleContainer.hpp
	$(CC) $(CFLAGS) -g $< -o $@

build/test08.out: test/08*.cpp include/CycleContainer.hpp
	$(CC) $(CFLAGS) -g $< -o $@

build/test09.out: test/09*.cpp include/CycleContainer.hpp
	$(CC) $(CFLAGS) -g $< -o $@

build/test10.out: test/10*.cpp include/CycleContainer.hpp
	$(CC) $(CFLAGS) -g $< -o $@