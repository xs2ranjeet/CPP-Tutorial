#include <iostream>
using namespace std;

class Base{
public:
	Base() { cout<<"Base constructor()\n";}
	virtual ~Base() { cout <<"Base Destructor()\n"; }
	static  Base *create(int x);
	virtual void  createAttribute() {cout <<"Base Attribute\n";}
	virtual Base *clone() = 0;
};
class Derived1:public Base{
public:
	Derived1() {cout <<"Derived1 constructor() \n";}
	Derived1(const Derived1& rhs) {cout <<"Derived1 copy constructor() \n";}
	~Derived1() {cout <<"Derived1 Destructor() \n";}
	void createAttribute() { cout<<"Derived1 Attribute\n";}
	Base *clone(){ return new Derived1(this);} 
};
class Derived2:public Base{
public:
	Derived2() {cout <<"Derived2 constructor() \n";}
	Derived2(const Derived2& rhs) {cout <<"Derived2 copy constructor() \n";}
	~Derived2() {cout <<"Derived2 Destructor() \n";}
	void createAttribute() { cout<<"Derived2vAttribute\n";}
	Base *clone(){ return new Derived2(this);} 
};
class Derived3:public Base{
public:
	Derived3() {cout <<"Derived3 constructor() \n";}
	Derived3(const Derived3& rhs) {cout <<"Derived3 copy constructor() \n";}
	~Derived3() {cout <<"Derived3 Destructor() \n";}
	void createAttribute() { cout<<"Derived3 Attribute\n";}
	Base *clone(){ return new Derived3(this);} 
};

class User {
private:
	Base *pBase;
public:
	User():pBase(0)
};
