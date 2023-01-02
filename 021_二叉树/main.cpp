#define _CRT_SECURE_NO_WARNINGS
#include "function.h"
//
//递归实现
//abdhiejcfg  前序遍历，前序遍历就是深度优先遍历
void preOrder(BiTree p)
{
	if (p != NULL)
	{
		putchar(p->c);//等价于visit函数
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}
int main()
{
	BiTree pnew;//每次用来接临时申请的空间的
	int i, j, pos;
	char c;
	BiTree tree = NULL;//树根
	ptag_t phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;//phead就是队列头，ptail就是队列尾
	//abcdefghij
	while (scanf("%c", &c) != EOF)
	{
		if (c == '\n')
		{
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));//calloc申请空间并对空间进行初始化，赋值为0
		pnew->c = c;//数据放进去
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));//给队列结点申请空间
		listpnew->p = pnew;

		if (NULL == tree)
		{
			tree = pnew;//树的根
			phead = listpnew;//队列头
			ptail = listpnew;//队列尾
			pcur = listpnew;
			continue;
		}
		else {
			
			ptail->pnext = listpnew;//新结点放入链表，通过尾插法
			ptail = listpnew;//ptail指向队列尾部
		}//pcur始终指向要插入的结点的位置
		
		if (NULL == pcur->p->lchild)//如何把新结点放入树
		{
			pcur->p->lchild = pnew;//把新结点放到要插入结点的左边
		}
		else if (NULL == pcur->p->rchild)
		{
			pcur->p->rchild = pnew;//把新结点放到要插入结点的右边
			pcur = pcur->pnext;//左右都放了结点后，pcur指向队列的下一个
		}
	}
	printf("--------前序遍历----------\n");//也叫先序遍历，先打印当前结点，打印左孩子，打印右孩子
	preOrder(tree);
	return 0;
}
