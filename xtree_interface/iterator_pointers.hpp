#ifndef __IT_PTR__
#define __IT_PTR__

#include "../xtree.hpp"
namespace ft {

template <class tree_traits>
class iterator_pointers {
	public:

	typedef typename xtree<tree_traits>::nodeptr nodeptr;
	typedef typename xtree<tree_traits>::const_nodeptr const_nodeptr;
	typedef typename xtree<tree_traits>::value_type value_type;
	
	iterator_pointers()
	:Ptr(0), End(0), Begin(0), Last(0){}
	iterator_pointers(nodeptr P)
	:Ptr(P), End(0), Begin(0), Last(0){}
	iterator_pointers(const_nodeptr P)
	:Ptr((nodeptr)P), End((nodeptr)P), Begin(0), Last(0){}
	iterator_pointers(const iterator_pointers& N)
	:Ptr(N.Ptr), End(N.End), Begin(N.Begin), Last(N.Last){}
	// ~iterator_pointers(){}
	protected:
		nodeptr Ptr;
		nodeptr End;
		nodeptr Begin;
		nodeptr Last;
};

}

#endif