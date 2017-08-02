#include <iostream>
using namespace std;

class Base{
public:
	virtual ~Base()=0;  // This will give error if we don't  have body
};
Base::~Base(){
	cout<<" Pure virtual destructor is called\n";
}
class Derived:public Base {
public:
	~Derived(){
		cout<<"~Derived() is  executed\n";
	}
};

int main(int argc, char const *argv[])
{
	Base *b = new Derived();
	delete b;
	return 0;
} 