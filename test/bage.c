#include<stdio.h>

# define max(a,b) a>b?a:b

int main()
{

	    int dp[101][1001],x[100],i,j;
		int m=5,T=43;
		int W=24;
		int temp=0;

		/*
		for(i=1;i<=m;i++)
	        scanf("%d %d",&w[i],&val[i]);
		*/
		int w[]={3,4,7,8,9};
		//int w[]={0,1,2,3,4};
		int val[]={4,5,10,11,13};
	    memset(dp,0,sizeof(dp));
	    for(i=1;i<=m;i++)
		{
			printf("\ni=%d\n",i);
		     for(j=0;j<=T;j++)
	          {
			      if(j>=w[i])
					{
			          dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+val[i]);
					}
			      else 
				  {
					  dp[i][j]=dp[i-1][j];
				  }
				printf("%2d ",dp[i][j]);
		       }
		}
		printf("\n%d\n",dp[m][T]);

		/*output select*/
		for(i=T;i>0;i--)
		{
			if(dp[m][i]==W)
			{
				temp=i;
				break;
			}
		}
		printf("%2d %d %d\n",W,m,temp);
		for(i=m;i>1;i--)
		{
			if(dp[i][temp]==dp[i-1][temp])
				x[i]=0;
			else
				x[i]=1;
			printf("i = %d: %d  %2d %02d\n",i,x[i],dp[i][temp],dp[i-1][temp]);
			W=W-w[i];
		}
		//x[1]=dp[1][temp]
		for(i=1;i<=m;i++)
			printf("%02d ",x[i]);
		printf("\n");
	    return 0;
}
