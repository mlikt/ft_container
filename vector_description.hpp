#include <memory>
#include "iterator2.hpp"

namespace ft {
	template<class T, class A = std::allocator<T> >
		class vector {
			public:
				typedef A							allocator_type;
				typedef typename A::pointer			pointer;
				typedef typename A::const_pointer	const_pointer;
				typedef typename A::reference		reference;
				typedef	typename A::const_reference	const_reference;
				typedef T0							iterator;
				typedef T1							const_iterator;
				typedef T2							size_type;
				typedef T3							difference_type;
				typedef reverse_iterator<const_iterator>	const_reverse_iterator;
				typedef reverse_iterator<iterator>			reverse_iterator;

				vector();
				explicit vector(const A& al);
				explicit vector(size_type n);
				vector(size_type n, const T& x);
				vector(size_type n, const T& x, const A& a1);
				vector(const vector& x);
				template<class InIt>
					vector(InIt first, InIt last);
				template<class InIt>
					vector(InIt first, InIt last, const A& al);


				void reserve(size_type n);
				size_type capacity() const;

				iterator begin();
				const_iterator begin() const;
				iterator end();
				const_iterator end() const;

				reverse_iterator rbegin();
				const_reverse_iterator rbegin() const;
				reverse_iterator rend();
				const_reverse_iterator rend() const;

				void resize(size_type n);
				void resize(size_type n, T x);

				size_type size() const;
				size_type max_size() const;

				bool empty() const;

				A get_allocator() const;
				reference at(size_type pos);
				const_reference at(size_type pos) const;
				
				reference operator[] (size_type pos);
				const_reference operator[](size_type pos);

				reference front();
				const_reference front() const;

				reference back();
				const_reference back() const;

				void push_back(const T& x);
				void pop_back();

				template<class InIt>
					void assign(InIt first, InIt last);		// здесь может понадобиться is_integral
					void assign(size_type n, const T& x);	// заполняет n-ое  кол-во элементов знчением x

				iterator insert(iterator it, const T& x);
				void insert(iterator it, size_type n, const T& x);
				template<class InIt>
					void insert(iterator it, InIt first, InIt last);

				iterator erase(iterator it);
				iterator erase(iterator first, iterator last);

				void clear();
				void swap(vector &x);
		};
}