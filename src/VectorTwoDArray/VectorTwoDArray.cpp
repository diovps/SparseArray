#include "VectorTwoDArray.h"
#include <iostream>
#include <assert.h>

template<typename T>
VectorTwoDArray<T>::VectorTwoDArray(int r, int c, T def){
	assert(r>0 && c>0);
	numRows = r;
	numCols = c;
	defaultVal = def;

	std::vector<T> columns;
	columns.resize(c,def);

	for(int i = 0; i < r; ++i){
		theArray.push_back(columns);
	}
}

template<typename T>
VectorTwoDArray<T>::~VectorTwoDArray(){

}

template<typename T>
void VectorTwoDArray<T>::insert(int r, int c, T value){
	assert(r>=0 && r<numRows);
	assert(c>=0 && c<numCols);

	theArray[r][c] = value;
}

template<typename T>
T VectorTwoDArray<T>::access(int r, int c){
	assert(r>=0 && r<numRows);
	assert(c>=0 && c < numCols);
	return theArray[r][c];
}

template<typename T>
void VectorTwoDArray<T>::remove(int r, int c){
	assert(r>=0 && r<numRows);
	assert(c>=0 && c<numRows);
	theArray[r][c] = defaultVal;
}

template<typename T>
void VectorTwoDArray<T>::print(){
	
}

template<typename T>
int VectorTwoDArray<T>::getNumRows(){
	return numRows;
}

template<typename T>
int VectorTwoDArray<T>::getNumCols(){
	return numCols;
}

template class VectorTwoDArray<int>;
template class VectorTwoDArray<double>;
template class VectorTwoDArray<std::string>;
