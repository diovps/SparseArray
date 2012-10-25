#include <iostream>
#include "ArrayTwoDArray.h"

int main(){

	ArrayTwoDArray<int>* n = new ArrayTwoDArray<int>(10,10,0);
	
	n->insert(5,5,5);
	n->insert(4,7,79);
	n->insert(8,8,158);
	/*
	std::cout << n->access(5,5) << std::endl;
	n->remove(5,5);
	std::cout << n->access(5,5) << std::endl;
	*/
	n->print();	
	delete n;
	return 0;
}
