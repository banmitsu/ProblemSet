#include <iostream>
#include <math.h>

void process(int digit, int num, char* out);

void recursive_reverse(int in, char* out)
{
	process(1, in, out);
}

void iterative_reverse(int in, char* out)
{
	const static double decimal = 10;

	int i = 1;
	int hold;
	while(1){
		hold = in % (int)pow(decimal,(double)i);
		in = in - hold;
		sprintf(out+i-1, "%d", (int)(hold/pow(decimal, (double)(i-1)))) ;

		double b = floor( (double)in/pow(decimal,(double)i) );
		if (b == 0)
			break;

		i++;
	}
}

void process(int digit, int num, char* out)
{
	const static double decimal = 10;

	int remain = num % (int)pow(decimal,(double)digit);
	sprintf(out+digit-1, "%d", (int)(remain/pow(decimal, (double)(digit-1)))) ;
	
	num = num - remain;
	double b = floor( (double)num/pow(decimal,(double)digit) );
	if (b == 0)
		return;
	else{
		process(digit+1, num, out);
	}	
}

int main()
{
	int x = 35628;
	char* out;

	//reverse(x, out);
	recursive_reverse(x, out);
	std::cout << "The int: " << x << "\n";
	std::cout << "The reverse string: " << out << "\n";
}
