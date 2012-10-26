#include <string>
#include "Node.h"

template <typename T>
Node<T>::Node(T val,int row, int col){
	value = val;
	rowNum = row;
	colNum = col;
	nextRow = 0;
	nextCol = 0;
}

template <typename T>
Node<T>::~Node(){

}

template <typename T>
T Node<T>::getValue(){
	return value;
}

template <typename T>
Node<T>*& Node<T>::getNextRow(){
	return nextRow;
}

template <typename T>
Node<T>*& Node<T>::getNextCol(){
	return nextCol;
}

template <typename T>
void Node<T>::setNextRow(Node<T>& n){
	nextRow = &n;
}

template <typename T>
void Node<T>::setNextCol(Node<T>& n){
	nextCol = &n;
}

template <typename T>
int Node<T>::getColNum(){
	return colNum;
}

template <typename T>
int Node<T>::getRowNum(){
	return rowNum;
}


template class Node<int>;
template class Node<double>;
template class Node<std::string>;
