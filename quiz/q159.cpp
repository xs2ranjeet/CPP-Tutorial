#include <iostream>
int i;
void f(int x){
	std::cout<<x<<i;
}
int main(int argc, char const *argv[])
{
	i = 3;
	f(i++);
	return 0;
}