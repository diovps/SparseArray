#include "SparseTwoDArray.h"
#include <iostream>
#include <assert.h>

template<typename T>
SparseTwoDArray<T>::SparseTwoDArray(int r, int c, T def){
	assert(r >0 && c > 0);
	numRows = r;
	numCols = c;
	defaultVal = def;
	
	rows = new Node<T>*[r];
	cols = new Node<T>*[c];
	
	for(int i = 0; i < r; ++i){
		rows[i] = 0;
	}

	for(int i = 0; i < c; ++i){
		cols[i] = 0;
	}
}

template<typename T>
SparseTwoDArray<T>::~SparseTwoDArray(){

}

template<typename T>
void SparseTwoDArray<T>::insert(int r, int c, T value){
	Node<T>* val = new Node(value,r,c);
			
}

template<typename T>
T SparseTwoDArray<T>::access(int r, int c){
	T val;
	return val;
}

template<typename T>
void SparseTwoDArray<T>::remove(int r, int c){

}

template<typename T>
void SparseTwoDArray<T>::print(){

}

template<typename T>
int SparseTwoDArray<T>::getNumRows(){
	return 0;
}

template<typename T>
int SparseTwoDArray<T>::getNumCols(){
	return 0;
}

template class SparseTwoDArray<int>;
template class SparseTwoDArray<double>;
template class SparseTwoDArray<std::string>;
