#include <stdio.h>


dump(int *array)
{
	int i;
	int size=8;

	for(i=0;i<size;i++)
	{
		printf("%2d ",array[i]);
	}
	printf("\n");

}

swap(int *a, int *b)
{
	int temp;

	temp=*a;
	*a=*b;
	*b=temp;
}

heap_sort(int *array,int start,int size)
{
	int child;
	int index=start;


	for(;2*index+1<size;index=child)
	{
		child=index*2+1;
		printf("start: %d nchild %d length %d\n",index, child,size);
		dump(array);
		if(child<size-1&&array[child+1]>array[child])
		{
			child++;
		}
		if(array[index]<array[child])
		{
			swap(array+index,array+child);	
		}
		else
			break;
		dump(array);
	}
}

int sort()
{
	int array[]={8,4,3,2,6,5,9,6};
	int size=sizeof(array)/sizeof(int);
	int i;

	for(i=size/2-1;i>=0;i--)
	{
		heap_sort(array,i,size);
	}

	for(i=size-1;i>0;i--)
	{
		swap(array,array+i);
		
		heap_sort(array,0,i);
	}

	dump(array);


}

int main()
{
	sort();
}
