#include <iostream>
struct A{
	A() {foo();}
	virtual ~A() { foo();}
	virtual void foo() {std::cout<<"1";}
	void  bar() { foo();}
};
struct  B: public A
{
	virtual void foo() {std::cout<<"2";}
};

int main(int argc, char const *argv[])
{
	B b;
	b.bar();
	return 0;
}