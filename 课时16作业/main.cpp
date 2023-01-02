//冒泡排序，快速排序，插入排序

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
	//srand(time(NULL));
	//for (size_t i = 0; i < ST.TableLen; i++)
	//{
	//	ST.elem[i] = rand() % 100;//生成0-99之间
	//}
}

void ST_print(SSTable ST)
{
	for (size_t i = 0; i < ST.TableLen; i++)
	{
		printf("%3d", ST.elem[i]);
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
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			if (A[j - 1] > A[j])
			{
				swap(A[j - 1], A[j]);
			}
		}
	}
}

//从最大的开始排序，没有优化
void BubbleSort1(ElemType A[], int n)
{
	for (size_t i = 0; i < n - 1; i++)
	{
		for (size_t j = 0; j < n - i - 1; j++)
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
		if (arr[i] < arr[right])
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
	if (low < high)
	{
		int pivotpos = Partition(A, low, high);//分割点左边的元素都比分割点要小，右边的比分割点大
		QuickSort(A, low, pivotpos - 1);
		QuickSort(A, pivotpos + 1, high);
	}
}

// 插入排序，从小到大排序，升序
void InsertSort(ElemType A[], int n)
{
	int i, j;
	int flag;
	//24 66 94  2 15 74 28 51 22 18  2
	for (i = 1; i < n; i++)
	{

		if (A[i] < A[i - 1])
		{
			flag = A[i];
			for (j = i - 1; flag < A[j]; --j)
			{
				A[j + 1] = A[j];
			}
			A[j + 1] = flag;
		}
	}
}
//
int main()
{
	SSTable ST;
	ElemType A[10];
	ElemType B[10],C[10];
	ST_Init(ST,10);
	//24 66 94  2 15 74 28 51 22 18 
	for (size_t i = 0; i < 10; i++)
	{
		scanf("%d", &A[i]);
	}
	for (size_t i = 0; i < 10; i++)
	{
		B[i] = A[i];
		C[i] = A[i];
	}
	
	memcpy(ST.elem, A, sizeof(A));//内存copy接口，当你copy整型数组，或者浮点型时，要用memcpy
	//冒泡排序
	BubbleSort1(ST.elem,10);
	ST_print(ST);

	memcpy(ST.elem, B, sizeof(A));//内存copy接口，当你copy整型数组，或者浮点型时，要用memcpy
	////快速排序
	QuickSort(ST.elem, 0, 9);
	ST_print(ST);

	memcpy(ST.elem, C, sizeof(A));//内存copy接口，当你copy整型数组，或者浮点型时，要用memcpy
	//插入排序
	InsertSort(ST.elem, 10);
	ST_print(ST);
	return 0;
}
