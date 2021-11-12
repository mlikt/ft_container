#include "vector.hpp"
#include "set.hpp"
#include "map.hpp"
#include <vector>
#include <deque>
#include <stack>
#include "stack.hpp"

int main(){

	ft::vector<int> vec;
	ft::set<int>	set;
	ft::vector<ft::pair<int, char> > vec_pair;
	ft::map<int, char> map;

	ft::stack<int> stack;
	std::stack<int> sstack;

	ft::stack<int, std::vector<int> > mystack;
	ft::stack<int, std::deque<int> > mystack;

	for(int i = 0; i < 30; i++)
		set.insert(i);

	vec.insert(vec.begin(), set.begin(), set.end());
	set.clear();
	set.insert(vec.begin(), vec.end());
	set.print_graph();

	for(int i = 0; i < 25; i++)
		map[i] = 'a' + i;

	vec_pair.insert(vec_pair.begin(), map.begin(), map.end());
	map.clear();
	map.insert(vec_pair.begin(), vec_pair.end());
	map.print_graph();

	return (0);
}