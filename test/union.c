#include <stdio.h>

int main()
{
	typedef union _tt
	{
		char str;
		int int_tt;
	}Utt;

	typedef struct _test
	{
		int data;
		Utt tt;
	}test;

	test test_data;
	test_data.data=1;
	//test_data.tt.str='c';
	test_data.tt.int_tt=2;
	Utt temp=test_data.tt;
	printf("%d\n",temp.int_tt);
}
