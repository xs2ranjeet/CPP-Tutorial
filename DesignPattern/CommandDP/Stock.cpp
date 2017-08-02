#include <iostream>
#include <string>
#include <algorithm>
using namespace  std;

class Order{
public:
	virtual void execute() = 0;
};
class Stoke{
private:
	string name;
	int quantity;
public:
	Stoke(string name="ABC", int q = 10):name(name), quantity(q){}
	voi buy(){
		cout<<"Stoke [ Name: "<< name <<", Quantity: "<< quantity <<" ] bought"<< endl;
	}
	void sell(){
		cout<<"Stoke [ Name: "<< name <<", Quantity: "<< quantity <<" ] sold"<< endl;
	}
};
class BuyStock:public Order{
private:
	Stoke *stoke;
public:
	BuyStock(Stoke *s){
		this->stoke = s;
	}
	void execute(){
		stoke->buy();
	}
};
class SellStock:public Order{
private:
	Stoke *stoke;
public:
	SellStock(Stoke *s){
		this->stoke = s;
	}
	void execute(){
		stoke->sell();
	}
};
class Broker{
private:
	std::list<Order *> *orderList = new std::list<Order *>();
public:
	void takeOrder(Order *order){ orderList->push_back(order);}
	void placeOrder(){
		std::list<Order *>::iterator *it = orderList->begin();
		for(it = orderList->begin(); it != orderList->end(); it++){
			it->execute();
		}
		orderList->clear();
	}
};