#include <iostream>
#include "VectorTwoDArray.h"

int main(){
	VectorTwoDArray<std::string>* n= new VectorTwoDArray<std::string>(2,2,"nil");
	n->insert(1,1,"Hey");
	std::cout << n->access(1,1) << std::endl;
	
	n->print();	
	n->remove(1,1);
	std::cout << n->access(1,1) << std::endl;
	return 0;
}
