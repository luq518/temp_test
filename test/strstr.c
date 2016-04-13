#include<string.h>
main()
{
	char*s="0.0.0.0192.168.1.110";
	char*l="0.0.0.0";
	char*p;
	p=strstr(s,l);
	if(p)
		printf("%s\n",p);
	else
		printf("NotFound!\n");
	return 0;
}
