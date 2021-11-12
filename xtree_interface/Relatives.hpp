#ifndef __RELATIVES_H__
#define __RELATIVES_H__
#include "../xtree.hpp"

namespace ft {
			template <class tree_traits>
			typename xtree<tree_traits>::value_type& xtree<tree_traits>::Value(const nodeptr &node) const {
				return (node->Value);
			}
			template <class tree_traits>
			typename xtree<tree_traits>::value_type& xtree<tree_traits>::Value(const nodeptr &node) {
				return (node->Value);
			}
			template <class tree_traits>
			typename xtree<tree_traits>::Palette& xtree<tree_traits>::Colour(const nodeptr &node) {
				return (node->colour);
			}
			template <class tree_traits> 
			typename xtree<tree_traits>::nodeptr xtree<tree_traits>::Left(const nodeptr &node) const {
				return ((nodeptr)(node->Left));
			}
			template <class tree_traits>
			typename xtree<tree_traits>::nodeptr xtree<tree_traits>::Right(const nodeptr &node) const {
				return ((nodeptr)(node->Right));
			}

			template <class tree_traits>
			typename xtree<tree_traits>::nodeptr xtree<tree_traits>::Left(const nodeptr &node) {
				return ((nodeptr)(node->Left));
			}

			template <class tree_traits>
			typename xtree<tree_traits>::nodeptr xtree<tree_traits>::Right(const nodeptr &node) {
				return ((nodeptr)(node->Right));
			}
			template <class tree_traits>
			typename xtree<tree_traits>::nodeptr xtree<tree_traits>::Parent(const nodeptr &node) {
				return ((nodeptr)(node->Parent));
			}
			template <class tree_traits>
			typename xtree<tree_traits>::nodeptr xtree<tree_traits>::Grandfather(const nodeptr &node) {
				return ((nodeptr)(Parent(node)->Parent));
			}
			template <class tree_traits>
			int xtree<tree_traits>::WhichChild(const nodeptr &node) {
				if (Parent(node) == NIL)
					return (ROOT);
				if (Parent(node)->Left == node)
					return (LEFT);
				if (Parent(node)->Right == node)
					return (RIGHT);
				return (NOTCHILD);
			}
			template <class tree_traits>
			typename xtree<tree_traits>::nodeptr xtree<tree_traits>::Uncle(const nodeptr &node) {
				if (Grandfather(node) == NIL)
					return (NIL);
				if (WhichChild(Parent(node)) == LEFT)
					return ((nodeptr)(Grandfather(node)->Right));
				return ((nodeptr)(Grandfather(node)->Left));
			}
			template <class tree_traits>
			typename xtree<tree_traits>::nodeptr xtree<tree_traits>::Brother(const nodeptr &node) {
				if (Parent(node) == NIL)
					return (NIL);
				if (WhichChild(node) == LEFT)
					return ((nodeptr)(Parent(node)->Right));
				return ((nodeptr)(Parent(node)->Left));
			}
			template <class tree_traits>
			typename xtree<tree_traits>::nodeptr xtree<tree_traits>::Min(nodeptr node) {
				while (Left(node) != NIL)
					node = Left(node);
				return (node);
			}
			template <class tree_traits>
			typename xtree<tree_traits>::nodeptr xtree<tree_traits>::Max(nodeptr node) {
				while (Right(node) != NIL)
					node = Right(node);
				return (node);
			}
			template <class tree_traits>
			typename xtree<tree_traits>::nodeptr xtree<tree_traits>::Rmost(nodeptr node) {
				return (Max(node));
			}
			template <class tree_traits>
			typename xtree<tree_traits>::nodeptr xtree<tree_traits>::Lmost(nodeptr node) {
				return (Min(node));
			}

			template <class tree_traits>
			typename xtree<tree_traits>::key_type xtree<tree_traits>::Key(nodeptr node) const {				
				return (this->GetKey(Value(node)));
			}

			template <class tree_traits>
			typename xtree<tree_traits>::key_type xtree<tree_traits>::Key(const value_type &V) const {				
				return (this->GetKey(V));
			}
}
#endif