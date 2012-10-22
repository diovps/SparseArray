#include <iostream>

#include "Node.h"
#include "SparseTwoDArray.h"

int main(){
	SparseTwoDArray<int>* n = new SparseTwoDArray<int>(10,10,0);
	n->insert(7,1,21);
	n->insert(8,1,24);
	n->insert(3,1,9);
	n->insert(5,1,15);
	n->insert(0,1,0);
	n->insert(4,1,12);
	n->insert(2,1,6);
	n->insert(2,1,18);
	n->insert(9,1,27);
	n->print();
	return 0;
}
