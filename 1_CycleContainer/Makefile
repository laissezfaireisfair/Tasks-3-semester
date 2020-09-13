CC = g++
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c++14 -I include



build: build/test1.out build/test2.out build/test3.out build/test4.out build/test5.out build/test6.out build/test7.out build/test8.out build/test9.out build/test10.out

run: build
	./build/test1.out
	./build/test2.out
	./build/test3.out
	./build/test4.out
	./build/test5.out
	./build/test6.out
	./build/test7.out
	./build/test8.out
	./build/test9.out
	./build/test10.out
clean:
	rm -rf build/*

test1: build/test1.out
	./build/test1.out

test2: build/test2.out
	./build/test2.out

test3: build/test3.out
	./build/test3.out

test4: build/test4.out
	./build/test4.out

test5: build/test5.out
	./build/test5.out

test6: build/test6.out
	./build/test6.out

test7: build/test7.out
	./build/test7.out

test8: build/test8.out
	./build/test8.out

test9: build/test9.out
	./build/test9.out

test10: build/test10.out
	./build/test10.out

build/test1.out: test/1*.cpp include/CycleContainer.hpp
	$(CC) $(CFLAGS) -g $< -o $@

build/test2.out: test/2*.cpp include/CycleContainer.hpp
	$(CC) $(CFLAGS) -g $< -o $@

build/test3.out: test/3*.cpp include/CycleContainer.hpp
	$(CC) $(CFLAGS) -g $< -o $@

build/test4.out: test/4*.cpp include/CycleContainer.hpp
	$(CC) $(CFLAGS) -g $< -o $@

build/test5.out: test/5*.cpp include/CycleContainer.hpp
	$(CC) $(CFLAGS) -g $< -o $@

build/test6.out: test/6*.cpp include/CycleContainer.hpp
	$(CC) $(CFLAGS) -g $< -o $@

build/test7.out: test/7*.cpp include/CycleContainer.hpp
	$(CC) $(CFLAGS) -g $< -o $@

build/test8.out: test/8*.cpp include/CycleContainer.hpp
	$(CC) $(CFLAGS) -g $< -o $@

build/test9.out: test/9*.cpp include/CycleContainer.hpp
	$(CC) $(CFLAGS) -g $< -o $@

build/test10.out: test/10*.cpp include/CycleContainer.hpp
	$(CC) $(CFLAGS) -g $< -o $@