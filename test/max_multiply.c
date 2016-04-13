#include <stdio.h>
static long MaxSubMul(int *seq, int seq_len, int beginIndex, int endIndex);
int main()
{
	long max_mul;
	int int_str[8]={-1,0,-9,0,0,-2,0,-11};
	
	max_mul=MaxSubMul(int_str,8,0,7);
	printf("max_mul[%ld]\n",max_mul);

}


static long MaxSubMul(int *seq, int seq_len, int beginIndex, int endIndex)
{
     long maxMul = seq[0];
     beginIndex = endIndex = 0;
     long curMaxMul = seq[0], curMinMul = seq[0];
     int curMinBeginIndex = 0, curMaxBeginIndex = 0;
	 int i;

     if (seq == NULL || seq_len == 0)
	 {
		printf("error: please input data\n");
		return 0;
	 }
     for (i = 1; i < seq_len; i++)
     {
			long a = curMaxMul * seq[i], b = curMinMul * seq[i];
            long max, min;
            int tmpMaxBeginIndex, tmpMinBeginIndex;
            if(a > b)
            {
                max = a;
                min = b;
                tmpMaxBeginIndex = curMaxBeginIndex;
                tmpMinBeginIndex = curMinBeginIndex;
            }
            else
            {
                max = b;
                min = a;
                tmpMaxBeginIndex = curMinBeginIndex;
                tmpMinBeginIndex = curMaxBeginIndex;
            }
            if (seq[i] > max)
            {
                curMaxBeginIndex = i;
                curMaxMul = seq[i];
            }
            else
            {
                curMaxBeginIndex = tmpMaxBeginIndex;
                curMaxMul = max;
            }
            if (seq[i] < min)
            {
                curMinBeginIndex = i;
                curMinMul = seq[i];
            }
            else
            {
                curMinBeginIndex = tmpMinBeginIndex;
                curMinMul = min;
            }
            if (curMaxMul > maxMul)
            {
                maxMul = curMaxMul;
                beginIndex = curMaxBeginIndex;
                endIndex = i;
            }
        }
        return maxMul;
    }
