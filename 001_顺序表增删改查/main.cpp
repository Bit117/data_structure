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
	// 检查是否有错误
	if (i<1 || i>L.length + 1)
	{
		return false;
	}
	if (L.length >= MaxSize)
	{
		return false;
	}

	//往后腾位置
	for (int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j - 1];
	}

	//因为i从位置变成了数组的位置，所以-1
	L.data[i - 1] = e;

	//length的长度+1
	L.length++;
	return true;
}

bool ListDelete(SqList& L, int i, ElemType& e)
{
	if (i<1 || i>L.length)//如果删除的位置是不合法
		return false;
	if (L.length == 0)//顺序表中没有元素，无需删除
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
	if (L.length == 0)//顺序表中没有元素
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
	if (L.length == 0)//顺序表中没有元素
	{
		return false;
	}
	if (L.length < i)//改的越界
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

	//首先手动在顺序表中前三个元素赋值
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;//总计三个元素

	// 增
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

	// 删
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

	// 改
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

	// 查
	int elem_pos; //被查找出来的元素位置
	elem_pos = locateElem(L, 60);
	if (elem_pos)
	{
		printf("search achieve\n");
		printf("the location is %d\n", elem_pos);
	}

	return 0;
}