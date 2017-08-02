#include <iostream>
#include <vector>
int main(int argc, char const *argv[])
{
	std::vector<int> v1(1,2);
	std::vector<int> v2{1,2};
	std::cout<<v1.size()<<v2.size();
	return 0;
}