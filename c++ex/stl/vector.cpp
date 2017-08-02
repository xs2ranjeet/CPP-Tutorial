#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

/*
Iterators
1. begin
2. end
3. rbegin
4. rend
Container:
1. size
2. max_size
3. capacity
4. resi
Accessing the element:
1. ref op: [g]
2. at(g)
3. front()
4. back()
*/
int basic(int argc, char const *argv[])
{
	vector <int>g1 = {1,2,3,4,5};
	vector <int> :: iterator i;
	vector <int> :: reverse_iterator ir;
	g1.push_back(6);
	cout<<"Output:\n";
	for(i = g1.begin(); i != g1.end(); ++i)
		cout<<*i<<"\t";
	cout << endl;
	for(ir = g1.rbegin(); ir != g1.rend();ir++)
		cout<<*ir<<"\t";
	cout << endl;
	cout << "size: "<<g1.size()<<endl;
	cout << "capacity: "<<g1.capacity() <<" Max Size: "<< g1.max_size()<<endl;
	
	cout<<"front: "<<g1.front()<<" back: "<<g1.back() <<" at: "<<g1.at(2)<<endl;	
	return 0;
}
void printVector(string s, vector<int> &v){
	cout <<"Vector("<<s<<"):\n";
	for(int i = 0; i < v.size(); i++)
		cout << v[i]<< "\t";
	cout<<endl;
}
int waystocopy(){
	vector<int> v1{1,2,3,4};
	vector<int> v2;
	printVector("v1", v1);
	//iterative deep copy
	for(int i = 0; i < v1.size(); ++i)
		v2.push_back(v1[i]);
	printVector("v2", v2);

	v2[0] = 2;
	cout<<"v1[0]: "<<v1[0] <<" : v2[0]:" <<v2[0]<<endl;

	//2. using = operator
	vector<int> v3;
	v3 = v1;
	printVector("v3", v3);

	v3[0] = 2;
	cout<<"v1[0]: "<<v1[0] <<" : v3[0]:" <<v3[0]<<endl;


	//3. By passing vector  as constructor
	vector<int> v4(v1);
	printVector("v4", v4);

	v4[0] = 2;
	cout<<"v1[0]: "<<v1[0] <<" : v4[0]:" <<v4[0]<<endl;

	//4. using in built functionse.g. copy(first_itr, last_itr, back_insertor())
	vector<int> v5;
	copy(v1.begin(), v1.end(), back_inserter(v5));
	printVector("v5", v5);

	v5[0] = 2;
	cout<<"v1[0]: "<<v1[0] <<" : v5[0]:" <<v5[0]<<endl;
	//5. assign( first_itr_o, last_itr_o)
	vector<int> v6;
	v6.assign(v1.begin(), v1.end());
	printVector("v6", v6);

	v6[0] = 2;
	cout<<"v1[0]: "<<v1[0] <<" : v6[0]:" <<v6[0]<<endl;
}
int main(int argc, char const *argv[])
{
	waystocopy();
	return 0;
}