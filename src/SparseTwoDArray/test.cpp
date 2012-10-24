#include <iostream>

#include "Node.h"
#include "SparseTwoDArray.h"

int main(){
	SparseTwoDArray<int>* n = new SparseTwoDArray<int>(10,10,0);
	n->insert(5,5,10);
	n->insert(5,5,12);
	n->insert(6,1,13);
	n->insert(6,2,15);
	n->insert(6,5,21);
	n->remove(6,5);	
	std::cout << n->access(5,5) << std::endl;
	std::cout << n->access(6,1) << std::endl;
	std::cout << n->access(6,2) << std::endl;
	std::cout << n->access(6,5) << std::endl;
	
	delete n;
	return 0;
}
