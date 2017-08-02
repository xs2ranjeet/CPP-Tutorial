#ifndef __io__
#define __io__

#include <iostream>
using namespace std;

#endif
class CarPlane
{
public:
	virtual  void setBase(string base) = 0;
	virtual  void setWheel(string wheel) = 0;
	virtual  void setEngine(string engine)= 0;
	virtual  void getInfo() = 0;
};
class Car : public CarPlane{
protected:
	string base;
	string wheel;
	string engine;
public:
	Car(){ cout <<"Car constructor called\n";}
	void setBase(string base){ this->base = base;}
	void setWheel(string w){ this->wheel = w;}
	void setEngine(string e){ this->engine = e;}
	void getInfo(){
		cout <<"getInfo called\n";
		cout << "Car Base: " <<base<<"  Wheel: "<<wheel<<"  Engine: "<<engine<<endl;
	}
};