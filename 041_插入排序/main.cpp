// �������� -> ��С������������
// �������� -> �۰����
// �������� -> ϣ������

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
	ST.TableLen = len + 1;
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	int i;
	srand(time(NULL));
	for (size_t i = 0; i < ST.TableLen; i++)
	{
		ST.elem[i] = rand() % 100;//�����11���������ǵ�һ��Ԫ����û���õ���
	}

}

void ST_print(SSTable ST)
{
	for (size_t i = 0; i < ST.TableLen; i++)
	{
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}

// �������򣬴�С������������
void InsertSort(ElemType A[], int n)
{
	int i, j;
	//24 66 94  2 15 74 28 51 22 18  2
	for (i = 2; i <= n; i++)
	{
		
		if (A[i]<A[i-1])
		{
			A[0] = A[i];
			for (j = i-1; A[0] <A[j] ; --j)
			{
				A[j+1] = A[j];
			}
			A[j+1] = A[0];
		}
	}
}

// �������� -> �۰����
void MidInsertSort(ElemType A[], int n)
{
	int i, j, low, high, mid;
	for (i = 2; i <= n; i++)
	{
		A[0] = A[i];

		//λ��
		low = 1;
		high = i - 1;

		//ͨ�����ֲ����ҵ�Ҫ�����λ��
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (A[mid]>A[0])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}

		for (j = i-1; j >=high+1; --j)
		{
			A[j + 1] = A[j];
		}
		A[high + 1] = A[0];

	}
}

int pluss(int a, int b)
{
	int c = (a + b)/2;
	return c;
}

//���ڱ�
// �������� -> ϣ������
void ShellSort(ElemType A[], int n)
{
	int dk, i, j;
	for (dk = n/2; dk>=1 ; dk = dk/2)
	{
		for (i = dk+1;  i<=n ; ++i)
		{
			if (A[i]<A[i-dk])
			{
				A[0] = A[i];
				for (j = i-dk; j >0&&A[0]<A[j]; j = j-dk)
				{
					A[j + dk] = A[j];
				}
				A[j + dk] = A[0];//û���⣬j����֮���Ǹ��ģ������һ��j=-4  A[j + dk]=A[1]   ��A[1] = A[0]
			}
		}
	}
}

int main()
{
	SSTable ST;
	ElemType A[10] = { 64, 94, 95, 79, 69, 84, 18, 22, 12 ,78 };
	ST_Init(ST,10);
	//ST_print(ST);
	//memcpy(A, ST.elem, sizeof(A));
	ST_print(ST);

	//// �������� -> ��С���������������ڱ���
	//InsertSort(ST.elem, 10);
	//ST_print(ST);

	//// �������� -> �۰����
	//MidInsertSort(ST.elem, 10);
	//ST_print(ST);	

	// �������� -> ϣ������
	ShellSort(ST.elem, 10);
	ST_print(ST);

	return 0;
}
