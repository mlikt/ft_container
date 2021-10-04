#include <assert.h>
#include <iostream>
#include <string>
#include <strstream>
#include <deque>
#include "iterator2.hpp"

typedef char* PtrIt;

void takes_ran_tag(ft::random_access_iterator_tag) {}

// Тестирование основных свойств шаблона

void test_prop() {

	ft::random_access_iterator_tag	*ran_tag	= (ft::random_access_iterator_tag *) 0;
	ft::bidirectional_iterator_tag	*bid_tag	= (ft::bidirectional_iterator_tag *) 0;
	ft::forward_iterator_tag		*fwd_tag	= (ft::forward_iterator_tag *) 0;
	ft::input_iterator_tag			*in_tag		= (ft::input_iterator_tag *) 0;
	ft::output_iterator_tag			*p_out_tag	= (ft::output_iterator_tag *) 0;


	typedef ft::iterator<ft::input_iterator_tag, float, short, float *, float &> Iter;
	float f1;

	Iter::iterator_category	*it_tag		= (ft::input_iterator_tag *)0;
	Iter::value_type		*it_val		= (float *) 0;
	Iter::difference_type	*it_dist	= (short *) 0;
	Iter::pointer			it_ptr		= (float *) 0;
	Iter::reference			it_ref		= f1;

	typedef ft::iterator_traits<Iter> Traits;

	Traits::iterator_category	*tr_tag		= (ft::input_iterator_tag *) 0;
	Traits::value_type			*tr_val		= (float *) 0;
	Traits::difference_type		*tr_dist	= (short *) 0;
	Traits::pointer				tr_ptr		= (float *) 0;
	Traits::reference			tr_ref		= f1;

	typedef ft::iterator_traits<PtrIt> Ptraits;
	char ch;

	takes_ran_tag(Ptraits::iterator_category());
	Ptraits::value_type			*ptr_val	= (char *)0;
	Ptraits::difference_type	*ptr_dist	= (ft::ptrdiff_t *) 0;
	Ptraits::pointer			ptr_ptr		= (char *) 0;
	Ptraits::reference			ptr_ref		= ch;

	const char *pc = "abcdefg";

	ft::advance(pc, 4);
	assert(*pc == 'e');
	ft::advance(pc, -1);
	assert(*pc == 'd');
	assert(ft::distance(pc, pc + 3) == 3);

}

// Тестирование итератора reverse_iterator

typedef ft::reverse_iterator<PtrIt> RevIt;

class MyrevIt : RevIt {
	public:
		MyrevIt (RevIt::iterator_type p)
			: RevIt(p) {}
		RevIt::iterator_type get_current () const
		{ return (current); }
};

void test_revit() {

	char *pc = (char *)"abcdefg" + 3;

	PtrIt pcit(pc);
	
	RevIt::iterator_type *p_iter = (PtrIt *) 0;
	RevIt rit0, rit(pcit);

	assert(rit.base() == pcit);
	assert(*rit == 'c');
	assert(*++rit == 'b');
	assert(*rit++ == 'b' && *rit == 'a');
	assert(*--rit == 'b');
	assert(*rit-- == 'b' && *rit == 'c');
	assert(*(rit += 2) == 'a');
	assert(*(rit -= 2) == 'c');
	assert(*(rit + 2) == 'a' && *rit == 'c');
	assert(*(rit - 2) == 'e' && *rit == 'c');
	assert(rit[2] == 'a');
	assert(rit == rit);
	assert(!(rit < rit) && rit < rit + 1);
	assert((rit + 2) - rit == 2);

	MyrevIt myrit(pc);
	assert(myrit.get_current() == pcit);
}

// Teстирование итераторов вставки

typedef std::deque<char, std::allocator<char> > Cont;
typedef ft::back_insert_iterator<Cont>			BackIt;
typedef ft::front_insert_iterator<Cont>			FrontIt;
typedef ft::insert_iterator<Cont>				InsIt;

class MybackIt : public BackIt {
	public:
		MybackIt (BackIt::container_type& c) 
			: BackIt (c) {}
		BackIt::container_type *get_container () const {
			return (this->container);
		}
};

class MyfrontIt : public FrontIt {
	public:
		MyfrontIt (FrontIt::container_type& c)
			: FrontIt (c) {}
		FrontIt::container_type *get_container () const {
			return (this->container);
		}
};

class MyinsIt : public InsIt {
	public:
		MyinsIt (InsIt::container_type& c, Cont::iterator it)
			: InsIt(c, it) {}
		InsIt::container_type *get_container () const {
			return (this->container);
		}
		Cont::iterator get_iterator () const {
			return (this->iter);
		}
};

