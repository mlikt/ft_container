#include <iostream>
#include "vector.hpp"


class B
{
	public:
		char *l;
		int i;
		
		B():l(nullptr), i(1) {};
		B(const int &ex) { 
			this->i = ex; 
			this->l = new char('a'); 
		};
		
		virtual ~B() {
			delete this->l;
			this->l = nullptr;
		};
};

class A : public B
{		
	public:
		A():B(){
		};

		A(const B* ex){
			this->l = new char(*(ex->l));
			this->i = ex->i;
			if (ex->i == -1)
			{
				throw "Nooo!!\n";
			}
		};

		~A(){
			delete this->l;
			this->l = nullptr;
		};
};


void foo(){

	std::auto_ptr<B> k(new B(1));
	std::auto_ptr<B> k1(new B(2));
	std::auto_ptr<B> k2(new B(3));
	std::auto_ptr<B> k3(new B(4));
	std::auto_ptr<B> k4(new B(-1));
	
	ft::vector<A> v;
	ft::vector<B*> v1;

	v1.push_back(&(*k));
	v1.push_back(&(*k1));
	v1.push_back(&(*k2));
	v1.push_back(&(*k3));
	v1.push_back(&(*k4));
	v1.push_back(&(*k));

	 try {
	 	v.insert(v.begin(), v1.begin(), v1.end());
	 }
	 catch (const char *msg) {
	 	std::cerr << msg << std::endl;
	 }
}

int main (void) {
	
	foo();
	return (0);
}