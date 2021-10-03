

# ifndef __ITERATOR_H__
# define __ITERATOR_H__

# include <string>
// # include "functional_description.hpp"
# include "new.hpp"

namespace ft {

// // Итератор вывода

// struct output_iterator_tag{};

// // Итератор ввода

// struct input_iterator_tag {};

// // Последовательный итератор ( однонаправленый, прямой )

// struct forward_iterator_tag 
// 	: public input_iterator_tag {};

// // Двунаправленный итератор

// struct bidirectional_iterator_tag
// 	: public forward_iterator_tag {};

// // Итератор произвольного доступа

// struct random_access_iterator_tag
// 	: public bidirectional_iterator_tag {};


// Класс iterator прямого порядка - он же базовый класс для всех типов итераторов
// template <class C, class T, class D = ptrdiff_t,
// 		 class Pt = T* , class Rt = T&> struct iterator
// 	{
// 		typedef C		iterator_category;	// Категория итератора
// 		typedef T		value_type;			// Тип значения
// 		typedef D	difference_type;	// Tип различия
// 		typedef Pt		pointer;			// Указатель 
// 		typedef Rt		reference;			// Ссылка
// 	};

	//Iterator traits - свойства итератора (характеристики)
	// template <class It>
	// 	struct iterator_traits
	// 	{
	// 		typedef typename It::iterator_category	iterator_category;
	// 		typedef typename It::valut_type			value_type;
	// 		typedef typename It::distance_type		distance_type; // Тип расстояния
	// 		typedef typename It::pointer			pointer;
	// 		typedef typename It::reference			reference;
	// 	};
	
	// template<class T>
	// 	struct iterator_traits<T *>
	// 	{
	// 		typedef random_access_iterator_tag	iterator_category;
	// 		typedef T							value_type;
	// 		typedef ptrdiff_t					distance_type;
	// 		typedef T*							pointer;
	// 		typedef T&							reference;
	// 	};
		


// Дла опредения категории итератора ? Iter_cat (iterator_category)
	template < class C, class T, class D> inline
		C Iter_cat (const iterator<C, T, D>&){
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

	template <class InIt, class D> inline
		void advance (InIt& p, D n);

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
	/*
	* Этот шаблонный класс описывает объект итератора вывода. Он вставляет
	* элементы в контейнер типа C, к которому он получает доступ через
	* через защищенный объект-указатель хранимый под именем container.
	*/
	template <class C>
		class back_insert_iterator
			: public iterator 
			<output_iterator_tag, void, void, void, void>
		{
			public:
				typedef C						container_type;
				typedef typename C::reference 	reference;
				typedef typename C::value_type	value_type;

				explicit back_insert_iterator (C &x);
				back_insert_iterator & operator = (typename C::const_reference val);
				back_insert_iterator & operator * ();
				back_insert_iterator & operator ++ ();
				back_insert_iterator & operator ++ (int);

			protected:
				C *container ;
		};
	
	// Шаблонный класс front_insert_iterator (см. строка 197)

	template <class C>
		class front_insert_iterator
			: public iterator
			<output_iterator_tag, void, void, void, void>
		{
			public:
				typedef C						container_type;
				typedef typename C::reference 	reference;
				typedef typename C::value_type	value_type;

				explicit front_insert_iterator (C &x);
				front_insert_iterator & operator = (typename C::const_reference val);
				front_insert_iterator & operator * ();
				front_insert_iterator & operator ++ ();
				front_insert_iterator & operator ++ (int);

			protected:
				C *container ;
		};
	
	// Шаблонный класс insert_iterator

	template <class C>
		class insert_iterator
			: public iterator
			<output_iterator_tag, void, void, void, void>
		{
			public:
				typedef C						container_type;
				typedef typename C::reference 	reference;
				typedef typename C::value_type	value_type;

				insert_iterator (C &x, typename C::iterator it);
				insert_iterator & operator = (typename C::const_reference val);
				insert_iterator & operator * ();
				insert_iterator & operator ++ ();
				insert_iterator & operator ++ (int);

			protected:
				C					*container ;
				typename C::iterator	iter;
		};

	// Шаблонный класс  istream_iterator
	/*
	* Этот шаблонный класс описывает объект итератора ввода. 
	* Он извлекает объекты класса U из входного потока, к которому 
	* он получает доступ через хранимый объект, имеющий тип указателя
	* basic_istream<E, T>
	*/

	template <class U, class E = char, class T = std::char_traits<E> ,
	class D = ptrdiff_t >
		class istream_iterator
			: public iterator
			< input_iterator_tag, U, D, U *, U &>
		{
			public:
				typedef E							char_type;
				typedef T							traits_type;
				typedef std::basic_istream<E, T>	istream_type;
				
				istream_iterator();
				istream_iterator(istream_type & is);

				const U& operator * () const;
				const U* operator -> () const;
				istream_iterator<U, E, T, D>& operator ++ ();
				istream_iterator<U, E, T, D> operator ++ (int);
			// protected:
			// 	istream_type is;
		};

	// Шаблонный класс istreambuf_iterator

	// template <class E, class T = std::char_traits<E> >
	// 	class istreambuf_iterator
	// 		: public iterator
	// 		<input_iterator_tag, E, typename T::off_type, E *, E&>
	// 	{
	// 		public:
	// 			typedef E							char_type;
	// 			typedef T							traits_type;
	// 			typedef typename T::int_type		int_type;
	// 			typedef std::basic_streambuf<E, T>	streambuf_type;
	// 			typedef std::basic_istream<E, T>	istream_type;

	// 			istreambuf_iterator (streambuf_type *sb = 0) throw ();
	// 			istreambuf_iterator (istream_type &is) throw ();

	// 			const E& operator * () const;
	// 			const E* operator -> () const;
	// 			istreambuf_iterator& operator ++ ();
	// 			istreambuf_iterator operator ++ (int);
	// 			bool equal (const istreambuf_iterator& rhs) const;
	// 		// protected:
	// 		// 	istream_type is;
	// 		// 	streambuf_type sb;
	// 	};
}

# endif