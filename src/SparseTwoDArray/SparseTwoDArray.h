#ifndef __SPARSETWODARRAY_H__
#define __SPARSETWODARRAY_H__

#include "Node.h"

template <typename T>
class SparseTwoDArray{
	private:
		Node<T>** rows;
		Node<T>** cols;
		int numRows;
		int numCols;
		T defaultVal;
	public:
		SparseTwoDArray<T>(int r, int c, T def);
		~SparseTwoDArray<T>();
		void insert(int r, int c, T value);
		T access(int r, int c);
		void remove(int r, int c);
		int getNumRows();
		int getNumCols();
};

#endif
