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
	char *p;
	std::allocator<char> allchar;

	p = allchar.allocate(10, (void *)0);

	char *tmp = p;

	allchar.construct(tmp, char());
	tmp++;
	allchar.construct(tmp, char());
	tmp++;
	allchar.construct(tmp, char());
	tmp++;

	std::cout << (*p == 0) << std::endl;

	return (0);
}