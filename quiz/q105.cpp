#include <iostream>
using namespace std;
class A{
public:
	A() {cout<<"a";}
	~A() {cout<<"A";}
};
int i = 1;
int main(int argc, char const *argv[])
{
	label:
	A a;
	if(i--)
		goto label;
	return 0;
}