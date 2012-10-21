#ifndef __SPARSETWODARRAY_H__
#define __SPARSETWODARRAY_H__

template <typename T>
class SparseTwoDArray{
	private:
		T** theArray;
	public:
		SparseTwoDArray<T>(int r, int c, T def);
		~SparseTwoDArray<T>();
		void insert(int r, int c, T value);
		T access(int r, int c);
		void remove(int r, int c);
		void print();
		int getNumRows();
		int getNumCols();
};

#endif
