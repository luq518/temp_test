#include <stdio.h>

int power(int x, int n)
{
	int odd_even;
	int sum=1;

	if(n==1)
	{
		sum=x;
	}
	
	if(n>1)
	{
		sum=power(x,n/2);	
		if(n%2==1)
		{
			sum=x*sum*sum;	
		}
		else
		{
			sum=sum*sum;	
		}
	}
	return sum;
}

int main()
{
	int val;

	val=power(9,3);
	printf(" %d \n",val);
}
