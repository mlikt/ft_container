#ifndef __MAP_H__
#define __MAP_H__

#include "xtree.hpp"
#include "less.hpp"
#include "pair.hpp"

namespace ft {

	
	template <class K, class T, class Pr, class Al, class Cmpr_value>
	class xtree_map_traits {
		public: 
			typedef K							key_type;
			typedef ft::pair<const K, T>		value_type;
			typedef Pr							key_compare;
			typedef	Cmpr_value					value_compare;
			typedef typename Al::template rebind<value_type>::other
				allocator_type;
						
			xtree_map_traits()
			: v_comp(), comp() {};
			
			xtree_map_traits(key_compare Parg)
			: v_comp(Parg), comp (Parg) {}

			key_type GetKey(const value_type& V) const {
					return (V.first);
			};

			value_compare v_comp;
			key_compare   comp;
};


	template <class K, class T,
		class Pr = ft::less<K>,
		class A = std::allocator<K> >
		class map
		{	
			public:
			
			typedef ft::pair<const K, T>	value_type;
			
			class value_compare
				: public ft::binary_function<value_type, value_type, bool>
			{
				protected:
					typedef Pr						key_compare;
				public:
					value_compare(key_compare Pred)
					: comp(Pred) {};

					bool operator()(const value_type& X, const value_type& Y) const {
						return (comp(X.first, Y.first));
					}
				protected:
					key_compare comp;
			};

			private:
				typedef ft::xtree<xtree_map_traits<K, T, Pr, A, value_compare> > _base;
				typedef map<K, T, Pr, A> container_type;
			public:

				typedef typename _base::allocator_type allocator_type;
				typedef typename _base::size_type		size_type;
				typedef typename _base::const_pointer	const_pointer;
				typedef typename _base::const_reference	const_reference;
				typedef typename _base::difference_type	difference_type;
				typedef typename _base::key_compare		key_compare;
				typedef typename _base::key_type		key_type;
				typedef typename _base::pointer			pointer;
				typedef typename _base::reference		reference;

				typedef typename _base::iterator iterator;
				typedef typename _base::const_iterator const_iterator;

				typedef typename _base::reverse_iterator	reverse_iterator;
				typedef typename _base::const_reverse_iterator	const_reverse_iterator;

				map ()
					: tree(key_compare(), allocator_type()) {};

				explicit map( const key_compare& k_comp,
            		 const allocator_type& Al = allocator_type() ) 
					 : tree(k_comp, Al) {};

				map (const map& copy)
				: tree(copy.key_comp(), copy.get_allocator(), copy.begin(), copy.end()) 
				{ };
				template <class It>
					map(It _f, It _l, 
					const key_compare &k_comp = key_compare(), 
					const allocator_type& Al = allocator_type() )
					: tree(k_comp, Al, _f, _l) {};
				
				~map(){};
				// ????????
				// void print_graph(){
				// 	tree.PrintGraphMap();
				// }

				iterator begin() {
					return (tree.begin());
				}

				const_iterator begin() const {
					return (tree.begin());
				}

				iterator end() {
					return (tree.end());
				}

				const_iterator end() const {
					return (tree.end());
				}

				reverse_iterator rbegin() {
					return (tree.rbegin());
				}

				reverse_iterator rend() {
					return (tree.rend());
				}
				const_reverse_iterator rbegin()  const {
					return (tree.rbegin());
				}

				const_reverse_iterator rend() const  {
					return (tree.rend());
				}


				ft::pair<iterator, bool> insert(const value_type & value) {
					return (tree.insert(value));
				}

				template <class It>
					void insert (It F, It L) {
						tree.insert(F, L);
				}

				iterator find(const key_type & value) {
					return (tree.find(value));
				}

				const_iterator find(const key_type & value) const {
					return (tree.find(value));
				}

				void clear() {
					tree.clear();
				}

				bool empty() const {
					return (tree.empty());
				}

				size_type size() const {
					return (tree.size());
				}

				T& at(const key_type &key){
					iterator it = find(key);
					if (it == end())
						throw "out of range";
					return(it->second);
				}
	
				const T& at(const key_type &key) const {
					const_iterator it = find(key);
					if (it == end())
						throw "out of range";
					return(it->second);
				}

				size_type max_size() const {
					return (tree.max_size());
				}
				
				size_type erase (const key_type &value) {
					return(tree.erase(value));
				}

				iterator erase (iterator _f, iterator _l) {
					return(tree.erase(_f, _l));
				}

				iterator erase(const iterator &it) {
					return (tree.erase(it));
				}

				allocator_type get_allocator () const {
					return (tree.Alnode);
				}

				void swap(map& other){
					tree.swap(other.tree);
				}

				size_type count(const key_type &key) const {
					size_type c = size_type();
					if (tree.end() != tree.find(key)){
						c++;
						return (c);
					}
					return (c);
				}

				iterator upper_bound(const key_type &key) {
					return (tree.upper_bound(key));
				}

				iterator lower_bound(const key_type& key) {
					return (tree.lower_bound(key));
				}

				const_iterator upper_bound(const key_type &key) const {
					return (tree.upper_bound(key));
				}

				const_iterator lower_bound(const key_type& key) const {
					return (tree.lower_bound(key));
				}

				ft::pair<iterator, iterator> equal_range(const key_type & key) {
					return (tree.equal_range(key));
				}

				ft::pair<const_iterator, const_iterator> equal_range(const key_type & key) const {
					return (tree.equal_range(key));
				}

				key_compare key_comp() const {
					return (tree.comp);
				}

				value_compare value_comp() const {
					return (tree.v_comp);
				}

				map& operator = (const map& copy) {
					clear();
					insert(copy.begin(), copy.end());
					return (*this);
				}

				T& operator[](const key_type& key) {
					iterator it = find(key);
					ft::pair<iterator, bool> check(end(), false);
					if (it == end())
						check = insert(ft::make_pair<K, T>(key, T()));
					if (check.second)
						it = check.first;
					return (it->second);
				}
			protected:

			_base tree;
		};

		template <class _K, class _T, class _Pr, class _A>
			bool operator == (	const map<_K, _T, _Pr, _A>& x,
								const map<_K, _T, _Pr, _A>& y) 
			{
				return (x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()));
			}
		template <class _K, class _T, class _Pr, class _A>
			bool operator != (	const map<_K, _T, _Pr, _A>& x,
								const map<_K, _T, _Pr, _A>& y) 
			{
				return (!(x == y));
			}

		template <class _K, class _T, class _Pr, class _A>
			bool operator < (	const map<_K, _T, _Pr, _A>& x,
								const map<_K, _T, _Pr, _A>& y) 
			{
				return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
			}

		template <class _K, class _T, class _Pr, class _A>
			bool operator > (	const map<_K, _T, _Pr, _A>& x,
								const map<_K, _T, _Pr, _A>& y) 
			{
				return (y < x);
			}

		template <class _K, class _T, class _Pr, class _A>
			bool operator >= (	const map<_K, _T, _Pr, _A>& x,
								const map<_K, _T, _Pr, _A>& y) 
			{
				return (!(y < x));
			}

		template <class _K, class _T, class _Pr, class _A>
			bool operator <= (	const map<_K, _T, _Pr, _A>& x,
								const map<_K, _T, _Pr, _A>& y) 
			{
				return (!(y > x));
			}
}

#endif