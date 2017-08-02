#ifndef __io__
#define __io__

#include <iostream>
using namespace std;

#endif
#include "CarPlane.cpp"
class CarBuilder
{
	//CarPlane *car;
public:
	virtual void buildBase() = 0;
	virtual void buildEngine() = 0;
	virtual void buildWheel() = 0;
	virtual CarPlane *getCar() = 0;
};

class LowPriceBuilder : public CarBuilder{
protected:
	CarPlane *car;
public:
	LowPriceBuilder(){
		car = new Car();
	}
	void buildBase(){
		car->setBase("Low price Base");
	}
	void buildWheel(){
		car->setWheel("Cheap Wheel");
	}
	void buildEngine(){
		car->setEngine("Low Quality Engine");
	}
	CarPlane *getCar(){
		return this->car;
	}
};

class HighPriceBuilder : public CarBuilder{
protected:
	CarPlane *car;
public:
	HighPriceBuilder(){
		car = new Car();
	}
	void buildBase(){
		car->setBase("High price Base");
	}
	void buildWheel(){
		car->setWheel("Quality Wheel");
	}
	void buildEngine(){
		car->setEngine("High Quality Engine");
	}
	CarPlane *getCar(){
		return this->car;
	}
};

class MechEngr{
protected:
	CarBuilder *cb;
public:
	MechEngr(CarBuilder *cb){
		this->cb = cb;
	}
	CarPlane *getCar(){
		return cb->getCar();
	}
	void buildCar(){
		cb->buildBase();
		cb->buildEngine();
		cb->buildWheel();	
	}
};