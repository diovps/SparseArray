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
	
	//I can't help but overcomplicate everything.

	Node<T>* val= new Node<T>(value,r,c);
	
	if(rows[r] == 0){	
		rows[r] = val;	
	}else{
		Node<T>* currCol = rows[r];
		Node<T>* prev = rows[r];

		while(currCol->getNextCol()!=0
			&& currCol->getNextCol()->getColNum()<c){
			
			prev = currCol;
			Node<T>* temp = currCol->getNextCol();
			currCol = temp;
		}
		
		if(rows[r]->getColNum()>val->getColNum()){
			val->setNextCol(rows[r]);
			rows[r] = val;
		}else if(currCol->getRowNum()==r
			&& currCol->getColNum()==c){
		
			currCol->setValue(value);	
		}else{	
			Node<T>* next = currCol->getNextCol();
			val->setNextCol(next);
			currCol->setNextCol(val);
		}
	}
	
	if(cols[c] == 0){
		cols[c] = val;
	}
	else{
		Node<T>* currRow = cols[c];
		Node<T>* prev = cols[c];
			
		while(currRow->getNextRow()!=0
			&& currRow->getNextRow()->getRowNum()<r){
		
			prev = currRow;	
			Node<T>* temp = currRow->getNextRow();
			currRow = temp;
		}			
		
		if(cols[c]->getRowNum()>val->getRowNum()){
			val->setNextRow(cols[c]);
			cols[c] = val;
		}else if(currRow->getRowNum() == r
			&& currRow->getColNum()==c){
			
			currRow->setValue(value);	
		}else{
			Node<T>* next = currRow->getNextRow();
			val->setNextRow(next);
			currRow->setNextRow(val);
		}
	}
}

template<typename T>
T SparseTwoDArray<T>::access(int r, int c){
	
	Node<T>** curr = &rows[r];
	
	while((*curr)!=0){
		if((*curr)->getRowNum() == r && (*curr)->getColNum()==c){
			break;	
		}
		Node<T>* next = (*curr)->getNextCol();
		curr = &next;	
	} 
	if((*curr)!=0){
		return (*curr)->getValue();
	}else{
		return defaultVal;
	}
}

template<typename T>
void SparseTwoDArray<T>::remove(int r, int c){
	
	Node<T>* currRow = cols[r];
	Node<T>* prevRow = cols[r];
	bool insertHere = false;

	while(currRow!=0 && !insertHere){
		if(currRow->getRowNum()==r && currRow->getColNum()==c){
			insertHere = true;
		}
		prevRow = currRow;
		currRow = currRow->getNextRow();
	}

	if(currRow!=0){
		prevRow->setNextRow(currRow->getNextRow());
		delete currRow;
	}
	
	Node<T>* currCol = rows[c];
	Node<T>* prevCol = rows[c];

	while(currCol!=0 && !insertHere){
		if(currCol->getRowNum()==r && currCol->getColNum()==c){
			insertHere = true;
		}
		prevCol = currCol;
		currCol = currCol->getNextCol();
	}

	if(currCol!=0){
		prevCol->setNextCol(currCol->getNextCol());
		delete currCol;
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
