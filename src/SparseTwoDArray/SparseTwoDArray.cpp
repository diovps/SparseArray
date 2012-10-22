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
		Node<T>** currCol = &rows[r];
		Node<T>** prev = &rows[r];

		while((*currCol)->getNextCol()!=0
			&&(*currCol)->getNextCol()->getColNum()<c){
			
			prev = currCol;
			Node<T>* temp = (*currCol)->getNextCol();
			currCol = &temp;
		}
		
		if(rows[r]->getColNum()>val->getColNum()){
			val->setNextCol(rows[r]);
			rows[r] = val;
		}/*else if((*currCol)->getRowNum()==r
			&&(*currCol)->getColNum()==c){

			Node<T>* next = (*currCol)->getNextCol();
			(*prev)->setNextCol(val);
			val->setNextCol(next);
			delete currCol;
		
		}*/else{	
			Node<T>* next = (*currCol)->getNextCol();
			val->setNextCol(next);
			(*currCol)->setNextCol(val);
		}
	}
	
	if(cols[c] == 0){
		cols[c] = val;
	}
	else{
		Node<T>** currRow = &cols[c];
		Node<T>** prev = &cols[c];
	
		while((*currRow)->getNextRow()!=0
			&& (*currRow)->getNextRow()->getRowNum()<r){
			
			prev = currRow; 
			Node<T>* temp = (*currRow)->getNextRow();
			currRow = &temp;
		}			
		
		if(cols[c]->getRowNum()>val->getRowNum()){
			val->setNextRow(cols[c]);
			cols[c] = val;
		}/*else if((*currRow)->getRowNum() == r
			&&(*currRow)->getColNum()==c){
			
			Node<T>* next = (*currRow)->getNextRow();
			(*prev)->setNextRow(val);
			val->setNextRow(next);
			delete currRow;
		}*/else{
			Node<T>* next = (*currRow)->getNextRow();
			val->setNextRow(next);
			(*currRow)->setNextRow(val);
		}
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
	Node<T>** curr = &cols[1];
	while((*curr)!= 0){
		std::cout << (*curr)->getValue() << std::endl;
		Node<T>* next = (*curr)->getNextRow();
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
