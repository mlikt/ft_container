#include <iostream>
#include <vector>
#include <type_traits>

template<bool B, class T = void>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> { typedef T type; };

namespace sp {
	template <typename T >
	void f(const T&, const typename enable_if<std::is_class<T>::value, T>::type * = nullptr) {
		std::cout << 1 << std::endl;
	}
	template <typename T >
	void f(const T&, const typename enable_if<std::is_integral<T>::value, T>::type * = nullptr) {
		std::cout << 2 << std::endl;
	}


}

template <typename L>
void f(const L& exmpl ) {
	sp::f(exmpl, &exmpl);
}

void f()
{
	std::cout << "f()" << std::endl;
}

int main ( void ) {
	int b;

	std::vector<int> l;
	f(b);
	f(l);
	f();

}