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

TEST(Array,remove){	
	
	ArrayTwoDArray<int>* ia = new ArrayTwoDArray<int>(10,7,0);
	ArrayTwoDArray<double>* da = new ArrayTwoDArray<double>(4,9,0.0);
	ArrayTwoDArray<std::string>* sa = 
		new ArrayTwoDArray<std::string>(12,12,"null");

	for(int i = 0; i < 9; ++i){
		ia->insert(i,0,i);
	}

	for(int i = 0; i < 9; ++i){
		ia->remove(i,0);
	}

	for(int i = 0; i < 9; ++i){
		EXPECT_EQ(0,ia->access(i,0));
	}

	
	for(int i = 0; i < 8; ++i){
		da->insert(0,i,(i+.8));
	}

	for(int i = 0; i < 8; ++i){
		da->remove(0,i);
	}

	for(int i = 0; i < 8; ++i){
		EXPECT_EQ(0,da->access(0,i));
	}
	
	for(int i = 0; i < 10; ++i){
		sa->insert(i,0,"heyya oh oh");
	}

	for(int i = 0; i < 10; ++i){
		sa->remove(i,0);
	}

	for(int i = 0; i < 10; ++i){
		EXPECT_EQ("null",sa->access(i,0));
	}
}

	
TEST(Sparse,numCols){
	SparseTwoDArray<int>* ia = new SparseTwoDArray<int>(5,7,0);
	SparseTwoDArray<double>* da = new SparseTwoDArray<double>(9,9,0.0);
	SparseTwoDArray<std::string>* sa = 
		new SparseTwoDArray<std::string>(18,7,"null");
		
	EXPECT_EQ(7,ia->getNumCols());
	EXPECT_EQ(9,da->getNumCols());
	EXPECT_EQ(7,sa->getNumCols());
}

TEST(Sparse,numRows){
	SparseTwoDArray<int>* ia = new SparseTwoDArray<int>(5,7,0);
	SparseTwoDArray<double>* da = new SparseTwoDArray<double>(9,9,0.0);
	SparseTwoDArray<std::string>* sa = 
		new SparseTwoDArray<std::string>(18,7,"null");
		
	EXPECT_EQ(5,ia->getNumRows());
	EXPECT_EQ(9,da->getNumRows());
	EXPECT_EQ(18,sa->getNumRows());

}


TEST(Sparse,insert){
	SparseTwoDArray<int>* ia = new SparseTwoDArray<int>(10,7,0);
	SparseTwoDArray<double>* da = new SparseTwoDArray<double>(4,9,0.0);
	SparseTwoDArray<std::string>* sa = 
		new SparseTwoDArray<std::string>(12,12,"null");

	
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


TEST(Sparse,remove){	
	
	SparseTwoDArray<int>* ia = new SparseTwoDArray<int>(10,7,0);
	SparseTwoDArray<double>* da = new SparseTwoDArray<double>(4,9,0.0);
	SparseTwoDArray<std::string>* sa = 
		new SparseTwoDArray<std::string>(12,12,"null");

	for(int i = 0; i < 9; ++i){
		ia->insert(i,0,i);
	}

	for(int i = 0; i < 9; ++i){
		ia->remove(i,0);
	}

	for(int i = 0; i < 9; ++i){
		EXPECT_EQ(0,ia->access(i,0));
	}

	
	for(int i = 0; i < 8; ++i){
		da->insert(0,i,(i+.8));
	}

	for(int i = 0; i < 8; ++i){
		da->remove(0,i);
	}

	for(int i = 0; i < 8; ++i){
		EXPECT_EQ(0,da->access(0,i));
	}
	
	for(int i = 0; i < 10; ++i){
		sa->insert(i,0,"heyya oh oh");
	}

	for(int i = 0; i < 10; ++i){
		sa->remove(i,0);
	}

	for(int i = 0; i < 10; ++i){
		EXPECT_EQ("null",sa->access(i,0));
	}
}

	
TEST(Vector,numCols){
	VectorTwoDArray<int>* ia = new VectorTwoDArray<int>(5,7,0);
	VectorTwoDArray<double>* da = new VectorTwoDArray<double>(9,9,0.0);
	VectorTwoDArray<std::string>* sa = 
		new VectorTwoDArray<std::string>(18,7,"null");
		
	EXPECT_EQ(7,ia->getNumCols());
	EXPECT_EQ(9,da->getNumCols());
	EXPECT_EQ(7,sa->getNumCols());
}

TEST(Vector,numRows){
	VectorTwoDArray<int>* ia = new VectorTwoDArray<int>(5,7,0);
	VectorTwoDArray<double>* da = new VectorTwoDArray<double>(9,9,0.0);
	VectorTwoDArray<std::string>* sa = 
		new VectorTwoDArray<std::string>(18,7,"null");
		
	EXPECT_EQ(5,ia->getNumRows());
	EXPECT_EQ(9,da->getNumRows());
	EXPECT_EQ(18,sa->getNumRows());

}


TEST(Vector,insert){
	VectorTwoDArray<int>* ia = new VectorTwoDArray<int>(10,7,0);
	VectorTwoDArray<double>* da = new VectorTwoDArray<double>(4,9,0.0);
	VectorTwoDArray<std::string>* sa = 
		new VectorTwoDArray<std::string>(12,12,"null");

	
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

	
TEST(Vector,remove){	
	
	VectorTwoDArray<int>* ia = new VectorTwoDArray<int>(10,7,0);
	VectorTwoDArray<double>* da = new VectorTwoDArray<double>(4,9,0.0);
	VectorTwoDArray<std::string>* sa = 
		new VectorTwoDArray<std::string>(12,12,"null");

	for(int i = 0; i < 9; ++i){
		ia->insert(i,0,i);
	}

	for(int i = 0; i < 9; ++i){
		ia->remove(i,0);
	}

	for(int i = 0; i < 9; ++i){
		EXPECT_EQ(0,ia->access(i,0));
	}

	
	for(int i = 0; i < 8; ++i){
		da->insert(0,i,(i+.8));
	}

	for(int i = 0; i < 8; ++i){
		da->remove(0,i);
	}

	for(int i = 0; i < 8; ++i){
		EXPECT_EQ(0,da->access(0,i));
	}
	
	for(int i = 0; i < 10; ++i){
		sa->insert(i,0,"heyya oh oh");
	}

	for(int i = 0; i < 10; ++i){
		sa->remove(i,0);
	}

	for(int i = 0; i < 10; ++i){
		EXPECT_EQ("null",sa->access(i,0));
	}
}

