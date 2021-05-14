#include <stdio.h>
#include <time.h>
void fun()
{
	for (long int i=0; i<200000000000000; i++)
	{
	}
}

int main()
{
	double x;
	clock_t t;
	t = clock();
	fun();
	t = clock() - t;
	x = ((double)t)/CLOCKS_PER_SEC;
	printf("%f \n", x);
	return 0;
}