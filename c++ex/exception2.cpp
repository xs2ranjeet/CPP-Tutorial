#include <iostream>
using namespace std;

class Base {};
class Derived:public Base {};
int main(){
	Derived d;
	try {
		throw d;
	}
	catch(Derived d){
		cout << "Caught Derived Exception\n";
	}
	catch(Base b){
		cout<<"Caught Base Exception\n";
	}
	return 0;
}