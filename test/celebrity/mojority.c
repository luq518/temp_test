#include <stdio.h>

int array[]={5,2,5,3,4,5,1};


int majority()
{
	int node;
	int times;
	int i;

	node=array[0];
	times=1;

	for(i=1;i<sizeof(array)/sizeof(int);i++)
	{
		if(array[i]==node)
		{
			times++;
		}
		else if(array[i]!=node)
		{
			if(times>0)
			{
				times--;
			}
			else
			{
				node=array[i];
				times=1;
			}
		}
	}
	if(times<=0)
	{
		printf("not found\n");
		node = -1;
	}
	else
	{
		times=0;
		for(i=0;i<sizeof(array)/sizeof(int);i++)
		{
			if(array[i]==node)
			{
				times++;
			}
		}
		if(times>sizeof(array)/(sizeof(int)*2))
			printf("found it %d\n",node);
		else
			node=-1;
	}
	return node;
}


int main()
{
	int ret=majority();

	printf("%d \n",ret);

}

