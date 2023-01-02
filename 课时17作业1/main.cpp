//简单选择排序
//堆排序

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
//
typedef int ElemType;
typedef struct {
	ElemType* elem;
	int TableLen;// 元素个数
}SSTable;

void ST_Init(SSTable& ST, int len)
{
	ST.TableLen = len;
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	//int i;
	//srand(time(NULL));
	//for (size_t i = 0; i < ST.TableLen; i++)
	//{
	//	ST.elem[i] = rand() % 100;//随机了11个数，但是第一个元素是没有用到的
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

void swap(ElemType& a, ElemType& b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void SelectSort(ElemType A[], int n)
{
	int i, j, min;
	for (i = 0; i < n - 1; i++)//i最多到0，因为数组是0-9，到8的时候，里面的循环j能够达到9
	{
		min = i;
		for (j = i + 1; j < n; j++)//j最多到9
		{
			if (A[j] < A[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(A[min], A[i]);
		}
	}
}

//调节某个父节点
void AdjustDown(ElemType A[], int k, int len)
{
	int i;
	A[0] = A[k];
	for (i = 2 * k; i <= len; i *= 2)
	{
		//左子节点与右子节点比较大小
		if (i < len && A[i] < A[i + 1])
		{
			i++;//如果右子树存在并且更大
		}

		if (A[0] >= A[i])
		{
			break;
		}
		else
		{
			A[k] = A[i];
			k = i;
		}
	}
	A[k] = A[0];
}

//用数组去表示树   层次建树
void BuildMaxHeap(ElemType A[], int len)
{
	for (size_t i = len / 2; i > 0; i--)
	{
		AdjustDown(A, i, len);
	}
}

//堆排序
void HeapSort(ElemType A[], int len)
{
	int i;
	BuildMaxHeap(A, len);
	for (i = len; i > 1; i--)
	{
		swap(A[i], A[1]);
		AdjustDown(A, 1, i - 1);
	}
}



//更简便的堆排序
//调整子树
void AdjustDown1(ElemType A[], int k, int len)
{
	int dad = k;
	int son = 2 * dad + 1;
	while (son <= len)
	{
		if (son + 1 <= len && A[son] < A[son + 1])
		{
			son++;
		}

		if (A[son] > A[dad])
		{
			swap(A[son], A[dad]);
			dad = son;
			son = 2 * dad + 1;
		}
		else
		{
			break;
		}
	}

}

void HeapSort1(ElemType A[], int len)
{
	int i;
	//建立大顶堆
	for (i = len / 2; i >= 0; i--)
	{
		AdjustDown1(A, i, len);
	}
	swap(A[0], A[len]);//交换懂不和数组的最后一个元素
	for (i = len - 1; i > 0; i--)
	{
		AdjustDown1(A, 0, i);
		swap(A[0], A[i]);
	}

}

int main()
{
	SSTable ST;
	ElemType A[10];
	ElemType B[10];
	ST_Init(ST, 10);
	//24 66 94  2 15 74 28 51 22 18 
	for (size_t i = 0; i < 10; i++)
	{
		scanf("%d", &A[i]);
	}
	for (size_t i = 0; i < 10; i++)
	{
		B[i] = A[i];
	}

	memcpy(ST.elem, A, sizeof(A));//内存copy接口，当你copy整型数组，或者浮点型时，要用memcpy
	//简单选择排序
	SelectSort(ST.elem,10);
	ST_print(ST);

	memcpy(ST.elem, B, sizeof(A));//内存copy接口，当你copy整型数组，或者浮点型时，要用memcpy
	//堆排序
	HeapSort1(ST.elem, 9);//**********************这里为什么是 9
	ST_print(ST);

	return 0;
}
