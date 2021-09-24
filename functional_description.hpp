namespace ft {
	
	struct input_iterator_tag;
	struct output_iterator_tag;
	struct forward_iterator_tag;
	struct bidirectional_iterator_tag;
	struct random_access_iterator_tag;

	// Шаблонные классы

	template <class C, class T, class Dist,
		class Pt, class Rt> 
		struct iterator;
	
	template <class It>
		struct iterator_traits;
	
	template <class T>
		struct iterator_traits<T *>;

	template <class RanIt>
		class reverse_iterator;

	template <class Cont>
		class back_insert_iterator;
	
	template <class Cont>
		class front_insert_iterator;

	template <class Cont>
		class insert_iterator;

	template <class U, class E, class T, class Dist>
		class istream_iterator;

	template <class U, class E, class T>
		class ostream_iterator;

	template <class E, class T>
		class istreambuf_iterator;

	template <class E, class T>
		class ostreambuf_iterator;


	// Шаблонные функции
	template <class RanIt>
		bool operator == (	const reverse_iterator<RanIt> &lhs,
							const reverse_iterator<RanIt> &rhs );

	template <class U, class E, class T, class Dist>
		bool operator == (	const istream_iterator<U, E, T, Dist> &lhs,
							const istream_iterator<U, E, T, Dist> &rhs );

	template <class E, class T>
		bool operator == (	const istreambuf_iterator<E, T> &lhs,
							const istreambuf_iterator<E, T> &lhr );

	template <class RanIt>
		bool operator != (	const reverse_iterator<RanIt> &lhs,
							const reverse_iterator<RanIt> &rhs );

	template <class U, class E, class T, class Dist>
		bool operator != (	const istream_iterator<U, E, T, Dist> &lhs,
							const istream_iterator<U, E, T, Dist> &rhs );

	template <class E, class T>
		bool operator != (	const istreambuf_iterator<E, T> &lhs,
							const istreambuf_iterator<E, T> &lhr );

	template <class RanIt>
		bool operator < (	const reverse_iterator<RanIt> &lhs,
							const reverse_iterator<RanIt> &rhs );	

	template <class RanIt>
		bool operator > (	const reverse_iterator<RanIt> &lhs,
							const reverse_iterator<RanIt> &rhs );

	template <class RanIt>
		bool operator <= (	const reverse_iterator<RanIt> &lhs,
							const reverse_iterator<RanIt> &rhs );	

	template <class RanIt>
		bool operator >= (	const reverse_iterator<RanIt> &lhs,
							const reverse_iterator<RanIt> &rhs );

	// template <class RanIt> было, есть ли ошибка в этом?
	template <class RanIt, class Dist>
		Dist operator - (	const reverse_iterator<RanIt> &lhs,
							const reverse_iterator<RanIt> &rhs );

	// template <class RanIt> было, есть ли ошибка в этом?
	template <class RanIt, class Dist>
		reverse_iterator<RanIt> operator + (	Dist n,
												const reverse_iterator<RanIt> &rhs );

	template <class Cont>
		back_insert_iterator<Cont> back_inserter (Cont &x);

	template <class Cont>
		front_insert_iterator<Cont> front_inserter (Cont &x);

	template <class Cont, class Iter>
		insert_iterator<Cont> inserter (Cont &x, Iter it);

	template <class InIt, class Dist>
		void advance (InIt &it, Dist n);

	template <class InIt>
		typename iterator_traits<InIt>::difference_type
		distance (InIt first, InIt last);
}