BUILD = ../build
TEST = ../test
LIB = ../lib
SRC = ../src
GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a

GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include

CPP = g++
CPPFLAGS = -Wall -Wextra

Array = $(SRC)/ArrayTwoDArray
Vector = $(SRC)/VectorTwoDArray
Sparse = $(SRC)/SparseTwoDArray


array_test: TwoDArray.cpp $(Array)/ArrayTwoDArray.o $(Vector)/VectorTwoDArray.o $(Sparse)/SparseTwoDArray.o $(Sparse)/Node.o $(GTEST_MAINA)
	$(CPP) $(CFLAGS) $(GTEST_INCLUDES) -pthread -o array_test TwoDArray.cpp $(Array)/ArrayTwoDArray.o $(Vector)/VectorTwoDArray.o $(Sparse)/SparseTwoDArray.o $(Sparse)/Node.o $(GTEST_MAINA)

$(GTEST_MAINA): $(GTEST)/src/*.cc $(GTEST)/src/*.h
	cd $(GTEST)/make; make

clean:
	rm -f array_test
	rm -f $(GTEST_MAINA)
	cd $(GTEST)/make; $(MAKE) clean


