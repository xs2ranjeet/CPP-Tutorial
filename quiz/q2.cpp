#include <iostream>
#include <string>
void f(const std::string &) {std::cout<<1;}
void f(const void *) { std::cout<<2;}
int main(int argc, char const *argv[])
{
	f("foo");
	const char *bar = "bar";
	f(bar);
	return 0;
}