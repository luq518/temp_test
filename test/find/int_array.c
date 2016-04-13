#include <stdio.h>


int find(int array[],int size)
{
	int start=0,end=size-1;
	int mid=end/2;

	while(end>=start)
	{
		printf("start %d mid %d end %d\n",start,mid,end);
		if(array[mid] > mid)
		{
			end=mid-1;
		}
		else if(array[mid]<mid)
		{
			start=mid+1;	
		}
		else
		{
			printf("find mid %d value [%d]\n",array[mid],mid);	
			break;
		}
		mid=(end+start)/2;
		printf("start %d mid %d end %d\n",start,mid,end);
	}
	return 0;
}

int main()
{
	int int_array[]={0,0,1,2,3,4,5,6,7};
	int size =sizeof(int_array)/sizeof(int);
	int ret;

	ret = find(int_array,size);
	printf("find:%d\n",ret);
}
