#include "gtest/gtest.h"
#include "../src/ArrayTwoDArray/ArrayTwoDArray.h"
#include "../src/VectorTwoDArray/VectorTwoDArray.h"
#include "../src/SparseTwoDArray/SparseTwoDArray.h"
#include <iostream>
#include <string>

TEST(Array,numCols){
	ArrayTwoDArray<int>* ia = new ArrayTwoDArray<int>(5,7,0);
	ArrayTwoDArray<double>* da = new ArrayTwoDArray<double>(9,9,0.0);
	ArrayTwoDArray<std::string>* sa = 
		new ArrayTwoDArray<std::string>(18,7,"null");
		
	EXPECT_EQ(7,ia->getNumCols());
	EXPECT_EQ(9,da->getNumCols());
	EXPECT_EQ(7,sa->getNumCols());
}

TEST(Array,numRows){
	ArrayTwoDArray<int>* ia = new ArrayTwoDArray<int>(5,7,0);
	ArrayTwoDArray<double>* da = new ArrayTwoDArray<double>(9,9,0.0);
	ArrayTwoDArray<std::string>* sa = 
		new ArrayTwoDArray<std::string>(18,7,"null");
		
	EXPECT_EQ(5,ia->getNumRows());
	EXPECT_EQ(9,da->getNumRows());
	EXPECT_EQ(18,sa->getNumRows());

}


TEST(Array,insert){
	ArrayTwoDArray<int>* ia = new ArrayTwoDArray<int>(10,7,0);
	ArrayTwoDArray<double>* da = new ArrayTwoDArray<double>(4,9,0.0);
	ArrayTwoDArray<std::string>* sa = 
		new ArrayTwoDArray<std::string>(12,12,"null");

	
	for(int i = 0; i < 5; ++i){
		ia->insert(i*2,i,i*5);
	}

	for(int i = 0; i < 4; i++){
		da->insert(i,i*2,3.14*i);
	}
	
	sa->insert(0,0,"H");
	sa->insert(0,2,"HE");
	sa->insert(2,0,"HEL");
	sa->insert(0,4,"hell");
	sa->insert(6,6,"hello");
	sa->insert(11,11,"Bob");
	
	for(int i = 0; i < 5; ++i){
		EXPECT_EQ(i*5,ia->access(i*2,i));	
	}

	for(int i = 0; i < 4; ++i){
		EXPECT_EQ(3.14*i,da->access(i,i*2));
	}


	EXPECT_EQ("H",sa->access(0,0));
	EXPECT_EQ("HE",sa->access(0,2));
	EXPECT_EQ("HEL",sa->access(2,0));
	EXPECT_EQ("hell",sa->access(0,4));
	EXPECT_EQ("hello",sa->access(6,6));
	EXPECT_EQ("Bob",sa->access(11,11));
}	
