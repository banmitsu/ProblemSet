#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class alphabet
{
	friend class dictionary;
	private:
		char letter;
		int count;
	public:
		alphabet(char& c);
		~alphabet();
		char getLetter();
		int  getCount();
		void addCount();
		bool operator<(const alphabet &rhs) const { return count < rhs.count; }
		bool operator==(const alphabet &rhs) const { return letter == rhs.letter; }
};
alphabet::alphabet(char& c){
	letter = c;
	count = 1;
}
alphabet::~alphabet() {}
char alphabet::getLetter(){ return this->letter; }
int alphabet::getCount(){ return this->count; }
void alphabet::addCount(){ this->count += 1; }

class Dictionary
{
	private:
		std::vector<alphabet> letters;
		std::vector<char> dict_table;
	public:
		Dictionary();
		Dictionary(std::string str);
		~Dictionary();
		void printLetters();
		void printLetters(int i);
		int  findLetter(char& c);
};
Dictionary::Dictionary(std::string str){
	for(int i=0; i<str.size(); i++){
		std::vector<char>::iterator iter = std::find(dict_table.begin(), dict_table.end(), str.at(i));
		if( iter != dict_table.end() ){
			letters.at(std::distance(dict_table.begin(), iter)).addCount();
		}
		else{
			letters.push_back(alphabet(str.at(i)));
			dict_table.push_back(str.at(i));
		}
	}
	std::sort(letters.begin(), letters.end());
}
Dictionary::~Dictionary(){}
int Dictionary::findLetter(char& c)
{
	std::vector<alphabet>::iterator iter = std::find(letters.begin(), letters.end(), alphabet(c));
	return std::distance(letters.begin(), iter);
}
void Dictionary::printLetters(int i){ std::cout << letters.at(i).getLetter(); }
void Dictionary::printLetters()
{
	for(int i=0; i<letters.size(); i++){
		std::cout << letters.at(i).getLetter();
		std::cout << letters.at(i).getCount() << ", ";
	}
	std::cout << "\n";
}

int main()
{
	int num_case;
	std::string encoded;
	std::string plaintext;
	std::cin >> num_case;

	for(int x=0; x<num_case; x++)
	{
		std::cin >> encoded;
		std::cin >> plaintext;
		Dictionary d(encoded);
		Dictionary p(plaintext);
		//d.printLetters();
		//p.printLetters();
		for(int i=0; i<plaintext.size(); i++){
			d.printLetters(p.findLetter(plaintext.at(i)));
		}
		std::cout << "\n";
		if(x+1<num_case)
			std::cout << "\n";
	}
}
