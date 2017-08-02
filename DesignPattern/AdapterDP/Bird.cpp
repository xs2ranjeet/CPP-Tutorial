#include <iostream>
using namespace std;

class Bird
{
public:
	virtual void fly() = 0;
	virtual void makeSound() = 0;	
};

class Sparrow : public Bird
{
public:
	void fly(){
		cout <<"Flying\n";
	}	
	void makeSound(){
		cout <<"Chirp Chirp\n";
	}
};

class ToyDuck{
public:
	virtual void squeak() = 0;
};
class PlasticToyDuck : public ToyDuck
{
public:
	void squeak(){
		cout <<"squeak"<< endl;
	}	
};
class BirdAdapter: public ToyDuck
{
	Bird *bird;
public:
	BirdAdapter(Bird *bird){
		this->bird = bird;
	}
	void squeak(){
		bird->makeSound();
	}
};

int main(int argc, char const *argv[])
{
	Sparrow *sp = new Sparrow();
	PlasticToyDuck *toyDuck = new PlasticToyDuck();
	ToyDuck *birdAdapter = new BirdAdapter(sp);
	cout << "Sparrow...\n";
	sp->fly();
	sp->makeSound();

	cout << "ToyDuck..."<<endl;
	toyDuck->squeak();

	cout << "BirdAdapter...\n";
	birdAdapter->squeak();
	return 0;
}