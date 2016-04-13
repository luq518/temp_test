#include <stdio.h>
int max(int a,int b, int c)
{
	printf("a %d b %d c %d\n",a,b,c);
	if(a>b && a>c)
	{
		return a;
	}
	else if(b>a&& b>c)
	{
		return b;
	}
	else if(c>a && c>b)
	{
		return c;
	}
	else
		return a;
}

int min(int a,int b, int c)
{
	printf("min a %d b %d c %d\n",a,b,c);
	if(a<b && a<c)
	{
		return a;
	}
	else if(b<a&& b<c)
	{
		return b;
	}
	else if(c<a && c<b)
	{
		return c;
	}
	else
		return a;
}


void longest_multiple(int *a,int n)
{  
 int Min[n+1];  
 int Max[n+1];  
 int p[n+1];  
 int i,j;
 int max_val=0;
 int min_val=0;

 for(i=0;i<=n;i++)
 {  
  p[i]=-1;  
 }  
 Min[0]=a[0];  
 Max[0]=a[0];  
 max_val=Max[0];  
 for(i=1;i<n;i++){  
  Max[i]=max(Max[i-1]*a[i],Min[i-1]*a[i],a[i]);  
  Min[i]=min(Max[i-1]*a[i],Min[i-1]*a[i],a[i]);  
  printf("i=%d %d %d\n",i,Max[i],Min[i]);
  if(max_val<Max[i])  
   max_val=Max[i];  
  else if(min_val>Min[i])
	  min_val=Min[i];
 }  
 if(max_val<0)  
  printf("%d\n",-1);  
 else  
  printf("%d d %d\n",max_val,min_val);  
}  

int main()
{
	int test[]={2,3,-5,1,2};

	longest_multiple(test,5);
}
