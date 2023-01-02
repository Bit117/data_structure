#include <stdio.h>
#include <stdlib.h>
//作者 王道训练营 龙哥
typedef char BiElemType; //用 char 型

//Binary tree 二叉树， BiTNode 二叉树节点
typedef struct BiTNode {
	BiElemType c;//c就是书籍上的data，存放数据
	struct BiTNode* lchild; //左子树
	struct BiTNode* rchild; //右子树
}BiTNode, * BiTree;

//要插入树中的队列，层次建树的辅助队列
typedef struct tag {
	BiTree p;//树的某一个结点的地址值
	struct tag* pnext;//与phead与ptail进行配合
}tag_t, * ptag_t;
