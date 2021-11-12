#ifndef __BALANCE__
#define __BALANCE__
#include "../xtree.hpp"
namespace ft {

	template <class tree_traits>
		void xtree<tree_traits>::RotateLeft (nodeptr node) {
			if (node == NIL)
				return ;
			
			nodeptr right	= Right(node);
			nodeptr left	= Left(right);

			if (right != NIL)
				right->Parent = Parent(node);

			if (Parent(node) != NIL) {
				if (WhichChild(node) == RIGHT)
					Parent(node)->Right = right;
				else if (WhichChild(node) == LEFT)
					Parent(node)->Left = right;
			}

			if (left != NIL)
				left->Parent = node;
			
			node->Right		= left;
			node->Parent	= right;
			right->Left		= node;
		}

	template <class tree_traits>
		void xtree<tree_traits>::RotateRight(nodeptr node) {
			if (node == NIL)
				return ;
			
			nodeptr left = Left(node);
			nodeptr right = Right(left);

			if (left != NIL)
				left->Parent = Parent(node);

			if (Parent(node) != NIL) {
				if (WhichChild(node) == RIGHT)
					Parent(node)->Right = left;
				else if (WhichChild(node) == LEFT)
					Parent(node)->Left = left;
			}

			if (right != NIL)
				right->Parent = node;
			
			node->Left		= right;
			node->Parent	= left;
			left->Right	= node;
		}

	template <class tree_traits>
		typename	xtree<tree_traits>::nodeptr xtree<tree_traits>::FindRoot(nodeptr node) {
			while (Parent(node) != NIL)
				node = Parent(node);
			return (node);
		}

	template <class tree_traits>
			void xtree<tree_traits>::FixInsertion(nodeptr node) {
			if (Parent(node) == NIL) {
				Colour(node) = Paint::Black;
				return ;
			}
			while (Colour(Parent(node)) == Paint::Red) {
				if (WhichChild(Parent(node)) == LEFT) {
					if (Colour(Uncle(node)) == Paint::Red) {
						Colour(Parent(node))		= Paint::Black;
						Colour(Uncle(node))			= Paint::Black;
						Colour(Grandfather(node))	= Paint::Red;
						node = Grandfather(node);
					} else {
						if (WhichChild(node) == RIGHT) {
							node = Parent(node);
							RotateLeft(node);
						}
						Colour(Parent(node))		= Paint::Black;
						Colour(Grandfather(node))	= Paint::Red;
						RotateRight(Grandfather(node));
					}
				} else if (WhichChild(Parent(node)) == RIGHT) {
					if (Colour(Uncle(node)) == Paint::Red) {
						Colour(Parent(node))		= Paint::Black;
						Colour(Uncle(node))			= Paint::Black;
						Colour(Grandfather(node))	= Paint::Red;
						node = Grandfather(node);
					} else {
						if (WhichChild(node) == LEFT) {
							node = Parent(node);
							RotateRight(node);
						}
						Colour(Parent(node))		= Paint::Black;
						Colour(Grandfather(node))	= Paint::Red;
						RotateLeft(Grandfather(node));
					}
				}
			}
			Root = FindRoot(node);
			Leaf->Right = Root;
			Colour(Root) = Paint::Black;
		}

	template <class tree_traits>
			void xtree<tree_traits>::FixDelete(nodeptr node) {
			while (node != Root && Colour(node) == Paint::Black)
			{
				if (WhichChild(node) == LEFT ) {
					if (Colour(Brother(node)) == Paint::Red) {
						Colour(Brother(node))	= Paint::Black;
						Colour(Parent(node))	= Paint::Red;
						RotateLeft(Parent(node));
					}

					if (Colour((nodeptr)Brother(node)->Left)	== Paint::Black &&
						Colour((nodeptr)Brother(node)->Right)	== Paint::Black ) {
							Colour(Brother(node)) = Paint::Red;
							node = Parent(node);
					} else {
						if (Colour((nodeptr)Brother(node)->Right)	== Paint::Black) {
							Colour((nodeptr)Brother(node)->Left)	= Paint::Black;
							Colour(Brother(node))					= Paint::Red;
							RotateRight(Brother(node));
						}
						Colour(Brother(node))					= Colour(Parent(node));
						Colour(Parent(node)) 					= Paint::Black;
						Colour((nodeptr)Brother(node)->Right)	= Paint::Black;
						RotateLeft(Parent(node));
						node = Root;
					}

				} else {
					if (Colour(Brother(node)) == Paint::Red) {
						Colour(Brother(node))	= Paint::Black;
						Colour(Parent(node))	= Paint::Red;
						RotateRight(Parent(node));
					}

					if (Colour((nodeptr)Brother(node)->Left)	== Paint::Black &&
						Colour((nodeptr)Brother(node)->Right)	== Paint::Black ) {
							Colour(Brother(node)) = Paint::Red;
							node = Parent(node);
					} else {
						if (Colour((nodeptr)Brother(node)->Left)	== Paint::Black) {
							Colour((nodeptr)Brother(node)->Right)	= Paint::Black;
							Colour(Brother(node))					= Paint::Red;
							RotateLeft(Brother(node));
						}
						Colour(Brother(node))					= Colour(Parent(node));
						Colour(Parent(node)) 					= Paint::Black;
						Colour((nodeptr)Brother(node)->Left)	= Paint::Black;
						RotateRight(Parent(node));
						node = Root;
					}
				}
			}
			
			Colour(node) = Paint::Black;
			Root = FindRoot(node);
			Leaf->Right = Root;
		}
}
#endif