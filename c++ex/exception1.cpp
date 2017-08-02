#include <iostream>
using namespace std;
class Test{
	static int count;
	int id;
public:
	Test(){
		count++;
		id = count;
		cout<<"Constructor object number "<<id<<endl;
		if(id == 4)
			throw 4;
	}
	~Test(){
		cout<<"Destructor object number "<<id<<" called\n";
	}
};
int Test::count = 0;

int main(){
	try{
		throw 'x';
	}
	catch(int x){
		cout<<" Caught int "<< x<<endl;
	}
	catch(...){
		cout << "Default catch block\n";
	}
	try{
		Test t[5];
	}
	catch(int i){
		cout <<"Caught: "<< i<< endl;
	}
}