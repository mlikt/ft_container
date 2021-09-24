
#include <algorithm>

namespace ft {

	template <class T, class U>
		struct pair
		{
			typedef T first_type;
			typedef U second_type;
			
			T first;
			U second;
			
			pair(): first(), second() {}

			pair(const T& x, const U& y)
			:first(x), second(y)
			{}
			
			template<class V, class W>
				pair(const pair<V, W>& pr)
				: first(pr.first), second(pr.second)
				{}

			void
			swap( pair<T, U>& pr )
			{
				std::swap(second, pr.second);
				std::swap(first, pr.first);
			}
		};
		
	template <class T, class U>
	pair<T, U>
	make_pair(T x, U y)
	{
		return pair<T, U>(x, y);
	}


	template <class T, class U>
		bool operator==(const pair<T, U>& x,
			const pair<T, U>& y){
				return x.first == y.first && x.second == y.second ;
			}

	template <class T, class U>
		bool operator != (const pair<T, U>& x,
			const pair<T, U>& y){
				return !(x == y);
			}

	template <class T, class U>
		bool operator < (const pair<T, U>& x,
			const pair<T, U>& y) {
				return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
			}

	template <class T, class U>
		bool operator > (const pair<T, U>& x,
			const pair<T, U>& y) {
				return y < x;
			}

	template <class T, class U>
		bool operator <= (const pair<T, U>& x,
			const pair<T, U>& y) {
				return !(y < x);
			}

	template <class T, class U>
		bool operator >= (const pair<T, U>& x,
			const pair<T, U>& y) {
				return !(x < y);
			}
	//Нужно ли описывать сравние для произвольного типа? (Когда определенный операторы == и <)
};