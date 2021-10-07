#include <iostream>
#include <memory>
#include <vector>

void foo(){
	std::allocator<int> alloc_int;
	int *l1 = alloc_int.allocate(99);
	
	// int *l2 = alloc_int.allocate(99);
	std::auto_ptr<int> 	k(l1); // Умный указатель
	// std::auto_ptr_ref<int> l(k);
	l1[0] = 88;
	l1[2] = 44;
	std::get_temporary_buffer<int>(444);
	std::cout << *((k.get()) + 2) << std::endl;
	std::cout << k.get() << std::endl; // отдать адресс указателя
	k.reset(); //высвободить память
	std::cout << k.release() << std::endl; // отдать адресс указателя и записать свой в ноль

}

int main ( void ) {

	std::allocator<char> alloc;


	std::vector<int> vec;



	// char *ptr = alloc.allocate(17);

	// allocator выделяет памяти больше чем запросим кратно 16-ти
	// 1 - 16 байт , 17 - 32 байта
	// Как и malloc  причина тому... https://en.wikipedia.org/wiki/Data_structure_alignment

	// int i = 0;
	// while (1)
	// 	ptrint[i++] = 4;
	// *ptrint = 4;

	// ptrint = NULL;
	// int k = 1234;

	// ptrint = &k;

	// foo();
	// std::cout << alloc.max_size() / 8 << std::endl;
	// alloc.deallocate(ptr, 1);
	// alloc.destroy(ptr);
	// ptr = NULL;
	// std::cout << &ptr << std::endl;
	// int a;
	// std::cin >> a;
	return (0);

}