runTests : AllTests
	@./AllTests -v

CXXFLAGS = -Wall -g -MMD -I inc -I mock
LDFLAGS = -lCppUTest -lCppUTestExt

AllTests : ../com/AllTests.cpp test.o use.o
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

test.o : test.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

CFLAGS = -Wall -c -g -MMD -I inc

use.o : ./src/use.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f AllTests *.o a.out *.d

-include *.d
