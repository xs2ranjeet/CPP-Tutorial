#ifndef __io__
#define __io__

#include <iostream>
using namespace std;

#endif

class Toy{
protected: 
	string name;
	float price;
public:
	virtual void prepareParts() =0;
	virtual void applyLabel() = 0;
	virtual void showProduct() = 0;
};

class Car : public Toy{
	//make all constructor private or protected
public:
	void prepareParts() { cout << "Preparing car parts"<<endl;}
	void applyLabel() { cout << "Applying label: Car Toy"<<endl; name = "Car"; price=10.0;}
	void showProduct() { cout << "Name: "<<name<<" Price: "<< price<<endl;}

};
class Bike : public Toy{
	//make all constructor private or protected
public:
	void prepareParts() { cout << "Preparing Bike parts"<<endl;}
	void applyLabel() { cout << "Applying label: Bike Toy"<<endl; name = "Bike"; price=20.0;}
	void showProduct() { cout << "Name: "<<name<<" Price: "<< price<<endl;}

};
class Plane : public Toy{
	//make all constructor private or protected
public:
	void prepareParts() { cout << "Preparing Plane parts"<<endl;}
	void applyLabel() { cout << "Applying label: Plane Toy"<<endl; name = "Plane"; price=30.0;}
	void showProduct() { cout << "Name: "<<name<<" Price: "<< price<<endl;}

};