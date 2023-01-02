#include <stdio.h>
#include <stdlib.h>

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
void Creat_BST(BiTree& T, KeyType str[], int n)
{
	T = NULL;
	for (size_t i = 0; i < n; i++)
	{
		BST_Insert(T, str[i]);
	}
}

//递归算法简单，但执行效率较低
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


//// 递归实现
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


//这个书上没有二叉排序树删除代码--考大题没那么高

/// <summary>
/// 用递归实现删除节点
/// </summary>
/// <param name="root">当前锚定的节点</param>
/// <param name="x">要删除的数值</param>
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
	//int searchD; // 递归实现
	KeyType str[7] = { 54,20,66,40,28,79,58 };//将要进入二叉排序树的元素值
	Creat_BST(T, str, 7);
	InOrder(T);
	printf("\n");
	search = BST_Search(T, 40, parent);
	if (search)
	{
		printf("找到对应结点，值=%d\n", search->key);
	}
	else {
		printf("未找到对应结点\n");//没找到search返回的是NULL
	}
	
	////递归实现
	//searchD = BST_Search_D(T, 40, parent);
	//if (searchD)
	//{
	//	printf("找到对应结点，值=%d\n", searchD);
	//}
	//else if (searchD == 0){
	//	printf("未找到对应结点\n");//没找到search返回的是NULL
	//}

	DeleteNode(T, 54);
	InOrder(T);
	printf("\n");

	return 0;
}