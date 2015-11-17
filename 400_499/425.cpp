#include <iostream>
#include <unistd.h> //xos
//#include <crypt.h>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>

bool less_comp(const std::string str1, const std::string str2)
{
	if(str1 > str2)
		return false;
	if(str1 < str2)
		return true;
	return false;
}
bool equal_comp(const std::string str1, const std::string str2)
{
	if(str1 == str2)
		return true;
	return false;
}

int main()
{
	std::string cyphertext;
	std::string input;
	char text[100];
	char parsed_l[100];
	char parsed_r[100];
	std::vector<std::string>::iterator it;

	std::cin >> cyphertext;
	std::vector<std::string> Vocabulary;
	std::vector<std::string> Digit;
	Digit.push_back(std::string("0"));
	Digit.push_back(std::string("2"));
	Digit.push_back(std::string("4"));
	Digit.push_back(std::string("8"));

	while(std::cin >> input)
	{
		text[0] = '-'; //tricky
		for (int x=0; x<input.size(); x++)
			text[x+1] = input.at(x);
		text[input.size()+1] = '\0';
		sscanf(text, "%*[^A-Za-z]%[A-Za-z]%*[^A-Za-z]%[A-Za-z]", parsed_l, parsed_r);

		if (parsed_l[0] != '\0' && strlen(parsed_l)<7 && strlen(parsed_l)>1 ){
			std::string data(parsed_l);
			std::transform(data.begin(), data.end(), data.begin(), ::tolower);
			Vocabulary.push_back(std::string(data));
		}
		if (parsed_r[0] != '\0' && strlen(parsed_r)<7 && strlen(parsed_r)>1 ){
			std::string data(parsed_r);
			std::transform(data.begin(), data.end(), data.begin(), ::tolower);
			Vocabulary.push_back(std::string(data));
		}
		memset(parsed_l, 0, sizeof(parsed_l));
		memset(parsed_r, 0, sizeof(parsed_r));
	}
	//remove the duplicate words.
	std::sort(Vocabulary.begin(), Vocabulary.end(), less_comp);
	it = std::unique(Vocabulary.begin(), Vocabulary.end(), equal_comp);
	Vocabulary.resize( std::distance(Vocabulary.begin(), it) );

	/*for (int x=0; x<Vocabulary.size(); x++){
		std::cout << Vocabulary.at(x) << " ";
	}
	std::cout << "\n";*/

	char salt[3];
	for(int i=0; i<2; i++)
		salt[i] = cyphertext.at(i);
	salt[2] = '\0';

	char passwd[9];

	for(int x=0; x<Vocabulary.size(); x++)
	{
		for(int y=0; y<Vocabulary.size(); y++)
		{
			for (int num=0; num<4; num++)
			{
				strcpy(passwd, Vocabulary.at(x).c_str());
				strcat(passwd, Digit.at(num).c_str());
				strcat(passwd, Vocabulary.at(y).c_str());
				if( strcmp( crypt(passwd, salt), cyphertext.c_str())==0 )
				{
					std::cout << passwd << "\n";
					return 0;
				}
			}
		}
	}
	return 0;
}
