#include <stdio.h>

int get_max_min(int *array,int size)
{
	int max,min;
	int i;

	max=array[0];
	min=array[0];
	for(i=1;i<size;i+=2)
	{
		if(array[i]>array[i+1])
		{
			if(max<array[i])
			{
				max=array[i];	
			}
		}
		else if(array[i]<array[i+1])
		{
			if(min>array[i])
			{
				min=array[i];
			}
		}
		else
		{
			if(max<array[i])
			{
				max=array[i];	
			}
			else if(min>array[i])
			{
				min=array[i];
			}
		}
	
	}

	printf("dd %2d %2d i=%d\n",max,min,i);
	if(size%2==0)
	{
		i=size-1;
		if(max<array[i])
		{
			max=array[i];	
		}
		else if(min>array[i])
		{
			min=array[i];
		}
	
	}
	printf("%2d %2d\n",max,min);
}

int main()
{
	int array1[]={0,8,7,9,2};	
	int array2[]={8,7,9,2};	
	int array3[]={8,7,7,2};	
	int array4[]={8,7,7,2,8};	
	int array[]={7,7,7,7};	
	get_max_min(array1,5);
	get_max_min(array2,4);
	get_max_min(array3,4);
	get_max_min(array4,5);
	get_max_min(array,4);
}
