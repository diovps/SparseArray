#include <iostream>

#include "Node.h"
#include "SparseTwoDArray.h"

int main(){
	SparseTwoDArray<int>* n = new SparseTwoDArray<int>(10,10,0);
	n->insert(8,8,8);
	n->insert(6,6,19);
	n->remove(7,7);
	std::cout << n->access(8,8) << std::endl;
	std::cout << n->access(6,6) << std::endl;	
	delete n;
	return 0;
}
