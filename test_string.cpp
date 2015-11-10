#include <iostream>
#include <cstring>

class A {
	public:
		A();
		virtual void print(){ std::cout << "in A" << std::endl; }
};

A::A(void){
	print();
}

class B : public A{
	public:
		B();
		virtual void print(){ std::cout << "in B" << std::endl; }
};

B::B(void){
	print();
}
int  main()
{
	char vowels[3] = {'A', 'B', '\0'};
	std::cout << vowels <<'\n';
	B b;

	char str[] = "123,4567,89";
	std::cout << str << '\n';

	char *tok1;
	tok1 = strtok(str, ",");
	std::cout << strcat(tok1,strtok(tok1,",")) << "\n";
	std::cout << atoi(tok1)+atoi(strtok(tok1,",")) << "\n";

	std::string str1 = "123";
	std::string str2 = "4567";
	std::cout << str1+str2 << "\n";
	std::cout << stoi(str1)+stoi(str2) << "\n";
}
