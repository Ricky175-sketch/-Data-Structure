#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>

#define MAXN 1000
#define MAXK 1e5

int MaxSubseqSum1(int A[], int N)
{
	int i, j, k = 0;
	int ThisSum, MaxSum = 0;
	for (i = 0; i < N; i++)
	{
		for (j = i; j < N; j++)
		{
			ThisSum = 0;
			for (k = i; k <= j; k++)
			{
				ThisSum += A[k];
			}
			if (ThisSum > MaxSum)
			{
				MaxSum = ThisSum;
			}
		}
	}
	return MaxSum;
}
int MaxSubseqSum2(int A[], int N)
{
	int i, j, k = 0;
	int ThisSum, MaxSum = 0;
	for (i = 0; i < N; i++)
	{
		ThisSum = 0;
		for (j = i; j < N; j++)
		{
			ThisSum += A[j];
			if (ThisSum > MaxSum)
			{
				MaxSum = ThisSum;
			}
		}
	}
	return MaxSum;
}

int Max3(int A, int B, int C)
{ /* ����3�������е����ֵ */
	return A > B ? A > C ? A : C : B > C ? B : C;
}
int DivideAndConquer(int A[], int left, int right)
{ /* ���η���List[left]��List[right]��������к� */
	int MaxLeftSum, MaxRightSum; /* �������������Ľ� */
	int MaxLeftBorderSum, MaxRightBorderSum; /*��ſ�ֽ��ߵĽ��*/
	int LeftBorderSum, RightBorderSum;
	int center, i;
	if (left == right)  { /* �ݹ����ֹ����������ֻ��1������ */
		if (A[left] > 0)  return A[left];
		else return 0;
	}
	/* ������"��"�Ĺ��� */
	center = (left + right) / 2; /* �ҵ��зֵ� */
	/* �ݹ�����������е����� */
	MaxLeftSum = DivideAndConquer(A, left, center);
	MaxRightSum = DivideAndConquer(A, center + 1, right);
	/* �������ֽ��ߵ�������к� */
	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for (i = center; i >= left; i--) { /* ����������ɨ�� */
		LeftBorderSum += A[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	} /* ���ɨ����� */
	MaxRightBorderSum = 0; RightBorderSum = 0;
	for (i = center + 1; i <= right; i++) { /* ����������ɨ�� */
		RightBorderSum += A[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	} /* �ұ�ɨ����� */
	/* ���淵��"��"�Ľ�� */
	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}
int MaxSubseqSum3(int A[], int N)
{ /* ������ǰ2���㷨��ͬ�ĺ����ӿ� */
	return DivideAndConquer(A, 0, N - 1);
}

int MaxSubseqSum4(int A[], int N)
{
	int i = 0;
	int ThisSum = 0;
	int MaxSum = 0;
	for (i = 0; i < N; i++)
	{
		ThisSum += A[i];
		if (ThisSum > MaxSum)
		{
			MaxSum = ThisSum;
		}
		else if (ThisSum<0)
		{
			ThisSum = 0;
		}
	}
	
	return MaxSum;
}

clock_t start, stop;
int duration;

int main()
{
	srand((unsigned int)time(NULL));
	int i = 0;
	int a[MAXN] = { 0 };
	for (i = 0; i < MAXN; i++)
	{
		a[i] = rand();
	}
	start = clock();

	for (i = 0; i < MAXK; i++){
		MaxSubseqSum2(a, MAXN);

	}

	stop = clock();
	duration = ((double)(stop - start)) / CLK_TCK/MAXK;
	printf("clicks=%lf\n", (double)(stop - start));
	printf("duration=%6.2e\n", duration);
	return 0;
}