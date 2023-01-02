#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define N 10
typedef	int ElemType;

//�Ѿ��Ź������������
//���бȽϺϲ���Ҳ���ǹ鲢
void Merge(ElemType A[], int low, int mid, int high)
{
	ElemType B[N];
	int i, j, k;
	for (k = low; k <= high; k++)
	{
		B[k] = A[k];//����Ԫ�ص�B��
	}
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
	{
		//�Ƚ�������������˭С������ǰ��
		if (B[i] <= B[j])
		{
			A[k] = B[i++];//���ǰ��������С
		}
		else
		{
			A[k] = B[j++];//�������������С���������
		}
	}

	//ʣ�¶����Ԫ�ط����������
	while (i <= mid)
	{
		A[k++] = B[i++];
	}
	while (j <= high)
	{
		A[k++] = B[j++];
	}

}

void MergeSort(ElemType A[], int low, int high)
{
	if (low < high)
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
	//12 63 58 95 41 35 65  0 38 44
	int A[10];//���飬10��Ԫ��
	for (size_t i = 0; i < 10; i++)
	{
		scanf("%d", &A[i]);
	}
	//print(A);
	//int A[10] = { 12,63,58,95,41,35,65,0,38,44 };
	MergeSort(A, 0, 9); //�����9���±꣬0-9һ������10���ģ�ע�����������
	print(A);
	return 0;
}