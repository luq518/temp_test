#include<stdio.h>  

const int c = 7;             //背包的容量  
const int w[] = {2,2,6,5,4};//物品的重量 
const int v[] = {6,3,5,4,6};//物品对应的待加  
const int n = sizeof(w)/sizeof(w[0]) - 1 ; //n为物品的个数   
int x[10];  

void package0_1(int m[][10],const int w[],const int v[],const int n)//n代表物品的个数   
{  
    int i, j;
/*********************************最后一个物品单独放置*********************************/  
    for(j = 1; j <= c; j++)  
	{
       if(j < w[n]) /*背包容量<最后一个物品的重量时*/
		   m[n][j-1] = 0;   
       else /*背包能够放下最后一个物品时*/        
		   m[n][j-1] = v[n];  
	}
         
/*********************************放置前n-1个物品*********************************/  
    for(i = n-1; i >= 0; i--)  
        for(j = 1; j <= c; j++) 
		{
           if(j < w[i])   
               m[i][j-1] = m[i+1][j-1];//如果j < w[i]则，当前位置就不能放置，它等于上一个位置的值 
           else //否则，就比较到底是放置之后的值大，还是不放置的值大，选择其中较大者
			   m[i][j-1] = m[i+1][j-1] > m[i+1][j-1-w[i]]+v[i] ? m[i+1][j-1] : m[i+1][j-1-w[i]]+v[i];
		}
}  
void answer(int m[][10],const int n)  
{  
    int j = c; /*i = 0, j= c-1坐标上存放着背包容量为c时的最大价值*/ 
    int i; 
	
    for(i = 0; i < n; i++)  
        if(m[i][j] == m[i+1][j]) 
			x[i] = 0;  
        else                
		{   
			x[i] = 1;  /*如果当前物品放入了背包*/
			j = j - w[i];  /*重新计算背包剩余容量，以计算在取最优时其他物品的取舍情况*/
        }
	i -= 1;
    x[n] = m[i][j] ? 1 : 0;   
}  
int main()  
{  
 int m[6][10]={0}; 
 int i, j;
   
 package0_1(m,w,v,n);  
 for(i = 0; i <= 4; i++)  
 {  
     for(j = 0; j < 10; j++)  
     printf("%3d ",m[i][j]);  
     printf("\n");
 }   
 answer(m,n);  
 printf("The best answer is:\n");  
 for(i = 0; i < 5; i++)  
	printf("%d ",  x[i]); 
 printf("\n");

 return 0;  
}  
