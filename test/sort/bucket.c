#include <stdio.h>
#include <string.h>

int	sort(int *array, int bit, int size)
{
	int *temp_array=(int *)malloc(size*sizeof(int));	
	int i,j,k,index;
	int x[10][2];
	int div=1;	

	memcpy(temp_array,array,size*sizeof(int));

	dump(array,size);
	dump(temp_array,size);

	for(i=0;i<bit;i++)
	{
		for(j=0;j<size;j++)
		{
			index=(temp_array[j]/div)%10;
			x[index][0]=temp_array[j];
			//printf("%2d \n",x[index][0]);
		}
		for(k=0;k<10;k++)
		{
			printf("%2d \n",x[k][0]);
			temp_array[k]=x[k][0];
		}
		dump(temp_array,size);
		div=div*10;
	}
	dump(temp_array,size);
	free(temp_array);
}
dump(int *array,int size)
{
	int i;

	for(i=0;i<size;i++)
	{
		printf("%2d ",array[i]);
	}
	printf("\n");

}

int main()
{
	int array[]={0,91,82,73,64,55,46,37,28,19};

	sort(array,2,10);
}
