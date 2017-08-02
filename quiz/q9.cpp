#include <iostream>

int f(int &a, int &b){
	a = 3; b = 4;
	return a+b;
}
int main(int argc, char const *argv[])
{
	int a = 1;
	int b = 2;
	int c = f(a,a);
	std::cout<<a<<b<<c<<std::endl;
	return 0;
}