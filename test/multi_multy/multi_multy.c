#include <stdio.h>
int a[11]={2,1,1,1,3,1,1,1,1,1,1};

int cultute()
{
	int i;
	int x=2;
	int n=2;
	int sum=a[n];

	for(i=n;i>0;i--)
	{
		sum=x*sum+a[i-1];	
		printf("all is sum=%d\n",sum);
	}
	printf("all is sum=%d\n",sum);
	return sum;
}

int main()
{
	cultute();
}
