#ifndef __ARRAYTWODARRAY_H__
#define __ARRAYTWODARRAY_H__

template <typename T>
class ArrayTwoDArray{
	private:
		T** theArray;
		int numRows;
		int numCols;
		T defaultVal;	
	public:
		ArrayTwoDArray<T>(int r, int c, T def);
		~ArrayTwoDArray<T>();
		void insert(int r, int c, T value);
		T access(int r, int c);
		void remove(int r, int c);
		void print();
		int getNumRows();
		int getNumCols();
};

#endif
