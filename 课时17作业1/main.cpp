//��ѡ������
//������

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
//
typedef int ElemType;
typedef struct {
	ElemType* elem;
	int TableLen;// Ԫ�ظ���
}SSTable;

void ST_Init(SSTable& ST, int len)
{
	ST.TableLen = len;
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	//int i;
	//srand(time(NULL));
	//for (size_t i = 0; i < ST.TableLen; i++)
	//{
	//	ST.elem[i] = rand() % 100;//�����11���������ǵ�һ��Ԫ����û���õ���
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
	for (i = 0; i < n - 1; i++)//i��ൽ0����Ϊ������0-9����8��ʱ�������ѭ��j�ܹ��ﵽ9
	{
		min = i;
		for (j = i + 1; j < n; j++)//j��ൽ9
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

//����ĳ�����ڵ�
void AdjustDown(ElemType A[], int k, int len)
{
	int i;
	A[0] = A[k];
	for (i = 2 * k; i <= len; i *= 2)
	{
		//���ӽڵ������ӽڵ�Ƚϴ�С
		if (i < len && A[i] < A[i + 1])
		{
			i++;//������������ڲ��Ҹ���
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

//������ȥ��ʾ��   ��ν���
void BuildMaxHeap(ElemType A[], int len)
{
	for (size_t i = len / 2; i > 0; i--)
	{
		AdjustDown(A, i, len);
	}
}

//������
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



//�����Ķ�����
//��������
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
	//�����󶥶�
	for (i = len / 2; i >= 0; i--)
	{
		AdjustDown1(A, i, len);
	}
	swap(A[0], A[len]);//������������������һ��Ԫ��
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

	memcpy(ST.elem, A, sizeof(A));//�ڴ�copy�ӿڣ�����copy�������飬���߸�����ʱ��Ҫ��memcpy
	//��ѡ������
	SelectSort(ST.elem,10);
	ST_print(ST);

	memcpy(ST.elem, B, sizeof(A));//�ڴ�copy�ӿڣ�����copy�������飬���߸�����ʱ��Ҫ��memcpy
	//������
	HeapSort1(ST.elem, 9);//**********************����Ϊʲô�� 9
	ST_print(ST);

	return 0;
}
