GCC = g++
FLAGS = -Werror -Wall -Wextra -pedantic
BUILD = ../../build

SparseTwoDArray: test.cpp SparseTwoDArray.o Node.o
	$(GCC) $(FLAGS) -o $(BUILD)/SparseTwoDArray test.cpp SparseTwoDArray.o Node.o

SparseTwoDArray.o: SparseTwoDArray.cpp SparseTwoDArray.h
	$(GCC) $(FLAGS) -c SparseTwoDArray.cpp

Node.o: Node.cpp Node.h
	$(GCC) $(FLAGS) -c Node.cpp

clean:
	rm -f $(BUILD)/SparseTwoDArray
	rm -f *.o
