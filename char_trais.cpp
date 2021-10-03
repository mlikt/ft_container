#include <string>
#include <iostream>
// Кратко об объектах std::char_traits<class T>
int main ( void ){

	std::char_traits<int> cht0;

	std::char_traits<int>::off_type l;

	int Int[5] = {1, 2, 3, 4, 5};
	int Int1[5] = {11, 22, 33, 44, 55};
	cht0.copy(Int, Int1, 5);
	std::cout << cht0.eq(4 , 4) << std::endl;
	
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << Int[i] << " " ;
	}
	std::cout << std::endl;

	std::char_traits<char> cht1;

	char Char[5] = {'a', 'b', 'c', 'd', 'e'};
	char Char1[5] = {'f', 'g', 'h', 'l', 'm'};
	char *ptr = cht1.copy(Char, Char1, 5);

	*ptr = 'A';

	std::cout << cht1.eq('k' , '[') << std::endl;
	
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << Char[i] << " " ;
	}
	std::cout << std::endl;

	return (0);
}