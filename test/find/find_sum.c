#include <stdio.h>

dump(float *array, int size)
{
	int i;

	for(i=0;i<size;i++)
	{
		printf("%2f ",array[i]);
	}
	printf("\n");
}

int sort(float *array, int left, int right)
{
	int i,j;
	float key=array[left];
	i=left;
	j=right;

	while(i<j)
	{
		while(i<j && key<array[j])
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

quick_sort(float *array, int left, int right)
{
	int mid;

	if(left<right)
	{
		mid = sort(array,left, right);
		quick_sort(array,left,mid-1);
		quick_sort(array,mid+1,right);
	}
}

int find_sum(float *array, float sum, int size)
{
	float temp_sum;
	int i,j;

	for(i=0,j=size-1;i<j;)
	{
		temp_sum=array[i]+array[j];
		if(temp_sum==sum)
		{
			printf("find it %d %d\n",i,j);
			break;
		}
		else if(temp_sum>sum)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
	if(i=j)
	{
		printf("not found i %d j %d\n",i,j);
	}
}

int main()
{
	float array[]={0.1,0.2,1,4,0.9};
	int sum;
	int size=sizeof(array)/sizeof(int);

	dump(array,size);
	quick_sort(array,0,size-1);
	dump(array,size);
	find_sum(array,8,size);
}
