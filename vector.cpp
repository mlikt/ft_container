#include <iostream>
#include <vector>

typedef struct k
{
	int l;
	int l1;
} kk;

int main (void){
	std::vector<int> k;
	// std::cout << k.back();  // Если пустой то segmentation fault
	// k.resize(10);
	k.reserve(8);
	k.resize(1);
	k[0] = 101;
	k[1] = 1;
	k[2] = 1;
	k[3] = 1;
	k[4] = 1;
	k[5] = 1;
	k[6] = 1;
	k[7] = 1;
	k[8] = 1;
	k[9] = 145;
	k[10] = 145;
	k[11] = 145;
	// for(int i = 0; 1; i++)
	// 	 std::cout << k[i];
	k.push_back(44);
	k.push_back(44);
	k.push_back(44);
	k.push_back(44);
	std::cout << k.capacity() << std::endl;
	std::vector<int> r;
	r.resize(10);

	r[0] = 111;
	r[1] = 1;
	r[2] = 1;
	r[3] = 146;
	r[4] = 1;
	r[5] = 1;
	r[6] = 1;
	r[7] = 1;
	r[8] = 1;
	r[9] = 115;

	// int &ll = *((int *) 0);

	// std::cout << ll << std::endl;
	// int &ref = r.at(16); // Бросает исключение

	std::cout << k.size() << std::endl;
	// std::cout << k.front() << std::endl;
	// std::cout << k.back() << std::endl;

	 k.swap(r);
	// std::cout << k[0] << std::endl;
	// std::cout << k[3] << std::endl;
	// std::cout << k[9] << std::endl;

	std::vector<int>::iterator it;
	std::vector<int>::reverse_iterator rit;
	std::vector<int>::const_iterator cit;
	std::vector<int>::const_reverse_iterator crit;

	k.assign(4, 4);

	std::vector<kk*> l;
	// l.insert(l.begin(), &((kk){4, 5}) );

	// l[0]->l;
	return (0);
}