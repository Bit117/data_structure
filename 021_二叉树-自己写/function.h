#include<stdio.h>
#include<stdlib.h>

typedef char BiElemType;

//define binaryTree node
typedef struct BiTNode {
	BiElemType data;//数据
	struct BiTNode* lchild;//左子树
	struct BiTNode* rchild;//右子树
}BiTNode, * BiTree;

//define binaryTree insert queue
typedef struct tag {
	BiTree p;//指向某一个节点 是tag结构体中的一个成员，p是一个结构体指针，p指向的有自己的data 左子树、右子树
	struct tag* pnext;//指向下一个节点
}tag_t, * ptag_t;
