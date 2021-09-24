#include <iostream>
#include <vector>
#include <map>
#include "iterator.hpp"

int main (void){

	std::vector<int> k;
	std::vector<int> b;
	std::map<int, char> k1;

	k.push_back(1);
	b.push_back(2);
 
	k.insert(k.begin(), 5);
	k.reserve(k.size());
	std::vector<int>::iterator it1;
	std::vector<int>::iterator it2;

	std::map<int, char>::iterator itk;

	it1 = k.begin();
	it2 = b.begin();

	std::cout << k[0] << std::endl;
	std::cin >> *it1;

	int k12;

	std::cout << typeid(ft::Val_type(&k12)).name() << std::endl;
	

	std::cout << k[0] << std::endl;
	std::cout << b[0] << std::endl;
	return (0);
}