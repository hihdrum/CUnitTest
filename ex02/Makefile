runTests : AllTests
	@./AllTests -v

AllTests : ../com/AllTests.cpp test.cpp use_init_x.o
	g++ -Wall ../com/AllTests.cpp test.cpp use_init_x.o -lCppUTest -lCppUTestExt -o AllTests

use_init_x.o : use_init_x.c
	gcc -Wall -c use_init_x.c -o use_init_x.o

.PHONY: clean
clean:
	rm -f AllTests *.o a.out
