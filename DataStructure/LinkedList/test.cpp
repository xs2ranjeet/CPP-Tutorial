#include <iostream>
#include <stack>

using namespace std;

int main(){
	stack<int> st;
	st.push(2);
	st.push(3);
	cout<<st.top()<<endl;
	st.pop();
	cout<<st.top()<<endl;
	st.pop();
	//cout<<st.pop()<<endl;
	return 0;
}