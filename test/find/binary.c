#include <stdio.h>



int find(int des,int array[],int size)
{
	int i;

	i=size/2;
	printf("i=%d size=%d val[%d]\n",i,size,array[i]);
	if(i==0)
	{
		return 0;
	}
	if(des==array[i])
	{
		return 1;
	}

	else if(des<array[i])
	{
		find(des,array,i);
	}
	else
	{
		find(des,&array[i],size-i);
	}

}

int main()
{
	int int_array[]={1,2,4,5,6,7,9,10};
	int size =sizeof(int_array)/sizeof(int);
	int ret;

	ret = find(8,int_array,size);
	printf("find:%d\n",ret);
}
