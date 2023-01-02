#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
//

typedef int Elemtype;

typedef struct LNode {
	Elemtype data;
	struct LNode* next;
}LNode, * LinkList;

LinkList CreatList1(LinkList& L)  //头插法
{
	LinkList s;
	int x;
	L = (LinkList)malloc(sizeof(LinkList));
	L->next = NULL; //L->data里为空，指针初始化
	scanf("%d", &x);

	//新插入
	while (x != 9999)
	{
		s = (LinkList)malloc(sizeof(LNode));//申请一个新空间给s，强制类型转换
		s->data = x;  //把接受到的值传给s->data
		s->next = L->next; //指针传递
		L->next = s; //链头指向 s（一个结构体），而不是只指向下一个指针
		scanf("%d", &x);
	}
	return L;
}

LinkList CreatList2(LinkList& L)
{
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LinkList s, r = L; //r 代表尾指针 ，都指向新给进来的 L
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		r->next = s; //指向尾部新建
		r = s; //让 r 等于新的s，好让下一个 r 指向下一个s
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
		printf("%d", L->data);//打印当前结点数据
		L = L->next;//指向下一个结点
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
