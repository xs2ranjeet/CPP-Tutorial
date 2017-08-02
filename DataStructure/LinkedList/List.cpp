#include <iostream>
#include <stack>

#include <exception>
#include <string>
using namespace std;

class LinkedList
{
private:
	struct Node{
		int value;
		Node *next;
		Node(int v, Node *n);
		Node(int v);
	};
	Node *head;
	int list_size;
public:
	virtual int size();
	virtual bool isEmpty();
	//virtual int peek();
	virtual void addHead(int value);
	virtual int removeHead();
	virtual void addTail(int value);
	virtual void sortedInsert(int value);
	virtual void reverseList();
	virtual void reverseRecurse();
	virtual void reverseUsingStack();
	Node *reverseRecurseUtil(Node *currentNode, Node *nextNode);
	void free_List();
	bool deleteNode(int v);
	//LinkedList();
	//~LinkedList();
	void print();
};

LinkedList::Node::Node(int v, Node *n){
	value = v;
	next = n;
}
LinkedList::Node::Node(int v){
	value = v;
	next = nullptr;
}
int LinkedList::size(){
	return list_size;
}
bool LinkedList::isEmpty(){
	return list_size == 0;
}
void LinkedList::sortedInsert(int value){
	Node *newNode = new Node(value, nullptr);
	Node *curr = head;
	list_size++;
	if(curr == nullptr || curr->value > value){
		newNode->next = head;
		head = newNode;
		return;
	}
	while(curr->next != nullptr && curr->value < value)
		curr = curr->next;
	newNode->next = curr->next;
	curr->next = newNode;
}
//Insert element at the Head
void LinkedList::addHead(int value){
	head = new Node(value, head);
	list_size++;
}
//Insert element at the end of Linked List
void LinkedList::addTail(int value){
	Node *newNode = new Node(value, nullptr);
	Node *curr = head;
	if(head == nullptr)
		head = newNode;
	while(curr->next != nullptr)
		curr = curr->next;
	curr->next = newNode;
}
void LinkedList::print(){
	Node *temp = head;
	while(temp != nullptr){
		std::cout<<temp->value<<" ";
		temp = temp->next;
	}
	std::cout<<std::endl;
}
int LinkedList::removeHead(){
	if(head == nullptr)
		return -1;
		//throw std::exception("EmptyListException");
	Node *deleteMe = head;
	int value = deleteMe->value;
	head = head->next;
	delete deleteMe;
	return value;
}
bool LinkedList::deleteNode(int delValue){
	Node *temp = head;
	Node *deleteMe;
	if(head == nullptr)
		return false;
	//throw std::exception("EmptyListException");
	if(delValue == head->value){
		deleteMe = head;
		head = head->next;
		list_size--;
		delete deleteMe;
		return true;
	}
	while(temp->next != nullptr){
		if(temp->next->value == delValue){
			deleteMe = temp->next;
			temp->next = deleteMe->next;
			list_size--;
			delete deleteMe;
			return true;
		}
		temp = temp->next;
	}
	return false;
}
void LinkedList::free_List(){
	Node *curr = head;
	Node *next;
	while(curr != nullptr){
		next = curr->next;
		delete curr;
		curr = next;
	}
	head = nullptr;
	list_size = 0;
}
void LinkedList::reverseList(){
	Node *curr = head;
	Node *next = nullptr;
	Node *prev = nullptr;
	while(curr != nullptr){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}
LinkedList::Node *LinkedList::reverseRecurseUtil(Node *currentNode, Node *nextNode){
	Node *ret;
	if(currentNode == nullptr)
		return nullptr;
	if(currentNode->next == nullptr)
	{
		currentNode->next = nextNode;
		return  currentNode;
	}
	ret = reverseRecurseUtil(currentNode->next, currentNode);
	currentNode->next = nextNode;
	return ret;
}
void LinkedList::reverseRecurse(){
	head = reverseRecurseUtil(head, nullptr);
}
void LinkedList::reverseUsingStack(){
	stack<Node *> st;
	Node *curr = head;
	Node *temp;
	while(curr != nullptr){
		temp = curr;
		st.push(temp);
		curr = curr->next;
	}
	while(st.empty() != false){
		temp = st.top();
		if(curr == nullptr)
		{
			curr = temp;
			curr->next = nullptr;
			head = curr;
		}
		else {
			curr->next = temp;
			curr = temp;
			curr->next = nullptr;
		}	
		st.pop();
	}
}
int main(){

	LinkedList ll = LinkedList();
	ll.addHead(1);
	ll.addHead(2);
	ll.addHead(3);
	ll.addTail(4);
	ll.print();
	ll.reverseUsingStack();
	ll.print();
}