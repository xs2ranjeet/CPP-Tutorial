#include <iostream>
using namespace std;
enum VehicleType{
	VT_TwoWheeler,  VT_ThreeWheeler, VT_FourWheeler
};

//Library class
class Vehicle {
public:
	virtual void printVehicle() = 0;
	static Vehicle* Create(VehicleType type);
};
class TwoWheeler : public Vehicle {
public:
	void printVehicle(){
		cout<<"I am two TwoWheeler" << endl;
	}
};
class ThreeWheeler : public Vehicle {
public:
	void printVehicle(){
		cout<<"I am ThreeWheeler" << endl;
	}
};
class FourWheeler : public Vehicle {
public:
	void printVehicle(){
		cout<<"I am FourWheeler" << endl;
	}
};

Vehicle* Vehicle::Create(VehicleType type){
	switch(type){
		case VT_TwoWheeler:
			return new TwoWheeler();
		case VT_ThreeWheeler:
			return new ThreeWheeler();
		case VT_FourWheeler:
			return new FourWheeler();
		default:
			return NULL;
	}
	return NULL;
}

// Client class
class Client {
	Vehicle *pVehicle;
public:
	Client(){
		VehicleType type = VT_ThreeWheeler;
		pVehicle = Vehicle::Create(type);
	}
	~Client(){
		if(pVehicle){
			delete pVehicle;
			pVehicle = NULL;
		}
	}
	Vehicle *getVehicle(){
		return pVehicle;
	}
};

int main(){
	Client *pClient = new Client();
	Vehicle *pVehicle = pClient->getVehicle();
	pVehicle->printVehicle();
	return 0;
}