#include <stdio.h>
#define MAX_NUM	4

int know[MAX_NUM][MAX_NUM]={{0,1,1,1},{0,1,0,1},{1,1,0,1},{0,0,0,1}};

celebrity()
{
	int i,j,k;
	int candidate=0;
	int confirm=1;

	i=0;
	j=1;
	k=2;

	while(k<=MAX_NUM)
	{
		if(know[i][j]==0)
		{
			j=k;	
		}
		else
		{
			i=k;	
		}
		printf("%d %d %d\n",i,j,k);
		k++;
	}
	if(i==MAX_NUM)
		candidate=j;
	else
		candidate=i;
	printf("candidate:%d\n",candidate);

	
	for(i=0;i<MAX_NUM;i++)
	{
		if((know[candidate][i]==1&&i!=candidate) || (know[i][candidate]==0&&i!=candidate))
			confirm=0;	
	}
	if(confirm==1)
		printf("find a person : %d\n",candidate);
	else
		printf("no person be found\n");
}

int main()
{
	celebrity();


}


