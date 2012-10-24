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
	
	Node<T>* curr = rows[0];

	for(int i = 0; i < numRows; ++i){
		curr = rows[i];
		Node<T>* temp = curr;
		
		while(curr!=0 && curr->getNextCol()!=0){
			temp = curr->getNextCol();
			delete curr;
			curr = temp;
		}	
	}

	delete[] rows;
	delete[] cols;
}
	
template<typename T>
void SparseTwoDArray<T>::insert(int r, int c, T value){
	
	Node<T>* val= new Node<T>(value,r,c);
	Node<T>** currCol = &rows[r];		
	Node<T>** currRow = &cols[c];
	
	while(*currCol!=0 && (*currCol)->getColNum() < c){
		currCol = &((*currCol)->getNextCol());
	}
	
	if(*currCol!=0 &&
		(*currCol)->getColNum()==c && (*currCol)->getRowNum()==r){
		
		(*currCol)->setValue(value);
	}else{
		val->setNextCol(**currCol);
		*currCol = val;
	}

	
	while(*currRow!=0 && (*currRow)->getRowNum() < r){
		currRow = &((*currRow)->getNextRow());
	}
	
	val->setNextRow(**currRow);
	*currRow = val;	
}

template<typename T>
T SparseTwoDArray<T>::access(int r, int c){
	Node<T>** curr = &rows[r];
	
	while((*curr)!=0){
		if((*curr)->getColNum()==c && (*curr)->getRowNum()==r){
			return (*curr)->getValue();
		}
		Node<T>* next = (*curr)->getNextCol();
		curr = &next;	
	}
	return defaultVal;	
}

template<typename T>
void SparseTwoDArray<T>::remove(int r, int c){
	
	Node<T>** currCol = &rows[r];
	Node<T>** prevCol = &rows[r];

	while(*currCol!=0){
		if((*currCol)->getColNum()==c && (*currCol)->getRowNum()==r){
			break;
		}
		prevCol = currCol;
		currCol = &((*currCol)->getNextCol());
	}
	
	if(currCol!=0){
		(*prevCol)->setNextCol(*((*currCol)->getNextCol()));
	}
	
	Node<T>** currRow = &cols[c];
	Node<T>** prevRow = &cols[c];
	
	while(*currRow!=0){
		if((*currRow)->getColNum()==c && (*currRow)->getRowNum()==r){
			break;
		}
		prevRow = currRow;
		currRow = &((*currRow)->getNextRow());
	}

	if(currCol!=0){
		(*prevRow)->setNextRow(*((*currRow)->getNextRow()));
		delete (*currRow);
	}
}

template<typename T>
void SparseTwoDArray<T>::print(){
	
}

template<typename T>
int SparseTwoDArray<T>::getNumRows(){
	return numRows;
}

template<typename T>
int SparseTwoDArray<T>::getNumCols(){
	return numCols;
}

template class SparseTwoDArray<int>;
template class SparseTwoDArray<double>;
template class SparseTwoDArray<std::string>;
