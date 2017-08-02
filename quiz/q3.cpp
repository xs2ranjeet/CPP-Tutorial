#include <iostream>

void f(int) { std::cout<<1;}
void f(unsigned ){std::cout<<2;}

int main(int argc, char const *argv[])
{
	f(-2.5);
	return 0;
}