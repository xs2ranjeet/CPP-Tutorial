#include <iostream>
#include <algorithm>

using namespace std;

void show(string msg, int a[], int asize){
	cout<<msg<<endl;
	for(int i = 0; i < asize; i++)
		cout << '\t' << a[i];
	cout << endl;
}

int main(int argc, char const *argv[])
{
	int a[] = {1,5,8,9,6,7,3,4,2,0};
	int asize = sizeof(a)/sizeof(a[0]);
	show("The array is", a, asize);
	sort(a,  a+10);
	show("The array after sort: ", a, asize);
	if(binary_search(a, a+asize, 2))
		cout<<"2 found\n";
	else
		cout<<"2 not found\n";
	return 0;
}