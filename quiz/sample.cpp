#include <iostream>
using namespace std;

class A {
public:
	A() {cout<<'a';}
	~A(){cout<<'A';}
};
class B:public A{
public:
	B(){cout<<'b';}
	~B(){cout<<'B';}
};
int main()
{
	B b;
}