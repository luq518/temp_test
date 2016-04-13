#include <stdio.h>

void test(int cmd, int temp)
{
	printf("temp[%d] line[%d]\n",temp,__LINE__);
	cmd=4;
	temp=4;
	printf("temp[%d] line[%d]\n",temp,__LINE__);
}

int main()
{
	int cmd,temp;

	cmd=1;
	temp=2;
	printf("temp[%d] line[%d]\n",temp,__LINE__);
	test(cmd,temp);
	printf("temp[%d] line[%d]\n",temp,__LINE__);
}
