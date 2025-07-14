#include <iostream>
#include "vector.hpp"
#include <vector>
int main()
{
	std::cout << "Hello world!" << std::endl;

	clonestl::vector<int> myVec;
	std::cout << myVec.size() << std::endl;
	std::cout << "size: " << myVec.size() << "; capacity: " << myVec.capacity() << std::endl;
	myVec.push_back(1);
	std::cout << "size: " << myVec.size() << "; capacity: " << myVec.capacity() << std::endl;
	myVec.push_back(2);
	std::cout << "size: " << myVec.size() << "; capacity: " << myVec.capacity() << std::endl;
	std::cout << myVec.size() << std::endl;
	myVec.print();
	std::cout <<"My vec: "<< myVec[0] << std::endl;
	myVec[0] = 100;
	std::cout << "My vec: " << myVec[0] << std::endl;

	std::vector<int> stlVector;
	stlVector.push_back(1);
	stlVector[0] = 2;
	int x = stlVector[0];
}