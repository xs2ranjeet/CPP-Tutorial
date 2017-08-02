#ifndef __io__
#define __io__

#include <iostream>
using namespace std;

#endif
#include "ToyFactory.cpp"
int main(int argc, char const *argv[])
{
	int type;
	while(1){
		cout <<endl<<"Enter type or zero for exit"<<endl;
		cin >> type;
		if(!type)
			break;
		Toy *v = ToyFactory::createToy(type);
		if(v){
			v->showProduct();
			delete v;
		}
	}
	return 0;
}