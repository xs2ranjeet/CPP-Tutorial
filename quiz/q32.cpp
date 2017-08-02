#include <iostream>
struct X{
	X() {std::cout<<"a";}
	X(const X &x) { std::cout<<"b"; }
	const X &operator=(const X &x) {
		std::cout<<"c";
		return *this;
	}
};
int main(int argc, char const *argv[])
{
	X x;
	X y(x);
	X z = y;
	z = x;
	return 0;
}