#include <iostream>
using namespace std;

class B
{
public:
	virtual void fun(){}
};

class D: public B {};
int main(){
	B *b = new D;
	D *d = dynamic_cast<D *>(b);
	if(d != NULL)
		cout << "works\n";
	else
		cout << "Not Working\n";
	return 0;
}