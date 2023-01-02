#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

typedef int ElemType;

typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;

bool ListInsert(SqList& L, int i, ElemType e)
{
	// ����Ƿ��д���
	if (i<1 || i>L.length + 1)
	{
		return false;
	}
	if (L.length >= MaxSize)
	{
		return false;
	}

	//������λ��
	for (int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j - 1];
	}

	//��Ϊi��λ�ñ���������λ�ã�����-1
	L.data[i - 1] = e;

	//length�ĳ���+1
	L.length++;
	return true;
}

bool ListDelete(SqList& L, int i, ElemType& e)
{
	if (i<1 || i>L.length)//���ɾ����λ���ǲ��Ϸ�
		return false;
	if (L.length == 0)//˳�����û��Ԫ�أ�����ɾ��
	{
		return false;
	}
	for (size_t j = i; j < L.length; j++)
	{
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

int locateElem(SqList& L, ElemType e)
{
	if (L.length == 0)//˳�����û��Ԫ��
	{
		return false;
	}
	for (size_t i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
		{
			return i + 1;
		}
	}
	return 0;
}

bool ListChange(SqList& L, int i, ElemType e)
{
	if (L.length == 0)//˳�����û��Ԫ��
	{
		return false;
	}
	if (L.length < i)//�ĵ�Խ��
	{
		return false;
	}

	L.data[i-1] = e;

}

void PrintList(SqList& L)
{
	for (size_t i = 0; i < L.length; i++)
	{
		printf("%3d", L.data[i]);
	}
	printf("\n");
}


int main()
{
	SqList L;
	bool ret;
	ElemType del;

	//�����ֶ���˳�����ǰ����Ԫ�ظ�ֵ
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;//�ܼ�����Ԫ��

	// ��
	ret = ListInsert(L, 2, 60);
	if (ret)
	{
		printf("instert achieve\n");
		PrintList(L);
	}
	else
	{
		printf("instert fail");
	}
	printf("\n");

	// ɾ
	ret = ListDelete(L, 1, del);
	if (ret)
	{
		printf("delete achieve\n");
		PrintList(L);
	}
	else
	{
		printf("delete fail");
	}
	printf("\n");

	// ��
	ret = ListChange(L, 2, 20);
	if (ret)
	{
		printf("change achieve\n");
		PrintList(L);
	}
	else
	{
		printf("delete fail");
	}
	printf("\n");

	// ��
	int elem_pos; //�����ҳ�����Ԫ��λ��
	elem_pos = locateElem(L, 60);
	if (elem_pos)
	{
		printf("search achieve\n");
		printf("the location is %d\n", elem_pos);
	}

	return 0;
}