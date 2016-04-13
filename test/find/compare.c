#include <stdio.h>
#include <string.h>
int dyna(char *str1, int m, char *str2, int n)
{
	int p[100][100];
	int x;

	// first row
	for (x=0; x<n; x++)
	{
		p[0][x]=x;
	}
	// first col
	for (x=0; x<m; x++)
	{
		p[x][0]=x;
	}
	/////

	int i,j;
	for (i=1; i<m; i++)
	{
		for (j=1; j<n; j++)
		{
			//printf("%d ", p[i][j]);
			int cost = (str1[i-1] == str2[j-1]) ? 0 : 1;
			cost += p[i-1][j-1];
			p[i][j] = ( cost < (p[i-1][j]+1) )? cost:(p[i-1][j]+1);
			p[i][j] = (p[i][j] < (p[i][j-1] +1)) ? p[i][j] :(p[i][j-1]);
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}


	int mm=p[m-1][n-1];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return mm;
}

int main()
{


	char str1[]={"abc"};
	char str2[]={"abcd"};
	int n = dyna(str1,strlen(str1)+1, str2, strlen(str2)+1);

	printf("num:  %d\n", n);
	return 0;
}
