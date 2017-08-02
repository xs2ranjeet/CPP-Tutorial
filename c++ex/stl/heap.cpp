#include <iostream>
#include <algorithm>
using namespace std;

void showHeap(vector<int> v1){
	for ( auto x: v1)
		cout<< x <<" \t";
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	vector<int> v1 = {20,30,40,25,15};
	make_heap(v1.begin(), v1.end());

	cout<<"The max element of heap is : ";
	cout << v1.front() << endl;
	
	showHeap(v1);

	v1.push_back(50);
	push_heap(v1.begin(), v1.end());

	showHeap(v1);

	pop_heap(v1.begin(),  v1.end());
	showHeap(v1);
	sort_heap(v1.begin(),  v1.end());
	showHeap(v1);
	return 0;
}