
#ifndef __CIT_TREE__
#define __CIT_TREE__
// #include "../xtree.hpp"
namespace ft{

template <class tree_traits>
class tree_const_iterator 
:	public bidirection_iterator<	typename xtree<tree_traits>::value_type, 
					typename xtree<tree_traits>::Dift, 
					typename xtree<tree_traits>::Ctptr, 
					typename xtree<tree_traits>::const_reference>,
	public iterator_pointers<tree_traits>
	{
		public:
			typedef bidirection_iterator<	typename xtree<tree_traits>::value_type,
							typename xtree<tree_traits>::Dift, 
							typename xtree<tree_traits>::Ctptr, 
							typename xtree<tree_traits>::const_reference> Mybase;
			
			typedef typename Mybase::iterator_category	iterator_category;
			typedef typename Mybase::difference_type	difference_type;
			typedef typename Mybase::value_type			value_type;
			typedef typename Mybase::pointer			pointer;
			typedef typename Mybase::reference			reference;


			typedef typename xtree<tree_traits>::nodeptr nodeptr;
			typedef typename xtree<tree_traits>::const_nodeptr const_nodeptr;

		protected:
				value_type& Value(const nodeptr &node){
					return(node->Value);
				}
		public:
			tree_const_iterator()
				: iterator_pointers<tree_traits>() {}

			tree_const_iterator(const tree_iterator<tree_traits> & X)
				: iterator_pointers<tree_traits>(X) {
				}

			tree_const_iterator(const tree_const_iterator& X)
				: iterator_pointers<tree_traits>(X) {
				}
			
			tree_const_iterator (const nodeptr &P)
				: iterator_pointers<tree_traits>(P) {
					this->End = P;
					ReCount(P);
			}

			tree_const_iterator (const const_nodeptr &P)
				: iterator_pointers<tree_traits>(P) {
					this->End = P;
					ReCount(P);
			}
			
			reference operator *() const {
				return (this->Ptr->Value);
			}
			typename xtree<tree_traits>::Ctptr operator-> () const {
				return (&**this);
			}

			template <class It1, class It2>
				friend bool operator == (const It1& X, const It2& Y);
			template <class It1, class It2>
				friend bool operator != (const It1& X, const It2& Y);
			
			tree_const_iterator& operator++ ()
			{
				Inc();
				return (*this);
			}

			tree_const_iterator operator++ (int)
			{
				tree_const_iterator Tmp = *this;
				++*this;
				return (Tmp);
			}

			tree_const_iterator& operator-- () {
				Dec();
				return (*this);
			}

			tree_const_iterator operator-- (int) {
				tree_const_iterator Tmp = *this;
				--*this;
				return (Tmp);
			}
		protected:


			nodeptr Left(const nodeptr& node){
				return ((nodeptr)(node->Left));
			}

			nodeptr Right(const nodeptr& node){
				return ((nodeptr)(node->Right));
			}

			nodeptr Parent(const nodeptr& node){
				return ((nodeptr)(node->Parent));
			}

			void Inc() {
				if (this->Last->Right != this->End)
					ReCount((nodeptr)this->End->Right);
				if (this->Ptr == this->End) {
					char *ptr = NULL; // Намеренная сега, чтобы пользователь знал, что мы выходим за this->End;
					*ptr = 0;
				}
				else if (Right(this->Ptr) != this->End) {
					this->Ptr = Right(this->Ptr);
					while ((nodeptr)this->Ptr->Left != this->End)
						this->Ptr = (nodeptr)(this->Ptr->Left);
				} else {
					nodeptr P;
					while ((P = Parent(this->Ptr)) != this->End && this->Ptr == Right(P))
						this->Ptr = P;
					this->Ptr = P;
				}
			}

			void Dec() {
				if (this->Last->Right != this->End)
					ReCount((nodeptr)this->End->Right);
				if (this->Ptr == this->End && this->End != this->Last) {
					this->Ptr = this->Last;
				} else if (this->Ptr == this->Begin) {
					char *ptr = NULL; // Намеренная сега, чтобы пользователь знал, что мы выходим за this->Begin;
					*ptr = 0;
				}
				else if (Left(this->Ptr) != this->End) {
					this->Ptr = Left(this->Ptr);
					while (this->Ptr->Right != this->End)
						this->Ptr = (nodeptr)(this->Ptr->Right);
				} else {
					nodeptr P;
					while ((P = Parent(this->Ptr)) != this->End && this->Ptr == Left(P))
						this->Ptr = P;
					this->Ptr = P;
				}
			}

			void ReCount (const_nodeptr NValue) {
					this->End = (nodeptr)NValue;
					while (this->End != this->End->Left)
						this->End = Left(this->End);					
					this->Last = Right(this->End);
					this->Begin = Right(this->End);
					while (Left(this->Begin) != this->End)
						this->Begin = Left(this->Begin);
					while (Right(this->Last) != this->End)
						this->Last = Right(this->Last);
			};
	};

};
#endif