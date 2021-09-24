
# include "functional_description.hpp"

namespace ft {

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

typedef long int ptrdiff_t ;

// Класс iterator прямого порядка
template <class C, class T, class Dist = ptrdiff_t,
		 class Pt = T* , class Rt = T&> struct iterator
	{
		typedef C		iterator_category;
		typedef T		value_type;
		typedef Dist	difference_type;
		typedef Pt		pointer;
		typedef Rt		reference;
	};

	//Iterator traits - свойства итератора (характеристики)
	template <class It>
		struct iterator_traits
		{
			typedef typename It::iterator_category iterator_category;
			typedef typename It::valut_type value_type;
			typedef typename It::distance_type distance_type;
			typedef typename It::pointer pointer;
			typedef typename It::reference reference;
		};
		
	template<class T>
		struct iterator_traits<T *>
		{
			typedef random_access_iterator_tag iterator_category;
			typedef T value_type;
			typedef ptrdiff_t distance_type;
			typedef T *pointer;
			typedef T& reference;
		};
		


// Дла опредения категории итератора ? Iter_cat
	template < class C, class T, class Dist> inline
		C Iter_cat (const iterator<C, T, Dist>&){
			C x;
			return (x);
		}

	template <class T> inline
		random_access_iterator_tag Iter_cat (const T*) {
			random_access_iterator_tag x;
			return (x);
		}

// Для определения типа данных (в контейнере?) Val_type или для определения типа итератора? 
// У итератора есть тип?

// Есил компилятор потдерживает частичную специализацию
// https://ravesli.com/urok-179-chastichnaya-spetsializatsiya-shablona/ - о частичной специализации
	template <class It> inline
		typename iterator_traits<It>::value_type *Val_type(It){
			return (0);
		}

// Если нет (Временно закаментированный код) [begin]

	template <class C, class T, class D, 
		class Pt, class Rt> inline
		T *Val_type(iterator< T, D, Pt, Rt>){
			return (0);
		}

	template<class T> inline
		T *Val_type (const T*){
			return (0);
		}
// Если нет [end]

// Реализация  iter_swap
	template <class FwdIt1, class FwdIt2, class T> inline
		void Iter_swap(FwdIt1 x, FwdIt2 y, T *){
			T Tmp = *x;
			*x = *y;
			*y = Tmp;
		}
	
	template <class FwdIt1, class FwdIt2> inline
		void iter_swap(FwdIt1 x, FwdIt2 y){
			Iter_swap( x , y, Val_type(&x));
		}

// Реверс функции

// # - 1-reverse
	template <class RanIt> inline
		void Reverse(RanIt first, RanIt last, bidirectional_iterator_tag) {
			for (; first < last; ++first)
				iter_swap(first, --last);
		}

// # - 2-reverse
	template<class BidIt> inline
		void Reverse(BidIt first, BidIt last, random_access_iterator_tag) {
			for(; first != last && first != --last; ++first)
				iter_swap(first, last);
		}

// # - 4-reverse
	template <class BidIt> inline
		void reverse(BidIt first, BidIt last) {
			Reverse(first, last, 
			typename iterator_traits<BidIt>::iterator_catergory());
		}	

/* Расмотреть подробней ошибка: переопределения [begin] */

// // # - 3-reverse
// 	template<class BidIt> inline
// 		void reverse(BidIt first, BidIt last) {
// 			Reverse(first, last, typename BidIt::iterator_category());
// 		}

// // # - 5-reverse
// 	template<class BidIt> inline
// 		void reverse(BidIt first, BidIt last) {
// 			Reverse(first, last, Iter_cat(first));
// 		}

/* Расмотреть подробней ошибка: переопределения 'error: redefinition of' [end] */

// distance_type измеряем растояние между двумя итераторамои
// Если существует частичная специализация
	template <class It> inline
		typename iterator_traits<It>::distance_type *Dist_type(It){
			return (0);
		}
// Если отсутствует [begin]
	template <class C, class T, class D,
		class Pt, class Rt> inline
		D *Dist_type(iterator<C, T, D, Pt, Rt>){
			return (0);
		}
	
	template<class T> inline
		ptrdiff_t *Dist_type(const T *){
			return (0);
		}
// Если отсутствует [end]

// Функции advance и distance (продвижение и расстояние) p += n и n = last - first

	template <class InIt, class Dist> inline
		void advance (InIt& p, Dist n);

	/* Историческая штука? */	
	// template <class InIt> inline
	// 	typename iterator_traits<InIt>::distance_type
	// 	distance(InIt first, InIt last);

	template <class InIt, class D> inline
		void Distance(InIt first, InIt last, D n0);


	/* Специализированные итераторы reverse iterators, insertion iterators, stream iterators, stream buffer iterator */
	/* Реверсивные итераторы, итераторы вставки, итераторы потока, итераторы буфера потока */

	// Класс итератор обратного порядка
	
	template <class RanIt>
		class reverse_iterator;

	// Шаблоный класс back_insert_iterator

	template <class Cont>
		class back_insert_iterator
			: public iterator 
			<output_iterator_tag, void, void, void, void>
		{
			public:
				typedef Cont	container_type;
				typedef typename Cont::reference 	reference;
				typedef typename Cont::value_type	value_type;
		};
}