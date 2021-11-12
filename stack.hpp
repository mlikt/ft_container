#ifndef __STACK_H__
#define __STACK_H__
#include "vector.hpp"

namespace ft {

	template <class _Tp, class _Container = ft::vector<_Tp> >
	class stack
	{
		public:
			typedef _Container									container_type;
			typedef typename container_type::value_type			value_type;
			typedef typename container_type::reference			reference;
			typedef typename container_type::const_reference	const_reference;
			typedef typename container_type::size_type			size_type;
		protected:
			container_type c;
		public:
			stack(): c(container_type()) {};
			stack(const stack& copy) : c(copy.c){}
			stack& operator = (const stack& copy){ c = copy.c; return *this; }
			explicit stack (const container_type& __c): c (__c) {}

			bool empty() const {
				return c.empty();
				}
			size_type size() const {
				return c.size();
				}
			reference top() {
				return c.back();
				}
			const_reference top() const {
				return c.back();
				}

			void push(const value_type& value) {
				c.push_back(value);
				}
			void pop() {
				c.pop_back();
				}
			void swap(stack & _s) {
				ft::swap(c, _s.c);
			}

			template <class T1, class C1>
			friend bool operator == (	const stack<T1, C1> & x, 
										const stack<T1, C1> & y);
			template <class T1, class C1>
			friend bool operator < (	const stack<T1, C1> & x, 
										const stack<T1, C1> & y);
	};

	template <class T1, class C1>
			bool operator == (	const stack<T1, C1> & x, const stack<T1, C1> & y)
			{
				return (x.c == y.c);
			};

	template <class T1, class C1>
			bool operator != (	const stack<T1, C1> & x, const stack<T1, C1> & y)
			{
				return (!(x == y));
			};

	template <class T1, class C1>
			bool operator < (	const stack<T1, C1> & x, const stack<T1, C1> & y)
			{
				return (x.c < y.c);
			};

	template <class T1, class C1>
			bool operator > (	const stack<T1, C1> & x, const stack<T1, C1> & y)
			{
				return (y < x);
			};

	template <class T1, class C1>
			bool operator >= (	const stack<T1, C1> & x, const stack<T1, C1> & y)
			{
				return (!(x < y));
			};

	template <class T1, class C1>
			bool operator <= (	const stack<T1, C1> & x, const stack<T1, C1> & y)
			{
				return (!(y < x));
			};

};

#endif