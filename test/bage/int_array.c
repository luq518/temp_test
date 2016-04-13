#include<stdio.h>
int max(int a,int b)
{
 if (a>b) return a;
 else return b;
}
int main()
{
 //int max(int , int );
 int n,m,i,j;
    int data[101][2];
 int f[101][101];
    scanf("%d%d",&n,&m);  //n表示个数，m表示能背的最大重量
 for(i=1;i<=n;i++)
 {
    scanf("%d%d",&data[i][0],&data[i][1]);
 }   //我是数组从第一个开始记得，看着容易理解，没必要去省那么几B的内存
 for(i=0;i<=m;i++) f[0][i]=0;
 for(i=0;i<=n;i++) f[i][0]=0;
 for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
   {
  f[i][j]=0;
  if (j>=data[i][0])   
  {      
       f[i][j]=max(f[i-1][j],f[i-1][j-data[i][0]]+data[i][1]);
     //对于这件物品要么不选要么选，不选是f[i-1][j];
     //选的话为f[i-1][j-data[i][0]]此处j-data[i][0]是因为要选上一次就得少背j-data[i][0]的重量
     //才能装下这次的物品
  }  
  else f[i][j]=f[i-1][j];
   } 
    printf("%d\n",f[n][m]);
 return 0;
}