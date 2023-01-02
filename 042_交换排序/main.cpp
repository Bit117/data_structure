//冒泡排序和快速排序

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef int ElemType;

typedef struct {
	ElemType* elem;//储存元素的起始地址
	int TableLen;//元素个数
}SSTable;

void ST_Init(SSTable& ST, int len)
{
	ST.TableLen = len;
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	//int i;
	srand(time(NULL));
	for (size_t i = 0; i < ST.TableLen; i++)
	{
		ST.elem[i] = rand() % 100;//生成0-99之间
	}
}

void ST_print(SSTable ST)
{
	for (size_t i = 0; i < ST.TableLen; i++)
	{
		printf("%3d",ST.elem[i]);
	}
	printf("\n");
}

// 直接的相互交换
void swap(ElemType& a, ElemType& b)
{
	ElemType tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void BubbleSort(ElemType A[], int n)
{
	int i, j, flag;
	for ( i = 0; i < n-1; i++)
	{
		for ( j = n-1; j>i ; j--)
		{
			if (A[j-1] > A[j])
			{
				swap(A[j - 1], A[j]);
			}
		}
	}
}

//从最大的开始排序，没有优化
void BubbleSort1(ElemType A[], int n)
{
	for (size_t i = 0; i < n-1; i++)
	{
		for (size_t j = 0; j < n-i-1; j++)
		{
			if (A[j] > A[j + 1])
			{
				swap(A[j], A[j + 1]);
			}
		}
	}
}

//Partition -> 分治，分区思想
//int left, int right,分别是数组的第一个位置和最后一个位置
int Partition(int* arr, int left, int right)
{
	int k, i;
	//i 用来遍历数组的下标
	//k 存比 right 小的元素 将要存的位置（之后i位置和k位置进行交换）

	for (k = i = left; i < right; i++)
	{
		if (arr[i]<arr[right])
		{
			swap(arr[k], arr[i]);
			k++;//到下一个位置（重要）
		}
	}
	swap(arr[k], arr[right]);//循环之后记得要把最右边的right和k位置的值进行交换
	return k;
}

// 快速排序 -> 递归分治好的数组
void QuickSort(ElemType A[], int low, int high)
{
	if (low<high)
	{
		int pivotpos = Partition(A, low, high);//分割点左边的元素都比分割点要小，右边的比分割点大
		QuickSort(A, low, pivotpos - 1);
		QuickSort(A, pivotpos + 1, high);
	}
}

//
int main()
{
	SSTable ST;
	ElemType A[10] = { 64, 94, 95, 79, 69, 84, 18, 22, 12 ,78 };
	//memccpy(ST.elem, A,10,sizeof(A));
	//初始化和复制数组
	ST_Init(ST,10);
	memcpy(ST.elem, A, sizeof(A));//内存copy接口，当你copy整型数组，或者浮点型时，要用memcpy
	ST_print(ST);

	//冒泡排序
	//BubbleSort1(ST.elem,10);
	//ST_print(ST);

	//快速排序
	QuickSort(ST.elem, 0, 9);
	ST_print(ST);

	return 0;
}
