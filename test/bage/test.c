#include <stdio.h>
#include <string.h>

#define MAX	4	
int v[]={0,4,5,6};
int m[]={0,3,4,5};
int total=15;
int mv[MAX][25];


int create_array()
{

	int i,j;

	memset(mv,0x00,sizeof(mv));
	dump();

	for(i=1;i<MAX;i++)
	{
		for(j=1;j<=total;j++)
		{
			printf("j[%d] v[%d]=[%d]\n",j,i,v[i]);
			if(j-m[i]>=0)
			{
				mv[i][j]=mv[i-1][j]>mv[i-1][j-m[i]]+v[i]?mv[i-1][j]:mv[i-1][j-m[i]]+v[i];
				printf("[%d] [%d] mv[%d][%d]=[%d]\n",mv[i-1][j],mv[i-1][j-m[i]]+v[i],i,j,mv[i][j]);
			}
			else
			{
				mv[i][j]=mv[i-1][j];
				printf("mv[%d][%d]=%d\n",i,j,mv[i][j]);
			}
		}
	}
	
}

dump()
{
	int i,j;

	for(j=0;j<=total;j++)
		printf("%2d ",j);
	printf("\n=========================================================\n");
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<=total;j++)
		{
			printf("%2d ",mv[i][j]);
		}
		printf("\n");
	}
	printf("=========================================================\n");
}

int x[MAX];

find_path(int findout)
{
	int i;
	int value=findout;

	for(i=MAX-1;i>=2;i--)
	{
		if(mv[i][value]==mv[i-1][value])
		{
			x[i]=0;
		}
		else
		{
			x[i]=1;
			value=value-m[i];
			printf("i=%d %d\n",i,value);
		}
	}
	x[1]=mv[1][value]?1:0;
}

int main()
{
	int i;

	create_array();
	dump();
	find_path(8);
	for(i=1;i<MAX;i++)
		printf("%2d ",x[i]);
	printf("\n");
}

