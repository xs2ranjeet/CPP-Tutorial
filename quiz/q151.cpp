#include <iostream>
#include <type_traits>

int main(int argc, char const *argv[])
{
	std::cout<<std::is_signed<char>::value<<std::endl;
	return 0;
}