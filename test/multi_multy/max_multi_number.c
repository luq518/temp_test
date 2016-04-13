void longest_multiple(int *a,int n)
{  
int Min=new int[n+1]();  
int *Max=new int[n+1]();  
int *p=new int[n+1]();  
for(int i=0;i<=n;i++){  
p[i]=-1;  
}  
Min[1]=a[1];  
Max[1]=a[1];  
int max_val=Max[1];  
for(int i=2;i<=n;i++){  
Max[i]=max(Max[i-1]*a[i],Min[i-1]*a[i],a[i]);  
Min[i]=min(Max[i-1]*a[i],Min[i-1]*a[i],a[i]);  
if(max_val<Max[i])  
max_val=Max[i];  
}  
if(max_val<0)  
printf("%d",-1);  
else  
printf("%d",max_val);  
delete [] Max;  
delete [] Min;  
}  
