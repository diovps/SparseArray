#include <iostream>
#include "VectorTwoDArray.h"

int main(){
	VectorTwoDArray<int>* n= new VectorTwoDArray<int>(10,10,0);
	n->insert(5,5,76);
	std::cout << n->access(5,5) << std::endl;
	n->remove(5,5);
	std::cout << n->access(5,5) << std::endl;
	return 0;
}
