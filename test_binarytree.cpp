#include <cstddef>
#include <iostream>

class Node
{
	friend class BinaryTree;
	private:
		int _value;
		Node *_pLeft;
		Node *_pRight;
	public:
		Node();
		Node(int val);
		int getValue();
		Node* getLeft();
		Node* getRight();

};
Node::Node()
{
	_pLeft = NULL;
	_pRight = NULL;
}
Node::Node(int val)
{
	_pLeft = NULL;
	_pRight = NULL;
	_value = val;
}
int Node::getValue()
{
	return _value;
}
Node* Node::getLeft()
{
	return _pLeft;
}
Node* Node::getRight()
{
	return _pRight;
}

class BinaryTree
{
	private:
		Node *_pRoot;
	public:
		BinaryTree();
		BinaryTree(int val);
		~BinaryTree();
		void Print();
		void TraversePrint(Node* ptr);
		int Count();
		int TraverseCount(Node* ptr);
		void Append(int val);
		void BalancedAppend(Node* ptr, int val);
};
BinaryTree::BinaryTree()
{
	_pRoot = NULL;
}
BinaryTree::BinaryTree(int val)
{
	_pRoot = new Node(val);
}
BinaryTree::~BinaryTree()
{
}
void BinaryTree::Print()
{
	if(_pRoot==NULL){
		std::cout << "This binary tree is empty." << "\n";
		return;
	}
	else{ 
		this->TraversePrint(_pRoot);
		std::cout << "\n";
	}
}
void BinaryTree::Append(int val)
{
	if(_pRoot==NULL){
		_pRoot = new Node(val);
	}
	else{
		BalancedAppend(_pRoot, val);
	}
}
void BinaryTree::BalancedAppend(Node* ptr, int val)
{
	if(ptr->getLeft()==NULL){
		ptr->_pLeft = new Node(val);
		return;
	}
	if(ptr->getRight()==NULL){
		ptr->_pRight = new Node(val);
		return;
	}
	int Lcount = this->TraverseCount(ptr->getLeft());
	int Rcount = this->TraverseCount(ptr->getRight());
	if ( Lcount > Rcount ){
		this->BalancedAppend(ptr->getRight(), val);
	}
	else{
		this->BalancedAppend(ptr->getLeft(), val);
	}
}
void BinaryTree::TraversePrint(Node* ptr)
{
	if(ptr == NULL){
		return;
	}
	else{
		std::cout << ptr->getValue() << " ";
		this->TraversePrint(ptr->getLeft());
		this->TraversePrint(ptr->getRight());
	}
}
int BinaryTree::Count()
{
	int count = 1;
	if(_pRoot==NULL){
		return 0;
	}
	else{
		count += this->TraverseCount(_pRoot->getLeft()); 
		count += this->TraverseCount(_pRoot->getRight());
	}
	return count;
}
int BinaryTree::TraverseCount(Node* ptr)
{
	int count = 1;
	if(ptr==NULL) { return 0; }
	else{
		count += this->TraverseCount(ptr->getLeft());
		count += this->TraverseCount(ptr->getRight());
		return count;
	}
}

int main()
{
	BinaryTree B(1);
	B.Print();
	for(int i=2; i<7; i++){
		B.Append(i);
	}
	std::cout << "total nodes: " << B.Count() << "\n";
	B.Print();
	BinaryTree A;
	A.Append(0);
	A.Print();
	std::cout << "total nodes: " << A.Count() << "\n";


	return 0;
}