void test_inserts() {
	Cont c0;
	char ch;

	BackIt::container_type	*pbi_const	= (Cont *) 0;
	BackIt::reference		pbi_ref		= ch;
	BackIt::value_type		*pbi_val	= (char *) 0;
	BackIt bit(c0);

	*bit = 'a', ++bit;
	*bit++ = 'b';
	assert(c0[0] == 'a' && c0[1] == 'b');

	MybackIt mybkit (c0);

	assert(mybkit.get_container () == &c0);
	*ft::back_inserter(c0)++ = 'x';
	assert(c0[2] == 'x');

	FrontIt::container_type	*pfi_cont	= (Cont *)0;
	FrontIt::reference		pfi_ref		= ch;
	FrontIt::value_type		*pfi_val	= (char *) 0;
	FrontIt	fit(c0);

	*fit = 'c', ++fit;
	*fit++ = 'd';
	assert (c0[0] == 'd' && c0[1] == 'c');

	MyfrontIt myfrit(c0);
	assert(myfrit.get_container() == &c0);
	*ft::front_inserter(c0)++ = 'y';
	assert(c0[0] == 'y');

	InsIt::container_type	*pii_cont	= (Cont *) 0;
	InsIt::reference		pii_ref		= ch;
	InsIt::value_type		*pii_val	= (char *) 0;
	InsIt	iit(c0, c0.begin());

	*iit = 'e', ++iit;
	*iit++ = 'f';
	assert(c0[0] == 'e' && c0[1] == 'f');

	MyinsIt	myinst(c0, c0.begin());
	assert(myinst.get_container() == &c0);
	assert(myinst.get_iterator() == c0.begin());
	*ft::inserter(c0, c0.begin())++ = 'z';
	assert(c0[0] == 'z');
}

// Тестирование istream_iterator

void test_istreamit() {
	std::istrstream istr("0 1 2 3");

	typedef ft::istream_iterator<int, char, std::char_traits<char>, ft::ptrdiff_t> IstrIt;

	IstrIt::char_type		*p_char		= (char *) 0;
	IstrIt::traits_type		*p_traits	= (std::char_traits<char> *) 0;
	IstrIt::istream_type	*p_istream	= (std::istream *) 0;

	IstrIt iit0, iit(istr);

	int n;

	// int k = *iit;
	// std::cout << k << std::endl;
	
	for (n = 0; n < 5 && iit != iit0; ++n)
		assert(*iit++ == n);
	assert(n == 4);
}

// Тестирование ostream_iterator

void test_ostreamit() {

	std::ostrstream ostr0, ostr;

	typedef ft::ostream_iterator<int, char, std::char_traits<char> > OstrIt;

	OstrIt::value_type		*p_val		= (int *) 0;
	OstrIt::char_type		*p_char		= (char *) 0;
	OstrIt::traits_type		*p_traits	= (std::char_traits<char> *) 0;
	OstrIt::ostream_type	*p_ostream	= (std::basic_ostream<char, std::char_traits<char> > *) 0;

	OstrIt oit0(ostr0), oit(ostr, "||");

	*oit0 = 1, ++oit0;
	*oit0++ = 2;
	ostr0 << std::ends;

	assert( std::strcmp(ostr0.str(), "12") == 0 );
	ostr.freeze(false);

	*oit = 1, ++oit;
	*oit++ = 2;
	ostr << std::ends;
	assert(std::strcmp(ostr.str(), "1||2||") == 0);
	ostr.freeze(false);
}

// Теустирование istreambuf_iterator

void test_istrbufit() {
	std::istrstream istr ("0123"), istr1("");

	typedef ft::istreambuf_iterator<char, std::char_traits<char> > IsbIt;

	IsbIt::char_type		*p_char		= (char *) 0;
	IsbIt::traits_type		*p_traits	= (std::char_traits<char> *) 0;
	IsbIt::int_type			*p_int		= (int *) 0;
	IsbIt::streambuf_type	*p_streambuf 	=
	(std::basic_streambuf<char, std::char_traits<char> > *) 0;
	IsbIt::istream_type		*p_istream		=
	(std::basic_istream<char, std::char_traits<char> > *) 0;

	IsbIt iit0, iit(istr), iit1(istr1.rdbuf());

	int n;

	for (n = 0; n < 5 && iit != iit0; ++n)
		assert(*iit++ == n + '0');
	assert(n == 4);
	assert(iit0.equal(iit1)); 
}

// Тестирование ostreambuf_iterator

void test_ostrbufit() {
	std::ostrstream ostr;
	typedef ft::ostreambuf_iterator<char, std::char_traits<char> > OsbIt;

	OsbIt::char_type		*p_char		 = (char *) 0;
	OsbIt::traits_type		*p_traits	 = (std::char_traits<char> *)0;
	OsbIt::streambuf_type	*p_streambuf = (std::basic_streambuf<char, std::char_traits<char> > *) 0;
	OsbIt::ostream_type		*p_ostream	 = (std::basic_ostream<char, std::char_traits<char> > *) 0;
	OsbIt oit0((OsbIt::streambuf_type *)0), oit(ostr);
	*oit0++ = 'x';
	assert(oit0.failed());

	*oit = '1', ++oit;
	*oit++ = '2';
	ostr << std::ends;
	assert(std::strcmp(ostr.str(), "12") == 0);
	assert(!oit.failed());
	ostr.freeze(false);
}


int main ( void ) {
	test_prop();
	test_revit();
	test_inserts();
	test_istreamit();
	test_ostreamit();
	test_istrbufit();
	test_ostrbufit();
	return (0);
}