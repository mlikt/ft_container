#ifndef __ERASE_H__
#define __ERASE_H__
namespace ft {

		template <class tree_traits>
			typename xtree<tree_traits>::iterator xtree<tree_traits>::erase (const_iterator F, const_iterator L) {
				while (F != L)
					erase(F++);
			return (iterator(find(Key(*F))));
		}

		template <class tree_traits>
		typename	xtree<tree_traits>::size_type xtree<tree_traits>::erase(const key_type& V) {
			nodeptr node = Find(V);
			nodeptr child, near;

			if (node == NIL) return (Size);

			if (Left(node) == NIL || Right(node) == NIL)
				near = node;
			else
				near = Lmost(Right(node));

			if (Left(near) != NIL)
				child = Left(near);
			else
				child = Right(near);
			
			child->Parent = Parent(near);

			if (Parent(near) != NIL) {
				if (WhichChild(near) == LEFT)
					Parent(near)->Left = child;
				else
					Parent(near)->Right = child;
			} else {
				Root = child;
				Leaf->Right = Root;
			}

			bool check = false;
			if (Colour(near) == Paint::Black)
				check = true;

			if (near != node) { 
				near->Parent = node->Parent;

				if (Parent(node) != NIL) {
					if (WhichChild(node) == LEFT)
						Parent(node)->Left = near;
					else
						Parent(node)->Right = near;
				}

				Colour(near) = Colour(node);

				Left(node)->Parent = near;
				Right(node)->Parent = near;


				near->Left = node->Left;
				near->Right = node->Right;
				if (WhichChild(node) == ROOT)
					Root = near;
			}

			if (check)
				FixDelete(child);

			DestructValue(node);
			FreeNode(node);
			Begin = Lmost(Root);
			Size--;
			return (Size);
		}

		template <class tree_traits>
		typename xtree<tree_traits>::iterator xtree<tree_traits>::erase(const const_iterator &P) {
			nodeptr node = Find( Key(*P));
			if (node == NIL)
				throw "out of range";
				
			erase(Key(node));
			return (iterator(NIL));
		}
}

#endif