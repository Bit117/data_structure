#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//

typedef int Elemtype;
#define MaxSize 50

typedef struct
{
	Elemtype data[MaxSize];
	int length;
}SqList;

void listPrint(SqList& L)
{
	for (size_t i = 0; i < L.length; i++)
	{
		printf("%3d", L.data[i]);
	}
	printf("\n");
}

bool listInsert(SqList& L, int a, Elemtype e)
{
	if (L.length >= MaxSize)
	{
		return false;
	}
	for (size_t i = L.length; i >= a; i--)
	{
		L.data[i] = L.data[i - 1];
	}
	L.data[a - 1] = e;
	L.length++;
	return true;
}

bool listDelete(SqList& L,int pos)
{
	if (pos > L.length)
	{
		printf("false");
		return false;
	}
	for (size_t i = pos; i < L.length; i++)
	{
		L.data[i - 1] = L.data[i];
	}

	L.length--;
	listPrint(L);
	return true;
}

int main()
{
	SqList L;
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;

	int num;
	scanf("%d", &num);

	listInsert(L, 2, num);
	listPrint(L);

	int del_pos;
	scanf("%d", &del_pos);
	listDelete(L, del_pos);

	return 0;
}
