#include <iostream>

#include "Node.h"
#include "SparseTwoDArray.h"

int main(){
	SparseTwoDArray<int>* n = new SparseTwoDArray<int>(10,10,0);
	n->insert(5,5,10);
	std::cout << n->access(5,5) << std::endl;
	n->insert(5,5,8);
	std::cout << n->access(5,5) << std::endl;

	return 0;
}
