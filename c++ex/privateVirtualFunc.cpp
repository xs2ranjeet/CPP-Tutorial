#include <iostream>

using namespace std;
class B {
private:
	virtual void fun() { cout<<"Base::fun()\n";}
public:
	friend int main();
};
class D : public B{
	void  fun(){ cout<<"Derived::fun()\n";}
};

int main(){
	B *b = new D;
	b->fun();
	return 0;
}