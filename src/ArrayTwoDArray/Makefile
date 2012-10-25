GCC = g++
FLAGS = -Werror -Wall -Wextra -pedantic
BUILD = ../../build

ArrayTwoDArray: test.cpp ArrayTwoDArray.o
	$(GCC) $(FLAGS) -o $(BUILD)/ArrayTwoDArray test.cpp ArrayTwoDArray.o

ArrayTwoDArray.o: ArrayTwoDArray.cpp ArrayTwoDArray.h
	$(GCC) $(FLAGS) -c ArrayTwoDArray.cpp

clean:
	rm -f $(BUILD)/ArrayTwoDArray
	rm -f *.o
