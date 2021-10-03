// #include "functional_description.hpp"
#include "new.hpp"
#include <iostream>

namespace ft {

	// TEMPLATE CLASS back_insert_iterator

	template <class C>
		class back_insert_iterator
			: Outit <void, void, void, void>
		{
			public:
				typedef C						container_type;
				typedef typename C::reference 	reference;
				typedef typename C::value_type	value_type;

				explicit back_insert_iterator (C &X)
					: container(&X) {}
				
				back_insert_iterator<C> & operator = (typename C::const_reference val){
					container->push_back(val);
					return (*this);
				}

				back_insert_iterator<C> & operator * () {
					return (*this);
				}

				back_insert_iterator<C> & operator ++ () {
					return (*this);
				}

				back_insert_iterator<C> & operator ++ (int) {
					return (*this);
				}

			protected:
				C *container ;
		};
	
		template <class C> inline
			back_insert_iterator<C> back_inserter(C& X) {
				return (back_insert_iterator<C>(X));
			}

	// TEMPLATE CLASS front_insert_iterator

	template <class C>
		class front_insert_iterator
			: Outit <void, void, void, void>
		{
			public:
				typedef C						container_type;
				typedef typename C::reference 	reference;
				typedef typename C::value_type	value_type;

				explicit front_insert_iterator (C &X)
					: container(&X) {}
				
				front_insert_iterator<C> & operator = (typename C::const_reference val){
					container->push_front(val);
					return (*this);
				}

				front_insert_iterator<C> & operator * () {
					return (*this);
				}

				front_insert_iterator<C> & operator ++ () {
					return (*this);
				}

				front_insert_iterator<C> & operator ++ (int) {
					return (*this);
				}

			protected:
				C *container ;
		};
	
		template <class C> inline
			front_insert_iterator<C> front_inserter(C& X) {
				return (front_insert_iterator<C>(X));
			}

	// TEMPLATE CLASS insert_iterator

	template <class C>
		class insert_iterator
			: Outit <void, void, void, void>
		{
			public:
				typedef C						container_type;
				typedef typename C::reference 	reference;
				typedef typename C::value_type	value_type;

				explicit insert_iterator (C &X, typename C::iterator I)
					: container(&X), iter(I) {}
				
				insert_iterator<C> & operator = (typename C::const_reference val){
					iter = container->insert(iter, val);
					++iter;
					return (*this);
				}

				insert_iterator<C> & operator * () {
					return (*this);
				}

				insert_iterator<C> & operator ++ () {
					return (*this);
				}

				insert_iterator<C> & operator ++ (int) {
					return (*this);
				}

			protected:
				C *container ;
				typename C::iterator iter;
		};
	
		template <class C, class XI> inline
			insert_iterator<C> inserter(C& X, XI I) {
				return (insert_iterator<C>(X, C::iterator(I)));
			}

	// TEMPLATE CLASS istream_iterator
	template <class T, class E = char, class Tr = std::char_traits<E>, class Dist = ptrdiff_t>
		class istream_iterator
			: public iterator<input_iterator_tag, T, Dist, T*, T&>
		{
			public:
				typedef istream_iterator<T, E, Tr, Dist> Myt;
				typedef E char_type;
				typedef Tr traits_type;
				typedef std::basic_istream<E, Tr> istream_type;
				
				istream_iterator()
					: Istr(0) {}
				
				istream_iterator (istream_type& I)
				: Istr(&I) {
					Getval();
				}
				const T& operator * () const {
					return (Val);
				}
				const T* operator-> () const {
					return (&**this);
				}
				Myt& operator ++ () {
					Getval();
					return (*this);
				}
				Myt& operator ++ (int) {
					Myt Tmp = *this;
					Getval();
					return (Tmp);
				}

				bool Equal (const Myt& X) const {
					return (Istr == X.Istr);
				}
			
			protected:
				void Getval() {
					if (Istr != 0 && !(*Istr >> Val))
						Istr = 0;
				}
				istream_type *Istr;
				T Val;
		};

	// istream_iterator TEMPLATE OPERATORS

	template <class T, class E, class Tr, class Dist> inline 
		bool operator == (	const istream_iterator<T, E, Tr, Dist> &X,
							const istream_iterator<T, E, Tr, Dist> &Y) 
		{ return (X.Equal(Y)); }

	template <class T, class E, class Tr, class Dist> inline 
		bool operator != (	const istream_iterator<T, E, Tr, Dist> &X,
							const istream_iterator<T, E, Tr, Dist> &Y) 
		{ return (!(X == Y)); }

	// TEMPLATE CLASS ostream_iterator

	template <class T, class E = char, class Tr = std::char_traits<E> >
		class ostream_itertor
			: public Outit <void, void, void, void>
		{

		};

}