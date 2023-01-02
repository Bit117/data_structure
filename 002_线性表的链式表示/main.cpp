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
	LinkList s, r = L; //r 代表尾指针 ，都指向新给进来的 L，不 =L 会出现没有初始化r
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x; //s拿到新的赋值
		r->next = s; //r指向 尾部新建 的空间
		r = s; //让 r 等于新的s，好让下一个 r 指向下一个s，依次向后
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

LinkList GetElem(LinkList& L, int i) //返回的是一个结构体指针
{
	int j = 1;
	LinkList p = L->next;  //指向头结点，已经是第一个了，所以查第一个的时候下面的while语句不用循环
	while (p && j < i)	//p！=NULL 与上 j < 查找的 i 位置时。 判断位置 不相等则继续
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
	while (p != NULL && p->data != e) //判断值 不相等则继续
	{
		p = p->next;
		pos++;
	}
	return pos;
}

bool ListFrontInsert(LinkList& L, int i, Elemtype e)
{
	LinkList p = GetElem(L, i - 1);//拿到插入节点的 前驱结构体指针
	LinkList s = (LinkList)malloc(sizeof(LNode));
	if (NULL == p)
	{
		return false;
	}
	s->data = e; //给新建的节点赋数值
	s->next= p->next;//新节点指向 前驱节点原来指向的节点
	p->next = s;//前驱节点指向新节点
	return true;
}

bool ListDelete(LinkList &L, int i)
{
	LinkList p = GetElem(L, i - 1);//拿到节点的 前驱节点结构体指针
	LinkList q = GetElem(L, i);//拿到节点的结构体指针
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
	p->next = q->next; //断链
	free(q); //释放空间
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
			printf(" "); // oj对空格敏感
		}
	}
	printf("\n");
}

void PrintList(LinkList L) //王道示例给出的标准输出
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
	LinkList search; //按位置查找的结构体指针
	int pos; // 按值查找的位置

	//3 4 5 6 7 9999
	//CreatList1(L); //头插法
	//listPrint(L);
	CreatList2(L); //尾插法
	//listPrint(L);

	//按位置查找
	search = GetElem(L, 2); //按照 位置 进行查询 search 拿到的是一个结构体指针
	if (search != NULL)
	{
		printf("%d\n", search->data);
	}

	////按值查找
	//pos = LocateElem(L, 7); //按照 值 进行查询 pos 拿到的是一个整形值
	//if (pos)
	//{
	//	printf("%d\n", pos);
	//}

	//插入新节点 对象 位置 数值
	ListFrontInsert(L, 2, 99);
	listPrint(L);

	ListDelete(L, 4);
	listPrint(L);

	return 0;
}
