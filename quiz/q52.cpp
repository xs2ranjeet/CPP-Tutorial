#include <iostream>
using namespace std;

class B;
class B{
public:
	B() {cout<<'B';}
	friend B A::createB();
};
class A{
public:
	A(){cout<<"A";}
	B createB() { return B();}
};
int main(int argc, char const *argv[])
{
	A a;
	B b = a.createB();
	return 0;
}