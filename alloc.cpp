#include <iostream>
#include <memory>

int main ( void ) {

	std::allocator<char> alloc;
	std::allocator<int> alloc_int;

	int *ptrint = alloc_int.allocate(1);
	char *ptr = alloc.allocate(17);

	// allocator выделяет памяти больше чем запросим кратно 16-ти
	// 1 - 16 байт , 17 - 32 байта
	// Как и malloc  причина тому... https://en.wikipedia.org/wiki/Data_structure_alignment

	ptrint = NULL;

	std::cout << alloc.max_size() / 8 << std::endl;
	alloc.deallocate(ptr, 17);
	alloc.destroy(ptr);
	ptr = NULL;
	std::cout << &ptr << std::endl;
	int a;
	std::cin >> a;
	return (0);

	return (0);
}