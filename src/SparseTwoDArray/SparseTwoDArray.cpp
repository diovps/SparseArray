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
	Node<T>* val= new Node<T>(value,r,c);
	
	Node<T>** currCol = &rows[r];
	Node<T>** currRow = &cols[c];
	
	while((*currCol)!=0 && (*currCol)->getNextCol()!=0){
		Node<T>* temp = (*currCol)->getNextCol();
		currCol = &temp;
	}			
	if((*currCol)==0){
		rows[r] = val;
	}else{
		Node<T>* next = (*currCol)->getNextCol();
		val->setNextCol(next);
		(*currCol)->setNextCol(val);
	}
	
	while((*currRow)!=0 && (*currRow)->getNextRow()!=0){
		Node<T>* temp = (*currRow)->getNextRow();
		currRow = &temp;
	}			
	if((*currRow)==0){
		cols[c] = val;
	}else{
		Node<T>* next = (*currRow)->getNextRow();
		val->setNextRow(next);
		(*currRow)->setNextRow(val);
	}
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
	Node<T>** curr = &rows[1];
	while((*curr)!= 0){
		std::cout << (*curr)->getValue() << std::endl;
		Node<T>* next = (*curr)->getNextCol();
		curr = &next;
	}
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
