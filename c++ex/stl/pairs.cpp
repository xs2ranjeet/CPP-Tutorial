#include <iostream>
#include <utility>

using namespace std;
/*
We can also initialize a pair.
Syntax :

pair (data_type1, data_type2) Pair_name (value1, value2) ;
Different ways to initialize pair:

pair  g1;         //default
pair  g2(1, 'a');  //initialized,  different data type
pair  g3(1, 10);   //initialized,  same data type
pair  g4(g3);    //copy of g3
Another way to initialize a pair is by using the make_pair() function.

g2 = make_pair(1, 'a');
*/
int main(int argc, char const *argv[])
{
	pair <int, char> p1;
	p1.first = 10;
	p1.second = 'R';
	cout<<"Pair: "<<p1.first<<" : "<<p1.second<<endl;
	
	pair <string, double> p2 ("harekrishna", 1.23), p3;
	cout<<"Pair2: "<<p2.first<<" : "<<p2.second<<endl;
	p3 = make_pair("ranjeet", 12.12);
	cout<<"Pair3: "<<p3.first<<" : "<<p3.second<<endl;
	p2.swap(p3);
	cout<<"Pair2: "<<p2.first<<" : "<<p2.second<<endl;
	cout<<"Pair3: "<<p3.first<<" : "<<p3.second<<endl;
	pair <int, int> p4 = make_pair(1,12);
	pair <int, int> p5 = make_pair(9,12);
	
	cout<< (p4 == p5) << endl;
	cout<< (p4 != p5) << endl;
	cout<< (p4 >= p5) << endl;
	cout<< (p4 <= p5) << endl;
	cout<< (p4 > p5) << endl;
	cout<< (p4 < p5) << endl;
	return 0;
}