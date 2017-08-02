#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;


void showpq(priority_queue<int, vector<int>, greater<int> > pq){
	priority_queue<int, vector<int>, greater<int> > p = pq;
	while(p.empty() == false){
		cout<<p.top()<<"\t";
		p.pop();
	}
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	priority_queue<int, vector<int>, greater<int> > pq;
	pq.push(5);
	pq.push(1);
	pq.push(10);
	pq.push(20);
	pq.push(30);
	pq.push(40);
	showpq(pq);
	return 0;
}