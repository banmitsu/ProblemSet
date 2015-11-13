#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

class Bin
{
	friend class Pack;
	private:
		int Blue;
		int Green;
		int Clear;
		int Total;
	public:
		Bin(int numB, int numG, int numC);
		~Bin();
		int getNum(char color);
};
Bin::Bin(int numB, int numG, int numC){
	Blue = numB;
	Green= numG;
	Clear= numC;
	Total= numB+numG+numC;
}
Bin::~Bin() { }
int Bin::getNum(char color)
{
	if( color=='B') return Blue;
	if( color=='G') return Green;
	if( color=='C') return Clear;
	else return -1;
}
class Pack
{
	private:
		std::vector<Bin*> Set;
	public:
		Pack();
		~Pack();
		int Size();
		void Append(Bin* b);
		void Clear();
		int  Work(std::string order);
};
Pack::Pack() {}
Pack::~Pack() {}
int  Pack::Size() {return this->Set.size();}
void Pack::Clear() {this->Set.clear();}
void Pack::Append(Bin* b) {this->Set.push_back(b);}
int  Pack::Work(std::string order)
{
	int move = 0;
	for(int x=0; x<3; x++){
		int value = Set.at(x)->getNum(order[x]);
		move += (Set.at(x)->Total - value);
	}
	return move;
}
int main()
{
	const int num_bin = 3;
	std::vector<int> Move;
	std::vector<int> Min;
	std::vector<std::string> Order;
	Order.push_back(std::string("BCG"));
	Order.push_back(std::string("BGC"));
	Order.push_back(std::string("CBG"));
	Order.push_back(std::string("CGB"));
	Order.push_back(std::string("GBC"));
	Order.push_back(std::string("GCB"));

	std::vector<int>::const_iterator min;
	int B, G, C;
	Pack Recycle;

	while(std::cin >> B >> G >> C){
		Recycle.Append(new Bin(B, G, C));
		if(Recycle.Size()==num_bin){
			int index;
			int value=INT_MAX;
			for(int i=0; i<Order.size(); i++){
				int temp = Recycle.Work(Order.at(i));
				if (temp < value){
					value = temp;
					index = i;
				}
			}
			Move.push_back(index);
			Min.push_back(value);
			Recycle.Clear();
		}

	}
	for(int i=0; i<Move.size(); i++){
		std::cout << Order.at(Move.at(i)) <<" " << Min.at(i) << "\n";
	}
}
