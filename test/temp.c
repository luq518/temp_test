#include <stdio.h>
#define MAX_INDEX	7

void content(int index)
{
	printf("function[%s] line[%d] index=[%d]\n",__FUNCTION__,__LINE__,index);	
}

int test(int index)
{
	int i=index;
	int loop=1;

	if(index==-1)
	{
		loop=MAX_INDEX;
		i=0;
	}

	do{
		content(i);
		i++;
		loop--;
		if(i==5)
		{
			printf("break\n");
			break;
		}
		if(i==2)
		{
			printf("continue\n");
			continue;
		}
		printf("end function\n");
	}while(loop);

#if 0
	if(index==-1)
	{
		for(i=0;i<MAX_INDEX;i++)
			content(i);
		printf("line[%d] index=[%d]\n",__LINE__,index);	
	}
	else
	{
		content(index);
		printf("line[%d] index=[%d]\n",__LINE__,index);	
	}
#endif
}

int main()
{
	int para;
	
	para=-1;
	printf("para:%d \n",para);
	test(para);
	printf("end\n \n");

	para=0;
	printf("para:%d \n",para);
	test(para);
	printf("end\n \n");

	para=3;
	printf("para:%d \n",para);
	test(para);
	printf("end\n");
}
