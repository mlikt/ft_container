namespace ft {
	
	struct input_iterator_tag;
	struct output_iterator_tag;
	struct forward_iterator_tag;
	struct bidirectional_iterator_tag;
	struct random_access_iterator_tag;
	typedef long int ptrdiff_t ;


// Итератор вывода

struct output_iterator_tag{};

// Итератор ввода

struct input_iterator_tag {};

// Последовательный итератор ( однонаправленый, прямой )

struct forward_iterator_tag 
	: public input_iterator_tag {};

// Двунаправленный итератор

struct bidirectional_iterator_tag
	: public forward_iterator_tag {};

// Итератор произвольного доступа

struct random_access_iterator_tag
	: public bidirectional_iterator_tag {};

	// Шаблонные классы

	// template <class C, class T, class D = ptrdiff_t, class Pt = T*, class Rt = T&> 
	// 	struct iterator ;
	
	template <class It>
		struct iterator_traits ;
	
	template <class T>
		struct iterator_traits<T *> ;

	template <class RanIt>
		class reverse_iterator;

	template <class C>
		class back_insert_iterator ;
	
	template <class C>
		class front_insert_iterator ;

	template <class C>
		class insert_iterator ;

	template <class U, class E, class T, class D>
		class istream_iterator ;

	template <class U, class E, class T>
		class ostream_iterator ;

	template <class E, class T>
		class istreambuf_iterator ;

	template <class E, class T>
		class ostreambuf_iterator ;


	// Шаблонные функции
	template <class RanIt>
		bool operator == (	const reverse_iterator<RanIt> &lhs,
							const reverse_iterator<RanIt> &rhs ) ;

	template <class U, class E, class T, class D>
		bool operator == (	const istream_iterator<U, E, T, D> &lhs,
							const istream_iterator<U, E, T, D> &rhs ) ;

	template <class E, class T>
		bool operator == (	const istreambuf_iterator<E, T> &lhs,
							const istreambuf_iterator<E, T> &lhr ) ;

	template <class RanIt>
		bool operator != (	const reverse_iterator<RanIt> &lhs,
							const reverse_iterator<RanIt> &rhs ) ;

	template <class U, class E, class T, class D>
		bool operator != (	const istream_iterator<U, E, T, D> &lhs,
							const istream_iterator<U, E, T, D> &rhs ) ;

	template <class E, class T>
		bool operator != (	const istreambuf_iterator<E, T> &lhs,
							const istreambuf_iterator<E, T> &lhr ) ;

	template <class RanIt>
		bool operator < (	const reverse_iterator<RanIt> &lhs,
							const reverse_iterator<RanIt> &rhs ) ;	

	template <class RanIt>
		bool operator > (	const reverse_iterator<RanIt> &lhs,
							const reverse_iterator<RanIt> &rhs ) ;

	template <class RanIt>
		bool operator <= (	const reverse_iterator<RanIt> &lhs,
							const reverse_iterator<RanIt> &rhs ) ;	

	template <class RanIt>
		bool operator >= (	const reverse_iterator<RanIt> &lhs,
							const reverse_iterator<RanIt> &rhs ) ;

	// template <class RanIt> было, есть ли ошибка в этом?
	template <class RanIt, class D>
		D operator - (	const reverse_iterator<RanIt> &lhs,
							const reverse_iterator<RanIt> &rhs ) ;

	// template <class RanIt> было, есть ли ошибка в этом?
	template <class RanIt, class D>
		reverse_iterator<RanIt> operator + (	D n,
												const reverse_iterator<RanIt> &rhs ) ;

	template <class C>
		back_insert_iterator<C> back_inserter (C &x) ;

	template <class C>
		front_insert_iterator<C> front_inserter (C &x) ;

	template <class C, class Iter>
		insert_iterator<C> inserter (C &x, Iter it);

	template <class InIt, class D>
		void advance (InIt &it, D n);

	template <class InIt>
		typename iterator_traits<InIt>::difference_type
		distance (InIt first, InIt last) ;
}