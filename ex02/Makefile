runTests : AllTests
	@./AllTests -v

CXXFLAGS = -Wall -g
LDFLAGS = -lCppUTest -lCppUTestExt

AllTests : ../com/AllTests.cpp test.cpp use_init_x.o
	$(CXX) $(CXXFLAGS) $? $(LDFLAGS) -o $@

CFLAGS = -Wall -c -g

use_init_x.o : use_init_x.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f AllTests *.o a.out *.d
