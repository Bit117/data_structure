#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//定义数据类型
typedef	char BiElemType;

//define binaryTree node
//定义二叉树节点
typedef struct BiTNode
{
	BiElemType data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, * BiTree;

//define binaryTree insert queue
//定义一个插入队列
typedef struct tag
{
	BiTree p;//指向某一个节点 是tag结构体中的一个成员，p是一个结构体指针，p指向的有自己的data 左子树、右子树
	struct tag* pnext;//指向下一个节点
}tag_t, *ptag_t;


//队列

//队列的相关数据结构
typedef BiTree ElemType;
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode;
typedef struct {
	LinkNode* front, * rear;
}LinkQueue;

void InitQueue(LinkQueue& Q)
{
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

void EnQueue(LinkQueue& Q, ElemType x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x; 
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}

bool DeQueue(LinkQueue& Q, ElemType& x)
{
	if (Q.front == Q.rear) return false;
	LinkNode* p = Q.front->next;//头结点什么都没存，所以头结点的下一个节点才有数据
	x = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return true;
}

//前序遍历
void preOrder(BiTree p)
{
	if (NULL != p)
	{
		putchar(p->data);
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}

//中序遍历
void InOrder(BiTree p)
{
	if (NULL !=p)
	{
		InOrder(p->lchild);
		putchar(p->data);
		InOrder(p->rchild);
	}
}

//后续遍历
void PostOrder(BiTree p)
{
	if (NULL != p)
	{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		putchar(p->data);
	}
}

//层次遍历,层序遍历，广度优先遍历
void LevelOrder(BiTree T)
{
	LinkQueue Q;
	InitQueue(Q);
	BiTree p;
	EnQueue(Q, T);// store root
	while (!IsEmpty(Q))
	{
		DeQueue(Q, p);
		putchar(p->data);
		if (NULL != p->lchild)
		{
			EnQueue(Q, p->lchild); // 入队左孩子
		}
		if (NULL != p->rchild)
		{
			EnQueue(Q, p->rchild); // 入队右孩子
		}
	}

}

//

int main()
{
	BiTree pnew;//每次用来接临时申请的空间,存新的树节点
	char data;
	BiTree tree = NULL;
	ptag_t phead = NULL, ptail = NULL, pcur = NULL, listpnew = NULL;

	while (scanf("%c",&data) != EOF)
	{
		if (data == '\n')
		{
			break;
		}

		pnew = (BiTree)calloc(1, sizeof(BiTNode));
		pnew->data = data;

		listpnew = (ptag_t)calloc(1, sizeof(tag_t));
		listpnew->p = pnew;//p是真正的树节点 的结构体指针

		//存辅助队列
		if (NULL == tree)
		{
			tree = pnew;
			phead = listpnew;
			ptail = listpnew;
			pcur = listpnew;
			continue; //这里也很重要，需要加一个tree来结束第一次加树后的操作
		}
		else
		{
			ptail->pnext = listpnew; //结构体指针指向新的队列节点
			ptail = listpnew; //向下走一个
		}

		//建树
		if (NULL == pcur->p->lchild)
		{
			pcur->p->lchild = pnew;
		}
		else if (NULL == pcur->p->rchild)
		{
			pcur->p->rchild = pnew;
			pcur = pcur->pnext;
		}
	}

	//printf("--------前序遍历----------\n");//也叫先序遍历，先打印当前结点，打印左孩子，打印右孩子
	//preOrder(tree);
	//printf("\n");
	
	//中序
	InOrder(tree);
	printf("\n");

	//后序
	PostOrder(tree);
	printf("\n");

	//层序遍历
	LevelOrder(tree);



	return 0;
}
