#include <stdio.h>

int get_max(int *array,int size)
{
	int max_globle;
	int max_temp;
	int i,j=0;
	int x[100];

	max_globle=0;
	max_temp=0;
	for(i=0;i<size;i++)
	{
		max_temp = max_temp+array[i];
		if(max_temp>max_globle)
		{
			x[j++]=i;
			max_globle=max_temp;	
		}
		else if(max_temp<=0)
		{
			j=0;
			max_temp=0;
		}
	}

	printf("%d %d \n",max_temp, max_globle);

	for(i=0;i<j;i++)
	{
		printf("%2d ",x[i]);
	}
	printf("\n");

}

int main()
{

	int array[]={1,2,3,-2,-7,9,2,-1};

	get_max(array,sizeof(array)/sizeof(int));
}
