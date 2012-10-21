#include "SparseTwoDArray.h"
#include <iostream>

template<typename T>
SparseTwoDArray<T>::SparseTwoDArray(int r, int c, T def){

}

template<typename T>
SparseTwoDArray<T>::~SparseTwoDArray(){

}

template<typename T>
void SparseTwoDArray<T>::insert(int r, int c, T value){

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
