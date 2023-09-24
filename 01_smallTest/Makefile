.PHONY: runTests
runTests : AllTests
	@./AllTests -v

AllTests : AllTests.cpp first_Test.cpp
	g++ -Wall AllTests.cpp first_Test.cpp -lCppUTest -o AllTests

.PHONY: clean
clean:
	rm -f AllTests *.o a.out
