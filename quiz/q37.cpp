#include <iostream>
int main(int argc, char const *argv[])
{
	int a = 0;
	decltype(a) b = a;
	b++;
	std::cout<<a<<b<<std::endl;
	return 0;
}