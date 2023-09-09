runTests : AllTests
	@./AllTests -v

AllTests : ../com/AllTests.cpp test.cpp
	g++ -Wall ../com/AllTests.cpp test.cpp -lCppUTest -o AllTests

.PHONY: clean
clean:
	rm -f AllTests *.o a.out
