#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

LinkList CreateListByEnd(LinkList& L) {
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode* s, * r = L; //r表示尾部结点
	L->next = NULL;
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s; //r指向新的表尾结点
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}
//按序号查找结点值
LNode* GetElem(LinkList L, int i) {
	int j = 1;
	LNode* p = L->next;
	if (i == 0) return L;
	if (i < 0) return NULL;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}
//新结点插入第i个位置
bool ListFrontInsert(LinkList L, int i, ElemType e) {
	LinkList p = GetElem(L, i - 1);
	if (NULL == p) return false;
	LinkList s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	printf("%d\n", s->next->data);
	return true;
}
//删除第i个结点
bool ListDel(LinkList L, int i) {
	LinkList p = GetElem(L, i - 1);
	if (NULL == p) {
		return false;
	}
	LinkList q;
	q = p->next;
	p->next = q->next;
	free(q);
	return true;
}
//打印
void ListPrint(LinkList L) {
	L = L->next;
	while (L != NULL)
	{
		printf("%3d", L->data);
		L = L->next;
	}
	printf("\n");
}
int main() {
	LinkList L;
	CreateListByEnd(L);
	int ret;
	ret = ListFrontInsert(L, 2, 99);
	if (ret) {
		ListPrint(L);
	}
	ret = ListDel(L, 4);
	if (ret) {
		ListPrint(L);
	}
	return 0;
}
