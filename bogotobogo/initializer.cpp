#include <iostream>
using namespace std;

//Uniform Initialization

int initArray()
{
	//Initialization of dynamically allocated arrays:
	int *pi = new int[5] {1,2,3,4,5};
	for(int i = 0;  i < 5; ++i){
		cout << pi[i] <<"\t";
	}
	cout<<endl;
	return 0;
}
//2.Initialization of an array member variable:
class A {
	int arr[3];
public:
	A(int x,int y, int z): arr{x,y,z} {};
};