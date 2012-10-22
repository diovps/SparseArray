#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class Node{
	private:
		T value;
		Node<T>* nextCol;
		Node<T>* nextRow;
		int rowNum;
		int colNum;
	
	public:
		Node<T>(T value,int row, int col);
		~Node<T>();
		T getValue();
		void setValue(T val);
		Node*& getNextRow();
		Node*& getNextCol();
		void setNextRow(Node<T> *n);
		void setNextCol(Node<T> *n);
		int getRowNum();
		int getColNum();

};

#endif
