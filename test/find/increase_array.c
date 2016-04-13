#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define SIZE 55
char a[SIZE]={
9,44,32,12,7,42,34,92,35,37,41,8,20,
27,83,64,61,28,39,93,29,17,13,14,55,
21,66,72,23,73,99,1,2,88,77,3,65,83,
84,62,5,11,74,68,76,78,67,75,69,70,
22,71,24,25,26};
 
void main(){
    int *lis;
    char *map;
    int i,j,k,t,x;
    int len;
    len=SIZE;
    lis=(int*)malloc(sizeof(int)*len);
    map=(char*)malloc(sizeof(char)*len);
    memset(lis,0,sizeof(int)*len);
    memset(map,0,sizeof(char)*len);
 
    for(i=0;i<len;i++){
        lis[i]=1;
        for(j=0;j<i;j++){
            if(a[i]>a[j]&&lis[j]+1>lis[i]){
                lis[i]=lis[j]+1;
            }
        }
    }

    k=0;
    for(i=0;i<len;i++){
        if(lis[i]>k){
            k=lis[i];j=i;
        }
    }
    printf("max len: %d\n",k);
    t=1;x=j;map[j]=1;
    for(i=j-1;i>=0;i--){
        if(lis[i]==k-t&&a[i]<a[x]){
            map[i]=1;t++;x=i;
        }
    }
    for(i=0;i<len;i++) if(map[i]==1) printf("%d, ",a[i]);
    printf("\n");
 
    free(map);
    free(lis);
}
