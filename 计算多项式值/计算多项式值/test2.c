#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<math.h>

#define MAXN 100
#define MAXK 1e5

double F1(int n, double a[], double x)
{
	int i = 0;
	double p = a[0];
	for (i = 0; i <= n - 1; i++)
	{
		p +=(pow(x, i)/a[i]);
	}
	return p;
}
double F2(int n, double a[], double x)
{
	int i = 0;
	double p = 1/a[n];
	for (i = n; i > 0; i--)
	{
		p = 1/a[i - 1] + x*p;
	}
	return p;
}

clock_t start, stop;
double duration;

int main()
{
	start = clock();

	int i = 0;
	double a1[MAXN];
	for (i = 0; i < MAXN; i++)
	{
		a1[i] =(double)i;
	}
	for (i = 0; i < MAXK; i++)
	{
		F1(MAXN-1, a1, 1.1);
	}

	stop = clock();
	duration = (double)(stop - start) / CLK_TCK/MAXK ;
	printf("ticks1=%lf\n", (double)(stop - start));
	printf("duration1=%6.2e\n", duration);

	start = clock();

	i = 0;
	double a2[MAXN];
	for (i = 0; i < MAXN; i++)
	{
		a2[i] =(double)i;
	}
	for (i = 0; i < MAXK; i++)
	{
		F1(MAXN-1, a2, 1.1);
	}

	stop = clock();
	duration = (double)(stop - start) / CLK_TCK/MAXK;
	printf("ticks2=%lf\n", (double)(stop - start));
	printf("duration2=%6.2e\n", duration);

	return 0;
}