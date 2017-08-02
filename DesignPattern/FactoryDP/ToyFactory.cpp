#ifndef __io__
#define __io__

#include <iostream>
using namespace std;

#endif
#include "Object.cpp"
class ToyFactory
{
public:
	static Toy *createToy(int type){
		Toy *toy = NULL;
		switch(type){
			case 1: { toy = new Car; break;}
			case 2: { toy = new Bike; break;}
			case 3: { toy = new Plane; break;}
			default: return  NULL;
		}
		toy->prepareParts();
		toy->applyLabel();
		return toy;
	}	
};