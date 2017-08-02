#include <iostream>
#include <vector>
using namespace std;

bool BinarySearch(std::vector<int> &data, int value){
	int size = data.size();
	int low = 0;
	int high = size-1;
	int mid = low + (high-low)/2;
	while(low  <= high){
		mid = low + (high-low)/2 ;
		if(data[mid] == value)
			return true;
		else if(data[mid] < value){
			high = mid-1;
		}
		else
			low = mid+1;
	}
	return false;
}
bool BinarySearchRec(std::vector<int> &data, int value, int low,  int high){
	if(low > high)
		return false;
	int mid = low + (high-low)/2;
	if(low <= high){
		if(data[mid] == value)
			return true;
		else if(data[mid] < value)
			BinarySearchRec(data, value, low,  mid-1);
		else
			BinarySearchRec(data,  value, mid+1,  high);
	}

}

int main(int argc, char const *argv[])
{
	std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
	std::cout<<"Element 5 is "<<BinarySearch(v, 5)<<endl;
	std::cout<<"Element 15 is "<<BinarySearch(v, 15)<<endl;
	std::cout<<"Element 5 is "<<BinarySearchRec(v, 5, 0, v.size()-1)<<endl;
	std::cout<<"Element 15 is "<<BinarySearchRec(v, 15, 0, v.size()-1)<<endl;
	return 0;
}