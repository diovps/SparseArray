#include <iostream>
#include "VectorTwoDArray.h"

int main(){
	VectorTwoDArray<std::string>* n= new VectorTwoDArray<std::string>(10,10,"default");
	n->insert(5,5,"Hello");
	std::cout << n->access(5,5) << std::endl;
	return 0;
}
