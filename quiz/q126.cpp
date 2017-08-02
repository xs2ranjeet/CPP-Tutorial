#include <iostream>
int foo() { return 10;}
struct foobar{
	static int x;
	static int foo(){
		return 11;
	}
};
int foobar::x = foo();
int main(int argc, char const *argv[])
{
	std::cout<<foobar::x;
	return 0;
}