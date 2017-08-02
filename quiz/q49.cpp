#include <iostream>

class C{
private:
	int i;
public:
	C(int i): i(i) {std::cout<<i;}
	~C() { std::cout<<i+5;}
 };
 int main(int argc, char const *argv[])
 {
 	const C &c = C(1);
 	C(2);
 	return 0;
 }