#include <iostream>
struct X{
	X() {std::cout<<"X";}
};

int main(int argc, char const *argv[])
{
	//X x(); //Cause no o/p
	X x{};
	return 0;
}