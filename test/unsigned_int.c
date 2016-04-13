#include <stdio.h>
#include <sys/time.h>

static unsigned int get_time_ms(void)
{
	    unsigned int ms = 0;
		struct timeval struTime = {0};

		gettimeofday(&struTime, NULL);
		ms = struTime.tv_sec * 1000 + struTime.tv_usec / 1000;
		printf("sec [%u] usec [%u]\n",struTime.tv_sec,struTime.tv_usec);

		return ms;
}



int main()
{

	unsigned int s1;
	unsigned int s3=0xFFFFFFFF;
	unsigned int s2=get_time_ms();

	sleep(1);
	s1=get_time_ms();

	if(s1-s2>s3)
	{
		printf("timeout %u\n",s1-s2);
	}
	else
	{
		printf("no timeout %u\n",s1-s2);
	}

}
