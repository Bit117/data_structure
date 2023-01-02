#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
typedef int Elemtype;

typedef struct LNode {
	Elemtype data;
	struct LNode* next;
}LNode, * LinkList;

LinkList CreatList2(LinkList& L)
{
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LinkList s, r = L; //r ����βָ�� ����ָ���¸������� L���� =L �����û�г�ʼ��r
	L->next = NULL;
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
	if (i == 0) return L;
	if (i < 0) return NULL;
	while (p && j < i)	//p��=NULL ���� j < ���ҵ� i λ��ʱ�� �ж�λ�� ����������
	{
		p = p->next;
		j++;
	}
	return p;
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
	s->next = p->next;//�½ڵ�ָ�� ǰ���ڵ�ԭ��ָ��Ľڵ�
	p->next = s;//ǰ���ڵ�ָ���½ڵ�
	return true;
}

bool ListDelete(LinkList& L, int i)
{
	LinkList p = GetElem(L, i - 1);//�õ��ڵ�� ǰ���ڵ�ṹ��ָ��
	LinkList q = GetElem(L, i);//�õ��ڵ�Ľṹ��ָ��
	if (NULL == p)
	{
		return false;
	}
	p->next = q->next; //����
	free(q); //�ͷſռ�
	return true;  //��bool��ʱ�ǵ÷��� true ����Ȼ�ᵼ��runtime error*****************************************
}

void listPrint(LinkList L)
{
	L = L->next;
	while (L != NULL)
	{
		printf("%3d", L->data);
		L = L->next;
		//if (L != NULL)
		//{
		//	printf(" "); // oj�Կո�����
		//}
	}
	printf("\n");
}

int main()
{
	LinkList L;
	LinkList search; //��λ�ò��ҵĽṹ��ָ��

	//3 4 5 6 7 9999
	CreatList2(L); //β�巨
	//listPrint(L);

	//��λ�ò���
	search = GetElem(L, 2); //���� λ�� ���в�ѯ search �õ�����һ���ṹ��ָ��
	if (search != NULL)
	{
		printf("%d\n", search->data);
	}

	//�����½ڵ� ���� λ�� ��ֵ
	ListFrontInsert(L, 2, 99);
	listPrint(L);

	ListDelete(L, 4);
	listPrint(L);

	return 0;
}
