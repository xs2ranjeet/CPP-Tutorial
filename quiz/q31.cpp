#include <iostream>
struct X{
	X() {std::cout<<"X";}
};
struct Y{ 
	Y(const X &x){ std::cout<<"Y";}
	void f() {std::cout<<"f";}
} ;
int main(int argc, char const *argv[])
{
	Y y(X()); Error cause in y.f()
	//Y y((X())); OK
	//Y y{X{}}; ok
	y.f();
	return 0;
}