#include <cstddef>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>

class Box
{
	friend class RobotArm;
	private:
		int _value;
	public:
		Box(int val);
		int getValue();
};
Box::Box(int val){ _value = val; }
int Box::getValue() {return _value;}

class RobotArm
{
	private:
		int num_box;
		std::vector< std::vector<Box*> > table;
		std::vector<Box*> pile;
	public:
		RobotArm(int n);
		~RobotArm();
		bool Check(int varL, int varR);
		void Pop(int pos);
		void Push(int pos, Box* b);
		int Find(int var);
		void Print();
		void Move(int posL, int posR, int varL, int varR);
		void Clean(int pos, int val);
};
RobotArm::RobotArm(int n)
{
	num_box = n; //one for temporary stack
	for(int i=0; i < n; i++)
	{
		std::vector<Box*> pile;
		table.push_back(pile);
		Box* b;
		b = new Box(i);
		table.at(i).push_back(b);
	}
}
RobotArm::~RobotArm() {}
void RobotArm::Pop(int pos)
{
	//std::cout << "pop:" << table.at(pos).back()->getValue() << "\n";
	table.at(pos).pop_back();
}
void RobotArm::Push(int pos, Box* b)
{
	//std::cout << "push: " << b->getValue() << " on " << pos << "\n";
	table.at(pos).push_back(b);
}
int RobotArm::Find(int var){
	for(int i=0; i < this->num_box; i++){
		for(int j=0; j<table.at(i).size(); j++){
			if( table.at(i).at(j)->getValue() == var)
				return i;
		}
	}
	return -1;
}
bool RobotArm::Check(int varL, int varR)
{
	int posL = Find(varL);
	int posR = Find(varR);
	if(posL == posR || posL == -1 || posR == -1 ) //unvalid command
		return false;
	else{
		//std::cout << "find " << varL << ", in " << posL << "\n";
		//std::cout << "find " << varR << ", in " << posR << "\n";
		return true;
	}
}
void RobotArm::Move(int posL, int posR, int varL, int varR)
{
	while(!this->table.at(posL).empty()){
		int value = this->table.at(posL).back()->getValue();
		this->Pop(posL);
		this->pile.push_back(new Box(value));
		if( value==varL ) break;
	}
	while(!this->pile.empty()){
		int value = this->pile.back()->getValue();
		this->pile.pop_back();
		this->table.at(posR).push_back(new Box(value));
	}
}
void RobotArm::Clean(int pos, int val)
{
	while(!table.at(pos).empty()){
		int value = table.at(pos).back()->getValue();
		this->Pop(pos);
		if( value==val ){
			this->Push(pos, new Box(value));
			break;
		}
		else
			this->Push(value, new Box(value));
	}

}
void RobotArm::Print(){
	for(int i=0; i < this->num_box; i++){
		std::cout << i << ":";
		for(int j=0; j<table.at(i).size(); j++)
			std::cout << " " << table.at(i).at(j)->getValue();
		std::cout << "\n";
	}
}

int main()
{
	int num_box;
	int varL, varR;
	std::string  verb, prep;

	std::cin >> num_box;
	RobotArm ra(num_box);
	
	while(std::cin >> verb )
	{
		if( verb == "quit" ) break;
		std::cin >> varL >> prep >> varR;
		if( ra.Check(varL, varR)==false) continue;
		if( verb == "move")
			ra.Clean(ra.Find(varL), varL);			
		if( prep == "onto")
			ra.Clean(ra.Find(varR), varR);
		ra.Move(ra.Find(varL), ra.Find(varR), varL, varR);
	}
	ra.Print();
	return 0;
}
