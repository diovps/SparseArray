#include "ArrayTwoDArray.h"
#include <iostream>
#include <assert.h>
#include <iomanip>

template<typename T>
ArrayTwoDArray<T>::ArrayTwoDArray(int r, int c, T def){
	assert(r > 0 && c >0);
	numRows = r;
	numCols = c;
	defaultVal = def;

	theArray = new T*[r];
	
	for(int i = 0; i < r; ++i){
		theArray[i] = new T[c];
	}

	for(int i =0; i < r; ++i){
		for(int j = 0; j < c; j++){
			theArray[i][j] = def;
		}
	}
}

template<typename T>
ArrayTwoDArray<T>::~ArrayTwoDArray(){
	for(int i = 0; i < numRows; ++i){
		delete[] theArray[i];
	}
	delete[] theArray;
}

template<typename T>
void ArrayTwoDArray<T>::insert(int r, int c, T value){
	assert(r<numRows && r>=0);
	assert(c<numCols && c>=0);

	theArray[r][c] = value;
}

template<typename T>
T ArrayTwoDArray<T>::access(int r, int c){
	assert(r<numRows && r>=0);
	assert(c<numCols && c>=0);

	return theArray[r][c];
}

template<typename T>
void ArrayTwoDArray<T>::remove(int r, int c){
	assert(r<numRows && r>=0);
	assert(c<numCols && c>=0);

	theArray[r][c] = defaultVal;
}

template<typename T>
void ArrayTwoDArray<T>::print(){
	
	std::cout << "   ";
	for(int i=0; i < numCols;++i){
		std::cout << std::setw(4) << i << " ";
	}	
	std::cout << std::endl;
	
	for(int i=0; i < numRows;++i){
		std::cout << i << "  ";
		for(int j = 0; j < numCols; j++){
			std::cout << std::left<<"|"<<
			  std::setw(3)<<std::right<<theArray[i][j] << " ";
		}
		std::cout << "|" << std::endl;
	}
}

template<typename T>
int ArrayTwoDArray<T>::getNumRows(){
	return numRows;
}

template<typename T>
int ArrayTwoDArray<T>::getNumCols(){
	return numCols;
}

template class ArrayTwoDArray<int>;
template class ArrayTwoDArray<double>;
template class ArrayTwoDArray<std::string>;
