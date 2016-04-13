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
	int key;
	int i,j;

	i=left;
	j=right;

	key = array[left];
	while(i<j)
	{
		while(i<j && key<=array[j])	
		{
			j--;
		}
		array[i]=array[j];
		while(i<j && key>=array[i])
		{
			i++;
		}
		array[j]=array[i];
	}
	printf("%d %d\n",i,j);
	array[i]=key;
	return i;
}

int quick_sort(int *array,int left, int right)
{
	int mid;
	int key;


	if(left<right)
	{
		mid=partition(array,left,right);
		quick_sort(array,left,mid-1);
		quick_sort(array,mid+1,right);
	}

}

int main()
{
	//int array[]={6,4,7,2,1,0,8};
	int array[]={1,2,3,4,5,6,7};

	quick_sort(array,0,7);
	dump(array,7);
}
