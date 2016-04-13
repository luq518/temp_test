#include <stdio.h>

int gcd(int a, int b)
{
	int i=a;
	int j=b;
	int temp;

	if(i>j)
	{
		j=i^j;
		i=i^j;
		j=i^j;
	}

	while(i!=0)
	{
		printf("befor %d %d\n",i,j);
		temp=j%i;
		j=i;
		i=temp;
		printf("after %d %d\n",i,j);
	}
	return j;
}

int main()
{
	int ret_val;

	ret_val=gcd(66,38);
	printf("%d\n",ret_val);
}
