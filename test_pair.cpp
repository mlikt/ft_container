#include <assert.h>
#include <iostream>
#include "pair.hpp"

typedef ft::pair<int, char> Pair_ic;
Pair_ic p0;

class Int {
	private:
		int val;

	public:
		Int (int v)
			: val(v)
			{}
		bool operator == (Int x) const
			{	return (val == x.val);	}
		bool operator <  (Int x) const
			{	return (val < x.val);	}
		void func(void);
};

int main ( void )
{
	Pair_ic p1 = p0, p2(3, 'a');

	assert(p1.first == 0);
	assert(p1.second == 0);
	assert(p2.first == 3);
	assert(p2.second == 'a');

	assert(p2 == ft::make_pair( (Pair_ic::first_type) 3,
								(Pair_ic::second_type) 'a'));
	assert(p2 < ft::make_pair( (Pair_ic::first_type) 4,
								(Pair_ic::second_type) 'a'));
	assert(p2 < ft::make_pair( (Pair_ic::first_type) 3,
								(Pair_ic::second_type) 'b'));
	
	assert (p1 != p2);
	assert (p2 > p1);
	assert (p2 <= p2);
	assert (p2 >= p2);

}