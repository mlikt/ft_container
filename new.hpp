#include "pair.hpp"
#include <iostream>
#include "iterator.hpp"

namespace ft {
    
// Итератор вывода

struct output_iterator_tag;

// Итератор ввода

struct input_iterator_tag;

// Последовательный итератор ( однонаправленый, прямой )

struct forward_iterator_tag;

// Двунаправленный итератор

struct bidirectional_iterator_tag;

// Итератор произвольного доступа

struct random_access_iterator_tag;

struct Int_iterator_tag;

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
		bool operator == (const reverse_iterator<RanIt>& X,
			const reverse_iterator<RanIt>& Y) {
				return (X.Eq(Y));
			}

	template <class RanIt> inline
		bool operator != (const reverse_iterator<RanIt>& X,
			const reverse_iterator<RanIt>& Y) {
				return (!(X ==Y));
			}


	template <class RanIt> inline
		bool operator < (const reverse_iterator<RanIt>& X,
			const reverse_iterator<RanIt>& Y) {
				return (X.Lt(Y));
			}

	template <class RanIt> inline
		bool operator > (const reverse_iterator<RanIt>& X,
			const reverse_iterator<RanIt>& Y) {
				return (Y < X);
			}

	template <class RanIt> inline
		bool operator <= (const reverse_iterator<RanIt>& X,
			const reverse_iterator<RanIt>& Y) {
				return (!(Y < X));
			}

	template <class RanIt> inline
		bool operator >= (const reverse_iterator<RanIt>& X,
			const reverse_iterator<RanIt>& Y) {
				return (!(X < Y));
			}

	// TEMPLATE CLASS Revbidit

