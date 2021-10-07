#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <memory>
#include <sstream>
// #include "iterator2.hpp"
#include <cmath>
#include <stack>

#include "vector.hpp"



int main (void) {


	std::vector<int> k;
	std::vector<int> k2;
	std::stack<int> st;
	std::stack<int> st1;

	/* Соответствия между stack и vector
	k.empty();
	k.pop_back();
	k.push_back(1234);
	k.size();
	k.end();
	k.swap(k2);

	st.empty();
	st.pop();
	st.push(1);
	st.size();
	st.top();
	st.swap(st1);
	*/


	int ptrr[10] = { 1, 2, 3, 4, 5};
	ft::Ptrit<int, long, int *, int&, int *, int&> itft(ptrr);

	// std::cout << *itft << std::endl; 
	// std::cout << itft.base() << std::endl;

	// mytype reb;
	k.push_back(26);
	
	ft::insert_iterator<std::vector<int> > L(k, k.begin());

	L = 11;
	L++;
	L = 6;
	L++;
	L = 23;

	ft::back_insert_iterator<std::vector<int> > end(k);


	end = 4;
	end = 8;
	end = 0;
	end = 13;
	end = 3;
	end = 5;

	ft::vector<int> myvec(10);

	myvec[1] = 4;
	// std::vector<int>::iterator libit(&myvec[0]);

	myvec.insert(myvec.begin(), 133);
	ft::vector<int>::iterator myit(&myvec[0]);
	ft::vector<int> newvec(10);

	std::cout << *myvec.begin() << std::endl;
	myvec.insert(myvec.begin(), newvec.begin(), newvec.end());
	std::cout << myvec.size() << std::endl;
	std::cout << newvec.size() << std::endl;
	std::cout << *myvec.begin() << std::endl;


	// std::sort(k.begin(), k.end());

	// // for (std::vector<int>::iterator k1 = k.begin(); k1 != k.end(); k1 ++)
	// // 	std::cout << *k1 << std::endl;

	// std::map<int, char> map;

	// for (int i = 0; i < 10; i++)
	// 	map.insert(map.begin(), std::make_pair(9 - i, 'z' - i));
	
	// 	map.insert(map.begin(), std::make_pair(0, 'd'));

	// // =( map - это бинарное дерево
	// for (std::map<int, char>::iterator it = map.begin(); it != map.end(); it++)
	// 	std::cout << it->first << " " << it->second << std::endl;



	int &ref1 = *(new int(57));

	// int a = 4;
	// int &ref = *((int *)0);



	// std::cout << ref1  << std::endl;

	// int numbr = 1 == 0 ? 6 : 4;

	// std::cout << numbr << std::endl;
	delete &ref1;
	return (0);
}