#include<stdio.h>  

const int c = 7;             //����������  
const int w[] = {2,2,6,5,4};//��Ʒ������ 
const int v[] = {6,3,5,4,6};//��Ʒ��Ӧ�Ĵ���  
const int n = sizeof(w)/sizeof(w[0]) - 1 ; //nΪ��Ʒ�ĸ���   
int x[10];  

void package0_1(int m[][10],const int w[],const int v[],const int n)//n������Ʒ�ĸ���   
{  
    int i, j;
/*********************************���һ����Ʒ��������*********************************/  
    for(j = 1; j <= c; j++)  
	{
       if(j < w[n]) /*��������<���һ����Ʒ������ʱ*/
		   m[n][j-1] = 0;   
       else /*�����ܹ��������һ����Ʒʱ*/        
		   m[n][j-1] = v[n];  
	}
         
/*********************************����ǰn-1����Ʒ*********************************/  
    for(i = n-1; i >= 0; i--)  
        for(j = 1; j <= c; j++) 
		{
           if(j < w[i])   
               m[i][j-1] = m[i+1][j-1];//���j < w[i]�򣬵�ǰλ�þͲ��ܷ��ã���������һ��λ�õ�ֵ 
           else //���򣬾ͱȽϵ����Ƿ���֮���ֵ�󣬻��ǲ����õ�ֵ��ѡ�����нϴ���
			   m[i][j-1] = m[i+1][j-1] > m[i+1][j-1-w[i]]+v[i] ? m[i+1][j-1] : m[i+1][j-1-w[i]]+v[i];
		}
}  
void answer(int m[][10],const int n)  
{  
    int j = c; /*i = 0, j= c-1�����ϴ���ű�������Ϊcʱ������ֵ*/ 
    int i; 
	
    for(i = 0; i < n; i++)  
        if(m[i][j] == m[i+1][j]) 
			x[i] = 0;  
        else                
		{   
			x[i] = 1;  /*�����ǰ��Ʒ�����˱���*/
			j = j - w[i];  /*���¼��㱳��ʣ���������Լ�����ȡ����ʱ������Ʒ��ȡ�����*/
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
