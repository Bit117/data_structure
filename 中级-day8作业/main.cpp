#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//������������
typedef	char BiElemType;

//define binaryTree node
//����������ڵ�
typedef struct BiTNode
{
	BiElemType data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, * BiTree;

//define binaryTree insert queue
//����һ���������
typedef struct tag
{
	BiTree p;//ָ��ĳһ���ڵ� ��tag�ṹ���е�һ����Ա��p��һ���ṹ��ָ�룬pָ������Լ���data ��������������
	struct tag* pnext;//ָ����һ���ڵ�
}tag_t, *ptag_t;


//����

//���е�������ݽṹ
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
	LinkNode* p = Q.front->next;//ͷ���ʲô��û�棬����ͷ������һ���ڵ��������
	x = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return true;
}

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

//�������
void InOrder(BiTree p)
{
	if (NULL !=p)
	{
		InOrder(p->lchild);
		putchar(p->data);
		InOrder(p->rchild);
	}
}

//��������
void PostOrder(BiTree p)
{
	if (NULL != p)
	{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		putchar(p->data);
	}
}

//��α���,���������������ȱ���
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
			EnQueue(Q, p->lchild); // �������
		}
		if (NULL != p->rchild)
		{
			EnQueue(Q, p->rchild); // ����Һ���
		}
	}

}

//

int main()
{
	BiTree pnew;//ÿ����������ʱ����Ŀռ�,���µ����ڵ�
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
		listpnew->p = pnew;//p�����������ڵ� �Ľṹ��ָ��

		//�渨������
		if (NULL == tree)
		{
			tree = pnew;
			phead = listpnew;
			ptail = listpnew;
			pcur = listpnew;
			continue; //����Ҳ����Ҫ����Ҫ��һ��tree��������һ�μ�����Ĳ���
		}
		else
		{
			ptail->pnext = listpnew; //�ṹ��ָ��ָ���µĶ��нڵ�
			ptail = listpnew; //������һ��
		}

		//����
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

	//printf("--------ǰ�����----------\n");//Ҳ������������ȴ�ӡ��ǰ��㣬��ӡ���ӣ���ӡ�Һ���
	//preOrder(tree);
	//printf("\n");
	
	//����
	InOrder(tree);
	printf("\n");

	//����
	PostOrder(tree);
	printf("\n");

	//�������
	LevelOrder(tree);



	return 0;
}
