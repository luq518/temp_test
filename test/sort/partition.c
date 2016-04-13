#include <stdio.h>

dump(int *array,int size)
{
	int i;

	for(i=0;i<size;i++)
	{
		printf("%2d ",array[i]);
	}
	printf("\n");

}

int partition(int *array,int left,int right)
{
	int i,j;
	int key;

	i=left;
	j=right;
	key=array[left];

	while(i<j)
	{
		while(i<j && array[j]>key)
		{
			j--;	
		}
		array[i]=array[j];
		while(i<j && array[i]<key)
		{
			i++;
		}
		array[j]=array[i];

	}
	array[i]=key;
	return i;
}

int main()
{
	int array[]={4,3,2,9,0};
	int retval;

	retval=partition(array,0,4);
	dump(array,5);
	printf("%d \n",retval);
}
