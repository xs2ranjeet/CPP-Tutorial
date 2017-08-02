#include <iostream>
#include <string>
using namespace std;

class Prototype
{
protected:
	std::string type;
	int value;
public:
	virtual Prototype* clone() = 0;
	std::string getType(){
		return type;
	}
	int getValue(){
		return value;
	}
};

class ConcreatePrototype1 : public Prototype
{
public:
	ConcreatePrototype1(int number){
		type = "Type1";
		value = number;
	}
	~ConcreatePrototype1() {}
	Prototype *clone(){
		return new ConcreatePrototype1(*this);
	}
};

class ConcreatePrototype2 : public Prototype
{
public:
	ConcreatePrototype2(int number){
		type = "Type2";
		value = number;
	}
	~ConcreatePrototype2() {}
	Prototype *clone(){
		return new ConcreatePrototype2(*this);
	}
};

// Factory that manages prototype instances and produces their clones.
class ObjectFactory
{
	static Prototype* type1value1;
	static Prototype* type1value2;
	static Prototype* type2value1;
	static Prototype* type2value2;

public:
	static void initialize(){
		type1value1 = new ConcreatePrototype1(1);
		type1value2 = new ConcreatePrototype1(2);
		type2value1 = new ConcreatePrototype2(1);
		type2value2 = new ConcreatePrototype2(1);
	}
	static Prototype* getType1Value1(){
		return type1value1->clone();
	}
	static Prototype* getType1Value2(){
		return type1value2->clone();
	}
	static Prototype* getType2Value1(){
		return type2value1->clone();
	}
	static Prototype* getType2Value2(){
		return type2value2->clone();
	}
};
Prototype* ObjectFactory::type1value1 = 0;
Prototype* ObjectFactory::type1value2 = 0;
Prototype* ObjectFactory::type2value1 = 0;
Prototype* ObjectFactory::type2value2 = 0;

int main(int argc, char const *argv[])
{
	ObjectFactory::initialize();
	Prototype *object;

	object = ObjectFactory::getType1Value1();
	std::cout<<object->getType() << ": "<<object->getValue()<<std::endl;

	object = ObjectFactory::getType1Value2();
	std::cout<<object->getType() << ": "<<object->getValue()<<std::endl;

	object = ObjectFactory::getType2Value1();
	std::cout<<object->getType() << ": "<<object->getValue()<<std::endl;

	object = ObjectFactory::getType2Value2();
	std::cout<<object->getType() << ": "<<object->getValue()<<std::endl;
	return 0;
}