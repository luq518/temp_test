#include <stdio.h>

#define MIN(a,b) a>b?b:a

int min(int a,int b,int c)
{
	int temp;
	temp=MIN(a,b);
	temp=MIN(temp,c);

	printf("temp %d\n",temp);
	return temp;
}

int compare(char *str1, int len1, char *str2, int len2)
{

	int i,j;
	int p[10][10];
	int x,y,z;

	for(i=0;i<len1;i++)
	{
		p[i][0]=i;
	}

	for(j=0;j<len2;j++)
	{
		p[0][j]=j;
	}
	for(i=1;i<len1;i++)
	{
		for(j=1;j<len2;j++)
		{
			if(str1[i-1]==str2[j-1])
				x=p[i-1][j-1];
			else
				x=p[i-1][j-1]+1;

			y=p[i-1][j]+1;
			z=p[i][j-1]+1;
			printf("%d %d %d \n",x,y,z);
			p[i][j]=min(x,y,z);
		}

	}

	for(i=0;i<len1;i++)
	{
		for(j=0;j<len2;j++)
		{
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	char *str1="abc";
	char *str2="cccd";

	compare(str1,4,str2,5);
}
