#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <memory>
#include <sstream>
#include "iterator2.hpp"
#include <cmath>

int main (void) {


	std::list<int> k;
	k.push_back(4);
	
	ft::insert_iterator<std::list<int> > L(k, k.begin());

	L = 4;
	L++;
	L = 6;
	L++;
	L = 23;

	ft::back_insert_iterator<std::list<int> > end(k);
	ft::front_insert_iterator<std::list<int> > begin(k);
	ft::front_insert_iterator<std::list<int> > *begin1;


	end = 4;
	end = 8;

	begin = 11;
	begin = 12;	
	begin1 = &begin;
	
	*(begin1) = 16;

	for (std::list<int>::iterator k1 = k.begin(); k1 != k.end(); k1 ++)
		std::cout << *k1 << std::endl;



	// char l1[10] = "hello";
	// std::char_traits<char> char_tr;

	// std::istringstream s1(l1);
	// std::ostringstream s11(l1);

	// std::char_traits<char> kkk;

	// std::basic_istream<char , std::char_traits<char> > *k3;
	// std::basic_ostream<char , std::char_traits<char> > *k33;

	// k3 = &s1;

	// k33 = &s11;

	// std::cout << k3->rdbuf() << std::endl;	


	// std::cout << k3->rdbuf() << std::endl;
	

	return (0);
}