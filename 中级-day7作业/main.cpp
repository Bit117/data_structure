#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef char BiElemType;

//define binaryTree node
typedef struct BiTNode {
	BiElemType data;//����
	struct BiTNode* lchild;//������
	struct BiTNode* rchild;//������
}BiTNode, * BiTree;

//define binaryTree insert queue
typedef struct tag {
	BiTree p;//ָ��ĳһ���ڵ� ��tag�ṹ���е�һ����Ա��p��һ���ṹ��ָ�룬pָ������Լ���data ��������������
	struct tag* pnext;//ָ����һ���ڵ�
}tag_t, * ptag_t;


//ǰ�����
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
	BiTree pnew; //ÿ����������ʱ����Ŀռ�
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
		//���Ĵ���
		//����
		pnew = (BiTree)calloc(1, sizeof(BiTNode));//ʹ��calloc����ռ�
		pnew->data = data;//���д�����

		//�渨������
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));
		listpnew->p = pnew;//���������µ�ָ��ָ���½�����

		if (NULL == tree)//�����ĵ�һ��
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
			ptail->pnext = listpnew; //ptail ָ��β����������β���ڵ�
			ptail = listpnew; //�� �Ѹ����������һ���ṹ��ָ�� ���� ptail�ṹ��ָ��
		}

		//��ΰ��½ڵ������
		if (NULL == pcur->p->lchild)
		{
			pcur->p->lchild = pnew;
		}
		else if (NULL == pcur->p->rchild)
		{
			pcur->p->rchild = pnew;
			pcur = pcur->pnext; //���Ҷ����˽ڵ�֮��pcurָ����е���һ��
		}

	}
	//printf("--------ǰ�����----------\n");//Ҳ������������ȴ�ӡ��ǰ��㣬��ӡ���ӣ���ӡ�Һ���
	preOrder(tree);
	return 0;
}
