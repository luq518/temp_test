#include <stdio.h>
#define MAX 8 

dump(int *array,int size)
{
	int i;

	for(i=0;i<size;i++)
	{
		printf("%2d ",array[i]);
	}
	printf("\n");

}

void HeapAdjust(int array[],int i,int nLength)
{
    int nChild;
    int nTemp;
    for(;2*i+1<nLength;i=nChild)
    {
        nChild=2*i+1; 
		printf("start: %d nchild %d length %d\n",i, nChild,nLength);
		dump(array,MAX);
        if(nChild<nLength-1&&array[nChild+1]>array[nChild])++nChild;

        if(array[i]<array[nChild])
        {
            nTemp=array[i];
            array[i]=array[nChild];
            array[nChild]=nTemp; 
        }
        else break;
		printf("end: %d nchild %d\n",i, nChild);
		dump(array,MAX);
    }
}

void HeapSort(int array[],int length)
{
    int i;
    
    for(i=length/2-1;i>=0;--i)
		HeapAdjust(array,i,length);
	printf("leaves end\n");
	    
    for(i=length-1;i>0;--i)
    {
 
        array[i]=array[0]^array[i];
        array[0]=array[0]^array[i];
        array[i]=array[0]^array[i];
        HeapAdjust(array,0,i);
    }
	
}
int main()
{
    int i;
	int num[]={8,4,3,2,6,5,9,6};
    //int num[]={9,8,7,6,5,4,3,2,1,0};
    HeapSort(num,sizeof(num)/sizeof(int));
    for(i=0;i<sizeof(num)/sizeof(int);i++)
    {
        printf("%d ",num[i]);
    }
    printf("\nok\n");
    return 0;
}
