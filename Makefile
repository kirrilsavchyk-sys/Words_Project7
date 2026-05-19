all: test cross_test

test: Words.o Words_test.o
	g++ Words.o Words_test.o -o test_program

cross_test: Words.o Words_cross_test.o
	g++ Words.o Words_cross_test.o -o cross_test_program

Words.o: Words.cpp Words.h
	g++ -c Words.cpp

Words_test.o: Words_test.cpp Words.h
	g++ -c Words_test.cpp

Words_cross_test.o: Words_cross_test.cpp Words.h
	g++ -c Words_cross_test.cpp

clean:
	rm -f *.o test_program cross_test_program