#ifndef __io__
#define __io__

#include <iostream>
using namespace std;

#endif
#include "CarBuilder.cpp"
int main(int argc, char const *argv[])
{
	cout<<"-------------1\n";
	CarBuilder *lpcBuilder = new LowPriceBuilder();
	cout <<"----------------------2\n";
	MechEngr *egr = new MechEngr(lpcBuilder);
	cout<<"-----------------------3\n";
	egr->buildCar();
	cout<<"-----------------------4\n";
	CarPlane *car = egr->getCar();
	cout<<"----------------------5\n";
	car->getInfo();
	cout<<"---------------------6\n";
	return 0;
}