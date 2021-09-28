#include "pair.hpp"

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

struct Int_iterator_tag {};

typedef long int ptrdiff_t ;

// Класс iterator прямого порядка
template <class C, class T, class D = ptrdiff_t,
		 class Pt = T* , class Rt = T&> struct iterator
	{
		typedef C		iterator_category;
		typedef T		value_type;
		typedef D		difference_type;
		typedef Pt		pointer;
		typedef Rt		reference;
	};

	template  <class T, class D, class Pt, class Rt>
		struct Bidit: public iterator<bidirectional_iterator_tag,
			T, D, Pt, Rt> {};

	template  <class T, class D, class Pt, class Rt>
		struct Ranit: public iterator<random_access_iterator_tag,
			T, D, Pt, Rt> {};

	template  <class T, class D, class Pt, class Rt>
		struct Outit: public iterator<output_iterator_tag,
			T, D, Pt, Rt> {};

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
		

	template<class T>
		struct iterator_traits<const T *>
		{
			typedef random_access_iterator_tag iterator_category;
			typedef T value_type;
			typedef ptrdiff_t distance_type;
			typedef T *pointer;
			typedef T& reference;
		};

	template < class C, class T, class D, class Pt, class Rt> inline
		C Iter_cat (const iterator<C, T, D, Pt, Rt>&){
			C x;
			return (x);
		}

	template <class T> inline
		random_access_iterator_tag Iter_cat (const T*) {
			random_access_iterator_tag x;
			return (x);
		}

    // INTEGER FUNCTION Iter_cat

    inline Int_iterator_tag Iter_cat(bool){
        Int_iterator_tag X;
        return (X);
    }

    inline Int_iterator_tag Iter_cat(char){
        Int_iterator_tag X;
        return (X);
    }

    inline Int_iterator_tag Iter_cat(signed char){
        Int_iterator_tag X;
        return (X);
    }

    inline Int_iterator_tag Iter_cat(unsigned char){
        Int_iterator_tag X;
        return (X);
    }

    inline Int_iterator_tag Iter_cat(wchar_t){
        Int_iterator_tag X;
        return (X);
    }

    inline Int_iterator_tag Iter_cat(short){
        Int_iterator_tag X;
        return (X);
    }

    inline Int_iterator_tag Iter_cat(unsigned short){
        Int_iterator_tag X;
        return (X);
    }

    inline Int_iterator_tag Iter_cat(int){
        Int_iterator_tag X;
        return (X);
    }

    inline Int_iterator_tag Iter_cat(unsigned int){
        Int_iterator_tag X;
        return (X);
    }

    inline Int_iterator_tag Iter_cat(long){
        Int_iterator_tag X;
        return (X);
    }

    inline Int_iterator_tag Iter_cat(unsigned long){
        Int_iterator_tag X;
        return (X);
    }

	// TEMPLATE FUNCTION Distance

	template <class InIt> inline
		typename iterator_traits<InIt>::difference_type
		distance (InIt F, InIt L){
			typename iterator_traits<InIt>::difference_type
			N =  0;
			Distance2(F, L, N, Iter_cat(F));
			return (N);
		}

	template <class InIt, class D> inline
		void Distance(InIt F, InIt L, D& N){
			Distance2(F, L, N, Iter_cat(F));
		}

	template <class InIt, class D> inline
		void Distance2(InIt F, InIt L, D& N, input_iterator_tag){
			for(; F != L; ++F)
				++N;
		}

	template <class InIt, class D> inline
		void Distance2(InIt F, InIt L, D& N, forward_iterator_tag){
			for(; F != L; ++F)
				++N;
		}

	template <class InIt, class D> inline
		void Distance2(InIt F, InIt L, D& N, bidirectional_iterator_tag){
			for(; F != L; ++F)
				++N;
		}

	template <class InIt, class D> inline
		void Distance2(InIt F, InIt L, D& N, random_access_iterator_tag){
			N += L - F;
		}

	// TEMPLATE CLASS Ptrit

	template <class T, class D, class Pt, class Rt, 
		class Pt2, class Rt2>
		class Ptrit : public iterator<random_access_iterator_tag,
			T, D, Pt, Rt> 
	{
		public:
			typedef Ptrit<T, D, Pt, Rt, Pt2, Rt2> Myt;
			
			Ptrit() {};
			explicit Ptrit(Pt P)
				: current (P) {}
			Ptrit(const Ptrit<T, D, Pt, Rt, Pt2, Rt2> &X)
				: current (X.base()) {}
			Pt base() const
				{ return (current);}
			Rt operator * () const
				{ return (*current);}
			Pt operator -> () const
				{ return (&**this);}
			Myt& operator++ ()
				{
					++current;
					return (*this);
				}
			Myt operator ++ (int)
				{
					Myt Tmp = *this;
					++current;
					return (Tmp);
				}
				Myt& operator-- ()
				{
					--current;
					return (*this);
				}
			Myt operator -- (int)
				{
					Myt Tmp = *this;
					--current;
					return (Tmp);
				}
			bool operator == (int Y) const
				{ return (current == (Pt)Y);}
			bool operator == (const Myt& Y) const
				{ return (current == Y.current);}
			bool operator != (const Myt& Y) const
				{ return (!(*this == Y));}
			Myt& operator += (D N)
				{ 
					current += N;
					return (*this);
				}
			Myt operator + (D N) const
			{
				return (Myt(current + N));
			}
			Myt& operator -= (D N)
				{ 
					current -= N;
					return (*this);
				}
			Myt operator - (D N) const
			{
				return (Myt(current - N));
			}
			Rt operator [] (D N) const
			{ return (*(*this + N));}
			bool operator < (const Myt& Y) const
			{ return (current < Y.current);}
			bool operator > (const Myt& Y) const
			{ return (Y < *this);}
			bool operator <= (const Myt& Y) const
			{ return (!(Y < *this));}
			bool operator >= (const Myt& Y) const
			{ return (!(*this < Y));}
			D operator - (const Myt& Y)
			{ return (current - Y.current);}
		protected:
			Pt current;
	};
	
	template <class T, class D, class Pt, class Rt,
		class Pt2, class Rt2> inline
		Ptrit <T, D, Pt, Rt, Pt2, Rt2>
		operator + (D N,
			const Ptrit<T, D, Pt, Rt, Pt2, Rt2>& Y)
		{ return (Y + N);}

	// TEMPLATE CLASS reverse_iterator

	template <class RanIt>
		class reverse_iterator: public iterator<
		typename iterator_traits<RanIt>::iterator_category,
		typename iterator_traits<RanIt>::value_type,
		typename iterator_traits<RanIt>::difference_type,
		typename iterator_traits<RanIt>::pointer,
		typename iterator_traits<RanIt>::reference>
		{
			public:
				typedef reverse_iterator<RanIt> Myt;
				typedef typename iterator_traits<RanIt>::difference_type D;
				typedef typename iterator_traits<RanIt>::pointer Pt;
				typedef typename iterator_traits<RanIt>::reference Rt;
				typedef RanIt iterator_type;

				reverse_iterator(){}
				explicit reverse_iterator(RanIt X)
				:current(X) {}
				RanIt base() const
					{return (current)}
				template <class U>
					reverse_iterator (const reverse_iterator<U>& X)
					: current (X.base()){}

				Rt operator * () const {
					RanIt Tmp = current;
					return (*--Tmp);
				}
				Pt operator -> () const {
					return (&**this);
				}
				Myt& operator ++ () {
					--current;
					return (*this);
				}
				Myt operator ++ (int) {
					Myt Tmp = *this;
					--current;
					return (Tmp);
				}
				Myt& operator -- () {
					++current;
					return (*this);
				}
				Myt operator -- (int) {
					Myt Tmp = *this;
					++current;
					return (Tmp);
				}
				bool Eq (const Myt& Y) const {
					return (current == Y.current);
				}
				// После только для произвольного доступа
				Myt& operator += (D N) {
					current -= N;
					return (*this);
				}
				Myt operator -= (D N){
					return (Myt(current + N));
				}
				Rt operator [] (D N) const {
					return (*(*this + N));
				}
				bool Lt (const Myt& Y) const {
					return (Y.current < current);
				}
				D Mi (const Myt& Y) const {
					return (Y.current - current);
				}

			protected:
				RanIt current;
		};

	// reverse_iterator TEMPLATE OPERATORS
	template <class RanIt> inline
		typename reverse_iterator<RanIt>::D
			operator - (const reverse_iterator<RanIt>& X,
				const reverse_iterator<RanIt>& Y) {
					return (X.Mi(Y));
				}

	template <class RanIt> inline
		bool operator == (const reverse_iterator<RanIt>& x,
			const reverse_iterator<RanIt>& Y) {
				return (X.Eq(Y));
			}
			
}