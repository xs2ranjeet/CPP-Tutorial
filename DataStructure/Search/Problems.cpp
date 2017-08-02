#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

//Time Complexity: O(nlogn)+O(n)=> O(nlogn)
//Space complexity: O(1)
void printDuplicate2(std::vector<int> &data){
	int size = data.size();
	sort(data.begin(),  data.end());  //O(nlogn)
	std::cout<<"Repeating elements are: ";
	//O(n)
	for(int i = 1; i < size; i++)
	{
		if(data[i] == data[i-1])
			std::cout<<" "<<data[i];
	}
	std::cout<<endl;
}
//Using hash table
//Time Complexity: Insert and find in hash is O(1)
//Space Complexity: forhash O(n)
void printDuplicate3(std::vector<int> &data){
	std::unordered_set<int> hs;  // Space: O(n)
	int size = data.size();
	std::cout<<"Repeating elements are: ";
	for(int i = 0; i < size; i++){
		if(std::find(hs.begin(), hs.end(), data[i]) != hs.end())  //O(1)
			std::cout<<" "<<data[i];
		else
			hs.insert(data[i]);   //O(1)
	}
	std::cout<<endl;
}
//If we know range of element than we can find it easily
// Time Complexity: In this insertion and find take O(1) so total complexity O(n)
// Space Complexity: O(n)
void printDuplicate4(std::vector<int> &data){
	int size = data.size();
	std::vector<int> count(size);
	for(int i = 0; i < size; i++)
		count[i] = 0;
	for(int i = 0; i < size; i++){
		if(count[data[i]] == 1)
			std::cout<<" "<< data[i];
		else
			count[data[i]]++;
	}
	std::cout<<endl;
}

/************ Get Max appearinng in Array ***********************/
int getMax2(std::vector<int> &data){
	int size = data.size();
	sort(data.begin(),  data.end());
	int max = data[0],  maxCount = 1;
	int curr = data[0], currCount = 1;

	for(int i = 1; i < size; i++){
		if(data[i] == data[i-1]){
			currCount++;
		}
		else{
			currCount = 1;
			curr = data[i];
		}
		if(currCount > maxCount)
		{
			maxCount = currCount;
			max = curr;
		}
	}
	if(maxCount > 1)
		return max;
	return -1;
}
int main(int argc, char const *argv[])
{
	std::vector<int> v = {12,3,5,2,6,7,12,5,3,21,4,5};
	printDuplicate2(v);
	printDuplicate3(v);
	printDuplicate4(v);
	std::cout<<"Max Find: "<< getMax2(v)<<std::endl;
	return 0;
}