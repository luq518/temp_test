# include<stdio.h>
# include<string.h>
int date[1005]={1,2,3,4,5};
int f(int w,int s)
{
	printf("w %d s %d\n",w,s);
    if(w==0) return 1;//����
    if(w<0||w>0 &&s==0) return 0;
    if(f(w-date[s],s-1)) return 1;//�˳�����ѡ��һ�� 
    return f(w,s-1);//ѡ����һ��
}

int main()
{
 int i,Weight,n;

 n=5;
 Weight=2;

    if(f(Weight,n))
       printf("YES\n");
	else 
		printf("NO\n");L:
 return 0;

}
