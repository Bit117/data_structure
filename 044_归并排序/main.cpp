#include<stdio.h>
#include<stdlib.h>

#define N 7
typedef	int ElemType;

//已经排过序的两个数组
//进行比较合并，也就是归并
void Merge(ElemType A[], int low, int mid, int high)
{
	ElemType B[N];
	int i, j, k;
	for ( k = low; k <= high; k++)
	{
		B[k] = A[k];//复制元素到B中
	}
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
	{
		//比较两个数组里面谁小，排在前面
		if (B[i]<=B[j])
		{
			A[k] = B[i++];//如果前面的数组更小
		}
		else
		{
			A[k] = B[j++];//如果后面的数组更小或者是相等
		}
	}

	//剩下多余的元素放入大数组中
	while (i<=mid)
	{
		A[k++] = B[i++];
	}
	while (j<=high)
	{
		A[k++] = B[j++];
	}
}

void MergeSort(ElemType A[], int low, int high)
{
	if (low<high)
	{
		int mid = (high + low) / 2;
		MergeSort(A, low, mid);
		MergeSort(A, mid + 1, high);
		Merge(A, low, mid, high);
	}
}

void print(int* A)
{
	for (size_t i = 0; i < N; i++)
	{
		printf("%3d", A[i]);
		//printf("3d", &A[i]);
	}
	printf("\n");
}

int main()
{
	int A[10] = { 49,38,65,97,76,13,27 };//数组，7个元素
	MergeSort(A, 0, 6);
	print(A);
	return 0;
}