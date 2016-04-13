#include <stdio.h>



int find(int array[],int size)
{
	int start=0,end=size-1;
	int mid=size/2;

	while(end!=start)
	{
		if(array[start] >= array[mid])
		{
			end=mid;
		}
		else if(array[start] < array[mid])
		{
			start=mid;	
		}
		printf("start %d mid %d end %d\n",start,mid,end);
		
		mid=(end+start)/2;
		
		if(end-start==1)
		{
			
			printf("find %d\n",array[start]>array[end]?array[end]:array[start]);
			return 1;
		}
	}
	return 0;
}

int main()
{
	int int_array[]={5,6,7,8,9,10,1,2,3,4,5};
	int size =sizeof(int_array)/sizeof(int);
	int ret;

	ret = find(int_array,size);
	printf("find:%d\n",ret);
}
