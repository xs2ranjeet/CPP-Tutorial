#include <iostream>

struct A {
	virtual std::ostream &put(std::ostream &o) const {
		return o << 'A';
	}
};
struct B : A {
	virtual std::ostream &put(std::ostream &o) const {
		return o << 'B';
	}
};
std::ostream &operator<<(std::ostream &o, const A &a){
	return a.put(o);
}
int main(int argc, char const *argv[])
{
	B b;
	std::cout<<b;
	return 0;
}