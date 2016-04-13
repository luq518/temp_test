#include <stdio.h>

#include <stdlib.h>

#define EVM_UPGRADE_MAX_SN  26 

int main()
{
		FILE *fp;
		char s8StbID[EVM_UPGRADE_MAX_SN];

		fp = fopen("/home/database/stbid","r");
		if(fp != NULL)
		{
			fread(s8StbID,1,EVM_UPGRADE_MAX_SN,fp);
			fclose(fp);
			printf("[%s]\n",s8StbID);
		}
		else
		{
			printf("error: fopen fp[%p]\n",fp);
			//fclose(fp);
			printf("error: 1 fopen\n");
		}
}
