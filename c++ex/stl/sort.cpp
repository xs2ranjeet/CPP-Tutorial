#include <iostream>
#include <algorithm>

using namespace std;
void show(int a[]){
	for(int i = 0; i< 10; i++){
		cout <<'\t'<<a[i];
	}
}

int main(int argc, char const *argv[])
{
	int a[10] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
	cout<< "The Array before soritng\n:";
	show(a);
	sort(a, a+10);
	cout<<"\nAfter sorting:\n";
	show(a);
	if(binary_search(a,a+10, 2))
		cout<<"\nElement found\n";
	else
		cout<<"\nElement not found\n";
	return 0;
}