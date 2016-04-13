#include <stdio.h>
#include <string.h>

int main()
{
	int temp=8;
	char bit[100];
	int i=0;

	memset(bit,0x00,sizeof(bit));
	while(temp>0)
	{
		bit[i++]=temp%2+'0';
		temp=temp/2;
	}
	printf("%s\n",bit);

}
