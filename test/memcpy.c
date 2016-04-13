#include <stdio.h>

int main()
{
	char str[10]="123456789";

	memcpy(str+3,"luqi",4);
	printf("str[%s]\n",str);
}
