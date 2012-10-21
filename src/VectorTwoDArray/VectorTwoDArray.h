#ifndef __VECTORTWODARRAY_H__
#define __VECTORTWODARRAY_H__

#include <vector>

template <typename T>
class VectorTwoDArray{
	private:
		std::vector<std::vector<T> > theArray;
		int numCols;
		int numRows;
		T defaultVal;
	public:
		VectorTwoDArray<T>(int r, int c, T def);
		~VectorTwoDArray<T>();
		void insert(int r, int c, T value);
		T access(int r, int c);
		void remove(int r, int c);
		void print();
		int getNumRows();
		int getNumCols();
};

#endif
