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
