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
		~Node();
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
Node::~Node()
{
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
		void Insert(int val);
		void BinaryInsert(Node* ptr, int val);
		void Search(int val);
		Node* BinarySearch(Node* ptr, int val);
		void Delete(int val);
		void BinaryDelete(Node* ptr, int val);
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
void BinaryTree::TraversePrint(Node* ptr)
{
	if(ptr == NULL){
		return;
	}
	else{
		this->TraversePrint(ptr->getLeft());
		std::cout << ptr->getValue() << " ";
		this->TraversePrint(ptr->getRight());
	}
}
void BinaryTree::Insert(int val)
{
	if(_pRoot==NULL){
		_pRoot = new Node(val);
	}
	else{
		BinaryInsert(_pRoot, val);
	}
}
void BinaryTree::BinaryInsert(Node* ptr, int val)
{
	if(val <= ptr->getValue()){
		if(ptr->_pLeft==NULL) { 
			ptr->_pLeft = new Node(val); 
			return;
		}
		this->BinaryInsert(ptr->getLeft(), val);
	}
	else{
		if(ptr->_pRight==NULL){
			ptr->_pRight = new Node(val);
			return;
		}
		this->BinaryInsert(ptr->getRight(), val);
	}
}
void BinaryTree::Search(int val)
{
	if(_pRoot==NULL){
		std::cout << "this tree is empty" << "\n";
		return;
	}
	else{
		Node* ptr;
		ptr = this->BinarySearch(_pRoot, val);
		if(ptr==NULL){
			std::cout << "find no " << val << "\n";
		}
		else{
			std::cout << ptr->getValue() << "\n";
		}
	}
}
Node* BinaryTree::BinarySearch(Node *ptr, int val)
{
	if(ptr==NULL){
		return NULL;
	}
	if(ptr->getValue()==val){
		return ptr;
	}
	else{
		if(val < ptr->getValue()){
			return this->BinarySearch(ptr->_pLeft, val);
		}
		else{
			return this->BinarySearch(ptr->_pRight, val);
		}
	}
}
void BinaryTree::Delete(int val)
{
	if(_pRoot==NULL){
		std::cout << "this tree is empty" << "\n";
		return;
	}
	else{
		this->BinaryDelete(_pRoot, val);
	}
}
void BinaryTree::BinaryDelete(Node *ptr, int val)
{
	Node* pLeft;
	Node* pRight;
	pLeft = ptr->_pLeft;
	pRight= ptr->_pRight;

	if(val > ptr->getValue() && pRight!=NULL){
	        if(pRight->getValue()==val){
			std::cout << "find " << val << "\n";
			if(pRight->_pLeft==NULL && pRight->_pRight==NULL){
				ptr->_pRight = NULL;
			
			}
		}
		else{
			this->BinaryDelete(pRight, val);
		}
	}
	else if( val <= ptr->getValue() && pLeft!=NULL){
		if(pLeft->getValue()==val){
			std::cout << "find " << val << "\n";
			if(pLeft->_pLeft==NULL && pLeft->_pRight==NULL){
				ptr->_pLeft = NULL;
			}
		}
		else{
			this->BinaryDelete(pLeft, val);
		}
	}
	else{
		std::cout << "find no " << val << "\n";
		return;
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
	BinaryTree A(8);
	A.Insert(1);
	A.Insert(2);
	A.Insert(9);
	A.Print();

	A.Search(8);
	A.Search(7);

	A.Delete(9);
	A.Delete(9);
	A.Delete(2);
	A.Delete(1);
	A.Delete(1);
	A.Print();
	std::cout << "total nodes: " << A.Count() << "\n";


	return 0;
}
