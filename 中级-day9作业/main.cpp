#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
//
typedef int ElemType;

typedef struct
{
	ElemType* elem; //����ָ��
	int TableLen;	//���涯̬��������Ԫ�صĸ���
}SSTable;


typedef int KeyType;
typedef struct BSTNode
{
	KeyType key;
	struct BSTNode* lchild, * rchild;
}BSTNode, * BiTree;

/// <summary>
/// ��������������
/// </summary>
/// <param name="T">�������������ӽڵ�</param>
/// <param name="k">�����ֵ</param>
/// <returns>����1������0,1��������µ���ɣ�0�������ĺ�֮ǰ�ڵ�Ԫ����ͬ</returns>
int BST_Insert(BiTree& T, KeyType k)
{
	if (NULL == T)
	{
		T = (BiTree)malloc(sizeof(BSTNode));
		T->key = k; //�����������������ɵ�
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

//��������������
void Creat_BST(BiTree& T, KeyType str[], int n,int arr[])
{
	T = NULL;
	int j = 0;
	for (size_t i = 0; i < n; i++)
	{
		BST_Insert(T, str[i]);
	}
}

//�ݹ��㷨�򵥣���ִ��Ч�ʽϵ�
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
	ST.TableLen = len + 1;//�����ڱ�,�ڱ������ᱻkey����
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);//Ϊ��̬��������ռ�
	int i;

	for (size_t i = 0; i < ST.TableLen; i++)
	{
		ST.elem[i] = arr[i];
	}

}


int Binary_Search(SSTable ST, ElemType key)
{
	// low ,high ,mid ����λ��
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

//��������Ĵ�ӡ
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

	//�����������
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


	//���ж��ֲ���
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
		printf("����ʧ��\n");
	}

	return 0;
}
