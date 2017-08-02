#include <iostream>
using namespace std;
namespace first{
	int val = 500;
}
//Global Variable
int val = 100;
namespace ns
{
	class geek{
	public:
		void display(){
			cout <<"ns::geek::display()\n";
		}
	};
}
int main(int argc, char const *argv[])
{
	ns::geek obj;
	obj.display();
	int val = 200;//Local variable
	cout<<first::val<<endl;
	cout<<val<<endl;
	cout<<::val<<endl;
	return 0;
}