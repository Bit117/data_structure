#define _CRT_SECURE_NO_WARNINGS
#include "function.h"
//
//�ݹ�ʵ��
//abdhiejcfg  ǰ�������ǰ���������������ȱ���
void preOrder(BiTree p)
{
	if (p != NULL)
	{
		putchar(p->c);//�ȼ���visit����
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}
int main()
{
	BiTree pnew;//ÿ����������ʱ����Ŀռ��
	int i, j, pos;
	char c;
	BiTree tree = NULL;//����
	ptag_t phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;//phead���Ƕ���ͷ��ptail���Ƕ���β
	//abcdefghij
	while (scanf("%c", &c) != EOF)
	{
		if (c == '\n')
		{
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));//calloc����ռ䲢�Կռ���г�ʼ������ֵΪ0
		pnew->c = c;//���ݷŽ�ȥ
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));//�����н������ռ�
		listpnew->p = pnew;

		if (NULL == tree)
		{
			tree = pnew;//���ĸ�
			phead = listpnew;//����ͷ
			ptail = listpnew;//����β
			pcur = listpnew;
			continue;
		}
		else {
			
			ptail->pnext = listpnew;//�½���������ͨ��β�巨
			ptail = listpnew;//ptailָ�����β��
		}//pcurʼ��ָ��Ҫ����Ľ���λ��
		
		if (NULL == pcur->p->lchild)//��ΰ��½�������
		{
			pcur->p->lchild = pnew;//���½��ŵ�Ҫ����������
		}
		else if (NULL == pcur->p->rchild)
		{
			pcur->p->rchild = pnew;//���½��ŵ�Ҫ��������ұ�
			pcur = pcur->pnext;//���Ҷ����˽���pcurָ����е���һ��
		}
	}
	printf("--------ǰ�����----------\n");//Ҳ������������ȴ�ӡ��ǰ��㣬��ӡ���ӣ���ӡ�Һ���
	preOrder(tree);
	return 0;
}
