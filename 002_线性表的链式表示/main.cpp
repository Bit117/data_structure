#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
//

typedef int Elemtype;

typedef struct LNode {
	Elemtype data;
	struct LNode* next;
}LNode, * LinkList;

LinkList CreatList1(LinkList& L)  //ͷ�巨
{
	LinkList s;
	int x;
	L = (LinkList)malloc(sizeof(LinkList));
	L->next = NULL; //L->data��Ϊ�գ�ָ���ʼ��
	scanf("%d", &x);

	//�²���
	while (x != 9999)
	{
		s = (LinkList)malloc(sizeof(LNode));//����һ���¿ռ��s��ǿ������ת��
		s->data = x;  //�ѽ��ܵ���ֵ����s->data
		s->next = L->next; //ָ�봫��
		L->next = s; //��ͷָ�� s��һ���ṹ�壩��������ָֻ����һ��ָ��
		scanf("%d", &x);
	}
	return L;
}

LinkList CreatList2(LinkList& L)
{
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LinkList s, r = L; //r ����βָ�� ����ָ���¸������� L���� =L �����û�г�ʼ��r
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x; //s�õ��µĸ�ֵ
		r->next = s; //rָ�� β���½� �Ŀռ�
		r = s; //�� r �����µ�s��������һ�� r ָ����һ��s���������
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

LinkList GetElem(LinkList& L, int i) //���ص���һ���ṹ��ָ��
{
	int j = 1;
	LinkList p = L->next;  //ָ��ͷ��㣬�Ѿ��ǵ�һ���ˣ����Բ��һ����ʱ�������while��䲻��ѭ��
	while (p && j < i)	//p��=NULL ���� j < ���ҵ� i λ��ʱ�� �ж�λ�� ����������
	{
		p = p->next;
		j++;
	}
	return p;
}

int LocateElem(LinkList& L, Elemtype e)
{
	int pos = 1;
	LinkList p = L->next;
	while (p != NULL && p->data != e) //�ж�ֵ ����������
	{
		p = p->next;
		pos++;
	}
	return pos;
}

bool ListFrontInsert(LinkList& L, int i, Elemtype e)
{
	LinkList p = GetElem(L, i - 1);//�õ�����ڵ�� ǰ���ṹ��ָ��
	LinkList s = (LinkList)malloc(sizeof(LNode));
	if (NULL == p)
	{
		return false;
	}
	s->data = e; //���½��Ľڵ㸳��ֵ
	s->next= p->next;//�½ڵ�ָ�� ǰ���ڵ�ԭ��ָ��Ľڵ�
	p->next = s;//ǰ���ڵ�ָ���½ڵ�
	return true;
}

bool ListDelete(LinkList &L, int i)
{
	LinkList p = GetElem(L, i - 1);//�õ��ڵ�� ǰ���ڵ�ṹ��ָ��
	LinkList q = GetElem(L, i);//�õ��ڵ�Ľṹ��ָ��
	if (NULL == p)
	{
		return false;
	}
	if (NULL == p->next)
	{
		return false;
	}
	if (NULL == q->next)
	{
		return false;
	}
	p->next = q->next; //����
	free(q); //�ͷſռ�
}

void listPrint(LinkList L)
{
	L = L->next;
	while (L != NULL)
	{
		printf("%d", L->data);
		L = L->next;
		if (L != NULL)
		{
			printf(" "); // oj�Կո�����
		}
	}
	printf("\n");
}

void PrintList(LinkList L) //����ʾ�������ı�׼���
{
	L = L->next;
	while (L != NULL)
	{
		printf("%d", L->data);//��ӡ��ǰ�������
		L = L->next;//ָ����һ�����
		if (L != NULL)
		{
			printf(" ");
		}
	}
	printf("\n");
}

int main()
{
	LinkList L; 
	LinkList search; //��λ�ò��ҵĽṹ��ָ��
	int pos; // ��ֵ���ҵ�λ��

	//3 4 5 6 7 9999
	//CreatList1(L); //ͷ�巨
	//listPrint(L);
	CreatList2(L); //β�巨
	//listPrint(L);

	//��λ�ò���
	search = GetElem(L, 2); //���� λ�� ���в�ѯ search �õ�����һ���ṹ��ָ��
	if (search != NULL)
	{
		printf("%d\n", search->data);
	}

	////��ֵ����
	//pos = LocateElem(L, 7); //���� ֵ ���в�ѯ pos �õ�����һ������ֵ
	//if (pos)
	//{
	//	printf("%d\n", pos);
	//}

	//�����½ڵ� ���� λ�� ��ֵ
	ListFrontInsert(L, 2, 99);
	listPrint(L);

	ListDelete(L, 4);
	listPrint(L);

	return 0;
}
