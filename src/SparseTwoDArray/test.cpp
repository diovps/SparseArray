#include <iostream>

#include "Node.h"
#include "SparseTwoDArray.h"

int main(){
	SparseTwoDArray<int>* n = new SparseTwoDArray<int>(10,10,0);
	n->insert(5,5,10);
	n->insert(6,5,21);
	n->insert(7,5,23);
	n->insert(8,5,29);
	n->insert(1,2,56);
	n->insert(1,3,57);
	n->insert(1,4,59);
	n->insert(1,5,60);
	n->print();
	return 0;
}
