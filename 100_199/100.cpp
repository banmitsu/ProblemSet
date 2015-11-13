#include <stdio.h>
#include <iostream>
#include <climits>

int process(int x)
{
	int count = 1;
	while(x!=1){
		if(x % 2 != 0)
			x = 3*x+1;
		else
			x = x/2;
		count++;
	}
	return count;
}

int main()
{
	int min, max, tmp;

	while(scanf("%d %d", &min, &max)==2)
	{
	    int current_max = INT_MIN;
	    if( min > 0 || max > 0) {
		std::cout << min << " " << max << " ";
		if( min > max ){
			tmp = max;
			max = min;
			min = tmp;	
		}
		for(int x=min; x<=max; x++)
		{
			tmp = process(x);
			if (tmp > current_max)
				current_max = tmp;
		}
		std::cout << current_max << "\n";
	    }
	}
}
