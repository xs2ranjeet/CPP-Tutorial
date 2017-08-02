#include <iostream>
#include <vector>
int f(){ std::cout<<"f"; return 0;}
int g(){ std::cout<<"g"; return 0;}
void h(std::vector<int> v) {}
int main(int argc, char const *argv[])
{
	h({f(),g()});
	return 0;
}