#include <iostream>
volatile int a;
int main(int argc, char const *argv[])
{
	std::cout<<(a+a);
	return 0;
}