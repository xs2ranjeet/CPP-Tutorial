#include <iostream>
#include <queue>
using namespace std;
/*
	1. empty
	2. size()
	3. push(g)
	4. pop()
*/
void showpq(priority_queue<int> gq){
	priority_queue<int> g = gq;
	while(!g.empty()){
		cout<<"\t"<<g.top();
		g.pop();
	}
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	priority_queue<int> pq;
	pq.push(10);
	pq.push(30);
	pq.push(20);
	pq.push(5);
	pq.push(1);
	cout<<"The PQ Size: "<< pq.size()<<endl;
	showpq(pq);
	cout<<"Top PQ: "<<pq.top()<<endl;
	cout<<"Pop: ";
	pq.pop();
	showpq(pq);
	return 0;
}