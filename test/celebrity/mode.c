#include <stdio.h>
int array[]={2,1,3,2,1,2,3,1,2};
struct node
{
	int number;
	int times;
};

mode()
{
	struct node temp;
	int size = sizeof(array)/sizeof(int);
	int i;
	temp.number=array[0];
	temp.times=1;
	for(i=1;i<size;i++)
	{
		if(array[i]==temp.number)
		{
			temp.times++;
		}
		else 
		{
			if(temp.times>1)
				temp.times--;
			else
			{
				temp.number=array[i];
				temp.times=1;
			}
		}
	}
	printf("%d %d\n",temp.number,temp.times);
	temp.times=0;
	for(i=0;i<size;i++)
	{
		if(array[i]==temp.number)
		{
			temp.times++;
		}
	}
	printf("%d %f\n",temp.number,(float)size/2);
	if(temp.times>size/2)
	{
		printf("%d %d\n",temp.number,temp.times);
	}
	else
		printf("no mode\n");
}

int main()
{

	mode();

}
