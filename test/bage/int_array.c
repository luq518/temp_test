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
    scanf("%d%d",&n,&m);  //n��ʾ������m��ʾ�ܱ����������
 for(i=1;i<=n;i++)
 {
    scanf("%d%d",&data[i][0],&data[i][1]);
 }   //��������ӵ�һ����ʼ�ǵã�����������⣬û��Ҫȥʡ��ô��B���ڴ�
 for(i=0;i<=m;i++) f[0][i]=0;
 for(i=0;i<=n;i++) f[i][0]=0;
 for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
   {
  f[i][j]=0;
  if (j>=data[i][0])   
  {      
       f[i][j]=max(f[i-1][j],f[i-1][j-data[i][0]]+data[i][1]);
     //���������ƷҪô��ѡҪôѡ����ѡ��f[i-1][j];
     //ѡ�Ļ�Ϊf[i-1][j-data[i][0]]�˴�j-data[i][0]����ΪҪѡ��һ�ξ͵��ٱ�j-data[i][0]������
     //����װ����ε���Ʒ
  }  
  else f[i][j]=f[i-1][j];
   } 
    printf("%d\n",f[n][m]);
 return 0;
}