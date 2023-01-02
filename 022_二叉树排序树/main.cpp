#include <stdio.h>
#include <stdlib.h>

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
void Creat_BST(BiTree& T, KeyType str[], int n)
{
	T = NULL;
	for (size_t i = 0; i < n; i++)
	{
		BST_Insert(T, str[i]);
	}
}

//�ݹ��㷨�򵥣���ִ��Ч�ʽϵ�
BSTNode* BST_Search(BiTree T, KeyType key, BiTree& p)
{
	p = NULL;
	while (T!=NULL && key != T->key)
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


//// �ݹ�ʵ��
//int BST_Search_D(BiTree T, KeyType key, BiTree& p)
//{
//	p = NULL;
//	if (key < T->key)
//	{
//		p = T;
//		return BST_Search_D(T->lchild, key, p);
//	}
//	else if (key < T->key)
//	{
//		p = T;
//		return BST_Search_D(T->rchild, key, p);
//	}
//	else
//	{
//		if (T->lchild->key == key)
//		{
//			return  T->lchild->key;
//		}
//		else if (T->rchild->key == key)
//		{
//			return  T->lchild->key;
//		}else
//		{
//			return 0;
//		}
//	}
//	/*else
//	{
//		return NULL;
//	}*/
//}


//�������û�ж���������ɾ������--������û��ô��

/// <summary>
/// �õݹ�ʵ��ɾ���ڵ�
/// </summary>
/// <param name="root">��ǰê���Ľڵ�</param>
/// <param name="x">Ҫɾ������ֵ</param>
void DeleteNode(BiTree& root, KeyType x)
{
	if (root == NULL)
	{
		return;
	}
	if (root->key>x)
	{
		DeleteNode(root->lchild, x);
	}
	else if (root->key<x)
	{
		DeleteNode(root->rchild, x);
	}
	else
	{
		if (root->lchild==NULL)
		{
			BiTree tempNode = root;
			root = root->rchild;
			free(tempNode);
		}
		else if(root->rchild==NULL)
		{
			BiTree tempNode = root;
			root = root->lchild;
			free(tempNode);
		}
		else
		{
			BiTree tempNode = root->lchild;
			if (tempNode->rchild!=NULL)
			{
				tempNode = tempNode->rchild;
			}
			root->key = tempNode->key;
			DeleteNode(root->lchild, tempNode->key);
		}
	}
}

void InOrder(BiTree T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		printf("%3d", T->key);
		InOrder(T->rchild);
	}
}

int main()
{
	BiTree T = NULL;
	BiTree parent;
	BiTree search;
	//int searchD; // �ݹ�ʵ��
	KeyType str[7] = { 54,20,66,40,28,79,58 };//��Ҫ���������������Ԫ��ֵ
	Creat_BST(T, str, 7);
	InOrder(T);
	printf("\n");
	search = BST_Search(T, 40, parent);
	if (search)
	{
		printf("�ҵ���Ӧ��㣬ֵ=%d\n", search->key);
	}
	else {
		printf("δ�ҵ���Ӧ���\n");//û�ҵ�search���ص���NULL
	}
	
	////�ݹ�ʵ��
	//searchD = BST_Search_D(T, 40, parent);
	//if (searchD)
	//{
	//	printf("�ҵ���Ӧ��㣬ֵ=%d\n", searchD);
	//}
	//else if (searchD == 0){
	//	printf("δ�ҵ���Ӧ���\n");//û�ҵ�search���ص���NULL
	//}

	DeleteNode(T, 54);
	InOrder(T);
	printf("\n");

	return 0;
}