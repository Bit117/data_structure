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
	LinkList s, r = L; //r ����βָ�� ����ָ���¸������� L
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		r->next = s; //ָ��β���½�
		r = s; //�� r �����µ�s��������һ�� r ָ����һ��s
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
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
			printf(" ");
		}
	}
	printf("\n");
}

void PrintList(LinkList L)
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
	CreatList1(L);
	listPrint(L);
	CreatList2(L);
	listPrint(L);
	return 0;
}
