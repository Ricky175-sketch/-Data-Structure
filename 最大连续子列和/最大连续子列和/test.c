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
{ /* 返回3个整数中的最大值 */
	return A > B ? A > C ? A : C : B > C ? B : C;
}
int DivideAndConquer(int A[], int left, int right)
{ /* 分治法求List[left]到List[right]的最大子列和 */
	int MaxLeftSum, MaxRightSum; /* 存放左右子问题的解 */
	int MaxLeftBorderSum, MaxRightBorderSum; /*存放跨分界线的结果*/
	int LeftBorderSum, RightBorderSum;
	int center, i;
	if (left == right)  { /* 递归的终止条件，子列只有1个数字 */
		if (A[left] > 0)  return A[left];
		else return 0;
	}
	/* 下面是"分"的过程 */
	center = (left + right) / 2; /* 找到中分点 */
	/* 递归求得两边子列的最大和 */
	MaxLeftSum = DivideAndConquer(A, left, center);
	MaxRightSum = DivideAndConquer(A, center + 1, right);
	/* 下面求跨分界线的最大子列和 */
	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for (i = center; i >= left; i--) { /* 从中线向左扫描 */
		LeftBorderSum += A[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	} /* 左边扫描结束 */
	MaxRightBorderSum = 0; RightBorderSum = 0;
	for (i = center + 1; i <= right; i++) { /* 从中线向右扫描 */
		RightBorderSum += A[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	} /* 右边扫描结束 */
	/* 下面返回"治"的结果 */
	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}
int MaxSubseqSum3(int A[], int N)
{ /* 保持与前2种算法相同的函数接口 */
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