	template <class BidIt>
		class Revbidit: public iterator <
			typename iterator_traits<BidIt>::iterator_category,
			typename iterator_traits<BidIt>::value_type,
			typename iterator_traits<BidIt>::difference_type,
			typename iterator_traits<BidIt>::pointer,
			typename iterator_traits<BidIt>:: reference >
	{
		public:
		typedef Revbidit<BidIt> Myt;
		typedef typename iterator_traits<BidIt>::difference_type;
		typedef typename iterator_traits<BidIt>::pointer Pt;	
		typedef typename iterator_traits<BidIt>::reference Rt;
		typedef BidIt iterator_type;

		Revbidit(){}
		
		explicit Revbidit (BidIt X)
		: current (X) {}

		BidIt base() const {
			return (current);
		}

		Rt operator * () const {
			BidIt Tmp = current;
			return (*--Tmp);
		}

		Pt operator -> () const {
			Rt Tmp = **this;
			return (&Tmp);
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

		bool operator == (const Myt& Y) const {
			return (current == Y.current);
		}

		bool operator != (const Myt& Y) const {
			return (!(*this == Y));
		}

		protected:
		BidIt current;
	};

	// TEMPLATE CLASS istreambuf_iterator

	template <class E, class Tr>
		class istreambuf_iterator
			: public iterator<input_iterator_tag,
				E, typename Tr::off_type, E *, E&>
	{
		public:
		typedef istreambuf_iterator<E, Tr> Myt;
		typedef E char_type;
		typedef Tr traits_type;
		typedef std::basic_streambuf<E, Tr> streambuf_type;
		typedef std::basic_istream<E, Tr> istream_type;
		typedef typename traits_type::int_type int_type;

		istreambuf_iterator (streambuf_type *Sb = 0) throw ()
			: Sbuf(sb), Got (Sb == 0) {}

		istreambuf_iterator (istream_type& I) throw () 
		: Sbuf(I.rdbuf()), Got(I.rdbuf() == 0) {}

		const E& operator * () const {
			if (!Got)
			((Myt *)this)->Peek();
			return (Val);
		}

		const E* operator->() const {
			return (&**this);
		}

		Myt& operator ++ () {
			Inc();
			return (*this);
		}

		Myt operator ++ (int) {
			Myt Tmp = *this;

			if (!Got)
				Peek();
			Inc();
			return (Tmp);
		}
		bool equal(const Myt& X) const {
			if (!Got)
				((Myt *)this)->Peek();
			if (!X.Got)
				((Myt *)&X)->Peek();
			return Sbuf != 0 && X.Sbuf != 0 ||
			Sbuf !=0 && X.Sbuf != 0 ;
		}

		private:
		void Inc() {
			if (Sbuf == 0
				|| traits_type::eq_int_type(traits_type::eof(),
				Sbuf->sbumpc()))
					Sbuf = 0, Got = true;
			else
				Got = false;
		}

		E Peek() {
			int_type C;
			if (Sbuf == 0 
				|| traits_type::eq_int_type(traits_type::eof(),
					C = Sbuf->sgetc()))
				Sbuf = 0;
			else
				Val = traits_type::to_char_type(C);
			Got = true;
			return (Val);
		}

		streambuf_type *Sbuf;
		bool Got;
		E Val;
	};

	// TEMPLATE OPERATORS istreambuf_iterator

	template <class E, class Tr> inline
		bool operator == (const istreambuf_iterator<E, Tr> &X,
		const istreambuf_iterator<E, Tr>& Y) {
			return (X.equal(Y));
		}
	template <class E, class Tr> inline
		bool operator != (const istreambuf_iterator<E, Tr>& X,
		const istreambuf_iterator<E, Tr>& Y) {
			return (!(X == Y));
		}

	// TEMPLATE CLASS ostreambuf_iterator
	template <class E, class Tr>
		class ostreambuf_iterator
			:public Outit 
	{
		public:
		typedef ostreambuf_iterator<E, Tr> Myt;
		typedef Tr traits_type;
		typedef std::basic_streambuf<E, Tr> streambuf_type;
		typedef std::basic_ostream<E, Tr> ostream_type;

		ostreambuf_iterator (streambuf_type *Sb) throw ()
		:Failed(false), Sbuf(sb) {}

		ostreambuf_iterator (ostream_type& O) throw()
		:Failed(false), Sbuf(O.rdbuf()) {}

		Myt& operator = (E X) {
			if (Sbuf == 0
				|| traits_type::eq_int_type(Tr::eof(),
					Sbuf->sputc(X)))
				Failed = true;
			return (*this);
		}

		Myt& operator * (){
			return (*this);
		}

		Myt& operator ++ () {
			return (*this);
		}

		Myt& operator ++ (int) {
			return (*this);
		}

		bool failed () const throw () {
			return (Failed);
		}

		private:
		bool Failed;
		streambuf_type *Sbuf;
	};

	// ALGORITHM STUFF
	template <class InIt, class OutIt> inline
		OutIt copy (InIt F, InIt L, OutIt X) {
			for (; F != L; ++X, ++F)
				*X = *F;
			return (X);
		}

	template <class BidIt1, class BidIt2> inline
		BidIt2 copy_backward(BidIt1 F, BidIt1 L, BidIt2 X) {
			while (F != L)
				*--X = *--L;
			return (X);
		}

	template <class InIt1, class InIt2> inline
		pair<InIt1, InIt2> mismatch(InIt1 F, InIt1 L, InIt2 X) {
			for (; F != L && *F == *X; ++F, ++X)
				;
			return (pair<InIt1, InIt2>(F, X));
		}

	template <class InIt1, class InIt2, class Pr> inline
	pair<InIt1, InIt2> mismatch(InIt1 F, InIt1 L, InIt2 X, Pr P) {
		for (; F != L && P(*F, *X); ++F, ++X)
			;
		return (pair<InIt1, InIt2>(F, X));
	}

	template <class InIt1, class InIt2> inline
		bool equal (InIt1 F, InIt1 L, InIt2 X) {
			return (mismatch(F, L, X).first == L);
		}
	
	template <class InIt1, class InIt2, class Pr> inline
		bool equal (InIt1 F, InIt1 L, InIt2 X, Pr P) {
			return (mismatch(F, L, X, P).first == L);
		}

	template<class FwdIt, class T> inline
		void fill (FwdIt F, FwdIt L, const T& X) {
			for (; F != L; ++F)
				*F = X;
		}

	template<class OutIt, class Sz, class T> inline
		void fill (OutIt F, Sz N, const T& X) {
			for (; 0 < N; --N, ++F)
				*F = X;
		}

	template<class InIt1, class InIt2> inline
		bool lexicographical_compare(InIt1 F1, InIt1 L1,
		InIt2 F2, InIt2 L2) {
			for (; F1, != L1 && F2 != L2, ++F1, ++F2)
				if (*F1 < *F2)
					return (true);
				else if (*F2 < *F1)
					return (false);
			return (F1 == L1 && F2 != L2);
		}

	template<class InIt1, class InIt2, class Pr> inline
		bool lexicographical_compare(InIt1 F1, InIt1 L1,
		InIt2 F2, InIt2 L2, Pr P) {
			for (; F1, != L1 && F2 != L2, ++F1, ++F2)
				if (P(*F1, *F2))
					return (true);
				else if (P(*F2,*F1))
					return (false);
			return (F1 == L1 && F2 != L2);
		}

	template<class T> inline
		const T& max(const T& X, const T& Y) {
			return (X < Y ? Y : X);
		}

	template<class T, class Pr> inline
		const T& max(const T& X, const T& Y, Pr P) {
			return (P(X,Y) ? Y : X);
		}

	template<class T> inline
		const T& min(const T& X, const T& Y) {
			return (Y < X ? Y : X);
		}

	template<class T, class Pr> inline
		const T& min(const T& X, const T& Y, Pr P) {
			return (P(Y,X) ? Y : X);
		}

	template <class T> inline
	void swap(T& X, T& Y) {
		T Tmp = X;
		X = Y, Y = Tmp;
	}
}
