#ifndef __io__
#define __io__

#include <iostream>
#include <atomic>
#include <mutex>
using namespace std;

#endif
//g++ -std=c++11 Singleton.cpp

class Singleton
{
public:
	static Singleton *Instance();
private:
	Singleton() {init();}	
	void init() { cout << "init Done."<<endl;}
	static atomic<Singleton *> pinstance;
	static mutex m_;
};

atomic<Singleton*> Singleton::pinstance {nullptr};
std::mutex Singleton::m_;
Singleton* Singleton::Instance(){
	if(pinstance == nullptr){
		lock_guard<mutex> lock(m_);
		if(pinstance == nullptr){
			pinstance = new Singleton();
		}
	}
	return pinstance;
}
int main(int argc, char const *argv[])
{
	Singleton *sg = Singleton::Instance();
	Singleton *sg2 = Singleton::Instance();
	return 0;
}