#include <cstddef>
#include <iostream>

class Node
{
	friend class LinkedList;
	private:
		int _value;
		Node *_pNext;
	public:
		Node();
		Node(int val);
		Node(int val, Node* next);
		int getValue();
		Node* getNext();

};
Node::Node(){
	_pNext = NULL;
}
Node::Node(int val){
	_value = val;
	_pNext = NULL;
}
Node::Node(int val, Node* next){
	_value = val;
	_pNext = next;
}
int Node::getValue(){
	return _value;
}
Node* Node::getNext(){
	return _pNext;
}

class LinkedList
{
	private:
		Node *_pHead;
		Node *_pTail;
	public:
		LinkedList(int val);
		~LinkedList();
		void Print();
		void Append(int val);
		void Reverse();
		void ReversePrint(Node *ptr);
		void ActuralReverse();
};
LinkedList::LinkedList(int val)
{
	_pHead = new Node(val);
	_pTail = _pHead;
}
LinkedList::~LinkedList()
{
}

void LinkedList::Print()
{
	Node *ptr = _pHead;
	if(ptr == NULL) {
		std::cout << "This list is empty" << "\n";
	}
	else{
		while(ptr != NULL){
			std::cout << ptr->getValue() <<" ";
			ptr = ptr->_pNext;
		}
		std::cout << "\n";
	}
	return;
}

void LinkedList::Append(int val)
{
	if(_pHead == NULL) {
		_pHead = new Node(val);
		_pTail = _pHead;
	}
	else{
		_pTail->_pNext = new Node(val);
		_pTail = _pTail->_pNext;
	}
}

void LinkedList::Reverse(){
	this->ReversePrint(_pHead);
	std::cout << "\n";
}
void LinkedList::ReversePrint(Node *ptr)
{
	if (ptr->getNext() == NULL){ 
		std::cout << ptr->getValue() << " ";
		return;
	}
	else {
		this->ReversePrint( ptr->getNext() );
		std::cout << ptr->getValue() << " ";
		return;
	}
}

void LinkedList::ActuralReverse(){
	if (_pHead == NULL)
		return;

	Node *prev = NULL;
	Node *next = _pHead;
	Node *curr = NULL;
	while(next){
		curr = next->getNext();
		next->_pNext = prev;
		prev = next;
		next = curr;
	}

	curr = _pTail;
	_pTail = _pHead;
	_pHead = curr;
}

int main()
{
	LinkedList list(1);
	for(int x = 2; x < 6; x++){
		list.Append(x);
	}
	list.Print();
	list.Reverse();
	list.ActuralReverse();
	list.Print();
	list.Reverse();
	return 0;
}
