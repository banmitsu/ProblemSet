#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string ciphertext;
	std::vector<std::string> plaintext;

	while(std::cin >> ciphertext)
	{
		for( int x=0; x<ciphertext.size(); x++)
			ciphertext.at(x) = (ciphertext.at(x)-7);//%128 do not mod
		plaintext.push_back(ciphertext);
	}
	for( int x=0; x<plaintext.size(); x++)
		std::cout << plaintext.at(x) << "\n";
	return 0;
}
