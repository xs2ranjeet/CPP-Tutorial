
#include <iostream>
#include <map>
#include <iterator>

using namespace std;

void showMultiMap(string str, multimap<int, int> gq){
	cout<<str<<endl;
	multimap<int, int>::iterator itr;
	for(itr = gq.begin(); itr != gq.end(); itr++){
		cout<< '\t'<< itr->first <<'\t'<<itr->second<<endl;
	}
}
int main(int argc, char const *argv[])
{
	multimap <int, int> gq;
	gq.insert(pair<int,int> (1,40));
	gq.insert(pair<int,int> (2,30));
	gq.insert(pair<int,int> (3,60));
	gq.insert(pair<int,int> (4,20));
	gq.insert(pair<int,int> (5,50));
	gq.insert(pair<int,int> (6,50));
	gq.insert(pair<int,int> (6,10));

	showMultiMap("gq data: ",  gq);
	multimap<int, int>gq2(gq.begin(), gq.end());
	showMultiMap("gq2 data", gq2);

	gq2.erase(gq2.begin(), gq2.find(3));
	showMultiMap("gq2 after removal of elements less than key=3: ", gq2);
	gq2.erase(4);
	showMultiMap("gq2 erase(4): ", gq2);
	return 0;
}