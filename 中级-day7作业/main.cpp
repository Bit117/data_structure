#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef char BiElemType;

//define binaryTree node
typedef struct BiTNode {
	BiElemType data;//数据
	struct BiTNode* lchild;//左子树
	struct BiTNode* rchild;//右子树
}BiTNode, * BiTree;

//define binaryTree insert queue
typedef struct tag {
	BiTree p;//指向某一个节点 是tag结构体中的一个成员，p是一个结构体指针，p指向的有自己的data 左子树、右子树
	struct tag* pnext;//指向下一个节点
}tag_t, * ptag_t;


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

int main()
{
	BiTree pnew; //每次用来接临时申请的空间
	//int i, j, pos;
	char data;
	BiTree tree = NULL;
	ptag_t phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;
	while (scanf("%c", &data) != EOF)
	{
		if (data == '\n')
		{
			break;
		}
		//核心代码
		//存树
		pnew = (BiTree)calloc(1, sizeof(BiTNode));//使用calloc申请空间
		pnew->data = data;//树中存数据

		//存辅助队列
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));
		listpnew->p = pnew;//辅助队列新的指针指向新建的树

		if (NULL == tree)//存树的第一层
		{
			//tree = listpnew->p;
			tree = pnew;
			phead = listpnew;
			ptail = listpnew;
			pcur = listpnew;
			continue;
		}
		else
		{
			ptail->pnext = listpnew; //ptail 指向尾部辅助队列尾部节点
			ptail = listpnew; //让 把辅助队列最后一个结构体指针 赋给 ptail结构体指针
		}

		//如何把新节点放入树
		if (NULL == pcur->p->lchild)
		{
			pcur->p->lchild = pnew;
		}
		else if (NULL == pcur->p->rchild)
		{
			pcur->p->rchild = pnew;
			pcur = pcur->pnext; //左右都放了节点之后，pcur指向队列的下一个
		}

	}
	//printf("--------前序遍历----------\n");//也叫先序遍历，先打印当前结点，打印左孩子，打印右孩子
	preOrder(tree);
	return 0;
}
