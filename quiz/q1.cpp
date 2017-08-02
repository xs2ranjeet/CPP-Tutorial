#include <iostream>
template <class T> void f(T &i) {std::cout<<1;}
template<> void f(const int &i) {std::cout<<2;}

int main(int argc, char const *argv[])
{
	int i = 42;
	f(i);
	return 0;
}