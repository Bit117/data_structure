#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
//
typedef int ElemType;

typedef struct
{
	ElemType* elem; //整形指针
	int TableLen;	//储存动态数组里面元素的个数
}SSTable;


typedef int KeyType;
typedef struct BSTNode
{
	KeyType key;
	struct BSTNode* lchild, * rchild;
}BSTNode, * BiTree;

/// <summary>
/// 二叉排序树插入
/// </summary>
/// <param name="T">树本身，可以是子节点</param>
/// <param name="k">传入的值</param>
/// <returns>返回1或者是0,1代表插入新的完成，0代表插入的和之前节点元素相同</returns>
int BST_Insert(BiTree& T, KeyType k)
{
	if (NULL == T)
	{
		T = (BiTree)malloc(sizeof(BSTNode));
		T->key = k; //插入是在这里进行完成的
		//arr[] = k;
		T->lchild = T->rchild = NULL;
		return 1;
	}
	else if (k == T->key)
	{
		return 0;
	}
	else if (k < T->key)
	{
		return BST_Insert(T->lchild, k);
	}
	else if (k > T->key)
	{
		return BST_Insert(T->rchild, k);
	}
}

//创建二叉排序树
void Creat_BST(BiTree& T, KeyType str[], int n,int arr[])
{
	T = NULL;
	int j = 0;
	for (size_t i = 0; i < n; i++)
	{
		BST_Insert(T, str[i]);
	}
}

//递归算法简单，但执行效率较低
BSTNode* BST_Search(BiTree T, KeyType key, BiTree& p)
{
	p = NULL;
	while (T != NULL && key != T->key)
	{
		p = T;
		if (key < T->key)
		{
			T = T->lchild;
		}
		else
		{
			T = T->rchild;
		}
	}
	return T;
}


void InOrder(BiTree T , int arr[],int & pos)
{
	if (T != NULL)
	{
		int i = 0;
		InOrder(T->lchild,arr,pos);
		printf("%3d", T->key);
		arr[pos++] = T->key;
		InOrder(T->rchild,arr,pos);
	}
}

void ST_Init(SSTable& ST, int len, int arr[])
{
	ST.TableLen = len + 1;//申请哨兵,哨兵后续会被key覆盖
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);//为动态数组申请空间
	int i;

	for (size_t i = 0; i < ST.TableLen; i++)
	{
		ST.elem[i] = arr[i];
	}

}


int Binary_Search(SSTable ST, ElemType key)
{
	// low ,high ,mid 都是位置
	int low = 0;
	int high = ST.TableLen - 1;
	int mid;
	while (high >= low)
	{
		mid = (high + low) / 2;
		if (ST.elem[mid] == key)
		{
			return mid;
		}
		else if (key >= ST.elem[mid])
		{
			low = mid + 1;
		}
		else
		{
			high = high - 1;
		}
	}
	return -1;
}

//进行数组的打印
void ST_print(SSTable ST)
{
	for (size_t i = 0; i < ST.TableLen-1; i++)
	{
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}

int main()
{
	int str[10];
	int arr[10];
	BiTree T = NULL;
	BiTree parent;
	BiTree search;

	//进行中序输出
	for (size_t i = 0; i < 10; i++)
	{
		scanf("%d", &str[i]);
	}
	Creat_BST(T, str, 10,arr);

	int pos = 0;
	InOrder(T, arr,pos);
	printf("\n");

	
	//for (size_t i = 0; i < 10; i++)
	//{
	//	printf("%3d", arr[i]);
	//}


	//进行二分查找
	SSTable ST;
	ElemType key;
	//int pos;

	ST_Init(ST, 10, arr);

	//ST_print(ST);
	pos = Binary_Search(ST, 21);
	if (pos)
	{
		printf("%d\n", pos);
	}
	else
	{
		printf("查找失败\n");
	}

	return 0;
}
