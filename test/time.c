#include <stdio.h>

int main()
{
	int time=0x7FFFFFFF;

	int year=time/(365*24*60*60);
	printf("year[%d]\n",year);
	year=time%(365*24*60*60);
	int day=year/(24*60*60);


	printf("day[%d]\n",day);
}
