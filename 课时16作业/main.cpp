//ð�����򣬿������򣬲�������

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef int ElemType;

typedef struct {
	ElemType* elem;//����Ԫ�ص���ʼ��ַ
	int TableLen;//Ԫ�ظ���
}SSTable;

void ST_Init(SSTable& ST, int len)
{
	ST.TableLen = len;
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	//int i;
	//srand(time(NULL));
	//for (size_t i = 0; i < ST.TableLen; i++)
	//{
	//	ST.elem[i] = rand() % 100;//����0-99֮��
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

// ֱ�ӵ��໥����
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

//�����Ŀ�ʼ����û���Ż�
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

//Partition -> ���Σ�����˼��
//int left, int right,�ֱ�������ĵ�һ��λ�ú����һ��λ��
int Partition(int* arr, int left, int right)
{
	int k, i;
	//i ��������������±�
	//k ��� right С��Ԫ�� ��Ҫ���λ�ã�֮��iλ�ú�kλ�ý��н�����

	for (k = i = left; i < right; i++)
	{
		if (arr[i] < arr[right])
		{
			swap(arr[k], arr[i]);
			k++;//����һ��λ�ã���Ҫ��
		}
	}
	swap(arr[k], arr[right]);//ѭ��֮��ǵ�Ҫ�����ұߵ�right��kλ�õ�ֵ���н���
	return k;
}

// �������� -> �ݹ���κõ�����
void QuickSort(ElemType A[], int low, int high)
{
	if (low < high)
	{
		int pivotpos = Partition(A, low, high);//�ָ����ߵ�Ԫ�ض��ȷָ��ҪС���ұߵıȷָ���
		QuickSort(A, low, pivotpos - 1);
		QuickSort(A, pivotpos + 1, high);
	}
}

// �������򣬴�С������������
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
	
	memcpy(ST.elem, A, sizeof(A));//�ڴ�copy�ӿڣ�����copy�������飬���߸�����ʱ��Ҫ��memcpy
	//ð������
	BubbleSort1(ST.elem,10);
	ST_print(ST);

	memcpy(ST.elem, B, sizeof(A));//�ڴ�copy�ӿڣ�����copy�������飬���߸�����ʱ��Ҫ��memcpy
	////��������
	QuickSort(ST.elem, 0, 9);
	ST_print(ST);

	memcpy(ST.elem, C, sizeof(A));//�ڴ�copy�ӿڣ�����copy�������飬���߸�����ʱ��Ҫ��memcpy
	//��������
	InsertSort(ST.elem, 10);
	ST_print(ST);
	return 0;
}
