#include <iostream>
using namespace std;
class Pet
{
public:
	virtual void petSound() = 0;
};
class Dog : public Pet {
public:
	void petSound(){
		cout << "Bow Bow\n";
	}
};
class Cat : public Pet {
public:
	void petSound(){
		cout << "Meow Meow\n";
	}
};
class PetFactory
{
public:
	PetFactory() {}
	Pet *getPet(int type){
		switch(type){
			case 1: return new Dog();
			case 2: return new Cat();
			default: return NULL;
		}
	}
	~PetFactory(){}
};

int main(int argc, char const *argv[])
{
	/* code */
	PetFactory *p = new PetFactory();
	Pet *dog = p->getPet(1);
	Pet *cat = p->getPet(2);
	dog->petSound();
	cat->petSound();
	delete dog;
	delete cat;
	delete p;

	return 0;
}