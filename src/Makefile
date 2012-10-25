A = ArrayTwoDArray
V = VectorTwoDArray
S = SparseTwoDArray

all: Array Vector Sparse

Array: $(A)/ArrayTwoDArray.cpp $(A)/ArrayTwoDArray.o 
	cd ArrayTwoDArray; $(MAKE)

Vector: $(V)/VectorTwoDArray.cpp $(V)/VectorTwoDArray.o 
	cd VectorTwoDArray; $(MAKE)
	
Sparse: $(S)/SparseTwoDArray.cpp $(S)/SparseTwoDArray.o $(S)/Node.cpp $(S)/Node.o
	cd SparseTwoDArray; $(MAKE)

clean:
	cd ArrayTwoDArray; $(MAKE) clean
	cd VectorTwoDArray; $(MAKE) clean
	cd SparseTwoDArray; $(MAKE) clean
