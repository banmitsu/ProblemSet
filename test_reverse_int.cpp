#include <iostream>
#include <math.h>

void reverse(int in, char* out)
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

int main()
{
	int x = 35628;
	char* out;

	reverse(x, out);
	std::cout << "The int: " << x << "\n";
	std::cout << "The reverse string: " << out << "\n";
}
