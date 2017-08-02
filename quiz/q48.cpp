#include <iostream>
#include <string>
#include <future>
//g++ -std=c++14 q48.cpp -lpthread
int main(){
	std::string x = "x";
	std::async(std::launch::async,[&x]() {
		x = "y";
	});
	std::async(std::launch::async,[&x]() {
		x = "z";
	});
	std::cout<<x<<std::endl;
}