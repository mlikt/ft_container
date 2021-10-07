// Как определить какую категрию итераторов использует контейнер
#include <iostream>
#include <iterator>
#include <vector>
#include <set>
#include <list>
#include <typeinfo>
#include <map>
#include "iterator2.hpp"

using namespace std;

template< class it >
void
which_tag( it i1, it i2 )
{
   typename ft::iterator_traits<it>::iterator_category cat;
   typename ft::iterator_traits<it>::pointer p;
   typename ft::iterator_traits<it>::reference r = *i1;
   typename ft::iterator_traits<it>::value_type type;
   typename ft::iterator_traits<it>::difference_type dif;


   cout << typeid( cat ).name( ) << endl;
   cout << typeid( p ).name( ) << endl;
   cout << typeid( r ).name( ) << endl;
   cout << typeid( type ).name( ) << endl;
   cout << typeid( dif ).name( ) << endl;
}



int main( void )
{
   std::vector<char> vc( 10,'a' );
   std::list<int>    li( 10 );
   std::set<int>     set;
   std::map<int, char> map;

   set.insert(3);
   set.insert(8);
   set.insert(7);
   set.insert(4);
   set.insert(9);
   set.insert(0);

   map.insert(map.begin(), std::make_pair(*set.begin(), 'a'));

	which_tag( vc.begin( ), vc.end( ) );
	which_tag( li.begin( ), li.end( ) );
	which_tag( set.begin( ), set.end( ) );
	which_tag( map.begin( ), map.end( ) );

   return (0);
}