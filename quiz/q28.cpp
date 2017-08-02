#include <iostream>
struct A{
	A() {std::cout<<"A";}
	A(const A &a) {std::cout<<"B";}
	virtual void f() {std::cout<<"C";}

};

int main(int argc, char const *argv[])
{
	A a[2];
	for(auto x : a)
		x.f();
	return 0;
}