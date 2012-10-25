GCC = g++
FLAGS = -Werror -Wall -Wextra -pedantic
BUILD = ../../build

VectorTwoDArray: test.cpp VectorTwoDArray.o
	$(GCC) $(FLAGS) -o $(BUILD)/VectorTwoDArray test.cpp VectorTwoDArray.o

VectorTwoDArray.o: VectorTwoDArray.cpp VectorTwoDArray.h
	$(GCC) $(FLAGS) -c VectorTwoDArray.cpp

clean:
	rm -f $(BUILD)/VectorTwoDArray
	rm -f *.o
