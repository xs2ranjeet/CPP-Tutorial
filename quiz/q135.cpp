#include <iostream>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
	map<bool, int> mb = {{1,2},{3,4},{5,0}};
	cout<<mb.size();
	map<int, int> mi = {{1,2},{3,4},{5,0}};
	cout<<mi.size();
	/*map<int,  int>::iterator i;
	for(i = mi.begin(); i != mi.end(); i++){
		cout<<i->first<<"\t"<<i->second<<endl;
	}*/
	map<bool,  int>::iterator i;
	for(i = mb.begin(); i != mb.end(); i++){
		cout<<i->first<<"\t"<<i->second<<endl;
	}
	return 0;
}